#include <iostream>

#include "PmergeMe.h"


int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "usage: ./PmergeMe positive_integers_sequence\n";
		return 0;
	}
    
	PmergeMe::pmerge(--ac, ++av);

	return 0;
}
