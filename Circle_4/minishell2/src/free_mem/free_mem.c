/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:15:56 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/22 18:21:32 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void free_token(t_token *tok)
{
	t_token *current;

	current = tok;
	while (current)
	{
		if (current->value)
			free (current->value);
		if (current->rd)
			free(current->rd->name);
		tok = tok->next;
		free (current);
		current = NULL;
		current = tok;
	}
}

static void	free_parse(t_parse *data)
{
	t_parse	*current;

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
	if (data->next)
	{
		data = data->next;
		free_parse(data);
	}
	if (tok->next)
	{
		tok = tok->next;
		free_token(tok);
	}
}
