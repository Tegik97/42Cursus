/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:54:32 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/19 18:45:41 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digitcount(int n)
{
	size_t	ndigits;

	ndigits = 0;
	if (n < 0)
	{
		ndigits++;
		n *= -1;
	}
	while (n != 0)
	{
		ndigits++;
		n /= 10;
	}
	return (ndigits);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		ndigits;

	if (n < -2147483647)
	{
		str = "-2147483648";
		return (str);
	}
	ndigits = ft_digitcount(n);
	str = (char *) malloc(sizeof(char) * (ndigits + 1));
	if (!str)
		return (NULL);
	*(str + ndigits) = '\0';
	if (n < 0)
	{
		*str = '-';
		n *= -1;
	}
	while (n != 0)
	{
		ndigits--;
		*(str + ndigits) = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
