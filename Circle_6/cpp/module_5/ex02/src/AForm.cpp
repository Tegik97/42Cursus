/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:23:17 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 14:23:18 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("form"), _is_signed(false), _sign_grade(1), _exec_grade(1)
{
    throw DeclarationNotAllowedException();
}

AForm::AForm(const std::string& name, const int sign_grade, const int exec_grade) :
    _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade < 1)
    {
        std::cout << "Sign ";
        throw GradeTooHighException();
    }
    if (exec_grade < 1)
    {
        std::cout << "Exec ";
        throw GradeTooHighException();
    }
    if (sign_grade > 150)
    {
        std::cout << "Sign ";
        throw GradeTooLowException();
    }
    if (exec_grade > 150)
    {
        std::cout << "Exec ";
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) :
    _name(other._name),
    _is_signed(other._is_signed),
    _sign_grade(other._sign_grade),
    _exec_grade(other._exec_grade) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        throw Bureaucrat::AssignmentNotAllowedException();
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_is_signed;
}

int AForm::getSignGrade() const
{
    return this->_sign_grade;
}

int AForm::getExecGrade() const
{
    return this->_exec_grade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (_sign_grade < bureaucrat.getGrade())
        throw GradeTooLowException();
    if (this->_is_signed == true)
        throw FormAlreadySignedException();
    this->_is_signed = true;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "form not signed yet";
}

const char*	AForm::FileFailException::what() const throw()
{
	return "file error";
}

const char *AForm::DeclarationNotAllowedException::what() const throw()
{
    return "Declaration not allowed, name, sign grade and execution grade are mandatory";
}

const char  *AForm::FormAlreadySignedException::what() const throw()
{
    return "form has already been signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os  << "Form: " << form.getName()
        << " signed: " << (form.getSigned() ? "yes" : "no")
        << ", sign grade: " << form.getSignGrade()
        << ", exec grade: " << form.getExecGrade();

    return os;
}