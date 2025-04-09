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
    frag.highFivesGuys();	// Should fail (no HP)



    // std::cout << "\n--- Testing FragTrap Energy Depletion ---\n";
    // FragTrap energyFrag("EnergeFrag");
    // std::cout << "Performing attacks to deplete energy (showing every 10th):\n";
    // for (int i = 0; i < 102; i++) {
    //     if (i % 10 == 0 || i > 97) {
    //         std::cout << "Attack " << (i + 1) << ": ";
    //         energyFrag.attack("EnergyTarget");
    //     } else {
    //         energyFrag.attack("EnergyTarget"); // No output for most attacks
    //     }
    // }
    
    // std::cout << "Trying to repair after energy depletion: ";
    // energyFrag.beRepaired(10);
    // std::cout << "Trying high five after energy depletion: ";
    // energyFrag.highFivesGuys();




    // std::cout << "\n--- Testing Copy Constructor and Assignment Operator ---\n";
    // FragTrap original("Original");
    // original.takeDamage(30);  // Now at 70 HP
    
    // std::cout << "Creating copy via copy constructor:\n";
    // FragTrap copied(original);
    // std::cout << "Testing copied FragTrap (should have 30 damage already):\n";
    // copied.attack("CopyTarget");
    
    // std::cout << "Creating assignment via assignment operator:\n";
    // FragTrap assigned("WillBeOverwritten");
    // assigned = original;
    // std::cout << "Testing assigned FragTrap (should have original's state):\n";
    // assigned.attack("AssignTarget");
    
    // std::cout << "\n--- Testing Construction/Destruction Chaining ---\n";
    // std::cout << "Creating nested scope to observe destruction order:\n";
    // {
    //     std::cout << "First creating a ClapTrap:\n";
    //     ClapTrap basic("Basic");
        
    //     std::cout << "Then creating a ScavTrap:\n";
    //     ScavTrap mid("Middle");
        
    //     std::cout << "Finally creating a FragTrap:\n";
    //     FragTrap advanced("Advanced");
        
    //     std::cout << "Now exiting scope, they should be destroyed in reverse order:\n";
    // }
    // std::cout << "Scope exited, all objects destroyed\n";

    return 0;
}