int	ft_atoi(const char *str)
{
	int	sig;
	int	base;

	sig = 1;
	base = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		base = (base * 10) + (*str - '0');
		str++;
	}
	return (base * sig);
}
