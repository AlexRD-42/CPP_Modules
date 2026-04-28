/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:44:52 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/27 12:54:29 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::~DiamondTrap()
{
}

DiamondTrap::DiamondTrap() : 
	ClapTrap("Default_clap_name"),
	FragTrap("Default"),
	ScavTrap("Default")
{	
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	name(name)
{
	this->health = FragTrap::health;
	this->stamina = ScavTrap::stamina;
	this->damage = FragTrap::damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->stamina = other.stamina;
		this->health = other.health;
		this->damage = other.damage;
	}
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : 
	ClapTrap("Default_clap_name"),
	FragTrap("Default"),
	ScavTrap("Default")
{
	*this = other;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << DiamondTrap::name << "\n";
	std::cout << "ClapTrap name: " << ClapTrap::name << "\n";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}