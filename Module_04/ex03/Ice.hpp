/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:17:06 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:29:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

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
