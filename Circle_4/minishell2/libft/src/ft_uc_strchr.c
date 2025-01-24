/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uc_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:22:20 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/24 11:08:39 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uc_strchr(const char *s, int c)
{
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == (char)uc)
			return ((char *) s);
		s++;
	}
	if (*s == (char)uc)
		return ((char *) s);
	return (NULL);
}
