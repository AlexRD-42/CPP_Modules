/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:20:58 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 13:09:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// first name, last name, nickname, phone number, and darkest secret
#include <cstring>
#include <limits>
#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include "iomanip"
#include "Contacts.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	cur_index_ = 0;
}

// Add, search and exit
int	PhoneBook::read(void)
{
	char	str[8];

	memset(str, 0, sizeof(str));
	std::cin >> std::setw(sizeof(str)) >> str;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::strcmp("ADD", str) == 0)
	{
		add_();
		return (0);
	}
	else if (std::strcmp("SEARCH", str) == 0)
	{
		search_();
		return (0);
	}
	else if (std::strcmp("EXIT", str) == 0)
	{
		std::cout << "Thank you for your data, we will sell it to the highest bidder\n";
		return (1);
	}
	std::cout << "(Invalid command) ";
	return (0);
}

void	PhoneBook::add_(void)
{
	Contacts	new_contact;

	new_contact.add_contact();
	PhoneBook::contacts[cur_index_] = new_contact;
	cur_index_ = (cur_index_ + 1) % 8;
}

void	PhoneBook::search_(void)
{
	size_t		index = SIZE_MAX;
	size_t		j = 0;
	const char	*msg[4] = {
		"I am confident in your capability of typing a number between 0 and 7\n",
		"It really shouldn't be this hard... The number must be between 0 and 7\n",
		"You're not very good at following instructions huh? Select a number between 0 and 7\n",
		"I can do this all day... Type in a number between 0 and the number of days in a week\n"};

	for (size_t i = 0; i < 8; i++)
		PhoneBook::contacts[i].print_short(i);
	std::cout << "Select an index from 0 to 7\n";
	while (true)
	{
		std::cin >> index;
		if (!std::cin.fail() && index <= 7)
			break ;
		std::cout << msg[j];
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		j = (j + 1) % 4;
	}
	PhoneBook::contacts[index].print_long();
}
