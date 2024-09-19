#include "FragTrap.h"
#include <iostream>


FragTrap::FragTrap()
{
    m_health = 100;
    m_energy = 100;
    m_attack = 30;
#ifndef NDEBUG
    std::cout << "FragTrap default constructor called: '"
        << m_name << "' created" << std::endl;
#endif
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    m_health = 100;
    m_energy = 100;
    m_attack = 30;
#ifndef NDEBUG
    std::cout << "FragTrap constructor called: '" << m_name << "' created" << std::endl;
#endif
}

FragTrap::~FragTrap()
{
#ifndef NDEBUG
    std::cout << "FragTrap destructor called: '" << m_name << "' destroyed" << std::endl;
#endif
}

FragTrap::FragTrap(const FragTrap& FragTrap)
    : ClapTrap(FragTrap.m_name)
{
    m_health = FragTrap.m_health;
    m_energy = FragTrap.m_energy;
    m_attack = FragTrap.m_attack;
#ifndef NDEBUG
    std::cout << "FragTrap copy constructor called: '" << m_name << "' created" << std::endl;
#endif
}

FragTrap& FragTrap::operator= (const FragTrap& FragTrap)
{
    m_name = FragTrap.m_name;
    m_health = FragTrap.m_health;
    m_energy = FragTrap.m_energy;
    m_attack = FragTrap.m_attack;
#ifndef NDEBUG
    std::cout << "FragTrap copy assignment operator called: copied '"
        << FragTrap.m_name << "'" << std::endl;
#endif

    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (m_health <= 0)
        std::cout << "FragTrap " << m_name << " is dead. Cannot perform any action." << std::endl;
    else if (m_energy <= 0)
        std::cout << "FragTrap " << m_name << " has no energy. Cannot perform attack." << std::endl;
    else
    {
        --m_energy;
        std::cout << "FragTrap " << m_name << " attacks " << target
            << " causing " << m_attack << " points of damage !" << std::endl;
    }
}

void FragTrap::takeDamage(int amount)
{
	if (m_health > 0)
    {
        std::cout << "FragTrap " << m_name << " takes " << amount << " damage." << std::endl;
        m_health -= amount;
        if (m_health <= 0)
            std::cout << "FragTrap " << m_name << " died." << std::endl;
    }
}

void FragTrap::beRepaired(int amount)
{
    if (m_health <= 0)
        std::cout << "FragTrap " << m_name << " is dead. Cannot perform any action." << std::endl;
    else if (m_energy <= 0)
        std::cout << "FragTrap " << m_name << " has no energy. Cannot perform repair." << std::endl;
    else
    {
        --m_energy;
        m_health += amount;
        std::cout << "FragTrap " << m_name << " repairs itself for " << amount << "hp." << std::endl;
    }
}

void FragTrap::highFivesGuys() const
{
	if (m_health > 0)
		std::cout << "FragTrap " << m_name << ": gg guys !" << std::endl;
	else
		std::cout << "FragTrap " << m_name << ": gg but sadge for me T^T" << std::endl;
}
