/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:41:54 by mchiaram          #+#    #+#             */
/*   Updated: 2024/06/29 16:41:55 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t			c_pid = 0;
	static unsigned char	c = 0;
	static int				bits = 0;

	if (c_pid != info->si_pid)
	{
		c = 0;
		bits = 0;
		c_pid = info->si_pid;
	}
	c = c << 1;
	if (signum == SIGUSR2)
		c = c | 1;
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		bits = 0;
		c = 0;
	}
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server PID: %d\n", getpid());
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
