/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:33:32 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 12:04:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "Insert the command\n";
		if (phonebook.read())
			break ;
	}
	return (0);
}
