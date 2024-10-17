/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:03:24 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/17 19:23:18 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	parsing(int nphilo, t_conditions *cond)
{
	if (nphilo <= 0 || nphilo > 200)
		printf("Number of philos must be greater than 0 and lower than 201\n");
	else if (cond->dietime <= 0)
		printf("Time to die must be greater than 0\n");
	else if (cond->eattime <= 0)
		printf("Time to eat must be greater than 0\n");
	else if (cond->sleeptime <= 0)
		printf("Time to sleep must be greater than 0\n");
	else if (cond->neat < -1 || cond->neat == 0)
		printf("Times to eat must be greater than 0");
	else
		return (1);
	return (0);
}

int	philo_alone(t_philo *p)
{
	if (p == p->next)
	{
		while (!check_death(p))
			usleep (1);
		pthread_mutex_unlock(&p->fork->lock);
		return (1);
	}
	return (0);
}

size_t	*ft_calloc(size_t size, size_t nmemb)
{
	size_t	*arr;
	size_t	i;

	arr = malloc(size * nmemb);
	i = 0;
	while (i < nmemb)
		arr[i++] = 0;
	return (arr);
}

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
	if (p->next->id != 1)
		pthread_mutex_lock(&p->fork->next->lock);
	else
		pthread_mutex_lock(&p->fork->lock);
	if (check_death(p))
	{
		pthread_mutex_unlock(&p->fork->lock);
		pthread_mutex_unlock(&p->fork->next->lock);
		return (0);
	}
	tstamp = get_time() - p->cond->inittime;
	pthread_mutex_lock(&p->cond->lockprint);
	printf("\033[32m%ldms philo %ld is eating\033[0m\n", tstamp, p->id);
	pthread_mutex_unlock(&p->cond->lockprint);
	pthread_mutex_lock(&p->cond->lockmeal);
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->cond->lockmeal);
	usleep(p->cond->eattime * 1000);
	pthread_mutex_lock(&p->cond->lockate);
	p->ate++;
	pthread_mutex_unlock(&p->cond->lockate);
	return (1);
}
