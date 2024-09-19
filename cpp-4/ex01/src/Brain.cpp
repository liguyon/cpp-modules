#include "Brain.h"
#include <iostream>


Brain::Brain()
{
#ifndef NDEBUG
    std::cout << "Brain default constructor called" << std::endl;
#endif
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		m_ideas[i] = other.m_ideas[i];
#ifndef NDEBUG
    std::cout << "Brain copy constructor called" << std::endl;
#endif
}

Brain::~Brain()
{
#ifndef NDEBUG
    std::cout << "Brain destructor called" << std::endl;
#endif
}

Brain& Brain::operator= (const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		m_ideas[i] = other.m_ideas[i];
#ifndef NDEBUG
    std::cout << "Brain copy assignment operator called" << std::endl;
#endif

    return *this;
}

void Brain::setIdea(int i, const std::string& idea)
{
	if (i >= 0 && i < 100)
		m_ideas[i] = idea;
}

const std::string& Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return m_ideas[i];
	else
		return NULL;
}
