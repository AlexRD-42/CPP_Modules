/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:02:43 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 15:11:53 by adeimlin         ###   ########.fr       */
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
	johnson->announce();
	delete johnson;
	randomChump("dummy");
	return (0);
}
