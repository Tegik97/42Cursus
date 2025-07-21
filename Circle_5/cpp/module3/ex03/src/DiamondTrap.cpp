#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "[DIAMOND CONSTRUCTOR]" << std::endl;

	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "FragTrap and ScavTrap merged into something new!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
	std::cout << "It doesn't look happy..." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "[DIAMOND CONSTRUCTOR]" << std::endl;

	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "FragTrap and ScavTrap merged into something new!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
	std::cout << "It doesn't look happy..." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other._name + "_clap_name"), ScavTrap(), FragTrap(), _name(other._name)
{
	std::cout << "[DIAMOND CONSTRUCTOR]" << std::endl;

	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	std::cout << "FragTrap and ScavTrap merged into something new!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
	std::cout << "It doesn't look happy..." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
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

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DIAMOND DESTRUCTOR]" << std::endl;

	if (this->_hit_points == 0)
		std::cout << this->_name << " has exploded into pieces..." << std::endl;
	else
		std::cout << this->_name << " leaves the battle victorious... It doesn't look happy..." << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "DiamondTrap is questioning life... Am I " << ClapTrap::_name << " or " << this->_name << "?" << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points > 0)
		std::cout << this->_name << "'s energy is too low to even bother about identity..." << std::endl;
	else if (this->_energy_points > 0)
		std::cout << this->_name << " is too damaged to question itself..." << std::endl;
	else
		std::cout << this->_name << " is completely busted and its identity doesn't matter anymore..." << std::endl;
}