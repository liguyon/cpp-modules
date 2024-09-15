#pragma once

#include <iostream>

class Fixed
{

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator= (const Fixed& fixed);

    int     getRawBits(void) const;
    void    setRawBits(const int raw);
    int     toInt(void) const;
    float   toFloat(void) const;

private:
    int                 m_rawBits;
    static const int    s_fractionalBits = 8;

};

std::ostream& operator<< (std::ostream& out, const Fixed& fixed);