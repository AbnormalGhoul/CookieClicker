#include "Level6Upgrade.hpp"

Level6Upgrade::Level6Upgrade()
    : Upgrade(100000, 5000, 1000) {
} // Cost: 100, 5000 cookies per secound

int Level6Upgrade::generateCookies() const {
    return cookiesPerInterval * count;
}
