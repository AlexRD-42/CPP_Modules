/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:49:13 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/04 23:12:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Clappy");
	ScavTrap	bob("Bob");
	ScavTrap	copy(bob);
	ScavTrap	assigned;

	assigned = bob;
	clap.attack("target");
	bob.attack("Martin");
	bob.takeDamage(10);
	bob.beRepaired(10);
	bob.guardGate();
	copy.takeDamage(100);
	copy.attack("Martin");
	return (0);
}
