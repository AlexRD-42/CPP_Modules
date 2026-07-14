/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:33:09 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/30 12:48:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main()
{
	{
		std::vector<int> int_array;
	
		int_array.push_back(1);
		int_array.push_back(5);
		int_array.push_back(6);
		print(int_array, 1);
		print(int_array, 5);
		print(int_array, 6);
		print(int_array, 7);
	}

	{
		std::list<int> int_list;

		int_list.push_back(1);
		int_list.push_back(5);
		int_list.push_back(6);
		print(int_list, 1);
		print(int_list, 5);
		print(int_list, 6);
		print(int_list, 7);
	}

	return (0);
}