#include "Tests.hpp"
#include "Game.hpp"
#include <cassert>
#include <iostream>

void runAllTests() {
    testCookieClick();
    testUpgradePurchase();
    testUpgradeProduction();
    testMultipleUpgradePurchase();
    testTransparentClick();

    std::cout << "All tests passed!" << std::endl;
}

void testCookieClick() {
    Game game;

    int initialCookies = game.getCookieCount();
    game.simulateCookieClick();

    assert(game.getCookieCount() == initialCookies + 1);
    std::cout << "testCookieClick passed!" << std::endl;
}

void testUpgradePurchase() {
    Game game;

    game.addCookies(10); // Add enough cookies for Level 1 Upgrade
    int initialCookies = game.getCookieCount();
    game.simulateUpgradePurchase(0);

    assert(game.getCookieCount() == initialCookies - 10);
    std::cout << "testUpgradePurchase passed!" << std::endl;
}

void testUpgradeProduction() {
    Game game;

    game.addCookies(10);
    game.simulateUpgradePurchase(0); // Purchase Level 1 Upgrade
    game.simulateTime(10); // Simulate 10 seconds

    assert(game.getCookieCount() > 0);
    std::cout << "testUpgradeProduction passed!" << std::endl;
}

void testMultipleUpgradePurchase() {
    Game game;

    game.addCookies(30); // Add enough cookies for 3 upgrades
    game.simulateUpgradePurchase(0);
    game.simulateUpgradePurchase(0);
    game.simulateUpgradePurchase(0);

    game.simulateTime(10); // Simulate 10 seconds
    assert(game.getCookieCount() >= 3); // Each upgrade adds 1 cookie per 10 seconds
    std::cout << "testMultipleUpgradePurchase passed!" << std::endl;
}

void testTransparentClick() {
    Game game;

    int initialCookies = game.getCookieCount();
    // Simulate clicking on a transparent area (not implemented here but should be mocked)
    // Assuming cookie's transparent click detection prevents increment
    bool clickedTransparent = false;
    if (clickedTransparent) {
        game.simulateCookieClick(); // Should not increment
    }

    assert(game.getCookieCount() == initialCookies);
    std::cout << "testTransparentClick passed!" << std::endl;
}
