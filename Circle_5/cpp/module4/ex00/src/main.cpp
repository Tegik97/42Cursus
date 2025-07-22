#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	printSeparator(const std::string& test_name)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "    " << test_name << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

int	main(void)
{
	std::cout << "🐶🐱 Cat & Dog Polymorphism tests 🐱🐶\n" << std::endl;

	//Each class type and makeSound
	{
	printSeparator("TEST 1: CORRECT POLYMORPHISM - VIRTUAL FUNCTIONS");
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "\nAnimal type: ";
	std::cout << meta->getType() << std::endl;
	std::cout << "Dog type: ";
	std::cout << j->getType() << std::endl;
	std::cout << "Cat type: ";
	std::cout << i->getType() << std::endl;
	std::cout << "\nDog makeSound(): ";
	j->makeSound();
	std::cout << "Cat makeSound(): ";
	i->makeSound();
	std::cout << "Animal makeSound(): ";
	meta->makeSound();
	
	std::cout << "\nCalling destructors for each element" << std::endl;
	delete j; //calling delete on a Dog class deletes Dog first then Animal
	delete i;
	delete meta;
	}

	//Wrong polymorphism: virtual missing in member method and destructor
	{
	printSeparator("TEST 2: WRONG POLYMORPHISM");
	const WrongAnimal*	meta = new WrongAnimal();
	const WrongAnimal*	i = new WrongCat();

	std::cout << "\nWrongAnimal type: ";
	std::cout << meta->getType() << std::endl;
	std::cout << "WrongCat type: ";
	std::cout << i->getType() << std::endl;
	std::cout << "\nWrongAnimal makeSound(): ";
	meta->makeSound();
	std::cout << "WrongCat makeSound(): ";
	i->makeSound();

	std::cout << "\nCalling destructors" << std::endl;
	delete i;
	delete meta;
	std::cout << "\nSince WrongAnimal's destructor is not virtual, only WrongAnimal destructor is called when deleting WrongCat" << std::endl;
	}

	{
		printSeparator("TEST 3: EXACT SUBJECT REQUIREMENTS");
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		printSeparator("TEST 4: POLYMORPHISM IN COLLECTIONS");
		const int	arraySize=10;
		std::cout << "Creating an array of " << arraySize << " elements" << std::endl;
		Animal* zoo[arraySize];

		std::cout << "Each element of the array is either a Dog or a Cat\n" << std::endl;
		for (int i = 0; i < arraySize; i++)
		{
			if (i % 2 == 0)
				zoo[i] = new Dog();
			else
				zoo[i] = new Cat();
		}

		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "Animal " << (i + 1) << " (" << zoo[i]->getType() << "): ";
			zoo[i]->makeSound();
		}

		for (int i = 0; i < arraySize; i++)
			delete zoo[i];
	}
	
	{
		printSeparator("TEST 5: SIDE-BY-SIDE COMPARISON");
		std::cout << "=== CORRECT POLYMORPHISM ===" << std::endl;
		Animal* cat = new Cat();
		cat->makeSound();
		delete cat;

		std::cout << "\n=== BROKEN POLYMORPHISM ===" << std::endl;
		WrongAnimal* wrongCat = new WrongCat();
		wrongCat->makeSound();  // Should print wrong sound
		delete wrongCat;
	}
	return 0;
}