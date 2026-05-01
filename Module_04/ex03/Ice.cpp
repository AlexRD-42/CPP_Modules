/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:29:19 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:29:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

// === Methods ================================================================
void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));	// And there we have it, the first hidden dynamic allocation, aka the first sin
}

// === Canonical Form and Constructors ========================================
Ice::Ice() :
	AMateria("ice")
{
}

Ice::Ice(const Ice &other) :
	AMateria("ice")
{
	//*this = other;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		//this->type = other.type;
	}
	return (*this);
}
