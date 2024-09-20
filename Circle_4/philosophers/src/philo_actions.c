#include "philosopher.h"

static int	check_dead(t_philo *p)
{
	if ((get_time() - p->last_meal) > p->cond->dietime)
	{
		printf("\033[1;41m%ldms philo %ld has died\033[0m\n", get_time() - p->cond->inittime, p->id);
		return (1);
	}
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
			p->cond->exit = 1;
			return ;
		}
		if (p->ate >= p->cond->neat)
			philoate[p->id - 1] = 1;
		p = p->next;
	}
}

int	philo_eat(t_philo *p, size_t tstamp)
{
	pthread_mutex_lock(&p->fork->lock);
	p->fork->status = TAKEN;
	if (p->fork->next->status == FREE && p->cond->exit == 0)
	{
		pthread_mutex_lock(&p->fork->next->lock);
		p->fork->next->status = TAKEN;
		tstamp = get_time() - p->cond->inittime;
		printf("\033[36m%ldms philo %ld has taken a fork\033[0m\n", tstamp, p->id);
		tstamp = get_time() - p->cond->inittime;
		printf("\033[32m%ldms philo %ld is eating\033[0m\n", tstamp, p->id);
		p->last_meal = get_time();
		usleep(p->cond->eattime * 1000);
		pthread_mutex_unlock(&p->fork->lock);
		pthread_mutex_unlock(&p->fork->next->lock);
		p->ate++;
		return (1);
	}
	else
		pthread_mutex_unlock(&p->fork->lock);
	p->fork->status = FREE;
	p->fork->next->status = FREE;
	return (0);
}
