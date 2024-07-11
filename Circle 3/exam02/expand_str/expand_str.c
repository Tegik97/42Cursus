#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

static int	ft_count_words(char *str)
{
	int	i;
	int	nwords;

	i = 0;
	nwords = 0;
	while (str[i])
	{
		if ((str[i] != ' ' || str[i] != '\t') &&
			(str[i + 1] == ' ' || str[i + 1] == '\t'))
			nwords++;
		i++;
	}
	return (nwords);
}

static char	*ft_strtrim(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	i -= 2;
	while (str[i] == ' ' || str[i] == '\t')
		str[i--] = '\0';
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

static char	*ft_expand_str(char *src)
{
	int		i;
	int		nspaces;
	char	*str;

	src = ft_strtrim(src);
	nspaces = (ft_count_words(src) * 3);
	i = (ft_strlen(src) + 1);
	i += nspaces;
	str = (char *) malloc (sizeof(char) * i);
	while (i >= 0)
		str[i--] = '\0';
	i++;
	while (*src)
	{
		if ((*src != ' ' && *src != '\t') &&
			(*(src + 1) == ' ' || *(src + 1) == '\t'))
		{
			str[i++] = *src;
			nspaces = 3;
			while (nspaces-- > 0)
				str[i++] = ' ';
		}
		else if (*src != ' ' && *src != '\t')
			str[i++] = *src;
		src++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc == 2)
	{
		i = 0;
		str = ft_expand_str(argv[1]);
		while (str[i])
			write (1, &str[i++], 1);
	}
	write (1, "\n", 1);
	return (0);
}