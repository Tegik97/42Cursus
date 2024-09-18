#include "philosopher.h"

/*	creare la funzione get_time ed impostare la struttura in modo che l'ultimo
	elemento punti al primo della struttura*/

int	init(char **argv)
{
	t_philo	*philos;
	t_fork	*forks;
	size_t	nphilo;

	nphilo = ft_atoi(argv[1]);
	while (nphilo-- > 1)
	{
		philos->id = nphilo;
		philos->status = THINKING;
		philos->last_meal = get_time();
		philos->next = NULL;
		forks->id = nphilo;
		pthread_mutex_init(&forks->lock, NULL);
		forks->next = NULL;
	}
	return (nphilo);
}

int	main(int argc, char *argv[])
{
	if (argc < 5)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	if (!init(argv))
		return (1);
	
	return (0);
}
