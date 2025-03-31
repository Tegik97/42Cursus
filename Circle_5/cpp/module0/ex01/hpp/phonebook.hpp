#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include <sstream>
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		nextIndex;
		int		contactCount;
	
	public:
		PhoneBook();
		PhoneBook(int nextI, int nContact);
		~PhoneBook();

		void	addContact();
		void	displayTable() const;
		void	searchContact() const;
};

#endif