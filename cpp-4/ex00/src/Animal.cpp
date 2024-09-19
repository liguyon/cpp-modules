#include "Animal.h"
#include <iostream>


Animal::Animal()
	: type("Urmetazoan") // last common ancestor of animals
{
#ifndef NDEBUG
    std::cout << type << " default constructor called" << std::endl;
#endif
}

Animal::Animal(const Animal& other)
    : type(other.type)
{
#ifndef NDEBUG
    std::cout << type << " copy constructor called" << std::endl;
#endif
}

Animal::~Animal()
{
#ifndef NDEBUG
    std::cout << type << " destructor called" << std::endl;
#endif
}

Animal& Animal::operator= (const Animal& other)
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy assignment operator called" << std::endl;
#endif

    return *this;
}

void Animal::makeSound() const
{
	std::cout << type << ": Oh boi, you're not ready for what's to come" << std::endl;
}
