#include "parsing.h"

static void	search_char_pos(char **map, t_texture *txt, t_game *g)
{
	size_t	i;
	size_t	j;

	g->map = ft_calloc((g->map_h + 1), sizeof(int *));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NESW", map[i][j]))
			{
				txt->pos_x = j;
				txt->pos_y = i;
				txt->direction = ft_charcpy(&txt->direction, map[i][j]);
				map[i][j] = '0';
			}
			j++;
		}
		g->map[i] = ft_calloc((g->map_w + 1), sizeof(int));
		i++;
	}
}

static void	copy_to_struct(char **textures, char **map, t_texture *txt, t_game *g)
{
	int	i;
	int	j;

	search_char_pos(map, txt, g);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
				g->map[i][j] = 0;
			else
				g->map[i][j] = map[i][j] - '0';
		}
		while (j < (int)g->map_w)
			g->map[i][j++] = 0;
	}
	txt->texturePath = ft_calloc(7, sizeof(char *));
	i = 0;
	while (textures[i])
	{
		txt->texturePath[i] = ft_strcat(&txt->texturePath[i], textures[i]);
		i++;
	}
}

t_texture	*init_struct(t_texture *txt, t_game *g)
{
	size_t	i;

	txt = NULL;
	txt = malloc(1 * sizeof(t_texture));
	txt->texturePath = NULL;
	txt->direction = NULL;
	g->map_h = 0;
	g->map_w = 0;
	i = 0;
	while (i < 6)
		g->texture[i++].imge = NULL;
	return (txt);
}

int	parsing_start(int argc, char **argv, t_texture *txt, t_game *g)
{
	int		fd;
	char	**textures;
	char	**map;

	fd = check_input_file(argc, argv[1]);
	if (fd <= 0)
		return (0);
	textures = textures_path(fd);
	if (!textures)
	{
		get_next_line(-42);
		close (fd);
		return (0);
	}
	map = get_map(fd, g);
	if (!map)
	{
		textures = free_mat(textures);
		return (0);
	}
	copy_to_struct(textures, map, txt, g);
	textures = free_mat(textures);
	map = free_mat(map);
	close (fd);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	t_texture	*txt;

// 	txt = init_struct(txt);
// 	if (!parsing_start(argc, argv, txt))
// 	{
// 		free_struct(txt);
// 		return (1);
// 	}
// 	free_struct(txt);
// 	return (0);
// }

// static void	print_struct(t_texture *txt, t_game *g)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (txt->texturePath[i])
// 		ft_printf("%s\n", txt->texturePath[i++]);
// 	i = 0;
// 	ft_printf("\n");
// 	while (i < g->map_h)
// 	{
// 		j = 0;
// 		while (j < g->map_w)
// 			ft_printf("%d", g->map[i][j++]);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	ft_printf("\ndir: %s\npos_x: %d\npos_y: %d\nmap_w: %d\nmap_h: %d\n", txt->direction, txt->pos_x, txt->pos_y, g->map_w, g->map_h);
// }