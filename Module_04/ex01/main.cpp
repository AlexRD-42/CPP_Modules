/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:57 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:24:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void printSeparator(const std::string& title)
{
	std::cout << std::endl;
	std::cout << "========== " << title << " ==========" << std::endl;
}

static void testSubjectSnippet(void)
{
	const Animal* j;
	const Animal* i;

	printSeparator("subject snippet: delete as Animal");
	j = new Dog();
	i = new Cat();
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;
}

static void testAnimalArray(void)
{
	Animal* animals[10];
	int i;

	printSeparator("array of Animal pointers: half Dogs, half Cats");
	i = 0;
	while (i < 10)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}
	printSeparator("sounds from array through Animal pointers");
	i = 0;
	while (i < 10)
	{
		std::cout << "animals[" << i << "] type: " << animals[i]->getType() << " -> ";
		animals[i]->makeSound();
		i++;
	}
	printSeparator("delete array through Animal pointers");
	i = 0;
	while (i < 10)
	{
		delete animals[i];
		i++;
	}
}

static void testDogDeepCopyConstructor(void)
{
	Dog original;
	Dog copy(original);

	printSeparator("Dog copy constructor deep copy");
	original.setIdea(0, "Chase the postman");
	original.setIdea(1, "Guard the house");
	copy = original;
	std::cout << "original brain address: " << original.getBrainAddress() << std::endl;
	std::cout << "copy brain address:     " << copy.getBrainAddress() << std::endl;
	std::cout << "copy idea before original changes: " << copy.getIdea(0) << std::endl;
	original.setIdea(0, "Eat all the kibble");
	std::cout << "original idea after change: " << original.getIdea(0) << std::endl;
	std::cout << "copy idea after original change: " << copy.getIdea(0) << std::endl;
}

static void testCatDeepCopyConstructor(void)
{
	Cat original;
	Cat copy(original);

	printSeparator("Cat copy constructor deep copy");
	original.setIdea(0, "Knock cup from table");
	original.setIdea(99, "Sleep in a cardboard box");
	copy = original;
	std::cout << "original brain address: " << original.getBrainAddress() << std::endl;
	std::cout << "copy brain address:     " << copy.getBrainAddress() << std::endl;
	std::cout << "copy idea before original changes: " << copy.getIdea(99) << std::endl;
	original.setIdea(99, "Demand food immediately");
	std::cout << "original idea after change: " << original.getIdea(99) << std::endl;
	std::cout << "copy idea after original change: " << copy.getIdea(99) << std::endl;
}

static void testCopyConstructorsDirectly(void)
{
	Dog dog;
	Cat cat;
	Dog dogCopy(dog);
	Cat catCopy(cat);

	printSeparator("direct copy constructor checks");
	dog.setIdea(2, "Original dog idea");
	cat.setIdea(2, "Original cat idea");
	Dog copiedDog(dog);
	Cat copiedCat(cat);
	std::cout << "dog brain address:        " << dog.getBrainAddress() << std::endl;
	std::cout << "copied dog brain address: " << copiedDog.getBrainAddress() << std::endl;
	std::cout << "cat brain address:        " << cat.getBrainAddress() << std::endl;
	std::cout << "copied cat brain address: " << copiedCat.getBrainAddress() << std::endl;
	dog.setIdea(2, "Changed dog idea");
	cat.setIdea(2, "Changed cat idea");
	std::cout << "copied dog idea remains: " << copiedDog.getIdea(2) << std::endl;
	std::cout << "copied cat idea remains: " << copiedCat.getIdea(2) << std::endl;
	(void)dogCopy;
	(void)catCopy;
}

static void testSelfAssignmentAndBounds(void)
{
	Dog dog;
	Cat cat;

	printSeparator("self-assignment and Brain bounds");
	dog.setIdea(0, "Keep this dog idea");
	cat.setIdea(0, "Keep this cat idea");
	dog = dog;
	cat = cat;
	std::cout << "dog idea after self-assignment: " << dog.getIdea(0) << std::endl;
	std::cout << "cat idea after self-assignment: " << cat.getIdea(0) << std::endl;
	dog.setIdea(-1, "invalid negative index");
	cat.setIdea(100, "invalid high index");
	std::cout << "dog invalid read: '" << dog.getIdea(-1) << "'" << std::endl;
	std::cout << "cat invalid read: '" << cat.getIdea(100) << "'" << std::endl;
}

int main(void)
{
	testSubjectSnippet();
	testAnimalArray();
	testDogDeepCopyConstructor();
	testCatDeepCopyConstructor();
	testCopyConstructorsDirectly();
	testSelfAssignmentAndBounds();
	return (0);
}
