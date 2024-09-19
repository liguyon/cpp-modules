#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

int main()
{
	{ // TEST: abstract base class
        std::cout << "==== TESTS: abstract base class ====\n";
		// AAnimal a; AAnimal is an abstract base class, thus cannot be instantiated
		Cat a;
	}

    std::cout << "\n================================================\n\n";

	return 0;
}
