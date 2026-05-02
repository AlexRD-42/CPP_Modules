/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:14:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/02 13:37:58 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void runTest(const char *name, Point const &a, Point const &b, Point const &c, Point const &p, bool expected)
{
	bool got = bsp(a, b, c, p);

	std::cout << (got == expected ? "[PASS] " : "[FAIL] ")
			  << name
			  << " | expected: " << std::boolalpha << expected
			  << ", got: " << got
			  << "\n";
}

int main(void)
{
	Point A(0.0f, 0.0f);
	Point B(10.0f, 0.0f);
	Point C(0.0f, 10.0f);

	std::cout << std::boolalpha;

	std::cout << "=== Basic inside/outside tests ===\n";
	runTest("inside: (1,1)", A, B, C, Point(1.0f, 1.0f), true);
	runTest("inside: (2,3)", A, B, C, Point(2.0f, 3.0f), true);
	runTest("inside: (3,3)", A, B, C, Point(3.0f, 3.0f), true);
	runTest("outside: (-1,1)", A, B, C, Point(-1.0f, 1.0f), false);
	runTest("outside: (1,-1)", A, B, C, Point(1.0f, -1.0f), false);
	runTest("outside: (6,6)", A, B, C, Point(6.0f, 6.0f), false);
	runTest("outside: (9,2)", A, B, C, Point(9.0f, 2.0f), false);

	std::cout << "\n=== Edge tests (must be false) ===\n";
	runTest("on edge AB: (5,0)", A, B, C, Point(5.0f, 0.0f), false);
	runTest("on edge AC: (0,5)", A, B, C, Point(0.0f, 5.0f), false);
	runTest("on edge BC: (5,5)", A, B, C, Point(5.0f, 5.0f), false);

	std::cout << "\n=== Vertex tests (must be false) ===\n";
	runTest("on vertex A", A, B, C, Point(0.0f, 0.0f), false);
	runTest("on vertex B", A, B, C, Point(10.0f, 0.0f), false);
	runTest("on vertex C", A, B, C, Point(0.0f, 10.0f), false);

	return 0;
}
