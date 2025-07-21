#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragDefault")
{
	std::cout << "[FRAG CONSTRUCTOR]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;

	std::cout << this->_name << " has high fived into a new form!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "[FRAG CONSTRUCTOR]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;

	std::cout << this->_name << " has high fived into a new form!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "[FRAG CONSTRUCTOR]" << std::endl;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;

	std::cout << this->_name << " has high fived into a new form!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

FragTrap::~FragTrap() 
{
	std::cout << "[FRAG DESTRUCTOR]" << std::endl;

	if (this->_hit_points == 0)
		std::cout << this->_name << " has exploded into pieces..." << std::endl;
	else
		std::cout << this->_name << " leaves the battle victorious!" << std::endl;
}

void	FragTrap::highFiveGuys()
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << this->_name << " requests the highest of fives!!" << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points > 0)
		std::cout << this->_name << " has no energy points left to cheer up allies!" << std::endl;
	else if (this->_energy_points > 0)
		std::cout << this->_name << " is too damaged to high five!" << std::endl;
	else
		std::cout << this->_name << " is completely busted and cannot high five anyone!" << std::endl;
}
