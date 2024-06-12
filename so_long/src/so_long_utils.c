#include "so_long.h"

size_t	*get_char_pos(char **mat)
{
	size_t	x;
	size_t	y;
	size_t	*char_pos;

	char_pos = ft_calloc(4, sizeof(size_t));
	y = 0;
	char_pos[2] = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == 'P')
			{
				char_pos[0] = x;
				char_pos[1] = y;
			}
			else if (mat[y][x] == 'C')
				char_pos[2]++;
			x++;
		}
		y++;
	}
	return (char_pos);
}

static char	**get_map_size(char *map)
{
	size_t	*size;
	char	**mat;

	size = ft_calloc(2, sizeof(size_t));
	size[0] = 0;
	size[1] = 0;
	while (map[size[0]] != '\n')
		size[0]++;
	while (*map)
	{
		if (*map == '\n' && *(map + 1) != '\0')
			size[1]++;
		map++;
	}
	mat = ft_calloc((size[1] + 2), sizeof(char *));
	while (size[1] != 0)
	{
		mat[size[1]] = ft_calloc((size[0] + 1), sizeof(char));
		size[1]--;
	}
	mat[size[1]] = ft_calloc((size[0] + 1), sizeof(char));
	free(size);
	return (mat);
}

char	**map_to_mat(char *map)
{
	char	**mat;
	size_t	x;
	size_t	y;

	mat = NULL;
	mat = get_map_size(map);
	x = 0;
	y = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			x = 0;
			y++;
		}
		else
			mat[y][x++] = *map;
		map++;
	}
	return (mat);
}

char	*get_map(char *map_name)
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