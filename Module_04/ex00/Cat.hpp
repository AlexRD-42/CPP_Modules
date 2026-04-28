/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:19:43 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:19:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat(void);

	virtual void makeSound(void) const;
};

#endif
