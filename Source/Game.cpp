#include "Game.hpp"
#include "Level1Upgrade.hpp"
#include "Level2Upgrade.hpp"
#include "Level3Upgrade.hpp"
#include "Level4Upgrade.hpp"
#include "Level5Upgrade.hpp"
#include "Level6Upgrade.hpp"

Game::Game()
	: window(sf::VideoMode(1600, 900), "Cookie Clicker", sf::Style::Titlebar | sf::Style::Close),
	cookie("assets/cookie.png", { 800, 450 }),
	cookieCount(0),
	showStartText(true),
	playingMusic1(true) { // Start with music1

	// Load font
	if (!font.loadFromFile("assets/arial.ttf")) {
		throw std::runtime_error("Failed to load font");
	}

	// Load click sound
	if (!clickSoundBuffer.loadFromFile("assets/click.mp3")) {
		throw std::runtime_error("Failed to load click sound");
	}
	clickSound.setBuffer(clickSoundBuffer);

	// Load background music
	if (!music1.openFromFile("assets/backgroundmusic1.mp3")) {
		throw std::runtime_error("Failed to load backgroundmusic1.mp3");
	}
	if (!music2.openFromFile("assets/backgroundmusic2.mp3")) {
		throw std::runtime_error("Failed to load backgroundmusic2.mp3");
	}

	// Play the first track
	music1.setLoop(true);
	music1.play();

	// Initialize cookie counter text
	cookieCounterText.setFont(font);
	cookieCounterText.setCharacterSize(24);
	cookieCounterText.setFillColor(sf::Color::White);
	cookieCounterText.setPosition(10, 10);

	// Initialize start text
	startText.setFont(font);
	startText.setString("Click the cookie to start the game");
	startText.setCharacterSize(30);
	startText.setFillColor(sf::Color::Yellow);
	startText.setPosition(800 - startText.getGlobalBounds().width / 2, 20);

	// Upgrades
	addUpgrade(std::make_unique<Level1Upgrade>());
	addUpgrade(std::make_unique<Level2Upgrade>());
	addUpgrade(std::make_unique<Level3Upgrade>());
	addUpgrade(std::make_unique<Level4Upgrade>());
	addUpgrade(std::make_unique<Level5Upgrade>());
	addUpgrade(std::make_unique<Level6Upgrade>());
}

void Game::addUpgrade(std::unique_ptr<Upgrade> upgrade) {
	timers.push_back(std::make_unique<Timer>(upgrade->getInterval(), [this, upgradePtr = upgrade.get()]() {
		if (upgradePtr->isActive()) {
			this->cookieCount += upgradePtr->generateCookies();
		}
		}));
	upgrades.push_back(std::move(upgrade));
}

void Game::handleInput() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			// Checks if the cookie was clicked
			if (cookie.isClicked(mousePos)) {
				cookieCount++; // Increments the cookie counter
				showStartText = false; // Hides the start text
				clickSound.play(); // Plays the click sound
			}

			// Checks if an upgrade was clicked
			int y = 150; // Starting position for upgrades
			for (size_t i = 0; i < upgrades.size(); ++i) {
				if (mousePos.x >= 1350 && mousePos.y >= y && mousePos.y <= y + 70) {
					if (cookieCount >= upgrades[i]->getCost()) {
						cookieCount -= upgrades[i]->getCost();
						upgrades[i]->upgradeLevel();
						if (!upgrades[i]->isActive()) {
							upgrades[i]->activate(); // Activate upgrade on first purchase
						}
					}
				}
				y += 90; // Offsets each upgrade button vertically
			}
		}

		// Checks for key press to switch music
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Period) {
			if (playingMusic1) {
				music1.stop();
				music2.setLoop(true);
				music2.play();
			}
			else {
				music2.stop();
				music1.setLoop(true);
				music1.play();
			}
			playingMusic1 = !playingMusic1; // Toggles the flag
		}
	}
}

void Game::update() {
	// Updates timers
	for (auto& timer : timers) {
		timer->update();
	}
	// Updates cookie counter text
	cookieCounterText.setString("Cookies: " + std::to_string(cookieCount));
}

void Game::render() {
	// Clears the window with a light blue color
	window.clear(sf::Color(37, 153, 190)); // Light blue background

	// Draws the start text if visible
	if (showStartText) {
		window.draw(startText);
	}

	// Draws the cookie
	cookie.draw(window);

	// Draws the cookie counter
	window.draw(cookieCounterText);

	// Draws upgrades
	int y = 150; // Starting position for upgrades
	for (size_t i = 0; i < upgrades.size(); ++i) {
		sf::RectangleShape button(sf::Vector2f(250, 70)); // Larger box dimensions
		button.setPosition(1350, y); // Aligns to the right side of the window
		button.setFillColor(sf::Color::Blue);

		sf::Text buttonText;
		buttonText.setFont(font);
		buttonText.setCharacterSize(18);
		buttonText.setFillColor(sf::Color::White);

		// Includes count in the button text
		buttonText.setString("Upgrade " + std::to_string(i + 1) +
			"\nCost: " + std::to_string(upgrades[i]->getCost()) +
			"\nCount: " + std::to_string(upgrades[i]->getCount()));
		buttonText.setPosition(1360, y + 5);

		window.draw(button);
		window.draw(buttonText);

		y += 90; // Offsets each upgrade button vertically
	}

	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		handleInput();
		update();
		render();
	}
}

int Game::getCookieCount() const {
	return cookieCount;
}

void Game::simulateCookieClick() {
	cookieCount++;
}

void Game::addCookies(int count) {
	cookieCount += count;
}

void Game::simulateUpgradePurchase(int index) {
	if (index >= 0 && index < static_cast<int>(upgrades.size())) {
		if (cookieCount >= upgrades[index]->getCost()) {
			cookieCount -= upgrades[index]->getCost();
			upgrades[index]->upgradeLevel();
			if (!upgrades[index]->isActive()) {
				upgrades[index]->activate();
			}
		}
	}
}

void Game::simulateTime(float seconds) {
	for (auto& upgrade : upgrades) {
		if (upgrade->isActive()) {
			cookieCount += upgrade->generateCookies();
		}
	}
}
