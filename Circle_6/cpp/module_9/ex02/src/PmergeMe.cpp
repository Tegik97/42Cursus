#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}

	return *this;
}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::inputParse(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return false;
	}

	for	(int i = 1; i < argc; i++)
	{
		std::stringstream	ss(argv[i]);
		int					value;

		while (ss >> value)
		{
			_vec.push_back(value);
			_deq.push_back(value);
		}

		if (!ss.eof())
		{
			std::cerr << "Error: invalid argument " << argv[i] << std::endl;
			return false;
		}
	}
	return true;
}