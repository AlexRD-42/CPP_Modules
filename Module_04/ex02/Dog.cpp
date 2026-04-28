/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:26:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) 
	: Animal(),
	brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->brain) = *(other.brain);
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (this->brain->getIdea(index));
}

const Brain* Dog::getBrainAddress(void) const
{
	return (this->brain);
}
