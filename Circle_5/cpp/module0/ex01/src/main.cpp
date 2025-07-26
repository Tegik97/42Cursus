/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:23:31 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 11:01:55 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "Welcome to your retro PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, input))
	{
		std::cout << "\nEOF detected" << std::endl;
		exit (0);
	}
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
