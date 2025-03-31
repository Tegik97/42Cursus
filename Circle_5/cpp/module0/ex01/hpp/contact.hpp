#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	
	public:
		Contact();
		Contact(std::string name, std::string surname, std::string nick, std::string number, std::string secret);
		~Contact();

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		void		displayContact() const;
};

#endif