#include "Level4Upgrade.hpp"

Level4Upgrade::Level4Upgrade()
    : Upgrade(1000, 100, 1000) {
} // Cost: 1000, 100 cookies every 1 secound

int Level4Upgrade::generateCookies() const {
    return cookiesPerInterval * count;
}
