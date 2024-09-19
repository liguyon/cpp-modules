#include "Cat.h"
#include <iostream>


Cat::Cat()
{
	type = "Cat";
#ifndef NDEBUG
    std::cout << type << " default constructor called" << std::endl;
#endif
}

Cat::Cat(const Cat& other)
	: Animal()
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy constructor called" << std::endl;
#endif
}

Cat::~Cat()
{
#ifndef NDEBUG
    std::cout << type << " destructor called" << std::endl;
#endif
}

Cat& Cat::operator= (const Cat& other)
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy assignment operator called" << std::endl;
#endif

    return *this;
}

void Cat::makeSound() const
{
	std::cout << type << ": Meow" << std::endl;
}
