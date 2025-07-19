#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB () {}

void	HumanB::attack() const
{
	if (this->weapon)
		std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with bare hands " << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}