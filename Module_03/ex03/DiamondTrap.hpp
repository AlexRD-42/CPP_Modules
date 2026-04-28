/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:44:39 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/27 12:54:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	name;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& other);

	DiamondTrap& operator=(const DiamondTrap& other);

	void whoAmI();
	void attack(const std::string& target);
};

#endif