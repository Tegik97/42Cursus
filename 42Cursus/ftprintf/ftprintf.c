/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:38:31 by mchiaram          #+#    #+#             */
/*   Updated: 2024/01/17 19:57:09 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

size_t	ft_digitcount(int n, char c)
{
	size_t			ndigits;
	unsigned int	div;

	ndigits = 0;
	div = 10;
	if (c == 'x' || c == 'X')
		div = 16;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		ndigits++;
		n *= -1;
	}
	while (n > 0)
	{
		ndigits++;
		n /= div;
	}
	return (ndigits);
}

int	ft_char_count(char c, va_list argscopy)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (ft_strlen(va_arg(argscopy, char *)));
	else if (c == 'p')
		return (ft_strlen(va_arg(argscopy, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_digitcount(va_arg(argscopy, int), c));
	else if (c == 'u')
		return (ft_digitcount(va_arg(argscopy, unsigned int), c));
	else if (c == 'x' || c == 'X')
		return (ft_digitcount(va_arg(argscopy, int), c));
	else
		return (1);
}

char	*ft_hex_conv(int n, char c)
{
	char	*conv;
	char	*str;
	int		i;

	i = ft_digitcount(n, c);
	conv = "0123456789abcdef";
	str = ft_calloc((i + 1), 1);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[--i] = conv[n % 16];
		if (c == 'X')
			str[i] = ft_toupper(str[i]);
		n /= 16;
	}
	return (str);
}

void	ft_printparam(char c, va_list args)
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
		ft_putstr_fd(ft_hex_conv(va_arg(args, int), c), 1);
	else
		ft_putchar_fd(c, 1);
}

int	ft_printf(const char *str, ...)
{
	int		nchar;
	va_list	args;
	va_list	argscopy;

	nchar = 0;
	va_start(args, str);
	va_copy(argscopy, args);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			ft_printparam(*++str, args);
			nchar += ft_char_count(*str, argscopy);
			str++;
		}
		if (*str != '%')
		{
		ft_putchar_fd(*str++, 1);
		nchar++;
		}
	}
	va_end(args);
	va_end(argscopy);
	return (nchar);
}
