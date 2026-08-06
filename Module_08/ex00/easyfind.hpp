/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:11:39 by adeimlin          #+#    #+#             */
/*   Updated: 2026/08/06 11:56:58 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T& data, int value)
{
	typename T::iterator it = std::find(data.begin(), data.end(), value);

	if (it == data.end())
		throw std::runtime_error("Value not found");
	return (it);
}

template<typename T>
void print(T& data, int value)
{
	try
	{
		typename T::iterator it = easyfind(data, value);
		(void) it;
		std::cout << value << " was found\n";
	}
	catch(const std::exception& e)
	{
		std::cout << value << " was not found\n";
	}
}
