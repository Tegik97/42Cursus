/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:58:40 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/28 17:02:47 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	unsigned char	c;

	c = 30;
	while (c <= 33)
	{
		printf("isprint %d result: %d\n", c, ft_isprint(c));
		c++;
	}
	return (0);
}*/

/*				---MAN DESCRIPTION---

	This function checks for any printable character including space.
	
	---RETURN VALUE---
    The values returned are nonzero if the character c falls into the
	tested class, and zero if not.
*/