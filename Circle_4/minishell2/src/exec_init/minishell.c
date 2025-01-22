/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:40:43 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/22 18:30:05 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_parse	*data;
	t_token	*tok;

	data = malloc(sizeof(t_parse));
	tok = malloc(sizeof(t_token));
	if (!init(data, tok))
	{
		free(data);
		free(tok);
		return (1);
	}
	free(data);
	free(tok);
	return (0);
}
