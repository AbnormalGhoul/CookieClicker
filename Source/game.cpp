#include "Game.hpp"
#include "Level1Upgrade.hpp" // Include specific upgrades as needed

Game::Game()
    : window(sf::VideoMode(1600, 900), "Cookie Clicker"),
    cookie(75.0f, { 800, 450 }, sf::Color(139, 69, 19)), // A brown circle at the center
    cookieCount(0) {
    // Load font
    if (!font.loadFromFile("assets/arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    // Initialize cookie counter text
    cookieCounterText.setFont(font);
    cookieCounterText.setCharacterSize(24);
    cookieCounterText.setFillColor(sf::Color::White);
    cookieCounterText.setPosition(10, 10);

    // Add Level 1 Upgrade (you can add more upgrades similarly)
    addUpgrade(std::make_unique<Level1Upgrade>());
}


void Game::addUpgrade(std::unique_ptr<Upgrade> upgrade) {
    int interval = upgrade->getLevel() == 1 ? 10000 : 1000; // Example interval logic
    timers.push_back(std::make_unique<Timer>(interval, [this, upgradePtr = upgrade.get()]() {
        this->cookieCount += upgradePtr->generateCookies();
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

            // Check if the cookie was clicked
            if (cookie.isClicked(mousePos)) {
                cookieCount++; // Increment the cookie counter
            }

            // Check if an upgrade was clicked
            int y = 100; // Starting position for upgrades
            for (size_t i = 0; i < upgrades.size(); ++i) {
                if (mousePos.x >= 650 && mousePos.y >= y && mousePos.y <= y + 50) {
                    if (cookieCount >= upgrades[i]->getCost()) {
                        cookieCount -= upgrades[i]->getCost();
                        upgrades[i]->upgradeLevel();
                    }
                }
                y += 60; // Offset each upgrade button vertically
            }
        }
    }
}


void Game::update() {
    // Update timers
    for (auto& timer : timers) {
        timer->update();
    }

    // Update cookie counter text
    cookieCounterText.setString("Cookies: " + std::to_string(cookieCount));
}

void Game::render() {
    window.clear();

    // Draw cookie
    cookie.draw(window);

    // Draw cookie counter
    window.draw(cookieCounterText);

    // Draw upgrades
    int y = 100; // Starting position for upgrades
    for (size_t i = 0; i < upgrades.size(); ++i) {
        sf::RectangleShape button(sf::Vector2f(120, 50));
        button.setPosition(650, y);
        button.setFillColor(sf::Color::Blue);

        sf::Text buttonText;
        buttonText.setFont(font);
        buttonText.setCharacterSize(18);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setString("Upgrade " + std::to_string(i + 1) + "\nCost: " +
            std::to_string(upgrades[i]->getCost()));
        buttonText.setPosition(655, y + 5);

        window.draw(button);
        window.draw(buttonText);

        y += 60; // Offset each upgrade button vertically
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
