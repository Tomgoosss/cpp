#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie " << _name << " has risen from the ground" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has crawled back into the ground" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	_name = name;
}