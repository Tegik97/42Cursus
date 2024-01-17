/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:25:55 by mchiaram          #+#    #+#             */
/*   Updated: 2024/01/17 20:04:19 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main(int argc, char *argv[])
{
	int				n;
	char			*str;
	char			c;
	unsigned int	un;
	void			*ptr;

	ptr = &argv[1];
	str = "Manuel";
	n = 27890;
	c = 'f';
	if (argc > 0)
	{
		ft_printf("Caratteri stampati %d\n\n", ft_printf("Ciao mi chiamo %s e %%ho %x anni %%%cf%%\n", argv[1], ft_atoi(argv[2]), argv[3][0]));
		printf("Caratteri stampati %d", printf("Ciao mi chiamo %s e %%ho %x anni %%%cf%%\n", argv[1], ft_atoi(argv[2]), argv[3][0]));
	}
	return (0);
}