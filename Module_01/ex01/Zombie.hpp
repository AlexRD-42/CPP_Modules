/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:10:31 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 15:53:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie
{
public: 
	Zombie();
	Zombie(std::string name);
	~Zombie();

private:
	std::string	name;
public:
	void announce(void);
	void setName(std::string name);
};
