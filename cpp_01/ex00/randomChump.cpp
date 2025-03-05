#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie normal(name);
	normal.announce();
}