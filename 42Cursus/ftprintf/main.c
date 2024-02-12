/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:25:55 by mchiaram          #+#    #+#             */
/*   Updated: 2024/01/29 17:22:23 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char *argv[])
{
	int				n;
	char			*str;
	char			c;
	unsigned int	un;
	void			*ptr;

	str = "";
	n = INT_MIN;
	un = 143;
	c = 'f';
	ptr = &n;
	if (argc > 0)
	{
		ft_printf("Caratteri stampati %d\n\n", ft_printf("%x", un));
		printf("Caratteri stampati %d", printf("%x", un));
	}
	return (0);
}
