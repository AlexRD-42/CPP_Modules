/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:43:50 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 12:33:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// === Methods ================================================================
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->m_signGrade)
		throw (GradeTooLowException());
	this->m_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (this->m_signed == false)
		throw (NotSignedException());
	if (executor.getGrade() > this->m_execGrade)
		throw (GradeTooLowException());
	executeAction();
}

// Overloads
std::ostream& operator<<(std::ostream& os, const AForm& form)
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
std::string &AForm::getName() const
{
	return m_name;
}

int AForm::getExecGrade() const
{
	return m_execGrade;
}

int AForm::getSignGrade() const
{
	return m_signGrade;
}

bool AForm::getSigned() const
{
	return m_signed;
}

// === Canonical Form and Constructors ========================================
AForm::AForm() :
	m_name("Default"),
	m_signGrade(1),
	m_execGrade(1),
	m_signed(false)
{
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) :
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

AForm::AForm(const AForm &other) :
	m_name(other.m_name),
	m_signGrade(other.m_signGrade),
	m_execGrade(other.m_execGrade),
	m_signed(other.m_signed)
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		// this->m_signed = other.m_signed;
	}
	return (*this);
}
