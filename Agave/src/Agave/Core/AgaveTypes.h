///=============================================================================
/// AgaveTypes.h
/// Agave/Core
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Identify standard types
///=============================================================================

#ifndef AGAVE_TYPES_H
#define AGAVE_TYPES_H

///=============================================================================
///	Includes
///=============================================================================
#include <inttypes.h>
#include <stddef.h>

#if !defined( __cplusplus )
#if !defined( static_assert )
#define static_assert( ... )
#endif
#endif

///=============================================================================
///=============================================================================
typedef	unsigned char	u8;
typedef	signed char		s8;
typedef unsigned short	u16;
typedef signed short	s16;
typedef	unsigned int	u32;
typedef signed int		s32;
typedef int64_t			s64;
typedef uint64_t        u64;

static_assert(sizeof(u8) == 1, "incorrect u8 size");
static_assert(sizeof(s8) == 1, "incorrect s8 size");
static_assert(sizeof(u16) == 2, "incorrect u16 size");
static_assert(sizeof(s16) == 2, "incorrect s16 size");
static_assert(sizeof(u32) == 4, "incorrect u32 size");
static_assert(sizeof(s32) == 4, "incorrect s32 size");
static_assert(sizeof(u64) == 8, "incorrect u64 size");
static_assert(sizeof(s64) == 8, "incorrect s64 size");

#ifdef _WCHAR_T_DEFINED
typedef wchar_t WCHAR;
#endif

#endif // #ifndef AGAVE_TYPES_H