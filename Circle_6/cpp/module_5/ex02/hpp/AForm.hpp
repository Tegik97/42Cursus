/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:22:55 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 14:22:56 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class AForm {

    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _sign_grade;
        const int           _exec_grade;

    public:
        AForm();
        AForm(const std::string& name, const int sign_grade, const int exec_grade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executor) const = 0;

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
        
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FileFailException : public std::exception
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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif