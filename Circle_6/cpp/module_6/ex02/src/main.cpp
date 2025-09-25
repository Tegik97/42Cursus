#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base*	generate(void)
{
	static bool	seeded = false;
	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}

	int	choice = rand() % 3;
	switch (choice)
	{
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

void	identify(Base* p)
{
	std::cout << "Pointer actual type: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "reference actual type: ";
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception&) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception&) {}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception&) {}
}

int	main(void)
{
	std::cout << "-----obj 1-----" << std::endl;
	Base*	obj = generate();
	identify(obj);
	delete obj;

	std::cout << "\n-----obj 2-----" << std::endl;
	Base*	obj2 = generate();
	identify(*obj2);
	delete obj2;

	std::cout << "\n-----obj 3-----" << std::endl;
	Base*	obj3 = generate();
	identify(obj3);
	identify(*obj3);
	delete obj3;
}