#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (!parsing(argc, argv[1]))
		return (1);
	game_init(argv[1]);
	return (0);
}
