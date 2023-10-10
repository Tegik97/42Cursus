/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:04:37 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/10 12:54:38 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*ptr;

	if (argc > 0)
	{
		ptr = ft_strrchr(argv[1], argv[2][0]);
		printf("mine %s\n", ptr);
		ptr = strrchr(argv[1], argv[2][0]);
		printf("original %s\n", ptr);
	}
	argv[2] = "aooo";
}
