#ifndef LEVEL6UPGRADE_HPP
#define LEVEL6UPGRADE_HPP

#include "Upgrade.hpp"

class Level6Upgrade : public Upgrade {
public:
    Level6Upgrade();
    int generateCookies() const override;
};

#endif
