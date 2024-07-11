#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		i = 0;
		while (s2[i++])
			;
		s1 = (char *) malloc (sizeof (char) * (i + 1));
	}
	i = -1;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}
// int	main(int argc, char *argv[])
// {
// 	char	*str;

// 	str = NULL;
// 	str = ft_strcpy(str, argv[1]);
// 	printf("mine: %s\n", str);
// 	str = strcpy(str, argv[1]);
// 	printf("original: %s\n", str);
// 	return (0);
// }