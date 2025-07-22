#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Generic")
{
	std::cout << "[WRONGANIMAL CONSTRUCTOR]" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	std::cout << "[WRONGANIMAL STRING CONSTRUCTOR]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "[WRONGANIMAL COPY CONSTRUCTOR]" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "[WRONGANIMAL ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WRONGANIMAL DESTRUCTOR]" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "generic animal sound" << std::endl;
}