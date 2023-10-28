/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:33:16 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/28 16:50:52 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	unsigned char	c;
	
	if (argc == 2)
	{
		c = argv[1][0];
		printf("isdigit result: %d", ft_isdigit(c));
	}
	return (0);
}*/
/*				---MAN DESCRIPTION---

	This function checks for a digit (0 through 9).
	
	---RETURN VALUE---
    The values returned are nonzero if the character c falls into the
	tested class, and zero if not.
*/