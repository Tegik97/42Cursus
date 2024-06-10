#include "so_long.h"

static int	check_rectangular(char *map)
{
	size_t	rows;
	size_t	columns;

	rows = 0;
	columns = 0;
	while (map[columns] != '\n')
		columns++;
	while (*map)
	{
		if (*map == '\n')
			rows++;
		map++;
	}
	rows++;
	if (rows == columns)
		return (0);
	return (1);
}

static int	check_wall_size(char *map)
{
	long long int	current_size;
	long long int	first_line_size;

	if (!check_rectangular(map))
		return (0);
	first_line_size = 0;
	while (map[first_line_size] != '\n')
		first_line_size++;
	while (*map)
	{
		current_size = 0;
		while (map[current_size] != '\n' && map[current_size])
			current_size++;
		if (current_size != first_line_size)
			return (0);
		while (current_size-- >= 0 && *map)
			map++;
	}
	return (1);
}

static int	check_line(char *line, const size_t nline)
{
	if (nline < 2)
	{
		while (*line)
		{
			if (*line != '1')
				return (0);
			line++;
		}
	}
	else
	{
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_walls(char *map)
{
	char			*line;
	long long int	size;
	size_t			nline;

	nline = 1;
	while (*map)
	{
		line = NULL;
		size = 0;
		while (map[size] != '\n' && map[size])
			size++;
		if (!map[size])
			nline = 0;
		line = ft_stringlcopy(line, map, (size + 1));
		if (!check_line(line, nline) || (nline == 1 && !check_wall_size(map)))
		{
			free (line);
			return (0);
		}
		while (size-- >= 0 && *map)
			map++;
		nline++;
		free (line);
	}
	return (1);
}
