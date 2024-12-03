#include "minishell.h"

static int	check_path_access(char *dir, char *value)
{
	char	*path;

	path = ft_strjoin(dir, "/");
	path = ft_freejoin(path, value);
	if (access(path, X_OK) == 0)
	{
		free (path);
		return (1);
	}
	free (path);
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

static int	check_if_quote(t_parse *data)
{
	if (data->value[0] == T_QUOTE)
		data->type = T_QUOTE;
	else if (data->value[0] == T_DQUOTE)
		data->type = T_DQUOTE;
	else if (data->value[0] == T_RED_IN)
	{
		if (data->value[1] == T_RED_IN)
			data->type = T_DELIM;
		else
			data->type = T_RED_IN;
	}
	else if (data->value[0] == T_RED_OUT)
	{
		if (data->value[1] == T_RED_OUT)
			data->type = T_RED_APPEN;
		else
			data->type = T_RED_OUT;
	}
	if (data->type == T_GENERAL)
		return (0);
	else if (data->next && (data->type != T_FILE
			&& data->type != T_QUOTE && data->type != T_DQUOTE))
		data->next->type = T_FILE;
	return (1);
}

void	fill_t_parse_types(t_parse *data)
{
	while (data)
	{
		if (!check_if_quote(data))
		{
			if (check_if_command(data->value))
				data->type = T_COMMAND;
			else if (data->value[0] == T_PIPE && !data->value[1])
				data->type = T_PIPE;
		}
		data = data->next;
		if (data->type != T_GENERAL)
			data = data->next;
	}
}
