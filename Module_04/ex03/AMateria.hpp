/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:02:12 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:41:10 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ICharacter;

class AMateria
{
public: // Canonical Form and Constructors
	AMateria();
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria(const AMateria &other);
	AMateria& operator=(const AMateria &other);

protected:
	std::string	m_type;

private:
	
public:
	std::string const & getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};
