#include "Dog.hpp"
#include "Cat.hpp"

void	printSeparator(const std::string& test_name)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "    " << test_name << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

int	main(void)
{
	std::cout << "🧠 Deep Copy Tester 🧠\n" << std::endl;

	{
		printSeparator("TEST 1: SUBJECT TEST");
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
		printSeparator("TEST 2: EXACT SUBJECT CODE");
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; // should not create a leak
		delete i;
	}

	{
		printSeparator("TEST 3: DEEP COPY VERIFICATION");
		std::cout << "Creating original Dog..." << std::endl;
		Dog originalDog;
		
		std::cout << "\nTesting copy constructor..." << std::endl;
		Dog copiedDog = originalDog;  // Copy constructor
		
		std::cout << "\nTesting assignment operator..." << std::endl;
		Dog assignedDog;
		assignedDog = originalDog;    // Assignment operator
		
		std::cout << "\nAll dogs created - they should have separate Brains" << std::endl;
		std::cout << "Destroying dogs to test proper cleanup..." << std::endl;
	}

	{
		printSeparator("TEST 4: MEMORY LEAK STRESS TEST");
		std::cout << "Creating and destroying many animals..." << std::endl;
		for (int count = 0; count < 100; count++) 
		{
			Animal* animal = (count % 2 == 0) ? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat());
			delete animal;
			std::cout << std::endl;
		}
		std::cout << "Stress test completed" << std::endl;
	}

	return 0;
}