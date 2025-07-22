#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "[DOG CONSTRUCTOR]" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other._type)
{
	std::cout << "[DOG COPY CONSTRUCTOR]" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "[DOG ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "[DOG DESTRUCTOR]" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}