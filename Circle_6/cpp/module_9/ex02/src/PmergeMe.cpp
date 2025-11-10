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

void	PmergeMe::printSortedVector()
{
	sortVector(1);
}

static std::vector<int>	copySortVec(std::vector<std::vector<int> >& pairs)
{
	std::vector<int>	vec;
	for (size_t i = 0; (i + 1) < pairs.size(); i += 2)
	{
		if (pairs[i].back() > pairs[i + 1].back())
			std::swap(pairs[i], pairs[i + 1]);
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "[";
		for (size_t j = 0; j < pairs[i].size(); j++)
		{
			vec.push_back(pairs[i][j]);
			std::cout << pairs[i][j] << ",";
		}
		std::cout << "] ";
	}
	std::cout << std::endl;
	return vec;
}


void	PmergeMe::sortVector(int recursion_level)
{
	size_t	pair_size = 1 << (recursion_level - 1);
	std::vector<std::vector<int> >	pairs_vec;
	
	for (size_t	i = 0; i < _vec.size(); i += pair_size)
	{
		std::vector<int>	pair;
		
		for(size_t j = 0; j < pair_size && (i + j) < _vec.size(); j++)
		pair.push_back(_vec[i + j]);
		
		pairs_vec.push_back(pair);
	}
	_vec = copySortVec(pairs_vec);
	
	if (static_cast<size_t>(1 << recursion_level) <= (_vec.size() / 2))
		sortVector(recursion_level + 1);
	
	// binaryVectInsertion(pairs_vec);
}

// void	PmergeMe::binaryVectInsertion(std::vector<std::vector<int> > pairs)
// {
	
// }
