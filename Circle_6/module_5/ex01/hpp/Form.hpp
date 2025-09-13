#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Form {

    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _sign_grade;
        const int           _exec_grade;

    public:
        Form();
        Form(const std::string& name, const int sign_grade, const int exec_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName();
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        const bool beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif