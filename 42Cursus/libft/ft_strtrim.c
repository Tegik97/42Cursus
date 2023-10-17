/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:31:26 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/17 17:00:31 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	len = 0;
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		s1++;
	while (*s1++ != '\0')
		len++;
	s1 -= 2;
	while (ft_strchr(set, *s1) != NULL)
	{
		s1--;
		len--;
	}
	str = (char *) malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len != 0)
		str[--len] = *s1--;
	return (str);
}
