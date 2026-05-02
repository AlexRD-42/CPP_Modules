/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:37:26 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/02 15:01:01 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define MIN(x, y)	((x) < (y) ? (x) : (y))
#define MAX(x, y)	((x) > (y) ? (x) : (y))

Point::Point() :
	x(0),
	y(0)
{}

Point::~Point()
{}

Point::Point(float xf, float yf) :
	x(xf),
	y(yf)
{}

Point::Point(const Point& other) :
	x(other.x),
	y(other.y)
{}

// But if the values are const how are they reassigned?
Point&	Point::operator=(const Point& other)
{
	if (this != &other)
		(void) other;
	return (*this);
}

int64_t	Point::cross(const Point &p0, const Point &p1, const Point &target)
{
	const int64_t ax = p0.x.getRawBits();
	const int64_t ay = p0.y.getRawBits();
	const int64_t bx = p1.x.getRawBits();
	const int64_t by = p1.y.getRawBits();
	const int64_t tx = target.x.getRawBits();
	const int64_t ty = target.y.getRawBits();

	return ((bx - ax) * (ty - ay) - (by - ay) * (tx - ax));
}
