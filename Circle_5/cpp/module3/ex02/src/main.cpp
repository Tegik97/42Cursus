#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void printSeparator(const std::string& test_name) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "    " << test_name << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

int main() {
	std::cout << "🤖 SCAVTRAP & FRAGTRAP TESTING ARENA 🤖\n" << std::endl;

	// Test 1: Construction/Destruction Chaining
	printSeparator("TEST 1: CONSTRUCTION/DESTRUCTION CHAINING");
	{
		std::cout << "Creating ScavTrap:" << std::endl;
		ScavTrap scav("Guardian");
		
		std::cout << "\nCreating FragTrap:" << std::endl;
		FragTrap frag("Destroyer");
		
		std::cout << "\nEnd of scope - destructors will be called in reverse order:" << std::endl;
	}

	// Test 2: Attack comparison (ScavTrap has override, FragTrap uses ClapTrap's)
	printSeparator("TEST 2: ATTACK COMPARISON");
	{
		ScavTrap scav("ScavWarrior");
		FragTrap frag("FragWarrior");
		
		std::cout << "\nScavTrap attack (20 damage, with override):" << std::endl;
		scav.attack("Target");
		
		std::cout << "\nFragTrap attack (30 damage, no override - uses ClapTrap's):" << std::endl;
		frag.attack("Target");
	}

	// Test 3: Special abilities
	printSeparator("TEST 3: SPECIAL ABILITIES");
	{
		ScavTrap gatekeeper("Fortress");
		FragTrap socialBot("Friendly");
		
		std::cout << "\nScavTrap Gate Keeper mode:" << std::endl;
		gatekeeper.guardGate();
		
		std::cout << "\nFragTrap High Five request:" << std::endl;
		socialBot.highFiveGuys();
	}

	// Test 4: Different HP/Energy values demonstration
	printSeparator("TEST 4: STATS COMPARISON");
	{
		ScavTrap scav("Tank");      // 100 HP, 50 Energy, 20 Attack
		FragTrap frag("PowerHouse"); // 100 HP, 100 Energy, 30 Attack
		
		std::cout << "\nBoth taking 60 damage:" << std::endl;
		scav.takeDamage(60);
		frag.takeDamage(60);
		
		std::cout << "\nBoth repairing (uses 1 energy each):" << std::endl;
		scav.beRepaired(10);
		frag.beRepaired(10);
		
		std::cout << "\nUsing special abilities:" << std::endl;
		scav.guardGate();
		frag.highFiveGuys();
	}

	// Test 5: Energy exhaustion comparison
	printSeparator("TEST 5: ENERGY EXHAUSTION TEST");
	{
		ScavTrap scav("Marathon1");  // 50 energy
		FragTrap frag("Marathon2");  // 100 energy
		
		std::cout << "\nScavTrap exhausting energy (50 total):" << std::endl;
		for (int i = 1; i <= 50; i++) {
			std::cout << "ScavTrap Action " << i << ": ";
			if (i % 2 == 0)
				scav.beRepaired(1);
			else
				scav.attack("Target");
		}
		std::cout << "ScavTrap trying guardGate when out of energy:" << std::endl;
		scav.guardGate();
		
		std::cout << "\nFragTrap can do more actions (100 energy):" << std::endl;
		for (int i = 1; i <= 50; i++) {
			std::cout << "FragTrap Action " << i << ": ";
			frag.attack("Target");
		}
		std::cout << "FragTrap still has energy for high five:" << std::endl;
		for (int i = 51; i <= 100; i++) {
		frag.highFiveGuys();
		}
		std::cout << "ScavTrap trying highFiveGuys when out of energy:" << std::endl;
		frag.highFiveGuys();
	}

	// Test 6: Copy constructors and assignment
	printSeparator("TEST 6: ORTHODOX CANONICAL FORM");
	{
		std::cout << "Testing ScavTrap Orthodox Canonical Form:" << std::endl;
		ScavTrap original_scav("Original");
		ScavTrap copy_scav(original_scav);
		ScavTrap assigned_scav;
		assigned_scav = original_scav;
		
		std::cout << "\nTesting FragTrap Orthodox Canonical Form:" << std::endl;
		FragTrap original_frag("Original");
		FragTrap copy_frag(original_frag);
		FragTrap assigned_frag;
		assigned_frag = original_frag;
	}

	// Test 7: Epic battle scenario
	printSeparator("TEST 7: EPIC BATTLE SCENARIO");
	{
		ScavTrap guardian("Guardian");
		FragTrap destroyer("Destroyer");
		
		std::cout << "\n--- BATTLE SIMULATION ---" << std::endl;
		
		std::cout << "\nRound 1: Pre-battle preparation!" << std::endl;
		guardian.guardGate();
		destroyer.highFiveGuys();
		
		std::cout << "\nRound 2: First attacks!" << std::endl;
		guardian.attack("Destroyer");  // 20 damage with special message
		destroyer.attack("Guardian");  // 30 damage with normal message
		
		std::cout << "\nRound 3: Taking damage!" << std::endl;
		guardian.takeDamage(30);
		destroyer.takeDamage(20);
		
		std::cout << "\nRound 4: Self-repair!" << std::endl;
		guardian.beRepaired(15);
		destroyer.beRepaired(15);
		
		std::cout << "\nRound 5: Final special abilities!" << std::endl;
		guardian.guardGate();
		destroyer.highFiveGuys();
	}

	// Test 8: Dead robots testing
	printSeparator("TEST 8: DEAD ROBOTS TESTING");
	{
		ScavTrap dead_scav("DeadScav");
		FragTrap dead_frag("DeadFrag");
		
		std::cout << "\nKilling both robots:" << std::endl;
		dead_scav.takeDamage(150);
		dead_frag.takeDamage(150);
		
		std::cout << "\nTrying abilities when dead:" << std::endl;
		dead_scav.attack("Ghost");
		dead_scav.guardGate();
		dead_frag.attack("Ghost");
		dead_frag.highFiveGuys();
	}

	printSeparator("END OF TESTS");
	std::cout << "🏆 SCAVTRAP & FRAGTRAP TESTING COMPLETE 🏆" << std::endl;

	return 0;
}