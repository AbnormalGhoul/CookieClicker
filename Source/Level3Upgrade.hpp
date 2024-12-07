#ifndef LEVEL3UPGRADE_HPP
#define LEVEL3UPGRADE_HPP

#include "Upgrade.hpp"

class Level3Upgrade : public Upgrade {
public:
    Level3Upgrade();
    int generateCookies() const override;
};

#endif
