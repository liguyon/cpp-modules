#include "easyfind.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <list>

int main()
{
	{ // TEST: easyfind on vector
        std::cout << "==== TESTS: easyfind on vector ====\n";
		std::vector<int> grades;
		grades.push_back(2);
		grades.push_back(10);
		grades.push_back(18);

		std::vector<int>::const_iterator ten(easyfind(grades, 10));
		assert(*ten == 10);

		std::vector<int>::const_iterator notFound(easyfind(grades, 3));
		assert(*notFound == *grades.end());

		std::cout << "all tests passed\n";
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: easyfind on list
        std::cout << "==== TESTS: easyfind on list ====\n";

		std::list<int> grades;
		grades.push_back(2);
		grades.push_back(10);
		grades.push_back(18);

		std::list<int>::const_iterator ten(easyfind(grades, 10));
		assert(*ten == 10);

		std::list<int>::const_iterator notFound(easyfind(grades, 3));
		assert(*notFound == *grades.end());

		std::cout << "all tests passed\n";
		
	}
	return 0;
}
