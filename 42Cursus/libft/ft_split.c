/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:12:12 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/17 19:36:10 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nwords(char const *s, char c)
{
	size_t		cont;
	const char	*s_orig;

	s_orig = s;
	cont = 0;
	while (*s++ != '\0')
	{
		if (*s == c && (s != s_orig) && *(s + 1) != '\0')
			cont++;
	}
	cont++;
	return (cont);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	char const	*str_orig;
	size_t		cont;

	str = (char **) malloc(sizeof(char *) * nwords(s, c));
	str_orig = s;
	cont = 0;
	while (*s)
	{
		if (*s == c || *s == '\0')
		{
			if ((s - cont) != str_orig)
				cont--;
			*str++ = ft_substr((s - cont), 0, cont);
			cont = 0;
		}
		cont++;
		s++;
	}
	cont--;
	*str = ft_substr((s - cont), 0, cont);
	return (str);
}
/*
char	**ft_split(char const *s, char c)
{
	size_t	cont;
	int		j;
	size_t	i;
	char	**str;

	str = (char **) malloc(sizeof(char *) * nwords(s, c));
	cont = 0;
	j = -1;
	i = 0;
	while (s[j] != '\0')
	{
		if (s[++j] == c)
		{
			str[i] = (char *) malloc(sizeof(char) * cont);
			str[i] = ft_substr(s, (j - cont), cont);
			cont = 0;
			i++;
		}
		cont++;
	}
	return (str);
}
*/
