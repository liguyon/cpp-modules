#pragma once

#include <string>


class ClapTrap
{

public:
    ClapTrap(const std::string& name);
    ~ClapTrap();
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator= (const ClapTrap& clapTrap);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


private:
    std::string m_name;
    int m_health;
    int m_energy;
    int m_attack;

#ifndef NDEBUG
    void _debug() const; // bad! for testing without unit tests framework and getters
#endif

};
