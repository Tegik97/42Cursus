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
