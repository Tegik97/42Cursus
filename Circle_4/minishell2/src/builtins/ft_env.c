/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/05 19:59:47 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_env(t_token *data)
{
	int	i;

	i = 0;
	while (data->env->var[i])
	{
		if (ft_strchr(data->env->var[i], '='))
			printf("%s\n", data->env->var[i++]);
		else
			i++;
	}
	data->env->exit_stat = 0;
}
