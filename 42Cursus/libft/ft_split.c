/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:12:12 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/21 12:39:52 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fillmat(const char *s, char c, char **mat, int nwords)
{
	size_t	wordlen;

	wordlen = 0;
	while (*s == c)
		s++;
	while (nwords > 0)
	{
		if (((*s == c && *(s - 1) != c))
			|| (*s == '\0' && *(s - 1) != c))
		{
			*mat++ = ft_substr((s - wordlen), 0, wordlen);
			nwords--;
			wordlen = 0;
		}
		if (*s++ != c)
			wordlen++;
	}
	*mat = NULL;
	return (mat);
}

static int	ft_wordcount(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s == c)
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
	size_t	nwords;
	char	**ptr;

	if (!s)
		return (mat = NULL);
	nwords = ft_wordcount(s, c);
	mat = (char **) malloc(sizeof(char *) * (nwords + 1));
	ptr = mat;
	if (!mat)
		return (NULL);
	mat = ft_fillmat(s, c, mat, nwords);
	return (ptr);
}
