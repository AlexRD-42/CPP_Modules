/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:14:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 15:47:48 by adeimlin         ###   ########.fr       */
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

	Harl		harl;
	std::string	level = argv[1];
	int			n = 0;
	while (n < 4 && levels[n] != level)
		n++;
	switch (n)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			harl.complain("DEBUG");
			/* fall through */
		case 1:
			std::cout << "[ INFO ]\n";
			harl.complain("INFO");
			/* fall through */
		case 2:
			std::cout << "[ WARNING ]\n";
			harl.complain("WARNING");
			/* fall through */
		case 3:
			std::cout << "[ ERROR ]\n";
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
