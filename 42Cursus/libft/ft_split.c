/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:12:12 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/18 17:01:04 by menny            ###   ########.fr       */
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
