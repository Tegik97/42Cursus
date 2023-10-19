/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:28:36 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/19 16:56:14 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;

	while (*big != '\0' && len != 0)
	{
		i = 0;
		while (*big == little[i] && little[i] != '\0' && (len - i) != 0)
		{
			i++;
			big++;
		}
		if (little[i] == '\0')
			return ((char *)(big - i));
		big -= i;
		len--;
		big++;
	}
	return (NULL);
}
