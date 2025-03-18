#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap robot("Robo");
	robot.attack("Enemy1");
	robot.takeDamage(5);
	robot.beRepaired(3);
	robot.takeDamage(7);
	robot.attack("Enemy2");
	robot.beRepaired(5);

	std::cout << "\n--- Testing ScavTrap ---\n";

	ScavTrap scav("Scavvy");
	scav.attack("Guard");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	scav.takeDamage(100);
	scav.attack("Intruder");

	return 0;
}