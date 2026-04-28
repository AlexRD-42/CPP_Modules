/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:14:58 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/22 15:23:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string _name) :
	name(_name),
	health(10),
	stamina(10),
	damage(0)
{
	std::cout << "(ClapTrap) " << _name << " constructor has been called\n";
}

// ClapTrap::ClapTrap(std::string _name, uint _health, uint _stamina, uint _damage) :
// 	name(_name),
// 	health(_health),
// 	stamina(_stamina),
// 	damage(_damage)
// {
// 	std::cout << "(ClapTrap) " << _name << " constructor has been called\n";
// }

ClapTrap::~ClapTrap()
{
	std::cout << "(ClapTrap) " << name << " destructor has been called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (health == 0 || stamina == 0)
		return ;
	stamina--;
	std::cout << "(ClapTrap) " << name
		<< " attacks " << target << ", causing " << damage << " damage\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (health == 0)
		return ;
	if (health > amount)
	{
		health -= amount;
		std::cout << "(ClapTrap) " << name << " loses " << amount << " hitpoints\n";
	}
	else
	{
		health = 0;
		std::cout << "(ClapTrap) " << name << " loses " << amount << " hitpoints (FATAL)\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (health == 0 || stamina == 0)
		return ;
	stamina--;
	health += amount;
	std::cout << "(ClapTrap) " << name << " gains " << amount << " hitpoints\n";
}
