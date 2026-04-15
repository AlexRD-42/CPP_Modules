/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:02:43 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 15:39:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main()
{
	Zombie mark("mark the strong");
	Zombie* johnson = newZombie("johnson the second");
	{
		Zombie steve("steve the first");
	}
	delete johnson;
	randomChump("dummy");
	return (0);
}
