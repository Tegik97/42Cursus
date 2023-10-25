/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:14:53 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/25 18:24:04 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	while (i >= 0)
	{
		if (*s == (char)c)
			return ((char *) s);
		s--;
		i--;
	}
	return (NULL);
}
