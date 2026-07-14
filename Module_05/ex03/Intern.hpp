/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:07:22 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/10 13:07:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& name, const std::string& target) const;

private:
	AForm* createShrubberyCreationForm(const std::string& target) const;
	AForm* createRobotomyRequestForm(const std::string& target) const;
	AForm* createPresidentialPardonForm(const std::string& target) const;
};
