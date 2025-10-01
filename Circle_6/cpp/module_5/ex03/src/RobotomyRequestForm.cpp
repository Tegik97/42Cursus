/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:25:12 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 14:25:13 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		throw Bureaucrat::AssignmentNotAllowedException();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();
	
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << "* DRILLING NOISES *" << std::endl;
	sleep(2);

	srand(time(NULL));
	if (rand() %2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}