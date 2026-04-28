/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:37:26 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/22 12:53:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcore.hpp"
#include "Point.hpp"

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
	// if (this == &other)
	// 	return (*this);
	// return (other);
}

int32_t	Point::lerp(const Point &p0, const Point &p1, int32_t xt)
{
	const int32_t	x0 = p0.x.getRawBits();
	const int32_t	y0 = p0.y.getRawBits();
	const int32_t	dy = p1.y.getRawBits() - y0;
	const int32_t	dx = p1.x.getRawBits() - x0;
	int64_t			yt;
	int64_t			k;

	k = y0 - ((int64_t)dy * x0) / dx;
	yt = ((int64_t)xt * dy) / dx  + k;
	return ((int32_t) yt);
}

bool	Point::within_dx(const Point &p0, const Point &p1, const Point &target)
{
	const int32_t	xt = target.x.getRawBits();
	const int32_t	x0 = p0.x.getRawBits();
	const int32_t	x1 = p1.x.getRawBits();

	return (xt > MIN(x0, x1) && xt < MAX(x0, x1));
}

// This is so stupid. Because they force the variables to be private, you can't access raw bits
// directly, so you'd have to create the getter of a getter and I refuse to do that.
// Instead I create a method bsp so you get direct access to the private members, so some form of sanity is preserved
bool	Point::_bsp(Point const a, Point const b, Point const c, Point const point)
{
	const int32_t	xt = point.x.getRawBits();
	const int32_t	yt = point.y.getRawBits();
	int32_t			y[2];
	size_t			count;

	count = 0;
	if (Point::within_dx(a, b, point))
	{
		y[count] = Point::lerp(a, b, xt);
		count++;
	}
	if (Point::within_dx(b, c, point))
	{
		y[count] = Point::lerp(b, c, xt);
		count++;
	}
	if (Point::within_dx(a, c, point))
	{
		if (count != 1)
			return (false);
		y[count] = Point::lerp(a, c, xt);
		count++;
	}
	if (count != 2)
		return (false);
	return (yt > MIN(y[0], y[1]) && yt < MAX(y[0], y[1]));
}
