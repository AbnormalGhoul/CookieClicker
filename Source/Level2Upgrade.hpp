#ifndef LEVEL2UPGRADE_HPP
#define LEVEL2UPGRADE_HPP

#include "Upgrade.hpp"

class Level2Upgrade : public Upgrade {
public:
    Level2Upgrade();
    int generateCookies() const override;
};

#endif
