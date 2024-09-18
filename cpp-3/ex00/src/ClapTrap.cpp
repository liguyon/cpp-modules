#include "ClapTrap.h"
#include <iostream>


ClapTrap::ClapTrap()
    : m_name(""), // avoid UB
    m_health(10), m_energy(10), m_attack(0)
{
#ifndef NDEBUG
    std::cout << "ClapTrap default constructor called: '"
        << m_name << "' created" << std::endl;
    _debug();
#endif
}

ClapTrap::ClapTrap(const std::string& name)
    : m_name(name), m_health(10), m_energy(10), m_attack(0)
{
#ifndef NDEBUG
    std::cout << "ClapTrap constructor called: '" << m_name << "' created" << std::endl;
    _debug();
#endif
}

ClapTrap::~ClapTrap()
{
#ifndef NDEBUG
    std::cout << "ClapTrap destructor called: '" << m_name << "' destroyed" << std::endl;
#endif
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
    : m_name(clapTrap.m_name), m_health(clapTrap.m_health),
    m_energy(clapTrap.m_energy), m_attack(clapTrap.m_attack)
{
#ifndef NDEBUG
    std::cout << "ClapTrap copy constructor called: '" << m_name << "' created" << std::endl;
    _debug();
#endif
}

ClapTrap& ClapTrap::operator= (const ClapTrap& clapTrap)
{
    m_name = clapTrap.m_name;
    m_health = clapTrap.m_health;
    m_energy = clapTrap.m_energy;
    m_attack = clapTrap.m_attack;

#ifndef NDEBUG
    std::cout << "ClapTrap copy assignment operator called: copied '"
        << clapTrap.m_name << "'" << std::endl;
    _debug();
#endif

    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (m_health <= 0)
        std::cout << "ClapTrap " << m_name << " is dead. Cannot perform any action." << std::endl;
    else if (m_energy <= 0)
        std::cout << "ClapTrap " << m_name << " has no energy. Cannot perform attack." << std::endl;
    else
    {
        --m_energy;
        std::cout << "ClapTrap " << m_name << " attacks " << target
            << " causing " << m_attack << " points of damage !" << std::endl;
#ifndef NDEBUG
        _debug();
#endif
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_health <= 0)
        std::cout << "ClapTrap " << m_name << " is dead. Cannot perform any action." << std::endl;
    else if (m_energy <= 0)
        std::cout << "ClapTrap " << m_name << " has no energy. Cannot perform repair." << std::endl;
    else
    {
        --m_energy;
        m_health += amount;
        std::cout << "ClapTrap " << m_name << " repairs itself for " << amount << "hp." << std::endl;
#ifndef NDEBUG
        _debug();
#endif
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << m_name << " takes " << amount << " damage." << std::endl;
    if (amount >= static_cast<unsigned int>(m_health))
    {
        m_health = 0;
        std::cout << "ClapTrap " << m_name << " died." << std::endl;
    }
    else
        m_health -= amount;

#ifndef NDEBUG
    _debug();
#endif
}

#ifndef NDEBUG
void ClapTrap::_debug() const
{
    std::cout << "ClapTrap { name:" << m_name << ", health:" << m_health
        << ", energy:" << m_energy << ", attack:" << m_attack << " }" << std::endl;
}
#endif
