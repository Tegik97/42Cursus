#include "so_long.h"

static void	put_background(void * mlx, void *window, char **map_mat, int size)
{
	int		x;
	int		y;
	void	*image;
	char	*str;

	y = 0;
	str = NULL;
	while (map_mat[y])
	{
		x = 0;
		while (map_mat[y][x])
		{
			str = ft_stringlcopy(str, "./assets/background/", 21);
			if (map_mat[y][x] == '1')
				str = ft_strcat(&str, "water1.xpm");
			else
				str = ft_strcat(&str, search_image(map_mat, x, y));
			image = mlx_xpm_file_to_image(mlx, str, &size, &size);
			mlx_put_image_to_window(mlx, window, image, (x * 48), (y * 48));
			x++;
		}
		y++;
	}
}

static char	*search_entity(char **map_mat, int x, int y)
{
	char	*str;
	char	*name;

	name = NULL;
	name = ft_strcat(&name, "./assets/");
	str = search_image(map_mat, x, y);
	if (map_mat[y][x] == 'P')
		name = ft_strcat(&name, "dino/dino1_");
	else if (map_mat[y][x] == 'C')
		name = ft_strcat(&name, "chest/chest1_");
	else if (map_mat[y][x] == 'N')
		name = ft_strcat(&name, "enemy/enemy1_");
	else if (map_mat[y][x] == 'E')
		name = ft_strcat(&name, "exit_");
	else 
		return (NULL);
	str = ft_strcat(&name, str);
	return (str);	
}

static char	*search_put(void *mlx, void *window, char **map_mat, void *image)
{
	int		x;
	int		y;
	char	*str;
	int		size;

	y = 1;
	size = 48;
	put_background(mlx, window, map_mat, size);
	while (map_mat[y + 1])
	{
		x = 1;
		while (map_mat[y][x + 1])
		{
			str = search_entity(map_mat, x, y);
			if (str)
			{
				image = mlx_xpm_file_to_image(mlx, str, &size, &size);
				mlx_put_image_to_window(mlx, window, image, (x * 48), (y * 48));
			}
			x++;
		}
		y++;
	}
	return (str);
}

void	put_image(void *mlx, void *window)
{
	char	*file_map;
	char	**map_mat;
	void	*image;

	image = NULL;
	file_map = get_map("./maps/map1.ber");
	map_mat = map_to_mat(file_map);
	search_put(mlx, window, map_mat, image);
}

/*valid.ber:
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111*/

/*image = mlx_xpm_file_to_image(mlx,"./assets/Square_5.xpm", &size, &size);
				mlx_put_image_to_window(mlx, window, image, i, j);*/

/*void	put_background(void *mlx, void *window)
{
	int		x;
	int		y;
	int		size;
	int		count;
	void	*image;

	y = 0;
	count = 0;
	size = 48;
	image = mlx_xpm_file_to_image(mlx,
			"./assets/Water.xpm", &size, &size);
	if (!image)
	{
		free(mlx);
		return ;
	}
	while (y <= 400)
	{
		x = 0;
		count = 0;
		while (count <= 13)
		{
			mlx_put_image_to_window(mlx, window, image, x, y);
			x += 48;
			count++;
		}
		y += 48;
	}
}*/
