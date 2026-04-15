/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:20:58 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 12:12:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <stdint.h>
#include <stddef.h>

class Contacts
{
public:
	Contacts();
	void	add_contact(void);
	void	print_short(size_t index);
	void	print_long(void);

public:
	// size_t	first_name_length;
	// size_t	last_name_length;
	// size_t	nickname_length;
	// size_t	phone_length;
	// size_t	secret_length;
	char	first_name[32];
	char	last_name[32];
	char	nickname[32];
	char	phone[32];
	char	secret[32];
};

#endif