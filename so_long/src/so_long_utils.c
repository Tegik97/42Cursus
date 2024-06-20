#include "so_long.h"

void	free_all(t_data *game)
{
	size_t	i;

	if (game)
	{
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		if (game->map)
			free(game->map);
		if (game->num_img)
		{
			i = 0;
			while (i < 10)
				mlx_destroy_image(game->mlx, game->num_img[i++]);
			free (game->num_img);
		}
		if (game->water_img && game->dino_img && game->win && game->mlx)
		{
			free (game->water_img);
			free (game->dino_img);
			mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			free (game->mlx);
		}
	}
}

void	get_char_pos(t_data *game, char **mat)
{
	size_t	x;
	size_t	y;

	y = 0;
	game->coll = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == 'P')
			{
				game->dino_x = x;
				game->dino_y = y;
			}
			else if (mat[y][x] == 'C')
				game->coll++;
			x++;
		}
		y++;
	}
	game->exit = 0;
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
	if (size[0] > 39 || size[1] > 20)
		return (NULL);
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
	if (!mat)
		return (NULL);
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
		ft_putendl_fd("Error!\nFile not found", 2);
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
	if (fd != -1)
		close (fd);
	return (map);
}
