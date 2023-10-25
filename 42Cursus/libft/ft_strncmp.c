/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:28:24 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/25 18:40:28 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || n == 0)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && n > 1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
