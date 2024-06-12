#include "so_long.h"

// static int	map_floodfill(size_t *char_pos, char *map, int e_found)
// {
	
// }

int	floodfill_check(char *map)
{
	size_t	*char_pos;
	size_t	i;
	char	**mat;

	mat = map_to_mat(map);
	char_pos = NULL;
	char_pos = get_char_pos(mat);
	// ft_printf("x: %d\ny: %d\nC: %d\n\n", char_pos[0], char_pos[1], char_pos[2]);
	// if (!map_floodfill(char_pos, mat, 0))
	free (char_pos);
	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
	return (1);
}
