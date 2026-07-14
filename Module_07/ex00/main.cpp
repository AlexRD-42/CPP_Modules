/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:41:32 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/29 11:51:15 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main()
{
	{
		int x = 42;
		int y = -1;
		std::cout << "AB Values before swap: " << x << " , "<< y << "\n";
		swap(x, y);
		std::cout << "AB Values after swap: " << x << " , "<< y << "\n";
		std::cout << "MIN, MAX: " << min(x, y) << " , "<< max(x, y) << "\n";
	}
	std::cout << "====================\n";
	{
		std::string x = "apples";
		std::string y = "oranges";
		std::cout << "AB Values before swap: " << x << " , "<< y << "\n";
		swap(x, y);
		std::cout << "AB Values after swap: " << x << " , "<< y << "\n";
		std::cout << "MIN, MAX: " << min(x, y) << " , "<< max(x, y) << "\n";
	}
	std::cout << "====================\n";
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return (0);
}
