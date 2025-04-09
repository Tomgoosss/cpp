#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "string"
#include "iostream"

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	// Existing members
	std::string getType() const;
	virtual void makeSound() const;
};

#endif