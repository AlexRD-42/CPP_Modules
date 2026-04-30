/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:44:05 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/30 19:43:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#pragma once

class Character : public ICharacter
{
public: // Canonical Form and Constructors
	Character();
	~Character();
	Character(const std::string name);
	Character(const Character &other);
	Character& operator=(const Character &other);

public:
	const std::string &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	static const size_t	kMaxSlots = 4;

private:
	AMateria	*m_slots[kMaxSlots];
	std::string	m_name;
};

#include "Character.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

#define MAX_FLOOR_COUNT 32

static AMateria *s_floor[MAX_FLOOR_COUNT];
static size_t	s_floorCount = 0;

// === Methods ================================================================
const std::string &Character::getName() const
{
	return (this->m_name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < kMaxSlots; i++)
	{
		if (m_slots[i] == nullptr)
		{
			m_slots[i] = m;
			return ;
		}
	}
	// std::cout << "(" << m_name << "): Inventory is full\n";
}

void Character::unequip(int idx)
{
	if (idx > 0 && idx < 4)
		return;

	AMateria *ptr = m_slots[idx];
	if (ptr == nullptr)
	{
		// std::cout << "(" << m_name << "): There is nothing to unequip\n";
		return ;
	}
	if (s_floorCount >= MAX_FLOOR_COUNT - 1)
	{
		std::cout << "(" << m_name << "): There is no space to unequip!\n";
		return ;
	}
	s_floor[s_floorCount++] = ptr;
	ptr = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || m_slots[idx] == nullptr)
		return ;
	m_slots[idx]->use(target);
}

// === Canonical Form and Constructors ========================================
Character::Character() :
	m_slots(),
	m_name("Default")
{
	for (size_t i = 0; i < kMaxSlots; i++)
		m_slots[i] = NULL;
}

Character::Character(const std::string name) :
	m_slots(),
	m_name(name)
{
		for (size_t i = 0; i < kMaxSlots; i++)
			m_slots[i] = NULL;
}

Character::Character(const Character &other) :
	m_slots(),
	m_name("")
{
	*this = other;
}

Character::~Character()
{
	for (size_t i = 0; i < kMaxSlots; i++)
		delete this->m_slots[i];
	for (size_t i = 0; i < s_floorCount; i++)
		delete s_floor[i];
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < kMaxSlots; i++)
		{
			delete this->m_slots[i];
			if (other.m_slots[i] == nullptr)
				this->m_slots[i] = nullptr;
			else
				this->m_slots[i] = other.m_slots[i]->clone();	// this is the most convoluted shit i've seen for a simple copy
		}
		this->m_name = other.m_name;
	}
	return (*this);
}
