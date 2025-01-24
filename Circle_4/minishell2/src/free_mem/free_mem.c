/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:15:56 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/24 10:30:42 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_token(t_token *tok)
{
	t_token	*current;
	size_t	i;

	current = tok;
	while (current)
	{
		i = 0;
		if (current->value)
		{
			while (current->value[i])
				free(current->value[i++]);
			free (current->value);
		}
		if (current->rd)
		{
			free(current->rd->name);
			free(current->rd);
		}
		tok = tok->next;
		free (current);
		current = NULL;
		current = tok;
	}
}

static void	free_parse(t_parse *data)
{
	t_parse	*current;

	if (data->value)
		free (data->value);
	data = data->next;
	current = data;
	while (current)
	{
		if (current->value)
			free (current->value);
		data = data->next;
		free (current);
		current = NULL;
		current = data;
	}
}

void	free_all(t_parse *data, t_token *tok)
{
	size_t	i;

	if (data)
		free_parse(data);
	if (tok)
	{
		i = 0;
		if (tok->value)
		{
			while (tok->value[i])
				free(tok->value[i++]);
			free (tok->value);
		}
		if (tok->rd)
		{
			free(tok->rd->name);
			free(tok->rd);
		}
		tok = tok->next;
		free_token(tok);
	}
}
