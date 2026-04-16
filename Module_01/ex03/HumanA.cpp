/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:01:08 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/16 13:34:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <utility>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
	name_(name),
	weapon_(weapon)
{
}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << "\n";
}
