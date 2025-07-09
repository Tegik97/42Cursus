#include "cub3d.h"

int	mouse_rotation(int x, int y, t_game *g)
{
	int		delta_x;
	double	angle;
	double	oldplane_x;
	double	olddir_x;
	(void)	y;

	delta_x = x - WIN_W / 2;
	if (delta_x != 0)
	{
		angle = delta_x * MOUSE_SENSITIVITY;
		olddir_x = g->dirX;
		g->dirX = g->dirX * cos(angle) - g->dirY * sin(angle);
		g->dirY = olddir_x * sin(angle) + g->dirY * cos(angle);
		oldplane_x = g->planeX;
		g->planeX = g->planeX * cos(angle) - g->planeY * sin(angle);
		g->planeY = oldplane_x * sin(angle) + g->planeY * cos(angle);
		mlx_mouse_move(g->mlx, g->win, WIN_W / 2, WIN_H / 2);
	}
	return (0);
}

void	mouse_controls(t_game *g)
{
	mlx_mouse_hide(g->mlx, g->win);
	mlx_mouse_move(g->mlx, g->win, WIN_W / 2, WIN_H / 2);
	mlx_hook(g->win, 6, 1L << 6, mouse_rotation, g);
}
