/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:02:12 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 17:27:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string	type;

public: // Canonical Form and Constructors
	AMateria();
	~AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	AMateria(const std::string &type);

public: // Methods
	const std::string	&getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#include "ICharacter.hpp"

// Canonical Form and Constructors
AMateria::AMateria(const std::string &type)
{
	
}

AMateria::~AMateria()
{
	
}

AMateria::AMateria()
{
		
}

AMateria& AMateria::operator=(const AMateria& other)
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

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

// Methods
const
std::string	&AMateria::getType() const
{
	
}

void	AMateria::use(ICharacter& target)
{
	
}
