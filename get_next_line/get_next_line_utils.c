/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:41:33 by mchiaram          #+#    #+#             */
/*   Updated: 2024/03/20 17:59:58 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if (*s == (char)c)
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(*s1));
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(((ft_strlen(s1) + ft_strlen(s2) + 1)), sizeof(*s1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free (s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	len;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	len = 0;
	while (len < nmemb)
	{
		ptr[len] = '\0';
		len++;
	}
	return (ptr);
}
