/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:14:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/02 14:08:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void check(std::string name, bool got, bool expected)
{
	if (got == expected)
		std::cout << "[OK] " << name << std::endl;
	else
		std::cout << "[FAIL] " << name
				  << " | got " << got
				  << " expected " << expected << std::endl;
}

int main(void)
{
	std::cout << "Basic triangle:" << std::endl;
	{
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 10);

		check("inside simple triangle", bsp(a, b, c, Point(1, 1)), true);
		check("outside simple triangle", bsp(a, b, c, Point(10, 10)), false);
		check("on vertex a", bsp(a, b, c, Point(0, 0)), false);
		check("on vertex b", bsp(a, b, c, Point(10, 0)), false);
		check("on vertex c", bsp(a, b, c, Point(0, 10)), false);
		check("on horizontal edge", bsp(a, b, c, Point(5, 0)), false);
		check("on vertical edge", bsp(a, b, c, Point(0, 5)), false);
		check("on diagonal edge", bsp(a, b, c, Point(5, 5)), false);
	}

	std::cout << std::endl << "Same triangle, reversed order:" << std::endl;
	{
		Point a(0, 0);
		Point b(0, 10);
		Point c(10, 0);

		check("inside reversed triangle", bsp(a, b, c, Point(1, 1)), true);
		check("outside reversed triangle", bsp(a, b, c, Point(10, 10)), false);
		check("on vertical edge reversed", bsp(a, b, c, Point(0, 5)), false);
		check("on diagonal edge reversed", bsp(a, b, c, Point(5, 5)), false);
	}

	std::cout << std::endl << "Triangle where scanline passes through vertex:" << std::endl;
	{
		Point a(0, 0);
		Point b(5, 10);
		Point c(10, 0);

		check("inside below top vertex", bsp(a, b, c, Point(5, 5)), true);
		check("top vertex itself", bsp(a, b, c, Point(5, 10)), false);
		check("base edge", bsp(a, b, c, Point(5, 0)), false);
		check("outside above top vertex", bsp(a, b, c, Point(5, 11)), false);
		check("outside left", bsp(a, b, c, Point(-1, 1)), false);
		check("outside right", bsp(a, b, c, Point(11, 1)), false);
	}

	std::cout << std::endl << "Non-axis-aligned triangle:" << std::endl;
	{
		Point a(-3, -2);
		Point b(4, 1);
		Point c(1, 7);

		check("inside slanted triangle", bsp(a, b, c, Point(1, 2)), true);
		check("outside slanted triangle", bsp(a, b, c, Point(5, 5)), false);
		check("vertex slanted triangle", bsp(a, b, c, Point(-3, -2)), false);
	}

	std::cout << std::endl << "Small fixed-point coordinates:" << std::endl;
	{
		Point a(0.0f, 0.0f);
		Point b(2.5f, 0.0f);
		Point c(0.0f, 2.5f);

		check("inside fractional triangle", bsp(a, b, c, Point(0.5f, 0.5f)), true);
		check("outside fractional triangle", bsp(a, b, c, Point(2.0f, 2.0f)), false);
		check("on fractional edge", bsp(a, b, c, Point(1.25f, 0.0f)), false);
	}

	return 0;
}
