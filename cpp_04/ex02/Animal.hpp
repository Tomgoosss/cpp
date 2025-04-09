#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "string"
#include "iostream"

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	// Existing members
	std::string getType() const;
	virtual void makeSound() const = 0; // Pure virtual function
};

#endif