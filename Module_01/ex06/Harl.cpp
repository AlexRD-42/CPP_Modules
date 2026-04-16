/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:56:40 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/16 16:07:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdint.h>
// #include <stddef.h>
#include <string>
#include <iostream>
#include "Harl.hpp"

void	Harl::debug()
{
	static const char	*msg[1] = {
		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
	};

	std::cout << msg[0];
}

void	Harl::info()
{
	static const char	*msg[1] = {
		"I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!\n"};

	std::cout << msg[0];
}

void	Harl::warning()
{
	static const char	*msg[1] = {
		"I think I deserve to have some extra bacon for free. Ive been coming for years, whereas you started working here just last month.\n"};

	std::cout << msg[0];
}

void	Harl::error()
{
	static const char	*msg[1] = {
		"This is unacceptable! I want to speak to the manager now.\n"};

	std::cout << msg[0];
}

void	Harl::complain(std::string level)
{
	static const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*actions[4])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	size_t i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	if (i < 4)
		(this->*actions[i])();
}