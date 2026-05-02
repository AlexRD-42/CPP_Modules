/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:55:16 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/02 14:58:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const int64_t ab = Point::cross(a, b, point);
	const int64_t bc = Point::cross(b, c, point);
	const int64_t ca = Point::cross(c, a, point);

	return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}
