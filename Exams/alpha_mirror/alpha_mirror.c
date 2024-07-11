#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	char 	*str;
	int		x;

	if (argc == 2)
	{
		i = 0;
		str = argv[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'm')
				str[i] = ('z' - str[i]) + 'a';
			else if (str[i] >= 'A' && str[i] <= 'M')
				str[i] = ('Z' - str[i]) + 'A';
			else if (str[i] >= 'n' && str[i] <= 'z')
				str[i] = ('a' - str[i]) + 'z';
			else if (str[i] >= 'N' && str[i] <= 'Z')
				str[i] = ('A' - str[i]) + 'Z';
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
