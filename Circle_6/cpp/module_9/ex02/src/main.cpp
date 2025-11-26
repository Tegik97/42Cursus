/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:28:45 by mchiaram          #+#    #+#             */
/*   Updated: 2025/11/26 11:28:46 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	PmergeMe	merge;

	if (!merge.inputParse(argc, argv))
		return 1;

	merge.runSort();
	return 0;
}