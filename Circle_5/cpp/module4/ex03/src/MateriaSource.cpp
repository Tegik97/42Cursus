#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_grimoire[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._grimoire[i])
			this->_grimoire[i] = other._grimoire[i]->clone();
		else
			this->_grimoire[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_grimoire[i];
			if (other._grimoire[i])
				this->_grimoire[i] = other._grimoire[i]->clone();
			else
				this->_grimoire[i] = NULL;
		}
	}
	
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->_grimoire[i];
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_grimoire[i])
		{
			this->_grimoire[i] = m->clone();
			return;
		}
	}

	delete this->_grimoire[0];
	for (int i = 0; i < 3; i++)
		this->_grimoire[i] = this->_grimoire[i + 1];
	this->_grimoire[3] = m->clone();
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_grimoire[i] && this->_grimoire[i]->getType() == type)
			return this->_grimoire[i]->clone();
	}
	return 0;
}