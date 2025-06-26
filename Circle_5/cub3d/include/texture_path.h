#ifndef CUB_CONTENT_H
# define CUB_CONTENT_H
# include "libft.h"
# include "utility.h"

char	**textures_path(int fd);
void	missing_path_print(size_t errNo, char **textures);
int		check_color_gradient(char *texture);

#endif