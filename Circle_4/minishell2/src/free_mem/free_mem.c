/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:15:56 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/21 16:17:21 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(char *input, char *str, t_parse *data)
{
	t_parse *current;

	current = data;
	if (str)
		free (str);
	if (input)
		free (input);
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