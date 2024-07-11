#include <unistd.h>

char	*rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') &&
			(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
		str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*str;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			str = rstr_capitalizer(argv[i]);
			while (*str)
				write (1, &(*str++), 1);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}
