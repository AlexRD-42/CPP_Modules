/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:14:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 19:59:31 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <string>
#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Variable address:\t" << &str << std::endl;
	std::cout << "Pointer address:\t" << &stringPTR << std::endl;
	std::cout << "Reference address:\t" << &stringREF << std::endl;

	std::cout << "Variable address:\t" << str << std::endl;
	std::cout << "Pointer address:\t" << stringPTR << std::endl;
	std::cout << "Reference address:\t" << stringREF << std::endl;
}
