#include "Animal.h"
#include <iostream>


Animal::Animal()
	: type("Urmetazoan") // last common ancestor of animals
{
#ifndef NDEBUG
    std::cout << "Urmetazoan default constructor called" << std::endl;
#endif
}

Animal::Animal(const Animal& other)
    : type(other.type)
{
#ifndef NDEBUG
    std::cout << "Urmetazoan copy constructor called" << std::endl;
#endif
}

Animal::~Animal()
{
#ifndef NDEBUG
    std::cout << "Urmetazoan destructor called" << std::endl;
#endif
}

Animal& Animal::operator= (const Animal& other)
{
	type = other.type;
#ifndef NDEBUG
    std::cout << "Urmetazoan copy assignment operator called" << std::endl;
#endif

    return *this;
}

void Animal::makeSound() const
{
	std::cout << "Urmetazoan: Oh boi, you're not ready for what's to come" << std::endl;
}
