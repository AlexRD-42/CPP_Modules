/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:01:18 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 16:27:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
private:
	int 				raw_bits;
	static const int	fractional_bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed(const int raw_int);
	Fixed(const float raw_float);

	Fixed&	operator=(const Fixed& other);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif