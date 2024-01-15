/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:38:31 by mchiaram          #+#    #+#             */
/*   Updated: 2024/01/15 19:00:04 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

size_t	ft_digitcount(int n)
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

int	ft_char_count(char c, va_list argsCopy)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (ft_strlen(va_arg(argsCopy, char *)));
	else if (c == 'p')
		return (ft_strlen(va_arg(argsCopy, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_digitcount(va_arg(argsCopy, int)));
	else if (c == 'u')
		return (ft_digitcount(va_arg(argsCopy, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_strlen(va_arg(argsCopy, char *)));
	else
		return (1);
}

char *ft_hex_conv(char *str)
{
	if (*str == 'x')
		return ("oke");
	return ("nope");
}

void	ft_putparam(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_putstr_fd(va_arg(args, void *), 1);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		ft_putstr_fd(ft_hex_conv(va_arg(args, char *)), 1);
	else
		ft_putchar_fd(c, 1);
}

int ft_printf(const char *str, ...)
{
	int	nchar;
	va_list args;
	va_list	argsCopy;
	
	nchar = 0;
	va_start(args, str);
	va_copy(argsCopy, args);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			ft_putparam(*++str, args);
			nchar += ft_char_count(*str, argsCopy);
			str++;
		}
		if (*str != '%')
		{
			ft_putchar_fd(*str++, 1);
			nchar++;
		}
	}
	va_end(args);
	va_end(argsCopy);
	return (nchar);
}
