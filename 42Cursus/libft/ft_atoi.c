/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:15 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/09 14:53:08 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	base;
	int	sign;
	int	countsign;
	int	i;

	base = 0;
	sign = 1;
	countsign = 0;
	i = 0;
	while ((nptr[i] > 9 && nptr[i] < 13) || nptr[i] == ' ')
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			countsign++;
		i++;
	}
	if (countsign % 2 == 1)
		sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		base = base * 10 + (nptr[i] - '0');
		i++;
	}
	return (base * sign);
}
