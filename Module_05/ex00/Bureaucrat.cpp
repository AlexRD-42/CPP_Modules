/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:05:06 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 11:07:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <ostream>

// === Methods ================================================================
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void Bureaucrat::decrementGrade()
{
	if (m_grade >= 150)
		throw (GradeTooLowException());	// Class instancing, not function
	m_grade++;
}

void Bureaucrat::incrementGrade()
{
	if (m_grade <= 1)
		throw (GradeTooHighException());
	m_grade--;
}

const
std::string &Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

// Overloads
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";

    return os;
}

// === Canonical Form and Constructors ========================================
Bureaucrat::Bureaucrat() :
	m_name("Default"),
	m_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	m_name(name),
	m_grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	m_name(other.m_name),
	m_grade(other.m_grade)
{
	// *this = other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->m_grade = other.m_grade;
	}
	return *this;
}
