/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:21:06 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 16:21:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
