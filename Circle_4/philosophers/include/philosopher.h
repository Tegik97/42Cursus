#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <pthread.h>
# include "philo_utils.h"

enum
{
	EATING 		= 1024,
	SLEEPING,
	THINKING
};

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	int				status;
	long long int	last_meal;
	struct s_philo	*next;
} t_philo;

typedef struct s_fork
{
	size_t			id;
	pthread_mutex_t	lock;
	struct s_fork	*next;
} t_fork;


#endif