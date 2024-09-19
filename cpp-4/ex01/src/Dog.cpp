#include "Dog.h"
#include <iostream>


Dog::Dog()
	: Animal(), m_brain(new Brain())
{
	type = "Dog";
#ifndef NDEBUG
    std::cout << type << " default constructor called" << std::endl;
#endif
}

Dog::Dog(const Dog& other)
	: Animal(), m_brain(new Brain(*other.m_brain))
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy constructor called" << std::endl;
#endif
}

Dog::~Dog()
{
	delete m_brain;
#ifndef NDEBUG
    std::cout << type << " destructor called" << std::endl;
#endif
}

Dog& Dog::operator= (const Dog& other)
{
	*m_brain = *other.m_brain;
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

Brain* Dog::getBrain() const
{
	return m_brain;
}
