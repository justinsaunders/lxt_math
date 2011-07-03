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
 * LXT math main header for C functions.
 *
 * If LXT_MATH_IMPL_OVERRIDE is defined, that will define what implementation is
 * used (useful for testing).
 */
#include _LXT_MATH_MATH_H_

#include "core/lxt_platform.h"

// Choose an implementation
#ifdef LXT_MATH_IMPL_OVERRIDE
    #undef LXT_MATH_IMPL_CURRENT
    #define LXT_MATH_IMPL_CURRENT LXT_MATH_IMPL_OVERRIDE
#endif

#if LXT_MATH_IMPL_CURRENT == LXT_MATH_IMPL_REF
    #include "core/impl_ref.h"
#elif LXT_MATH_IMPL_CURRENT == LXT_MATH_IMPL_SSE
    #include "core/impl_sse.h"
#else
    #error "Unsupported implementation"
#endif

#endif // _LXT_MATH_MATH_H_
