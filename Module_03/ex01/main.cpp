/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:28:18 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/22 15:30:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "ftcore.hpp"

int	main(void)
{
	{
		ScavTrap bob("Bob");
		bob.takeDamage(10);
		bob.beRepaired(10);
		bob.attack("Martin");
		bob.guardGate();
	}

	// ScavTrap steve("Steve");

	// for (size_t i = 0; i < 20; i++)
	// 	steve.attack("Bob");
	// std::cout << "Massive Steve combo! And he tries to swing again aaaaand:\n";
	// steve.attack("Bob");
	// std::cout << "If an attack was printed im in trouble\n";
}
