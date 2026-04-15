/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:40:48 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 15:57:38 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde;
	if (N <= 0)
	{
		std::cout << "A zombie horde cannot have negative zombies\n";
		return (NULL);
	}
	horde = new Zombie[N];
	for (size_t i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
