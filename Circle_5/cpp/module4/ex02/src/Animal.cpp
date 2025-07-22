#include "Animal.hpp"

AAnimal::AAnimal() : _type("Generic")
{
	std::cout << "[AANIMAL CONSTRUCTOR]" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type)
{
	std::cout << "[AANIMAL STRING CONSTRUCTOR]" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "[AANIMAL COPY CONSTRUCTOR]" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "[AANIMAL ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "[AANIMAL DESTRUCTOR]" << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}