/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:02:43 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/22 12:39:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static inline
void	stt_print_upper(const char *arg)
{
	std::string	str = arg;
	size_t		length = str.length();

	for (size_t i = 0; i < length; i++)
		str[i] = toupper(str[i]);
	std::cout << str;
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}

	for (size_t i = 1; i < (size_t)argc; i++)
		stt_print_upper(argv[i]);
	std::cout << "\n";
	return (0);
}
