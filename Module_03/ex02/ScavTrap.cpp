/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:49:52 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:49:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() :
	ClapTrap("Default")
{
	health = 100;
	stamina = 50;
	damage = 20;
	std::cout << "(ScavTrap) " << name << " default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(std::string input_name) :
	ClapTrap(input_name)
{
	health = 100;
	stamina = 50;
	damage = 20;
	std::cout << "(ScavTrap) " << name << " constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) :
	ClapTrap(other)
{
	std::cout << "(ScavTrap) " << name << " copy constructor has been called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "(ScavTrap) " << name << " copy assignment operator has been called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "(ScavTrap) " << name << " destructor has been called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (health == 0 || stamina == 0)
	{
		std::cout << "(ScavTrap) " << name << " cannot attack" << std::endl;
		return ;
	}
	stamina--;
	std::cout << "(ScavTrap) " << name << " kicks " << target
		<< ", causing " << damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
