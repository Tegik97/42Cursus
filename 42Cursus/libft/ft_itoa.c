/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:54:32 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/27 14:44:02 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digitcount(int n)
{
	size_t	ndigits;

	ndigits = 0;
	if (n == 0)
		return (1);
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
	long int	nbr;

	nbr = (long int)n;
	ndigits = ft_digitcount(nbr);
	str = (char *) malloc(sizeof(char) * (ndigits + 1));
	if (!str)
		return (NULL);
	*(str + ndigits) = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		*str = '-';
		nbr *= -1;
	}
	while (nbr != 0)
	{
		ndigits--;
		*(str + ndigits) = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
/*int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	ft_itoa(argv[1]);
	return (0);
}*/