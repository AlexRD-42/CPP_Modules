/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:01:13 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 20:20:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
	type = weapon_type;
}

const std::string& Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string weapon_type)
{
	type = weapon_type;
}
