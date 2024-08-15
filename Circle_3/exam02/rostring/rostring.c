#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	ft_putstr(char *str)
{
	while (*str)
		write (1, &(*str++), 1);
}

static int	ft_count_words(char *str)
{
	int	nwords;

	nwords = 0;
	while (*str)
	{
		if (*str == ' ')
			nwords++;
		str++;
	}
	return (nwords + 1);
}

static char	**ft_split(char *str)
{
	char	**mat;
	int		offset;
	int		nwords;
	int		i;
	int		j;

	nwords = ft_count_words(str);
	mat = (char **) malloc (sizeof(char *) * (nwords + 1));
	offset = 0;
	i = 0;
	j = 0;
	while (nwords > 0)
	{
		while (*(str + offset) && *(str + offset) != ' ')
			offset++;
		mat[j] = (char *) malloc (sizeof(char) * (offset + 1));
		mat[j][offset] = '\0';
		while (offset > 0)
		{
			mat[j][i++] = *str++;
			offset--;
		}
		str++;
		i = 0;
		j++;
		nwords--;
	}
	return (mat);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

static char	*ft_strtrim(char *src)
{
	int		i;
	char	*str;

	while (*src == ' ' || *src == '\t')
		src++;
	i = (ft_strlen(src) - 1);
	while (src[i] == ' ' || src[i] == '\t')
		src[i--] = '\0';
	str = (char *) malloc (sizeof(char) * (i + 1));
	i = 0;
	while (*src)
	{
		if ((*src != ' ' && *src != '\t') &&
				(*(src + 1) == ' ' || *(src + 1) == '\t')) 
		{
			str[i++] = *src++;
			str[i++] = ' ';
		}
		else if (*src != ' ' && *src != '\t')
			str[i++] = *src++;
		else
			src++;
	}
	str[i] = '\0';
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	**mat;
	int		i;

	if (argc > 1)
	{
		str = ft_strtrim(argv[1]);
		mat = ft_split(str);
		i = 1;
		while (mat[i])
		{
			ft_putstr(mat[i++]);
			write (1, " ", 1);
		}
		ft_putstr(mat[0]);
		i = 0;
		free (str);
	}
	write (1, "\n", 1);
	return (0);
}
