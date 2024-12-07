#include "Upgrade.hpp"

Upgrade::Upgrade(int cost, int cookiesPerInterval, int interval)
    : cost(cost), cookiesPerInterval(cookiesPerInterval), interval(interval), level(1), count(0), active(false) {
}

void Upgrade::upgradeLevel() {
    cost *= 2;  // Increase cost by 2x
    level++;
    count++;    // Increment the number of this upgrade purchased
}

int Upgrade::generateCookies() const {
    return cookiesPerInterval * count; // Multiply production rate by the number purchased
}

void Upgrade::activate() {
    active = true; // Activate the upgrade
}

bool Upgrade::isActive() const {
    return active;
}

int Upgrade::getCost() const {
    return cost;
}

int Upgrade::getLevel() const {
    return level;
}

int Upgrade::getCount() const {
    return count;
}

int Upgrade::getInterval() const
{
    return interval;
}
