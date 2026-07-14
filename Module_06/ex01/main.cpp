/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:39:18 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/17 17:39:45 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "example";

	Data* original = &data;

	uintptr_t raw = Serializer::serialize(original);
	Data* converted = Serializer::deserialize(raw);

	std::cout << "original:  " << original << std::endl;
	std::cout << "raw:       " << raw << std::endl;
	std::cout << "converted: " << converted << std::endl;

	if (original == converted)
		std::cout << "Pointers are equal" << std::endl;
	else
		std::cout << "Pointers are different" << std::endl;

	std::cout << "converted id: " << converted->id << std::endl;
	std::cout << "converted name: " << converted->name << std::endl;

	return 0;
}
