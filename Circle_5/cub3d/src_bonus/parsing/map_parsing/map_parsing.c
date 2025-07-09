#include "map_parsing.h"
#include "check_map_validity.h"

static char	**fill_map(char **map, t_game *g)
{
	size_t	row;

	row = 0;
	while (row < g->map_h)
	{
		while (ft_strlen(map[row]) < g->map_w)
			map[row] = ft_freejoin(map[row], " ");
		row++;
	}
	return (map);
}

static char	**copy_map(int fd, char *line, t_game *g)
{
	char	*fullMap;
	char	**map;

	fullMap = NULL;
	while (line)
	{
		fullMap = ft_freejoin(fullMap, " ");
		fullMap = ft_freejoin(fullMap, line);
		g->map_h++;
		if (ft_strlen(line) > g->map_w)
			g->map_w = ft_strlen(line);
		free (line);
		line = get_next_line(fd);
	}
	map = ft_split(fullMap, '\n');
	free (fullMap);
	map = fill_map(map, g);
	return (map);
}

static int	find_map_start(char *line)
{
	char	*trimLine;

	trimLine = ft_strtrim(line, " \t\n");
	if (*trimLine == '1')
	{
		free (trimLine);
		return (1);
	}
	free (trimLine);
	return (0);
}

char	**get_map(int fd, t_game *g)
{
	char	*line;
	char	**map;

	map = NULL;
	line = get_next_line(fd);
	while (line && !find_map_start(line))
	{
		free (line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		ft_putstr_fd("Error\nMap not found\n", 2);
		return (NULL);
	}
	map = copy_map(fd, line, g);
	if (!map_validity(map))
	{
		map = free_mat(map);
		close(fd);
		return (map);
	}
	return (map);
}
