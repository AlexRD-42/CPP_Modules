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

#include "MateriaSource.hpp"

// === Methods ================================================================
void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == nullptr)
		return ;
	for (size_t i = 0; i < kMaxSlots; i++)
	{
		if (m_slots[i] == nullptr)
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
		if (src != nullptr && src->getType() == type)
			return (src->clone());
	}
	return (nullptr);
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
			if (other.m_slots[i] == nullptr)
				this->m_slots[i] = nullptr;
			else
				this->m_slots[i] = other.m_slots[i]->clone();
		}
	}
	return (*this);
}
