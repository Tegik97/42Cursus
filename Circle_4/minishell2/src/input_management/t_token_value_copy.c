#include "minishell.h"

static char	*find_path(char *value)
{
	char	*path_env;
	char	**dir;
	int		i;

	path_env = getenv("PATH");
	if (!path_env)
		return (0);
	dir = ft_split(path_env, ':');
	path_env = ft_strdup(value);
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

size_t	get_tok(t_parse *data, t_token *new_tok, t_redir *new_rd, size_t i)
{
	if (data && (data->type >= T_GENERAL && data->type <= T_COMMAND))
	{
		if (i == 0 && data->type != T_BUILTIN && data->type != T_VAR)
			new_tok->value[i++] = find_path(data->value);
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
		if (i == 0 && data->type != T_BUILTIN && data->type != T_VAR)
			tok->value[i++] = find_path(data->value);
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
