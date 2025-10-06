#include "iter.hpp"
#include <iostream>

template<typename T>
void	printValue(const T& value)
{
	std::cout << value << ", ";
}

void	increment(int& n)
{
	n += 1;
}

int main(void)
{
	int		arr[] = {1, 2, 3, 4, 5, 6};
	const char*	arr2[] = {"Firenze", "Bologna", "Roma", "Venezia", "Torino"};

	
	::iter(arr, 6, printValue<int>);
	std::cout << std::endl;
	::iter(arr, 6, increment);
	::iter(arr, 6, printValue<int>);
	std::cout << std::endl;
	::iter(arr2, 5, printValue<const char*>);
	std::cout << std::endl;
}