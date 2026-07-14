/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:52:20 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/29 12:54:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>

template <typename Type>
void iter(Type *arrayPtr, const size_t length, void (*fn)(Type&))
{
	for (size_t i = 0; i < length; i++)
		fn(arrayPtr[i]);
}

// why does arrayptr need to be const here to not be ambiguous?
template <typename Type>
void iter(const Type *arrayPtr, const size_t length, void (*fn)(const Type&))
{
	for (size_t i = 0; i < length; i++)
		fn(arrayPtr[i]);
}


	// if (dynamic_cast<std::string&>(var))
template <typename Type>
void test_mutable(Type &var)
{
	var += 1;
}

template <typename Type>
void test_const(const Type &var)
{
	std::cout << var << " ";
}
