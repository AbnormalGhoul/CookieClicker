#include "Level3Upgrade.hpp"

Level3Upgrade::Level3Upgrade()
    : Upgrade(100, 50, 5000) {
} // Cost: 100, Cookies per 5 seconds: 50

int Level3Upgrade::generateCookies() const {
    return cookiesPerInterval * count;
}
