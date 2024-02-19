#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	ssize_t		buffer;
	size_t		i;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = ft_calloc(BUFFER_SIZE, sizeof(*str));
		if (!str)
		{
			free (str);
			return (NULL);
		}
		buffer = read(fd, str, BUFFER_SIZE);
		if (buffer == -1)
		{
			printf("error");
			free (str);
			return (NULL);
		}
	}
	line = ft_calloc(ft_linelen(str), sizeof(*line));
	if (!line)
	{
		free (line);
		return (NULL);
	}
	i = 0;
	while (*str && *str != '\n')
		line[i++] = *str++;
	if (*str == '\n')
		line[i] = *str++;
	return (line);
}

/*int	main(void)
{
	int		fd;

	fd = open("get_next_line.txt", O_RDONLY);
	fd = STDIN_FILENO;
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}*/
