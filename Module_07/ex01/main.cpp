/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:52:25 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/29 12:47:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cstddef>

int main()
{
	{
		const size_t length = 8;
		int array[length] = {1, 2, 3, 4, 5, 6, 7, 8};

		std::cout << "Before iter: ";
		iter(array, length, test_const);
		std::cout << "\n";
		std::cout << "After Iter: ";
		iter(array, length, test_mutable);
		iter(array, length, test_const);
		std::cout << "\n";
	}

	{
		const size_t length = 8;
		char array[length] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

		std::cout << "Before iter: ";
		iter(array, length, test_const);
		std::cout << "\nAfter Iter: ";
		iter(array, length, test_mutable);
		iter(array, length, test_const);
		std::cout << "\n";
	}

	{
		const size_t length = 4;
		std::string array[length] = {"apple", "orange", "banana", "berry"};

		std::cout << "Before iter: ";
		iter(array, length, test_const);
		std::cout << "\nAfter Iter: ";
		iter(array, length, test_mutable);
		iter(array, length, test_const);
		std::cout << "\n";
	}

	return (0);
}
