/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:54 by liguyon           #+#    #+#             */
/*   Updated: 2024/07/12 13:12:28 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "Phonebook.h"
#include <iostream>
#include <string>
#include <limits>
#include <cstdio>


int	main()
{
	Phonebook pb;
	
	while (pb.getIsRunning())
	{
		std::cout << "\nEnter a command:\n";
		std::string command;
		std::cin >> std::ws;
		std::getline(std::cin, command);
		if (std::cin.fail())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Failed reading input. Please try again." << std::endl;
			continue;
		}
		if (!command.compare("EXIT"))
			pb.exit();
		else if (!command.compare("ADD"))
			pb.add();
		else if (!command.compare("SEARCH"))
			pb.search();
		else
			std::cout << "The command is invalid. Please try again.\n\n";
	}
	return 0;
}
