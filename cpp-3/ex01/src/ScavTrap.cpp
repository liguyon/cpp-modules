#include "ScavTrap.h"
#include <iostream>


static int clamp_min(int value, int min);

ScavTrap::ScavTrap()
    : m_defense(0), m_isGuarding(false)
{
    m_health = 100;
    m_energy = 50;
    m_attack = 20;
#ifndef NDEBUG
    std::cout << "ScavTrap default constructor called: '"
        << m_name << "' created" << std::endl;
#endif
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name), m_defense(0), m_isGuarding(false)
{
    m_health = 100;
    m_energy = 50;
    m_attack = 20;
#ifndef NDEBUG
    std::cout << "ScavTrap constructor called: '" << m_name << "' created" << std::endl;
#endif
}

ScavTrap::~ScavTrap()
{
#ifndef NDEBUG
    std::cout << "ScavTrap destructor called: '" << m_name << "' destroyed" << std::endl;
#endif
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
    : ClapTrap(scavTrap.m_name)
{
    m_health = scavTrap.m_health;
    m_energy = scavTrap.m_energy;
    m_attack = scavTrap.m_attack;
#ifndef NDEBUG
    std::cout << "ScavTrap copy constructor called: '" << m_name << "' created" << std::endl;
#endif
}

ScavTrap& ScavTrap::operator= (const ScavTrap& scavTrap)
{
    m_name = scavTrap.m_name;
    m_health = scavTrap.m_health;
    m_energy = scavTrap.m_energy;
    m_attack = scavTrap.m_attack;
#ifndef NDEBUG
    std::cout << "ScavTrap copy assignment operator called: copied '"
        << scavTrap.m_name << "'" << std::endl;
#endif

    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (m_health <= 0)
        std::cout << "ScavTrap " << m_name << " is dead. Cannot perform any action." << std::endl;
    else if (m_energy <= 0)
        std::cout << "ScavTrap " << m_name << " has no energy. Cannot perform attack." << std::endl;
    else
    {
        --m_energy;
        std::cout << "ScavTrap " << m_name << " attacks " << target
            << " causing " << m_attack << " points of damage !" << std::endl;
    }
}

void ScavTrap::takeDamage(int amount)
{
    if (m_health > 0)
    {
        int finalDamage = clamp_min(amount - m_defense, 0);
        std::cout << "ScavTrap " << m_name << " takes "
            << finalDamage << " damage." << std::endl;
        m_health -= finalDamage;
        if (m_isGuarding)
        {
            m_isGuarding = false;
            m_defense -= 10;
        }
        if (m_health <= 0)
            std::cout << "ScavTrap " << m_name << " died." << std::endl;
    }
}

void ScavTrap::beRepaired(int amount)
{
    if (m_health <= 0)
        std::cout << "ScavTrap " << m_name << " is dead. Cannot perform any action." << std::endl;
    else if (m_energy <= 0)
        std::cout << "ScavTrap " << m_name << " has no energy. Cannot perform repair." << std::endl;
    else
    {
        --m_energy;
        m_health += amount;
        std::cout << "ScavTrap " << m_name << " repairs itself for " << amount << "hp." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (!m_isGuarding)
    {
        if (m_health <= 0)
        {
            std::cout << "ScavTrap " << m_name
                << " is dead. Cannot perform any action." << std::endl;
        }
        else if (m_energy < 10)
        {
            std::cout << "ScavTrap " << m_name
                << " doesn't have enough energy. Cannot guard." << std::endl;
        }
        else
        {
            m_energy -= 10;
            m_isGuarding = true;
            m_defense += 10;
            std::cout << "ScavTrap " << m_name << " is guarding." << std::endl;
        }
    }
    else
        std::cout << "ScavTrap " << m_name << " is already guarding." << std::endl;
}

int ScavTrap::getDefense() const
{
    return m_defense;
}

static int clamp_min(int value, int min)
{
    if (value <= min)
        return min;
    return value;
}
