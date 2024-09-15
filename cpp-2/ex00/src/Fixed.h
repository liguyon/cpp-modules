#pragma once

class Fixed
{

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator= (const Fixed& fixed);

    int     getRawBits(void) const;
    void    setRawBits(const int raw);


private:
    int                 m_rawBits;
    static const int    s_fractionalBits = 8;

};
