/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:45:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:46:40 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Animal polymorphism ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete cat;
	delete dog;
	delete meta;

	std::cout << "\n=== WrongAnimal non-polymorphism ===" << std::endl;
	WrongCat wrongCat;
	WrongAnimal* wrong = &wrongCat;

	wrong->makeSound();      // WrongAnimal sound: makeSound is not virtual
	wrongCat.makeSound();   // WrongCat sound
	return (0);
}
