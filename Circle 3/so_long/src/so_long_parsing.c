/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:26:18 by mchiaram          #+#    #+#             */
/*   Updated: 2024/06/21 11:26:19 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_valid_chars(char *map)
{
	int		dups[4];
	size_t	i;

	i = 0;
	while (i < 4)
		dups[i++] = 0;
	while (*map)
	{
		if (!ft_strrchr("01CEPN", *map) && *map != '\n')
			dups[3] = 1;
		if (*map == 'C')
			dups[0]++;
		else if (*map == 'E')
			dups[1]++;
		else if (*map == 'P')
			dups[2]++;
		map++;
	}
	if (dups[0] < 1 || dups[1] > 1 || dups[2] > 1 || dups[3] == 1)
	{
		ft_putendl_fd("Error!\nSome characters are not valid", 2);
		return (0);
	}
	return (1);
}

static int	arg_check(char *arg)
{
	if (*arg == '.')
	{
		ft_putendl_fd("Error\nNot a valid .ber file", 2);
		return (0);
	}
	while (arg)
	{
		if (*arg == '.')
		{
			if (ft_strncmp(arg, ".ber", (ft_strlen(arg) + 1)) != 0)
			{
				ft_putendl_fd("Error\nNot a valid .ber file", 2);
				return (0);
			}
			else
				break ;
		}
		arg++;
	}
	return (1);
}

int	parsing(int nargs, char *map_name)
{
	char	*map_path;
	char	*map;

	if (nargs != 2 || !arg_check(map_name))
		return (0);
	map_path = NULL;
	map_path = ft_strcat(&map_path, "./maps/");
	map_path = ft_strcat(&map_path, map_name);
	map = get_map(map_path);
	if (!map || !check_valid_chars(map)
		|| !check_walls(map) || !floodfill_check(map))
	{
		free (map);
		free (map_path);
		return (0);
	}
	free (map);
	free (map_path);
	return (1);
}
