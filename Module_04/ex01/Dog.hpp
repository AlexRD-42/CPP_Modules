/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:52 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:24:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog(void);
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog(void);

	void makeSound(void) const;
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
	const Brain* getBrainAddress(void) const;
};

#endif
