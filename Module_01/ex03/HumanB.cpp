/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:01:08 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 15:18:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name_(name),
	weapon_(NULL)
{
}

void HumanB::attack()
{
	if (weapon_ == NULL)
		return;
	std::cout << name_ << " attacks with their " << weapon_->getType() << "\n";
}

void HumanB::setWeapon(Weapon &type)
{
	weapon_ = &type;
}
