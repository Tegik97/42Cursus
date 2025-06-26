#include "parsing.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**textures;
	char	**map;

	fd = check_input_file(argc, argv[1]);
	if (fd <= 0)
		return (1);
	textures = textures_path(fd);
	if (!textures)
	{
		get_next_line(-42);
		close (fd);
		return (1);
	}
	map = get_map(fd);
	textures = free_mat(textures);
	map = free_mat(map);
	close (fd);
	return (0);
}
