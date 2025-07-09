#include "libft.h"

void	print_error(int foundP)
{
	if (!foundP)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Player not found", 2);
	}
}