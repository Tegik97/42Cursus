/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:26:41 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 11:26:42 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	z;

	randomChump("stackFoo");
	z = newZombie("heapFoo");
	z->announce();
	delete z;
	return 0;
}