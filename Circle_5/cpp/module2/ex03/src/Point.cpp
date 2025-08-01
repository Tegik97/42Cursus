/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:52:09 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 11:52:10 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Point::~Point() {}

const Fixed&	Point::getX() const
{
	return this->_x;
}

const Fixed&	Point::getY() const
{
	return this->_y;
}