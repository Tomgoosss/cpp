#include "HumanA.hpp"

void HumanA::attack(){
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "constructor HumanA is called" << std::endl;
}