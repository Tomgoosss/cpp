#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _Fixed_pnum;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int convert);
	Fixed(const float value);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	

	float toFloat(void) const;
	int toInt(void) const;
	int get_pnum() const;
	int get_bits() const;
};
std::ostream &operator<<(std::ostream &os, const Fixed &fp);

#endif