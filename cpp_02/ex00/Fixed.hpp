#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _Fixed_pnum;
	static const int _fractionalBits = 8;
public:
	// Orthodox Canonical Form / OCF
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other); // Copy assignment operator
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif