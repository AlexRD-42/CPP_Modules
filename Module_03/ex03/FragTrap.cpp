/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:50:18 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:50:19 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() :
	ClapTrap("Default")
{
	health = 100;
	stamina = 100;
	damage = 30;
	std::cout << "(FragTrap) " << name << " default constructor has been called" << std::endl;
}

FragTrap::FragTrap(std::string input_name) :
	ClapTrap(input_name)
{
	health = 100;
	stamina = 100;
	damage = 30;
	std::cout << "(FragTrap) " << name << " constructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) :
	ClapTrap(other)
{
	std::cout << "(FragTrap) " << name << " copy constructor has been called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "(FragTrap) " << name << " copy assignment operator has been called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "(FragTrap) " << name << " destructor has been called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (health == 0 || stamina == 0)
	{
		std::cout << "(FragTrap) " << name << " cannot attack" << std::endl;
		return ;
	}
	stamina--;
	std::cout << "FragTrap " << name << " headbutts " << target
		<< ", causing " << damage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (health == 0 || stamina == 0)
		return ;
	stamina--;
	std::cout << "(FragTrap) " << name << " is pumped and requests the highest of fives!\n";
}
