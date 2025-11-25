#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <string>
# include <algorithm>
# include <cstddef>
# include <utility>
# include <iomanip>
# include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		double				_timeVec;
		double				_timeDeq;

		typedef std::pair<int, int> Pair;
		typedef std::vector<Pair> PairVector;
		typedef std::deque<Pair> PairDeque;

		void	mergeInsertSort(std::vector<int>& S);
		void	binaryInsert(std::vector<int>& S, int element, int max_index);

		void	mergeInsertSort(std::deque<int>& S);
		void	binaryInsert(std::deque<int>& S, int element, int max_index);

		size_t	getJacobsthal(int n);
		long	getTime();

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();

		bool	inputParse(int argc, char** argv);
		void	runSort();
};

#endif