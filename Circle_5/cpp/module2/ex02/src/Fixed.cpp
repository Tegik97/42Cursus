/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:51:46 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 11:51:47 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const Fixed& other)
{
	this->_rawBits = other._rawBits;
}

Fixed::Fixed(const int value)
{
	this->_rawBits = value << this->_fracBits;
}

Fixed::Fixed(const float value)
{
	this->_rawBits = static_cast<int>(roundf(value * (1 << this->_fracBits)));
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat() const
{
    return static_cast<float>(this->_rawBits) / (1 << this->_fracBits);
}

int	Fixed::toInt() const
{
	return this->_rawBits / (1 << this->_fracBits);
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return this->_rawBits > other._rawBits;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->_rawBits < other._rawBits;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->_rawBits >= other._rawBits;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->_rawBits <= other._rawBits;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->_rawBits == other._rawBits;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->_rawBits != other._rawBits;
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_rawBits * other._rawBits) >> this->_fracBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_rawBits << this->_fracBits) / other._rawBits);
	return result;
}

Fixed&	Fixed::operator++()
{
	++this->_rawBits;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++this->_rawBits;
	return temp;
}

Fixed&	Fixed::operator--()
{
	--this->_rawBits;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--this->_rawBits;
	return temp;
}

Fixed&	Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1._rawBits < n2._rawBits)
		return n1;
	else
		return n2;
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1._rawBits < n2._rawBits)
		return n1;
	else
		return n2;
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1._rawBits > n2._rawBits)
		return n1;
	else
		return n2;
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1._rawBits > n2._rawBits)
		return n1;
	else
		return n2;
}