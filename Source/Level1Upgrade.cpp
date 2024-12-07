#include "Level1Upgrade.hpp"

Level1Upgrade::Level1Upgrade()
    : Upgrade(10, 1, 10000) {
} // Cost: 10, Cookies per 10 seconds: 1

int Level1Upgrade::generateCookies() const {
    return cookiesPerInterval * count;
}
