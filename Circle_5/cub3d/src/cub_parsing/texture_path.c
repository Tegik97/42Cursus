#include "texture_path.h"

static int	check_mat_status(char **textures)
{
	int		fd;
	size_t	i;

	if (!ft_strcmp(textures[0], "NO "))
		return (1);
	if (!ft_strcmp(textures[1], "SO "))
		return (2);
	if (!ft_strcmp(textures[2], "WE "))
		return (3);
	if (!ft_strcmp(textures[3], "EA "))
		return (4);
	if (!ft_strcmp(textures[4], "F "))
		return (5);
	if (!ft_strcmp(textures[5], "C "))
		return (6);
	i = 0;
	while (textures[i])
	{
		fd = open(textures[i++], O_RDONLY);
		if (fd == -1)
			return (i + 6);
		close (fd);
	}
	return (0);
}

static char	*get_path(char *line)
{
	char	*path;

	path = NULL;
	line += 2;
	while (*line == ' ' || *line == '\t')
		line++;
	path = ft_stringlcopy(path, line, ft_strlen(line));
	return (path);
}

static char	**get_texture_path(char **textures, int fd)
{
	char	*line;
	size_t	i;

	line = "a";
	while (line && check_mat_status(textures))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_freetrim(&line, "\t \n");
		i = 0;
		while (textures[i])
		{
			if (ft_strncmp(line, textures[i], ft_strlen(textures[i])) == 0)
			{
				free (textures[i]);
				textures[i] = get_path(line);
				break;
			}
			i++;
		}
		free (line);
	}
	return (textures);
}

static char	**texture_mat_init(char **textures)
{
	textures = ft_calloc(7, sizeof(char *));
	textures[0] = ft_stringlcopy(textures[0], "NO ", 3);
	textures[1] = ft_stringlcopy(textures[1], "SO ", 3);
	textures[2] = ft_stringlcopy(textures[2], "WE ", 3);
	textures[3] = ft_stringlcopy(textures[3], "EA ", 3);
	textures[4] = ft_stringlcopy(textures[4], "F ", 2);
	textures[5] = ft_stringlcopy(textures[5], "C ", 2);
	textures[6] = NULL;
	return (textures);
}

char	**textures_path(int fd)
{
	char	**textures;
	size_t	checkMat;
	
	textures = NULL;
	textures = texture_mat_init(textures);
	textures = get_texture_path(textures, fd);
	checkMat = check_mat_status(textures);
	if (checkMat)
	{
		missing_path_print(checkMat, textures);
		textures = free_mat(textures);
	}
	return (textures);
}

/*
*	Looks for each texture's path avoiding duplicates and checks for missing infos
*	Fills a matrix with each path in the following order:
*	North, South, West, East, Floor, Ceiling.
*	
*	Infos can be placed anywhere inside the .cub file but each path must
*	start on a new line and the beginning of the line must identify which path
*	follows (NO, SO, WE, EA, F, C), order doesn't matter
* 
*	RETURN VALUE
*	A matrix in which each row is a path or the path's identification if no path is found
*/