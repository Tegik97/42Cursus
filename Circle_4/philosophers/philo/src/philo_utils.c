/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:03:26 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/18 14:29:16 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	connect_philos_and_forks(t_philo *p, t_fork *f, t_conditions *cond)
{
	t_philo	*phead;

	phead = p;
	p->ate = 0;
	p->fork = f;
	p->cond = cond;
	p = p->next;
	f = f->next;
	while (p != phead)
	{
		p->ate = 0;
		p->fork = f;
		p->cond = cond;
		p = p->next;
		f = f->next;
	}
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
	while (++i <= nphilo)
	{
		new_element = malloc (1 * sizeof(t_fork));
		new_element->id = i;
		pthread_mutex_init(&new_element->lock, NULL);
		forks->next = new_element;
		forks = forks->next;
	}
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
	while (++i <= nphilo)
	{
		new_element = malloc (1 * sizeof(t_philo));
		new_element->id = i;
		new_element->last_meal = get_time();
		philos->next = new_element;
		philos = philos->next;
	}
	philos->next = phead;
}

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}

size_t	ft_atoi(char *str)
{
	size_t	base;

	base = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		base = base * 10 + *str - '0';
		str++;
		if (*str && (*str < '0' || *str > '9'))
			return (0);
	}
	if (base > INT_MAX)
		return (0);
	return (base);
}
