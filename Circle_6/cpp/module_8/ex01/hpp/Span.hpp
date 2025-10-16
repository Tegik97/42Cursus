#ifndef SPAN_HPP
# define SPAN_HPP

# include <limits>
# include <stdexcept>
# include <vector>
# include <algorithm>

class	Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_vec;
	
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

		template<typename T>
        void    addRange(T first, T last);
};

template<typename T>
void	Span::addRange(T first, T last)
{
	size_t	count = std::distance(first, last);

	if (_vec.size() + count > _maxSize)
		throw std::runtime_error("Error: adding range would exceed max size");
	
	_vec.insert(_vec.end(), first, last);
}

#endif