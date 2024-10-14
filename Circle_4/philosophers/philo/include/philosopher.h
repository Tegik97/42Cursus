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
} t_fork;

typedef struct s_conditions
{
	size_t	inittime;
	size_t	dietime;
	size_t	eattime;
	size_t	sleeptime;
	size_t	neat;
	size_t	eaten;
	pthread_mutex_t	lockexit;
	pthread_mutex_t	lockmeal;
	pthread_mutex_t	lockate;
	int		exit;
} t_conditions;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	size_t			last_meal;
	size_t			ate;
	t_fork			*fork;
	t_conditions	*cond;
	struct s_philo	*next;
} t_philo;

size_t	ft_atoi(char *str);
size_t	get_time();
void	create_philos(int nphilo, t_philo *philos);
void	create_forks(int nphilo, t_fork *forks);
void	connect_philos_and_forks(t_philo *philos, t_fork *forks, t_conditions *cond);
int		philo_eat(t_philo *p);
void	check_philos(t_philo *p, size_t nphilo);
void	free_all(t_philo *p);
int		check_death(t_philo *p);
int		take_next_fork(t_philo *p, size_t tstamp);

#endif