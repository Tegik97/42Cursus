#include "replacer.hpp"

int	main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cerr << "Not enough arguments" << std::endl << "Expected: ./replacer <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	replaceInFile(argv[1], argv[2], argv[3]);
	return 0;
}