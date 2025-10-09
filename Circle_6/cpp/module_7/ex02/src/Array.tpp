/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:00:53 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/09 14:42:34 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	_array = new T[0];
	_size = 0;
}
template<typename T>
Array<T>::Array(unsigned int n)
{
	if (n > static_cast<unsigned int>(std::numeric_limits<int>::max()))
		throw std::invalid_argument("Error: Invalid array size, probably negative number");

	if (n > std::numeric_limits<unsigned int>::max() / sizeof(T))
		throw std::invalid_argument("Error: Array size too big");

	_array = new T[n]();
	_size = n;
}

template<typename T>
Array<T>::Array(const Array<T>& other)
{
	_array = new T[other.size()];

	for (unsigned int i = 0; i < other.size(); i++)
		_array[i] = other._array[i];
	_size = other.size();
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] _array;

		_array = new T[other.size()];
		for (unsigned int i = 0; i < other.size(); i++)
			_array[i] = other._array[i];
		_size = other.size();
	}

	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Error: Index out of bounds");

	return _array[index];
}

template<typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Error: Index out of bounds");

	return _array[index];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}