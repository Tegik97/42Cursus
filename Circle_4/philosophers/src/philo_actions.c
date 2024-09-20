#include "philosopher.h"

static int	check_dead(t_philo *p)
{
	if ((get_time() - p->last_meal) > p->cond->eattime)
	{
		printf("%ld %ld has died\n", get_time() - p->cond->inittime, p->id);
		return (1);
	}
	return (0);
}

static int	check_array(size_t	*arr, size_t neat, size_t nphilo)
{
	size_t	i;
	size_t	cont;

	i = 0;
	cont = 0;
	while (i < nphilo)
	{
		if (arr[i++] >= neat)
			cont++;
	}
	if (cont == nphilo)
		return (1);
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
		if (check_array(philoate, p->cond->neat, nphilo) || check_dead(p))
		{
			p->cond->exit = 1;
			return ;
		}
		if (p->ate >= p->cond->neat)
			philoate[p->id - 1]++;
		p = p->next;
	}
}

int	philo_eat(t_philo *p, size_t tstamp)
{
	pthread_mutex_lock(&p->fork->lock);
	p->fork->status = TAKEN;
	if (p->fork->next->status == FREE)
	{
		tstamp = get_time() - p->cond->inittime;
		printf("%ld %ld has taken a fork\n", tstamp, p->id);
		pthread_mutex_lock(&p->fork->next->lock);
		p->fork->next->status = TAKEN;
		tstamp = get_time() - p->cond->inittime;
		printf("%ld %ld is eating\n", tstamp, p->id);
		usleep(p->cond->eattime * 1000);
		p->last_meal = get_time() - p->cond->inittime;
		pthread_mutex_unlock(&p->fork->lock);
		p->fork->status = FREE;
		pthread_mutex_unlock(&p->fork->next->lock);
		p->fork->next->status = FREE;
		p->ate++;
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&p->fork->lock);
		p->fork->status = FREE;
		return (0);
	}
}
