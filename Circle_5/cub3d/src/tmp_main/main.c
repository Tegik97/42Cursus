#include "parsing.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**textures;

	fd = check_input_file(argc, argv[1]);
	if (fd <= 0)
		return (1);
	textures = textures_path(fd);
	if (!textures)
		return (1);
	textures = free_mat(textures);
	close (fd);
	return (0);
}
