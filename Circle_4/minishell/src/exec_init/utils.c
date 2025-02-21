/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:42:18 by gvigano           #+#    #+#             */
/*   Updated: 2025/02/21 20:33:47 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	num_command(t_token *cmd)
{
	int		ncommand;

	if (!cmd || !cmd->value)
		return (0);
	ncommand = 0;
	while (cmd)
	{
		if (cmd->value[0] && (access(cmd->value[0], X_OK)
			&& !check_if_builtin(cmd->value[0])))
		{
			ft_putstr_fd(cmd->value[0], 2);
			ft_putstr_fd(": Command not found\n", 2);
			cmd->env->exit_stat = 1;
			return (0);
		}
		if (cmd->value && cmd->value[0])
			ncommand++;
		cmd = cmd->next;
	}
	return (ncommand);
}

int	*create_pid(int ncommand)
{
	int		*pids;

	pids = ft_calloc(ncommand, sizeof(int));
	if (!pids)
	{
		perror("pids malloc failed");
		exit(EXIT_FAILURE);
	}
	return (pids);
}

void	check_pid(t_token *data, int pid)
{
	if (pid < 0)
	{
		free_token(data);
		perror("Fork Error");
		exit(EXIT_FAILURE);
	}
}

void	free_process_memory(t_token *data, t_environ *env, t_free *fvar)
{
	int		i;

	i = 0;
	if (fvar->pipes)
	{
		while (fvar->pipes[i])
			free (fvar->pipes[i++]);
		free (fvar->pipes);
	}
	if (*(fvar->pids))
	{
		free (*(fvar->pids));
		fvar->pids = NULL;
	}
	if (fvar)
	{
		free (fvar);
		fvar = NULL;
	}
	if (env)
		free_environment(env, 1);
	if (data)
		free_token(data);
}


// void	free_process_memory(t_free *fvar, int **pipes, int **pids)
// {
// 	int		i;

// 	i = 0;
// 	if (pipes)
// 	{
// 		while (pipes[i])
// 			free (pipes[i++]);
// 		free (pipes);
// 	}
// 	if (*(pids))
// 		free (*(pids));
// 	if (fvar)
// 		free (fvar);
// 	unlink("heredoc_tmp.txt");
// }
