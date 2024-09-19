#pragma once

#include "ClapTrap.h"
#include <string.h>


class ScavTrap : public ClapTrap
{

public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ~ScavTrap();
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator= (const ScavTrap& ScavTrap);

    void    attack(const std::string& target);
    void    takeDamage(int amount);
    void    beRepaired(int amount);
    void    guardGate();

    int     getDefense() const;

private:
    int     m_defense;
    bool    m_isGuarding;

};
