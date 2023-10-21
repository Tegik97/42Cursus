/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:15:19 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/21 11:44:06 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	offset;

	offset = 0;
	if (!dst || !src || size == 0)
		return (ft_strlen(src));
	while (*(src + offset) != '\0' && offset < (size - 1))
	{
		*(dst + offset) = *(src + offset);
		offset++;
	}
	*(dst + offset) = '\0';
	return (ft_strlen(src));
}
