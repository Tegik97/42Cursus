/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_frame_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:26:13 by mchiaram          #+#    #+#             */
/*   Updated: 2024/06/21 11:26:14 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chest_anim(t_data *game, int y, int x)
{
	char	*img_path;
	void	*img;

	game->is_updating = 1;
	img_path = NULL;
	img_path = ft_stringlcopy(img_path, "./assets/chest/chest1_", 23);
	img_path = ft_strcat(&img_path, search_image(game->map, x, y));
	while (img_path[20] < '5')
	{
		game->frames = 100000;
		img_path[20]++;
		img = mlx_xpm_file_to_image(game->mlx, img_path, \
		&game->size, &game->size);
		mlx_put_image_to_window(game->mlx, game->win, img, (x * 48), (y * 48));
		mlx_destroy_image(game->mlx, img);
		while (game->frames++ < 200000)
			ft_printf("\b");
	}
	game->map[y][x] = 'c';
	free (img_path);
	if (--game->coll == 0)
		game->exit = 1;
	while (game->frames-- > 40000)
		ft_printf("\b");
	game->is_updating = 0;
}

static void	enemy_update(t_data *g)
{
	int		x;
	int		y;
	char	*str;
	void	*i;

	if (g->enemy_img == '3')
		g->enemy_img = '0';
	g->enemy_img++;
	y = 0;
	while (g->map[++y])
	{
		x = 0;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == 'N')
			{
				str = search_entity(g->map, x, y);
				str[20] = g->enemy_img;
				i = mlx_xpm_file_to_image(g->mlx, str, &g->size, &g->size);
				mlx_put_image_to_window(g->mlx, g->win, i, (x * 48), (y * 48));
				free (str);
				mlx_destroy_image(g->mlx, i);
			}
		}
	}
}

static void	dino_update(t_data *game)
{
	void	*image;

	if (game->dino_img[18] == '4')
		game->dino_img[18] = '0';
	game->dino_img[18]++;
	image = mlx_xpm_file_to_image(game->mlx, game->dino_img, \
	&game->size, &game->size);
	mlx_put_image_to_window(game->mlx, game->win, image, \
	(game->dino_x * 48), (game->dino_y * 48));
	mlx_destroy_image(game->mlx, image);
}

static void	water_update(t_data *game)
{
	int		x;
	int		y;
	void	*image;

	if (game->water_img[31] == '4')
		game->water_img[31] = '0';
	game->water_img[31]++;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				image = mlx_xpm_file_to_image(game->mlx, \
				game->water_img, &game->size, &game->size);
				mlx_put_image_to_window(game->mlx, game->win, image, \
				(x * 48), (y * 48));
				mlx_destroy_image(game->mlx, image);
			}
			x++;
		}
		y++;
	}
}

int	change_frame(t_data *game)
{
	if (game->is_updating == 0)
	{
		game->is_updating = 1;
		if (game->frames == 0)
			water_update(game);
		if (game->frames == 0 || game->frames == 20000)
		{
			dino_update(game);
			enemy_update(game);
		}
		if (game->frames == 0)
			game->frames = 40000;
		game->frames--;
		game->is_updating = 0;
	}
	return (1);
}
