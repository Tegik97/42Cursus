/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:26:22 by mchiaram          #+#    #+#             */
/*   Updated: 2024/06/21 11:26:23 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_num_image(t_data *game)
{
	game->num_img = (void **)malloc (sizeof(void *) * 10);
	game->num_img[0] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_0.xpm", &game->size, &game->size);
	game->num_img[1] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_1.xpm", &game->size, &game->size);
	game->num_img[2] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_2.xpm", &game->size, &game->size);
	game->num_img[3] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_3.xpm", &game->size, &game->size);
	game->num_img[4] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_4.xpm", &game->size, &game->size);
	game->num_img[5] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_5.xpm", &game->size, &game->size);
	game->num_img[6] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_6.xpm", &game->size, &game->size);
	game->num_img[7] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_7.xpm", &game->size, &game->size);
	game->num_img[8] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_8.xpm", &game->size, &game->size);
	game->num_img[9] = mlx_xpm_file_to_image(game->mlx, \
	"./assets/moves/move_9.xpm", &game->size, &game->size);
}

void	put_num_moves(t_data *game, int x, int y)
{
	int	count;
	int	tmp_moves;
	int	digit;
	int	digits[10];

	count = 0;
	tmp_moves = game->nmoves;
	if (game->nmoves == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->num_img[0], x, y);
	while (tmp_moves > 0 && count < 10)
	{
		digit = tmp_moves % 10;
		tmp_moves /= 10;
		digits[count++] = digit;
	}
	while ((count - 1) >= 0)
	{
		if (digits[count - 1] < 0 || digits[count - 1] >= 10 || \
			game->num_img[digits[count - 1]] == NULL)
			break ;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->num_img[digits[count - 1]], x, y);
		x += 24;
		count--;
	}
}
