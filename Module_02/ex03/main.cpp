/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:14:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/20 11:52:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void runTest(
	const char *name,
	Point const &a,
	Point const &b,
	Point const &c,
	Point const &p,
	bool expected
){
	bool got = bsp(a, b, c, p);

	std::cout << (got == expected ? "[PASS] " : "[FAIL] ")
			  << name
			  << " | expected: " << std::boolalpha << expected
			  << ", got: " << got
			  << "\n";
}

int main(void)
{
	std::cout << std::boolalpha;

	// ------------------------------------------------------------
	// Triangle 1: easy to reason about
	// Inside iff x > 0, y > 0, x + y < 10
	// ------------------------------------------------------------
	Point A(0.0f, 0.0f);
	Point B(10.0f, 0.0f);
	Point C(0.0f, 10.0f);

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

	std::cout << "\n=== Winding order tests ===\n";
	runTest("inside with reversed order", A, C, B, Point(1.0f, 1.0f), true);
	runTest("edge with reversed order", A, C, B, Point(5.0f, 5.0f), false);
	runTest("outside with reversed order", A, C, B, Point(9.0f, 2.0f), false);

	// ------------------------------------------------------------
	// Precision tests for 8 fractional bits
	// Use exact multiples of 1/256
	// ------------------------------------------------------------
	std::cout << "\n=== Fixed-point precision tests (8 fractional bits) ===\n";

	runTest("tiny point inside",
		A, B, C,
		Point(1.0f / 256.0f, 1.0f / 256.0f),
		true);

	runTest("tiny point outside on negative x",
		A, B, C,
		Point(-1.0f / 256.0f, 1.0f / 256.0f),
		false);

	runTest("just inside hypotenuse",
		A, B, C,
		Point(5.0f, 1279.0f / 256.0f),   // 5 + 4.99609375 = 9.99609375
		true);

	runTest("exactly on hypotenuse",
		A, B, C,
		Point(5.0f, 1280.0f / 256.0f),   // 5 + 5 = 10
		false);

	runTest("just outside hypotenuse",
		A, B, C,
		Point(5.0f, 1281.0f / 256.0f),   // 5 + 5.00390625 = 10.00390625
		false);

	// ------------------------------------------------------------
	// Your original triangle
	// ------------------------------------------------------------
	std::cout << "\n=== Your original triangle ===\n";

	Point D(1.0f, 2.0f);
	Point E(5.0f, 6.0f);
	Point F(5.0f, 1.0f);

	runTest("your sample target: (1,3)", D, E, F, Point(1.0f, 3.0f), false);
	runTest("inside: (4,3)",          D, E, F, Point(4.0f, 3.0f), true);
	runTest("inside: (3,3)",          D, E, F, Point(3.0f, 3.0f), true);
	runTest("inside: (4.5,2)",        D, E, F, Point(4.5f, 2.0f), true);
	runTest("outside: (2,1.5)",       D, E, F, Point(2.0f, 1.5f), false);
	runTest("outside: (4,5)",         D, E, F, Point(4.0f, 5.0f), false);
	runTest("on edge x=5",            D, E, F, Point(5.0f, 3.0f), false);
	runTest("on vertex D",            D, E, F, Point(1.0f, 2.0f), false);

	runTest("inside with reversed order", D, F, E, Point(4.0f, 3.0f), true);
	runTest("edge with reversed order",   D, F, E, Point(5.0f, 3.0f), false);

	// ------------------------------------------------------------
	// Degenerate triangles
	// These should always be false
	// ------------------------------------------------------------
	std::cout << "\n=== Degenerate triangle tests ===\n";

	Point G(0.0f, 0.0f);
	Point H(5.0f, 0.0f);
	Point I(10.0f, 0.0f); // collinear with G and H

	runTest("collinear triangle, point on line", G, H, I, Point(7.0f, 0.0f), false);
	runTest("collinear triangle, point off line", G, H, I, Point(7.0f, 1.0f), false);

	Point J(1.0f, 1.0f);
	Point K(1.0f, 1.0f);  // duplicate point
	Point L(2.0f, 2.0f);

	runTest("duplicate vertices", J, K, L, Point(1.5f, 1.5f), false);

	return 0;
}
