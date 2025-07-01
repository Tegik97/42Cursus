#include "map_parsing.h"
#include "check_map_validity.h"

static char	**copy_map(int fd, char *line)
{
	char	*fullMap;
	char	**map;

	fullMap = NULL;
	while (line)
	{
		fullMap = ft_freejoin(fullMap, " ");
		fullMap = ft_freejoin(fullMap, line);
		free (line);
		line = get_next_line(fd);
	}
	map = ft_split(fullMap, '\n');
	free (fullMap);
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

char	**get_map(int fd)
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
	map = copy_map(fd, line);
	if (!map_validity(map))
	{
		map = free_mat(map);
		close(fd);
		return (map);
	}
	return (map);
}
