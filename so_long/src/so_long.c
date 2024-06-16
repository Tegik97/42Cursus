#include "so_long.h"

void	get_size_window(int *width, int *height)
{
	int		x;
	int		y;
	char	*file_map;
	char	**map_mat;

	x = 0;
	y = 0;
	*width = 0;
	*height = 0;
	file_map = get_map("./maps/map1.ber");
	map_mat = map_to_mat(file_map);
	while (map_mat[0][x])
		x++;
	*width = x * 48;
	while (map_mat[y])
		y++;
	*height = y * 48;
	if (*width > 1800)
		*width = 1800;
	if (*height > 900)
		*height = 900; 
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
	return (0);
}

int	keypress(int key, t_data *data)
{
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}

// 65307 è l'escape key

// int	keypress(int key, t_data *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", key);
// 	return (0);
// }

// int	destroy(t_data *data)
// {
// 	mlx_destroy_window(data->mlx, data->window);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	exit(0);
// 	return (0);
// }