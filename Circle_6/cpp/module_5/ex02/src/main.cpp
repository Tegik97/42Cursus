#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printSeparator(const std::string& msg)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "      " << msg << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

int main(void)
{
	{
		printSeparator("TEST 1: BUREAUCRAT CONSTRUCTION");

		//Bureaucrat with basic constructor
		try
		{
			Bureaucrat	piero;
			std::cout << piero << std::endl;
		} 
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Bureaucrat with name and grade
		try
		{
			Bureaucrat	luca("Luca", 15);
			std::cout << "\n" << luca << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Bureaucrat with copy constructor
		try
		{
			Bureaucrat	gigi("Gigi", 42);
			Bureaucrat	gigiCopy(gigi);

			std::cout << "\n" << gigi << std::endl;
			std::cout << gigiCopy << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Bureaucrat with assignment operator
		try
		{
			Bureaucrat	franco("Franco", 73);
			Bureaucrat	franchino("Franchino", 12);

			franchino = franco;
			std::cout << "\n" << franco << std::endl;
			std::cout << franchino << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Bureaucrat with invalid grade
		try
		{
			Bureaucrat	pietro("Pietro", 0);

			std::cout << pietro << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat	pietro("Pietro", 151);

			std::cout << pietro << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}

	{
		printSeparator("TEST 2: BUREAUCRAT GRADE INCREASE/DECREASE");

		//Incrementing grade over limit
		try
		{
			Bureaucrat	lorenzo("Lorenzo", 1);

			std::cout << lorenzo << std::endl;
			lorenzo.incrementGrade();
			std::cout << lorenzo << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//decrementing grade over limit
		try
		{
			Bureaucrat	mario("Mario", 150);

			std::cout << mario << std::endl;
			mario.decrementGrade();
			std::cout << mario << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}

	{
		printSeparator("TEST 3: FORM CONSTRUCTION");

		//Form with basic constructor
		try
		{
			ShrubberyCreationForm	a42;
			std::cout << a42 << std::endl;
		} 
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with target
		try
		{
			ShrubberyCreationForm	b42("home");
			std::cout << "\n" << b42 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with copy constructor
		try
		{
			ShrubberyCreationForm	c42("Park");
			ShrubberyCreationForm	c42Copy(c42);

			std::cout << "\n" << c42 << std::endl;
			std::cout << c42Copy << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with assignment operator
		try
		{
			ShrubberyCreationForm	d42("Garden");
			ShrubberyCreationForm	d43("Garden2");

			d43 = d42;
			std::cout << "\n" << d42 << std::endl;
			std::cout << d43 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}

	{
		printSeparator("TEST 4: EXECUTING SHRUBBERY FORMS");

		//Form signed and executed with higher grades
		try
		{
			Bureaucrat					luca("Luca", 10);
			ShrubberyCreationForm		a42("Home");

			std::cout << luca << std::endl;
			std::cout << a42 << std::endl;
			luca.signForm(a42);
			std::cout << a42 << std::endl;
			luca.executeForm(a42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form signed with lower grade and executed while not signed
		try
		{
			Bureaucrat					gigi("Gigi", 150);
			ShrubberyCreationForm		b42("Garden");

			std::cout << gigi << std::endl;
			std::cout << b42 << std::endl;
			gigi.signForm(b42);
			std::cout << b42 << std::endl;
			gigi.executeForm(b42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form signed but executed with lower grade
		try
		{
			Bureaucrat					davide("Davide", 139);
			ShrubberyCreationForm		c42("Park");

			std::cout << davide << std::endl;
			std::cout << c42 << std::endl;
			davide.signForm(c42);
			std::cout << c42 << std::endl;
			davide.executeForm(c42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}

	{
		printSeparator("TEST 5: EXECUTING ROBOTOMY FORMS");

		//Form signed and executed with higher grades
		try
		{
			Bureaucrat					luca("Luca", 10);
			RobotomyRequestForm			a42("Factory");

			std::cout << luca << std::endl;
			std::cout << a42 << std::endl;
			luca.signForm(a42);
			std::cout << a42 << std::endl;
			luca.executeForm(a42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form signed with lower grade and executed while not signed
		try
		{
			Bureaucrat					gigi("Gigi", 150);
			RobotomyRequestForm			b42("Construction Line");

			std::cout << gigi << std::endl;
			std::cout << b42 << std::endl;
			gigi.signForm(b42);
			std::cout << b42 << std::endl;
			gigi.executeForm(b42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form signed but executed with lower grade
		try
		{
			Bureaucrat					davide("Davide", 65);
			RobotomyRequestForm			c42("Storage");

			std::cout << davide << std::endl;
			std::cout << c42 << std::endl;
			davide.signForm(c42);
			std::cout << c42 << std::endl;
			davide.executeForm(c42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}

	{
		printSeparator("TEST 6: EXECUTING PARDON FORMS");

		//Form signed and executed with higher grades
		try
		{
			Bureaucrat					luca("Luca", 3);
			PresidentialPardonForm		a42("Giulia");

			std::cout << luca << std::endl;
			std::cout << a42 << std::endl;
			luca.signForm(a42);
			std::cout << a42 << std::endl;
			luca.executeForm(a42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form signed with lower grade and executed while not signed
		try
		{
			Bureaucrat					gigi("Gigi", 150);
			PresidentialPardonForm		b42("Piero");

			std::cout << gigi << std::endl;
			std::cout << b42 << std::endl;
			gigi.signForm(b42);
			std::cout << b42 << std::endl;
			gigi.executeForm(b42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form signed but executed with lower grade
		try
		{
			Bureaucrat					davide("Davide", 20);
			PresidentialPardonForm		c42("Marco");

			std::cout << davide << std::endl;
			std::cout << c42 << std::endl;
			davide.signForm(c42);
			std::cout << c42 << std::endl;
			davide.executeForm(c42);
			std::cout << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
}