#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "[CAT CONSTRUCTOR]" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "[CAT COPY CONSTRUCTOR]" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "[CAT ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "[CAT DESTRUCTOR]" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}