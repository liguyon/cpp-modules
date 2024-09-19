#include "WrongAnimal.h"
#include <iostream>


WrongAnimal::WrongAnimal()
	: type("WrongAnimal")
{
#ifndef NDEBUG
    std::cout << type << " default constructor called" << std::endl;
#endif
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : type(other.type)
{
#ifndef NDEBUG
    std::cout << type << " copy constructor called" << std::endl;
#endif
}

WrongAnimal::~WrongAnimal()
{
#ifndef NDEBUG
    std::cout << type << " destructor called" << std::endl;
#endif
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy assignment operator called" << std::endl;
#endif

    return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << type << ": Bad Bad Bad !" << std::endl;
}
