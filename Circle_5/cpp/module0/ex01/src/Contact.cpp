/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:23:29 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 10:36:15 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::Contact(std::string name, std::string surname, std::string nick, std::string number, std::string secret)
				: first_name(name), last_name(surname), nickname(nick), phone_number(number), darkest_secret(secret) {}
Contact::~Contact() {}

std::string Contact::getFirstName() const
{
	if (first_name.length() > 10)
		return first_name.substr(0, 9) + '.';
	return first_name;
}

std::string	Contact::getLastName() const
{
	if (last_name.length() > 10)
		return last_name.substr(0, 9) + '.';
	return last_name;
}

std::string Contact::getNickname() const
{
	if (nickname.length() > 10)
		return nickname.substr(0, 9) + '.';
	return nickname;
}

void	Contact::displayContact() const
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}