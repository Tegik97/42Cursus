#include "philosopher.h"

void	connect_philos_and_forks(t_philo *philos, t_fork *forks)
{
	t_philo	*phead;

	phead = philos;
	do
	{
		philos->fork = forks;
		philos = philos->next;
		forks = forks->next;
	} while (philos != phead);
}

void	create_forks(int nphilo, t_fork *forks)
{
	t_fork	*fhead;
	t_fork	*new_element;
	int		i;

	i = 1;
	forks->id = i;
	pthread_mutex_init(&forks->lock, NULL);
	fhead = forks;
	while (++i < nphilo)
	{
		new_element = malloc (1 * sizeof(t_fork));
		new_element->id = i;
		pthread_mutex_init(&new_element->lock, NULL);
		forks->next = new_element;
		forks = forks->next;
	}
	new_element = malloc (1 * sizeof(t_fork));
	new_element->id = i;
	pthread_mutex_init(&new_element->lock, NULL);
	forks->next = new_element;
	forks = forks->next;
	forks->next = fhead;
}

void	create_philos(int nphilo, t_philo *philos)
{
	t_philo	*phead;
	t_philo	*new_element;
	int		i;

	i = 1;
	philos->id = i;
	philos->last_meal = get_time();
	phead = philos;
	while (++i < nphilo)
	{
		new_element = malloc (1 * sizeof(t_philo));
		new_element->id = i;
		new_element->last_meal = get_time();
		philos->next = new_element;
		philos = philos->next;
	}
	new_element = malloc (1 * sizeof(t_philo));
	new_element->id = i;
	new_element->last_meal = get_time();
	philos->next = new_element;
	philos = philos->next;
	philos->next = phead;
}

size_t	get_time()
{
	struct timeval tv;
	size_t	current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}

size_t	ft_atoi(char *str)
{
	size_t base;

	base = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		printf("Number of philosophers must be a positive integer\n");
		return (0);
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		base = base * 10 + *str - '0';
		str++;
	}
	if (base == 0)
		printf("Number of philosophers must be greater than 0\n");
	else if (base > INT_MAX)
	{
		printf("Number of philosophers must be a valid integer\n");
		return (0);
	}
	return (base);
}
