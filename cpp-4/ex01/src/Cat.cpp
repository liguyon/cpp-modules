#include "Cat.h"
#include <iostream>


Cat::Cat()
	: Animal(), m_brain(new Brain())
{
	type = "Cat";
#ifndef NDEBUG
    std::cout << type << " default constructor called" << std::endl;
#endif
}

Cat::Cat(const Cat& other)
	: Animal(), m_brain(new Brain(*other.m_brain))
{
	type = other.type;
#ifndef NDEBUG
    std::cout << type << " copy constructor called" << std::endl;
#endif
}

Cat::~Cat()
{
	delete m_brain;
#ifndef NDEBUG
    std::cout << type << " destructor called" << std::endl;
#endif
}

Cat& Cat::operator= (const Cat& other)
{
	*m_brain = *other.m_brain;
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

Brain* Cat::getBrain() const
{
	return m_brain;
}
