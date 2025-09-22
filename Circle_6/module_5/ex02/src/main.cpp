#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
			AForm	a42;
			std::cout << a42 << std::endl;
		} 
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with name and grades
		try
		{
			AForm	b42("b42", 15, 15);
			std::cout << "\n" << b42 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with copy constructor
		try
		{
			AForm	c42("c42", 42, 42);
			AForm	c42Copy(c42);

			std::cout << "\n" << c42 << std::endl;
			std::cout << c42Copy << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with assignment operator
		try
		{
			AForm	d42("d42", 73, 73);
			AForm	d43("d43", 12, 12);

			d43 = d42;
			std::cout << "\n" << d42 << std::endl;
			std::cout << d43 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with invalid sign grade
		try
		{
			AForm	e42("e42", 0, 1);

			std::cout << e42 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		try
		{
			AForm	f42("f42", 151, 150);

			std::cout << f42 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Form with invalid exec grade
		try
		{
			AForm	e42("e42", 1, 0);

			std::cout << e42 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		try
		{
			AForm	f42("f42", 150, 151);

			std::cout << f42 << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}

	{
		printSeparator("TEST 4: SIGNING FORMS");

		//Bureaucrat with higher signing rights
		try
		{
			Bureaucrat	luca("Luca", 10);
			AForm		a42("A42", 15, 15);

			std::cout << luca << std::endl;
			std::cout << a42 << std::endl;
			luca.signForm(a42);
			std::cout << a42 << "\n" << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Bureaucrat with lower signing rights
		try
		{
			Bureaucrat	gigi("Gigi", 42);
			AForm		b42("B42", 15, 15);

			std::cout << gigi << std::endl;
			std::cout << b42 << std::endl;
			gigi.signForm(b42);
			std::cout << b42 << "\n" << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}

		//Bureaucrat with equal signing rights
		try
		{
			Bureaucrat	davide("Davide", 15);
			AForm		c42("C42", 15, 15);

			std::cout << davide << std::endl;
			std::cout << c42 << std::endl;
			davide.signForm(c42);
			std::cout << c42 << "\n" << std::endl;
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
}