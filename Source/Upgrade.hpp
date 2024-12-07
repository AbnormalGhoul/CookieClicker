#ifndef UPGRADE_HPP
#define UPGRADE_HPP

#include <string>

class Upgrade {
protected:
    int cost;
    int level;
    int cookiesPerInterval;
    int interval; // in milliseconds
    int count;    // Number of this upgrade purchased
    bool active;  // Indicates if the upgrade is active

public:
    Upgrade(int cost, int cookiesPerInterval, int interval);
    virtual ~Upgrade() = default;

    virtual int generateCookies() const;
    virtual void upgradeLevel();

    void activate();
    bool isActive() const;

    int getCost() const;
    int getLevel() const;
    int getCount() const;
    int getInterval() const;

};


#endif
