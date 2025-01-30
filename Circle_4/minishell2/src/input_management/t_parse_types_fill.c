/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_types_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:04 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/30 14:23:05 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_if_var(t_parse *data)
{
	char	*str;
	char	*var_val;
	size_t	i;

	i = 0;
	if ((data && data->value) && data->value[i] == '$')
	{
		if (data->value[i + 1] && data->value[i + 1] == '?')
		{
			data->type = T_EXIT_STAT;
			return (0);
		}
		str = ft_substr(data->value, 1, ft_strlen(data->value));
		var_val = expand_var(str);
		free (str);
		free (data->value);
		data->value = ft_strdup(var_val);
		return (1);
	}
	return (0);
}

static int	check_if_command(char *value)
{
	char	*path_env;
	char	**dir;
	size_t	i;

	path_env = getenv("PATH");
	if (!path_env)
		return (0);
	dir = ft_split(path_env, ':');
	i = 0;
	while (dir[i])
	{
		if (check_path_access(dir[i++], value))
		{
			i = 0;
			while (dir[i])
				free (dir[i++]);
			free (dir);
			return (1);
		}
	}
	i = 0;
	while (dir[i])
		free (dir[i++]);
	free (dir);
	return (0);
}

int	check_if_builtin(char *value)
{
	const char	**builtins;
	size_t		i;

	builtins = malloc(sizeof(char *) * 8);
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (!ft_strncmp(value, builtins[i++], ft_strlen(value)))
		{
			free (builtins);
			return (1);
		}
	}
	free (builtins);
	return (0);
}

static int	check_if_quote(t_parse *data)
{
	if (data->value[0] == '\'')
		data->type = T_QUOTE;
	else if (data->value[0] == '\"')
		data->type = T_DQUOTE;
	else if (data->value[0] == '<')
	{
		if (data->value[1] == '<')
			data->type = T_DELIM;
		else
			data->type = T_RED_IN;
	}
	else if (data->value[0] == '>')
	{
		if (data->value[1] == '>')
			data->type = T_RED_APPEN;
		else
			data->type = T_RED_OUT;
	}
	if (data->type == T_GENERAL)
		return (0);
	else if (data->type >= T_RED_IN && data->type <= T_DELIM)
		data->next->type = T_LIM;
	return (1);
}

int	fill_t_parse_types(t_parse *data)
{
	if (!data->value)
		return (0);
	while (data)
	{
		if (!check_if_quote(data))
		{
			if (check_if_builtin(data->value))
				data->type = T_BUILTIN;
			else if (check_if_command(data->value))
				data->type = T_COMMAND;
			else if (check_if_var(data))
				data->type = T_VAR;
			else if (data->value[0] == '|' && !data->value[1])
				data->type = T_PIPE;
		}
		data = data->next;
		if (data && data->type != T_GENERAL)
			data = data->next;
	}
	return (1);
}
