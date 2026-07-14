/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:51:09 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/17 17:51:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int choice = std::rand() % 3;

	if (choice == 0)
	{
		std::cout << "Generated: A" << std::endl;
		return new A;
	}
	else if (choice == 1)
	{
		std::cout << "Generated: B" << std::endl;
		return new B;
	}
	std::cout << "Generated: C" << std::endl;
	return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...)
	{
	}
	std::cout << "Unknown" << std::endl;
}

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 10; ++i)
	{
		Base* p = generate();

		std::cout << "Pointer identification:   ";
		identify(p);
		std::cout << "Reference identification: ";
		identify(*p);
		delete p;
		std::cout << std::endl;
	}
	return 0;
}
