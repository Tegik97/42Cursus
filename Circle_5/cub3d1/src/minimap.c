#include "cub3d.h"

// void	draw_minimap(t_game *g)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < MINIMAP_H)
// 	{
// 		x = 0;
// 		while (x < MINIMAP_W)
// 		{
// 			if (g->map[y / (MINIMAP_H / MAP_H)][x / (MINIMAP_W / MAP_W)] == 1)
// 				my_mlx_pixel_put(&g->img, x, y, COLOR_MINI_WALL);
// 			else if (g->map[y / (MINIMAP_H / MAP_H)][x / (MINIMAP_W / MAP_W)] == 0)
// 				my_mlx_pixel_put(&g->img, x, y, COLOR_MINI_FLOOR);
// 			x++;
// 		}
// 		y++;
// 	}
// }
// void	draw_player_on_minimap(t_game *g)
// {
// 	int	size;
// 	int	player_x;
// 	int	player_y;

// 	size = 1;
// 	player_x = (int)(g->posX * (MINIMAP_W / (double)MAP_W));
// 	player_y = (int)(g->posY * (MINIMAP_H / (double)MAP_H));

// 	for (int y = -size; y <= size; y++)
// 	{
// 		for (int x = -size; x <= size; x++)
// 		{
// 			int px = player_x + x;
// 			int py = player_y + y;
// 			if (px >= 0 && px < MINIMAP_W && py >= 0 && py < MINIMAP_H)
// 				my_mlx_pixel_put(&g->img, px, py, COLOR_MINI_PLAYER);
// 		}
// 	}
// }

// void	draw_minimap_and_player(t_game *g)
// {
// 	int	start_x;
// 	int	start_y;

// 	start_x = WIN_W - MINIMAP_W - 10; // 10 pixel di margine
// 	start_y = WIN_H - MINIMAP_H - 10; // 10 pixel di margine
// 	draw_minimap(g);
// 	draw_player_on_minimap(g);
// 	mlx_put_image_to_window(g->mlx, g->win, g->img.img, start_x, start_y);
// }
