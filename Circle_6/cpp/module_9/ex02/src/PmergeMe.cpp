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
	std::cout << "Before: ";
	for (size_t	i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	sortVector(1);

	std::cout << "After: ";
	for (size_t	i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

static std::vector<std::vector<int> >	swapPairs(std::vector<std::vector<int> > pairs)
{
	for (size_t i = 0; (i + 1) < pairs.size(); i += 2)
	{
		if (pairs[i].back() > pairs[i + 1].back())
			std::swap(pairs[i], pairs[i + 1]);
	}

	return pairs;
}

static std::vector<int>	copyVect(std::vector<std::vector<int> > pairs)
{
	std::vector<int>	vec;
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = 0; j < pairs[i].size(); j++)
			vec.push_back(pairs[i][j]);
	}

	return vec;
}

static std::vector<std::vector<int> >	getPairsVect(size_t pair_size, std::vector<int> vec)
{
	std::vector<std::vector<int> >	pairs_vec;

	for (size_t	i = 0; i < vec.size(); i += pair_size)
	{
		std::vector<int>	pair;
		
		for(size_t j = 0; j < pair_size && (i + j) < vec.size(); j++)
		pair.push_back(vec[i + j]);
		
		pairs_vec.push_back(pair);
	}
	return pairs_vec;
}

void	PmergeMe::sortVector(int recursion_level)
{
	size_t	pair_size = 1 << (recursion_level - 1);
	std::vector<std::vector<int> >	pairs_vec = getPairsVect(pair_size, _vec);

	pairs_vec = swapPairs(pairs_vec);
	_vec = copyVect(pairs_vec);
	
	if (static_cast<size_t>(1 << recursion_level) <= (_vec.size() / 2))
		sortVector(recursion_level + 1);
	
	binaryVectInsertion(pair_size);
}

static size_t	getJacobsthal(int n)
{
	size_t	power = 1 << (n + 1);
	int		sign = (n % 2 == 0) ? 1 : -1;

	return (power + sign) / 3;
}

static int	binarySearchBound(const std::vector<std::vector<int> >& main_vec,
									const std::vector<int>& element,
									int bound)
{
	if (main_vec.empty() || bound == 0)
		return 0;
	
	int	target = element.back();
	
	while (bound >= 0)
	{
		if (main_vec[bound].back() < target)
			return bound + 1;
		bound--;
	}
	return bound + 1;
}

void	PmergeMe::binaryVectInsertion(size_t pair_size)
{
	std::vector<std::vector<int> >	pairs_vec = getPairsVect(pair_size, _vec);
	std::vector<std::vector<int> >	main_vec;
	std::vector<std::vector<int> >	pend_vec;
	std::vector<int>				carry_vec;

	main_vec.push_back(pairs_vec[0]);

	for (size_t i = 1; i < (pairs_vec.size() - 1); i++)
	{
		if (i % 2 == 0)
			pend_vec.push_back(pairs_vec[i]);
		else
			main_vec.push_back(pairs_vec[i]);
	}
	if (pairs_vec.back().size() == pair_size)
		pend_vec.push_back(pairs_vec.back());
	else
		carry_vec = pairs_vec.back();
	
	if (pend_vec.empty())
	{
		if (!carry_vec.empty())
			main_vec.push_back(carry_vec);
		_vec = copyVect(main_vec);
		return ;
	}
	
	size_t	jacob_idx = 2;
	size_t	inserted = 0;

	while (inserted < pend_vec.size())
	{
		size_t	current_jacob = (getJacobsthal(jacob_idx));
		size_t	prev_jacob = (getJacobsthal(jacob_idx - 1));
		size_t	end = std::min(current_jacob, pend_vec.size());

		for (size_t pos = end; pos >= prev_jacob && pos > 0; pos--)
		{
			int	bound = 1 + pos;
			bound = std::min(static_cast<size_t>(bound), main_vec.size() - 1);
			int	insert_pos = binarySearchBound(main_vec, pend_vec[pos - 1], bound);

			main_vec.insert(main_vec.begin() + insert_pos, pend_vec[pos - 1]);
			inserted++;
		}
		jacob_idx++;
	}
	if (!carry_vec.empty())
		main_vec.push_back(carry_vec);
	_vec = copyVect(main_vec);
}
