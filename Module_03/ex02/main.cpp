/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:49:48 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/04 23:20:25 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	scav("Serena");
	FragTrap	frag("Frank");
	FragTrap	copy(frag);
	FragTrap	assigned;

	assigned = frag;
	scav.attack("target");
	scav.guardGate();
	frag.attack("Martin");
	frag.takeDamage(10);
	frag.beRepaired(10);
	frag.highFivesGuys();
	copy.takeDamage(100);
	copy.highFivesGuys();
	return (0);
}
