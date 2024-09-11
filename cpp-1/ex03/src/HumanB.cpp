/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:26:11 by liguyon           #+#    #+#             */
/*   Updated: 2024/01/15 07:32:16 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string& name)
	: m_name(name), m_weapon(NULL)
{
}

void HumanB::attack() const
{
	if (m_weapon)
		std::cout <<
		m_name << " attacks with their " << m_weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
	m_weapon = &weapon;
}
