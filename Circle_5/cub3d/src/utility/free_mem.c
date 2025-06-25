#include "utility.h"

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
