#include "cub3d.h"

static void	draw_square(t_game *g, int px, int py, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(g, &g->img, px + x, py + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *g, int offset)
{
	int		player_x;
	int		player_y;

	player_x = offset * (g->win_w / 100) + (g->win_w / 100) / 2 - (g->win_w / 250) / 2;
	player_y = offset * (g->win_w / 100) + (g->win_w / 100) / 2 - (g->win_w / 250) / 2;
	draw_square(g, player_x, player_y, (g->win_w / 250), COLOR_MINI_PLAYER);
}

static void	find_size_to_draw(t_game *g, int x, int y, int offset)
{
	int		px;
	int		py;
	int		win_x;
	int		win_y;

	while (x <= offset)
	{
		px = (int)g->posX + x;
		py = (int)g->posY + y;
		win_x = (x + offset) * (g->win_w / 100);
		win_y = (y + offset) * (g->win_w / 100);
		if (px >= 0 && px < (int)g->map_w && py >= 0 && py < (int)g->map_h)
		{
			if (g->map[py][px] == 1) 
				draw_square(g, win_x, win_y, (g->win_w / 100), COLOR_MINI_WALL);
		}
		x++;
	}
}

void	draw_minimap(t_game *g)
{
	int		x;
	int		y;
	
	int		offset;

	offset = MINI_SIZE;
	y = - offset;
	x = -offset;
	while (y <= offset)
	{
		find_size_to_draw(g, x, y, offset);
		y++;
	}
	draw_player(g, offset);
}

