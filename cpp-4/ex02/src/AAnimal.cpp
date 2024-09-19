#include "AAnimal.h"
#include <iostream>


AAnimal::AAnimal()
    : type("Urmetazoan")
{
#ifndef NDEBUG
    std::cout << "Urmetazoan default constructor called" << std::endl;
#endif
}

AAnimal::AAnimal(const AAnimal& other)
    : type(other.type)
{
#ifndef NDEBUG
    std::cout << "Urmetazoan copy constructor called" << std::endl;
#endif
}

AAnimal::~AAnimal()
{
#ifndef NDEBUG
    std::cout << "Urmetazoan destructor called" << std::endl;
#endif
}

AAnimal& AAnimal::operator= (const AAnimal& other)
{
	type = other.type;
#ifndef NDEBUG
    std::cout << "Urmetazoan copy assignment operator called" << std::endl;
#endif

    return *this;
}
