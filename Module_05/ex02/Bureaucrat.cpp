/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:05:06 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 12:33:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>
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

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << m_name << " couldn't sign " << form.getName() << " because "
		<< e.what() << "\n";
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->m_name << " executed " << form.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << this->m_name << " couldn't execute " << form.getName()
		<< " because " << e.what() << "\n";
	}
}

// Getters
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
