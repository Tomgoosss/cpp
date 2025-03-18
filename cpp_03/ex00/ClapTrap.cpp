#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a) : _name(a._name), _hitPoints(a._hitPoints), _energyPoints(a._energyPoints), _attackDamage(a._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a)
{
	if (this != &a)
	{
		_name = a._name;
		_hitPoints = a._hitPoints;
		_energyPoints = a._energyPoints;
		_attackDamage = a._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack, it's out of hit points!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack, no energy left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already out of hit points!" << std::endl;
		return;
	}
	if (amount > _hitPoints)
		_hitPoints = 0;
		else
		_hitPoints -= amount;
	if (_hitPoints == 0){
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage, " << "and dies!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, " << _hitPoints << " hit points remaining!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair, no hit points left!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair, no energy left!" << std::endl;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount
			  << " hit points. Now at " << _hitPoints << " hit points!" << std::endl;
}