/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:50:25 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/04 23:20:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond("Dia");
	DiamondTrap	copy(diamond);
	DiamondTrap	assigned;

	assigned = diamond;
	diamond.whoAmI();
	diamond.attack("target");
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.takeDamage(40);
	diamond.beRepaired(20);
	copy.whoAmI();
	return (0);
}
