/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:36:24 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 17:29:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public: // Canonical Form and Constructors
	Cure();
	~Cure() {};
	Cure(const Cure &other);
	Cure& operator=(const Cure &other);

private:

public:
	void		use(ICharacter& target);	// Cannot override because we're using ice age C++98 version
	AMateria*	clone() const;
};
