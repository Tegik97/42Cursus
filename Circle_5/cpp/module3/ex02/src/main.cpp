/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:31:35 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 15:45:15 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void printSeparator(const std::string& test_name) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "    " << test_name << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

int main() {
	std::cout << "🤖 CLAPTRAP, SCAVTRAP & FRAGTRAP TESTING ARENA 🤖\n" << std::endl;

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

	printSeparator("TEST 2: CONSTRUCTION/DESTRUCTION CHAINING");
	{
		std::cout << "Creating ScavTrap:" << std::endl;
		ScavTrap scav("Guardian");
		
		std::cout << "\nCreating FragTrap:" << std::endl;
		FragTrap frag("Destroyer");
		
		std::cout << "\nEnd of scope - destructors will be called in reverse order:" << std::endl;
	}

	printSeparator("TEST 3: ATTACK COMPARISON");
	{
		ScavTrap scav("ScavWarrior");
		FragTrap frag("FragWarrior");
		
		std::cout << "\nScavTrap attack (20 damage, with override):" << std::endl;
		scav.attack("Target");
		
		std::cout << "\nFragTrap attack (30 damage, no override - uses ClapTrap's):" << std::endl;
		frag.attack("Target");
	}

	printSeparator("TEST 4: ENERGY EXHAUSTION TEST");
	{
		ScavTrap scav("Marathon1");
		FragTrap frag("Marathon2");
		
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
			std::cout << "FragTrap Action " << i << ": ";
			frag.highFiveGuys();
		}
		std::cout << "FragTrap trying highFiveGuys when out of energy:" << std::endl;
		frag.highFiveGuys();
	}

	printSeparator("TEST 5: EPIC BATTLE SCENARIO");
	{
		ScavTrap guardian("Guardian");
		FragTrap destroyer("Destroyer");
		
		std::cout << "\n--- BATTLE SIMULATION ---" << std::endl;
		
		std::cout << "\nRound 1: Pre-battle preparation!" << std::endl;
		guardian.guardGate();
		destroyer.highFiveGuys();
		
		std::cout << "\nRound 2: First attacks!" << std::endl;
		guardian.attack("Destroyer");
		destroyer.attack("Guardian");
		
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

	printSeparator("TEST 6: DEAD ROBOTS TESTING");
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
	std::cout << "🏆 CLAPTRAP, SCAVTRAP & FRAGTRAP TESTING COMPLETE 🏆" << std::endl;

	return 0;
}