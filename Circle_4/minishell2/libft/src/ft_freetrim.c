/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:47:51 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/24 11:06:50 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freetrim(char **s1, char const *set)
{
	char	*str;
	size_t	l;
	size_t	os;

	if (!*s1)
		return (NULL);
	l = 0;
	os = 0;
	while ((*s1)[os] && ft_uc_strchr(set, (*s1)[os]))
		os++;
	if ((*s1)[os + l])
	{
		while ((*s1)[os + l])
			l++;
		while ((*s1)[os + (l - 1)] && ft_uc_strchr(set, (*s1)[os + (l - 1)]))
			l--;
	}
	str = ft_calloc(sizeof(char), (l + 1));
	while (l != 0)
	{
		l--;
		str[l] = (*s1)[os + l];
	}
	free (*s1);
	return (str);
}
