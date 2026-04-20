/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:37:48 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/20 11:52:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x, y;

public:
	Point();
	Point(float x, float y);
	Point(const Point& other);
	~Point();

	Point& operator=(const Point& other);
	static int32_t	lerp(const Point &p0, const Point &p1, int32_t xt);
	static bool		within_dx(const Point &p0, const Point &p1, const Point &target);
	static bool		_bsp(Point const a, Point const b, Point const c, Point const point);
};
#endif