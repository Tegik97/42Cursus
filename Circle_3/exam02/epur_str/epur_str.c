#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &(*str++), 1);
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
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

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
	int	nwords;

	nwords = 0;
	while (*(str + 1))
	{
		if ((*str != ' ' && *str != '\t') &&
			(*(str + 1) == ' ' || *(str + 1) == '\t' || *(str + 1) == '\0'))
			nwords++;
		str++;
	}
	return (nwords);
}

static void	ft_epur_str(char *src)
{
	int		nwords;
	char	*str;
	int		i;

	src = ft_strtrim(src);
	nwords = ft_count_words(src);
	nwords += ft_strlen(src);
	str = (char *) malloc (sizeof(char) * nwords);
	str[nwords] = '\0';
	i = 0;
	while (*src)
	{
		if ((*src != ' ' && *src != '\t') &&
			(*(src + 1) == ' ' || *(src + 1) == '\t'))
		{
			str[i++] = *src++;
			str[i++] = ' ';
			while (*src == ' ' || *src == '\t')
				src++;
		}
		else if (*src != ' ' && *src != '\t')
			str[i++] = *src++;
	}
	ft_putstr(str);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_epur_str(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}