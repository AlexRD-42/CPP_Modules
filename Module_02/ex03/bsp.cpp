/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:55:16 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/20 11:51:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcore.hpp"
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (Point::_bsp(a, b, c, point));
}
