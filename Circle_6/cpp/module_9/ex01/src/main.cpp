#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: expression missing" << std::endl;
		return 1;
	}

	RPN	expr;

	expr.calculate(argv[1]);
	return 0;
}