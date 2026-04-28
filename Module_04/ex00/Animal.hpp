/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:19:22 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:19:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal(void);

	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif
