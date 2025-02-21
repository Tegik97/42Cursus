/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:56:08 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/21 20:30:11 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_bin_bash(t_token *data, t_token *head)
{
	char	*bash_args[4];

	bash_args[0] = "bin/bash";
	bash_args[1] = data->value[0];
	bash_args[2] = NULL;
	if ((!ft_strcmp(data->value[0], "+")
			|| !ft_strcmp(data->value[0], "-"))
		|| execve("/bin/bash", bash_args, data->env->var) == -1)
	{
		ft_putstr_fd(data->value[0], 2);
		ft_putstr_fd(": Command not found\n", 2);
		free(*(head->fvar->fd));
		free_process_memory(head, head->env, head->fvar);
		exit(EXIT_FAILURE);
	}
	free(*(head->fvar->fd));
	free_process_memory(head, head->env, head->fvar);
	exit(EXIT_SUCCESS);
}

static void	child_process(t_token *data, int *fd, int i, t_token *head)
{
	fd = handle_redir(data, fd, i, head);
	if (check_if_builtin(data->value[0]))
	{
		if (!execute_builtin(data, data->value[0], fd[1]))
		{
			free(*(head->fvar->fd));
			free_process_memory(head, head->env, head->fvar);
			exit(EXIT_FAILURE);
		}
		free(*(head->fvar->fd));
		free_process_memory(head, head->env, head->fvar);
		exit(0);
	}
	if (fd[0] != STDIN_FILENO)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	if (fd[1] != STDOUT_FILENO)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	if (data->value[0]
		&& execve(data->value[0], data->value, data->env->var) == -1)
		execute_bin_bash(data, head);
	free(*(head->fvar->fd));
	free_process_memory(head, head->env, head->fvar);
	exit(EXIT_SUCCESS);
}

static void	parent_process(t_token *data, int *pid, int ncommand)
{
	int	status;
	int	i;

	i = 0;
	if (data->env->exit_stat == SIGKILL)
	{
		write(1, "\n", 1);
		return ;
	}
	while (i < ncommand)
	{
		waitpid(pid[i], &status, 0);
		if (WIFSIGNALED(status))
			data->env->exit_stat = WTERMSIG(status);
		else
			data->env->exit_stat = WEXITSTATUS(status);
		i++;
	}
	if (data->env->exit_stat == 3)
		ft_putstr_fd("Quit (core dumped)\n", 2);
}

/*				PIU' RECENTE				*/
// static void	handle_process(t_token *cmd, int **pipes, int *pids, int ncommand)
// {
// 	int		i;
// 	t_token	*cmd_head;
// 	int		*fd;

// 	cmd_head = cmd;
// 	fd = check_heredoc(cmd, &pids);
// 	if (!fd)
// 		return ;
// 	i = 0;
// 	cmd = cmd_head;
// 	while (i < ncommand)
// 	{
// 		fd = first_check_pipes(fd, ncommand, i, pipes);
// 		pids[i] = fork();
// 		check_pid(cmd, pids[i]);
// 		if (pids[i] == 0)
// 		{
// 			close_pipes_for_child(pipes, i, ncommand);
// 			child_process(cmd, fd, i);
// 		}
// 		close_pipes_for_parent(pipes, i, ncommand);
// 		cmd = cmd->next;
// 		i++;
// 	}
// 	free (fd);
// }


static void	handle_process(t_token *cmd, int **pipes, int *pids, int ncommand)
{
	int		i;
	t_token	*cmd_head;
	int		*fd;

	cmd_head = cmd;
	fd = check_heredoc(cmd);
	if (!fd)
		return ;
	cmd->fvar->fd = &fd;
	i = 0;
	cmd = cmd_head;
	while (i < ncommand)
	{
		fd = first_check_pipes(fd, ncommand, i, pipes);
		pids[i] = fork();
		check_pid(cmd, pids[i]);
		if (pids[i] == 0)
		{
			close_pipes_for_child(pipes, i, ncommand);
			child_process(cmd, fd, i, cmd_head);
		}
		close_pipes_for_parent(pipes, i, ncommand);
		cmd = cmd->next;
		i++;
	}
	free (fd);
}

// static void	handle_process(t_token *cmd,
// int **pipes, int *pids, int ncommand)
// {
// 	int		i;
// 	t_token	*cmd_head;
// 	int		*fd;

// 	i = 0;
// 	cmd_head = cmd;
// 	fd = ft_calloc(3, sizeof(int));
// 	while (cmd && i < ncommand)
// 	{
// 		if (cmd->rd && cmd->rd->type == T_DELIM)
// 		{
// 			if (!here_doc(cmd) || cmd->env->exit_stat == SIGKILL)
// 			{
// 				free (fd);
// 				return ;
// 			}
// 			fd[2] = i;
// 		}
// 		i++;
// 		cmd = cmd->next;
// 	}
// 	i = 0;
// 	cmd = cmd_head;
// 	while (i < ncommand)
// 	{
// 		fd = first_check_pipes(fd, ncommand, i, pipes);
// 		pids[i] = fork();
// 		check_pid(cmd, pids[i]);
// 		if (pids[i] == 0)
// 		{
// 			close_pipes_for_child(pipes, i, ncommand);
// 			child_process(cmd, fd, i);
// 		}
// 		close_pipes_for_parent(pipes, i, ncommand);
// 		cmd = cmd->next;
// 		i++;
// 	}
// 	free (fd);
// }



// static t_free	*init_fvar()
// {
// 	t_free	*fvar;

// 	fvar = malloc(sizeof(t_free));
// 	fvar->fd = NULL;
// 	fvar->pids = NULL;
// 	fvar->pipes = NULL;
// 	return (fvar);
// }

void	do_command(t_token *data)
{
	int			**pipes;
	int			*pids;
	t_token		*cmd;
	t_free		*fvar;

	pipes = NULL;
	pids = NULL;
	cmd = data;
	data->env->exit_stat = 0;
	data->ncommand = num_command(cmd);
	if (!data->ncommand && !data->rd)
		return ;
	if (data->ncommand == 1 && check_if_builtin(data->value[0]))
	{
		execute_builtin(data, data->value[0], 1);
		return ;
	}
	pipes = handle_pipes(data, data->ncommand);
	pids = create_pid(data->ncommand);
	fvar = malloc(sizeof(t_free));
	fvar->pids = &pids;
	fvar->pipes = pipes;
	fvar->fd = NULL;
	data->fvar = fvar;
	cmd = data;
	handle_process(cmd, pipes, pids, cmd->ncommand);
	parent_process(data, pids, data->ncommand);
	free_process_memory(NULL, NULL, data->fvar);
	unlink("heredoc_tmp.txt");
}

// void	do_command(t_token *data)
// {
// 	int			**pipes;
// 	int			ncommand;
// 	t_token		*cmd;
// 	int			*pids;

// 	pipes = NULL;
// 	pids = NULL;
// 	cmd = data;
// 	data->env->exit_stat = 0;
// 	ncommand = num_command(cmd);
// 	if (!ncommand && !data->rd)
// 		return ;
// 	if (ncommand == 1 && check_if_builtin(data->value[0]))
// 	{
// 		execute_builtin(data, data->value[0], 1);
// 		return ;
// 	}
// 	pipes = handle_pipes(data, ncommand);
// 	cmd = data;
// 	pids = create_pid(ncommand);
// 	handle_process(cmd, pipes, pids, ncommand);
// 	parent_process(data, pids, ncommand);
// 	free_process_memory(pipes, &pids);
// }
