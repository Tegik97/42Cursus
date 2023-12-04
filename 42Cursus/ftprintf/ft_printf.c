#include "ft_printf.h"
#include <stdio.h>

static int	ft_checkformat(const char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (0);
	else
		return (-1);
}
static int	ft_countparam(const char *str)
{
	int	format;
	int numargs;

	format = 0;
	numargs = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			format = ft_checkformat(*str);
			if (format > 0)
				numargs++;
			else if (format < 0)
				return (-1);
		}
		str++;
	}
	return (numargs);
}

int	ft_printf(const char *str, ...)
{
	int	numargs;

	numargs = ft_countparam(str);
	printf("%dciao%s\n", numargs);
	return (1);
}
int	main(void)
{
	char	*str;
	str = "ciao%ssmi%d,chiamo%i%xmanuel%%";

	ft_printf(str);
}