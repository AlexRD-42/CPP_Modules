/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:49:04 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:49:05 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
	name("Default"),
	health(10),
	stamina(10),
	damage(0)
{
	std::cout << "(ClapTrap) " << name << " default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string input_name) :
	name(input_name),
	health(10),
	stamina(10),
	damage(0)
{
	std::cout << "(ClapTrap) " << name << " constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	name(other.name),
	health(other.health),
	stamina(other.stamina),
	damage(other.damage)
{
	std::cout << "(ClapTrap) " << name << " copy constructor has been called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		health = other.health;
		stamina = other.stamina;
		damage = other.damage;
	}
	std::cout << "(ClapTrap) " << name << " copy assignment operator has been called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "(ClapTrap) " << name << " destructor has been called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (health == 0 || stamina == 0)
	{
		std::cout << "(ClapTrap) " << name << " cannot attack" << std::endl;
		return ;
	}
	stamina--;
	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (health == 0)
	{
		std::cout << "(ClapTrap) " << name << " is already destroyed" << std::endl;
		return ;
	}
	if (health > amount)
		health -= amount;
	else
		health = 0;
	std::cout << "ClapTrap " << name << " takes " << amount
		<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (health == 0 || stamina == 0)
	{
		std::cout << "(ClapTrap) " << name << " cannot be repaired" << std::endl;
		return ;
	}
	stamina--;
	health += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
		<< " hit points!" << std::endl;
}
