#include "Level2Upgrade.hpp"

Level2Upgrade::Level2Upgrade()
    : Upgrade(50, 5, 10000) {
} // Cost: 50, Cookies per 10 seconds: 5

int Level2Upgrade::generateCookies() const {
    return cookiesPerInterval * count;
}
