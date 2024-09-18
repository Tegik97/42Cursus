#include "philo_utils.h"

size_t	ft_atoi(char *str)
{
	size_t base;

	base = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		printf("Number of philosophers must be a positive integer\n");
		return (0);
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		base = base * 10 + *str - '0';
		str++;
	}
	if (base == 0)
		printf("Number of philosophers must be greater than 0\n");
	else if (base > INT_MAX)
	{
		printf("Number of philosophers must be a valid integer\n");
		return (0);
	}
	return (base);
}
