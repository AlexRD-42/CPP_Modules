/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:04:29 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/17 15:53:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ftcore.hpp"
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const
Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const
Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

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
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	return (out << fixed.toFloat());
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return (*this);
	this->raw_bits = other.raw_bits;
	return (*this);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->raw_bits > other.raw_bits);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->raw_bits < other.raw_bits);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->raw_bits >= other.raw_bits);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->raw_bits <= other.raw_bits);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->raw_bits == other.raw_bits);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->raw_bits != other.raw_bits);	
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.raw_bits = this->raw_bits + other.raw_bits;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.raw_bits = this->raw_bits - other.raw_bits;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	int64_t	value;

	value = (int64_t)this->raw_bits * other.raw_bits;
	value >>= fractional_bits;
	result.raw_bits = (int32_t)value;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	int64_t	value;
	Fixed	result;

	value = (int64_t)this->raw_bits << fractional_bits;
	value /= other.raw_bits;
	result.raw_bits = (int32_t)value;
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	this->raw_bits += 1;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->raw_bits -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;

	this->raw_bits += 1;
	return (old);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;

	this->raw_bits -= 1;
	return (old);
}
