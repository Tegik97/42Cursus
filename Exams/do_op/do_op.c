#include <unistd.h>
#include <stdio.h>

static int	ft_atoi(char *str)
{
	int	sig;
	int base;

	sig = 1;
	if (*str == '-')
	{
		sig = -1;
		str++;
	}
	base = 0;
	while (*str >= '0' && *str <= '9')
	{
		base = (base * 10) + (*str - '0');
		str++;
	}
	return (base * sig);
}

static int	ft_do_op(char *first, char op, char *second)
{
	int	n1;
	int	n2;
	int	res;

	n1 = ft_atoi(first);
	n2 = ft_atoi(second);

	if (op == '+')
		res = n1 + n2;
	else if (op == '-')
		res = n1 - n2;
	else if (op == '*')
		res = n1 * n2;
	else if (op == '/')
		res = n1 / n2;
	else
		res = n1 % n2;
	return (res);
}

int	main(int argc, char *argv[])
{
	int	res;

	if (argc == 4)
	{
		res = ft_do_op(argv[1], argv[2][0], argv[3]);
		printf("%d\n", res);
	}
	else
		printf("\n");
	return (0);
}
