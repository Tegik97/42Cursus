/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:25:09 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 14:25:10 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		throw Bureaucrat::AssignmentNotAllowedException();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}