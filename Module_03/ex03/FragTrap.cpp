/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:38:23 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/22 18:32:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name) :
	ClapTrap(_name)
{
	health = 100;
	stamina = 100;
	damage = 30;
	std::cout << "(FragTrap) " << _name << " constructor has been called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "(FragTrap) " << name << " destructor has been called\n";
}

void	FragTrap::attack(const std::string& target)
{
	if (health == 0 || stamina == 0)
		return ;
	stamina--;
	std::cout << "(FragTrap) " << name << " headbutts " << target << ", causing " << damage << " damage\n";
}

void	FragTrap::highFivesGuys()
{
	if (health == 0 || stamina == 0)
		return ;
	stamina--;
	std::cout << "(FragTrap) " << name << " is pumped and requests the highest of fives!\n";
}
