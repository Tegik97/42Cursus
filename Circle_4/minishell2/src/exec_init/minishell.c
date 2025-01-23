/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:40:43 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/23 16:05:25 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigquit_handler(int sig)
{
	(void)sig;
}

static void	sigint_handler(int sig)
{
	(void)sig;
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

int	main(void)
{
	t_parse	*data;
	t_token	*tok;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
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
