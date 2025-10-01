/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:52:37 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/01 12:52:38 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void printSeparator(const std::string& msg)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "      " << msg << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

int main(void)
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