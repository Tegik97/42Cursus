#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>

std::string toString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void printSeparator(const std::string& test_name) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "    " << test_name << std::endl;
    std::cout << std::string(50, '=') << "\n" << std::endl;
}

int main() {
    std::cout << "🤖 CLAPTRAP & SCAVTRAP TESTING ARENA 🤖\n" << std::endl;

    // Test 1: ClapTrap Basic Tests
    printSeparator("TEST 1: CLAPTRAP BASIC FUNCTIONALITY");
    {
        std::cout << "Creating ClapTrap with default constructor:" << std::endl;
        ClapTrap default_clap;
        
        std::cout << "\nCreating ClapTrap with name constructor:" << std::endl;
        ClapTrap named_clap("BasicWarrior");
        
        std::cout << "\nClapTrap basic attacks:" << std::endl;
        named_clap.attack("Training Dummy");
        named_clap.attack("Evil Robot");
        
        std::cout << "\nClapTrap taking damage and repairing:" << std::endl;
        named_clap.takeDamage(3);
        named_clap.beRepaired(2);
        
        std::cout << "\nEnd of ClapTrap basic tests:" << std::endl;
    }

    // Test 2: Construction/Destruction Chaining
    printSeparator("TEST 2: CONSTRUCTION/DESTRUCTION CHAINING");
    {
        std::cout << "Creating ScavTrap with default constructor:" << std::endl;
        ScavTrap default_scav;
        
        std::cout << "\nCreating ScavTrap with name constructor:" << std::endl;
        ScavTrap named_scav("Guardian");
        
        std::cout << "\nCreating ScavTrap with copy constructor:" << std::endl;
        ScavTrap copy_scav(named_scav);
        
        std::cout << "\nTesting assignment operator:" << std::endl;
        ScavTrap assigned_scav;
        assigned_scav = named_scav;
        
        std::cout << "\nEnd of constructor tests (destructors will be called in reverse order):" << std::endl;
    }

    // Test 3: ScavTrap Enhanced Attacks
    printSeparator("TEST 3: SCAVTRAP ENHANCED ATTACKS");
    {
        ScavTrap warrior("Berserker");
        
        std::cout << "\nPerforming enhanced attacks:" << std::endl;
        warrior.attack("Bandit");
        warrior.attack("Psycho");
        warrior.attack("Boss Raider");
    }

    // Test 4: Gate Keeper Mode
    printSeparator("TEST 4: GATE KEEPER SPECIAL ABILITY");
    {
        ScavTrap gatekeeper("Sentinel");
        
        std::cout << "\nActivating Gate Keeper mode:" << std::endl;
        gatekeeper.guardGate();
        
        std::cout << "\nTesting multiple activations:" << std::endl;
        gatekeeper.guardGate();
        gatekeeper.guardGate();
    }

    // Test 5: Enhanced Stats Testing
    printSeparator("TEST 5: ENHANCED STATS VERIFICATION");
    {
        ScavTrap tank("IronWall");
        
        std::cout << "\nTesting enhanced hit points (should survive 50+ damage):" << std::endl;
        tank.takeDamage(30);
        tank.attack("Enemy");
        tank.takeDamage(40);
        tank.attack("Another Enemy");
        tank.takeDamage(50); // Should still survive
        
        std::cout << "\nTrying to repair:" << std::endl;
        tank.beRepaired(20);
    }

    // Test 6: Energy Exhaustion with Enhanced Pool
    printSeparator("TEST 6: ENHANCED ENERGY POOL TEST");
    {
        ScavTrap energetic("Marathon");
        
        std::cout << "\nUsing enhanced energy pool (50 points):" << std::endl;
        for (int i = 1; i <= 15; i++) {
            std::cout << "Action " << i << ": ";
            if (i % 3 == 0) {
                energetic.beRepaired(2);
            } else if (i % 2 == 0) {
                energetic.guardGate();
            } else {
                energetic.attack("Target" + toString(i));
            }
        }
        
        std::cout << "\nTrying actions after exhaustion:" << std::endl;
        energetic.attack("Final Target");
        energetic.guardGate();
    }

    // Test 7: Battle Simulation
    printSeparator("TEST 7: SCAVTRAP BATTLE SIMULATION");
    {
        ScavTrap hero("ScavHero");
        
        std::cout << "\n--- INTENSE BATTLE SCENARIO ---" << std::endl;
        
        std::cout << "\nRound 1: Hero enters Gate Keeper mode!" << std::endl;
        hero.guardGate();
        
        std::cout << "\nRound 2: Hero launches powerful attack!" << std::endl;
        hero.attack("Vault Hunter");
        
        std::cout << "\nRound 3: Hero takes significant damage!" << std::endl;
        hero.takeDamage(60);
        
        std::cout << "\nRound 4: Hero repairs itself!" << std::endl;
        hero.beRepaired(25);
        
        std::cout << "\nRound 5: Final assault!" << std::endl;
        hero.attack("Final Boss");
        
        std::cout << "\nRound 6: Critical damage!" << std::endl;
        hero.takeDamage(80);
        
        std::cout << "\nRound 7: Desperate attempts while heavily damaged!" << std::endl;
        hero.attack("Last Enemy");
        hero.guardGate();
    }

    // Test 8: Death and Revival Attempts
    printSeparator("TEST 8: DEATH SCENARIOS");
    {
        ScavTrap victim("Sacrifice");
        
        std::cout << "\nDealing fatal damage:" << std::endl;
        victim.takeDamage(150); // More than 100 HP
        
        std::cout << "\nTrying actions while dead:" << std::endl;
        victim.attack("Ghost");
        victim.beRepaired(50);
        victim.guardGate();
    }

    // Test 9: Comparison with Base Values
    printSeparator("TEST 9: INHERITANCE VERIFICATION");
    {
        std::cout << "Creating both ClapTrap and ScavTrap for comparison:" << std::endl;
        
        std::cout << "\n--- Creating ClapTrap ---" << std::endl;
        ClapTrap basic("BasicBot");
        
        std::cout << "\n--- Creating ScavTrap ---" << std::endl;
        ScavTrap advanced("AdvancedBot");
        
        std::cout << "\n--- Comparing attack power ---" << std::endl;
        std::cout << "ClapTrap attack: ";
        basic.attack("Test Target");
        std::cout << "ScavTrap attack: ";
        advanced.attack("Test Target");
        
        std::cout << "\n--- ScavTrap special ability ---" << std::endl;
        advanced.guardGate();
        
        std::cout << "\nEnd of comparison test:" << std::endl;
    }

    printSeparator("END OF SCAVTRAP TESTS");
    std::cout << "All ClapTrap and ScavTrap tests completed! Verify construction/destruction chaining above." << std::endl;
    std::cout << "🏆 CLAPTRAP & SCAVTRAP TESTING COMPLETE 🏆" << std::endl;

    return 0;
}
