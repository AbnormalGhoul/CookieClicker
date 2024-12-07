#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Cookie.hpp"
#include "Upgrade.hpp"
#include "Timer.hpp"

class Game {
private:
    sf::RenderWindow window;
    Cookie cookie;
    sf::Font font;
    sf::Text cookieCounterText;
    sf::Text startText;
    bool showStartText;
    int cookieCount;

    std::vector<std::unique_ptr<Timer>> timers;
    std::vector<std::unique_ptr<Upgrade>> upgrades;

    // Sound for clicking
    sf::SoundBuffer clickSoundBuffer;
    sf::Sound clickSound;

    // Background music
    sf::Music music1;
    sf::Music music2;
    bool playingMusic1;

    void addUpgrade(std::unique_ptr<Upgrade> upgrade);

public:
    Game();
    void run();
    void handleInput();
    void update();
    void render();

    // Testing methods
    int getCookieCount() const;              // Get the current cookie count
    void simulateCookieClick();              // Simulate a cookie click
    void addCookies(int count);              // Add cookies directly
    void simulateUpgradePurchase(int index); // Simulate buying an upgrade
    void simulateTime(float seconds);        // Simulate the passage of time
};


#endif
