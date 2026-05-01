/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:08:11 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 20:48:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// === Methods ================================================================
const
std::string	&AMateria::getType() const
{
	return (this->m_type);
}

void	AMateria::use(ICharacter& target)
{
	(void) target;
	// Impossible. Only here because I have no control over the fn prototype
}

// === Canonical Form and Constructors ========================================
AMateria::AMateria() :
	m_type("Default")
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const std::string &type) :
	m_type(type)
{
}

AMateria::AMateria(const AMateria &other) :
	m_type("")
{
	*this = other;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		//this->m_type = other.m_type;
	}
	return (*this);
}
