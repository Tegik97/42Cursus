#include "philo_bonus.h"

int	main(void)
{
	pid_t	pids[200];
	size_t	i;
	int		status;

	i = 0;
	while (i < 200)
	{
		pids[i] = fork();
		if (pids[i] < 0)
		{
			perror("aia");
			return (1);
		}
		else if (pids[i] == 0)
		{
			printf("Child process with pid: %d\n", getpid());
			sleep(2);
			exit(i + 1);
		}
		i++;
	}
	i = 0;
	while (i < 200)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			printf("Child process %d ended with status: %d\n", pids[i], WEXITSTATUS(status));
		else
			printf("Child process %d ended with abnormal status\n", pids[i]);
		i++;
	}
	return (0);
}