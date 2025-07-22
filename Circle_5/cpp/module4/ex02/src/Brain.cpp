#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[BRAIN DEFAULT CONSTRUCTOR]" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "[BRAIN COPY CONSTRUCTOR]" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "[BRAIN ASSIGNMENT OPERATOR]" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() 
{
	std::cout << "[BRAIN DESTRUCTOR]" << std::endl;
}