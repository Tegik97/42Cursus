/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:26:15 by mchiaram          #+#    #+#             */
/*   Updated: 2024/06/21 11:26:16 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_window(t_data *g, int old_pos, char change)
{
	void	*img;
	char	*bg_path;

	bg_path = NULL;
	bg_path = ft_stringlcopy(bg_path, "./assets/background/", 21);
	img = mlx_xpm_file_to_image(g->mlx, g->dino_img, &g->size, &g->size);
	mlx_put_image_to_window(g->mlx, g->win, img, (g->dino_x * 48), \
	(g->dino_y * 48));
	mlx_destroy_image (g->mlx, img);
	if (change == 'x')
	{
		bg_path = ft_strcat(&bg_path, search_image(g->map, old_pos, g->dino_y));
		img = mlx_xpm_file_to_image(g->mlx, bg_path, &g->size, &g->size);
		mlx_put_image_to_window(g->mlx, g->win, img, (old_pos * 48), \
		(g->dino_y * 48));
	}
	else
	{
		bg_path = ft_strcat(&bg_path, search_image(g->map, g->dino_x, old_pos));
		img = mlx_xpm_file_to_image(g->mlx, bg_path, &g->size, &g->size);
		mlx_put_image_to_window(g->mlx, g->win, img, (g->dino_x * 48), \
		(old_pos * 48));
	}
	mlx_destroy_image (g->mlx, img);
	free(bg_path);
}

void	move_right(t_data *game)
{
	if (game->map[game->dino_y][game->dino_x + 1] != '1')
	{
		if (game->map[game->dino_y][game->dino_x + 1] == 'N' ||
			(game->map[game->dino_y][game->dino_x + 1] == 'E' &&
			game->exit == 1))
			destroy(game);
		else if (game->map[game->dino_y][game->dino_x + 1] == 'C')
		{
			chest_anim(game, game->dino_y, (game->dino_x + 1));
			move_right(game);
		}
		else if (game->map[game->dino_y][game->dino_x + 1] != 'E')
		{
			game->img_path = ft_substr(game->dino_img, 0, 20);
			free (game->dino_img);
			game->map[game->dino_y][game->dino_x] = '0';
			game->dino_x++;
			game->map[game->dino_y][game->dino_x] = 'P';
			game->dino_img = ft_strcat(&game->img_path, \
			search_image(game->map, game->dino_x, game->dino_y));
			update_window(game, (game->dino_x - 1), 'x');
			game->nmoves++;
		}
	}
}

void	move_left(t_data *game)
{
	if (game->map[game->dino_y][game->dino_x - 1] != '1')
	{
		if (game->map[game->dino_y][game->dino_x - 1] == 'N' ||
			(game->map[game->dino_y][game->dino_x - 1] == 'E'
			&& game->exit == 1))
			destroy(game);
		else if (game->map[game->dino_y][game->dino_x - 1] == 'C')
		{
			chest_anim(game, game->dino_y, (game->dino_x - 1));
			move_left(game);
		}
		else if (game->map[game->dino_y][game->dino_x - 1] != 'E')
		{
			game->img_path = ft_substr(game->dino_img, 0, 20);
			free (game->dino_img);
			game->map[game->dino_y][game->dino_x] = '0';
			game->dino_x--;
			game->map[game->dino_y][game->dino_x] = 'P';
			game->dino_img = ft_strcat(&game->img_path, \
			search_image(game->map, game->dino_x, game->dino_y));
			update_window(game, (game->dino_x + 1), 'x');
			game->nmoves++;
		}
	}
}

void	move_down(t_data *game)
{
	if (game->map[game->dino_y + 1][game->dino_x] != '1')
	{
		if (game->map[game->dino_y + 1][game->dino_x] == 'N' ||
			(game->map[game->dino_y + 1][game->dino_x] == 'E'
			&& game->exit == 1))
			destroy (game);
		else if (game->map[game->dino_y + 1][game->dino_x] == 'C')
		{
			chest_anim(game, (game->dino_y + 1), (game->dino_x));
			move_down(game);
		}
		else if (game->map[game->dino_y + 1][game->dino_x] != 'E')
		{
			game->img_path = ft_substr(game->dino_img, 0, 20);
			free (game->dino_img);
			game->map[game->dino_y][game->dino_x] = '0';
			game->dino_y++;
			game->map[game->dino_y][game->dino_x] = 'P';
			game->dino_img = ft_strcat(&game->img_path, \
			search_image(game->map, game->dino_x, game->dino_y));
			update_window(game, (game->dino_y - 1), 'y');
			game->nmoves++;
		}
	}
}

void	move_up(t_data *game)
{
	if (game->map[game->dino_y - 1][game->dino_x] != '1')
	{
		if (game->map[game->dino_y - 1][game->dino_x] == 'N' ||
			(game->map[game->dino_y - 1][game->dino_x] == 'E'
			&& game->exit == 1))
			destroy (game);
		else if (game->map[game->dino_y - 1][game->dino_x] == 'C')
		{
			chest_anim(game, (game->dino_y - 1), (game->dino_x));
			move_up(game);
		}
		else if (game->map[game->dino_y - 1][game->dino_x] != 'E')
		{
			game->img_path = ft_substr(game->dino_img, 0, 20);
			free (game->dino_img);
			game->map[game->dino_y][game->dino_x] = '0';
			game->dino_y--;
			game->map[game->dino_y][game->dino_x] = 'P';
			game->dino_img = ft_strcat(&game->img_path, \
			search_image(game->map, game->dino_x, game->dino_y));
			update_window(game, (game->dino_y + 1), 'y');
			game->nmoves++;
		}
	}
}
