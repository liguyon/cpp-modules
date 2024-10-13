#include "ScalarConverter.h"
#include <iostream>
#include <iomanip>

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "usage: ./convert literal" << "\n";
		return 0;
	}

	{ // TEST: non instantiable
        std::cout << "==== TESTS: non instantiable (remove comment) ====\n";
		// ScalarConverter a;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: scalar converter
        std::cout << "==== TESTS: scalar converter ====\n";
		std::cout << std::setprecision(1) << std::fixed;
		ScalarConverter::convert(av[1]);

	}

	return 0;
}
