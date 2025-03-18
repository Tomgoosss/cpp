#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot("Robo");

	for (int i = 1; i <= 11; i++)
	{
		robot.attack("Enemy" + std::to_string(i));
	}
	robot.beRepaired(5);
	robot.takeDamage(5);
	robot.attack("Enemy12"); 

	return 0;
}

// int main()
// {
// 	ClapTrap robot("Robo");

// 	robot.attack("Enemy1");
// 	robot.takeDamage(5);
// 	robot.beRepaired(3);
// 	robot.takeDamage(10);	
// 	robot.attack("Enemy2");
// 	robot.beRepaired(5);	

// 	return 0;
// }