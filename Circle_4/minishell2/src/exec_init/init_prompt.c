/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:20:12 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/25 16:56:48 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_prompt(void)
{
	char	*prompt;
	char	cwd[1024];
	char	*user;
	char	*path;
	size_t	i;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return (NULL);
	}
	user = getenv("USER");
	path = ft_strnstr(cwd, user, ft_strlen(cwd));
	i = 1;
	while (i++ < ft_strlen(user))
		path++;
	path[0] = '~';
	prompt = ft_strjoin("\033[1;32m", user);
	prompt = ft_freejoin(prompt, "\033[0m:\033[1;34m");
	prompt = ft_freejoin(prompt, path);
	prompt = ft_freejoin(prompt, "\033[0m$ ");
	return (prompt);
}

static void	init_struct(t_parse *data, t_token *tok)
{
	data->value = NULL;
	data->next = NULL;
	tok->value = NULL;
	tok->type = 0;
	tok->rd = NULL;
	tok->next = NULL;
}

static char	*prompt_init(void)
{
	char	*prompt;
	char	*input;

	prompt = get_prompt();
	if (!prompt)
		return (NULL);
	input = readline(prompt);
	free (prompt);
	input = ft_freetrim(&input, " \t\n");
	return (input);
}

int	init(t_parse *data, t_token *tok)
{
	char	*input;

	while (1)
	{
		input = prompt_init();
		if (input && *input)
		{
			init_struct(data, tok);
			add_history(input);
			input_parse(input, data, tok);
			free_all(data, tok);
		}
		else if (!input)
		{
			rl_clear_history();
			free (input);
			return (1);
		}
		free (input);
	}
	return (0);
}
