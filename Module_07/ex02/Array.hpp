/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:56:31 by adeimlin          #+#    #+#             */
/*   Updated: 2026/08/06 11:42:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>

template <typename Type>
class Array
{
private:
	Type *arrayPtr;
	size_t length;

public: // Canonical Form and Constructors
	Array() :
	length(0)
	{
		arrayPtr = NULL;
	}

	Array(unsigned int n) :
	length(n)
	{
		if (length == 0)
			arrayPtr = NULL;
		else
		{
			arrayPtr = new Type[n]();
		}
	}

	Array(const Array &other) :
	length(other.length)
	{
		arrayPtr = new Type[length];
		for (size_t i = 0; i < length; i++)
			arrayPtr[i] = other.arrayPtr[i];	// Could have used subscript overload
	}

	~Array()
	{
		delete[] arrayPtr;
	}

	Array& operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] this->arrayPtr;
			this->arrayPtr = NULL;
			this->length = 0;
			if (other.length == 0)
				return *this;
			this->arrayPtr = new Type[other.length];
			this->length = other.length;
			for (size_t i = 0; i < length; i++)
				arrayPtr[i] = other.arrayPtr[i];
		}
		return *this;
	}

	const Type& operator[](unsigned int n) const
	{
		if (n >= length)
			throw std::out_of_range("Index out of range");;
		return arrayPtr[n];
	}

	Type& operator[](unsigned int n)
	{
		if (n >= length)
			throw std::out_of_range("Index out of range");;
		return arrayPtr[n];
	}

	size_t size() const
	{
		return length;
	}
};
