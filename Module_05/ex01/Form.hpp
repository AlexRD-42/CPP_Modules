/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:08:02 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 12:03:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class Form
{
public: // Canonical Form and Constructors
	Form();
	Form(const std::string &name, int signGrade, int execGrade);
	~Form();
	Form(const Form &other);
	Form& operator=(const Form &other);

	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);

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
	const std::string m_name;
	const int m_signGrade, m_execGrade;
	bool m_signed;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
