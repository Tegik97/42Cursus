#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Unknown")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_backpack[i] = NULL;
}

Character::Character(const std::string& name) : _name(name) 
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_backpack[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) 
{
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
			return;
		}
	}
	std::cout << "Not enough space in " << this->_name << " inventory" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return;
	
	for (int i = 0; i < 100; i++)
	{
		if (!this->_backpack[i])
		{
			this->_backpack[i] = this->_inventory[idx];
			this->_inventory[idx] = NULL;
			return;
		}
	}

	delete _backpack[0];
	for (int i = 0; i < 99; i++)
		_backpack[i] = _backpack[i + 1];
	_backpack[99] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}