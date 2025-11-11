#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <string>
# include <algorithm> // Per std::min
# include <cstddef>   // Per size_t
# include <utility>   // Per std::pair
# include <iomanip>   // Per std::setprecision
# include <sys/time.h> // Per gettimeofday

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		double				_timeVec;
		double				_timeDeq;

		// Tipi per le coppie
		typedef std::pair<int, int> Pair;
		typedef std::vector<Pair> PairVector;
		typedef std::deque<Pair> PairDeque;

		// --- Algoritmo per VECTOR ---
		void	mergeInsertSort(std::vector<int>& S);
		void	binaryInsert(std::vector<int>& S, int element, int max_index);

		// --- Algoritmo per DEQUE ---
		void	mergeInsertSort(std::deque<int>& S);
		void	binaryInsert(std::deque<int>& S, int element, int max_index);

		// --- Helper Comune ---
		size_t	getJacobsthal(int n);
		long	getTime(); // Ritorna microsecondi

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();

		bool	inputParse(int argc, char** argv);
		void	runSort();
};

#endif