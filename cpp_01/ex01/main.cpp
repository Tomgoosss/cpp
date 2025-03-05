#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie *zombs= nullptr;
	try
	{
		zombs = zombieHorde(n ,"wouter");
	}
	catch (std::bad_alloc &e) {
		std::cerr << "error: " << e.what() << std::endl;
		return (1);
	}
	for (int i = 0; i < n; i++)
	{
		zombs[i].announce();
	}
	delete[] zombs;

	return 0;
}