#pragma once

#include <string>


class ClapTrap
{

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ~ClapTrap();
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator= (const ClapTrap& clapTrap);

    void attack(const std::string& target);

    /* deliberate choice to implement as int instead of uint:
        - working with uint for entity stats is error prone:
            UB, type conversions
        - game-dev generally: allowing negative stats to signal death
            or other states, simplicity and flexibility of signed vs unsigned
        - in the specific case of cpp-2, entities stats will never
            overflow INT_MAX, so there is no reason really to use unsigned ints
    */
    void takeDamage(int amount);
    void beRepaired(int amount);

private:
    std::string m_name;
    int m_health;
    int m_energy;
    int m_attack;

#ifndef NDEBUG
    void _debug() const; // bad! use getters or debugger for debug/tests
#endif

};
