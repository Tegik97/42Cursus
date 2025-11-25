#include "PmergeMe.hpp"

// =============================================================================
// Funzioni Canoniche
// =============================================================================

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vec(other._vec), _deq(other._deq), _timeVec(other._timeVec), _timeDeq(other._timeDeq) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
		_timeVec = other._timeVec;
		_timeDeq = other._timeDeq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// =============================================================================
// Helper: Tempo e Jacobsthal
// =============================================================================

long	PmergeMe::getTime()
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000) + tv.tv_usec;
}

size_t	PmergeMe::getJacobsthal(int n)
{
	if (n < 2)
		return n;
	size_t	power = 1 << (n + 1); // 2^(n+1)
	int		sign = (n % 2 == 0) ? 1 : -1;
	return (power + sign) / 3;
}

// =============================================================================
// Parsing e Stampa Principale
// =============================================================================

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
		long				value;

		std::string arg_check = argv[i];
		if (arg_check.find_first_not_of(' ') == std::string::npos)
		{
			std::cerr << "Error: invalid argument (empty)" << std::endl;
			return false;
		}

		while (ss >> value)
		{
			if (value < 0)
			{
				std::cerr << "Error: not a positive integer: " << value << std::endl;
				return false;
			}
			if (value > 2147483647)
			{
				std::cerr << "Error: number too large: " << value << std::endl;
				return false;
			}
			_vec.push_back(static_cast<int>(value));
			_deq.push_back(static_cast<int>(value));
		}
		if (!ss.eof() || ss.fail())
		{
			ss.clear();
			std::string remaining;
			ss >> remaining;
			if (remaining.find_first_not_of(' ') != std::string::npos)
			{
				std::cerr << "Error: invalid argument " << argv[i] << std::endl;
				return false;
			}
		}
	}
	return true;
}

void	PmergeMe::runSort()
{
	std::cout << "Before: ";
	for (size_t	i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	// Sort per Vector
	long startTimeVec = getTime();
	mergeInsertSort(_vec);
	long endTimeVec = getTime();
	_timeVec = static_cast<double>(endTimeVec - startTimeVec);

	// Sort per Deque
	long startTimeDeq = getTime();
	mergeInsertSort(_deq);
	long endTimeDeq = getTime();
	_timeDeq = static_cast<double>(endTimeDeq - startTimeDeq);

	std::cout << "After: ";
	for (size_t	i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector: " << std::fixed << std::setprecision(5)
			  << _timeVec << " us" << std::endl;

	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque: " << std::fixed << std::setprecision(5)
			  << _timeDeq << " us" << std::endl;
}

// =============================================================================
// Implementazione Pura (VECTOR)
// =============================================================================

void	PmergeMe::binaryInsert(std::vector<int>& S, int element, int max_index)
{
	int low = 0;
	int high = max_index;
	
	if (high >= static_cast<int>(S.size()))
		high = S.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (S[mid] < element)
			low = mid + 1;
		else
			high = mid - 1;
	}
	S.insert(S.begin() + low, element);
}

void	PmergeMe::mergeInsertSort(std::vector<int>& S)
{
	size_t n = S.size();
	if (n < 2)
		return;

	int straggler = -1;
	bool hasStraggler = (n % 2 != 0);
	if (hasStraggler)
	{
		straggler = S.back();
		S.pop_back();
		n--;
	}

	PairVector pairs;
	for (size_t i = 0; i < n; i += 2)
	{
		if (S[i] > S[i + 1])
			pairs.push_back(std::make_pair(S[i], S[i + 1]));
		else
			pairs.push_back(std::make_pair(S[i + 1], S[i]));
	}

	std::vector<int> main_chain;
	for (size_t i = 0; i < pairs.size(); ++i)
		main_chain.push_back(pairs[i].first);

	mergeInsertSort(main_chain); // Ricorsione

	std::vector<int> pend_chain;
	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (main_chain[i] == pairs[j].first)
			{
				pend_chain.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j); 
				break;
			}
		}
	}

	if (!pend_chain.empty())
		main_chain.insert(main_chain.begin(), pend_chain[0]);

	size_t	jacob_idx = 2;
	size_t	inserted = 1;
	size_t	max_pend = pend_chain.size();

	while (inserted < max_pend)
	{
		size_t	end_idx = getJacobsthal(jacob_idx);
		end_idx = std::min(end_idx, max_pend);
		size_t	start_idx = getJacobsthal(jacob_idx - 1);

		for (size_t i = end_idx; i > start_idx; --i)
		{
			if (i - 1 >= pend_chain.size())
				continue;
			int element_to_insert = pend_chain[i - 1];
			int bound = (i - 1) + inserted;
			bound = std::min(static_cast<size_t>(bound), main_chain.size());

			binaryInsert(main_chain, element_to_insert, bound - 1); // bound-1 è l'indice max
			inserted++;
		}
		jacob_idx++;
	}

	if (hasStraggler)
		binaryInsert(main_chain, straggler, main_chain.size() - 1);

	S = main_chain;
}

// =============================================================================
// Implementazione Pura (DEQUE)
// =============================================================================

void	PmergeMe::binaryInsert(std::deque<int>& S, int element, int max_index)
{
	int low = 0;
	int high = max_index;
	
	if (high >= static_cast<int>(S.size()))
		high = S.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (S[mid] < element)
			low = mid + 1;
		else
			high = mid - 1;
	}
	S.insert(S.begin() + low, element);
}

void	PmergeMe::mergeInsertSort(std::deque<int>& S)
{
	size_t n = S.size();
	if (n < 2) return;

	int straggler = -1;
	bool hasStraggler = (n % 2 != 0);
	if (hasStraggler)
	{
		straggler = S.back();
		S.pop_back();
		n--;
	}

	PairDeque pairs;
	for (size_t i = 0; i < n; i += 2)
	{
		if (S[i] > S[i + 1])
			pairs.push_back(std::make_pair(S[i], S[i + 1]));
		else
			pairs.push_back(std::make_pair(S[i + 1], S[i]));
	}

	std::deque<int> main_chain;
	for (size_t i = 0; i < pairs.size(); ++i)
		main_chain.push_back(pairs[i].first);

	mergeInsertSort(main_chain); // Ricorsione

	std::deque<int> pend_chain;
	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (main_chain[i] == pairs[j].first)
			{
				pend_chain.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j); 
				break;
			}
		}
	}

	if (!pend_chain.empty())
		main_chain.insert(main_chain.begin(), pend_chain[0]);

	size_t	jacob_idx = 2;
	size_t	inserted = 1;
	size_t	max_pend = pend_chain.size();

	while (inserted < max_pend)
	{
		size_t	end_idx = getJacobsthal(jacob_idx);
		end_idx = std::min(end_idx, max_pend);
		size_t	start_idx = getJacobsthal(jacob_idx - 1);

		for (size_t i = end_idx; i > start_idx; --i)
		{
			if (i - 1 >= pend_chain.size()) continue;
			int element_to_insert = pend_chain[i - 1];
			int bound = (i - 1) + inserted;
			bound = std::min(static_cast<size_t>(bound), main_chain.size());

			binaryInsert(main_chain, element_to_insert, bound - 1); // bound-1 è l'indice max
			inserted++;
		}
		jacob_idx++;
	}

	if (hasStraggler)
		binaryInsert(main_chain, straggler, main_chain.size() - 1);

	S = main_chain;
}