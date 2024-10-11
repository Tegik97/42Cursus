#include "philosopher.h"

int	check_death(t_philo *p)
{
	pthread_mutex_lock(&p->cond->lockexit);
	if (p->cond->exit == 1)
	{
		pthread_mutex_unlock(&p->cond->lockexit);
		return (1);
	}
	pthread_mutex_unlock(&p->cond->lockexit);
	return (0);
}

int	take_next_fork(t_philo *p, size_t tstamp)
{
	pthread_mutex_lock(&p->fork->next->lock);
	if (check_death(p))
	{
		pthread_mutex_unlock(&p->fork->lock);
		pthread_mutex_unlock(&p->fork->next->lock);
		return (0);
	}
	tstamp = get_time() - p->cond->inittime;
	printf("\033[32m%ldms philo %ld is eating\033[0m\n", tstamp, p->id);
	pthread_mutex_lock(&p->cond->lockmeal);
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->cond->lockmeal);
	pthread_mutex_lock(&p->cond->lockate);
	p->ate++;
	pthread_mutex_unlock(&p->cond->lockate);
	usleep(p->cond->eattime * 1000);
	pthread_mutex_unlock(&p->fork->next->lock);
	return (1);
}
