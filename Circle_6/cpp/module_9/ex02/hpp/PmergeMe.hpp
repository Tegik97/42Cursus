#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <cstddef>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		void	sortVector(int recursion_level);
		void	binaryVectInsertion(size_t pair_size);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();

		bool	inputParse(int argc, char** argv);
		void	printSortedVector();
};

#endif