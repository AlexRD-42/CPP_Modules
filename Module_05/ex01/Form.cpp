/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:43:50 by adeimlin          #+#    #+#             */
/*   Updated: 2026/07/08 15:08:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


// === Methods ================================================================
const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->m_signGrade)
		throw (GradeTooLowException());
	this->m_signed = true;
}

// Overloads
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName()
		<< ", form execution grade "
		<< form.getExecGrade()
		<< ", form sign grade "
		<< form.getSignGrade();

	if (form.getSigned() == true)
		os << ", signed.";
	else
		os << ", not signed.";

	return os;
}

// === Getters ================================================================
const
std::string &Form::getName() const
{
	return m_name;
}

int Form::getExecGrade() const
{
	return m_execGrade;
}

int Form::getSignGrade() const
{
	return m_signGrade;
}

bool Form::getSigned() const
{
	return m_signed;
}

// === Canonical Form and Constructors ========================================
Form::Form() :
	m_name("Default"),
	m_signGrade(1),
	m_execGrade(1),
	m_signed(false)
{
}

Form::Form(const std::string &name, int signGrade, int execGrade) :
	m_name(name),
	m_signGrade(signGrade),
	m_execGrade(execGrade),
	m_signed(false)
{
	if (m_signGrade > 150 || m_execGrade > 150)
		throw (GradeTooLowException());
	else if (m_signGrade < 1 || m_execGrade < 1)
		throw (GradeTooHighException());
}

Form::Form(const Form &other) :
	m_name(other.m_name),
	m_signGrade(other.m_signGrade),
	m_execGrade(other.m_execGrade),
	m_signed(other.m_signed)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->m_signed = other.m_signed;
	}
	return (*this);
}
