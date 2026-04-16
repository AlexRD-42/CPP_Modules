/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:01:11 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 22:33:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name_;
	Weapon weapon_;

public:
	HumanA(std::string name, Weapon weapon);
	void attack();

};
