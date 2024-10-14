#include "philosopher.h"

void	free_all(t_philo *p)
{
	t_philo	*phead;
	t_philo	*current;

	phead = p;
	p = p->next;
	pthread_mutex_destroy(&p->cond->lockexit);
	pthread_mutex_destroy(&p->cond->lockate);
	pthread_mutex_destroy(&p->cond->lockmeal);
	free (p->cond);
	while (p != phead)
	{
		current = p;
		p = p->next;
		pthread_mutex_destroy(&current->fork->lock);
		free (current->fork);
		free (current);
	}
	pthread_mutex_destroy(&p->fork->lock);
	free (p->fork);
	free (p);
}

static int	check_dead(t_philo *p)
{
	pthread_mutex_lock(&p->cond->lockmeal);
	if ((get_time() - p->last_meal) > p->cond->dietime)
	{
		pthread_mutex_unlock(&p->cond->lockmeal);
		printf("\033[1;41m%ldms philo %ld has died\033[0m\n", get_time() - p->cond->inittime, p->id);
		return (1);
	}
	pthread_mutex_unlock(&p->cond->lockmeal);
	return (0);
}

static int	check_array(size_t	*arr, size_t nphilo)
{
	size_t	i;
	size_t	cont;

	i = 0;
	cont = 0;
	while (i < nphilo)
	{
		if (arr[i++] > 0)
			cont++;
	}
	if (cont == nphilo)
	{
		printf("\033[1;48;2;0;64;0mAll philosophers have eaten\033[0m\n");
		return (1);
	}
	return (0);
}

void	check_philos(t_philo *p, size_t nphilo)
{
	size_t	philoate[nphilo];
	size_t	i;

	i = 0;
	while (i < nphilo)
		philoate[i++] = 0;
	while (1)
	{
		if (check_array(philoate, nphilo) || check_dead(p))
		{
			pthread_mutex_lock(&p->cond->lockexit);
			p->cond->exit = 1;
			pthread_mutex_unlock(&p->cond->lockexit);
			return ;
		}
		pthread_mutex_lock(&p->cond->lockate);
		if (p->ate >= p->cond->neat)
			philoate[p->id - 1] = 1;
		pthread_mutex_unlock(&p->cond->lockate);
		p = p->next;
	}
}

int	philo_eat(t_philo *p)
{
	size_t	tstamp;

	pthread_mutex_lock(&p->fork->lock);
	if (check_death(p))
	{
		pthread_mutex_unlock(&p->fork->lock);
		return (0);
	}
	tstamp = get_time() - p->cond->inittime;
	printf("\033[36m%ldms philo %ld has taken a fork\033[0m\n", tstamp, p->id);
	if (p->next->id != p->id)
	{
		if (!take_next_fork(p, tstamp))
			return (0);
	}
	else
	{
		while (!check_death(p))
			;
		pthread_mutex_unlock(&p->fork->lock);
		return (0);
	}
	pthread_mutex_unlock(&p->fork->lock);
	return (1);
}

// int	philo_eat(t_philo *p)
// {
// 	size_t	tstamp;

// 	pthread_mutex_lock(&p->fork->lock);
// 	if (check_death(p))
// 	{
// 		pthread_mutex_unlock(&p->fork->lock);
// 		return (0);
// 	}
// 	tstamp = get_time() - p->cond->inittime;
// 	printf("\033[36m%ldms philo %ld has taken a fork\033[0m\n", tstamp, p->id);
// 	if (p->next->id != p->id)
// 	{
// 		pthread_mutex_lock(&p->fork->next->lock);
// 		if (check_death(p))
// 		{
// 			pthread_mutex_unlock(&p->fork->lock);
// 			pthread_mutex_unlock(&p->fork->next->lock);
// 			return (0);
// 		}
// 		tstamp = get_time() - p->cond->inittime;
// 		printf("\033[32m%ldms philo %ld is eating\033[0m\n", tstamp, p->id);
// 		pthread_mutex_lock(&p->cond->lockmeal);
// 		p->last_meal = get_time();
// 		pthread_mutex_unlock(&p->cond->lockmeal);
// 		pthread_mutex_lock(&p->cond->lockate);
// 		p->ate++;
// 		pthread_mutex_unlock(&p->cond->lockate);
// 		usleep(p->cond->eattime * 1000);
// 		pthread_mutex_unlock(&p->fork->next->lock);
// 	}
// 	pthread_mutex_unlock(&p->fork->lock);
// 	return (1);
// }
