#include <unistd.h>

static char	*ft_strtrim(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc == 2)
	{
		str = ft_strtrim(argv[1]);
		while (*str && (*str != ' ' && *str != '\t'))
			write (1, &(*str++), 1);
	}
	write (1, "\n", 1);
	return (0);
}