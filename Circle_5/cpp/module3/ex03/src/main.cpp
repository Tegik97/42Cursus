#include "DiamondTrap.hpp"
#include <iostream>

void printSeparator(const std::string& test_name) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "    " << test_name << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

int main() {
	std::cout << "💎 CLAPTRAP, SCAVTRAP, FRAGTRAP & DIAMONDTRAP TESTING ARENA 💎\n" << std::endl;

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

	// Test 2: ScavTrap Basic Tests
	printSeparator("TEST 2: SCAVTRAP FUNCTIONALITY");
	{
		std::cout << "Creating ScavTrap:" << std::endl;
		ScavTrap scav("Guardian");
		
		std::cout << "\nScavTrap enhanced attack:" << std::endl;
		scav.attack("Bandit");
		
		std::cout << "\nScavTrap special ability:" << std::endl;
		scav.guardGate();
		
		std::cout << "\nEnd of ScavTrap basic tests:" << std::endl;
	}

	// Test 3: FragTrap Basic Tests
	printSeparator("TEST 3: FRAGTRAP FUNCTIONALITY");
	{
		std::cout << "Creating FragTrap:" << std::endl;
		FragTrap frag("Destroyer");
		
		std::cout << "\nFragTrap attack:" << std::endl;
		frag.attack("Target");
		
		std::cout << "\nFragTrap special ability:" << std::endl;
		frag.highFiveGuys();
		
		std::cout << "\nEnd of FragTrap basic tests:" << std::endl;
	}

	// Test 4: Construction/Destruction Chaining with Diamond Inheritance
	printSeparator("TEST 4: DIAMOND INHERITANCE CONSTRUCTION/DESTRUCTION");
	{
		std::cout << "Creating DiamondTrap - watch the construction chain:" << std::endl;
		DiamondTrap diamond("Fusion");
		
		std::cout << "\nEnd of scope - destructors will be called in reverse order:" << std::endl;
	}

	// Test 5: Diamond Problem Resolution - whoAmI function
	printSeparator("TEST 5: DIAMOND PROBLEM - WHO AM I?");
	{
		DiamondTrap diamond("Hybrid");
		
		std::cout << "\nTesting whoAmI() function:" << std::endl;
		diamond.whoAmI();
	}

	// Test 6: Inherited Attributes Values
	printSeparator("TEST 6: DIAMONDTRAP ATTRIBUTES VERIFICATION");
	{
		DiamondTrap diamond("TestStats");
		
		std::cout << "\nVerifying DiamondTrap stats (should be HP: 100-FragTrap, Energy: 50-ScavTrap, Attack: 30-FragTrap):" << std::endl;
		
		std::cout << "\n1. Testing Hit Points (should be 100 like FragTrap):" << std::endl;
		std::cout << "   Taking 99 damage (should survive):" << std::endl;
		diamond.takeDamage(99);
		std::cout << "   Taking 1 more damage (should die):" << std::endl;
		diamond.takeDamage(1);
		std::cout << std::endl << "\nTrying abilities when dead:" << std::endl;
		diamond.attack("Ghost");
		diamond.guardGate();
		diamond.highFiveGuys();
		diamond.whoAmI();
	
		std::cout << "\n2. Testing Energy Points (should be 50 like ScavTrap):" << std::endl;
		DiamondTrap energyTest("EnergyTest");
		std::cout << std::endl << "Performing 50 actions to exhaust energy:" << std::endl;
		for (int i = 1; i <= 50; i++) {
			std::cout << "Action " << i << ": ";
			energyTest.attack("Target");
		}
		std::cout << std::endl << "Trying 51st action (should fail - no energy):" << std::endl;
		energyTest.attack("Target");
		
		std::cout << "\n3. Testing Attack Damage (should be 30 like FragTrap):" << std::endl;
		DiamondTrap attackTest("AttackTest");
		std::cout << "Attack message should show 30 damage:" << std::endl;
		attackTest.attack("TestTarget");
	}

	// Test 7: Attack Function (should use ScavTrap's attack)
	printSeparator("TEST 7: ATTACK FUNCTION - SCAVTRAP INHERITANCE");
	{
		DiamondTrap diamond("Attacker");
		
		std::cout << "\nDiamondTrap attack (should use ScavTrap's attack with 'great strength'):" << std::endl;
		diamond.attack("Enemy");
	}

	// Test 8: Inherited Special Abilities
	printSeparator("TEST 8: INHERITED SPECIAL ABILITIES");
	{
		DiamondTrap diamond("SpecialBot");
		
		std::cout << "\nTesting inherited FragTrap ability:" << std::endl;
		diamond.highFiveGuys();
		
		std::cout << "\nTesting inherited ScavTrap ability:" << std::endl;
		diamond.guardGate();
	}

	// Test 9: Orthodox Canonical Form
	printSeparator("TEST 9: ORTHODOX CANONICAL FORM");
	{
		std::cout << "Testing DiamondTrap Orthodox Canonical Form:" << std::endl;
		
		std::cout << "\nOriginal DiamondTrap:" << std::endl;
		DiamondTrap original("Original");
		
		std::cout << "\nCopy constructor:" << std::endl;
		DiamondTrap copy(original);
		
		std::cout << "\nAssignment operator:" << std::endl;
		DiamondTrap assigned("TempName");
		assigned = original;
		
		std::cout << "\nTesting whoAmI() on all three:" << std::endl;
		original.whoAmI();
		copy.whoAmI();
		assigned.whoAmI();
	}

	// Test 10: Combat Simulation
	printSeparator("TEST 10: DIAMONDTRAP COMBAT SIMULATION");
	{
		DiamondTrap warrior("UltimateWarrior");
		
		std::cout << "\n--- COMBAT SIMULATION ---" << std::endl;
		
		std::cout << "\nRound 1: Pre-battle identity crisis!" << std::endl;
		warrior.whoAmI();
		
		std::cout << "\nRound 2: Special abilities!" << std::endl;
		warrior.guardGate();
		warrior.highFiveGuys();
		
		std::cout << "\nRound 3: Combat!" << std::endl;
		warrior.attack("FinalBoss");
		
		std::cout << "\nRound 4: Taking damage!" << std::endl;
		warrior.takeDamage(30);
		
		std::cout << "\nRound 5: Self-repair!" << std::endl;
		warrior.beRepaired(15);
		
		std::cout << "\nRound 6: Final identity check!" << std::endl;
		warrior.whoAmI();
	}

	printSeparator("END OF TESTS");
	std::cout << "💎 CLAPTRAP, SCAVTRAP, FRAGTRAP & DIAMONDTRAP TESTING COMPLETE 💎" << std::endl;

	return 0;
}