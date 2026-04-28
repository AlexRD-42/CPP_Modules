/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:20:09 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:20:10 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void printSeparator(const std::string& title)
{
	std::cout << std::endl;
	std::cout << "========== " << title << " ==========" << std::endl;
}

static void subjectTest(void)
{
	printSeparator("Subject test");

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
}

static void stackObjectTest(void)
{
	printSeparator("Stack object test");

	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << "animal type: " << animal.getType() << std::endl;
	std::cout << "dog type: " << dog.getType() << std::endl;
	std::cout << "cat type: " << cat.getType() << std::endl;

	animal.makeSound();
	dog.makeSound();
	cat.makeSound();
}

static void polymorphicArrayTest(void)
{
	printSeparator("Polymorphic array test");

	const int size = 6;
	Animal* animals[size];
	int index;

	index = 0;
	while (index < size)
	{
		if (index < size / 2)
			animals[index] = new Dog();
		else
			animals[index] = new Cat();
		index++;
	}

	index = 0;
	while (index < size)
	{
		std::cout << "animals[" << index << "] type: " << animals[index]->getType() << std::endl;
		animals[index]->makeSound();
		index++;
	}

	index = 0;
	while (index < size)
	{
		delete animals[index];
		index++;
	}
}

static void copyTest(void)
{
	printSeparator("Copy constructor and assignment test");

	Dog originalDog;
	Dog copiedDog(originalDog);
	Dog assignedDog;

	assignedDog = originalDog;
	std::cout << "originalDog type: " << originalDog.getType() << std::endl;
	std::cout << "copiedDog type: " << copiedDog.getType() << std::endl;
	std::cout << "assignedDog type: " << assignedDog.getType() << std::endl;
	copiedDog.makeSound();
	assignedDog.makeSound();

	Cat originalCat;
	Cat copiedCat(originalCat);
	Cat assignedCat;

	assignedCat = originalCat;
	std::cout << "originalCat type: " << originalCat.getType() << std::endl;
	std::cout << "copiedCat type: " << copiedCat.getType() << std::endl;
	std::cout << "assignedCat type: " << assignedCat.getType() << std::endl;
	copiedCat.makeSound();
	assignedCat.makeSound();
}

static void wrongAnimalTest(void)
{
	printSeparator("WrongAnimal non-polymorphic test");

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCatAsAnimal = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();

	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCatAsAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	wrongMeta->makeSound();
	wrongCatAsAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongCat;
	delete wrongCatAsAnimal;
	delete wrongMeta;
}

int main(void)
{
	subjectTest();
	stackObjectTest();
	polymorphicArrayTest();
	copyTest();
	wrongAnimalTest();
	return (0);
}
