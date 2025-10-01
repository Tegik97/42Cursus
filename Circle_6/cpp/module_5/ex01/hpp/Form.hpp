/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:08:10 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 13:32:10 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        const std::string& getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
        
        class DeclarationNotAllowedException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class FormAlreadySignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif