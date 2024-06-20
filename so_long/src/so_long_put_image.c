#include "so_long.h"

void	exit_ready(t_data *game)
{
	int		x;
	int		y;
	char	*img_path;
	void	*img;

	y = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'E')
			{
				img_path = NULL;
				img_path = ft_stringlcopy(img_path, "./assets/exit/open_", 20);
				img_path = ft_strcat(&img_path, search_image(game->map, x, y));
				img = mlx_xpm_file_to_image(game->mlx, img_path, \
				&game->size, &game->size);
				mlx_put_image_to_window(game->mlx, game->win, img, \
				(x * 48), (y * 48));
			}
		}
	}
	mlx_destroy_image(game->mlx, img);
	free (img_path);
}

void	put_background(void *mlx, void *window, char **map_mat, int size)
{
	int		x;
	int		y;
	void	*image;
	char	*str;

	y = 0;
	str = NULL;
	while (map_mat[y])
	{
		x = 0;
		while (map_mat[y][x])
		{
			str = ft_stringlcopy(str, "./assets/background/", 21);
			if (map_mat[y][x] == '1')
				str = ft_strcat(&str, "water/water1.xpm");
			else
				str = ft_strcat(&str, search_image(map_mat, x, y));
			image = mlx_xpm_file_to_image(mlx, str, &size, &size);
			mlx_put_image_to_window(mlx, window, image, (x * 48), (y * 48));
			x++;
			free (str);
			mlx_destroy_image(mlx, image);
		}
		y++;
	}
}

char	*search_entity(char **map_mat, int x, int y)
{
	char	*str;
	char	*name;

	name = NULL;
	name = ft_strcat(&name, "./assets/");
	str = search_image(map_mat, x, y);
	if (map_mat[y][x] == 'P')
		name = ft_strcat(&name, "dino/dino1_");
	else if (map_mat[y][x] == 'C')
		name = ft_strcat(&name, "chest/chest1_");
	else if (map_mat[y][x] == 'N')
		name = ft_strcat(&name, "enemy/enemy1_");
	else if (map_mat[y][x] == 'E')
		name = ft_strcat(&name, "exit/closed_");
	else
	{
		free (name);
		return (NULL);
	}
	str = ft_strcat(&name, str);
	return (str);
}

void	search_put(void *mlx, void *window, char **map_mat, void *image)
{
	int		x;
	int		y;
	char	*str;
	int		size;

	y = 1;
	size = 48;
	while (map_mat[y + 1])
	{
		x = 1;
		while (map_mat[y][x + 1])
		{
			str = search_entity(map_mat, x, y);
			if (str)
			{
				image = mlx_xpm_file_to_image(mlx, str, &size, &size);
				mlx_put_image_to_window(mlx, window, image, (x * 48), (y * 48));
				free (str);
				mlx_destroy_image(mlx, image);
			}
			x++;
		}
		y++;
	}
}

void	put_image(t_data *game)
{
	void	*image;

	image = NULL;
	search_put(game->mlx, game->win, game->map, image);
	game->frames = 40000;
	game->size = 48;
	game->water_img = ft_stringlcopy(game->water_img, \
	"./assets/background/water/water1.xpm", 37);
	get_char_pos(game, game->map);
	game->dino_img = ft_stringlcopy(game->dino_img, "./assets/dino/dino1_", 21);
	game->dino_img = ft_strcat(&game->dino_img, \
	search_image(game->map, game->dino_x, game->dino_y));
	game->enemy_img = '1';
}

/*valid.ber:
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111*/

/*image = mlx_xpm_file_to_image(mlx,"./assets/Square_5.xpm", &size, &size);
				mlx_put_image_to_window(mlx, window, image, i, j);*/

/*void	put_background(void *mlx, void *window)
{
	int		x;
	int		y;
	int		size;
	int		count;
	void	*image;

	y = 0;
	count = 0;
	size = 48;
	image = mlx_xpm_file_to_image(mlx,
			"./assets/Water.xpm", &size, &size);
	if (!image)
	{
		free(mlx);
		return ;
	}
	while (y <= 400)
	{
		x = 0;
		count = 0;
		while (count <= 13)
		{
			mlx_put_image_to_window(mlx, window, image, x, y);
			x += 48;
			count++;
		}
		y += 48;
	}
}*/
