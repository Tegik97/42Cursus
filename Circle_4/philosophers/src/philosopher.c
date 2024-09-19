#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	printf("philo id %ld\nfork id %ld\nnext fork id %ld\nlast meal %ld\n\n", philos->id, philos->fork->id, philos->fork->next->id, philos->last_meal);
	return (NULL);
}

static void create_threads(t_philo *philos)
{
    t_philo *current;
	
	current = philos;
    do {
        if (pthread_create(&current->thread, NULL, routine, current) != 0) {
            printf("pthread_create error\n");
            return;
        }
        current = current->next;
    } while (current != philos);
	current = philos;
    do {
        if (pthread_join(current->thread, NULL) != 0) {
            printf("pthread_join error\n");
            return;
        }
        current = current->next;
    } while (current != philos);
}


static int	init(char **argv, t_philo *philos, t_fork *forks)
{
	int	nphilo;

	nphilo = ft_atoi(argv[1]);
	if (nphilo == 0)
		return (0);
	create_forks(nphilo, forks);
	create_philos(nphilo, philos);
	connect_philos_and_forks(philos, forks);
	return (nphilo);
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;
	t_fork	*forks;

	if (argc < 5)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	philos = malloc (1 * sizeof(t_philo));
	forks = malloc (1 * sizeof(t_fork));
	if (!init(argv, philos, forks))
		return (1);
	create_threads(philos);
	return (0);
}
