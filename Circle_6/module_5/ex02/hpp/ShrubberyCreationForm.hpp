#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};

#endif