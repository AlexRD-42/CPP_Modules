/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:32 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:24:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	int i;

	std::cout << "Brain default constructor called" << std::endl;
	i = 0;
	while (i < 100)
	{
		this->ideas[i] = "";
		i++;
	}
}

Brain::Brain(const Brain& other)
{
	int i;

	std::cout << "Brain copy constructor called" << std::endl;
	i = 0;
	while (i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
}

Brain& Brain::operator=(const Brain& other)
{
	int i;

	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		i = 0;
		while (i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Brain idea index out of range" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Brain idea index out of range" << std::endl;
		return ("");
	}
	return (this->ideas[index]);
}
