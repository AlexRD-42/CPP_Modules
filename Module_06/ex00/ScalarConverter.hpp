/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:36:47 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 14:50:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
public: // Canonical Form and Constructors
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter &other);

	static void convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
};
