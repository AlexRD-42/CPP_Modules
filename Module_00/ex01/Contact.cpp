/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:52:33 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/20 12:34:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include <iomanip>
#include <limits>

#include "Contact.hpp"

Contact::Contact(void)
{
	memset(Contact::first_name, 0, 32);
	memset(Contact::last_name, 0, 32);
	memset(Contact::nickname, 0, 32);
	memset(Contact::phone, 0, 32);
	memset(Contact::secret, 0, 32);
}

static
size_t	stt_read_input(const char *msg, char *dst, size_t length)
{
	size_t	str_len = 0;

	while (true)
	{
		memset(dst, 0, length);
		std::cout << msg;
		std::cin.getline(dst, (long)length);
		str_len = strlen(dst);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (str_len != 0)
			break ;
		std::cout << "An empty field is invalid, please try again\n";
	}
	return (str_len);
}

void	Contact::add_contact(void)
{
	stt_read_input("Insert the first name:\n", Contact::first_name, 32);
	stt_read_input("Insert the last name:\n", Contact::last_name, 32);
	stt_read_input("Insert the nickname:\n", Contact::nickname, 32);
	stt_read_input("Insert the phone number:\n", Contact::phone, 32);
	stt_read_input("Insert the darkest secret:\n", Contact::secret, 32);
}

static
void	stt_print_trunc(const char *src)
{
	char	buffer[16];
	size_t	length = strlen(src);

	memset(buffer, 0, 16);
	if (length > 10)
	{
		memcpy(buffer, src, 9);
		buffer[9] = '.';
	}
	else
		memcpy(buffer, src, length);
	std::cout << std::setw(10) << std::right << buffer;
}

void	Contact::print_short(size_t index)
{
	std::cout << std::setw(10) << std::right << index;
	std::cout << "|";
	stt_print_trunc(Contact::first_name);
	std::cout << "|";
	stt_print_trunc(Contact::last_name);
	std::cout << "|";
	stt_print_trunc(Contact::nickname);
	std::cout << std::endl;
}

void	Contact::print_long()
{
	if (Contact::first_name[0] == 0)
	{
		std::cout << "That contact does not exist yet\n";
		return ;
	}
	std::cout << Contact::first_name << std::endl;
	std::cout << Contact::last_name << std::endl;
	std::cout << Contact::nickname << std::endl;
	std::cout << Contact::phone << std::endl;
	std::cout << Contact::secret << std::endl;
}
