/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:14:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/16 16:14:01 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	static const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (0);
	}

	Harl 		harl;
	std::string	level = argv[1];
	size_t 		n = 0;
	while (n < 4 && levels[n] != level)
		n++;
	if (n == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (0);
	}
	for (size_t i = 0; i <= n; i++)
		harl.complain(levels[i]);
	return (0);
}
