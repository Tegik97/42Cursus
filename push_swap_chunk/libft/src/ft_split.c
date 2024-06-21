/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:12:12 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/03 13:24:47 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemat(char **mat)
{
	while (*mat)
		free(*mat++);
}

static char	**ft_fillmat(const char *s, char c, char **mat, int nwords)
{
	size_t	wordlen;
	size_t	i;

	wordlen = 0;
	i = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (nwords > 0)
	{
		if (((*s == c && *(s - 1) != c))
			|| (*s == '\0' && *(s - 1) != c))
		{
			mat[i] = ft_substr((s - wordlen), 0, wordlen);
			if (!mat[i++])
				return (NULL);
			nwords--;
			wordlen = 0;
		}
		if (*s++ != c)
			wordlen++;
	}
	mat[i] = NULL;
	return (mat);
}

static int	ft_wordcount(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (*s++ != '\0')
	{
		if (((*s == c && *(s - 1) != c))
			|| (*s == '\0' && *(s - 1) != c))
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != c)
			return (NULL);
		i++;
	}
	i = ft_wordcount(s, c);
	mat = (char **) malloc(sizeof(char *) * (i + 1));
	if (!mat)
		return (NULL);
	mat = ft_fillmat(s, c, mat, i);
	if (!mat)
	{
		ft_freemat(mat);
		return (NULL);
	}
	return (mat);
}

/*int	main(int argc, char *argv[])
{
	char	**mat;

	if (argc == 3)
	{
		printf("Split the string '%s'\n\n", argv[1]);
		mat = ft_split(argv[1], argv[2][0]);
		while (*mat)
			printf("%s\n", *mat++);
	}
}*/

/*				---MAN DESCRIPTION---
	Allocates (with malloc(3)) and returns an array
	of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter. The array must end
	with a NULL pointer.

	---RETURN VALUE---
	The array of new strings resulting from the split.
	NULL if the allocation fails.
*/