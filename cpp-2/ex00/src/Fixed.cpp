#include "Fixed.h"
#include <iostream>

Fixed::Fixed()
    : m_value(0)
{
#ifdef DEBUG
    std::cout << "Defaut constructor called" << std::endl;
#endif
}

Fixed::~Fixed()
{
#ifdef DEBUG
    std::cout << "Destructor called" << std::endl;
#endif
}

Fixed::Fixed(const Fixed& fixed) 
    : m_value(fixed.m_value)
{
#ifdef DEBUG
    std::cout << "Copy constructor called" << std::endl;
#endif
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
#ifdef DEBUG
    std::cout << "Copy assignment operator called" << std::endl;
#endif

    m_value = fixed.m_value;
    return *this;
}

int Fixed::getRawBits(void) const
{
#ifdef DEBUG
    std::cout << "getRawBits member function called" << std::endl;
#endif

    return m_value;
}

void Fixed::setRawBits(const int raw)
{
#ifdef DEBUG
    std::cout << "setRawBits member function called" << std::endl;
#endif

    m_value = raw;
}
