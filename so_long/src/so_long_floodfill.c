#include "so_long.h"

static int	check_space(size_t x, size_t y, char **mat, size_t *coll)
{
	if (mat[y][(x + 1)] != '1')
	{
		if (map_floodfill((x + 1), y, mat, coll))
			return (1);
	}
	if (mat[y][(x - 1)] != '1')
	{
		if (map_floodfill((x - 1), y, mat, coll))
			return (1);
	}
	if (mat[y + 1][(x)] != '1')
	{
		if (map_floodfill(x, (y + 1), mat, coll))
			return (1);
	}
	if (mat[y - 1][(x)] != '1')
	{
		if (map_floodfill(x, (y - 1), mat, coll))
			return (1);
	}
	return (0);
}

static size_t	*check_value(size_t x, size_t y, char **mat, size_t *coll)
{
	if (mat[y][x] == 'C')
	{
			coll[2]--;
			mat[y][x] = '1';
	}
	else if (mat[y][x] == 'E')
	{
		coll[3] = 1;
		mat[y][x] = '1';
	}
	else
		mat[y][x] = '1';
	return (coll);
}

int	map_floodfill(size_t x, size_t y, char **mat, size_t *coll)
{
	coll = check_value(x, y, mat, coll);
	if (coll[2] == 0 && coll[3] == 1)
		return (1);
	if (check_space(x, y, mat, coll))
		return (1);
	return (0);
}

int	floodfill_check(char *map)
{
	size_t	*char_pos;
	char	**mat;

	mat = map_to_mat(map);
	char_pos = NULL;
	char_pos = get_char_pos(mat);
	if (!map_floodfill(char_pos[0], char_pos[1], mat, char_pos))
	{
		if (char_pos[2] != 0)
			ft_putendl_fd("Error!\nCan't reach all collectables", 2);
		else
			ft_putendl_fd("Error!\nCan't reach exit", 2);
		free_all(mat, &char_pos);
		return (0);
	}
	free_all(mat, &char_pos);
	return (1);
}
