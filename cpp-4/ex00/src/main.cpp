#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

int main()
{
	{ // TEST: Animal
        std::cout << "==== TESTS: Animal ====\n";
		Animal a;
		Animal b(a);
		Animal c;
		c = b;
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: Cat
        std::cout << "==== TESTS: Cat ====\n";
		Cat a;
		Cat b(a);
		Cat c;
		c = b;
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: Dog
        std::cout << "==== TESTS: Dog ====\n";
		Dog a;
		Dog b(a);
		Dog c;
		c = b;
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}
	
	std::cout << "\n================================================\n\n";

	{ // TEST: WrongAnimal
        std::cout << "==== TESTS: WrongAnimal ====\n";
		WrongAnimal a;
		WrongAnimal b(a);
		WrongAnimal c;
		c = b;
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}

	std::cout << "\n================================================\n\n";

	{ // TEST: WrongCat
        std::cout << "==== TESTS: WrongCat ====\n";
		WrongCat a;
		WrongCat b(a);
		WrongCat c;
		c = b;
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}

	return 0;
}
