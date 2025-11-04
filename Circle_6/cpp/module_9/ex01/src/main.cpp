/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:41:14 by mchiaram          #+#    #+#             */
/*   Updated: 2025/11/04 15:41:15 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: expression missing" << std::endl;
		return 1;
	}

	RPN	expr;

	expr.calculate(argv[1]);
	return 0;
}