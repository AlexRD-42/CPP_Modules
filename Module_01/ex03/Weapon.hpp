/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:00:34 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 20:26:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	Weapon(std::string weapon_type);
	const std::string&	getType() const;
	void setType(std::string weapon_type);
};
