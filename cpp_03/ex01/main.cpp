#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n=== BASIC CLAPTRAP TESTS ===\n";
    ClapTrap robot("Robo");
    robot.attack("Enemy1");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(7);
    robot.attack("Enemy2");
    robot.beRepaired(5);
    


    std::cout << "\n=== CLAPTRAP ENERGY DEPLETION TEST ===\n";
    ClapTrap energyTest("EnergyBot");
    std::cout << "Performing 10 attacks to deplete energy:\n";
    for (int i = 0; i < 12; i++) {
        std::cout << "Attack " << (i + 1) << ": ";
        energyTest.attack("Target");
    }
    std::cout << "Trying to repair after energy depletion: ";
    energyTest.beRepaired(5);
    


    std::cout << "\n=== CLAPTRAP DEATH TEST ===\n";
    ClapTrap mortal("Morty");
    mortal.takeDamage(5);
    std::cout << "After 5 damage, can still attack: ";
    mortal.attack("Someone");
    mortal.takeDamage(10);
    std::cout << "After lethal damage, cannot attack: ";
    mortal.attack("Someone");
    std::cout << "After death, cannot repair: ";
    mortal.beRepaired(100);



    std::cout << "\n=== BASIC SCAVTRAP TESTS ===\n";
    ScavTrap scav("Scavvy");
    scav.attack("Guard");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    scav.takeDamage(100);
    scav.attack("Intruder");
    

    // std::cout << "\n=== SCAVTRAP ENERGY DEPLETION TEST ===\n";
    // ScavTrap scavEnergy("ScavEnergy");
    // std::cout << "Performing 50 attacks to deplete energy:\n";
    // for (int i = 0; i < 52; i++) {
    //     if (i % 10 == 0 || i > 47) {
    //         std::cout << "Attack " << (i + 1) << ": ";
    //         scavEnergy.attack("Target");
    //     } else {
    //         scavEnergy.attack("Target");
    //     }
    // }
    // std::cout << "Trying to repair after energy depletion: ";
    // scavEnergy.beRepaired(5);
    // std::cout << "Trying to guard gate after energy depletion: ";
    // scavEnergy.guardGate();
    

    // std::cout << "\n=== COPY CONSTRUCTOR AND ASSIGNMENT TEST ===\n";
    // ScavTrap original("Original");
    // original.takeDamage(30);  // Damage the original
    
    // std::cout << "Creating copy via copy constructor:\n";
    // ScavTrap copy(original);
    // std::cout << "Testing copy (should have 30 damage already):\n";
    // copy.attack("Someone");
    
    // std::cout << "Creating another via assignment:\n";
    // ScavTrap assigned("WillBeOverwritten");
    // assigned = original;
    // std::cout << "Testing assigned ScavTrap:\n";
    // assigned.attack("Someone");
    
    // return 0;
}