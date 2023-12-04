#include "ft_printf.h"
#include <stdio.h>
int	ft_printf(const char *str, ...)
{
	str = "2";
	printf("%s", str);

	return (1);
}
int	main(void)
{
	char	*str;
	str = "ciao";

	ft_printf(str);
}