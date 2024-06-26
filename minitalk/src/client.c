#include "minitalk.h"

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
		usleep(50);
	}
}

static void	send_str(int s_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char(s_pid, str[i++]);
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
	send_str(s_pid, argv[2]);
	return (0);
}
