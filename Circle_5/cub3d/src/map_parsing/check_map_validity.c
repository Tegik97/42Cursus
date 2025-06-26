#include "check_map_validity.h"

static int	check_walls(char **map)
{
	size_t	col;
	size_t	row;

	col = 0;
	while (map[1][col])
	{
		if (ft_strchr(" 1", map[1][col++]))
			return (0);
	}
	row = 1;
	col = 0;
	while (map[row + 1])
		row++;
	while (map[row][col])
	{
		if (ft_strchr(" 1", map[1][col++]))
			return (0);
	}
}

int	map_validity(char **map)
{
	check_walls(map);
}