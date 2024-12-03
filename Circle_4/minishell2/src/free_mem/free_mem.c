/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:15:56 by mchiaram          #+#    #+#             */
/*   Updated: 2024/12/03 15:26:57 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_parse *data)
{
	t_parse	*current;

	if (data)
	{
		current = data;
		while (current)
		{
			if (current->value)
				free (current->value);
			if (current->path)
				free (current->path);
			data = data->next;
			free (current);
			current = NULL;
			current = data;
		}
	}
}
