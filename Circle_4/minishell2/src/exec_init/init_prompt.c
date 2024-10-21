/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:20:12 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/21 16:51:08 by mchiaram         ###   ########.fr       */
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

int	init(void)
{
	char	*input;
	char	*prompt;

	while (1)
	{
		if (!(prompt = get_prompt()))
			return (1);
		input = readline(prompt);
		free (prompt);
		if (input[0] != '0') //just for valgrind check
			input_parse(input);
		else
		{
			free (input);
			return (1);
		}
	}
	return (0);
}
