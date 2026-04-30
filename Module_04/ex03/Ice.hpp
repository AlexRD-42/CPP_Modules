/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:17:06 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/30 18:32:00 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
public: // Canonical Form and Constructors
	Ice();
	~Ice() {};
	Ice(const Ice &other);
	Ice& operator=(const Ice &other);

private:

public:
	void		use(ICharacter& target);	// Cannot override because we're using ice age C++98 version
	AMateria*	clone() const;
};

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
