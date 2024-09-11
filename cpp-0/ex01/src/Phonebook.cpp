/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:57 by liguyon           #+#    #+#             */
/*   Updated: 2024/07/12 13:10:43 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.h"
#include <iostream>
#include <limits>
#include <cstdio>

int 	Phonebook::m_nbContacts = 0;
bool	Phonebook::m_contactsFilled = false;

Phonebook::Phonebook()
{
	std::cout << "Welcome to the awesome phonebook!\n\n";
	std::cout << "Usage:\n"
		ANSI_BOLD "ADD" ANSI_RESET "    save a new contact\n"
		ANSI_BOLD "SEARCH" ANSI_RESET " display a specific contact\n"
		ANSI_BOLD "EXIT" ANSI_RESET "   quit the program\n";
	m_isRunning = true;
}

void Phonebook::add()
{
	static int i = 0;

	m_contacts[i] = Contact(i);
	++i;
	if (!Phonebook::m_contactsFilled)
		++Phonebook::m_nbContacts;
	if (i > 7)
	{
		i = 0;
		Phonebook::m_contactsFilled = true;
	}
}

static void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Phonebook::m_askContactIndex() const
{
	while (true)
	{
		std::cout << "\nEnter the index of the entry to display:\n";
		int index;
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			clearerr(stdin);
			ignoreLine();
			std::cout << "Failed reading input. Please try again." << std::endl;
			continue;
		}
		if (index < 0 || index >= Phonebook::m_nbContacts)
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid index. Please try again.\n";
			std::cin >> index;
		}
		else
		{
			ignoreLine();
			return index;
		}
	}
}

void Phonebook::search()
{
	if (Phonebook::m_nbContacts == 0)
		std::cout << "\nNo registered contact yet.\n";
	else
	{
		std::cout << "\nRegistered contacts:\n";
		for (int i = 0 ; i < Phonebook::m_nbContacts ; ++i)
			m_contacts[i].displayInList();
		int index = m_askContactIndex();
		if (index != -1)
			m_contacts[index].print();
	}
}

void Phonebook::exit()
{
	std::cout << "\nGoodbye!\n";
	m_isRunning = false;
}

bool Phonebook::getIsRunning() const
{
	return m_isRunning;
}
