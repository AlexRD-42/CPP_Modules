/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:50:11 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:50:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() :
	ClapTrap("Default_clap_name"),
	FragTrap("Default"),
	ScavTrap("Default"),
	name("Default")
{
	health = 100;
	stamina = 50;
	damage = 30;
	std::cout << "(DiamondTrap) " << name << " default constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string input_name) :
	ClapTrap(input_name + "_clap_name"),
	FragTrap(input_name),
	ScavTrap(input_name),
	name(input_name)
{
	health = 100;
	stamina = 50;
	damage = 30;
	std::cout << "(DiamondTrap) " << name << " constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	FragTrap(other),
	ScavTrap(other),
	name(other.name)
{
	std::cout << "(DiamondTrap) " << name << " copy constructor has been called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	std::cout << "(DiamondTrap) " << name << " copy assignment operator has been called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "(DiamondTrap) " << name << " destructor has been called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
