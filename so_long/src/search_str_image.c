#include "so_long.h"

static char	*search_round(char **map_mat, int x, int y)
{
	if (map_mat[y][x - 1] == '1' && map_mat[y - 1][x] == '1')
	{
		if (map_mat[y + 1][x] == '1' && map_mat[y][x + 1] == '1')
			return ("round.xpm");
		else if (map_mat[y + 1][x] == '1')
			return ("round_left.xpm");
		else
			return ("top_left.xpm");
	}
	else if (map_mat[y][x - 1] == '1' && map_mat[y + 1][x] == '1')
	{
		if (map_mat[y][x + 1] == '1')
			return ("round_bot.xpm");
		else
			return ("bot_left.xpm");
	}
	else if (map_mat[y][x + 1] == '1' && map_mat[y - 1][x] == '1')
	{
		if (map_mat[y][x - 1] == '1')
			return ("round_top.xpm");
		else
			return ("top_right.xpm");
	}
	else
		return (NULL);
}

static char	*search_walls(char **map_mat, int x, int y)
{
	if (map_mat[y + 1][x] == '1' && map_mat[y][x + 1] == '1')
	{
		if (map_mat[y - 1][x] == '1')
			return ("round_right.xpm");
		else
			return ("bot_right.xpm");
	}
	else if (map_mat[y][x - 1] == '1')
	{
		if (map_mat[y][x + 1] == '1')
			return ("left_right.xpm");
		else
			return ("left.xpm");
	}
	else if (map_mat[y - 1][x] == '1' )
	{
		if (map_mat[y + 1][x] == '1')
			return ("top_bot.xpm");
		else
			return ("top.xpm");
	}
	else if (map_mat[y + 1][x] == '1')
		return ("bot.xpm");
	else
		return (NULL);
}

char	*search_image(char **map_mat, int x, int y)
{
	char	*str;

	str = search_round(map_mat, x, y);
	if (!str)
	{
		str = search_walls(map_mat, x, y);
		if (!str)
		{
			if (map_mat[y][x + 1] == '1')
				str = "right.xpm";
			else
				str = "center.xpm";
		}
	}
	return (str);
}
