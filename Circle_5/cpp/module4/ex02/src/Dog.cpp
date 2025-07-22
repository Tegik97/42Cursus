#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "[DOG CONSTRUCTOR]" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	std::cout << "[DOG COPY CONSTRUCTOR]" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "[DOG ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "[DOG DESTRUCTOR]" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}