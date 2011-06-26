/*
 * LXT math platform definitions.
 *
 * After including this file, inspect:
 * LXT_MATH_ARCH_CURRENT, LXT_MATH_PLATFORM_CURRENT to see current platform.
 *
 * Copyright (c) 2011 Justin Saunders.
 *
 */

#ifndef _LXT_MATH_PLATFORM_H_
#define	_LXT_MATH_PLATFORM_H_

// Supported architectures
#define LXT_MATH_ARCH_UNKNOWN   -1
#define LXT_MATH_ARCH_ARM		0
#define LXT_MATH_ARCH_X86		1
#define LXT_MATH_ARCH_PPC		2

#if defined ( __i386__ )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_X86
#elif defined ( __arm__ )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_ARM
#elif defined ( __ppc__ )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_PPC
#endif

#if !defined( LXT_MATH_ARCH_CURRENT )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_UNKNOWN
    #error "Unsupported architecture for LXT math."
#endif

// Supported operating systems
#define LXT_MATH_OS_UNKNOWN -1
#define LXT_MATH_OS_IOS     0
#define LXT_MATH_OS_OSX     1
#define LXT_MATH_OS_WINDOWS 2
#define LXT_MATH_OS_LINUX   3

#if defined ( __APPLE__ ) && defined ( __MACH__ )
	#if TARGET_OS_IPHONE
		#define LXT_MATH_OS_CURRENT LXT_MATH_OS_IOS
	#else
		#define LXT_MATH_OS_CURRENT LXT_MATH_OS_OSX
	#endif
#endif

#if !defined ( LXT_MATH_OS_CURRENT )
	#error "Unsupported platform for LXT math."
#endif

// Debugging enabled (non release build)
#if !defined ( NDEBUG )
    #define LXT_MATH_DEBUG
#endif

#endif // _LXT_MATH_PLATFORM_H_
