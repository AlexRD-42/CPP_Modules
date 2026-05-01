/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:45:42 by adeimlin          #+#    #+#             */
/*   Updated: 2026/05/01 18:45:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Animal array ===" << std::endl;
	Animal* animals[4];

	for (int i = 0; i < 2; ++i)
		animals[i] = new Dog();
	for (int i = 2; i < 4; ++i)
		animals[i] = new Cat();
	for (int i = 0; i < 4; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < 4; ++i)
		delete animals[i];

	std::cout << "\n=== Deep copy ===" << std::endl;
	Dog basic;
	basic.setIdea(0, "protect the house");

	Dog copy(basic);
	copy.setIdea(0, "chase the ball");

	std::cout << "basic idea: " << basic.getIdea(0) << std::endl;
	std::cout << "copy idea: " << copy.getIdea(0) << std::endl;
	std::cout << "basic brain: " << basic.getBrainAddress() << std::endl;
	std::cout << "copy brain: " << copy.getBrainAddress() << std::endl;

	Dog assigned;
	assigned = basic;
	std::cout << "assigned idea: " << assigned.getIdea(0) << std::endl;
	std::cout << "assigned brain: " << assigned.getBrainAddress() << std::endl;
	return (0);
}
