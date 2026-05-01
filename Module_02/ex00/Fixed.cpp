/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:04:29 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 16:20:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	raw_bits = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other) :
	raw_bits(other.raw_bits)
{
	std::cout << "Copy constructor called\n";
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return (*this);
	this->raw_bits = other.raw_bits;
	return (*this);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits method called\n";
	return (raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits method called\n";
	raw_bits = raw;
}
