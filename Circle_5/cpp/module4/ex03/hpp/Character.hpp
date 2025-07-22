#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	AMateria;

class	Character : public ICharacter
{
	private:
		AMateria*	_backpack[100];
		AMateria*	_inventory[4];
		std::string	_name;

	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();

		const std::string&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif