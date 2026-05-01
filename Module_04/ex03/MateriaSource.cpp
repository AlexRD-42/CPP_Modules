/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:25:57 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:26:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// === Methods ================================================================
void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL)
		return ;
	for (size_t i = 0; i < kMaxSlots; i++)
	{
		if (m_slots[i] == NULL)
		{
			m_slots[i] = materia->clone();
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria	*src;

	for (size_t i = 0; i < kMaxSlots; i++)
	{
		src = m_slots[i];
		if (src != NULL && src->getType() == type)
			return (src->clone());
	}
	return (NULL);
}

// === Canonical Form and Constructors ========================================
MateriaSource::MateriaSource() :
	m_slots()
{
	for (size_t i = 0; i < kMaxSlots; i++)
		m_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) :
	m_slots()
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < kMaxSlots; i++)
		delete this->m_slots[i];	
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < kMaxSlots; i++)
		{
			delete this->m_slots[i];
			if (other.m_slots[i] == NULL)
				this->m_slots[i] = NULL;
			else
				this->m_slots[i] = other.m_slots[i]->clone();
		}
	}
	return (*this);
}
