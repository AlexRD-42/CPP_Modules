/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:20:58 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/20 12:34:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <stdint.h>
#include <stddef.h>

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	int			read(void);

private:
	void		add_();
	void		search_();

private:
	size_t		cur_index_;

public:
	Contact	contacts[8];
};

#endif