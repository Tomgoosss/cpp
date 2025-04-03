#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &a) : ClapTrap(a)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &a)
{
	if (this != &a)
	{
		ClapTrap::operator=(a);
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack, it's out of hit points!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack, no energy left!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " fiercely attacks " << target
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " can't enter gate keeper mode, it's out of hit points!" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " can't enter gate keeper mode, no energy left!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}