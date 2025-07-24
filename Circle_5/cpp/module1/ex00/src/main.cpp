#include "Zombie.hpp"

int	main(void)
{
	Zombie*	z;

	randomChump("stackFoo");
	z = newZombie("heapFoo");
	z->announce();
	delete z;
	return 0;
}