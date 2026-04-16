/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:01:08 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/16 09:51:06 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <utility>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : name_(std::move(name)), weapon_(weapon)
{
	
	
}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon_.getType();
}
