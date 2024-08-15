/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:41:44 by mchiaram          #+#    #+#             */
/*   Updated: 2024/06/29 16:53:21 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received = 0;

static void	sig_handler(int signum)
{
	static int	i = 0;

	g_received = 1;
	if (i++ == 7)
	{
		write(1, "Received\n", 10);
		i = 0;
	}
	(void)signum;
}

static int	send_char(int s_pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
		{
			if (kill(s_pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
				return (0);
		}
		i--;
		while (g_received == 0)
			;
		g_received = 0;
	}
	return (1);
}

static void	send_str(int s_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!send_char(s_pid, str[i++]))
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
	}
}

static void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
	{
		ft_putendl_fd("Error\nUsage: ./client <Server PID> <string>", 2);
		exit(1);
	}
	if (!argv[2][0])
	{
		ft_putendl_fd("Error\nEmpty string", 2);
		exit(1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_putendl_fd("Error\nInvalid PID", 2);
			exit(1);
		}
	}
}

int	main(int argc, char *argv[])
{
	int	s_pid;

	check_args(argc, argv);
	s_pid = ft_atoi(argv[1]);
	if (s_pid <= 0)
	{
		ft_putendl_fd("Error\nInvalid PID", 2);
		exit(1);
	}
	signal(SIGUSR2, sig_handler);
	send_str(s_pid, argv[2]);
	return (0);
}
