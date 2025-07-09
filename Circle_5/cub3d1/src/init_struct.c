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

