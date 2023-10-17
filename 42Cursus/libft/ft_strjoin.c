/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:55:22 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/17 15:23:04 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		str[i++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
