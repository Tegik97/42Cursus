#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo	*p;
	size_t	tstamp;

	p = (t_philo *)arg;
	while (p->cond->exit == 0)
	{
		while (!philo_eat(p, tstamp))
			;
		usleep(p->cond->sleeptime * 1000);
		tstamp = get_time() - p->cond->inittime;
		printf("%ld %ld is sleeping\n", tstamp, p->id);
	}
	return (NULL);
}

static void create_joins(t_philo *philos)
{
    t_philo *current;
	
	current = philos;
    do {
        if (pthread_join(current->thread, NULL) != 0) {
            printf("pthread_join error\n");
            return;
        }
        current = current->next;
    } while (current != philos);
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
}


static size_t	init(char **argv, t_philo *philos, t_fork *forks)
{
	int	nphilo;
	t_conditions	*cond;

	nphilo = ft_atoi(argv[1]);
	if (nphilo == 0)
		return (0);
	cond = malloc (1 * sizeof(t_conditions));
	cond->inittime = get_time();
	cond->dietime = ft_atoi(argv[2]);
	cond->eattime = ft_atoi(argv[3]);
	cond->sleeptime = ft_atoi(argv[4]);
	if (argv[5])
		cond->neat = ft_atoi(argv[5]);
	else
		cond->neat = -1;
	cond->exit = 0;
	create_forks(nphilo, forks);
	create_philos(nphilo, philos);
	connect_philos_and_forks(philos, forks, cond);
	return (nphilo);
}

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	t_fork			*forks;
	size_t			nphilo;

	if (argc < 5)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	philos = malloc (1 * sizeof(t_philo));
	forks = malloc (1 * sizeof(t_fork));
	nphilo = init(argv, philos, forks);
	create_threads(philos);
	check_philos(philos, nphilo);
	create_joins(philos);
	return (0);
}
