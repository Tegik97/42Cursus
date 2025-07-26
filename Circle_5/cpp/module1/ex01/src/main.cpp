/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:27:05 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 11:27:06 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombieHorde.hpp"

int	main(void)
{
	int		N = 10;
	Zombie* horde = zombieHorde(N, "foo");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}