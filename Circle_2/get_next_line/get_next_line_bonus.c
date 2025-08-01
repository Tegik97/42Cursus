/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:55:35 by mchiaram          #+#    #+#             */
/*   Updated: 2024/03/21 14:08:57 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif
#ifndef FD_MAX
# define FD_MAX 2048
#endif

static char	*ft_trimstr(char *str)
{
	size_t	i;
	size_t	j;
	char	*temp_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	temp_str = ft_calloc((ft_strlen(str) - i + 1), sizeof(*temp_str));
	if (!temp_str)
		return (NULL);
	i++;
	while (str[i])
		temp_str[j++] = str[i++];
	free (str);
	return (temp_str);
}

static char	*ft_get_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(*line));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_find_line(int fd, char *str)
{
	char	*temp_line;
	ssize_t	buffer;

	buffer = 1;
	temp_line = ft_calloc((BUFFER_SIZE + 1), sizeof(*temp_line));
	if (!temp_line)
		return (NULL);
	while (!ft_strchr(str, '\n') && buffer > 0)
	{
		buffer = read(fd, temp_line, BUFFER_SIZE);
		if (buffer == -1)
		{
			free (temp_line);
			free (str);
			return (NULL);
		}
		else if (buffer == 0)
			break ;
		temp_line[buffer] = '\0';
		str = ft_freejoin(str, temp_line);
		if (!str)
			return (NULL);
	}
	free (temp_line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[FD_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = ft_find_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_trimstr(str[fd]);
	if (!line || !*line)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int	fd2;
// 	int	fd3;
// 	int	i;

// 	i = 0;
// 	fd = open("get_next_line.txt", O_RDONLY);
// 	fd2 = open("get_next_line2.txt", O_RDONLY);
// 	fd3 = open("get_next_line3.txt", O_RDONLY);
// 	while (i < 4)
// 	{
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd2));
// 		printf("%s", get_next_line(fd3));
// 		i++;
// 	}
// 	close (fd);
// 	return (0);
// }