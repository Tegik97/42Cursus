/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:28:41 by mchiaram          #+#    #+#             */
/*   Updated: 2025/11/26 11:28:42 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		void	mergeInsertSort(std::vector<int>& vec);
		void	binaryInsert(std::vector<int>& vec, int element, int max_index);

		void	mergeInsertSort(std::deque<int>& deq);
		void	binaryInsert(std::deque<int>& deq, int element, int max_index);

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