/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:44 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:24:45 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat(void);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat(void);

	void makeSound(void) const;
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
	const Brain* getBrainAddress(void) const;
};

#endif
