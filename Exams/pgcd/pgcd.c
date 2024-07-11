#include <stdio.h>
#include <stdlib.h>

static int	ft_pgcd(int n1, int n2)
{
	int	cd;
	int	i;

	i = 1;
	while (i <= n1 && i <= n2)
	{
		if (n1 % i == 0 && n2 % i == 0)
			cd = i;
		i++;
	}
	return (cd);
}

int	main(int argc, char *argv[])
{
	int	cd;

	if (argc == 3)
	{
		cd = ft_pgcd(atoi(argv[1]), atoi(argv[2]));
		printf("%d\n", cd);
	}
	else
		printf("\n");
	return (0);
}