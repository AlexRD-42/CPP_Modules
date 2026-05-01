/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:04:29 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 16:22:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// ========== Constructors ==========================================
Fixed::Fixed()
{
	raw_bits = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int raw_int)
{
	std::cout << "Int constructor called\n";
	raw_bits = raw_int << fractional_bits;
}

Fixed::Fixed(const float raw_float)
{
	std::cout << "Float constructor called\n";

	// t32	mem;
	// mem.f32 = raw_float;
	// mem.u32 += (fractional_bits << 23);			// This can overflow sign bit. Oh well
	// raw_bits = (int32_t)roundf(mem.f32);

	raw_bits = (int32_t)roundf(raw_float * ((float)(1 << fractional_bits)));
}

Fixed::Fixed(const Fixed& other) :
	raw_bits(other.raw_bits)
{
	std::cout << "Copy constructor called\n";
}

// ========== Methods ===============================================

int		Fixed::getRawBits() const
{
	return (raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	raw_bits = raw;
}

float	Fixed::toFloat(void) const
{
	return (((float)raw_bits) / ((float)(1 << fractional_bits)));
}

int	Fixed::toInt(void) const
{
	return (raw_bits >> fractional_bits);
}

// ========== Operators =============================================

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return (*this);
	this->raw_bits = other.raw_bits;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	return (out << fixed.toFloat());
}
