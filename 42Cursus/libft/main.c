/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:04:37 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/12 18:41:54 by mchiaram         ###   ########.fr       */
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
	/*
	char	str[50];
	char	str2[50];

	ft_strlcpy(str, argv[1], strlen(argv[1]));
	ft_strlcpy(str2, argv[2], strlen(argv[2]));
	*/
	if (argc > 0)
	{
		//printf("found %c in %s\n", argv[2][0], str);
		printf("mine: %s\n", ft_strdup(argv[1]));
		printf("original: %s\n", strdup(argv[1]));
	}
	argv[2] = "aaaaaaaaaaaaaa";
}
