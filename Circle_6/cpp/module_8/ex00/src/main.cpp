/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:06:11 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/09 14:14:23 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vec;

	vec.push_back(10);
	vec.push_back(20);

	int	ref = easyfind(vec, 20);
	std::cout << "Value found in container: " << ref << std::endl;

	try
	{
		ref = easyfind(vec, 42);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	ref = easyfind(vec, 10);
	std::cout << "Value found in container: " << ref << std::endl;
}