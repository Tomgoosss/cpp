#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "--- Testing ClapTrap ---\n";
	ClapTrap clap("Clappy");
	clap.attack("Enemy1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- Testing ScavTrap ---\n";
	ScavTrap scav("Scavvy");
	scav.attack("Guard");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n--- Testing FragTrap ---\n";
	FragTrap frag("Fraggy");
	frag.attack("Target");	// Should attack with 30 damage
	frag.takeDamage(50);	// Should lose 50 HP, down to 50
	frag.beRepaired(25);	// Should heal 25 HP, up to 75
	frag.highFivesGuys();	// Should request high fives
	frag.takeDamage(80);	// Should die (HP = 0)
	frag.attack("Target2"); // Should fail (no HP)
	frag.highFivesGuys();	// Should still work even with 0 HP

	return 0;
}