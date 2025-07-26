/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:31:30 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 15:31:31 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0) 
{
	std::cout << "[CONSTRUCTOR]" << std::endl;

	std::cout << "A new legend is rising!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "[CONSTRUCTOR]" << std::endl;

	std::cout << "A new legend is rising!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
	std::cout << "[CONSTRUCTOR]" << std::endl;
	
	std::cout << "A new legend is rising!" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_energy_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap() 
{
	std::cout << "[DESTRUCTOR]" << std::endl;

	if (this->_hit_points == 0)
		std::cout << this->_name << " has exploded into pieces..." << std::endl;
	else
		std::cout << this->_name << " leaves the battle victorious!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points > 0)
		std::cout << this->_name << " has no energy points left!" << std::endl;
	else if (this->_energy_points > 0)
		std::cout << this->_name << " is too damaged to fight!" << std::endl;
	else
		std::cout << this->_name << " is completely busted!" << std::endl << "It has no energy and hit points left!" << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " can't take any more damage!" << std::endl;
		return;
	}
	if (this->_hit_points > amount)
	{
		std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hit_points -= amount;
	}
	else
	{
		std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hit_points = 0;
		std::cout << "After the blow " << this->_name << " is on the ground!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << this->_name << " has repaired itself for " << amount << " hit points!" << std::endl;
		this->_hit_points += amount;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points > 0)
		std::cout << this->_name << " has no energy points left!" << std::endl;
	else if (this->_energy_points > 0)
		std::cout << this->_name << " is laying on the ground with no hit points left!" << std::endl;
	else
		std::cout << this->_name << " is completely busted!" << std::endl << "It has no energy and hit points left!" << std::endl;
}