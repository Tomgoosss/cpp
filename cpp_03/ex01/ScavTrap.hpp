#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &a);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &a);

	void attack(const std::string &target);
	void guardGate();
};

#endif