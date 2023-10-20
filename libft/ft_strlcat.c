/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:53:17 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/19 16:55:36 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;

	dst_l = 0;
	while (*dst != '\0')
	{
		dst_l++;
		dst++;
	}
	if (dst_l >= size)
		return (size);
	while (*src != '\0' && (size - dst_l - 1) > 0)
	{
		*dst = *src;
		dst_l++;
		dst++;
		src++;
	}
	*dst = '\0';
	dst_l++;
	return (dst_l);
}
