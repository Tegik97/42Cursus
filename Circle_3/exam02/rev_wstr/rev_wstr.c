#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &(*str++), 1);
}

static int	ft_count_words(char *str)
{
	int	nwords;

	nwords = 0;
	while (*str)
	{
		if (*str != ' ' && *(str + 1) == ' ')
			nwords++;
		str++;
	}
	return (nwords + 1);
}

static char	**ft_split(char *str)
{
	int 	nwords;
	char	**mat;
	int		offset;
	int		i;
	
	nwords = ft_count_words(str);
	mat = (char **) malloc (sizeof(char *) * (nwords + 1));
	mat[nwords] = NULL;
	nwords--;
	offset = 0;
	while (nwords >= 0)
	{
		if (*(str + offset) == ' ')
		{
			mat[nwords] = (char *) malloc (sizeof(char) * (offset));
			mat[nwords][offset - 1] = '\0';
			i = 0;
			while (--offset >= 0)
				mat[nwords][i++] = *str++;
			nwords--;
			str++;
		}
		offset++;
	}
	return (mat);
}

static void	ft_rev_wstr(char *str)
{
	char	**mat;
	int		i;

	i = 0;
	mat = ft_split(str);
	while (mat[i])
	{
		ft_putstr(mat[i++]);
		if (mat[i] != NULL)
			write (1, " ", 1);
	}
	i = 0;
	while (mat[i])
		free (mat[i++]);
	free (mat);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_rev_wstr(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}