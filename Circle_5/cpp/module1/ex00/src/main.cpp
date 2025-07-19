#include "Zombie.hpp"

static Zombie*	newZombie(std::string name)
{
	Zombie*	z = new Zombie(name);
	return z;
}

static void	randomChump(std::string name)
{
	Zombie	z(name);
	z.announce();
}

int	main(void)
{
	Zombie*	z;

	randomChump("stackFoo");
	z = newZombie("heapFoo");
	z->announce();
	delete z;
	return 0;
}