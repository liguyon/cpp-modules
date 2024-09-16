#pragma once

#include <iostream>

class Fixed
{

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    ~Fixed();
    Fixed(const Fixed& fixed);
    Fixed& operator= (const Fixed& fixed);

    // comparison operators
    bool    operator>  (const Fixed& fixed) const;
    bool    operator<  (const Fixed& fixed) const;
    bool    operator>= (const Fixed& fixed) const;
    bool    operator<= (const Fixed& fixed) const;
    bool    operator== (const Fixed& fixed) const;
    bool    operator!= (const Fixed& fixed) const;

    // arithmetic operators
    Fixed   operator+ (const Fixed& fixed) const;
    Fixed   operator- (const Fixed& fixed) const;
    Fixed   operator* (const Fixed& fixed) const;
    Fixed   operator/ (const Fixed& fixed) const;

    // increment/decrement operators
    // prefix
    Fixed&  operator++ ();
    Fixed&  operator-- ();
    // postfix
    Fixed   operator++ (int);
    Fixed   operator-- (int);

    int     getRawBits(void) const;
    void    setRawBits(const int raw);
    int     toInt(void) const;
    float   toFloat(void) const;

    static Fixed& min(Fixed& f1, Fixed& f2);
    static Fixed& max(Fixed& f1, Fixed& f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);
    static const Fixed& max(const Fixed& f1, const Fixed& f2);

private:
    int                 m_rawBits;
    static const int    s_fractionalBits = 8;

};

std::ostream& operator<< (std::ostream& out, const Fixed& fixed);