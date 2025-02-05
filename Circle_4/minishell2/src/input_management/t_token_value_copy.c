/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_value_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:22:57 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/05 11:53:36 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_path(t_token *tok, char *value)
{
	char	*path_env;
	char	**dir;
	int		i;

	path_env = ft_getenv(tok->env->var, "PATH");
	if (!path_env)
		return (0);
	dir = ft_split(path_env, ':');
	path_env = ft_freelcopy(&path_env, value, ft_strlen(value));
	i = -1;
	while (dir[++i])
	{
		if (check_path_access(dir[i], value))
		{
			free(path_env);
			path_env = ft_strjoin(dir[i], "/");
			path_env = ft_freejoin(path_env, value);
			break ;
		}
	}
	i = 0;
	while (dir[i])
		free (dir[i++]);
	free (dir);
	return (path_env);
}

static char	*get_var_str(t_token *tok, t_parse *data, size_t i, char *str)
{
	char	*var;
	char	*var_val;

	if (str)
		free (str);
	var = ft_substr(data->value, (i + 1), ft_strlen(data->value));
	if (var[0] == '?')
		var_val = ft_strdup("$?");
	else
		var_val = expand_var(tok, var);
	str = ft_substr(data->value, 0, i);
	if (var_val)
	{
		str = ft_freejoin(str, var_val);
		free (var_val);
	}
	i++;
	while (data->value[i] && (ft_isalnum(data->value[i])
			|| data->value[i] == '_' || data->value[i] == '?'))
		i++;
	var_val = ft_substr(data->value, i, ft_strlen(data->value));
	if (var_val && *var_val)
		str = ft_freejoin(str, var_val);
	threerowstoolong(data, &var, &var_val, str);
	return (str);
}

static char	*check_var(t_parse *data, t_token *tok)
{
	size_t	i;
	char	*str;

	str = ft_strdup(data->value);
	if (data->type == T_DQUOTE)
	{
		i = 0;
		while (data->value[i])
		{
			if (data->value[i] == '$' && data->value[i + 1] == '?')
				str = ft_itoa(tok->env->exit_stat);
			else if (data->value[i] == '$')
			{
				str = get_var_str(tok, data, i, str);
				i = 0;
			}
			i++;
		}
	}
	else if (data->type == T_EXIT_STAT)
		str = ft_itoa(tok->env->exit_stat);
	return (str);
}

size_t	get_tok(t_parse *data, t_token *new_tok, t_redir *new_rd, size_t i)
{
	if (data && (data->type >= T_GENERAL && data->type <= T_COMMAND))
	{
		if (data->type >= T_QUOTE && data->type <= T_VAR)
		{
			if (data->type == T_QUOTE || data->type == T_DQUOTE)
				remove_quotes(data);
			if (data->value)
				new_tok->value[i++] = check_var(data, new_tok);
		}
		else if (i == 0 && data->type != T_BUILTIN)
			new_tok->value[i++] = find_path(new_tok, data->value);
		else
			new_tok->value[i++] = ft_strdup(data->value);
	}
	else if (data && (data->type >= T_RED_IN && data->type <= T_DELIM))
	{
		new_rd->type = data->type;
		new_rd->name = ft_strdup(data->next->value);
	}
	return (i);
}

size_t	first_tok_copy(t_parse *data, t_token *tok, t_redir *rd, size_t i)
{
	if (data && (data->type >= T_GENERAL && data->type <= T_COMMAND))
	{
		if (data->type >= T_QUOTE && data->type <= T_VAR)
		{
			if (data->type == T_QUOTE || data->type == T_DQUOTE)
				remove_quotes(data);
			if (data->value)
				tok->value[i++] = check_var(data, tok);
		}
		else if (i == 0 && data->type != T_BUILTIN)
			tok->value[i++] = find_path(tok, data->value);
		else
			tok->value[i++] = ft_strdup(data->value);
	}
	else if (data && (data->type >= T_RED_IN && data->type <= T_DELIM))
	{
		rd->type = data->type;
		rd->name = ft_strdup(data->next->value);
	}
	return (i);
}
