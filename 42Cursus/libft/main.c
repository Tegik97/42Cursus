/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:04:37 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/09 17:25:28 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("mine %d\n", ft_tolower(argv[1][0]));
		printf("original %d\n", tolower(argv[1][0]));
	}
	argv[2] = "aooo";
}
