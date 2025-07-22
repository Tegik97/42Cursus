#include "Animal.hpp"

Animal::Animal() : _type("Generic")
{
	std::cout << "[ANIMAL CONSTRUCTOR]" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "[ANIMAL STRING CONSTRUCTOR]" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "[ANIMAL COPY CONSTRUCTOR]" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "[ANIMAL ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[ANIMAL DESTRUCTOR]" << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound() const
{
	std::cout << "Generic animal noise" << std::endl;
}