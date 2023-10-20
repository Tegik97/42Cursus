/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:17:29 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/17 14:52:32 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	i;

	sstr = (char *) malloc(sizeof(char) * (len + 1));
	if (!sstr)
		return (NULL);
	len += start;
	i = 0;
	while (s[start] && start < len)
		sstr[i++] = s[start++];
	sstr[i] = '\0';
	return (sstr);
}
