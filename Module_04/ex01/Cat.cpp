/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:41 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:24:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->brain) = *(other.brain);
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (this->brain->getIdea(index));
}

const Brain* Cat::getBrainAddress(void) const
{
	return (this->brain);
}
