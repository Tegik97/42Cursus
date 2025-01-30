/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:23:52 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/30 14:24:24 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(t_parse *data)
{
	char	*str;

	str = ft_substr(data->value, 1, (ft_strlen(data->value) - 2));
	free (data->value);
	data->value = NULL;
	if (*str)
		data->value = ft_strdup(str);
	free (str);
}

char	*expand_var(char *var)
{
	size_t	i;
	char	*var_name;
	char	*var_exp;

	i = 0;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	var_name = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
	{
		var_name[i] = var[i];
		i++;
	}
	var_exp = getenv(var_name);
	free(var_name);
	return (var_exp);
}

int	check_path_access(char *dir, char *value)
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
