/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:45:35 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:45:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	// Animal animal; // must not compile: Animal is abstract

	std::cout << "=== Abstract Animal through base pointers ===" << std::endl;
	Animal* animals[4];

	for (int i = 0; i < 2; ++i)
		animals[i] = new Dog();
	for (int i = 2; i < 4; ++i)
		animals[i] = new Cat();
	for (int i = 0; i < 4; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < 4; ++i)
		delete animals[i];

	std::cout << "\n=== Deep copy still works ===" << std::endl;
	Cat original;
	original.setIdea(0, "sleep on the keyboard");

	Cat copy(original);
	copy.setIdea(0, "knock over a glass");

	std::cout << "original idea: " << original.getIdea(0) << std::endl;
	std::cout << "copy idea: " << copy.getIdea(0) << std::endl;
	std::cout << "original brain: " << original.getBrainAddress() << std::endl;
	std::cout << "copy brain: " << copy.getBrainAddress() << std::endl;
	return (0);
}
