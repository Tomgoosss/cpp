#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &a) : ClapTrap(a)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &a)
{
	if (this != &a)
	{
		ClapTrap::operator=(a);
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " can't attack, it's out of hit points!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " can't attack, no energy left!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}