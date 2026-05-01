/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:08:29 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 20:46:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

// === Methods ================================================================
const std::string &Character::getName() const
{
	return (this->m_name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < kMaxSlots; i++)
	{
		if (m_slots[i] == NULL)
		{
			m_slots[i] = m;
			return ;
		}
	}
	// std::cout << "(" << m_name << "): Inventory is full\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;

	if (m_slots[idx] == NULL)
	{
		// std::cout << "(" << m_name << "): There is nothing to unequip\n";
		return ;
	}
	if (m_backpackCount >= MAX_BACKPACK - 1)
	{
		std::cout << "(" << m_name << "): Your backpack is full!\n";
		return ;
	}
	m_backpack[m_backpackCount++] = m_slots[idx];
	m_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || m_slots[idx] == NULL)
		return ;
	m_slots[idx]->use(target);
}

// === Canonical Form and Constructors ========================================
Character::Character() :
	m_slots(),
	m_name("Default"),
	m_backpack(),
	m_backpackCount(0)
{
	for (size_t i = 0; i < kMaxSlots; i++)
		m_slots[i] = NULL;
	for (size_t i = 0; i < MAX_BACKPACK; i++)
		m_backpack[i] = NULL;
}

Character::Character(const std::string name) :
	m_slots(),
	m_name(name),
	m_backpack(),
	m_backpackCount(0)
{
	for (size_t i = 0; i < kMaxSlots; i++)
		m_slots[i] = NULL;
	for (size_t i = 0; i < MAX_BACKPACK; i++)
		m_backpack[i] = NULL;
}

Character::Character(const Character &other) :
	m_slots(),
	m_name(""),
	m_backpack(),
	m_backpackCount(0)
{
	*this = other;
}

Character::~Character()
{
	for (size_t i = 0; i < kMaxSlots; i++)
		delete this->m_slots[i];
	for (size_t i = 0; i < m_backpackCount; i++)
		delete m_backpack[i];
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < MAX_BACKPACK; i++)
		{
			delete(this->m_backpack[i]);
			this->m_backpack[i] = NULL;
		}
		for (size_t i = 0; i < kMaxSlots; i++)
		{
			delete this->m_slots[i];
			if (other.m_slots[i] == NULL)
				this->m_slots[i] = NULL;
			else
				this->m_slots[i] = other.m_slots[i]->clone();	// this is the most convoluted shit i've seen for a simple copy
		}
		this->m_name = other.m_name;
		this->m_backpackCount = other.m_backpackCount;
		for (size_t i = 0; i < m_backpackCount; i++)
			this->m_backpack[i] = other.m_backpack[i]->clone();
	}
	return (*this);
}
