/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:45:01 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/27 15:23:50 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	if (dest && src)
	{
		ptr_dest = (unsigned char *)dest;
		ptr_src = (const unsigned char *)src;
		while (n != 0)
		{
			*(ptr_dest++) = *(ptr_src++);
			n--;
		}
	}
	return (dest);
}
