#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	PmergeMe	merge;

	if (!merge.inputParse(argc, argv))
		return 1;

	merge.runSort();
	return 0;
}