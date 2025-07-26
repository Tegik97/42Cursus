/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:31:00 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 15:39:14 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

void printSeparator(const std::string& test_name) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "    " << test_name << std::endl;
    std::cout << std::string(50, '=') << "\n" << std::endl;
}

int main() {
    std::cout << "🤖 CLAPTRAP TESTING ARENA 🤖\n" << std::endl;

    printSeparator("TEST 1: CONSTRUCTORS");
    {
        std::cout << "Creating ClapTrap with default constructor:" << std::endl;
        ClapTrap default_clap;
        
        std::cout << "\nCreating ClapTrap with name constructor:" << std::endl;
        ClapTrap named_clap("Warrior");
        
        std::cout << "\nCreating ClapTrap with copy constructor:" << std::endl;
        ClapTrap copy_clap(named_clap);
        
        std::cout << "\nTesting assignment operator:" << std::endl;
        ClapTrap assigned_clap;
        assigned_clap = named_clap;
        
        std::cout << "\nEnd of constructor tests (destructors will be called):" << std::endl;
    }

    printSeparator("TEST 2: NORMAL ATTACKS");
    {
        ClapTrap fighter("Gladiator");
        
        std::cout << "\nPerforming attacks:" << std::endl;
        fighter.attack("Training Dummy");
        fighter.attack("Evil Robot");
        fighter.attack("Boss Enemy");
    }

    printSeparator("TEST 3: TAKING DAMAGE");
    {
        ClapTrap victim("Tank");
        
        std::cout << "\nTaking small damage:" << std::endl;
        victim.takeDamage(3);
        
        std::cout << "\nTaking more damage:" << std::endl;
        victim.takeDamage(5);
        
        std::cout << "\nTaking fatal damage:" << std::endl;
        victim.takeDamage(10); // Should set HP to 0
        
        std::cout << "\nTrying to damage when already dead:" << std::endl;
        victim.takeDamage(5); // Should show "too damaged" message
    }

    printSeparator("TEST 4: REPAIRS");
    {
        ClapTrap medic("Healer");
        
        std::cout << "\nTaking some damage first:" << std::endl;
        medic.takeDamage(7);
        
        std::cout << "\nRepairing:" << std::endl;
        medic.beRepaired(3);
        medic.beRepaired(2);
    }

    printSeparator("TEST 5: ENERGY EXHAUSTION");
    {
        ClapTrap tired("Marathon");
        
        std::cout << "\nExhausting energy with attacks and repairs:" << std::endl;
        for (int i = 1; i <= 12; i++) {
            if (i % 2 == 0) {
                std::cout << "Action " << i << ": ";
                tired.beRepaired(1);
            } else {
                std::cout << "Action " << i << ": ";
                tired.attack("Target");
            }
        }
    }

    printSeparator("TEST 6: COMPLEX BATTLE SCENARIO");
    {
        ClapTrap hero("Hero");
        
        std::cout << "\n--- BATTLE SIMULATION ---" << std::endl;
        
        std::cout << "\nRound 1: Hero attacks!" << std::endl;
        hero.attack("Goblin");
        
        std::cout << "\nRound 2: Hero takes counter-attack!" << std::endl;
        hero.takeDamage(4);
        
        std::cout << "\nRound 3: Hero repairs!" << std::endl;
        hero.beRepaired(2);
        
        std::cout << "\nRound 4: Hero attacks again!" << std::endl;
        hero.attack("Goblin");
        
        std::cout << "\nRound 5: Heavy damage!" << std::endl;
        hero.takeDamage(8);
        
        std::cout << "\nRound 6: Trying to fight while heavily damaged!" << std::endl;
        hero.attack("Final Boss");
        hero.beRepaired(1);
    }

    printSeparator("TEST 7: DEAD CLAPTRAP ACTIONS");
    {
        ClapTrap zombie("Undead");
        
        std::cout << "\nKilling the ClapTrap:" << std::endl;
        zombie.takeDamage(15);
        
        std::cout << "\nTrying actions while dead:" << std::endl;
        zombie.attack("Ghost");
        zombie.beRepaired(5);
        zombie.takeDamage(1);
    }

    printSeparator("END OF TESTS");
    std::cout << "🏆 CLAPTRAP TESTING COMPLETE 🏆" << std::endl;

    return 0;
}
