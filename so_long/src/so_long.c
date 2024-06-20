#include "so_long.h"

void	get_size_window(t_data *game, char *map_name)
{
	int		x;
	int		y;
	char	*map_path;
	char	*map;

	map_path = NULL;
	map_path = ft_strcat(&map_path, "./maps/");
	map_path = ft_strcat(&map_path, map_name);
	map = get_map(map_path);
	free (map_path);
	game->map = map_to_mat(map);
	free (map);
	if (!game->map)
		return ;
	x = -1;
	y = -1;
	game->width = 0;
	game->height = 0;
	while (game->map[0][++x] && game->width < 1920)
		game->width = (x + 1) * 48;
	while (game->map[++y] && game->height < 1008)
		game->height = (y + 1) * 48;
}

int	destroy(t_data *game)
{
	free_all(game);
	free (game);
	exit(0);
	return (0);
}

int	keypress(int key, t_data *game)
{
	if (key == 65307)
		destroy(game);
	if (game->is_updating == 0)
	{
		game->is_updating = 1;
		if (key == 65362 || key == 119)
			move_up(game);
		else if (key == 65364 || key == 115)
			move_down(game);
		else if (key == 65361 || key == 97)
			move_left(game);
		else if (key == 65363 || key == 100)
			move_right(game);
		if (game->exit == 1)
			exit_ready(game);
		put_num_moves(game, 24, (game->height + 16));
		game->is_updating = 0;
	}
	return (0);
}

int	game_init(char *map_name)
{
	t_data	*game;

	game = (t_data *)malloc(sizeof(t_data));
	get_size_window(game, map_name);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, \
	game->height + 48, "dinokekw");
	game->is_updating = 0;
	game->nmoves = 0;
	init_num_image(game);
	put_background(game->mlx, game->win, game->map, 48);
	put_image(game);
	mlx_loop_hook(game->mlx, change_frame, (void *)game);
	mlx_hook(game->win, 3, 1L << 1, &keypress, game);
	mlx_hook(game->win, 17, 0L, &destroy, game);
	mlx_loop(game->mlx);
	return (1);
}
// 65307 è l'escape key

// int	keypress(int key, t_data *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", key);
// 	return (0);
// }

// int	destroy(t_data *data)
// {
// 	mlx_destroy_window(data->mlx, data->window);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	exit(0);
// 	return (0);
// }