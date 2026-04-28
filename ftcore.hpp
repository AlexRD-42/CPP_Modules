/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcore.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:52:02 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/28 14:28:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// To remember: typeof, offset_of, circshift, complex numbers return
// LQR , fixed point LUT pack, lut size differences
// Immintrin types, overflow functions, ROTL and reverse
// // consteval, constexpr, 

#include <cmath>
#ifdef __cplusplus
	#include <cstddef>
	#include <cstdint>
	#include <climits>
	#define restrict __restrict__
#else
	#include <stddef.h>
	#include <stdint.h>
	#include <stdbool.h>
	#include <limits.h>
	#define static_assert(cond, msg) _Static_assert(cond, msg)
#endif

// === Attributes ==========================================
#define ALWAYS_INLINE	static inline __attribute__((always_inline))
#define NOINLINE		__attribute__((noinline))
#define PURE			__attribute__((pure))
#define CONST_FN		__attribute__((const))
#define PACKED			__attribute__((packed))
#define ALIGNED(n)		__attribute__((aligned(n)))
#define LIKELY(x)		__builtin_expect(!!(x), 1)
#define UNLIKELY(x)		__builtin_expect(!!(x), 0)
#define UNREACHABLE()	__builtin_unreachable()
#if defined(__clang__)
	#define ASSUME(x)	__builtin_assume(x)
#elif defined(__GNUC__)
	#define ASSUME(x) ((x) ? (void)0 : __builtin_unreachable())
#endif

// === Types ===============================================
typedef int8_t			i8;
typedef uint8_t			u8;
typedef int16_t			i16;
typedef uint16_t		u16;
typedef int32_t			i32;
typedef uint32_t		u32;
typedef int64_t			i64;
typedef uint64_t		u64;
typedef float			f32;
typedef double			f64;
typedef size_t			usize;
typedef ptrdiff_t		isize;
typedef unsigned short	ushort;	// For completeness, to mirror platform's type
typedef unsigned int	uint;
typedef unsigned long	ulong;

typedef union
{
	uint8_t u8[4]; uint16_t u16[2]; uint32_t u32;
	int8_t i8[4]; int16_t i16[2]; int32_t i32;
	float f32;
}	m32;

typedef union
{
	uint8_t u8[8]; uint16_t u16[4]; uint32_t u32[2]; uint64_t u64;
	int8_t i8[8]; int16_t i16[4]; int32_t i32[2]; int64_t i64;
	float f32; double f64;
}	m64;

// === Constants ===========================================
#define WORD_SIZE	sizeof(size_t)
#define WORD_BITS	(WORD_SIZE * CHAR_BIT)
#define PI			3.141592653589793238462643383279502884	// Todo: get actual double representation on these
#define EULER		2.718281828459045235360287471352662497	// Todo: get actual double representation on these
#define KLOG2		0.301029995663981195213738894724493026
#define DEG2RAD		(PI / 180.0)
#define RAD2DEG		(180.0 / PI)

#ifdef __cplusplus
	#define ALIGN_SIZE	alignof(std::max_align_t)
#else
	#define ALIGN_SIZE	_Alignof(max_align_t)
#endif

// === Bit Helpers =========================================
#define BIT_READ(word, index)	(((word) >> (index)) & 1)
#define BIT_SET(word, index)	((word) | ((typeof(word))1 << (index)))
#define BIT_CLR(word, index)	((word) & ~((typeof(word))1 << (index)))

// === Math Helpers ========================================
#define MIN(x, y)			((x) < (y) ? (x) : (y))
#define MIN3(x, y, z)		MIN(x, MIN(y, z))
#define MIN4(x, y, z, w)	MIN(MIN(x, y), MIN(z, w))
#define MAX(x, y)			((x) > (y) ? (x) : (y))
#define MAX3(x, y, z)		MAX(x, MAX(y, z))
#define MAX4(x, y, z, w)	MAX(MAX(x, y), MAX(z, w))
#define ABS(x)				((x) > 0 ? (x) : -(x))
#define ABSMAX(x, y)		MAX(ABS(x), ABS(y))
#define ABSMIN(x, y)		MIN(ABS(x), ABS(y))
#define ABSDIFF(x, y)		(MAX(x, y) - MIN(x, y))
#define CLAMP(x, low, high)	MAX(low, MIN(x, high))
#define LOG2(x)				(63u - CLZ(x))

// === Generic Helpers =====================================
#define ARRAY_COUNT(arr)	(sizeof(arr) / sizeof((arr)[0]))
#define STRINGIFY_(x)		#x
#define STRINGIFY(x)		STRINGIFY_(x)
#define ALIGN_UP(x, a)		(((x) + ((a) - 1)) & ~((a) - 1))	// TODO: rename this
#define ALIGN_DOWN(x, a)	((x) & ~((a) - 1))
#define IS_POW2(x)			(((x) & ((x) - 1)) == 0)			// UB for x==0

// #define PREV_POW2(x) ((typeof(x))1 << ((sizeof(x) * 8 - 1) - CLZ(x)))	// TODO: fix this
// #define NEXT_POW2(x) ((typeof(x))1 << ((sizeof(x) * 8 + 1) - CLZ(x)))

// === Builtins ============================================
#define MEMCPY_BUILTIN(dst, src, n)		__builtin_memcpy(dst, src, n)
#define MEMMOVE_BUILTIN(dst, src, n)	__builtin_memmove(dst, src, n)
#define MEMSET_BUILTIN(dst, val, n)		__builtin_memset(dst, val, n)	// memchr
#define SWAP(a, b) ({__auto_type _tmp = (a); (a) = (b); (b) = _tmp;(void)0;})	// just because it can be done, doesnt mean it should

#if defined(__clang__) && __has_builtin(__builtin_memcpy_inline)
	#define MEMCPY_INLINE(dst, src, n)	__builtin_memcpy_inline(dst, src, n)
#else
	#define MEMCPY_INLINE(dst, src, n)	__builtin_memcpy(dst, src, n)
#endif

#define CLZ(x)			__builtin_clzll(x)
#define CTZ(x)			__builtin_ctzll(x)
#define POPCOUNT(x)		__builtin_popcountll(x)
#define FFS(x)			__builtin_ffsll(x)
#define PARITY(x)		__builtin_parityll(x)
#define BSWAP16(x)		__builtin_bswap16(x)
#define BSWAP32(x)		__builtin_bswap32(x)
#define BSWAP64(x)		__builtin_bswap64(x)
#define BITREVERSE(x)	__builtin_bitreverse64(x)	// CLANG SPECIFIC

// === New Stuff
typedef _Complex float f32x2;
#define F32X2_NEW(x, y) __builtin_complex((x), (y))
#define F32X2_AT(pair, idx) __builtin_choose_expr(idx /(_idx == 0 || idx == 1), __real__(pair), __imag__(pair))

#ifdef __cplusplus
	#define CONST_SELECT(cond, a, b) ({typeof(a) x; if constexpr (cond) x = (a); else x = (b); x;})
#else
	#define CONST_SELECT(cond, a, b) __builtin_choose_expr(cond, a, b)
#endif

#define IS_CONST(x) __builtin_constant_p(x)