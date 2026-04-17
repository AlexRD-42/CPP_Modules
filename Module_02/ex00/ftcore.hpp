/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcore.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:52:02 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/17 12:07:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTCORE_HPP
# define FTCORE_HPP

#include <cstddef>
#include <stdint.h>
#include <string>

typedef std::string string;

typedef int8_t		i8;
typedef uint8_t		u8;
typedef int16_t		i16;
typedef uint16_t	u16;
typedef int32_t		i32;
typedef uint32_t	u32;
typedef int64_t		i64;
typedef uint64_t	u64;
typedef float 		f32;
typedef double 		f64;
typedef size_t		usize;
typedef ptrdiff_t	isize;

typedef union t32
{
	uint8_t		u8[4];
	uint16_t	u16[2];
	uint32_t	u32;
	int8_t		i8[4];
	int16_t		i16[2];
	int32_t		i32;
	float		f32;
}	t32;

#endif