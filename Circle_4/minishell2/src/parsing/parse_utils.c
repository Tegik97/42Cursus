/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:23:52 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/24 15:20:04 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
