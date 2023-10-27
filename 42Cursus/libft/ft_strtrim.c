/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:31:26 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/27 17:51:14 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		s1++;
	if (*s1 != '\0')
	{
		while (*s1++ != '\0')
			len++;
		s1 -= 2;
		while (ft_strchr(set, *s1) != NULL && s1--)
			len--;
	}
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len != 0)
		str[--len] = *s1--;
	return (str);
}
