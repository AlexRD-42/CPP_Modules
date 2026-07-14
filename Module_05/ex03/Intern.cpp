/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:07:18 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 13:07:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
	}
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Intern::*creators because it points to member functions
	AForm* (Intern::*creators[])(const std::string&) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << "\n";
			return (this->*creators[i])(target);
		}
	}

	std::cout << "Intern couldn't create " << name
		<< " because this form does not exist\n";
	return 0;
}
