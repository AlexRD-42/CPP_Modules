/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:44:05 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:23:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_BACKPACK 32

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
	AMateria 	*m_backpack[MAX_BACKPACK];
	size_t		m_backpackCount;
};
