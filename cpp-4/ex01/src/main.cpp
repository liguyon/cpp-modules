#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

int main()
{
	{ // TEST: Cat, deep cpy
        std::cout << "==== TESTS: Cat, deep copy ====\n";
		Cat a;
		a.getBrain()->setIdea(0, "initial idea");
		Cat b(a);
		Cat c;
		c = b;
		std::cout << a.getBrain()->getIdea(0) << std::endl;
		std::cout << c.getBrain()->getIdea(0) << std::endl;
		c.getBrain()->setIdea(0, "i think i can eat dog food");
		std::cout << a.getBrain()->getIdea(0) << std::endl;
		std::cout << c.getBrain()->getIdea(0) << std::endl;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: Dog, deep copy
        std::cout << "==== TESTS: Dog, deep copy ====\n";
		Dog a;
		a.getBrain()->setIdea(0, "initial idea");
		Dog b(a);
		Dog c;
		c = b;
		std::cout << a.getBrain()->getIdea(0) << std::endl;
		std::cout << c.getBrain()->getIdea(0) << std::endl;
		c.getBrain()->setIdea(0, "i think i can eat cat food");
		std::cout << a.getBrain()->getIdea(0) << std::endl;
		std::cout << c.getBrain()->getIdea(0) << std::endl;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: Array of animals
        std::cout << "==== TESTS: Array of animals ====\n";
		const int countAnimals = 2;
		Animal* animals[countAnimals];
		for (int i = 0; i < countAnimals / 2; ++i)
			animals[i] = new Cat();
		for (int i = countAnimals / 2; i < countAnimals; ++i)
			animals[i] = new Dog();
		for (int i = 0; i < countAnimals; ++i)
			delete animals[i];
	}

	return 0;
}
