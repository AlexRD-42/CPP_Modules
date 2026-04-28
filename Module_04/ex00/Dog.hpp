/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:19:59 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:20:00 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog(void);

	virtual void makeSound(void) const;
};

#endif
