/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:47:51 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/22 15:57:19 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freetrim(char **s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	offset;

	if (!*s1)
		return (NULL);
	len = 0;
	offset = 0;
	while (*s1[offset] && ft_uc_strchr(set, *s1[offset]))
		offset++;
	if (*s1[offset + len])
	{
		while (*s1[offset + len + 1])
			len++;
		while (*s1[offset + len] && ft_uc_strchr(set, *s1[offset + len]))
			len--;
	}
	str = ft_calloc(sizeof(char), (len + 1));
	while (len != 0)
	{
		len--;
		str[len] = *s1[offset + len];
	}
	free (*s1);
	return (str);
}
