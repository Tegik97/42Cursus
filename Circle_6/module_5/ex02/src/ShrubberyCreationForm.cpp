#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		throw Bureaucrat::AssignmentNotAllowedException();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream file(_target + "_shrubbery");
	if (file.is_open())
	{
		file << "       /\\         /\\\n";
		file << "      /  \\       /  \\\n";
		file << "     /____\\     /____\\\n";
		file << "       ||          ||\n";
	  
		file.close();
	}
	if (file.fail())
		throw AForm::FileFailException();
}