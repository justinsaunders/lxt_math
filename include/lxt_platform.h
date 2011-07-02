/*
 The MIT License
 
 Copyright (c) 2011 Justin Saunders
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

/*
 * LXT math platform definitions.
 *
 * After including this file, inspect:
 * LXT_MATH_ARCH_CURRENT, LXT_MATH_PLATFORM_CURRENT to see current platform.
 */

#ifndef _LXT_MATH_PLATFORM_H_
#define	_LXT_MATH_PLATFORM_H_

// Supported C variant
#ifndef __cplusplus
    // If C is being used, it must be C99 or above.
    #if __STDC_VERSION__ < 199901L
        #error "C99 required to build lxt-math."
    #endif

    // include bool type
    #include <stdbool.h>
#endif

// Debugging enabled (non release build)
#if !defined ( NDEBUG )
    #define LXT_MATH_DEBUG
#endif

// Supported architectures
#define LXT_MATH_ARCH_UNKNOWN   -1
#define LXT_MATH_ARCH_ARM       0
#define LXT_MATH_ARCH_X86       1
#define LXT_MATH_ARCH_PPC       2

#if defined ( __i386__ )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_X86
#elif defined ( __arm__ )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_ARM
#elif defined ( __ppc__ )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_PPC
#endif

#if !defined( LXT_MATH_ARCH_CURRENT )
    #define LXT_MATH_ARCH_CURRENT LXT_MATH_ARCH_UNKNOWN
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
    #define LXT_MATH_OS_CURRENT LXT_MATH_OS_UNKNOWN
#endif

// Implementation types, note these may map from architecture types, but REF
// is availble on all architectures, and x86 supports AVX and SSE 
#define LXT_MATH_IMPL_REF   0
#define LXT_MATH_IMPL_SSE   1
#define LXT_MATH_IMPL_AVX   2
#define LXT_MATH_IMPL_NEON  3

#if LXT_MATH_ARCH_CURRENT == LXT_MATH_ARCH_X86
    #define LXT_MATH_IMPL_CURRENT LXT_MATH_IMPL_SSE
#elif LXT_MATH_ARCH_CURRENT == LXT_MATH_ARCH_ARM
    #define LXT_MATH_IMPL_CURRENT LXT_MATH_IMPL_NEON
#else
    #define LXT_MATH_IMPL_CURRENT LXT_MATH_IMPL_REF
#endif

#endif // _LXT_MATH_PLATFORM_H_