/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:24:37 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 16:24:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain(void);
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain(void);

	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
};

#endif
