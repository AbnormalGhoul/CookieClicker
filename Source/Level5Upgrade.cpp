#include "Level5Upgrade.hpp"

Level5Upgrade::Level5Upgrade()
    : Upgrade(5000, 500, 1000) {
} // Cost: 5000, Cookies per 1 seconds: 500

int Level5Upgrade::generateCookies() const {
    return cookiesPerInterval * count;
}
