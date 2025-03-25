#include "Zombie.hpp"

int main()
{
	randomChump("stan");
	Zombie *zombie = NULL;
	try {
		zombie = newZombie("vincent");
	}
	catch (std::exception &e) {
		std::cerr << "error: " << e.what() << std::endl;
		return (1);
	}
	delete zombie;     
    return 0;
}