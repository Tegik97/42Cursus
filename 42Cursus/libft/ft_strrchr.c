#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	while (i > 0)
	{
		if (*s == c)
			return (char *) s;
		s--;
		i--;
	}
	
	return NULL;
}