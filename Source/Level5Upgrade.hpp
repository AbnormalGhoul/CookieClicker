#ifndef LEVEL5UPGRADE_HPP
#define LEVEL5UPGRADE_HPP

#include "Upgrade.hpp"

class Level5Upgrade : public Upgrade {
public:
    Level5Upgrade();
    int generateCookies() const override;
};

#endif
