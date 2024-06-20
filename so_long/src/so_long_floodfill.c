#include "so_long.h"

static int	check_space(size_t x, size_t y, char **mat, t_data *game)
{
	if (mat[y][(x + 1)] != '1' && mat[y][(x + 1)] != 'N')
	{
		if (map_floodfill((x + 1), y, mat, game))
			return (1);
	}
	if (mat[y][(x - 1)] != '1' && mat[y][(x - 1)] != 'N')
	{
		if (map_floodfill((x - 1), y, mat, game))
			return (1);
	}
	if (mat[y + 1][(x)] != '1' && mat[y + 1][(x)] != 'N')
	{
		if (map_floodfill(x, (y + 1), mat, game))
			return (1);
	}
	if (mat[y - 1][(x)] != '1' && mat[y - 1][(x)] != 'N')
	{
		if (map_floodfill(x, (y - 1), mat, game))
			return (1);
	}
	return (0);
}

static void	check_value(size_t x, size_t y, char **mat, t_data *game)
{
	if (mat[y][x] == 'C')
	{
		game->coll--;
		mat[y][x] = '1';
	}
	else if (mat[y][x] == 'E')
	{
		game->exit = 1;
		mat[y][x] = '1';
	}
	else
		mat[y][x] = '1';
}

int	map_floodfill(size_t x, size_t y, char **mat, t_data *game)
{
	check_value(x, y, mat, game);
	if (game->coll == 0 && game->exit == 1)
		return (1);
	if (check_space(x, y, mat, game))
		return (1);
	return (0);
}

static void	set_game_struct(t_data *game)
{
	game->water_img = NULL;
	game->dino_img = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->num_img = NULL;
}

int	floodfill_check(char *map)
{
	t_data	*game;

	game = (t_data *)malloc(sizeof(t_data));
	set_game_struct(game);
	game->map = map_to_mat(map);
	if (!game->map)
	{
		ft_putendl_fd("Error\nMap is too big", 2);
		return (0);
	}
	get_char_pos(game, game->map);
	if (!map_floodfill(game->dino_x, game->dino_y, game->map, game))
	{
		if (game->coll != 0)
			ft_putendl_fd("Error!\nCan't reach all collectables", 2);
		else
			ft_putendl_fd("Error!\nCan't reach exit", 2);
		free_all(game);
		return (0);
	}
	free_all(game);
	free (game);
	return (1);
}
