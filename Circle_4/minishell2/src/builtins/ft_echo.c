/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/05 14:57:05 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_token *data, int fd)
{
	size_t	i;
	int		new_line;

	i = 1;
	new_line = 1;
	if (data->value[i] && ft_strncmp(data->value[i], "-n", ft_strlen(data->value[0])) == 0)
	{
		new_line = 0;
		i++;
	}
	while (data->value[i])
	{
		if (i > 1)
			write(fd, " ", 1);
		write(fd, data->value[i], ft_strlen(data->value[i]));
		i++;
	}
	if (new_line == 1)
		write(fd, "\n", 1);
	data->env->exit_stat = 0;
}
