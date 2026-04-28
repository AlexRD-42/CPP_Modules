/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:38:23 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/22 18:32:05 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name) :
	ClapTrap(_name)
{
	health = 100;
	stamina = 50;
	damage = 20;
	std::cout << "(ScavTrap) " << _name << " constructor has been called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "(ScavTrap) " << name << " destructor has been called\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (health == 0 || stamina == 0)
		return ;
	stamina--;
	std::cout << "(ScavTrap) " << name << " kicks " << target << ", causing " << damage << " damage\n";
}

void	ScavTrap::guardGate()
{
	if (health == 0 || stamina == 0)
		return ;
	stamina--;
	std::cout << "(ScavTrap) " << name << " is now in Gate Keeper mode!\n";
}