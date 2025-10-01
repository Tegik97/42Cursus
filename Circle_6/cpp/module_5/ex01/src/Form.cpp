/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:08:20 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 13:32:50 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("form"), _is_signed(false), _sign_grade(1), _exec_grade(1)
{
    throw DeclarationNotAllowedException();
}

Form::Form(const std::string& name, const int sign_grade, const int exec_grade) :
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

Form::Form(const Form& other) :
    _name(other._name),
    _is_signed(other._is_signed),
    _sign_grade(other._sign_grade),
    _exec_grade(other._exec_grade) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        throw Bureaucrat::AssignmentNotAllowedException();
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_is_signed;
}

int Form::getSignGrade() const
{
    return this->_sign_grade;
}

int Form::getExecGrade() const
{
    return this->_exec_grade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (_sign_grade < bureaucrat.getGrade())
        throw GradeTooLowException();
    if (this->_is_signed == true)
        throw FormAlreadySignedException();
    this->_is_signed = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::DeclarationNotAllowedException::what() const throw()
{
    return "Declaration not allowed, name, sign grade and execution grade are mandatory";
}

const char  *Form::FormAlreadySignedException::what() const throw()
{
    return "form has aldready been signed";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os  << "Form: " << form.getName()
        << " signed: " << (form.getSigned() ? "yes" : "no")
        << ", sign grade: " << form.getSignGrade()
        << ", exec grade: " << form.getExecGrade();

    return os;
}