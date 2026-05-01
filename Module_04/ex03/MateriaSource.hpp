/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:26:33 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:26:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public: // Canonical Form and Constructors
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource& operator=(const MateriaSource &other);

public:
	void		learnMateria(AMateria* materia);
	AMateria*	createMateria(std::string const & type);
	static const size_t	kMaxSlots = 4;

private:
	AMateria*	m_slots[kMaxSlots];
};
