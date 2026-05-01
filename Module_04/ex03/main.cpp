/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:24:38 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:27:25 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void printHeader(std::string const &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
	printHeader("Basic subject test");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob); // expected: ice bolt at bob
	me->use(1, *bob); // expected: heals bob's wounds

	delete bob;
	delete me;
	delete src;

	printHeader("Unknown materia should return NULL");

	MateriaSource source;
	source.learnMateria(new Ice());

	AMateria* unknown = source.createMateria("fire");
	if (unknown == NULL)
		std::cout << "OK: unknown materia returned NULL" << std::endl;
	else
	{
		std::cout << "FAIL: unknown materia did not return NULL" << std::endl;
		delete unknown;
	}

	printHeader("Cure type must be lowercase");

	MateriaSource source2;
	source2.learnMateria(new Cure());

	AMateria* cureLower = source2.createMateria("cure");
	AMateria* cureUpper = source2.createMateria("Cure");

	if (cureLower != NULL)
		std::cout << "OK: createMateria(\"cure\") works" << std::endl;
	else
		std::cout << "FAIL: createMateria(\"cure\") returned NULL" << std::endl;

	if (cureUpper == NULL)
		std::cout << "OK: createMateria(\"Cure\") rejected" << std::endl;
	else
	{
		std::cout << "FAIL: createMateria(\"Cure\") should not work" << std::endl;
		delete cureUpper;
	}

	delete cureLower;

	printHeader("Inventory limit and invalid use");

	Character alice("alice");
	Character target("target");

	AMateria* a = new Ice();
	AMateria* b = new Cure();
	AMateria* c = new Ice();
	AMateria* d = new Cure();
	AMateria* e = new Ice();

	alice.equip(a);
	alice.equip(b);
	alice.equip(c);
	alice.equip(d);
	alice.equip(e); // inventory full: should do nothing, caller still owns e

	alice.use(0, target);
	alice.use(1, target);
	alice.use(2, target);
	alice.use(3, target);
	alice.use(4, target);   // invalid: should do nothing
	alice.use(-1, target);  // invalid: should do nothing

	delete e;

	printHeader("Unequip should not delete and should clear slot");

	Character uneq("uneq");
	AMateria* floor = new Ice();

	uneq.equip(floor);
	uneq.use(0, target);

	uneq.unequip(0);        // must NOT delete floor, must clear slot
	uneq.use(0, target);    // should do nothing

	delete floor;           // should not double-free later

	printHeader("Unequip indexes 1, 2, 3 must work");

	Character idx("idx");
	AMateria* m0 = new Ice();
	AMateria* m1 = new Ice();
	AMateria* m2 = new Ice();
	AMateria* m3 = new Ice();

	idx.equip(m0);
	idx.equip(m1);
	idx.equip(m2);
	idx.equip(m3);

	idx.unequip(1);
	idx.unequip(2);
	idx.unequip(3);

	idx.use(1, target); // should do nothing
	idx.use(2, target); // should do nothing
	idx.use(3, target); // should do nothing

	delete m1;
	delete m2;
	delete m3;

	printHeader("Character copy constructor deep copy");

	Character original("original");
	original.equip(new Ice());
	original.equip(new Cure());

	Character copy(original);

	original.use(0, target);
	copy.use(0, target);
	original.use(1, target);
	copy.use(1, target);

	printHeader("Character assignment deep copy");

	Character assigned("assigned");
	assigned = original;

	original.use(0, target);
	assigned.use(0, target);
	original.use(1, target);
	assigned.use(1, target);

	printHeader("MateriaSource must clone learned materia");

	MateriaSource cloneSource;
	AMateria* learned = new Ice();

	cloneSource.learnMateria(learned);
	delete learned; // should be safe if MateriaSource cloned it

	AMateria* cloned = cloneSource.createMateria("ice");
	if (cloned != NULL)
	{
		std::cout << "OK: cloned materia after deleting original learned pointer" << std::endl;
		cloned->use(target);
		delete cloned;
	}
	else
		std::cout << "FAIL: could not clone learned materia" << std::endl;

	printHeader("End of tests");

	return 0;
}
