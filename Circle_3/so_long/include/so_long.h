/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:29:10 by mchiaram          #+#    #+#             */
/*   Updated: 2024/06/21 11:31:30 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <mlx_int.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

int		parsing(int nargs, char *map_name);
char	*get_map(char *map_name);
int		check_walls(char *map);
int		floodfill_check(char *map);
char	**map_to_mat(char *map);

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	int		size;
	char	*water_img;
	char	*dino_img;
	char	*chest_img;
	char	enemy_img;
	int		frames;
	int		coll;
	int		exit;
	int		dino_x;
	int		dino_y;
	int		nmoves;
	int		is_updating;
	char	*img_path;
	void	**num_img;
}	t_data;

int		map_floodfill(size_t x, size_t y, char **mat, t_data *game);
void	get_char_pos(t_data *data, char **mat);
void	free_all(t_data *game);
int		destroy(t_data *data);
int		keypress(int key, t_data *data);
void	put_image(t_data *game);
void	get_size_window(t_data *game, char *map_name);
char	*search_image(char **map_mat, int x, int y);
void	search_put(void *mlx, void *window, char **map_mat, void *image);
int		game_init(char *map_name);
void	put_background(void *mlx, void *window, char **map_mat, int size);
int		change_frame(t_data *game);
char	*search_entity(char **map_mat, int x, int y);
void	chest_anim(t_data *game, int y, int x);
void	move_right(t_data *game);
void	move_left(t_data *game);
void	move_down(t_data *game);
void	move_up(t_data *game);
void	update_window(t_data *g, int old_pos, char change);
void	exit_ready(t_data *game);
void	put_num_moves(t_data *game, int x, int y);
void	init_num_image(t_data *game);

/* CHANGES */
// -get_size_window ritorna la mat;

#endif