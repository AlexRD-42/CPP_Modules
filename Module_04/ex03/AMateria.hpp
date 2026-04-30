/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:02:12 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/30 19:24:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ICharacter;

class AMateria
{
public: // Canonical Form and Constructors
	AMateria();
	AMateria(std::string const & type);
	virtual ~AMateria() {};
	AMateria(const AMateria &other);
	AMateria& operator=(const AMateria &other);

protected:
	std::string	m_type;

private:
	
public:
	std::string const & getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#include "AMateria.hpp"

// === Methods ================================================================
const
std::string	&AMateria::getType() const
{
	return (this->m_type);
}

void	AMateria::use(ICharacter& target)
{
	// Impossible. Only here because I have no control over the fn prototype
}

// === Canonical Form and Constructors ========================================
AMateria::AMateria() :
	m_type("Default")
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
		this->m_type = other.m_type;
	}
	return (*this);
}
