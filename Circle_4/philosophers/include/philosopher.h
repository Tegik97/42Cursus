#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_fork
{
	size_t			id;
	pthread_mutex_t	lock;
	struct s_fork	*next;
} t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	size_t			last_meal;
	t_fork			*fork;
	struct s_philo	*next;
} t_philo;

size_t	ft_atoi(char *str);
size_t	get_time();
void	create_philos(int nphilo, t_philo *philos);
void	create_forks(int nphilo, t_fork *forks);
void	connect_philos_and_forks(t_philo *philos, t_fork *forks);

#endif