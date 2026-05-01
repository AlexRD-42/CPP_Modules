/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:28:18 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:21:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "FragTrap.hpp"

int	main(void)
{
	{
		FragTrap bob("Bob");
		bob.takeDamage(10);
		bob.beRepaired(10);
		bob.attack("Martin");
		bob.highFivesGuys();
	}

	// ScavTrap steve("Steve");

	// for (size_t i = 0; i < 20; i++)
	// 	steve.attack("Bob");
	// std::cout << "Massive Steve combo! And he tries to swing again aaaaand:\n";
	// steve.attack("Bob");
	// std::cout << "If an attack was printed im in trouble\n";
}
