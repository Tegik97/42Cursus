/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:24:31 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 14:24:32 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include <iostream>
# include <exception>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		
		AForm*	makeForm(const std::string& name, const std::string& target);

		class InvalidFormNameException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif