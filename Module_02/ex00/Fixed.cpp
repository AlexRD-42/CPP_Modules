/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:04:29 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/17 12:28:25 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcore.hpp"

class Fixed
{
private:
	int 				raw_bits;
	static const int	fractional_bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);

	Fixed&	operator=(const Fixed& other);
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#include <iostream>
#include <string>
#include "ftcore.hpp"

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
	return (raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	raw_bits = raw;
}
