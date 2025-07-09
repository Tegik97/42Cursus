#include "utility.h"

void	free_struct(t_texture *txt, t_game *g)
{
	size_t	i;

	i = 0;
	if (txt->texturePath)
	{
		while (txt->texturePath[i])
			free(txt->texturePath[i++]);
		free (txt->texturePath);
	}
	if (g->map)
	{
		i = 0;
		while (g->map[i])
			free (g->map[i++]);
		free (g->map);
	}
	if (txt->direction)
		free (txt->direction);
	if (txt)
		free (txt);
	if (g)
		free (g);
}

char	**free_mat(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free (mat[i++]);
	free (mat);
	mat = NULL;
	return (mat);
}
