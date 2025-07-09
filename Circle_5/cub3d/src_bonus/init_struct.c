#include "cub3d.h"

void	init_struct_keys(t_game *g)
{
	t_keys	key;

	key.a = 0;
	key.d = 0;
	key.left = 0;
	key.right = 0;
	key.s = 0;
	key.w = 0;
	g->keys = key;
}

static void	init_game_direction(t_game *g, t_texture *txt)
{
	g->dirX = 0;
	g->dirY = 0;
	g->planeX = 0;
	g->planeY = 0;
	if (!ft_strcmp(txt->direction, "N"))
	{
		g->dirY = -1;
		g->planeX = 0.66;
	}
	else if (!ft_strcmp(txt->direction, "S"))
	{
		g->dirY = 1;
		g->planeX = -0.66;
	}
	else if (!ft_strcmp(txt->direction, "W"))
	{
		g->dirX = -1;
		g->planeY = -0.66;
	}
	else if (!ft_strcmp(txt->direction, "E"))
	{
		g->dirX = 1;
		g->planeY = 0.66;
	}
}

void	init_struct_game(t_game *g, t_texture *txt)
{
	if (WIN_W > 1920)
		g->win_w = 1920;
	else
		g->win_w = WIN_W;
	if (WIN_H > 1080)
		g->win_h = 1080;
	else
		g->win_h = WIN_H;
	g->posX = txt->pos_x;
	g->posY = txt->pos_y;
	init_game_direction(g, txt);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->win_w, g->win_h, "cub3d - base raycasting");
	g->img.img = mlx_new_image(g->mlx, g->win_w, g->win_h);
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bpp, &g->img.line_len, &g->img.endian);
	init_struct_keys(g);
	g->use_ceil_text = True;
	g->use_floor_text = True;
	init_texture(g, txt);
	g->current_text_id = 0;
	g->txt = txt;
}
