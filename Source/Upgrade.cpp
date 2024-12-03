#include "Upgrade.hpp"

Upgrade::Upgrade(int cost, int cookiesPerInterval, int interval)
    : cost(cost), cookiesPerInterval(cookiesPerInterval), interval(interval), level(1) {
}

void Upgrade::upgradeLevel() {
    cost *= 2; // Increase cost by 2x
    level++;
    cookiesPerInterval *= 2;   
}

int Upgrade::getCost() const {
    return cost;
}

int Upgrade::getLevel() const {
    return level;
}
