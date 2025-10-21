/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:34:17 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/21 13:34:18 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n)
{
	if (n > static_cast<unsigned int>(std::numeric_limits<int>::max()))
		throw std::invalid_argument("Error: Invalid size, probably negative number");

	_maxSize = n;
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _vec(other._vec) {}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_vec = other._vec;
	}
	
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_vec.size() >= _maxSize)
		throw std::runtime_error("Error: max size reached, can't add more numbers");

	_vec.push_back(n);
}

int	Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::runtime_error("Error: not enough elements in the container");

	std::vector<int>	sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	int	minSpan = std::numeric_limits<int>::max();

	std::vector<int>::iterator it = sorted.begin();
	++it;
	for (; it != sorted.end(); ++it)
	{
		int	span = *it - *(it - 1);
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

int	Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::runtime_error("Error: not enough elements in the container");

	int	max = *std::max_element(_vec.begin(), _vec.end());
	int	min = *std::min_element(_vec.begin(), _vec.end());

	return max - min;
}
