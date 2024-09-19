#include "ClapTrap.h"
#include <iostream>


ClapTrap::ClapTrap()
    : m_name(""),
    m_health(10), m_energy(10), m_attack(0)
{
#ifndef NDEBUG
    std::cout << "ClapTrap default constructor called: '"
        << m_name << "' created" << std::endl;
#endif
}

ClapTrap::ClapTrap(const std::string& name)
    : m_name(name), m_health(10), m_energy(10), m_attack(0)
{
#ifndef NDEBUG
    std::cout << "ClapTrap constructor called: '" << m_name << "' created" << std::endl;
#endif
}

ClapTrap::~ClapTrap()
{
#ifndef NDEBUG
    std::cout << "ClapTrap destructor called: '" << m_name << "' destroyed" << std::endl;
#endif
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    *this = clapTrap;
#ifndef NDEBUG
    std::cout << "ClapTrap copy constructor called: '" << m_name << "' created" << std::endl;
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
    }
}

void ClapTrap::beRepaired(int amount)
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
    }
}

void ClapTrap::takeDamage(int amount)
{
    if (m_health > 0)
    {
        std::cout << "ClapTrap " << m_name << " takes " << amount << " damage." << std::endl;
        m_health -= amount;
        if (m_health <= 0)
            std::cout << "ClapTrap " << m_name << " died." << std::endl;
    }
}

const std::string& ClapTrap::getName() const
{
    return m_name;
}

int ClapTrap::getHealth() const
{
    return m_health;
}

int ClapTrap::getEnergy() const
{
    return m_energy;
}

int ClapTrap::getAttack() const
{
    return m_attack;
}
