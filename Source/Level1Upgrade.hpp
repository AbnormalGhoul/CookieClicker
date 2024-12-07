#ifndef LEVEL1UPGRADE_HPP
#define LEVEL1UPGRADE_HPP

#include "Upgrade.hpp"

class Level1Upgrade : public Upgrade {
public:
    Level1Upgrade();
    int generateCookies() const override;
};

#endif
