#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_Fixed_pnum = 0;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	if(this != &other)
		this->_Fixed_pnum = other._Fixed_pnum;
}

Fixed &Fixed::operator=(const Fixed & other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_Fixed_pnum = other._Fixed_pnum;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	return (_Fixed_pnum);
}

void Fixed::setRawBits(int const raw){
	_Fixed_pnum = raw;
}
