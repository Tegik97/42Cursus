#include "cub3d.h"

void	draw_floor(t_game *g, t_ray *r, int x, int y)
{
	int		color;
	double	weight;
	double	floor_x;
	double	floor_y;
	double 	camera_dist;

	camera_dist = WIN_H / (2.0 * y - WIN_H); // distanza dal giocatore all'y corrente (PER y > WIN_H / 2)
	find_floor_position_on_wallbase(r);
	weight = camera_dist / r->walldist; //fattore di interpolazione per ottenere la posizione corretta tra player e muro
	floor_x = weight * r->floor_wall_x + (1.0 - weight) * g->posX;
	floor_y = weight * r->floor_wall_y + (1.0 - weight) * g->posY;
	r->floor_tex_x = (int)(floor_x * g->texture[FLOOR_ID].width)
		% g->texture[FLOOR_ID].width;
	if (r->floor_tex_x < 0)
		r->floor_tex_x += g->texture[FLOOR_ID].width;
	r->floor_tex_y = (int)(floor_y * g->texture[FLOOR_ID].height)
		% g->texture[FLOOR_ID].height;
	if (r->floor_tex_y < 0)
		r->floor_tex_y += g->texture[FLOOR_ID].height;
	color = *(int *)(g->texture[FLOOR_ID].addr
		+ (r->floor_tex_y * g->texture[FLOOR_ID].line_len
		+ r->floor_tex_x * (g->texture[FLOOR_ID].bpp / 8)));
	my_mlx_pixel_put(&g->img, x, y, color);
}

void	draw_ceil(t_game *g, t_ray *r, int x, int y)
{
	int		color;
	double	floor_x;
	double	floor_y;
	double	weight;
	double	camera_dist;

	camera_dist = WIN_H / (WIN_H - 2.0 * y); // per y < WIN_H / 2
	find_floor_position_on_wallbase(r); // per aggiornare floor_wall_x/y
	weight = camera_dist / r->walldist;
	floor_x = weight * r->floor_wall_x + (1.0 - weight) * g->posX;
	floor_y = weight * r->floor_wall_y + (1.0 - weight) * g->posY;
	r->ceil_tex_x = (int)(floor_x * g->texture[CEIL_ID].width)
		% g->texture[CEIL_ID].width;
	if (r->ceil_tex_x < 0)
		r->ceil_tex_x += g->texture[CEIL_ID].width;
	r->ceil_tex_y = (int)(floor_y * g->texture[CEIL_ID].height)
		% g->texture[CEIL_ID].height;
	if (r->ceil_tex_y < 0)
		r->ceil_tex_y += g->texture[CEIL_ID].height;
	color = *(int *)(g->texture[CEIL_ID].addr
		+ (r->ceil_tex_y * g->texture[CEIL_ID].line_len
		+ r->ceil_tex_x * (g->texture[CEIL_ID].bpp / 8)));
	my_mlx_pixel_put(&g->img, x, y, color);
}

void	draw_map(t_game *g, t_ray *r, int x)
{
	int		y;
	int		color;
	int		text_y;
	double	step;
	double	text_pos;

	step = 1.0 * g->texture[g->current_text_id].height / r->height; ////calcolo incremento verticale (Scaling)
	text_pos = (r->draw_start - WIN_H / 2 + r->height / 2) * step;
	y = 0;
	while (y < r->draw_start)
		draw_ceil(g, r, x, y++);
	while (y <= r->draw_end)
	{
		text_y = (int)text_pos;
		if (text_y < 0)
			text_y = 0;
		if (text_y >= g->texture[g->current_text_id].height)
			text_y= g->texture[g->current_text_id].height - 1;
		color = *(int *)(g->texture[g->current_text_id].addr
			+ (text_y * g->texture[g->current_text_id].line_len
			+ r->text_x * (g->texture[g->current_text_id].bpp / 8)));
		my_mlx_pixel_put(&g->img, x, y++, color);
		text_pos += step;
	}
	while (y < WIN_H)
		draw_floor(g, r, x, y++);
}
