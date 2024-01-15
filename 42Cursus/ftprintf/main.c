/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:25:55 by mchiaram          #+#    #+#             */
/*   Updated: 2024/01/15 19:00:18 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main(void)
{
	int				n;
	char 			*str;
	char 			c;
	unsigned int	un;
	
	str = "Manuel";
	un = 26;
	c = 'f';
	ft_printf("Caratteri stampati %d\n\n", ft_printf("Ciao mi chiamo %s e %%ho %u anni %%%cf%%\n", str, un, c));
	printf("Caratteri stampati %d", printf("ciao mi chiamo %s e %%ho %u anni %%%cf%%\n", str, un, c));
	/*ft_printf("Caratteri stampati %d\n\n", ft_printf("Ciao mi chiamo %s e %%ho %u anni %%%c\n", str, un, c));
	printf("Caratteri stampati %d", printf("Ciao mi chiamo %s e %%ho %u anni %%%c\n", str, un, c));*/
	return (0);
}