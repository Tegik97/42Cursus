/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:23:26 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 10:58:57 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include <sstream>
#include "Contact.hpp"

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