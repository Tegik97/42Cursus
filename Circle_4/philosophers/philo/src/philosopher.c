/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:03:28 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/18 14:04:29 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo	*p;
	size_t	tstamp;

	p = (t_philo *)arg;
	tstamp = 0;
	while (1)
	{
		if (!philo_eat(p, tstamp) || check_death(p, 2))
			return (NULL);
		tstamp = get_time() - p->cond->inittime;
		pthread_mutex_lock(&p->cond->lockprint);
		printf("\033[34m%ldms philo %ld is sleeping\033[0m\n", tstamp, p->id);
		pthread_mutex_unlock(&p->cond->lockprint);
		usleep(p->cond->sleeptime * 1000);
		if (check_death(p, 2))
			return (NULL);
		tstamp = get_time() - p->cond->inittime;
		pthread_mutex_lock(&p->cond->lockprint);
		printf("\033[33m%ldms philo %ld is thinking\033[0m\n", tstamp, p->id);
		pthread_mutex_unlock(&p->cond->lockprint);
	}
}

static void	create_joins(t_philo *philos)
{
	t_philo	*current;

	current = philos;
	if (pthread_join(current->thread, NULL) != 0)
	{
		printf("pthread_join error\n");
		return ;
	}
	current = current->next;
	while (current != philos)
	{
		if (pthread_join(current->thread, NULL) != 0)
		{
			printf("pthread_join error\n");
			return ;
		}
		current = current->next;
	}
}

static void	create_threads(t_philo *philos)
{
	t_philo	*current;

	current = philos;
	if (pthread_create(&current->thread, NULL, routine, current) != 0)
	{
		printf("pthread_create error\n");
		return ;
	}
	current = current->next;
	usleep(50);
	while (current != philos)
	{
		if (pthread_create(&current->thread, NULL, routine, current) != 0)
		{
			printf("pthread_create error\n");
			return ;
		}
		current = current->next;
		usleep(500);
	}
}

static size_t	init(char **argv, t_philo *p, t_conditions *cond, t_fork *forks)
{
	cond->nphilo = ft_atoi(argv[1]);
	cond->inittime = get_time();
	cond->dietime = ft_atoi(argv[2]);
	cond->eattime = ft_atoi(argv[3]);
	cond->sleeptime = ft_atoi(argv[4]);
	cond->neat = -1;
	if (argv[5])
		cond->neat = ft_atoi(argv[5]);
	cond->exit = 0;
	if (!parsing(cond->nphilo, cond))
		return (0);
	pthread_mutex_init(&cond->lockexit, NULL);
	pthread_mutex_init(&cond->lockmeal, NULL);
	pthread_mutex_init(&cond->lockate, NULL);
	pthread_mutex_init(&cond->lockprint, NULL);
	create_forks(cond->nphilo, forks);
	create_philos(cond->nphilo, p);
	connect_philos_and_forks(p, forks, cond);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	t_fork			*forks;
	t_conditions	*cond;

	if (argc < 5)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	philos = malloc (1 * sizeof(t_philo));
	forks = malloc (1 * sizeof(t_fork));
	cond = malloc (1 * sizeof(t_conditions));
	if (!init(argv, philos, cond, forks))
	{
		free (philos);
		free (forks);
		free (cond);
		return (1);
	}
	create_threads(philos);
	check_philos(philos, cond->nphilo);
	create_joins(philos);
	free_all(philos);
	return (0);
}
