/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:36:33 by adeimlin          #+#    #+#             */
/*   Updated: 2026/06/29 11:49:00 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Type>
void swap(Type &x, Type &y)
{
	Type tmp = x;

	x = y;
	y = tmp;
}

template <typename Type>
Type min(Type &x, Type &y)
{
	return (x < y ? x : y);
}

template <typename Type>
Type max(Type &x, Type &y)
{
	return (x > y ? x : y);
}

