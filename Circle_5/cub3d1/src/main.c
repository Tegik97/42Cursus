#include "cub3d.h"
#include "parsing.h"

int	draw_walls(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		cast_ray(g, x);
		x++;
	}
	return (0);
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
	size_t	i;

	g->posX = txt->pos_x;
	g->posY = txt->pos_y;
	init_game_direction(g, txt);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3d - base raycasting");
	g->img.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bpp, &g->img.line_len, &g->img.endian);
	init_struct_keys(g);
	i = 0;
	while (txt->texturePath[i])
	{
		g->texture[i] = load_texture(g->mlx, txt->texturePath[i]);
		i++;
	}
	g->current_text_id = 0;
}

int main (int argc, char **argv)
{
	t_game 		*g;
	t_texture	*txt;

	g = malloc(1 * sizeof(t_game));
	g->map = NULL;
	txt = NULL;
	txt = init_struct(txt, g);
	if (!parsing_start(argc, argv, txt, g))
	{
		free_struct(txt, g);
		return (1);
	}
	if (argc >= 3 && !ft_strcmp(argv[2], "--test"))
		return (0);
	init_struct_game(g, txt);
	mouse_controls(g);
	mlx_loop_hook(g->mlx, render, g);
	mlx_hook(g->win, 2, 1L<<0, key_press, g);
	mlx_hook(g->win, 3, 1L<<1, key_release, g);
	mlx_hook(g->win, 17, 0, close_window, g);
	mlx_loop(g->mlx);
	//free_map(&g);
	free_struct(txt, g);
	return (0);
}
