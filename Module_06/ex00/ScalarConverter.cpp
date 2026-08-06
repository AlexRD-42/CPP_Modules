/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:46:07 by adeimlin          #+#    #+#             */
/*   Updated: 2026/08/06 11:22:22 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

static inline
bool s_isSpecial(const std::string &s)
{
	if (s == "nan" || s == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return true;
	}
	if (s == "+inf" || s == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return true;
	}
	if (s == "-inf" || s == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return true;
	}
	return false;
}

static inline
bool s_isValid(const char *start, const char *end)
{
	if (start == end)
		return false;

	if (*end == 0)
		return true;

	if (end[0] == 'f' && end[1] == 0)
	{
		end--;
		while (end > start && std::isdigit(*end))
			end--;
		if (*end == '.')
			return true;
	}
	return false;
}

static
void s_printChar(double value)
{
	if (value != value) {
		std::cout << "char: impossible\n";
		return;
	}

	bool isImpossible = 
		value < std::numeric_limits<char>::min() 
		|| value > std::numeric_limits<char>::max();

	if (isImpossible)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
}

static void s_printInt(double value)
{
	static const double min = std::numeric_limits<int>::min() - 1.0;
	static const double max = std::numeric_limits<int>::max() + 1.0;

	if (value != value)
	{
		std::cout << "int: impossible\n";
		return;
	}

	if (value <= min || value >= max)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << "\n";
}

static
void s_printHelper(double value)
{
	std::ios::fmtflags oldFlags = std::cout.flags();
	std::cout << std::fixed << "double: " << value << "\n";
	std::cout.flags(oldFlags);
}

static
void s_printHelper(float value)
{
	std::ios::fmtflags oldFlags = std::cout.flags();
	std::cout << std::fixed << "float: " << value << "f\n";
	std::cout.flags(oldFlags);
}

static
void s_printFloat(double value)
{
	if (value != value) {
		std::cout << "float: nanf\n";
		return;
	}

	if (value < -std::numeric_limits<float>::max())
		std::cout << "float: -inff\n";
	else if (value > std::numeric_limits<float>::max())
		std::cout << "float: +inff\n";
	else
		s_printHelper(static_cast<float>(value));
}

static
void s_printDouble(double value)
{
	if (value != value) {
		std::cout << "double: nan\n";
		return;
	}

	if (value < -std::numeric_limits<double>::max())
		std::cout << "double: -inf\n";
	else if (value > std::numeric_limits<double>::max())
		std::cout << "double: +inf\n";
	else
		s_printHelper(value);
}

// === Methods ================================================================
void ScalarConverter::convert(const std::string &literal)
{
	double value = 0.0;

	if (s_isSpecial(literal))
		return ;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else
	{
		char *end = NULL;
		value = std::strtod(literal.c_str(), &end);
		if (s_isValid(literal.c_str(), end) == false)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return ;
		}
	}

	s_printChar(value);
	s_printInt(value);
	s_printFloat(value);
	s_printDouble(value);
}

// === Canonical Form and Constructors ========================================
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
	}
	return (*this);
}
