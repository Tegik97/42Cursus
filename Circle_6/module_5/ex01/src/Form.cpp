#include "Form.hpp"

Form::Form() {}

Form::Form(const std::string& name, const int sign_grade, const int exec_grade) :
    _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw Bureaucrat::GradeTooLowException();
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
        throw Bureaucrat::GradeTooLowException();
    this->_is_signed = true;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os  << "Form: " << form.getName()
        << " signed: " << (form.getSigned() ? "yes" : "no")
        << ", sign grade: " << form.getSignGrade()
        << ", exec grade: " << form.getExecGrade();

    return os;
}