/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:00:55 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/09 14:39:36 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

void	printSeparator(const std::string& str)
{
	std::cout << std::string(50, '=') << std::endl;
	std::cout << "     " << str << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

int	main(void)
{
	{
		printSeparator("TEST 1: OCF ARRAY CONSTUCTORS");

		//Default constructor
		Array<int>	emptyArray;
		std::cout << "emptyArray size: " << emptyArray.size() << std::endl;

		//Parametric constructor
		Array<int>	sizeArray(6);
		std::cout << "sizeArray size: " << sizeArray.size() << std::endl;

		//Copy constructor
		Array<int>	copyArray(sizeArray);
		std::cout << "Copy array size: " << copyArray.size() << std::endl;

		//Assignment operator
		Array<int>	assignArray;
		assignArray = copyArray;
		std::cout << "assignArray size: " << assignArray.size() << std::endl;

		//copy constructor independence
		std::cout << std::endl;
		std::cout << "original sizeArray[1]: " << sizeArray[1] << std::endl;
		std::cout << "original copyArray[1]: " << copyArray[1] << std::endl;
		std::cout << "original assignArray[1]: " << assignArray[1] << std::endl;
		copyArray[1] = 42;
		assignArray[1] = 4242;
		std::cout << "\nunmodified sizeArray[1]: " << sizeArray[1] << std::endl;
		std::cout << "modified copyArray[1]: " << copyArray[1] << std::endl;
		std::cout << "modified assignArray[1]: " << assignArray[1] << std::endl;
		std::cout << std::endl;
	}

	{
		printSeparator("TEST 2: OVERFLOW ALLOCATION");

		//Max int size
		try
		{
			Array<char>	maxArray(2147483647);
			std::cout << "maxArray size: " << maxArray.size() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//Too much memory allocated
		try
		{
			Array<std::string>	overflowSize(2147483644);
			std::cout << overflowSize.size() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//Negative size
		try
		{
			Array<char>	negativeSize(-5);
			std::cout << negativeSize.size() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;
	}

	{
		printSeparator("TEST 3: ARRAY MEMORY ACCESS");

		//Correct memory access
		try
		{
			Array<int>	valuesArray(10);
			std::cout << "valuesArray size: " << valuesArray.size() << std::endl;
			std::cout << "valuesArray[2]: " << valuesArray[2] << "\n" << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//Const memory access
		try
		{
			const Array<char>	constArray(5);
			std::cout << "constArray[3]: " << constArray[3] << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//Out of bound memory access
		try
		{
			std::cout << std::endl;
			Array<char>	charArray(5);
			std::cout << "charArray size: " << charArray.size() << std::endl;
			std::cout << "charArray[5]: " << charArray[5] << "\n" << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//Negative index access
		try
		{
			Array<int>	negativeArray(23);
			std::cout << "negativeArray[-20]: " << negativeArray[-20] << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//Modify array value
		try
		{
			std::cout << std::endl;
			Array<int>	modifyArray(3);
			std::cout << "original modifyArray[2]: " << modifyArray[2] << std::endl;
			modifyArray[2] = 42;
			std::cout << "modified modifyArray[2]: " << modifyArray[2] << "\n" << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}