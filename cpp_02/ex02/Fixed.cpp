#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_Fixed_pnum = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &other)
		this->_Fixed_pnum = other._Fixed_pnum;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_Fixed_pnum = other._Fixed_pnum;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int convert)
{
	std::cout << "Int constructor called: converting to fixed-point value" << std::endl;
	_Fixed_pnum = convert << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "const float constructor called: converting to fixed-point value" << std::endl;
	_Fixed_pnum = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (float)_Fixed_pnum / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _Fixed_pnum >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fp)
{
	float temp = fp.toFloat();
	os << temp;
	return os;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_Fixed_pnum > other._Fixed_pnum;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_Fixed_pnum < other._Fixed_pnum;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_Fixed_pnum >= other._Fixed_pnum;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_Fixed_pnum <= other._Fixed_pnum;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_Fixed_pnum == other._Fixed_pnum;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_Fixed_pnum != other._Fixed_pnum;
}

Fixed Fixed::operator+(const Fixed &other) const{
	Fixed result;
	
	result._Fixed_pnum = this->_Fixed_pnum + other._Fixed_pnum;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const{
	Fixed result;

	result._Fixed_pnum = this->_Fixed_pnum - other._Fixed_pnum;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long temp = (long)this->_Fixed_pnum * (long)other._Fixed_pnum >> _fractionalBits;
	result._Fixed_pnum = temp;
	return (result);
}
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result._Fixed_pnum = this->_Fixed_pnum / other._Fixed_pnum;
	return (result);
}

//pre
Fixed& Fixed::operator++(){
	this->_Fixed_pnum++;
	return (*this);
}

// post
Fixed Fixed::operator++(int){
	Fixed old = *this;
	this->_Fixed_pnum++;
	return (old);
}

// pre
Fixed& Fixed::operator--(){
	this->_Fixed_pnum--;
	return (*this);
}
// post
Fixed Fixed::operator--(int){
	Fixed old = *this;
	this->_Fixed_pnum--;
	return (old);
}

Fixed Fixed::min(Fixed &a, Fixed &b){
	if(a < b)
		return a;
	return b;
}

Fixed Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return a;
	return b;
}

Fixed Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return a;
	return b;
}

Fixed Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return a;
	return b;
}