/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:04:37 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/11 17:39:04 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	str[50];

	ft_strlcpy(str, argv[1], strlen(argv[1]));
	if (argc > 0)
	{
		ft_bzero(str, 5);
		printf("mine: %s\n", str);
		bzero(str, 5);
		printf("original: %s\n", str);
	}
	argv[2] = "aaaaaaaaaaaaaa";
}
