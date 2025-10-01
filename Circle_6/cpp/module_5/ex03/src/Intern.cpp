/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:24:58 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 14:24:59 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		*this = other;
	return *this;
}

Intern::~Intern() {}

static AForm* createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	struct FormCreator {
		std::string name;
		AForm* (*create)(const std::string& target);
	};

	FormCreator forms[] = {
		{"shrubbery creation", createShrubberyForm},
		{"robotomy request", createRobotomyForm},
		{"presidential pardon", createPresidentialForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}

	throw InvalidFormNameException();
}

const char*	Intern::InvalidFormNameException::what() const throw()
{
	return "form name doesn't exist";
}