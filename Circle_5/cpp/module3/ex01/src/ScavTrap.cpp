#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scavDefault")
{
	std::cout << "[SCAV CONSTRUCTOR]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;

	std::cout << this->_name << " has evolved into a new form!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "[SCAV CONSTRUCTOR]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;

	std::cout << this->_name << " has evolved into a new form!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "[SCAV CONSTRUCTOR]" << std::endl;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;

	std::cout << this->_name << " has evolved into a new form!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
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

ScavTrap::~ScavTrap() 
{
	std::cout << "[SCAV DESTRUCTOR]" << std::endl;

	if (this->_hit_points == 0)
		std::cout << this->_name << " has exploded into pieces..." << std::endl;
	else
		std::cout << this->_name << " leaves the battle victorious!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << this->_name << " attacks " << target << " with great strength causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points > 0)
		std::cout << this->_name << " has no energy points left!" << std::endl;
	else if (this->_energy_points > 0)
		std::cout << this->_name << " is too damaged to fight!" << std::endl;
	else
		std::cout << this->_name << " is completely busted!" << std::endl << "It has no energy and hit points left!" << std::endl;

}

void	ScavTrap::guardGate()
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << this->_name << " has entered in Gate Keeper mode!" << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points > 0)
		std::cout << this->_name << " has no energy points left to guard the gate!" << std::endl;
	else if (this->_energy_points > 0)
		std::cout << this->_name << " is too damaged to guard the gate!" << std::endl;
	else
		std::cout << this->_name << " is completely busted and cannot guard anything!" << std::endl;
}