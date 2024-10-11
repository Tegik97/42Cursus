#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo	*p;
	size_t	tstamp;

	p = (t_philo *)arg;
	while (1)
	{
		if (!philo_eat(p) || check_death(p))
			return (NULL);
		tstamp = get_time() - p->cond->inittime;
		printf("\033[34m%ldms philo %ld is sleeping\033[0m\n", tstamp, p->id);
		usleep(p->cond->sleeptime * 1000);
		if (check_death(p))
			return (NULL);
		tstamp = get_time() - p->cond->inittime;
		printf("\033[33m%ldms philo %ld is thinking\033[0m\n", tstamp, p->id);
	}
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
		usleep(500);
    } while (current != philos);
}


static size_t	init(char **argv, t_philo *philos, t_fork *forks)
{
	int	nphilo;
	t_conditions	*cond;

	nphilo = ft_atoi(argv[1]);
	if (nphilo == 0 || nphilo > 200)
	{
		printf("Number of philosophers must be greater than 0 and lower than 201\n");
		return (0);
	}
	cond = malloc (1 * sizeof(t_conditions));
	pthread_mutex_init(&cond->lockexit, NULL);
	pthread_mutex_init(&cond->lockmeal, NULL);
	pthread_mutex_init(&cond->lockate, NULL);
	cond->inittime = get_time();
	cond->dietime = ft_atoi(argv[2]);
	cond->eattime = ft_atoi(argv[3]);
	cond->sleeptime = ft_atoi(argv[4]);
	cond->neat = -1;
	if (argv[5])
		cond->neat = ft_atoi(argv[5]);
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
	if (!nphilo)
		return (1);
	create_threads(philos);
	check_philos(philos, nphilo);
	create_joins(philos);
	free_all(philos);
	return (0);
}
