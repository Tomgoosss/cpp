#include "Zombie.hpp"

int main()
{
	randomChump("stan");
	Zombie *zombie = nullptr;
	try {
		zombie = newZombie("vincent");
	}
	catch (std::bad_alloc &e) {
		std::cerr << "error: " << e.what() << std::endl;
		return (1);
	}
	delete zombie;     
    return 0;
}