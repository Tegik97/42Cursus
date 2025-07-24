#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	// Test del subject
	{
		std::cout << "=== SUBJECT TESTS ===" << std::endl;
		
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << std::endl << "=== ADDITIONAL TESTS ===" << std::endl;
		
		// Test aggiuntivi per deep copy
		std::cout << "--- Testing deep copy ---" << std::endl;
		Character original("Cloud");
		original.equip(new Ice());
		original.equip(new Cure());
		
		Character copy = original;
		Character* cloud = new Character("Sephiroth");
		
		std::cout << "Original uses ice on cloud: ";
		original.use(0, *cloud);
		std::cout << "Copy uses ice on cloud: ";
		copy.use(0, *cloud);

		// Test unequip
		std::cout << "\n--- Testing unequip ---" << std::endl;
		original.unequip(0);
		std::cout << "After unequip, original uses slot 0: ";
		original.use(0, *cloud);  // Should do nothing
		std::cout << "Copy still has ice: ";
		copy.use(0, *cloud);

		delete cloud;
	}
	
	{
		// Test MateriaSource
		std::cout << "\n--- Testing MateriaSource ---" << std::endl;
		MateriaSource source;
		source.learnMateria(new Ice());
		source.learnMateria(new Cure());
		
		AMateria* ice_materia = source.createMateria("ice");
		AMateria* cure_materia = source.createMateria("cure");
		AMateria* unknown = source.createMateria("fireball");
		
		if (ice_materia)
		{
			std::cout << "Created: " << ice_materia->getType() << std::endl;
			delete ice_materia;
		}
		if (cure_materia)
		{
			std::cout << "Created: " << cure_materia->getType() << std::endl;
			delete cure_materia;
		}
		if (!unknown)
			std::cout << "Unknown materia returned 0" << std::endl;
		
		// Test inventory full
		std::cout << "\n--- Testing full inventory ---" << std::endl;
		Character full_char("Tifa");
		for (int i = 0; i < 5; i++)  // Try to equip 5 items (inventory has only 4 slots)
		{
			AMateria* materia = source.createMateria(i % 2 == 0 ? "ice" : "cure");
			if (materia)
				full_char.equip(materia);
		}
	}
	
	return 0;
}
