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

	std::cout << "[ MATERIASOURCE DESTRUCTOR ]" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_grimoire[i];
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	
	std::cout << m->getType() << " materia learnt" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_grimoire[i])
		{
			this->_grimoire[i] = m->clone();
			std::cout << "Materia saved in the grimoire slot: " << i << std::endl;
			delete m;
			int	count = 0;
			for (int i = 0; i < 4; i++)
			{
				if (this->_grimoire[i])
					count++;
			}
			std::cout << "Grimoire slot used " << count << "/4" << std::endl;

			return;
		}
	}

	std::cout << "Grimoire is full, deleting " << this->_grimoire[0]->getType() << " materia in grimoire's first position\n";
	std::cout << "and saved the new materia in grimoire's last position" << std::endl;
	delete this->_grimoire[0];
	for (int i = 0; i < 3; i++)
		this->_grimoire[i] = this->_grimoire[i + 1];
	this->_grimoire[3] = m->clone();
	delete m;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_grimoire[i] && this->_grimoire[i]->getType() == type)
		{
			std::cout << "Materia " << type << " created" << std::endl;
			return this->_grimoire[i]->clone();
		}
	}
	std::cout << "Materia " << type << " not found in grimoire" << std::endl;
	return 0;
}