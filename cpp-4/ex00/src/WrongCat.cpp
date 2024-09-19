#include "WrongCat.h"
#include <iostream>


WrongCat::WrongCat()
{
	type = "WrongCat";
#ifndef NDEBUG
    std::cout << type << " default constructor called" << std::endl;
#endif
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal()
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy constructor called" << std::endl;
#endif
}

WrongCat::~WrongCat()
{
#ifndef NDEBUG
    std::cout << type << " destructor called" << std::endl;
#endif
}

WrongCat& WrongCat::operator= (const WrongCat& other)
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy assignment operator called" << std::endl;
#endif

    return *this;
}
