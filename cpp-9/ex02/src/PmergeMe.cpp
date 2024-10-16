#include "PmergeMe.h"

#include <cstdlib>

#include <limits>
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>


static int parseInt(const char* cstr)
{
	const std::string str = cstr;

	if (str.length() < 1)
		throw "empty argument";
	if (str.length() > 11)
		throw "invalid integer";

	std::string::const_iterator it = str.begin();
	if (*it == '+')
		++it;
	for (; it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			throw "invalid integer";
	}

	long nbr = std::strtol(cstr, NULL, 10);
	if (nbr > std::numeric_limits<int>::max())
		throw "int overflow";

	return static_cast<int>(nbr);
}

static bool parseArgs(
	int ac, char* av[],
	std::vector<int>& vecOut, std::list<int>& lstOut)
{
	for (int i = 0; i < ac; ++i)
	{
		try
		{
			int parsedInt = parseInt(av[i]);
			if (std::find(vecOut.begin(), vecOut.end(), parsedInt) != vecOut.end())
				throw "dublicate";
			vecOut.push_back(parsedInt);
			lstOut.push_back(parsedInt);
		}
		catch(const char* e)
		{
			std::cerr << "error: " << e << " => " << av[i] << '\n';
			return false;
		}
	}
	return true;
}

static void printVec(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (i < 5)
			std::cout << vec.at(i) << ' ';
		else
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << '\n';
}

// static void miSortVector(std::vector<int>& vec)
// {

// }

// static void miSortList(std::list<int>& lst);

void PmergeMe::pmerge(int ac, char* av[])
{
	std::vector<int> vec;
	std::list<int> lst;

	if (!parseArgs(ac, av, vec, lst))
		return ;
	
	std::cout << "Before: ";
	printVec(vec);
	
	// miSortVector(vec);

	std::cout << "After:  ";
	printVec(vec);
}
