/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:45:29 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:45:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main(void)
{
	MateriaSource src;
	Ice ice;
	Cure cure;

	src.learnMateria(&ice);
	src.learnMateria(&cure);

	Character me("me");
	Character bob("bob");

	AMateria* tmp = src.createMateria("ice");
	me.equip(tmp);
	tmp = src.createMateria("cure");
	me.equip(tmp);

	me.use(0, bob);
	me.use(1, bob);
	me.use(2, bob); // empty slot: does nothing

	std::cout << "=== Deep copy ===" << std::endl;
	Character copy(me);
	copy.use(0, bob);
	copy.use(1, bob);

	return (0);
}
