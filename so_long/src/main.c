#include "so_long.h"

int	main(int argc, char *argv[])
{
	// t_data	data;
	// void	*img;
	// int		img_size;
	if (!parsing(argc, argv[1]))
		return (1);
	
	// data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (1);
	// data.window = mlx_new_window(data.mlx, 1920, 1080, ":D");
	// mlx_loop_hook(data.mlx, render_next_frame(),);
	// img_size = 48;
	// img = mlx_xpm_file_to_image(data.mlx, "./assets/background/water/water1.xpm", &img_size, &img_size);
	// mlx_put_image_to_window(data.mlx, data.window, img, 0, 0);
	// // img = mlx_xpm_file_to_image(data.mlx, "./assets/char/dino1.xpm", &img_size, &img_size);
	// // mlx_put_image_to_window(data.mlx, data.window, img, 0, 0);
	// mlx_loop(data.mlx);
	return (0);
}
