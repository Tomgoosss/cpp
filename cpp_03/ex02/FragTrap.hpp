#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &a);
	~FragTrap();
	FragTrap &operator=(const FragTrap &a);

	void attack(const std::string &target);
	void highFivesGuys(void);
};

#endif