#include "so_long.h"

static int	check_valid_chars(char *map)
{
	int		dups[3];
	size_t	i;

	i = 0;
	while (i < 3)
		dups[i++] = 0;
	while (*map)
	{
		if (!ft_strrchr("01CEP", *map) && *map != '\n')
			return (0);
		if (*map == 'C')
			dups[0]++;
		else if (*map == 'E')
			dups[1]++;
		else if (*map == 'P')
			dups[2]++;
		map++;
	}
	if (dups[0] < 1 || dups[1] > 1 || dups[2] > 1)
		return (0);
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

static char	*get_map(char *map_name)
{
	char	*line;
	char	*map;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	map = NULL;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			get_next_line(-42);
			break ;
		}
		map = ft_strcat(&map, line);
		free (line);
	}
	close (fd);
	return (map);
}

int	parsing(int nargs, char *map_name)
{
	char	*map_path;
	char	*map;

	if (nargs != 2)
		return (0);
	if (!arg_check(map_name))
		return (0);
	map_path = NULL;
	map_path = ft_strcat(&map_path, "./maps/");
	map_path = ft_strcat(&map_path, map_name);
	map = get_map(map_path);
	if (!map || !check_valid_chars(map) || !check_walls(map))
	{
		ft_putendl_fd("Error\nNot a valid map", 2);
		free (map);
		free (map_path);
		return (0);
	}
	free (map);
	free (map_path);
	return (1);
}
