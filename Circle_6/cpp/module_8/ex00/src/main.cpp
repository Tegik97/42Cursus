/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:06:11 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/15 20:26:17 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "easyfind.hpp"

int	main(void)
{
	// Test with std::vector
	std::cout << "=== Testing with std::vector ===" << std::endl;
	std::vector<int>	vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Value found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Value found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::vector<int>::iterator it = easyfind(vec, 10);
		std::cout << "Value found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// Test with std::list
	std::cout << "\n=== Testing with std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);

	try {
		std::list<int>::iterator it = easyfind(lst, 200);
		std::cout << "Value found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 999);
		std::cout << "Value found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// Test with std::deque
	std::cout << "\n=== Testing with std::deque ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);

	try {
		std::deque<int>::iterator it = easyfind(deq, 3);
		std::cout << "Value found in deque: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}