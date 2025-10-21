/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:34:14 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/21 13:39:03 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>
#include <iostream>

void	printSeparator(std::string str)
{
	std::cout << "\n" << std::string(40, '=') << std::endl;
	std::cout << "     " << str << std::endl;
	std::cout << std::string(40, '=') << std::endl;
}

int main()
{
	//Test with subject main
	{
		printSeparator("TEST 1: SUBJECT MAIN");

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	//Not enough elements in container
	{
		printSeparator("TEST 2: NOT ENOUGH ELEMENTS");

		try
		{
			Span	sp = Span(5);

			sp.addNumber(4);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	//Negative size
	{
		printSeparator("TEST 3: NEGATIVE SIZE");

		try
		{
			Span	sp = Span(-10);

			sp.addNumber(4);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	//adding more numbers than max size
	{
		printSeparator("TEST 4: MAX SIZE REACHED");
		try
		{
			Span	sp = Span(3);
			sp.addNumber(1);
			sp.addNumber(4);
			sp.addNumber(-100);
			sp.addNumber(1000);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	//Test with 10.000 elements using range
	{
		printSeparator("TEST 5: 10.000 ELEMENTS");
		Span				sp = Span(10000);
		std::vector<int>	temp;

		for (int i = 0; i < 10000; i++)
			temp.push_back(i);

		sp.addRange(temp.begin(), temp.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	//pushing limits
	{
		printSeparator("TEST 6: 100.000 ELEMENTS");
		Span				sp = Span(100000);
		std::vector<int>	temp;

		for (int i = 0; i < 100000; i++)
			temp.push_back(i);

		sp.addRange(temp.begin(), temp.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	{
		printSeparator("TEST 7: 1.000.000 ELEMENTS");
		Span				sp = Span(1000000);
		std::vector<int>	temp;

		for (int i = 0; i < 1000000; i++)
			temp.push_back(i);

		sp.addRange(temp.begin(), temp.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	{
		printSeparator("TEST 8: 10.000.000 ELEMENTS");
		Span				sp = Span(10000000);
		std::vector<int>	temp;

		for (int i = 0; i < 10000000; i++)
			temp.push_back(i);

		sp.addRange(temp.begin(), temp.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
}