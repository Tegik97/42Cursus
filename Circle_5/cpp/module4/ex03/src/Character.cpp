#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Unknown")
{
	std::cout << _name << " has been promoted to Soldier First Class" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_backpack[i] = NULL;
}

Character::Character(const std::string& name) : _name(name) 
{
	std::cout << _name << " has been promoted to Soldier First Class" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_backpack[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) 
{
	std::cout << _name << " has been promoted to Soldier First Class" << std::endl;
	for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	for (int i = 0; i < 100; i++)
	{
		if (other._backpack[i])
			this->_backpack[i] = other._backpack[i]->clone();
		else
			this->_backpack[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		std::cout << _name << " has been promoted to Soldier First Class" << std::endl;
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		for (int i = 0; i < 100; i++)
		{
			delete this->_backpack[i];
			if (other._backpack[i])
				this->_backpack[i] = other._backpack[i]->clone();
			else
				this->_backpack[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << _name << " has died in battle..." << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < 100; i++)
		delete _backpack[i];
}

const std::string&	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " equipped " << m->getType() << " materia" << std::endl;
			return;
		}
	}
	std::cout << "Not enough space in " << this->_name << " inventory" << std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (!this->_backpack[i])
		{
			this->_backpack[i] = m;
			std::cout << m->getType() << " materia has been added to the backpack" << std::endl;
			return;
		}
	}

	delete this->_backpack[0];
	for (int i = 0; i < 99; i++)
		this->_backpack[i] = this->_backpack[i + 1];
	this->_backpack[99] = m;
	std::cout << m->getType() << " materia has been added to the backpack" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return;
	
	std::cout << this->_name << " unequipped " << this->_inventory[idx]->getType() << " materia" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (!this->_backpack[i])
		{
			this->_backpack[i] = this->_inventory[idx];
			this->_inventory[idx] = NULL;
			std::cout << this->_backpack[i]->getType() << " materia has been added to the backpack" << std::endl;
			return;
		}
	}

delete this->_backpack[0];
for (int i = 0; i < 99; i++)
	this->_backpack[i] = this->_backpack[i + 1];
this->_backpack[99] = this->_inventory[idx];
this->_inventory[idx] = NULL;
std::cout << this->_backpack[99]->getType() << " materia has been added to the backpack" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}