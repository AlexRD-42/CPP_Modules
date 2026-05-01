/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:13:20 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 15:14:38 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*horde = zombieHorde(5, "Bob");

	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
}
