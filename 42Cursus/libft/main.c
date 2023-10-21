/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:04:37 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/21 10:32:09 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	ft_myextfunct(unsigned int index, char *c)
{
	*c = ft_toupper((int)(*c));
}

int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		ft_isprint(127);
	}
}
