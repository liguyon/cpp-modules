#include "Dog.h"
#include <iostream>


Dog::Dog()
{
	type = "Dog";
#ifndef NDEBUG
    std::cout << type << " default constructor called" << std::endl;
#endif
}

Dog::Dog(const Dog& other)
	: Animal()
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy constructor called" << std::endl;
#endif
}

Dog::~Dog()
{
#ifndef NDEBUG
    std::cout << type << " destructor called" << std::endl;
#endif
}

Dog& Dog::operator= (const Dog& other)
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy assignment operator called" << std::endl;
#endif

    return *this;
}

void Dog::makeSound() const
{
	std::cout << type << ": Waf" << std::endl;
}
