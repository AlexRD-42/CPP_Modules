/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:08:02 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 12:33:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_AFORM_HPP
#define EX03_AFORM_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class AForm
{
public: // Canonical Form and Constructors
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm& operator=(const AForm &other);

	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& executor) const;

	virtual void executeAction() const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
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
	const std::string m_name;
	const int m_signGrade, m_execGrade;
	bool m_signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
