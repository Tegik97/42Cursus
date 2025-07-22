#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
	std::cout << "[WRONGCAT CONSTRUCTOR]" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other._type)
{
	std::cout << "[WRONGCAT COPY CONSTRUCTOR]" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WRONGCAT ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WRONGCAT DESTRUCTOR]" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}