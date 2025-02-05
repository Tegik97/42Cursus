/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/04 14:14:04 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process_hd(char *limiter, int fd0, int fd1, t_token *data)
{
	char	*line;

	close(fd0);
	while ((line = get_next_line(STDIN_FILENO)) != NULL)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(fd1, line, ft_strlen(line));
		free(line);
	}
	close(fd1);
	free_token(data);
	exit(EXIT_SUCCESS);
}

static int	here_doc(t_token *data)
{
	int		pid_r;
	int		fd[2];
	char	*limiter;

	limiter = data->rd->name;
	handle_pipe(data, fd);
	pid_r = fork();
	check_pid(data, pid_r);
	if (pid_r == 0)
		child_process_hd(limiter, fd[0], fd[1], data);
	else
	{
		close(fd[1]);
		wait(NULL);
	}
	return (fd[0]);
}

static int	handle_input_redir(t_token *data)
{
	int	tmpin;

	tmpin = 0;
	if (data->rd && data->rd->type == T_RED_IN)
	{
		tmpin = open(data->rd->name, O_RDONLY);
		if (tmpin < 0)
		{
			free_token(data);
			perror("Error opening input file");
			exit(EXIT_FAILURE);
		}
	}
	else if (data->rd && data->rd->type == T_DELIM)
	{ 
		if (data->rd->name)
			tmpin = here_doc(data);
		else
		{
			free_token(data);
			perror("Error delimiter here_doc");
			exit(EXIT_FAILURE);
		}
	}
	else
		tmpin = dup(STDIN_FILENO);
	return (tmpin);
}

static int	handle_output_redir(t_token *data)
{
	int	tmpout;

	tmpout = 0;
	if (data->rd && data->rd->type == T_RED_OUT)
	{
		tmpout = open(data->rd->name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (tmpout < 0)
		{
			free_token(data);
			perror("Error opening output file");
			exit(EXIT_FAILURE);
		}
	}
	else if (data->rd && data->rd->type == T_RED_APPEN)
	{
		tmpout = open(data->rd->name, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (tmpout < 0)
		{
			free_token(data);
			perror("Error opening output file");
			exit(EXIT_FAILURE);
		}
	}
	else
		tmpout = dup(STDOUT_FILENO);
	return (tmpout);
}

void	handle_redir(t_token *data)
{
	int		tmpin;
	int		tmpout;

	tmpin = handle_input_redir(data);
	if (tmpin != STDIN_FILENO)
	{
		dup2(tmpin, STDIN_FILENO);
		close(tmpin);
	}
	tmpout = handle_output_redir(data);
	if (tmpout != STDIN_FILENO)
	{
		dup2(tmpout, STDOUT_FILENO);
		close(tmpout);
	}
}
