/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:13:04 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/12 17:16:06 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while (n != 0)
	{
		if (ptr_dest > ptr_src)
			ptr_dest[n] = ptr_src[n];
		else
			*(ptr_dest++) = *(ptr_src++);
		n--;
	}
	return (dest);
}
