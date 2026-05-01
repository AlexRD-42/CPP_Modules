/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:28:12 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:29:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

// === Methods ================================================================
void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));	// And there we have it, the first hidden dynamic allocation, aka the first sin
}

// === Canonical Form and Constructors ========================================
Cure::Cure() :
	AMateria("Cure")
{
}

Cure::Cure(const Cure &other) :
	AMateria("Cure")
{
	//*this = other;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		//this->type = other.type;
	}
	return (*this);
}
