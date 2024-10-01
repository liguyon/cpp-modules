#include "Bureaucrat.h"
#include <iostream>
#include <cassert>

int main()
{
	{ // TEST: basic tests
        std::cout << "==== TESTS: basic tests ====\n";
		Bureaucrat a("Velo", 10);
		std::cout << a << std::endl;
		Bureaucrat b(a);
		std::cout << b << std::endl;
		Bureaucrat c;
		std::cout << c << std::endl;
		c = a;
		std::cout << c << std::endl;
		Bureaucrat def;
		std::cout << def << std::endl;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: exceptions at construction
        std::cout <<
			"==== TESTS: exceptions at construction (uncomment test cases) ====\n";
		// Bureaucrat a("Moto", 0);
		// Bureaucrat a("Deux roues", 151);
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: exceptions increment/decrement
        std::cout <<
			"==== TESTS: exceptions increment/decrement (uncomment test cases) ====\n";
		Bureaucrat a("Deux roux", 1);
		a.decrement();
		assert(a.getGrade() == 2);
		a.increment();
		assert(a.getGrade() == 1);
		// a.increment();

		Bureaucrat b("Quatre roues motrices", 150);
		// b.decrement();
	}

	return 0;
}
