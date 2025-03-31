#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "Welcome to your retro PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Unknown command. Use ADD, SEARCH, or EXIT." << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}
