/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:03:32 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/18 13:59:06 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>

enum
{
	FREE = 1024,
	TAKEN,
	EATING,
	THINKING,
	SLEEPING
};

typedef struct s_fork
{
	size_t			id;
	pthread_mutex_t	lock;
	struct s_fork	*next;
}	t_fork;

typedef struct s_conditions
{
	int				neat;
	int				exit;
	int				nphilo;
	size_t			inittime;
	size_t			dietime;
	size_t			eattime;
	size_t			sleeptime;
	size_t			eaten;
	pthread_mutex_t	lockexit;
	pthread_mutex_t	lockmeal;
	pthread_mutex_t	lockate;
	pthread_mutex_t	lockprint;
}	t_conditions;

typedef struct s_philo
{
	pthread_t		thread;
	int				ate;
	size_t			id;
	size_t			last_meal;
	t_fork			*fork;
	t_conditions	*cond;
	struct s_philo	*next;
}	t_philo;

size_t	ft_atoi(char *str);
size_t	get_time(void);
void	create_philos(int nphilo, t_philo *philos);
void	create_forks(int nphilo, t_fork *forks);
void	connect_philos_and_forks(t_philo *p, t_fork *f, t_conditions *cond);
int		philo_eat(t_philo *p, size_t tstamp);
void	check_philos(t_philo *p, size_t nphilo);
void	free_all(t_philo *p);
int		check_death(t_philo *p, int cond);
int		take_next_fork(t_philo *p, size_t tstamp);
size_t	*ft_calloc(size_t size, size_t nmemb);
int		philo_alone(t_philo *p);
int		parsing(int nphilo, t_conditions *cond);

#endif