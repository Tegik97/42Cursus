#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
					: nextIndex(0), contactCount(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	std::string	name;
	std::string last;
	std::string nick;
	std::string number;
	std::string secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << "Error: All fields must be filled in" << std::endl;
		return;
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, last);
	if (last.empty())
	{
		std::cout << "Error: All fields must be filled in" << std::endl;
		return;
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nick);
	if (nick.empty())
	{
		std::cout << "Error: All fields must be filled in" << std::endl;
		return;
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, number);
	if (number.empty())
	{
		std::cout << "Error: All fields must be filled in" << std::endl;
		return;
	}
	std::cout << "Enter contact's darkest secret: ";
	std::getline(std::cin, secret) ;
	if (secret.empty())
	{
		std::cout << "Error: All fields must be filled in" << std::endl;
		return;
	}
	contacts[nextIndex] = Contact(name, last, nick, number, secret);
	nextIndex = (nextIndex + 1) % 8;
	if (contactCount < 8)
		contactCount++;
	std::stringstream ss;
	ss << contactCount;
	std::string countStr = ss.str();
	std::cout << std::endl;
	std::cout << "Contact added successfully" << std::endl << "Number of contacts in phonebook: " << countStr << "/8" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::displayTable() const
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) <<"FIRST NAME" << "|";
	std::cout << std::setw(10) <<"LAST NAME" << "|";
	std::cout << std::setw(10) <<"NICKNAME" << std::endl;
	for(int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
		std::cout << std::setw(10) << contacts[i].getLastName() << "|";
		std::cout << std::setw(10) << contacts[i].getNickname() << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::searchContact() const
{
	std::string	input;
	int			index;

	if (contactCount == 0)
	{
		std::cout << "Contact list is empty" << std::endl;
		return;
	}
	while (true)
	{
		displayTable();
		std::cout << "Select which index entry you want to display: ";
		std::getline(std::cin, input);
		if (input == "EXIT" || input == "exit")
			return;
		std::stringstream ss(input);
		ss >> index;
		if (ss.fail())
		{
			std::cout << "Error: Not a number" << std::endl;
			continue;
		}
		else if (index < 0 || index >= contactCount)
			std::cout << "Error: Selected index does not exists" << std::endl;
		else
		{
			contacts[index].displayContact();
			break;
		}
	}
}
