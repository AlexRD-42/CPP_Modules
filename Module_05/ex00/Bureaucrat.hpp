/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:25:30 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/02 16:21:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>

class Bureaucrat
{
public: // Canonical Form and Constructors
	Bureaucrat();
	Bureaucrat(std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	int	getGrade() const;
	void incrementGrade();
	void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

private:
	const std::string	m_name;
	int					m_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#include "Bureaucrat.hpp"
#include <iostream>

// === Methods ================================================================
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

void	Bureaucrat::decrementGrade()
{

	if (m_grade >= 150)
		throw (GradeTooLowException());	// Class instancing, not function
	m_grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (m_grade <= 1)
		throw (GradeTooHighException());
	m_grade--;
}

// Overloads
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";

    return (os);
}

// === Canonical Form and Constructors ========================================
Bureaucrat::Bureaucrat() :
	m_name("Default"),
	m_grade(150)
{
}

Bureaucrat::Bureaucrat(std::string &name, int grade) :
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
	return (*this);
}
