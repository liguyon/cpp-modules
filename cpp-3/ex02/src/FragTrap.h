#pragma once

#include "ClapTrap.h"
#include <string.h>


class FragTrap : public ClapTrap
{

public:
    FragTrap();
    FragTrap(const std::string& name);
    ~FragTrap();
    FragTrap(const FragTrap& FragTrap);
    FragTrap& operator= (const FragTrap& FragTrap);

    void    attack(const std::string& target);
    void    takeDamage(int amount);
    void    beRepaired(int amount);
    void    highFivesGuys() const;

private:

};
