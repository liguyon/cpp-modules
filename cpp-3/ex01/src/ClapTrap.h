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

    // getters for testing
    const std::string& getName() const;
    int getHealth() const;
    int getEnergy() const;
    int getAttack() const;

    void attack(const std::string& target);
    void takeDamage(int amount);
    void beRepaired(int amount);

protected:
/* Eval sheet requires that we use protected attributes.
Private should be favored over protected, especially as an interface for this class is not hard to implement.
*/
    std::string m_name;
    int m_health;
    int m_energy;
    int m_attack;

};
