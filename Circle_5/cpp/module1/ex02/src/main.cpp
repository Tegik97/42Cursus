/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:27:15 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 11:27:16 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	strPtr = &str;
	std::string&	strRef = str;

	std::cout << "string memory address:" << &str << std::endl;
	std::cout << "pointer memory address:" << strPtr << std::endl;
	std::cout << "reference memory address:" << &strRef << std::endl << std::endl;
	std::cout << "string value:" << str << std::endl;
	std::cout << "pointer value:" << *strPtr << std::endl;
	std::cout << "reference value:" << strRef << std::endl;
}