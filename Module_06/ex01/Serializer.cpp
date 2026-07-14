/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:32:23 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/17 17:35:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// === Methods ================================================================
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

// === Canonical Form and Constructors ========================================
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer::~Serializer()
{
}

Serializer& Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
	}
	return (*this);
}
