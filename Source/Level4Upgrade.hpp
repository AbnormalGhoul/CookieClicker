#ifndef LEVEL4UPGRADE_HPP
#define LEVEL4UPGRADE_HPP

#include "Upgrade.hpp"

class Level4Upgrade : public Upgrade {
public:
    Level4Upgrade();
    int generateCookies() const override;
};

#endif
