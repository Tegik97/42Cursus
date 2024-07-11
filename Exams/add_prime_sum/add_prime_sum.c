#include <stdio.h>
#include <unistd.h>

static void ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

static int	ft_isprime(int n)
{
	int	i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi(char *str)
{
	int	base;
	int	sig;

	base = 0;
	sig = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
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

int	main(int argc, char *argv[])
{
	int		n;
	int		res;

	if (argc == 2 && ft_atoi(argv[1]) >= 0)
	{
		n = ft_atoi(argv[1]);
		res = 0;
		while (n > 1)
		{
			if (ft_isprime(n))
				res += n;
			n--;
		}
		ft_putnbr(res);
	}
	else
		ft_putnbr(0);
	write (1, "\n", 1);
	return (0);
}