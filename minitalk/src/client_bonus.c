#include "minitalk.h"

int	received = 0;

static void	sig_handler(int signum)
{
	received = 1;
	// ft_printf("Received\n");
	(void)signum;
}

static void	send_char(int s_pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
		{
			if (kill(s_pid, SIGUSR1) == -1)
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
		}
		i--;
		while (received == 0)
			;
		received = 0;
	}
}

static void	send_str(int s_pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		send_char(s_pid, str[i++]);
	}
	send_char(s_pid, '\n');
	send_char(s_pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	s_pid;

	if (argc != 3)
	{
		ft_putendl_fd("Error\nUsage: ./client <Server PID> <string>", 2);
		exit(1);
	}
	s_pid = ft_atoi(argv[1]);
	if (s_pid <= 0)
	{
		ft_putendl_fd("Error\nPID not valid", 2);
		exit(1);
	}
	signal(SIGUSR2, sig_handler);
	send_str(s_pid, argv[2]);
	return (0);
}
