#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

static int	ft_strchr(char c, char *find)
{
	while (*find)
	{
		if (*find == c)
			return (1);
		find++;
	}
	return (0);
}

static char	*ft_inter(char *src, char *find)
{
	char	*str;
	int		i;

	i = (ft_strlen(src) + 1);
	str = (char *) malloc (sizeof(char) * i);
	while (i >= 0)
		str[i--] = '\0';
	i = 0;
	while (*src)
	{
		if (ft_strchr(*src, find))
		{
			if (!ft_strchr(*src, str))
				str[i++] = *src;
		}
		src++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc == 3)
	{
		i = 0;
		str = ft_inter(argv[1], argv[2]);
		while (str[i])
			write(1, &str[i++], 1);
	}
	write (1, "\n", 1);
}