#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <mlx_int.h>
# include <mlx.h>

int		parsing(int nargs, char *map_name);
char	*get_map(char *map_name);
int		check_walls(char *map);
int		floodfill_check(char *map);
char	**map_to_mat(char *map);
size_t	*get_char_pos(char **mat);
int		map_floodfill(size_t x, size_t y, char **mat, size_t *coll);
void	free_all(char **mat, size_t **char_pos);

typedef struct s_data
{
	void	*mlx;
	void	*window;
}	t_data;

int		destroy(t_data *data);
int		keypress(int key, t_data *data);
void	put_image(void *mlx, void *window);
void	get_size_window(int *width, int *height);
char	*search_image(char **map_mat, int x, int y);


#endif