#include <unistd.h>

static char	*search_and_replace(char *str, char find, char replace)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			str[i] = replace;
		i++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
	{
		i = 0;
		str = search_and_replace(argv[1], argv[2][0], argv[3][0]);
		while (str[i])
			write(1, &str[i++], 1);
	}
	write(1, "\n", 1);
	return(0);
}