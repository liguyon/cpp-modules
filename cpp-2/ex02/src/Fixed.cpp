#include "Fixed.h"
#include <cmath>

Fixed::Fixed()
    : m_rawBits(0)
{
#ifdef DEBUG
    std::cout << "Defaut constructor called" << std::endl;
#endif
}

Fixed::Fixed(const int n)
    : m_rawBits(n << s_fractionalBits)
{
#ifdef DEBUG
    std::cout << "Int constructor called" << std::endl;
#endif
}

Fixed::Fixed(const float f)
    : m_rawBits(roundf(f * (1 << s_fractionalBits)))
{
#ifdef DEBUG
    std::cout << "Float constructor called" << std::endl;
#endif
}

Fixed::~Fixed()
{
#ifdef DEBUG
    std::cout << "Destructor called" << std::endl;
#endif
}

Fixed::Fixed(const Fixed& fixed) 
    : m_rawBits(fixed.m_rawBits)
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

    m_rawBits = fixed.m_rawBits;
    return *this;
}

int Fixed::getRawBits(void) const
{
#ifdef DEBUG
    std::cout << "getRawBits member function called" << std::endl;
#endif

    return m_rawBits;
}

void Fixed::setRawBits(const int raw)
{
#ifdef DEBUG
    std::cout << "setRawBits member function called" << std::endl;
#endif

    m_rawBits = raw;
}

int Fixed::toInt(void) const
{
    return m_rawBits >> s_fractionalBits;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(m_rawBits) / (1 << s_fractionalBits);
}

std::ostream& operator<< (std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator> (const Fixed& fixed) const
{
    return m_rawBits > fixed.m_rawBits;
}

bool Fixed::operator< (const Fixed& fixed) const
{
    return m_rawBits < fixed.m_rawBits;
}

bool Fixed::operator>= (const Fixed& fixed) const
{
    return !(operator<(fixed));
}

bool Fixed::operator<= (const Fixed& fixed) const
{
    return !(operator>(fixed));
}

bool Fixed::operator== (const Fixed& fixed) const
{
    return m_rawBits == fixed.m_rawBits;
}

bool Fixed::operator!= (const Fixed& fixed) const
{
    return !(operator==(fixed));
}

Fixed Fixed::operator+ (const Fixed& fixed) const
{
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator- (const Fixed& fixed) const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator* (const Fixed& fixed) const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/ (const Fixed& fixed) const
{
    return Fixed(toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++ ()
{
    m_rawBits += 1;
    return *this;
}

Fixed& Fixed::operator-- ()
{
    m_rawBits -= 1;
    return *this;
}

Fixed Fixed::operator++ (int)
{
    Fixed ret(*this);
    ++(*this);
    return ret;
}

Fixed Fixed::operator-- (int)
{
    Fixed ret(*this);
    --(*this);
    return ret;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    return f1 <= f2 ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    return f1 >= f2 ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return f1 <= f2 ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    return f1 >= f2 ? f1 : f2;
}
