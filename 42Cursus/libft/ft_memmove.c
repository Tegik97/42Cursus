/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:13:04 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/21 11:15:15 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_dest == ptr_src)
		return (dest);
	if (ptr_dest < ptr_src)
	{
		while (n-- > 0)
			*(ptr_dest++) = *(ptr_src++);
	}
	else
	{
		ptr_dest += n;
		ptr_src += n;
		while (n > 0)
		{
			*(--ptr_dest) = *(--ptr_src);
			n--;
		}
	}
	return (dest);
}
