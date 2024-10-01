
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


//===========================================================================
//  Cpp2 utility macros:
//      Language support implementations
//      #include'd by generated Cpp1 code

//      These should not be used by the program. They form the language
//      support library intended to be called only from generated code.
//===========================================================================

#ifndef CPP2_CPP2UTIL_PRE_H
#define CPP2_CPP2UTIL_PRE_H


//  If this implementation doesn't support source_location yet, disable it
#include <version>

#undef CPP2_USE_SOURCE_LOCATION
#if defined(__cpp_lib_source_location)
    #define CPP2_USE_SOURCE_LOCATION Yes
#endif

//  If the user requested making the entire C++ standard library available
//  via module import (incl. via -pure-cpp2) or header include, do that
#if defined(CPP2_IMPORT_STD) || defined(CPP2_INCLUDE_STD)

    //  If C++23 'import std;' was requested but isn't available, fall back
    //  to the 'include std' path
    #if defined(CPP2_IMPORT_STD) && defined(__cpp_lib_modules)
        import std.compat;
    //  If 'include std' was requested, include all standard headers.
    //  This list tracks the current draft standard, so as of this
    //  writing includes draft C++26 headers like <debugging>.
    //  Use a feature test #ifdef for each header that isn't supported
    //  by all of { VS 2022, g++-10, clang++-12 }
    #else
        #ifdef _MSC_VER
            #include "intrin.h"
        #endif
        #include <algorithm>
        #include <any>
        #include <array>
        #include <atomic>
        #ifdef __cpp_lib_barrier
            #include <barrier>
        #endif
        #include <bit>
        #include <bitset>
        #include <cassert>
        #include <cctype>
        #include <cerrno>
        #include <cfenv>
        #include <cfloat>
        #include <charconv>
        #include <chrono>
        #include <cinttypes>
        #include <climits>
        #include <clocale>
        #include <cmath>
        #include <codecvt>
        #include <compare>
        #include <complex>
        #include <concepts>
        #include <condition_variable>
        #ifdef __cpp_lib_coroutine
            #include <coroutine>
        #endif
        #include <csetjmp>
        #include <csignal>
        #include <cstdarg>
        #include <cstddef>
        #include <cstdint>
        #include <cstdio>
        #include <cstdlib>
        #include <cstring>
        #include <ctime>
        #if __has_include(<cuchar>)
            #include <cuchar>
        #endif
        #include <cwchar>
        #include <cwctype>
        #ifdef __cpp_lib_debugging
            #include <debugging>
        #endif
        #include <deque>
        #ifndef CPP2_NO_EXCEPTIONS
            #include <exception>
        #endif
        // libstdc++ currently has a dependency on linking TBB if <execution> is
        // included, and TBB seems to be not automatically installed and linkable
        // on some GCC installations, so let's not pull in that little-used header
        // in our -pure-cpp2 "import std;" simulation mode... if you need this,
        // use mixed mode (not -pure-cpp2) and #include all the headers you need
        // including this one
        //
        // #include <execution>
        #ifdef __cpp_lib_expected
            #include <expected>
        #endif
        #include <filesystem>
        #if defined(__cpp_lib_format) || (defined(_MSC_VER) && _MSC_VER >= 1929)
            #include <format>
        #endif
        #ifdef __cpp_lib_flat_map
            #include <flat_map>
        #endif
        #ifdef __cpp_lib_flat_set
            #include <flat_set>
        #endif
        #include <forward_list>
        #include <fstream>
        #include <functional>
        #include <future>
        #ifdef __cpp_lib_generator
            #include <generator>
        #endif
        #ifdef __cpp_lib_hazard_pointer
            #include <hazard_pointer>
        #endif
        #include <initializer_list>
        #ifdef __cpp_lib_inplace_vector
            #include <inplace_vector>
        #endif
        #include <iomanip>
        #include <ios>
        #include <iosfwd>
        #include <iostream>
        #include <iso646.h>
        #include <istream>
        #include <iterator>
        #ifdef __cpp_lib_latch
            #include <latch>
        #endif
        #include <limits>
        #ifdef __cpp_lib_linalg
            #include <linalg>
        #endif
        #include <list>
        #include <locale>
        #include <map>
        #ifdef __cpp_lib_mdspan
            #include <mdspan>
        #endif
        #include <memory>
        #ifdef __cpp_lib_memory_resource
            #include <memory_resource>
        #endif
        #include <mutex>
        #include <new>
        #include <numbers>
        #include <numeric>
        #include <optional>
        #include <ostream>
        #ifdef __cpp_lib_print
            #include <print>
        #endif
        #include <queue>
        #include <random>
        #include <ranges>
        #include <ratio>
        #ifdef __cpp_lib_rcu
            #include <rcu>
        #endif
        #include <regex>
        #include <scoped_allocator>
        #ifdef __cpp_lib_semaphore
            #include <semaphore>
        #endif
        #include <set>
        #include <shared_mutex>
        #ifdef __cpp_lib_source_location
            #include <source_location>
        #endif
        #include <span>
        #ifdef __cpp_lib_spanstream
            #include <spanstream>
        #endif
        #include <sstream>
        #include <stack>
        #ifdef __cpp_lib_stacktrace
            #include <stacktrace>
        #endif
        #ifdef __cpp_lib_stdatomic_h
            #include <stdatomic.h>
        #endif
        #include <stdexcept>
        #if __has_include(<stdfloat>)
            #if !defined(_MSC_VER) || _HAS_CXX23
                #include <stdfloat>
            #endif
        #endif
        #ifdef __cpp_lib_jthread
            #include <stop_token>
        #endif
        #include <streambuf>
        #include <string>
        #include <string_view>
        #ifdef __cpp_lib_syncbuf
            #include <syncstream>
        #endif
        #include <system_error>
        #ifdef __cpp_lib_text_encoding
            #include <text_encoding>
        #endif
        #include <thread>
        #include <tuple>
        #include <type_traits>
        #include <typeindex>
        #ifndef CPP2_NO_RTTI
            #include <typeinfo>
        #endif
        #include <unordered_map>
        #include <unordered_set>
        #include <utility>
        #include <valarray>
        #include <variant>
        #include <vector>
    #endif
#endif


//-----------------------------------------------------------------------
//
//  Macros
//
//-----------------------------------------------------------------------
//
#define CPP2_TYPEOF(x)              std::remove_cvref_t<decltype(x)>
#if __cplusplus >= 202302L && \
    ( \
     (defined(__clang_major__) && __clang_major__ >= 15) \
     || (defined(__GNUC__) && __GNUC__ >= 12) \
     )
#define CPP2_COPY(x)                auto(x)
#else
#define CPP2_COPY(x)                CPP2_TYPEOF(x)(x)
#endif
#define CPP2_FORWARD(x)             std::forward<decltype(x)>(x)
#define CPP2_PACK_EMPTY(x)          (sizeof...(x) == 0)
#define CPP2_CONTINUE_BREAK(NAME)   goto CONTINUE_##NAME; CONTINUE_##NAME: continue; goto BREAK_##NAME; BREAK_##NAME: break;
                                    // these redundant goto's to avoid 'unused label' warnings


#if defined(_MSC_VER)
   // MSVC can't handle 'inline constexpr' variables yet in all cases
    #define CPP2_CONSTEXPR const
#else
    #define CPP2_CONSTEXPR constexpr
#endif


#ifdef CPP2_USE_SOURCE_LOCATION
    #define CPP2_SOURCE_LOCATION_PARAM              , [[maybe_unused]] std::source_location where
    #define CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT , [[maybe_unused]] std::source_location where = std::source_location::current()
    #define CPP2_SOURCE_LOCATION_PARAM_SOLO         [[maybe_unused]] std::source_location where
    #define CPP2_SOURCE_LOCATION_ARG                , where
    #define CPP2_SOURCE_LOCATION_VALUE              (cpp2::to_string(where.file_name()) + "(" + cpp2::to_string(where.line()) + ") " + where.function_name())
#else
    #define CPP2_SOURCE_LOCATION_PARAM
    #define CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT
    #define CPP2_SOURCE_LOCATION_PARAM_SOLO
    #define CPP2_SOURCE_LOCATION_ARG
    #define CPP2_SOURCE_LOCATION_VALUE              std::string("")
#endif

//  For C++23: make this std::string_view and drop the macro
//      Before C++23 std::string_view was not guaranteed to be trivially copyable,
//      and so in<T> will pass it by const& and really it should be by value
#define CPP2_MESSAGE_PARAM  char const*
#define CPP2_CONTRACT_MSG   cpp2::message_to_cstr_adapter


#define CPP2_ASSERT_NOT_ZERO(NumType, arg)          (cpp2::impl::assert_not_zero<NumType>((arg)))
#define CPP2_ASSERT_NOT_ZERO_LITERAL(NumType, arg)  (cpp2::impl::assert_not_zero<NumType, (arg)>('_'))

#define CPP2_ASSERT_IN_BOUNDS(x,arg)         (cpp2::impl::assert_in_bounds((x),(arg)))
#define CPP2_ASSERT_IN_BOUNDS_LITERAL(x,arg) (cpp2::impl::assert_in_bounds<(arg)>(x))


//-----------------------------------------------------------------------
//
//  CPP2_UFCS: Variadic macro generating a variadic lambda, oh my...
//
//-----------------------------------------------------------------------
//
// Workaround <https://github.com/llvm/llvm-project/issues/70556>.
#define CPP2_FORCE_INLINE_LAMBDA_CLANG /* empty */

#if defined(_MSC_VER) && !defined(__clang_major__)
    #define CPP2_FORCE_INLINE              __forceinline
    #define CPP2_FORCE_INLINE_LAMBDA       [[msvc::forceinline]]
    #define CPP2_LAMBDA_NO_DISCARD
#else
    #define CPP2_FORCE_INLINE              __attribute__((always_inline))
    #if defined(__clang__)
        #define CPP2_FORCE_INLINE_LAMBDA       /* empty */
        #undef CPP2_FORCE_INLINE_LAMBDA_CLANG
        #define CPP2_FORCE_INLINE_LAMBDA_CLANG __attribute__((always_inline))
    #else
        #define CPP2_FORCE_INLINE_LAMBDA       __attribute__((always_inline))
    #endif

    #if defined(__clang_major__)
        //  Also check __cplusplus, only to satisfy Clang -pedantic-errors
        #if __cplusplus >= 202302L && (__clang_major__ > 13 || (__clang_major__ == 13 && __clang_minor__ >= 2))
            #define CPP2_LAMBDA_NO_DISCARD   [[nodiscard]]
        #else
            #define CPP2_LAMBDA_NO_DISCARD
        #endif
    #elif defined(__GNUC__)
        #if __GNUC__ >= 9
            #define CPP2_LAMBDA_NO_DISCARD   [[nodiscard]]
        #else
            #define CPP2_LAMBDA_NO_DISCARD
        #endif
        #if ((__GNUC__ * 100) + __GNUC_MINOR__) < 1003
            //  GCC 10.2 doesn't support this feature (10.3 is fine)
            #undef  CPP2_FORCE_INLINE_LAMBDA
            #define CPP2_FORCE_INLINE_LAMBDA
        #endif
    #else
        #define CPP2_LAMBDA_NO_DISCARD
    #endif
#endif

#define CPP2_UFCS_EMPTY(...)
#define CPP2_UFCS_IDENTITY(...)  __VA_ARGS__
#define CPP2_UFCS_REMPARENS(...) __VA_ARGS__

// Ideally, the expression `CPP2_UFCS_IS_NOTHROW` expands to
// is in the _noexcept-specifier_ of the UFCS lambda, but without 'std::declval'.
// To workaround [GCC bug 101043](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=101043),
// we instead make it a template parameter of the UFCS lambda.
// But using a template parameter, Clang also ICEs on an application.
// So we use these `NOTHROW` macros to fall back to the ideal for when not using GCC.
#define CPP2_UFCS_IS_NOTHROW(MVFWD,QUALID,TEMPKW,...) \
   requires { requires  requires { std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...); }; \
              requires    noexcept(std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...)); } \
|| requires { requires !requires { std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...); }; \
              requires noexcept(MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(std::declval<Obj>(), std::declval<Params>()...)); }
#define CPP2_UFCS_IS_NOTHROW_PARAM(...)                     /*empty*/
#define CPP2_UFCS_IS_NOTHROW_ARG(MVFWD,QUALID,TEMPKW,...)   CPP2_UFCS_IS_NOTHROW(MVFWD,QUALID,TEMPKW,__VA_ARGS__)
#if defined(__GNUC__) && !defined(__clang__)
    #undef  CPP2_UFCS_IS_NOTHROW_PARAM
    #undef  CPP2_UFCS_IS_NOTHROW_ARG
    #define CPP2_UFCS_IS_NOTHROW_PARAM(MVFWD,QUALID,TEMPKW,...) , bool IsNothrow = CPP2_UFCS_IS_NOTHROW(MVFWD,QUALID,TEMPKW,__VA_ARGS__)
    #define CPP2_UFCS_IS_NOTHROW_ARG(...)                       IsNothrow
    #if __GNUC__ < 11
        #undef  CPP2_UFCS_IS_NOTHROW_PARAM
        #undef  CPP2_UFCS_IS_NOTHROW_ARG
        #define CPP2_UFCS_IS_NOTHROW_PARAM(...)    /*empty*/
        #define CPP2_UFCS_IS_NOTHROW_ARG(...)      false // GCC 10 UFCS is always potentially-throwing.
    #endif
#endif

// Ideally, the expression `CPP2_UFCS_CONSTRAINT_ARG` expands to
// is in the _requires-clause_ of the UFCS lambda.
// To workaround an MSVC bug within a member function 'F' where UFCS is also for 'F'
// (<https://github.com/hsutter/cppfront/pull/506#issuecomment-1826086952>),
// we instead make it a template parameter of the UFCS lambda.
// But using a template parameter, Clang also ICEs and GCC rejects a local 'F'.
// Also, Clang rejects the SFINAE test case when using 'std::declval'.
// So we use these `CONSTRAINT` macros to fall back to the ideal for when not using MSVC.
#define CPP2_UFCS_CONSTRAINT_PARAM(...)                   /*empty*/
#define CPP2_UFCS_CONSTRAINT_ARG(MVFWD,QUALID,TEMPKW,...) \
   requires { CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); } \
|| requires { MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); }
#if defined(_MSC_VER)
    #undef  CPP2_UFCS_CONSTRAINT_PARAM
    #undef  CPP2_UFCS_CONSTRAINT_ARG
    #define CPP2_UFCS_CONSTRAINT_PARAM(MVFWD,QUALID,TEMPKW,...) , bool IsViable = \
   requires { std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...); } \
|| requires { MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(std::declval<Obj>(), std::declval<Params>()...); }
    #define CPP2_UFCS_CONSTRAINT_ARG(...)                 IsViable
#endif

#define CPP2_UFCS_(LAMBDADEFCAPT,SFINAE,MVFWD,QUALID,TEMPKW,...) \
[LAMBDADEFCAPT]< \
    typename Obj, typename... Params \
    CPP2_UFCS_IS_NOTHROW_PARAM(MVFWD,QUALID,TEMPKW,__VA_ARGS__) \
    CPP2_UFCS_CONSTRAINT_PARAM(MVFWD,QUALID,TEMPKW,__VA_ARGS__) \
  > \
  CPP2_LAMBDA_NO_DISCARD (Obj&& obj, Params&& ...params) CPP2_FORCE_INLINE_LAMBDA_CLANG \
  noexcept(CPP2_UFCS_IS_NOTHROW_ARG(MVFWD,QUALID,TEMPKW,__VA_ARGS__)) CPP2_FORCE_INLINE_LAMBDA -> decltype(auto) \
    SFINAE( requires CPP2_UFCS_CONSTRAINT_ARG(MVFWD,QUALID,TEMPKW,__VA_ARGS__) ) \
  { \
    if constexpr      (requires{ CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); }) { \
        return                   CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); \
    } \
    else if constexpr (requires{ MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); }) { \
        return                   MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); \
    } \
    else if constexpr (requires{ obj.CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); }) { \
        static_assert( cpp2::impl::dependent_false<Obj>::value, "error: implicit discard of an object's modified value is not allowed - this function call modifies 'obj', but 'obj' is never used again in the function so the new value is never used - if that's what you intended, add another line '_ = obj;' afterward to explicitly discard the new value of the object" ); \
        CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); \
        MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); \
    } \
    else if constexpr (requires{ MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(obj, CPP2_FORWARD(params)...); }) { \
        static_assert( cpp2::impl::dependent_false<Obj>::value, "error: implicit discard of an object's modified value is not allowed - this function call modifies 'obj', but 'obj' is never used again in the function so the new value is never used - if that's what you intended, add another line '_ = obj;' afterward to explicitly discard the new value of the object" ); \
        CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); \
        MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); \
    } \
    else { \
        static_assert( cpp2::impl::dependent_false<Obj>::value, "this function call syntax tries 'obj.func(...)', then 'func(obj,...);', but both failed - if this function call is passing a local variable that will be modified by the function, but that variable is never used again in the function so the new value is never used, that's likely the problem - if that's what you intended, add another line '_ = obj;' afterward to explicitly discard the new value of the object" ); \
        CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); \
        MVFWD(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__)(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); \
    } \
  }

#define CPP2_UFCS(...)                                    CPP2_UFCS_(&,CPP2_UFCS_EMPTY,CPP2_UFCS_IDENTITY,(),,__VA_ARGS__)
#define CPP2_UFCS_MOVE(...)                               CPP2_UFCS_(&,CPP2_UFCS_EMPTY,std::move,(),,__VA_ARGS__)
#define CPP2_UFCS_FORWARD(...)                            CPP2_UFCS_(&,CPP2_UFCS_EMPTY,CPP2_FORWARD,(),,__VA_ARGS__)
#define CPP2_UFCS_TEMPLATE(...)                           CPP2_UFCS_(&,CPP2_UFCS_EMPTY,CPP2_UFCS_IDENTITY,(),template,__VA_ARGS__)
#define CPP2_UFCS_QUALIFIED_TEMPLATE(QUALID,...)          CPP2_UFCS_(&,CPP2_UFCS_EMPTY,CPP2_UFCS_IDENTITY,QUALID,template,__VA_ARGS__)
#define CPP2_UFCS_NONLOCAL(...)                           CPP2_UFCS_(,CPP2_UFCS_IDENTITY,CPP2_UFCS_IDENTITY,(),,__VA_ARGS__)
#define CPP2_UFCS_TEMPLATE_NONLOCAL(...)                  CPP2_UFCS_(,CPP2_UFCS_IDENTITY,CPP2_UFCS_IDENTITY,(),template,__VA_ARGS__)
#define CPP2_UFCS_QUALIFIED_TEMPLATE_NONLOCAL(QUALID,...) CPP2_UFCS_(,CPP2_UFCS_IDENTITY,CPP2_UFCS_IDENTITY,QUALID,template,__VA_ARGS__)


//  Work around MSVC modules bugs: source_location doesn't work correctly if imported via a module
#if defined(_MSC_VER) && defined(CPP2_IMPORT_STD)
    #define CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT_AS
    #define CPP2_SOURCE_LOCATION_ARG_AS
#else
    #define CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT_AS    CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT
    #define CPP2_SOURCE_LOCATION_ARG_AS                   CPP2_SOURCE_LOCATION_ARG
#endif


//  Stabilize line numbers for "compatibility" static assertions that we know
//  will fire for some compilers, to keep regression test outputs cleaner
#line 9999

//  GCC 10 doesn't support 'requires' in forward declarations in some cases
//  Workaround: Disable the requires clause where that gets reasonable behavior
//  Diagnostic: static_assert the other cases that can't be worked around
#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ == 10
    #define CPP2_REQUIRES(...) /* empty */
    #define CPP2_REQUIRES_(...) static_assert(false, "GCC 11 or higher is required to support variables and type-scope functions that have a 'requires' clause. This includes a type-scope 'forward' parameter of non-wildcard type, such as 'func: (this, forward s: std::string)', which relies on being able to add a 'requires' clause - in that case, use 'forward s: _' instead if you need the result to compile with GCC 10.")
#else
    #define CPP2_REQUIRES(...) requires (__VA_ARGS__)
    #define CPP2_REQUIRES_(...) requires (__VA_ARGS__)
#endif

#endif // CPP2_CPP2UTIL_PRE_H
