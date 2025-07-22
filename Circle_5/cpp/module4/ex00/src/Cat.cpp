#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "[CAT CONSTRUCTOR]" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other._type)
{
	std::cout << "[CAT COPY CONSTRUCTOR]" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "[CAT ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "[CAT DESTRUCTOR]" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}