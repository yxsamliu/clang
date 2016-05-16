//===--- opencl-c.h - OpenCL C language builtin function header -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _OPENCL_H_
#define _OPENCL_H_

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
#ifndef cl_khr_depth_images
#define cl_khr_depth_images
#endif //cl_khr_depth_images
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

#define __overload __attribute__((overloadable))

// Optimizations

#define __const_func __attribute__((const, overloadable))

// built-in scalar data types:

/**
 * An unsigned 8-bit integer.
 */
typedef unsigned char uchar;

/**
 * An unsigned 16-bit integer.
 */
typedef unsigned short ushort;

/**
 * An unsigned 32-bit integer.
 */
typedef unsigned int uint;

/**
 * An unsigned 64-bit integer.
 */
typedef unsigned long ulong;

/**
 * The unsigned integer type of the result of the sizeof operator. This
 * is a 32-bit unsigned integer if CL_DEVICE_ADDRESS_BITS
 * defined in table 4.3 is 32-bits and is a 64-bit unsigned integer if
 * CL_DEVICE_ADDRESS_BITS is 64-bits.
 */
typedef __SIZE_TYPE__ size_t;

/**
 * A signed integer type that is the result of subtracting two pointers.
 * This is a 32-bit signed integer if CL_DEVICE_ADDRESS_BITS
 * defined in table 4.3 is 32-bits and is a 64-bit signed integer if
 * CL_DEVICE_ADDRESS_BITS is 64-bits.
 */
typedef __PTRDIFF_TYPE__ ptrdiff_t;

/**
* A signed integer type with the property that any valid pointer to
* void can be converted to this type, then converted back to pointer
* to void, and the result will compare equal to the original pointer.
*/
typedef __INTPTR_TYPE__ intptr_t;

/**
* An unsigned integer type with the property that any valid pointer to
* void can be converted to this type, then converted back to pointer
* to void, and the result will compare equal to the original pointer.
*/
typedef __UINTPTR_TYPE__ uintptr_t;

// built-in vector data types:
typedef char char2 __attribute__((ext_vector_type(2)));
typedef char char3 __attribute__((ext_vector_type(3)));
typedef char char4 __attribute__((ext_vector_type(4)));
typedef char char8 __attribute__((ext_vector_type(8)));
typedef char char16 __attribute__((ext_vector_type(16)));
typedef uchar uchar2 __attribute__((ext_vector_type(2)));
typedef uchar uchar3 __attribute__((ext_vector_type(3)));
typedef uchar uchar4 __attribute__((ext_vector_type(4)));
typedef uchar uchar8 __attribute__((ext_vector_type(8)));
typedef uchar uchar16 __attribute__((ext_vector_type(16)));
typedef short short2 __attribute__((ext_vector_type(2)));
typedef short short3 __attribute__((ext_vector_type(3)));
typedef short short4 __attribute__((ext_vector_type(4)));
typedef short short8 __attribute__((ext_vector_type(8)));
typedef short short16 __attribute__((ext_vector_type(16)));
typedef ushort ushort2 __attribute__((ext_vector_type(2)));
typedef ushort ushort3 __attribute__((ext_vector_type(3)));
typedef ushort ushort4 __attribute__((ext_vector_type(4)));
typedef ushort ushort8 __attribute__((ext_vector_type(8)));
typedef ushort ushort16 __attribute__((ext_vector_type(16)));
typedef int int2 __attribute__((ext_vector_type(2)));
typedef int int3 __attribute__((ext_vector_type(3)));
typedef int int4 __attribute__((ext_vector_type(4)));
typedef int int8 __attribute__((ext_vector_type(8)));
typedef int int16 __attribute__((ext_vector_type(16)));
typedef uint uint2 __attribute__((ext_vector_type(2)));
typedef uint uint3 __attribute__((ext_vector_type(3)));
typedef uint uint4 __attribute__((ext_vector_type(4)));
typedef uint uint8 __attribute__((ext_vector_type(8)));
typedef uint uint16 __attribute__((ext_vector_type(16)));
typedef long long2 __attribute__((ext_vector_type(2)));
typedef long long3 __attribute__((ext_vector_type(3)));
typedef long long4 __attribute__((ext_vector_type(4)));
typedef long long8 __attribute__((ext_vector_type(8)));
typedef long long16 __attribute__((ext_vector_type(16)));
typedef ulong ulong2 __attribute__((ext_vector_type(2)));
typedef ulong ulong3 __attribute__((ext_vector_type(3)));
typedef ulong ulong4 __attribute__((ext_vector_type(4)));
typedef ulong ulong8 __attribute__((ext_vector_type(8)));
typedef ulong ulong16 __attribute__((ext_vector_type(16)));
typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float3 __attribute__((ext_vector_type(3)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));
typedef float float16 __attribute__((ext_vector_type(16)));
#ifdef cl_khr_fp16
#pragma OPENCL EXTENSION cl_khr_fp16 : enable
typedef half half2 __attribute__((ext_vector_type(2)));
typedef half half3 __attribute__((ext_vector_type(3)));
typedef half half4 __attribute__((ext_vector_type(4)));
typedef half half8 __attribute__((ext_vector_type(8)));
typedef half half16 __attribute__((ext_vector_type(16)));
#endif
#ifdef cl_khr_fp64
#if __OPENCL_C_VERSION__ < CL_VERSION_1_2
#pragma OPENCL EXTENSION cl_khr_fp64 : enable
#endif
typedef double double2 __attribute__((ext_vector_type(2)));
typedef double double3 __attribute__((ext_vector_type(3)));
typedef double double4 __attribute__((ext_vector_type(4)));
typedef double double8 __attribute__((ext_vector_type(8)));
typedef double double16 __attribute__((ext_vector_type(16)));
#endif

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
#define NULL                              ((void*)0)
#endif

/**
 * Value of maximum non-infinite single-precision floating-point
 * number.
 */
#define MAXFLOAT    0x1.fffffep127f

/**
 * A positive float constant expression. HUGE_VALF evaluates
 * to +infinity. Used as an error value returned by the built-in
 * math functions.
 */
#define HUGE_VALF (__builtin_huge_valf())

/**
 * A positive double constant expression. HUGE_VAL evaluates
 * to +infinity. Used as an error value returned by the built-in
 * math functions.
 */
#define HUGE_VAL (__builtin_huge_val())

/**
 * A constant expression of type float representing positive or
 * unsigned infinity.
 */
#define INFINITY (__builtin_inff())

/**
 * A constant expression of type float representing a quiet NaN.
 */
#define NAN as_float(INT_MAX)

#define FP_ILOGB0    INT_MIN
#define FP_ILOGBNAN    INT_MAX

#define FLT_DIG 6
#define FLT_MANT_DIG 24
#define FLT_MAX_10_EXP +38
#define FLT_MAX_EXP +128
#define FLT_MIN_10_EXP -37
#define FLT_MIN_EXP -125
#define FLT_RADIX 2
#define FLT_MAX 0x1.fffffep127f
#define FLT_MIN 0x1.0p-126f
#define FLT_EPSILON 0x1.0p-23f

#define M_E_F         2.71828182845904523536028747135266250f
#define M_LOG2E_F     1.44269504088896340735992468100189214f
#define M_LOG10E_F    0.434294481903251827651128918916605082f
#define M_LN2_F       0.693147180559945309417232121458176568f
#define M_LN10_F      2.30258509299404568401799145468436421f
#define M_PI_F        3.14159265358979323846264338327950288f
#define M_PI_2_F      1.57079632679489661923132169163975144f
#define M_PI_4_F      0.785398163397448309615660845819875721f
#define M_1_PI_F      0.318309886183790671537767526745028724f
#define M_2_PI_F      0.636619772367581343075535053490057448f
#define M_2_SQRTPI_F  1.12837916709551257389615890312154517f
#define M_SQRT2_F     1.41421356237309504880168872420969808f
#define M_SQRT1_2_F   0.707106781186547524400844362104849039f

#define DBL_DIG 15
#define DBL_MANT_DIG 53
#define DBL_MAX_10_EXP +308
#define DBL_MAX_EXP +1024
#define DBL_MIN_10_EXP -307
#define DBL_MIN_EXP -1021
#define DBL_RADIX 2
#define DBL_MAX 0x1.fffffffffffffp1023
#define DBL_MIN 0x1.0p-1022
#define DBL_EPSILON 0x1.0p-52

#define M_E           0x1.5bf0a8b145769p+1
#define M_LOG2E       0x1.71547652b82fep+0
#define M_LOG10E      0x1.bcb7b1526e50ep-2
#define M_LN2         0x1.62e42fefa39efp-1
#define M_LN10        0x1.26bb1bbb55516p+1
#define M_PI          0x1.921fb54442d18p+1
#define M_PI_2        0x1.921fb54442d18p+0
#define M_PI_4        0x1.921fb54442d18p-1
#define M_1_PI        0x1.45f306dc9c883p-2
#define M_2_PI        0x1.45f306dc9c883p-1
#define M_2_SQRTPI    0x1.20dd750429b6dp+0
#define M_SQRT2       0x1.6a09e667f3bcdp+0
#define M_SQRT1_2     0x1.6a09e667f3bcdp-1

#ifdef cl_khr_fp16

#define HALF_DIG 3
#define HALF_MANT_DIG 11
#define HALF_MAX_10_EXP +4
#define HALF_MAX_EXP +16
#define HALF_MIN_10_EXP -4
#define HALF_MIN_EXP -13
#define HALF_RADIX 2
#define HALF_MAX ((0x1.ffcp15h))
#define HALF_MIN ((0x1.0p-14h))
#define HALF_EPSILON ((0x1.0p-10h))

#define M_E_H         2.71828182845904523536028747135266250h
#define M_LOG2E_H     1.44269504088896340735992468100189214h
#define M_LOG10E_H    0.434294481903251827651128918916605082h
#define M_LN2_H       0.693147180559945309417232121458176568h
#define M_LN10_H      2.30258509299404568401799145468436421h
#define M_PI_H        3.14159265358979323846264338327950288h
#define M_PI_2_H      1.57079632679489661923132169163975144h
#define M_PI_4_H      0.785398163397448309615660845819875721h
#define M_1_PI_H      0.318309886183790671537767526745028724h
#define M_2_PI_H      0.636619772367581343075535053490057448h
#define M_2_SQRTPI_H  1.12837916709551257389615890312154517h
#define M_SQRT2_H     1.41421356237309504880168872420969808h
#define M_SQRT1_2_H   0.707106781186547524400844362104849039h

#endif //cl_khr_fp16

#define CHAR_BIT    8
#define SCHAR_MAX  127
#define SCHAR_MIN  (-128)
#define UCHAR_MAX  255
#define CHAR_MAX  SCHAR_MAX
#define CHAR_MIN  SCHAR_MIN
#define USHRT_MAX  65535
#define SHRT_MAX  32767
#define SHRT_MIN  (-32768)
#define UINT_MAX  0xffffffff
#define INT_MAX    2147483647
#define INT_MIN    (-2147483647-1)
#define ULONG_MAX  0xffffffffffffffffUL
#define LONG_MAX  0x7fffffffffffffffL
#define LONG_MIN  (-0x7fffffffffffffffL-1)

// OpenCL v1.1/1.2/2.0 s6.2.3 - Explicit conversions

char __const_func convert_char_rte(char);
char __const_func convert_char_sat_rte(char);
char __const_func convert_char_rtz(char);
char __const_func convert_char_sat_rtz(char);
char __const_func convert_char_rtp(char);
char __const_func convert_char_sat_rtp(char);
char __const_func convert_char_rtn(char);
char __const_func convert_char_sat_rtn(char);
char __const_func convert_char(char);
char __const_func convert_char_sat(char);
char __const_func convert_char_rte(uchar);
char __const_func convert_char_sat_rte(uchar);
char __const_func convert_char_rtz(uchar);
char __const_func convert_char_sat_rtz(uchar);
char __const_func convert_char_rtp(uchar);
char __const_func convert_char_sat_rtp(uchar);
char __const_func convert_char_rtn(uchar);
char __const_func convert_char_sat_rtn(uchar);
char __const_func convert_char(uchar);
char __const_func convert_char_sat(uchar);
char __const_func convert_char_rte(short);
char __const_func convert_char_sat_rte(short);
char __const_func convert_char_rtz(short);
char __const_func convert_char_sat_rtz(short);
char __const_func convert_char_rtp(short);
char __const_func convert_char_sat_rtp(short);
char __const_func convert_char_rtn(short);
char __const_func convert_char_sat_rtn(short);
char __const_func convert_char(short);
char __const_func convert_char_sat(short);
char __const_func convert_char_rte(ushort);
char __const_func convert_char_sat_rte(ushort);
char __const_func convert_char_rtz(ushort);
char __const_func convert_char_sat_rtz(ushort);
char __const_func convert_char_rtp(ushort);
char __const_func convert_char_sat_rtp(ushort);
char __const_func convert_char_rtn(ushort);
char __const_func convert_char_sat_rtn(ushort);
char __const_func convert_char(ushort);
char __const_func convert_char_sat(ushort);
char __const_func convert_char_rte(int);
char __const_func convert_char_sat_rte(int);
char __const_func convert_char_rtz(int);
char __const_func convert_char_sat_rtz(int);
char __const_func convert_char_rtp(int);
char __const_func convert_char_sat_rtp(int);
char __const_func convert_char_rtn(int);
char __const_func convert_char_sat_rtn(int);
char __const_func convert_char(int);
char __const_func convert_char_sat(int);
char __const_func convert_char_rte(uint);
char __const_func convert_char_sat_rte(uint);
char __const_func convert_char_rtz(uint);
char __const_func convert_char_sat_rtz(uint);
char __const_func convert_char_rtp(uint);
char __const_func convert_char_sat_rtp(uint);
char __const_func convert_char_rtn(uint);
char __const_func convert_char_sat_rtn(uint);
char __const_func convert_char(uint);
char __const_func convert_char_sat(uint);
char __const_func convert_char_rte(long);
char __const_func convert_char_sat_rte(long);
char __const_func convert_char_rtz(long);
char __const_func convert_char_sat_rtz(long);
char __const_func convert_char_rtp(long);
char __const_func convert_char_sat_rtp(long);
char __const_func convert_char_rtn(long);
char __const_func convert_char_sat_rtn(long);
char __const_func convert_char(long);
char __const_func convert_char_sat(long);
char __const_func convert_char_rte(ulong);
char __const_func convert_char_sat_rte(ulong);
char __const_func convert_char_rtz(ulong);
char __const_func convert_char_sat_rtz(ulong);
char __const_func convert_char_rtp(ulong);
char __const_func convert_char_sat_rtp(ulong);
char __const_func convert_char_rtn(ulong);
char __const_func convert_char_sat_rtn(ulong);
char __const_func convert_char(ulong);
char __const_func convert_char_sat(ulong);
char __const_func convert_char_rte(float);
char __const_func convert_char_sat_rte(float);
char __const_func convert_char_rtz(float);
char __const_func convert_char_sat_rtz(float);
char __const_func convert_char_rtp(float);
char __const_func convert_char_sat_rtp(float);
char __const_func convert_char_rtn(float);
char __const_func convert_char_sat_rtn(float);
char __const_func convert_char(float);
char __const_func convert_char_sat(float);
uchar __const_func convert_uchar_rte(char);
uchar __const_func convert_uchar_sat_rte(char);
uchar __const_func convert_uchar_rtz(char);
uchar __const_func convert_uchar_sat_rtz(char);
uchar __const_func convert_uchar_rtp(char);
uchar __const_func convert_uchar_sat_rtp(char);
uchar __const_func convert_uchar_rtn(char);
uchar __const_func convert_uchar_sat_rtn(char);
uchar __const_func convert_uchar(char);
uchar __const_func convert_uchar_sat(char);
uchar __const_func convert_uchar_rte(uchar);
uchar __const_func convert_uchar_sat_rte(uchar);
uchar __const_func convert_uchar_rtz(uchar);
uchar __const_func convert_uchar_sat_rtz(uchar);
uchar __const_func convert_uchar_rtp(uchar);
uchar __const_func convert_uchar_sat_rtp(uchar);
uchar __const_func convert_uchar_rtn(uchar);
uchar __const_func convert_uchar_sat_rtn(uchar);
uchar __const_func convert_uchar(uchar);
uchar __const_func convert_uchar_sat(uchar);
uchar __const_func convert_uchar_rte(short);
uchar __const_func convert_uchar_sat_rte(short);
uchar __const_func convert_uchar_rtz(short);
uchar __const_func convert_uchar_sat_rtz(short);
uchar __const_func convert_uchar_rtp(short);
uchar __const_func convert_uchar_sat_rtp(short);
uchar __const_func convert_uchar_rtn(short);
uchar __const_func convert_uchar_sat_rtn(short);
uchar __const_func convert_uchar(short);
uchar __const_func convert_uchar_sat(short);
uchar __const_func convert_uchar_rte(ushort);
uchar __const_func convert_uchar_sat_rte(ushort);
uchar __const_func convert_uchar_rtz(ushort);
uchar __const_func convert_uchar_sat_rtz(ushort);
uchar __const_func convert_uchar_rtp(ushort);
uchar __const_func convert_uchar_sat_rtp(ushort);
uchar __const_func convert_uchar_rtn(ushort);
uchar __const_func convert_uchar_sat_rtn(ushort);
uchar __const_func convert_uchar(ushort);
uchar __const_func convert_uchar_sat(ushort);
uchar __const_func convert_uchar_rte(int);
uchar __const_func convert_uchar_sat_rte(int);
uchar __const_func convert_uchar_rtz(int);
uchar __const_func convert_uchar_sat_rtz(int);
uchar __const_func convert_uchar_rtp(int);
uchar __const_func convert_uchar_sat_rtp(int);
uchar __const_func convert_uchar_rtn(int);
uchar __const_func convert_uchar_sat_rtn(int);
uchar __const_func convert_uchar(int);
uchar __const_func convert_uchar_sat(int);
uchar __const_func convert_uchar_rte(uint);
uchar __const_func convert_uchar_sat_rte(uint);
uchar __const_func convert_uchar_rtz(uint);
uchar __const_func convert_uchar_sat_rtz(uint);
uchar __const_func convert_uchar_rtp(uint);
uchar __const_func convert_uchar_sat_rtp(uint);
uchar __const_func convert_uchar_rtn(uint);
uchar __const_func convert_uchar_sat_rtn(uint);
uchar __const_func convert_uchar(uint);
uchar __const_func convert_uchar_sat(uint);
uchar __const_func convert_uchar_rte(long);
uchar __const_func convert_uchar_sat_rte(long);
uchar __const_func convert_uchar_rtz(long);
uchar __const_func convert_uchar_sat_rtz(long);
uchar __const_func convert_uchar_rtp(long);
uchar __const_func convert_uchar_sat_rtp(long);
uchar __const_func convert_uchar_rtn(long);
uchar __const_func convert_uchar_sat_rtn(long);
uchar __const_func convert_uchar(long);
uchar __const_func convert_uchar_sat(long);
uchar __const_func convert_uchar_rte(ulong);
uchar __const_func convert_uchar_sat_rte(ulong);
uchar __const_func convert_uchar_rtz(ulong);
uchar __const_func convert_uchar_sat_rtz(ulong);
uchar __const_func convert_uchar_rtp(ulong);
uchar __const_func convert_uchar_sat_rtp(ulong);
uchar __const_func convert_uchar_rtn(ulong);
uchar __const_func convert_uchar_sat_rtn(ulong);
uchar __const_func convert_uchar(ulong);
uchar __const_func convert_uchar_sat(ulong);
uchar __const_func convert_uchar_rte(float);
uchar __const_func convert_uchar_sat_rte(float);
uchar __const_func convert_uchar_rtz(float);
uchar __const_func convert_uchar_sat_rtz(float);
uchar __const_func convert_uchar_rtp(float);
uchar __const_func convert_uchar_sat_rtp(float);
uchar __const_func convert_uchar_rtn(float);
uchar __const_func convert_uchar_sat_rtn(float);
uchar __const_func convert_uchar(float);
uchar __const_func convert_uchar_sat(float);

short __const_func convert_short_rte(char);
short __const_func convert_short_sat_rte(char);
short __const_func convert_short_rtz(char);
short __const_func convert_short_sat_rtz(char);
short __const_func convert_short_rtp(char);
short __const_func convert_short_sat_rtp(char);
short __const_func convert_short_rtn(char);
short __const_func convert_short_sat_rtn(char);
short __const_func convert_short(char);
short __const_func convert_short_sat(char);
short __const_func convert_short_rte(uchar);
short __const_func convert_short_sat_rte(uchar);
short __const_func convert_short_rtz(uchar);
short __const_func convert_short_sat_rtz(uchar);
short __const_func convert_short_rtp(uchar);
short __const_func convert_short_sat_rtp(uchar);
short __const_func convert_short_rtn(uchar);
short __const_func convert_short_sat_rtn(uchar);
short __const_func convert_short(uchar);
short __const_func convert_short_sat(uchar);
short __const_func convert_short_rte(short);
short __const_func convert_short_sat_rte(short);
short __const_func convert_short_rtz(short);
short __const_func convert_short_sat_rtz(short);
short __const_func convert_short_rtp(short);
short __const_func convert_short_sat_rtp(short);
short __const_func convert_short_rtn(short);
short __const_func convert_short_sat_rtn(short);
short __const_func convert_short(short);
short __const_func convert_short_sat(short);
short __const_func convert_short_rte(ushort);
short __const_func convert_short_sat_rte(ushort);
short __const_func convert_short_rtz(ushort);
short __const_func convert_short_sat_rtz(ushort);
short __const_func convert_short_rtp(ushort);
short __const_func convert_short_sat_rtp(ushort);
short __const_func convert_short_rtn(ushort);
short __const_func convert_short_sat_rtn(ushort);
short __const_func convert_short(ushort);
short __const_func convert_short_sat(ushort);
short __const_func convert_short_rte(int);
short __const_func convert_short_sat_rte(int);
short __const_func convert_short_rtz(int);
short __const_func convert_short_sat_rtz(int);
short __const_func convert_short_rtp(int);
short __const_func convert_short_sat_rtp(int);
short __const_func convert_short_rtn(int);
short __const_func convert_short_sat_rtn(int);
short __const_func convert_short(int);
short __const_func convert_short_sat(int);
short __const_func convert_short_rte(uint);
short __const_func convert_short_sat_rte(uint);
short __const_func convert_short_rtz(uint);
short __const_func convert_short_sat_rtz(uint);
short __const_func convert_short_rtp(uint);
short __const_func convert_short_sat_rtp(uint);
short __const_func convert_short_rtn(uint);
short __const_func convert_short_sat_rtn(uint);
short __const_func convert_short(uint);
short __const_func convert_short_sat(uint);
short __const_func convert_short_rte(long);
short __const_func convert_short_sat_rte(long);
short __const_func convert_short_rtz(long);
short __const_func convert_short_sat_rtz(long);
short __const_func convert_short_rtp(long);
short __const_func convert_short_sat_rtp(long);
short __const_func convert_short_rtn(long);
short __const_func convert_short_sat_rtn(long);
short __const_func convert_short(long);
short __const_func convert_short_sat(long);
short __const_func convert_short_rte(ulong);
short __const_func convert_short_sat_rte(ulong);
short __const_func convert_short_rtz(ulong);
short __const_func convert_short_sat_rtz(ulong);
short __const_func convert_short_rtp(ulong);
short __const_func convert_short_sat_rtp(ulong);
short __const_func convert_short_rtn(ulong);
short __const_func convert_short_sat_rtn(ulong);
short __const_func convert_short(ulong);
short __const_func convert_short_sat(ulong);
short __const_func convert_short_rte(float);
short __const_func convert_short_sat_rte(float);
short __const_func convert_short_rtz(float);
short __const_func convert_short_sat_rtz(float);
short __const_func convert_short_rtp(float);
short __const_func convert_short_sat_rtp(float);
short __const_func convert_short_rtn(float);
short __const_func convert_short_sat_rtn(float);
short __const_func convert_short(float);
short __const_func convert_short_sat(float);
ushort __const_func convert_ushort_rte(char);
ushort __const_func convert_ushort_sat_rte(char);
ushort __const_func convert_ushort_rtz(char);
ushort __const_func convert_ushort_sat_rtz(char);
ushort __const_func convert_ushort_rtp(char);
ushort __const_func convert_ushort_sat_rtp(char);
ushort __const_func convert_ushort_rtn(char);
ushort __const_func convert_ushort_sat_rtn(char);
ushort __const_func convert_ushort(char);
ushort __const_func convert_ushort_sat(char);
ushort __const_func convert_ushort_rte(uchar);
ushort __const_func convert_ushort_sat_rte(uchar);
ushort __const_func convert_ushort_rtz(uchar);
ushort __const_func convert_ushort_sat_rtz(uchar);
ushort __const_func convert_ushort_rtp(uchar);
ushort __const_func convert_ushort_sat_rtp(uchar);
ushort __const_func convert_ushort_rtn(uchar);
ushort __const_func convert_ushort_sat_rtn(uchar);
ushort __const_func convert_ushort(uchar);
ushort __const_func convert_ushort_sat(uchar);
ushort __const_func convert_ushort_rte(short);
ushort __const_func convert_ushort_sat_rte(short);
ushort __const_func convert_ushort_rtz(short);
ushort __const_func convert_ushort_sat_rtz(short);
ushort __const_func convert_ushort_rtp(short);
ushort __const_func convert_ushort_sat_rtp(short);
ushort __const_func convert_ushort_rtn(short);
ushort __const_func convert_ushort_sat_rtn(short);
ushort __const_func convert_ushort(short);
ushort __const_func convert_ushort_sat(short);
ushort __const_func convert_ushort_rte(ushort);
ushort __const_func convert_ushort_sat_rte(ushort);
ushort __const_func convert_ushort_rtz(ushort);
ushort __const_func convert_ushort_sat_rtz(ushort);
ushort __const_func convert_ushort_rtp(ushort);
ushort __const_func convert_ushort_sat_rtp(ushort);
ushort __const_func convert_ushort_rtn(ushort);
ushort __const_func convert_ushort_sat_rtn(ushort);
ushort __const_func convert_ushort(ushort);
ushort __const_func convert_ushort_sat(ushort);
ushort __const_func convert_ushort_rte(int);
ushort __const_func convert_ushort_sat_rte(int);
ushort __const_func convert_ushort_rtz(int);
ushort __const_func convert_ushort_sat_rtz(int);
ushort __const_func convert_ushort_rtp(int);
ushort __const_func convert_ushort_sat_rtp(int);
ushort __const_func convert_ushort_rtn(int);
ushort __const_func convert_ushort_sat_rtn(int);
ushort __const_func convert_ushort(int);
ushort __const_func convert_ushort_sat(int);
ushort __const_func convert_ushort_rte(uint);
ushort __const_func convert_ushort_sat_rte(uint);
ushort __const_func convert_ushort_rtz(uint);
ushort __const_func convert_ushort_sat_rtz(uint);
ushort __const_func convert_ushort_rtp(uint);
ushort __const_func convert_ushort_sat_rtp(uint);
ushort __const_func convert_ushort_rtn(uint);
ushort __const_func convert_ushort_sat_rtn(uint);
ushort __const_func convert_ushort(uint);
ushort __const_func convert_ushort_sat(uint);
ushort __const_func convert_ushort_rte(long);
ushort __const_func convert_ushort_sat_rte(long);
ushort __const_func convert_ushort_rtz(long);
ushort __const_func convert_ushort_sat_rtz(long);
ushort __const_func convert_ushort_rtp(long);
ushort __const_func convert_ushort_sat_rtp(long);
ushort __const_func convert_ushort_rtn(long);
ushort __const_func convert_ushort_sat_rtn(long);
ushort __const_func convert_ushort(long);
ushort __const_func convert_ushort_sat(long);
ushort __const_func convert_ushort_rte(ulong);
ushort __const_func convert_ushort_sat_rte(ulong);
ushort __const_func convert_ushort_rtz(ulong);
ushort __const_func convert_ushort_sat_rtz(ulong);
ushort __const_func convert_ushort_rtp(ulong);
ushort __const_func convert_ushort_sat_rtp(ulong);
ushort __const_func convert_ushort_rtn(ulong);
ushort __const_func convert_ushort_sat_rtn(ulong);
ushort __const_func convert_ushort(ulong);
ushort __const_func convert_ushort_sat(ulong);
ushort __const_func convert_ushort_rte(float);
ushort __const_func convert_ushort_sat_rte(float);
ushort __const_func convert_ushort_rtz(float);
ushort __const_func convert_ushort_sat_rtz(float);
ushort __const_func convert_ushort_rtp(float);
ushort __const_func convert_ushort_sat_rtp(float);
ushort __const_func convert_ushort_rtn(float);
ushort __const_func convert_ushort_sat_rtn(float);
ushort __const_func convert_ushort(float);
ushort __const_func convert_ushort_sat(float);
int __const_func convert_int_rte(char);
int __const_func convert_int_sat_rte(char);
int __const_func convert_int_rtz(char);
int __const_func convert_int_sat_rtz(char);
int __const_func convert_int_rtp(char);
int __const_func convert_int_sat_rtp(char);
int __const_func convert_int_rtn(char);
int __const_func convert_int_sat_rtn(char);
int __const_func convert_int(char);
int __const_func convert_int_sat(char);
int __const_func convert_int_rte(uchar);
int __const_func convert_int_sat_rte(uchar);
int __const_func convert_int_rtz(uchar);
int __const_func convert_int_sat_rtz(uchar);
int __const_func convert_int_rtp(uchar);
int __const_func convert_int_sat_rtp(uchar);
int __const_func convert_int_rtn(uchar);
int __const_func convert_int_sat_rtn(uchar);
int __const_func convert_int(uchar);
int __const_func convert_int_sat(uchar);
int __const_func convert_int_rte(short);
int __const_func convert_int_sat_rte(short);
int __const_func convert_int_rtz(short);
int __const_func convert_int_sat_rtz(short);
int __const_func convert_int_rtp(short);
int __const_func convert_int_sat_rtp(short);
int __const_func convert_int_rtn(short);
int __const_func convert_int_sat_rtn(short);
int __const_func convert_int(short);
int __const_func convert_int_sat(short);
int __const_func convert_int_rte(ushort);
int __const_func convert_int_sat_rte(ushort);
int __const_func convert_int_rtz(ushort);
int __const_func convert_int_sat_rtz(ushort);
int __const_func convert_int_rtp(ushort);
int __const_func convert_int_sat_rtp(ushort);
int __const_func convert_int_rtn(ushort);
int __const_func convert_int_sat_rtn(ushort);
int __const_func convert_int(ushort);
int __const_func convert_int_sat(ushort);
int __const_func convert_int_rte(int);
int __const_func convert_int_sat_rte(int);
int __const_func convert_int_rtz(int);
int __const_func convert_int_sat_rtz(int);
int __const_func convert_int_rtp(int);
int __const_func convert_int_sat_rtp(int);
int __const_func convert_int_rtn(int);
int __const_func convert_int_sat_rtn(int);
int __const_func convert_int(int);
int __const_func convert_int_sat(int);
int __const_func convert_int_rte(uint);
int __const_func convert_int_sat_rte(uint);
int __const_func convert_int_rtz(uint);
int __const_func convert_int_sat_rtz(uint);
int __const_func convert_int_rtp(uint);
int __const_func convert_int_sat_rtp(uint);
int __const_func convert_int_rtn(uint);
int __const_func convert_int_sat_rtn(uint);
int __const_func convert_int(uint);
int __const_func convert_int_sat(uint);
int __const_func convert_int_rte(long);
int __const_func convert_int_sat_rte(long);
int __const_func convert_int_rtz(long);
int __const_func convert_int_sat_rtz(long);
int __const_func convert_int_rtp(long);
int __const_func convert_int_sat_rtp(long);
int __const_func convert_int_rtn(long);
int __const_func convert_int_sat_rtn(long);
int __const_func convert_int(long);
int __const_func convert_int_sat(long);
int __const_func convert_int_rte(ulong);
int __const_func convert_int_sat_rte(ulong);
int __const_func convert_int_rtz(ulong);
int __const_func convert_int_sat_rtz(ulong);
int __const_func convert_int_rtp(ulong);
int __const_func convert_int_sat_rtp(ulong);
int __const_func convert_int_rtn(ulong);
int __const_func convert_int_sat_rtn(ulong);
int __const_func convert_int(ulong);
int __const_func convert_int_sat(ulong);
int __const_func convert_int_rte(float);
int __const_func convert_int_sat_rte(float);
int __const_func convert_int_rtz(float);
int __const_func convert_int_sat_rtz(float);
int __const_func convert_int_rtp(float);
int __const_func convert_int_sat_rtp(float);
int __const_func convert_int_rtn(float);
int __const_func convert_int_sat_rtn(float);
int __const_func convert_int(float);
int __const_func convert_int_sat(float);
uint __const_func convert_uint_rte(char);
uint __const_func convert_uint_sat_rte(char);
uint __const_func convert_uint_rtz(char);
uint __const_func convert_uint_sat_rtz(char);
uint __const_func convert_uint_rtp(char);
uint __const_func convert_uint_sat_rtp(char);
uint __const_func convert_uint_rtn(char);
uint __const_func convert_uint_sat_rtn(char);
uint __const_func convert_uint(char);
uint __const_func convert_uint_sat(char);
uint __const_func convert_uint_rte(uchar);
uint __const_func convert_uint_sat_rte(uchar);
uint __const_func convert_uint_rtz(uchar);
uint __const_func convert_uint_sat_rtz(uchar);
uint __const_func convert_uint_rtp(uchar);
uint __const_func convert_uint_sat_rtp(uchar);
uint __const_func convert_uint_rtn(uchar);
uint __const_func convert_uint_sat_rtn(uchar);
uint __const_func convert_uint(uchar);
uint __const_func convert_uint_sat(uchar);
uint __const_func convert_uint_rte(short);
uint __const_func convert_uint_sat_rte(short);
uint __const_func convert_uint_rtz(short);
uint __const_func convert_uint_sat_rtz(short);
uint __const_func convert_uint_rtp(short);
uint __const_func convert_uint_sat_rtp(short);
uint __const_func convert_uint_rtn(short);
uint __const_func convert_uint_sat_rtn(short);
uint __const_func convert_uint(short);
uint __const_func convert_uint_sat(short);
uint __const_func convert_uint_rte(ushort);
uint __const_func convert_uint_sat_rte(ushort);
uint __const_func convert_uint_rtz(ushort);
uint __const_func convert_uint_sat_rtz(ushort);
uint __const_func convert_uint_rtp(ushort);
uint __const_func convert_uint_sat_rtp(ushort);
uint __const_func convert_uint_rtn(ushort);
uint __const_func convert_uint_sat_rtn(ushort);
uint __const_func convert_uint(ushort);
uint __const_func convert_uint_sat(ushort);
uint __const_func convert_uint_rte(int);
uint __const_func convert_uint_sat_rte(int);
uint __const_func convert_uint_rtz(int);
uint __const_func convert_uint_sat_rtz(int);
uint __const_func convert_uint_rtp(int);
uint __const_func convert_uint_sat_rtp(int);
uint __const_func convert_uint_rtn(int);
uint __const_func convert_uint_sat_rtn(int);
uint __const_func convert_uint(int);
uint __const_func convert_uint_sat(int);
uint __const_func convert_uint_rte(uint);
uint __const_func convert_uint_sat_rte(uint);
uint __const_func convert_uint_rtz(uint);
uint __const_func convert_uint_sat_rtz(uint);
uint __const_func convert_uint_rtp(uint);
uint __const_func convert_uint_sat_rtp(uint);
uint __const_func convert_uint_rtn(uint);
uint __const_func convert_uint_sat_rtn(uint);
uint __const_func convert_uint(uint);
uint __const_func convert_uint_sat(uint);
uint __const_func convert_uint_rte(long);
uint __const_func convert_uint_sat_rte(long);
uint __const_func convert_uint_rtz(long);
uint __const_func convert_uint_sat_rtz(long);
uint __const_func convert_uint_rtp(long);
uint __const_func convert_uint_sat_rtp(long);
uint __const_func convert_uint_rtn(long);
uint __const_func convert_uint_sat_rtn(long);
uint __const_func convert_uint(long);
uint __const_func convert_uint_sat(long);
uint __const_func convert_uint_rte(ulong);
uint __const_func convert_uint_sat_rte(ulong);
uint __const_func convert_uint_rtz(ulong);
uint __const_func convert_uint_sat_rtz(ulong);
uint __const_func convert_uint_rtp(ulong);
uint __const_func convert_uint_sat_rtp(ulong);
uint __const_func convert_uint_rtn(ulong);
uint __const_func convert_uint_sat_rtn(ulong);
uint __const_func convert_uint(ulong);
uint __const_func convert_uint_sat(ulong);
uint __const_func convert_uint_rte(float);
uint __const_func convert_uint_sat_rte(float);
uint __const_func convert_uint_rtz(float);
uint __const_func convert_uint_sat_rtz(float);
uint __const_func convert_uint_rtp(float);
uint __const_func convert_uint_sat_rtp(float);
uint __const_func convert_uint_rtn(float);
uint __const_func convert_uint_sat_rtn(float);
uint __const_func convert_uint(float);
uint __const_func convert_uint_sat(float);
long __const_func convert_long_rte(char);
long __const_func convert_long_sat_rte(char);
long __const_func convert_long_rtz(char);
long __const_func convert_long_sat_rtz(char);
long __const_func convert_long_rtp(char);
long __const_func convert_long_sat_rtp(char);
long __const_func convert_long_rtn(char);
long __const_func convert_long_sat_rtn(char);
long __const_func convert_long(char);
long __const_func convert_long_sat(char);
long __const_func convert_long_rte(uchar);
long __const_func convert_long_sat_rte(uchar);
long __const_func convert_long_rtz(uchar);
long __const_func convert_long_sat_rtz(uchar);
long __const_func convert_long_rtp(uchar);
long __const_func convert_long_sat_rtp(uchar);
long __const_func convert_long_rtn(uchar);
long __const_func convert_long_sat_rtn(uchar);
long __const_func convert_long(uchar);
long __const_func convert_long_sat(uchar);
long __const_func convert_long_rte(short);
long __const_func convert_long_sat_rte(short);
long __const_func convert_long_rtz(short);
long __const_func convert_long_sat_rtz(short);
long __const_func convert_long_rtp(short);
long __const_func convert_long_sat_rtp(short);
long __const_func convert_long_rtn(short);
long __const_func convert_long_sat_rtn(short);
long __const_func convert_long(short);
long __const_func convert_long_sat(short);
long __const_func convert_long_rte(ushort);
long __const_func convert_long_sat_rte(ushort);
long __const_func convert_long_rtz(ushort);
long __const_func convert_long_sat_rtz(ushort);
long __const_func convert_long_rtp(ushort);
long __const_func convert_long_sat_rtp(ushort);
long __const_func convert_long_rtn(ushort);
long __const_func convert_long_sat_rtn(ushort);
long __const_func convert_long(ushort);
long __const_func convert_long_sat(ushort);
long __const_func convert_long_rte(int);
long __const_func convert_long_sat_rte(int);
long __const_func convert_long_rtz(int);
long __const_func convert_long_sat_rtz(int);
long __const_func convert_long_rtp(int);
long __const_func convert_long_sat_rtp(int);
long __const_func convert_long_rtn(int);
long __const_func convert_long_sat_rtn(int);
long __const_func convert_long(int);
long __const_func convert_long_sat(int);
long __const_func convert_long_rte(uint);
long __const_func convert_long_sat_rte(uint);
long __const_func convert_long_rtz(uint);
long __const_func convert_long_sat_rtz(uint);
long __const_func convert_long_rtp(uint);
long __const_func convert_long_sat_rtp(uint);
long __const_func convert_long_rtn(uint);
long __const_func convert_long_sat_rtn(uint);
long __const_func convert_long(uint);
long __const_func convert_long_sat(uint);
long __const_func convert_long_rte(long);
long __const_func convert_long_sat_rte(long);
long __const_func convert_long_rtz(long);
long __const_func convert_long_sat_rtz(long);
long __const_func convert_long_rtp(long);
long __const_func convert_long_sat_rtp(long);
long __const_func convert_long_rtn(long);
long __const_func convert_long_sat_rtn(long);
long __const_func convert_long(long);
long __const_func convert_long_sat(long);
long __const_func convert_long_rte(ulong);
long __const_func convert_long_sat_rte(ulong);
long __const_func convert_long_rtz(ulong);
long __const_func convert_long_sat_rtz(ulong);
long __const_func convert_long_rtp(ulong);
long __const_func convert_long_sat_rtp(ulong);
long __const_func convert_long_rtn(ulong);
long __const_func convert_long_sat_rtn(ulong);
long __const_func convert_long(ulong);
long __const_func convert_long_sat(ulong);
long __const_func convert_long_rte(float);
long __const_func convert_long_sat_rte(float);
long __const_func convert_long_rtz(float);
long __const_func convert_long_sat_rtz(float);
long __const_func convert_long_rtp(float);
long __const_func convert_long_sat_rtp(float);
long __const_func convert_long_rtn(float);
long __const_func convert_long_sat_rtn(float);
long __const_func convert_long(float);
long __const_func convert_long_sat(float);
ulong __const_func convert_ulong_rte(char);
ulong __const_func convert_ulong_sat_rte(char);
ulong __const_func convert_ulong_rtz(char);
ulong __const_func convert_ulong_sat_rtz(char);
ulong __const_func convert_ulong_rtp(char);
ulong __const_func convert_ulong_sat_rtp(char);
ulong __const_func convert_ulong_rtn(char);
ulong __const_func convert_ulong_sat_rtn(char);
ulong __const_func convert_ulong(char);
ulong __const_func convert_ulong_sat(char);
ulong __const_func convert_ulong_rte(uchar);
ulong __const_func convert_ulong_sat_rte(uchar);
ulong __const_func convert_ulong_rtz(uchar);
ulong __const_func convert_ulong_sat_rtz(uchar);
ulong __const_func convert_ulong_rtp(uchar);
ulong __const_func convert_ulong_sat_rtp(uchar);
ulong __const_func convert_ulong_rtn(uchar);
ulong __const_func convert_ulong_sat_rtn(uchar);
ulong __const_func convert_ulong(uchar);
ulong __const_func convert_ulong_sat(uchar);
ulong __const_func convert_ulong_rte(short);
ulong __const_func convert_ulong_sat_rte(short);
ulong __const_func convert_ulong_rtz(short);
ulong __const_func convert_ulong_sat_rtz(short);
ulong __const_func convert_ulong_rtp(short);
ulong __const_func convert_ulong_sat_rtp(short);
ulong __const_func convert_ulong_rtn(short);
ulong __const_func convert_ulong_sat_rtn(short);
ulong __const_func convert_ulong(short);
ulong __const_func convert_ulong_sat(short);
ulong __const_func convert_ulong_rte(ushort);
ulong __const_func convert_ulong_sat_rte(ushort);
ulong __const_func convert_ulong_rtz(ushort);
ulong __const_func convert_ulong_sat_rtz(ushort);
ulong __const_func convert_ulong_rtp(ushort);
ulong __const_func convert_ulong_sat_rtp(ushort);
ulong __const_func convert_ulong_rtn(ushort);
ulong __const_func convert_ulong_sat_rtn(ushort);
ulong __const_func convert_ulong(ushort);
ulong __const_func convert_ulong_sat(ushort);
ulong __const_func convert_ulong_rte(int);
ulong __const_func convert_ulong_sat_rte(int);
ulong __const_func convert_ulong_rtz(int);
ulong __const_func convert_ulong_sat_rtz(int);
ulong __const_func convert_ulong_rtp(int);
ulong __const_func convert_ulong_sat_rtp(int);
ulong __const_func convert_ulong_rtn(int);
ulong __const_func convert_ulong_sat_rtn(int);
ulong __const_func convert_ulong(int);
ulong __const_func convert_ulong_sat(int);
ulong __const_func convert_ulong_rte(uint);
ulong __const_func convert_ulong_sat_rte(uint);
ulong __const_func convert_ulong_rtz(uint);
ulong __const_func convert_ulong_sat_rtz(uint);
ulong __const_func convert_ulong_rtp(uint);
ulong __const_func convert_ulong_sat_rtp(uint);
ulong __const_func convert_ulong_rtn(uint);
ulong __const_func convert_ulong_sat_rtn(uint);
ulong __const_func convert_ulong(uint);
ulong __const_func convert_ulong_sat(uint);
ulong __const_func convert_ulong_rte(long);
ulong __const_func convert_ulong_sat_rte(long);
ulong __const_func convert_ulong_rtz(long);
ulong __const_func convert_ulong_sat_rtz(long);
ulong __const_func convert_ulong_rtp(long);
ulong __const_func convert_ulong_sat_rtp(long);
ulong __const_func convert_ulong_rtn(long);
ulong __const_func convert_ulong_sat_rtn(long);
ulong __const_func convert_ulong(long);
ulong __const_func convert_ulong_sat(long);
ulong __const_func convert_ulong_rte(ulong);
ulong __const_func convert_ulong_sat_rte(ulong);
ulong __const_func convert_ulong_rtz(ulong);
ulong __const_func convert_ulong_sat_rtz(ulong);
ulong __const_func convert_ulong_rtp(ulong);
ulong __const_func convert_ulong_sat_rtp(ulong);
ulong __const_func convert_ulong_rtn(ulong);
ulong __const_func convert_ulong_sat_rtn(ulong);
ulong __const_func convert_ulong(ulong);
ulong __const_func convert_ulong_sat(ulong);
ulong __const_func convert_ulong_rte(float);
ulong __const_func convert_ulong_sat_rte(float);
ulong __const_func convert_ulong_rtz(float);
ulong __const_func convert_ulong_sat_rtz(float);
ulong __const_func convert_ulong_rtp(float);
ulong __const_func convert_ulong_sat_rtp(float);
ulong __const_func convert_ulong_rtn(float);
ulong __const_func convert_ulong_sat_rtn(float);
ulong __const_func convert_ulong(float);
ulong __const_func convert_ulong_sat(float);
float __const_func convert_float_rte(char);
float __const_func convert_float_rtz(char);
float __const_func convert_float_rtp(char);
float __const_func convert_float_rtn(char);
float __const_func convert_float(char);
float __const_func convert_float_rte(uchar);
float __const_func convert_float_rtz(uchar);
float __const_func convert_float_rtp(uchar);
float __const_func convert_float_rtn(uchar);
float __const_func convert_float(uchar);
float __const_func convert_float_rte(short);
float __const_func convert_float_rtz(short);
float __const_func convert_float_rtp(short);
float __const_func convert_float_rtn(short);
float __const_func convert_float(short);
float __const_func convert_float_rte(ushort);
float __const_func convert_float_rtz(ushort);
float __const_func convert_float_rtp(ushort);
float __const_func convert_float_rtn(ushort);
float __const_func convert_float(ushort);
float __const_func convert_float_rte(int);
float __const_func convert_float_rtz(int);
float __const_func convert_float_rtp(int);
float __const_func convert_float_rtn(int);
float __const_func convert_float(int);
float __const_func convert_float_rte(uint);
float __const_func convert_float_rtz(uint);
float __const_func convert_float_rtp(uint);
float __const_func convert_float_rtn(uint);
float __const_func convert_float(uint);
float __const_func convert_float_rte(long);
float __const_func convert_float_rtz(long);
float __const_func convert_float_rtp(long);
float __const_func convert_float_rtn(long);
float __const_func convert_float(long);
float __const_func convert_float_rte(ulong);
float __const_func convert_float_rtz(ulong);
float __const_func convert_float_rtp(ulong);
float __const_func convert_float_rtn(ulong);
float __const_func convert_float(ulong);
float __const_func convert_float_rte(float);
float __const_func convert_float_rtz(float);
float __const_func convert_float_rtp(float);
float __const_func convert_float_rtn(float);
float __const_func convert_float(float);
char2 __const_func convert_char2_rte(char2);
char2 __const_func convert_char2_sat_rte(char2);
char2 __const_func convert_char2_rtz(char2);
char2 __const_func convert_char2_sat_rtz(char2);
char2 __const_func convert_char2_rtp(char2);
char2 __const_func convert_char2_sat_rtp(char2);
char2 __const_func convert_char2_rtn(char2);
char2 __const_func convert_char2_sat_rtn(char2);
char2 __const_func convert_char2(char2);
char2 __const_func convert_char2_sat(char2);
char2 __const_func convert_char2_rte(uchar2);
char2 __const_func convert_char2_sat_rte(uchar2);
char2 __const_func convert_char2_rtz(uchar2);
char2 __const_func convert_char2_sat_rtz(uchar2);
char2 __const_func convert_char2_rtp(uchar2);
char2 __const_func convert_char2_sat_rtp(uchar2);
char2 __const_func convert_char2_rtn(uchar2);
char2 __const_func convert_char2_sat_rtn(uchar2);
char2 __const_func convert_char2(uchar2);
char2 __const_func convert_char2_sat(uchar2);
char2 __const_func convert_char2_rte(short2);
char2 __const_func convert_char2_sat_rte(short2);
char2 __const_func convert_char2_rtz(short2);
char2 __const_func convert_char2_sat_rtz(short2);
char2 __const_func convert_char2_rtp(short2);
char2 __const_func convert_char2_sat_rtp(short2);
char2 __const_func convert_char2_rtn(short2);
char2 __const_func convert_char2_sat_rtn(short2);
char2 __const_func convert_char2(short2);
char2 __const_func convert_char2_sat(short2);
char2 __const_func convert_char2_rte(ushort2);
char2 __const_func convert_char2_sat_rte(ushort2);
char2 __const_func convert_char2_rtz(ushort2);
char2 __const_func convert_char2_sat_rtz(ushort2);
char2 __const_func convert_char2_rtp(ushort2);
char2 __const_func convert_char2_sat_rtp(ushort2);
char2 __const_func convert_char2_rtn(ushort2);
char2 __const_func convert_char2_sat_rtn(ushort2);
char2 __const_func convert_char2(ushort2);
char2 __const_func convert_char2_sat(ushort2);
char2 __const_func convert_char2_rte(int2);
char2 __const_func convert_char2_sat_rte(int2);
char2 __const_func convert_char2_rtz(int2);
char2 __const_func convert_char2_sat_rtz(int2);
char2 __const_func convert_char2_rtp(int2);
char2 __const_func convert_char2_sat_rtp(int2);
char2 __const_func convert_char2_rtn(int2);
char2 __const_func convert_char2_sat_rtn(int2);
char2 __const_func convert_char2(int2);
char2 __const_func convert_char2_sat(int2);
char2 __const_func convert_char2_rte(uint2);
char2 __const_func convert_char2_sat_rte(uint2);
char2 __const_func convert_char2_rtz(uint2);
char2 __const_func convert_char2_sat_rtz(uint2);
char2 __const_func convert_char2_rtp(uint2);
char2 __const_func convert_char2_sat_rtp(uint2);
char2 __const_func convert_char2_rtn(uint2);
char2 __const_func convert_char2_sat_rtn(uint2);
char2 __const_func convert_char2(uint2);
char2 __const_func convert_char2_sat(uint2);
char2 __const_func convert_char2_rte(long2);
char2 __const_func convert_char2_sat_rte(long2);
char2 __const_func convert_char2_rtz(long2);
char2 __const_func convert_char2_sat_rtz(long2);
char2 __const_func convert_char2_rtp(long2);
char2 __const_func convert_char2_sat_rtp(long2);
char2 __const_func convert_char2_rtn(long2);
char2 __const_func convert_char2_sat_rtn(long2);
char2 __const_func convert_char2(long2);
char2 __const_func convert_char2_sat(long2);
char2 __const_func convert_char2_rte(ulong2);
char2 __const_func convert_char2_sat_rte(ulong2);
char2 __const_func convert_char2_rtz(ulong2);
char2 __const_func convert_char2_sat_rtz(ulong2);
char2 __const_func convert_char2_rtp(ulong2);
char2 __const_func convert_char2_sat_rtp(ulong2);
char2 __const_func convert_char2_rtn(ulong2);
char2 __const_func convert_char2_sat_rtn(ulong2);
char2 __const_func convert_char2(ulong2);
char2 __const_func convert_char2_sat(ulong2);
char2 __const_func convert_char2_rte(float2);
char2 __const_func convert_char2_sat_rte(float2);
char2 __const_func convert_char2_rtz(float2);
char2 __const_func convert_char2_sat_rtz(float2);
char2 __const_func convert_char2_rtp(float2);
char2 __const_func convert_char2_sat_rtp(float2);
char2 __const_func convert_char2_rtn(float2);
char2 __const_func convert_char2_sat_rtn(float2);
char2 __const_func convert_char2(float2);
char2 __const_func convert_char2_sat(float2);
uchar2 __const_func convert_uchar2_rte(char2);
uchar2 __const_func convert_uchar2_sat_rte(char2);
uchar2 __const_func convert_uchar2_rtz(char2);
uchar2 __const_func convert_uchar2_sat_rtz(char2);
uchar2 __const_func convert_uchar2_rtp(char2);
uchar2 __const_func convert_uchar2_sat_rtp(char2);
uchar2 __const_func convert_uchar2_rtn(char2);
uchar2 __const_func convert_uchar2_sat_rtn(char2);
uchar2 __const_func convert_uchar2(char2);
uchar2 __const_func convert_uchar2_sat(char2);
uchar2 __const_func convert_uchar2_rte(uchar2);
uchar2 __const_func convert_uchar2_sat_rte(uchar2);
uchar2 __const_func convert_uchar2_rtz(uchar2);
uchar2 __const_func convert_uchar2_sat_rtz(uchar2);
uchar2 __const_func convert_uchar2_rtp(uchar2);
uchar2 __const_func convert_uchar2_sat_rtp(uchar2);
uchar2 __const_func convert_uchar2_rtn(uchar2);
uchar2 __const_func convert_uchar2_sat_rtn(uchar2);
uchar2 __const_func convert_uchar2(uchar2);
uchar2 __const_func convert_uchar2_sat(uchar2);
uchar2 __const_func convert_uchar2_rte(short2);
uchar2 __const_func convert_uchar2_sat_rte(short2);
uchar2 __const_func convert_uchar2_rtz(short2);
uchar2 __const_func convert_uchar2_sat_rtz(short2);
uchar2 __const_func convert_uchar2_rtp(short2);
uchar2 __const_func convert_uchar2_sat_rtp(short2);
uchar2 __const_func convert_uchar2_rtn(short2);
uchar2 __const_func convert_uchar2_sat_rtn(short2);
uchar2 __const_func convert_uchar2(short2);
uchar2 __const_func convert_uchar2_sat(short2);
uchar2 __const_func convert_uchar2_rte(ushort2);
uchar2 __const_func convert_uchar2_sat_rte(ushort2);
uchar2 __const_func convert_uchar2_rtz(ushort2);
uchar2 __const_func convert_uchar2_sat_rtz(ushort2);
uchar2 __const_func convert_uchar2_rtp(ushort2);
uchar2 __const_func convert_uchar2_sat_rtp(ushort2);
uchar2 __const_func convert_uchar2_rtn(ushort2);
uchar2 __const_func convert_uchar2_sat_rtn(ushort2);
uchar2 __const_func convert_uchar2(ushort2);
uchar2 __const_func convert_uchar2_sat(ushort2);
uchar2 __const_func convert_uchar2_rte(int2);
uchar2 __const_func convert_uchar2_sat_rte(int2);
uchar2 __const_func convert_uchar2_rtz(int2);
uchar2 __const_func convert_uchar2_sat_rtz(int2);
uchar2 __const_func convert_uchar2_rtp(int2);
uchar2 __const_func convert_uchar2_sat_rtp(int2);
uchar2 __const_func convert_uchar2_rtn(int2);
uchar2 __const_func convert_uchar2_sat_rtn(int2);
uchar2 __const_func convert_uchar2(int2);
uchar2 __const_func convert_uchar2_sat(int2);
uchar2 __const_func convert_uchar2_rte(uint2);
uchar2 __const_func convert_uchar2_sat_rte(uint2);
uchar2 __const_func convert_uchar2_rtz(uint2);
uchar2 __const_func convert_uchar2_sat_rtz(uint2);
uchar2 __const_func convert_uchar2_rtp(uint2);
uchar2 __const_func convert_uchar2_sat_rtp(uint2);
uchar2 __const_func convert_uchar2_rtn(uint2);
uchar2 __const_func convert_uchar2_sat_rtn(uint2);
uchar2 __const_func convert_uchar2(uint2);
uchar2 __const_func convert_uchar2_sat(uint2);
uchar2 __const_func convert_uchar2_rte(long2);
uchar2 __const_func convert_uchar2_sat_rte(long2);
uchar2 __const_func convert_uchar2_rtz(long2);
uchar2 __const_func convert_uchar2_sat_rtz(long2);
uchar2 __const_func convert_uchar2_rtp(long2);
uchar2 __const_func convert_uchar2_sat_rtp(long2);
uchar2 __const_func convert_uchar2_rtn(long2);
uchar2 __const_func convert_uchar2_sat_rtn(long2);
uchar2 __const_func convert_uchar2(long2);
uchar2 __const_func convert_uchar2_sat(long2);
uchar2 __const_func convert_uchar2_rte(ulong2);
uchar2 __const_func convert_uchar2_sat_rte(ulong2);
uchar2 __const_func convert_uchar2_rtz(ulong2);
uchar2 __const_func convert_uchar2_sat_rtz(ulong2);
uchar2 __const_func convert_uchar2_rtp(ulong2);
uchar2 __const_func convert_uchar2_sat_rtp(ulong2);
uchar2 __const_func convert_uchar2_rtn(ulong2);
uchar2 __const_func convert_uchar2_sat_rtn(ulong2);
uchar2 __const_func convert_uchar2(ulong2);
uchar2 __const_func convert_uchar2_sat(ulong2);
uchar2 __const_func convert_uchar2_rte(float2);
uchar2 __const_func convert_uchar2_sat_rte(float2);
uchar2 __const_func convert_uchar2_rtz(float2);
uchar2 __const_func convert_uchar2_sat_rtz(float2);
uchar2 __const_func convert_uchar2_rtp(float2);
uchar2 __const_func convert_uchar2_sat_rtp(float2);
uchar2 __const_func convert_uchar2_rtn(float2);
uchar2 __const_func convert_uchar2_sat_rtn(float2);
uchar2 __const_func convert_uchar2(float2);
uchar2 __const_func convert_uchar2_sat(float2);
short2 __const_func convert_short2_rte(char2);
short2 __const_func convert_short2_sat_rte(char2);
short2 __const_func convert_short2_rtz(char2);
short2 __const_func convert_short2_sat_rtz(char2);
short2 __const_func convert_short2_rtp(char2);
short2 __const_func convert_short2_sat_rtp(char2);
short2 __const_func convert_short2_rtn(char2);
short2 __const_func convert_short2_sat_rtn(char2);
short2 __const_func convert_short2(char2);
short2 __const_func convert_short2_sat(char2);
short2 __const_func convert_short2_rte(uchar2);
short2 __const_func convert_short2_sat_rte(uchar2);
short2 __const_func convert_short2_rtz(uchar2);
short2 __const_func convert_short2_sat_rtz(uchar2);
short2 __const_func convert_short2_rtp(uchar2);
short2 __const_func convert_short2_sat_rtp(uchar2);
short2 __const_func convert_short2_rtn(uchar2);
short2 __const_func convert_short2_sat_rtn(uchar2);
short2 __const_func convert_short2(uchar2);
short2 __const_func convert_short2_sat(uchar2);
short2 __const_func convert_short2_rte(short2);
short2 __const_func convert_short2_sat_rte(short2);
short2 __const_func convert_short2_rtz(short2);
short2 __const_func convert_short2_sat_rtz(short2);
short2 __const_func convert_short2_rtp(short2);
short2 __const_func convert_short2_sat_rtp(short2);
short2 __const_func convert_short2_rtn(short2);
short2 __const_func convert_short2_sat_rtn(short2);
short2 __const_func convert_short2(short2);
short2 __const_func convert_short2_sat(short2);
short2 __const_func convert_short2_rte(ushort2);
short2 __const_func convert_short2_sat_rte(ushort2);
short2 __const_func convert_short2_rtz(ushort2);
short2 __const_func convert_short2_sat_rtz(ushort2);
short2 __const_func convert_short2_rtp(ushort2);
short2 __const_func convert_short2_sat_rtp(ushort2);
short2 __const_func convert_short2_rtn(ushort2);
short2 __const_func convert_short2_sat_rtn(ushort2);
short2 __const_func convert_short2(ushort2);
short2 __const_func convert_short2_sat(ushort2);
short2 __const_func convert_short2_rte(int2);
short2 __const_func convert_short2_sat_rte(int2);
short2 __const_func convert_short2_rtz(int2);
short2 __const_func convert_short2_sat_rtz(int2);
short2 __const_func convert_short2_rtp(int2);
short2 __const_func convert_short2_sat_rtp(int2);
short2 __const_func convert_short2_rtn(int2);
short2 __const_func convert_short2_sat_rtn(int2);
short2 __const_func convert_short2(int2);
short2 __const_func convert_short2_sat(int2);
short2 __const_func convert_short2_rte(uint2);
short2 __const_func convert_short2_sat_rte(uint2);
short2 __const_func convert_short2_rtz(uint2);
short2 __const_func convert_short2_sat_rtz(uint2);
short2 __const_func convert_short2_rtp(uint2);
short2 __const_func convert_short2_sat_rtp(uint2);
short2 __const_func convert_short2_rtn(uint2);
short2 __const_func convert_short2_sat_rtn(uint2);
short2 __const_func convert_short2(uint2);
short2 __const_func convert_short2_sat(uint2);
short2 __const_func convert_short2_rte(long2);
short2 __const_func convert_short2_sat_rte(long2);
short2 __const_func convert_short2_rtz(long2);
short2 __const_func convert_short2_sat_rtz(long2);
short2 __const_func convert_short2_rtp(long2);
short2 __const_func convert_short2_sat_rtp(long2);
short2 __const_func convert_short2_rtn(long2);
short2 __const_func convert_short2_sat_rtn(long2);
short2 __const_func convert_short2(long2);
short2 __const_func convert_short2_sat(long2);
short2 __const_func convert_short2_rte(ulong2);
short2 __const_func convert_short2_sat_rte(ulong2);
short2 __const_func convert_short2_rtz(ulong2);
short2 __const_func convert_short2_sat_rtz(ulong2);
short2 __const_func convert_short2_rtp(ulong2);
short2 __const_func convert_short2_sat_rtp(ulong2);
short2 __const_func convert_short2_rtn(ulong2);
short2 __const_func convert_short2_sat_rtn(ulong2);
short2 __const_func convert_short2(ulong2);
short2 __const_func convert_short2_sat(ulong2);
short2 __const_func convert_short2_rte(float2);
short2 __const_func convert_short2_sat_rte(float2);
short2 __const_func convert_short2_rtz(float2);
short2 __const_func convert_short2_sat_rtz(float2);
short2 __const_func convert_short2_rtp(float2);
short2 __const_func convert_short2_sat_rtp(float2);
short2 __const_func convert_short2_rtn(float2);
short2 __const_func convert_short2_sat_rtn(float2);
short2 __const_func convert_short2(float2);
short2 __const_func convert_short2_sat(float2);
ushort2 __const_func convert_ushort2_rte(char2);
ushort2 __const_func convert_ushort2_sat_rte(char2);
ushort2 __const_func convert_ushort2_rtz(char2);
ushort2 __const_func convert_ushort2_sat_rtz(char2);
ushort2 __const_func convert_ushort2_rtp(char2);
ushort2 __const_func convert_ushort2_sat_rtp(char2);
ushort2 __const_func convert_ushort2_rtn(char2);
ushort2 __const_func convert_ushort2_sat_rtn(char2);
ushort2 __const_func convert_ushort2(char2);
ushort2 __const_func convert_ushort2_sat(char2);
ushort2 __const_func convert_ushort2_rte(uchar2);
ushort2 __const_func convert_ushort2_sat_rte(uchar2);
ushort2 __const_func convert_ushort2_rtz(uchar2);
ushort2 __const_func convert_ushort2_sat_rtz(uchar2);
ushort2 __const_func convert_ushort2_rtp(uchar2);
ushort2 __const_func convert_ushort2_sat_rtp(uchar2);
ushort2 __const_func convert_ushort2_rtn(uchar2);
ushort2 __const_func convert_ushort2_sat_rtn(uchar2);
ushort2 __const_func convert_ushort2(uchar2);
ushort2 __const_func convert_ushort2_sat(uchar2);
ushort2 __const_func convert_ushort2_rte(short2);
ushort2 __const_func convert_ushort2_sat_rte(short2);
ushort2 __const_func convert_ushort2_rtz(short2);
ushort2 __const_func convert_ushort2_sat_rtz(short2);
ushort2 __const_func convert_ushort2_rtp(short2);
ushort2 __const_func convert_ushort2_sat_rtp(short2);
ushort2 __const_func convert_ushort2_rtn(short2);
ushort2 __const_func convert_ushort2_sat_rtn(short2);
ushort2 __const_func convert_ushort2(short2);
ushort2 __const_func convert_ushort2_sat(short2);
ushort2 __const_func convert_ushort2_rte(ushort2);
ushort2 __const_func convert_ushort2_sat_rte(ushort2);
ushort2 __const_func convert_ushort2_rtz(ushort2);
ushort2 __const_func convert_ushort2_sat_rtz(ushort2);
ushort2 __const_func convert_ushort2_rtp(ushort2);
ushort2 __const_func convert_ushort2_sat_rtp(ushort2);
ushort2 __const_func convert_ushort2_rtn(ushort2);
ushort2 __const_func convert_ushort2_sat_rtn(ushort2);
ushort2 __const_func convert_ushort2(ushort2);
ushort2 __const_func convert_ushort2_sat(ushort2);
ushort2 __const_func convert_ushort2_rte(int2);
ushort2 __const_func convert_ushort2_sat_rte(int2);
ushort2 __const_func convert_ushort2_rtz(int2);
ushort2 __const_func convert_ushort2_sat_rtz(int2);
ushort2 __const_func convert_ushort2_rtp(int2);
ushort2 __const_func convert_ushort2_sat_rtp(int2);
ushort2 __const_func convert_ushort2_rtn(int2);
ushort2 __const_func convert_ushort2_sat_rtn(int2);
ushort2 __const_func convert_ushort2(int2);
ushort2 __const_func convert_ushort2_sat(int2);
ushort2 __const_func convert_ushort2_rte(uint2);
ushort2 __const_func convert_ushort2_sat_rte(uint2);
ushort2 __const_func convert_ushort2_rtz(uint2);
ushort2 __const_func convert_ushort2_sat_rtz(uint2);
ushort2 __const_func convert_ushort2_rtp(uint2);
ushort2 __const_func convert_ushort2_sat_rtp(uint2);
ushort2 __const_func convert_ushort2_rtn(uint2);
ushort2 __const_func convert_ushort2_sat_rtn(uint2);
ushort2 __const_func convert_ushort2(uint2);
ushort2 __const_func convert_ushort2_sat(uint2);
ushort2 __const_func convert_ushort2_rte(long2);
ushort2 __const_func convert_ushort2_sat_rte(long2);
ushort2 __const_func convert_ushort2_rtz(long2);
ushort2 __const_func convert_ushort2_sat_rtz(long2);
ushort2 __const_func convert_ushort2_rtp(long2);
ushort2 __const_func convert_ushort2_sat_rtp(long2);
ushort2 __const_func convert_ushort2_rtn(long2);
ushort2 __const_func convert_ushort2_sat_rtn(long2);
ushort2 __const_func convert_ushort2(long2);
ushort2 __const_func convert_ushort2_sat(long2);
ushort2 __const_func convert_ushort2_rte(ulong2);
ushort2 __const_func convert_ushort2_sat_rte(ulong2);
ushort2 __const_func convert_ushort2_rtz(ulong2);
ushort2 __const_func convert_ushort2_sat_rtz(ulong2);
ushort2 __const_func convert_ushort2_rtp(ulong2);
ushort2 __const_func convert_ushort2_sat_rtp(ulong2);
ushort2 __const_func convert_ushort2_rtn(ulong2);
ushort2 __const_func convert_ushort2_sat_rtn(ulong2);
ushort2 __const_func convert_ushort2(ulong2);
ushort2 __const_func convert_ushort2_sat(ulong2);
ushort2 __const_func convert_ushort2_rte(float2);
ushort2 __const_func convert_ushort2_sat_rte(float2);
ushort2 __const_func convert_ushort2_rtz(float2);
ushort2 __const_func convert_ushort2_sat_rtz(float2);
ushort2 __const_func convert_ushort2_rtp(float2);
ushort2 __const_func convert_ushort2_sat_rtp(float2);
ushort2 __const_func convert_ushort2_rtn(float2);
ushort2 __const_func convert_ushort2_sat_rtn(float2);
ushort2 __const_func convert_ushort2(float2);
ushort2 __const_func convert_ushort2_sat(float2);
int2 __const_func convert_int2_rte(char2);
int2 __const_func convert_int2_sat_rte(char2);
int2 __const_func convert_int2_rtz(char2);
int2 __const_func convert_int2_sat_rtz(char2);
int2 __const_func convert_int2_rtp(char2);
int2 __const_func convert_int2_sat_rtp(char2);
int2 __const_func convert_int2_rtn(char2);
int2 __const_func convert_int2_sat_rtn(char2);
int2 __const_func convert_int2(char2);
int2 __const_func convert_int2_sat(char2);
int2 __const_func convert_int2_rte(uchar2);
int2 __const_func convert_int2_sat_rte(uchar2);
int2 __const_func convert_int2_rtz(uchar2);
int2 __const_func convert_int2_sat_rtz(uchar2);
int2 __const_func convert_int2_rtp(uchar2);
int2 __const_func convert_int2_sat_rtp(uchar2);
int2 __const_func convert_int2_rtn(uchar2);
int2 __const_func convert_int2_sat_rtn(uchar2);
int2 __const_func convert_int2(uchar2);
int2 __const_func convert_int2_sat(uchar2);
int2 __const_func convert_int2_rte(short2);
int2 __const_func convert_int2_sat_rte(short2);
int2 __const_func convert_int2_rtz(short2);
int2 __const_func convert_int2_sat_rtz(short2);
int2 __const_func convert_int2_rtp(short2);
int2 __const_func convert_int2_sat_rtp(short2);
int2 __const_func convert_int2_rtn(short2);
int2 __const_func convert_int2_sat_rtn(short2);
int2 __const_func convert_int2(short2);
int2 __const_func convert_int2_sat(short2);
int2 __const_func convert_int2_rte(ushort2);
int2 __const_func convert_int2_sat_rte(ushort2);
int2 __const_func convert_int2_rtz(ushort2);
int2 __const_func convert_int2_sat_rtz(ushort2);
int2 __const_func convert_int2_rtp(ushort2);
int2 __const_func convert_int2_sat_rtp(ushort2);
int2 __const_func convert_int2_rtn(ushort2);
int2 __const_func convert_int2_sat_rtn(ushort2);
int2 __const_func convert_int2(ushort2);
int2 __const_func convert_int2_sat(ushort2);
int2 __const_func convert_int2_rte(int2);
int2 __const_func convert_int2_sat_rte(int2);
int2 __const_func convert_int2_rtz(int2);
int2 __const_func convert_int2_sat_rtz(int2);
int2 __const_func convert_int2_rtp(int2);
int2 __const_func convert_int2_sat_rtp(int2);
int2 __const_func convert_int2_rtn(int2);
int2 __const_func convert_int2_sat_rtn(int2);
int2 __const_func convert_int2(int2);
int2 __const_func convert_int2_sat(int2);
int2 __const_func convert_int2_rte(uint2);
int2 __const_func convert_int2_sat_rte(uint2);
int2 __const_func convert_int2_rtz(uint2);
int2 __const_func convert_int2_sat_rtz(uint2);
int2 __const_func convert_int2_rtp(uint2);
int2 __const_func convert_int2_sat_rtp(uint2);
int2 __const_func convert_int2_rtn(uint2);
int2 __const_func convert_int2_sat_rtn(uint2);
int2 __const_func convert_int2(uint2);
int2 __const_func convert_int2_sat(uint2);
int2 __const_func convert_int2_rte(long2);
int2 __const_func convert_int2_sat_rte(long2);
int2 __const_func convert_int2_rtz(long2);
int2 __const_func convert_int2_sat_rtz(long2);
int2 __const_func convert_int2_rtp(long2);
int2 __const_func convert_int2_sat_rtp(long2);
int2 __const_func convert_int2_rtn(long2);
int2 __const_func convert_int2_sat_rtn(long2);
int2 __const_func convert_int2(long2);
int2 __const_func convert_int2_sat(long2);
int2 __const_func convert_int2_rte(ulong2);
int2 __const_func convert_int2_sat_rte(ulong2);
int2 __const_func convert_int2_rtz(ulong2);
int2 __const_func convert_int2_sat_rtz(ulong2);
int2 __const_func convert_int2_rtp(ulong2);
int2 __const_func convert_int2_sat_rtp(ulong2);
int2 __const_func convert_int2_rtn(ulong2);
int2 __const_func convert_int2_sat_rtn(ulong2);
int2 __const_func convert_int2(ulong2);
int2 __const_func convert_int2_sat(ulong2);
int2 __const_func convert_int2_rte(float2);
int2 __const_func convert_int2_sat_rte(float2);
int2 __const_func convert_int2_rtz(float2);
int2 __const_func convert_int2_sat_rtz(float2);
int2 __const_func convert_int2_rtp(float2);
int2 __const_func convert_int2_sat_rtp(float2);
int2 __const_func convert_int2_rtn(float2);
int2 __const_func convert_int2_sat_rtn(float2);
int2 __const_func convert_int2(float2);
int2 __const_func convert_int2_sat(float2);
uint2 __const_func convert_uint2_rte(char2);
uint2 __const_func convert_uint2_sat_rte(char2);
uint2 __const_func convert_uint2_rtz(char2);
uint2 __const_func convert_uint2_sat_rtz(char2);
uint2 __const_func convert_uint2_rtp(char2);
uint2 __const_func convert_uint2_sat_rtp(char2);
uint2 __const_func convert_uint2_rtn(char2);
uint2 __const_func convert_uint2_sat_rtn(char2);
uint2 __const_func convert_uint2(char2);
uint2 __const_func convert_uint2_sat(char2);
uint2 __const_func convert_uint2_rte(uchar2);
uint2 __const_func convert_uint2_sat_rte(uchar2);
uint2 __const_func convert_uint2_rtz(uchar2);
uint2 __const_func convert_uint2_sat_rtz(uchar2);
uint2 __const_func convert_uint2_rtp(uchar2);
uint2 __const_func convert_uint2_sat_rtp(uchar2);
uint2 __const_func convert_uint2_rtn(uchar2);
uint2 __const_func convert_uint2_sat_rtn(uchar2);
uint2 __const_func convert_uint2(uchar2);
uint2 __const_func convert_uint2_sat(uchar2);
uint2 __const_func convert_uint2_rte(short2);
uint2 __const_func convert_uint2_sat_rte(short2);
uint2 __const_func convert_uint2_rtz(short2);
uint2 __const_func convert_uint2_sat_rtz(short2);
uint2 __const_func convert_uint2_rtp(short2);
uint2 __const_func convert_uint2_sat_rtp(short2);
uint2 __const_func convert_uint2_rtn(short2);
uint2 __const_func convert_uint2_sat_rtn(short2);
uint2 __const_func convert_uint2(short2);
uint2 __const_func convert_uint2_sat(short2);
uint2 __const_func convert_uint2_rte(ushort2);
uint2 __const_func convert_uint2_sat_rte(ushort2);
uint2 __const_func convert_uint2_rtz(ushort2);
uint2 __const_func convert_uint2_sat_rtz(ushort2);
uint2 __const_func convert_uint2_rtp(ushort2);
uint2 __const_func convert_uint2_sat_rtp(ushort2);
uint2 __const_func convert_uint2_rtn(ushort2);
uint2 __const_func convert_uint2_sat_rtn(ushort2);
uint2 __const_func convert_uint2(ushort2);
uint2 __const_func convert_uint2_sat(ushort2);
uint2 __const_func convert_uint2_rte(int2);
uint2 __const_func convert_uint2_sat_rte(int2);
uint2 __const_func convert_uint2_rtz(int2);
uint2 __const_func convert_uint2_sat_rtz(int2);
uint2 __const_func convert_uint2_rtp(int2);
uint2 __const_func convert_uint2_sat_rtp(int2);
uint2 __const_func convert_uint2_rtn(int2);
uint2 __const_func convert_uint2_sat_rtn(int2);
uint2 __const_func convert_uint2(int2);
uint2 __const_func convert_uint2_sat(int2);
uint2 __const_func convert_uint2_rte(uint2);
uint2 __const_func convert_uint2_sat_rte(uint2);
uint2 __const_func convert_uint2_rtz(uint2);
uint2 __const_func convert_uint2_sat_rtz(uint2);
uint2 __const_func convert_uint2_rtp(uint2);
uint2 __const_func convert_uint2_sat_rtp(uint2);
uint2 __const_func convert_uint2_rtn(uint2);
uint2 __const_func convert_uint2_sat_rtn(uint2);
uint2 __const_func convert_uint2(uint2);
uint2 __const_func convert_uint2_sat(uint2);
uint2 __const_func convert_uint2_rte(long2);
uint2 __const_func convert_uint2_sat_rte(long2);
uint2 __const_func convert_uint2_rtz(long2);
uint2 __const_func convert_uint2_sat_rtz(long2);
uint2 __const_func convert_uint2_rtp(long2);
uint2 __const_func convert_uint2_sat_rtp(long2);
uint2 __const_func convert_uint2_rtn(long2);
uint2 __const_func convert_uint2_sat_rtn(long2);
uint2 __const_func convert_uint2(long2);
uint2 __const_func convert_uint2_sat(long2);
uint2 __const_func convert_uint2_rte(ulong2);
uint2 __const_func convert_uint2_sat_rte(ulong2);
uint2 __const_func convert_uint2_rtz(ulong2);
uint2 __const_func convert_uint2_sat_rtz(ulong2);
uint2 __const_func convert_uint2_rtp(ulong2);
uint2 __const_func convert_uint2_sat_rtp(ulong2);
uint2 __const_func convert_uint2_rtn(ulong2);
uint2 __const_func convert_uint2_sat_rtn(ulong2);
uint2 __const_func convert_uint2(ulong2);
uint2 __const_func convert_uint2_sat(ulong2);
uint2 __const_func convert_uint2_rte(float2);
uint2 __const_func convert_uint2_sat_rte(float2);
uint2 __const_func convert_uint2_rtz(float2);
uint2 __const_func convert_uint2_sat_rtz(float2);
uint2 __const_func convert_uint2_rtp(float2);
uint2 __const_func convert_uint2_sat_rtp(float2);
uint2 __const_func convert_uint2_rtn(float2);
uint2 __const_func convert_uint2_sat_rtn(float2);
uint2 __const_func convert_uint2(float2);
uint2 __const_func convert_uint2_sat(float2);
long2 __const_func convert_long2_rte(char2);
long2 __const_func convert_long2_sat_rte(char2);
long2 __const_func convert_long2_rtz(char2);
long2 __const_func convert_long2_sat_rtz(char2);
long2 __const_func convert_long2_rtp(char2);
long2 __const_func convert_long2_sat_rtp(char2);
long2 __const_func convert_long2_rtn(char2);
long2 __const_func convert_long2_sat_rtn(char2);
long2 __const_func convert_long2(char2);
long2 __const_func convert_long2_sat(char2);
long2 __const_func convert_long2_rte(uchar2);
long2 __const_func convert_long2_sat_rte(uchar2);
long2 __const_func convert_long2_rtz(uchar2);
long2 __const_func convert_long2_sat_rtz(uchar2);
long2 __const_func convert_long2_rtp(uchar2);
long2 __const_func convert_long2_sat_rtp(uchar2);
long2 __const_func convert_long2_rtn(uchar2);
long2 __const_func convert_long2_sat_rtn(uchar2);
long2 __const_func convert_long2(uchar2);
long2 __const_func convert_long2_sat(uchar2);
long2 __const_func convert_long2_rte(short2);
long2 __const_func convert_long2_sat_rte(short2);
long2 __const_func convert_long2_rtz(short2);
long2 __const_func convert_long2_sat_rtz(short2);
long2 __const_func convert_long2_rtp(short2);
long2 __const_func convert_long2_sat_rtp(short2);
long2 __const_func convert_long2_rtn(short2);
long2 __const_func convert_long2_sat_rtn(short2);
long2 __const_func convert_long2(short2);
long2 __const_func convert_long2_sat(short2);
long2 __const_func convert_long2_rte(ushort2);
long2 __const_func convert_long2_sat_rte(ushort2);
long2 __const_func convert_long2_rtz(ushort2);
long2 __const_func convert_long2_sat_rtz(ushort2);
long2 __const_func convert_long2_rtp(ushort2);
long2 __const_func convert_long2_sat_rtp(ushort2);
long2 __const_func convert_long2_rtn(ushort2);
long2 __const_func convert_long2_sat_rtn(ushort2);
long2 __const_func convert_long2(ushort2);
long2 __const_func convert_long2_sat(ushort2);
long2 __const_func convert_long2_rte(int2);
long2 __const_func convert_long2_sat_rte(int2);
long2 __const_func convert_long2_rtz(int2);
long2 __const_func convert_long2_sat_rtz(int2);
long2 __const_func convert_long2_rtp(int2);
long2 __const_func convert_long2_sat_rtp(int2);
long2 __const_func convert_long2_rtn(int2);
long2 __const_func convert_long2_sat_rtn(int2);
long2 __const_func convert_long2(int2);
long2 __const_func convert_long2_sat(int2);
long2 __const_func convert_long2_rte(uint2);
long2 __const_func convert_long2_sat_rte(uint2);
long2 __const_func convert_long2_rtz(uint2);
long2 __const_func convert_long2_sat_rtz(uint2);
long2 __const_func convert_long2_rtp(uint2);
long2 __const_func convert_long2_sat_rtp(uint2);
long2 __const_func convert_long2_rtn(uint2);
long2 __const_func convert_long2_sat_rtn(uint2);
long2 __const_func convert_long2(uint2);
long2 __const_func convert_long2_sat(uint2);
long2 __const_func convert_long2_rte(long2);
long2 __const_func convert_long2_sat_rte(long2);
long2 __const_func convert_long2_rtz(long2);
long2 __const_func convert_long2_sat_rtz(long2);
long2 __const_func convert_long2_rtp(long2);
long2 __const_func convert_long2_sat_rtp(long2);
long2 __const_func convert_long2_rtn(long2);
long2 __const_func convert_long2_sat_rtn(long2);
long2 __const_func convert_long2(long2);
long2 __const_func convert_long2_sat(long2);
long2 __const_func convert_long2_rte(ulong2);
long2 __const_func convert_long2_sat_rte(ulong2);
long2 __const_func convert_long2_rtz(ulong2);
long2 __const_func convert_long2_sat_rtz(ulong2);
long2 __const_func convert_long2_rtp(ulong2);
long2 __const_func convert_long2_sat_rtp(ulong2);
long2 __const_func convert_long2_rtn(ulong2);
long2 __const_func convert_long2_sat_rtn(ulong2);
long2 __const_func convert_long2(ulong2);
long2 __const_func convert_long2_sat(ulong2);
long2 __const_func convert_long2_rte(float2);
long2 __const_func convert_long2_sat_rte(float2);
long2 __const_func convert_long2_rtz(float2);
long2 __const_func convert_long2_sat_rtz(float2);
long2 __const_func convert_long2_rtp(float2);
long2 __const_func convert_long2_sat_rtp(float2);
long2 __const_func convert_long2_rtn(float2);
long2 __const_func convert_long2_sat_rtn(float2);
long2 __const_func convert_long2(float2);
long2 __const_func convert_long2_sat(float2);
ulong2 __const_func convert_ulong2_rte(char2);
ulong2 __const_func convert_ulong2_sat_rte(char2);
ulong2 __const_func convert_ulong2_rtz(char2);
ulong2 __const_func convert_ulong2_sat_rtz(char2);
ulong2 __const_func convert_ulong2_rtp(char2);
ulong2 __const_func convert_ulong2_sat_rtp(char2);
ulong2 __const_func convert_ulong2_rtn(char2);
ulong2 __const_func convert_ulong2_sat_rtn(char2);
ulong2 __const_func convert_ulong2(char2);
ulong2 __const_func convert_ulong2_sat(char2);
ulong2 __const_func convert_ulong2_rte(uchar2);
ulong2 __const_func convert_ulong2_sat_rte(uchar2);
ulong2 __const_func convert_ulong2_rtz(uchar2);
ulong2 __const_func convert_ulong2_sat_rtz(uchar2);
ulong2 __const_func convert_ulong2_rtp(uchar2);
ulong2 __const_func convert_ulong2_sat_rtp(uchar2);
ulong2 __const_func convert_ulong2_rtn(uchar2);
ulong2 __const_func convert_ulong2_sat_rtn(uchar2);
ulong2 __const_func convert_ulong2(uchar2);
ulong2 __const_func convert_ulong2_sat(uchar2);
ulong2 __const_func convert_ulong2_rte(short2);
ulong2 __const_func convert_ulong2_sat_rte(short2);
ulong2 __const_func convert_ulong2_rtz(short2);
ulong2 __const_func convert_ulong2_sat_rtz(short2);
ulong2 __const_func convert_ulong2_rtp(short2);
ulong2 __const_func convert_ulong2_sat_rtp(short2);
ulong2 __const_func convert_ulong2_rtn(short2);
ulong2 __const_func convert_ulong2_sat_rtn(short2);
ulong2 __const_func convert_ulong2(short2);
ulong2 __const_func convert_ulong2_sat(short2);
ulong2 __const_func convert_ulong2_rte(ushort2);
ulong2 __const_func convert_ulong2_sat_rte(ushort2);
ulong2 __const_func convert_ulong2_rtz(ushort2);
ulong2 __const_func convert_ulong2_sat_rtz(ushort2);
ulong2 __const_func convert_ulong2_rtp(ushort2);
ulong2 __const_func convert_ulong2_sat_rtp(ushort2);
ulong2 __const_func convert_ulong2_rtn(ushort2);
ulong2 __const_func convert_ulong2_sat_rtn(ushort2);
ulong2 __const_func convert_ulong2(ushort2);
ulong2 __const_func convert_ulong2_sat(ushort2);
ulong2 __const_func convert_ulong2_rte(int2);
ulong2 __const_func convert_ulong2_sat_rte(int2);
ulong2 __const_func convert_ulong2_rtz(int2);
ulong2 __const_func convert_ulong2_sat_rtz(int2);
ulong2 __const_func convert_ulong2_rtp(int2);
ulong2 __const_func convert_ulong2_sat_rtp(int2);
ulong2 __const_func convert_ulong2_rtn(int2);
ulong2 __const_func convert_ulong2_sat_rtn(int2);
ulong2 __const_func convert_ulong2(int2);
ulong2 __const_func convert_ulong2_sat(int2);
ulong2 __const_func convert_ulong2_rte(uint2);
ulong2 __const_func convert_ulong2_sat_rte(uint2);
ulong2 __const_func convert_ulong2_rtz(uint2);
ulong2 __const_func convert_ulong2_sat_rtz(uint2);
ulong2 __const_func convert_ulong2_rtp(uint2);
ulong2 __const_func convert_ulong2_sat_rtp(uint2);
ulong2 __const_func convert_ulong2_rtn(uint2);
ulong2 __const_func convert_ulong2_sat_rtn(uint2);
ulong2 __const_func convert_ulong2(uint2);
ulong2 __const_func convert_ulong2_sat(uint2);
ulong2 __const_func convert_ulong2_rte(long2);
ulong2 __const_func convert_ulong2_sat_rte(long2);
ulong2 __const_func convert_ulong2_rtz(long2);
ulong2 __const_func convert_ulong2_sat_rtz(long2);
ulong2 __const_func convert_ulong2_rtp(long2);
ulong2 __const_func convert_ulong2_sat_rtp(long2);
ulong2 __const_func convert_ulong2_rtn(long2);
ulong2 __const_func convert_ulong2_sat_rtn(long2);
ulong2 __const_func convert_ulong2(long2);
ulong2 __const_func convert_ulong2_sat(long2);
ulong2 __const_func convert_ulong2_rte(ulong2);
ulong2 __const_func convert_ulong2_sat_rte(ulong2);
ulong2 __const_func convert_ulong2_rtz(ulong2);
ulong2 __const_func convert_ulong2_sat_rtz(ulong2);
ulong2 __const_func convert_ulong2_rtp(ulong2);
ulong2 __const_func convert_ulong2_sat_rtp(ulong2);
ulong2 __const_func convert_ulong2_rtn(ulong2);
ulong2 __const_func convert_ulong2_sat_rtn(ulong2);
ulong2 __const_func convert_ulong2(ulong2);
ulong2 __const_func convert_ulong2_sat(ulong2);
ulong2 __const_func convert_ulong2_rte(float2);
ulong2 __const_func convert_ulong2_sat_rte(float2);
ulong2 __const_func convert_ulong2_rtz(float2);
ulong2 __const_func convert_ulong2_sat_rtz(float2);
ulong2 __const_func convert_ulong2_rtp(float2);
ulong2 __const_func convert_ulong2_sat_rtp(float2);
ulong2 __const_func convert_ulong2_rtn(float2);
ulong2 __const_func convert_ulong2_sat_rtn(float2);
ulong2 __const_func convert_ulong2(float2);
ulong2 __const_func convert_ulong2_sat(float2);
float2 __const_func convert_float2_rte(char2);
float2 __const_func convert_float2_rtz(char2);
float2 __const_func convert_float2_rtp(char2);
float2 __const_func convert_float2_rtn(char2);
float2 __const_func convert_float2(char2);
float2 __const_func convert_float2_rte(uchar2);
float2 __const_func convert_float2_rtz(uchar2);
float2 __const_func convert_float2_rtp(uchar2);
float2 __const_func convert_float2_rtn(uchar2);
float2 __const_func convert_float2(uchar2);
float2 __const_func convert_float2_rte(short2);
float2 __const_func convert_float2_rtz(short2);
float2 __const_func convert_float2_rtp(short2);
float2 __const_func convert_float2_rtn(short2);
float2 __const_func convert_float2(short2);
float2 __const_func convert_float2_rte(ushort2);
float2 __const_func convert_float2_rtz(ushort2);
float2 __const_func convert_float2_rtp(ushort2);
float2 __const_func convert_float2_rtn(ushort2);
float2 __const_func convert_float2(ushort2);
float2 __const_func convert_float2_rte(int2);
float2 __const_func convert_float2_rtz(int2);
float2 __const_func convert_float2_rtp(int2);
float2 __const_func convert_float2_rtn(int2);
float2 __const_func convert_float2(int2);
float2 __const_func convert_float2_rte(uint2);
float2 __const_func convert_float2_rtz(uint2);
float2 __const_func convert_float2_rtp(uint2);
float2 __const_func convert_float2_rtn(uint2);
float2 __const_func convert_float2(uint2);
float2 __const_func convert_float2_rte(long2);
float2 __const_func convert_float2_rtz(long2);
float2 __const_func convert_float2_rtp(long2);
float2 __const_func convert_float2_rtn(long2);
float2 __const_func convert_float2(long2);
float2 __const_func convert_float2_rte(ulong2);
float2 __const_func convert_float2_rtz(ulong2);
float2 __const_func convert_float2_rtp(ulong2);
float2 __const_func convert_float2_rtn(ulong2);
float2 __const_func convert_float2(ulong2);
float2 __const_func convert_float2_rte(float2);
float2 __const_func convert_float2_rtz(float2);
float2 __const_func convert_float2_rtp(float2);
float2 __const_func convert_float2_rtn(float2);
float2 __const_func convert_float2(float2);
char3 __const_func convert_char3_rte(char3);
char3 __const_func convert_char3_sat_rte(char3);
char3 __const_func convert_char3_rtz(char3);
char3 __const_func convert_char3_sat_rtz(char3);
char3 __const_func convert_char3_rtp(char3);
char3 __const_func convert_char3_sat_rtp(char3);
char3 __const_func convert_char3_rtn(char3);
char3 __const_func convert_char3_sat_rtn(char3);
char3 __const_func convert_char3(char3);
char3 __const_func convert_char3_sat(char3);
char3 __const_func convert_char3_rte(uchar3);
char3 __const_func convert_char3_sat_rte(uchar3);
char3 __const_func convert_char3_rtz(uchar3);
char3 __const_func convert_char3_sat_rtz(uchar3);
char3 __const_func convert_char3_rtp(uchar3);
char3 __const_func convert_char3_sat_rtp(uchar3);
char3 __const_func convert_char3_rtn(uchar3);
char3 __const_func convert_char3_sat_rtn(uchar3);
char3 __const_func convert_char3(uchar3);
char3 __const_func convert_char3_sat(uchar3);
char3 __const_func convert_char3_rte(short3);
char3 __const_func convert_char3_sat_rte(short3);
char3 __const_func convert_char3_rtz(short3);
char3 __const_func convert_char3_sat_rtz(short3);
char3 __const_func convert_char3_rtp(short3);
char3 __const_func convert_char3_sat_rtp(short3);
char3 __const_func convert_char3_rtn(short3);
char3 __const_func convert_char3_sat_rtn(short3);
char3 __const_func convert_char3(short3);
char3 __const_func convert_char3_sat(short3);
char3 __const_func convert_char3_rte(ushort3);
char3 __const_func convert_char3_sat_rte(ushort3);
char3 __const_func convert_char3_rtz(ushort3);
char3 __const_func convert_char3_sat_rtz(ushort3);
char3 __const_func convert_char3_rtp(ushort3);
char3 __const_func convert_char3_sat_rtp(ushort3);
char3 __const_func convert_char3_rtn(ushort3);
char3 __const_func convert_char3_sat_rtn(ushort3);
char3 __const_func convert_char3(ushort3);
char3 __const_func convert_char3_sat(ushort3);
char3 __const_func convert_char3_rte(int3);
char3 __const_func convert_char3_sat_rte(int3);
char3 __const_func convert_char3_rtz(int3);
char3 __const_func convert_char3_sat_rtz(int3);
char3 __const_func convert_char3_rtp(int3);
char3 __const_func convert_char3_sat_rtp(int3);
char3 __const_func convert_char3_rtn(int3);
char3 __const_func convert_char3_sat_rtn(int3);
char3 __const_func convert_char3(int3);
char3 __const_func convert_char3_sat(int3);
char3 __const_func convert_char3_rte(uint3);
char3 __const_func convert_char3_sat_rte(uint3);
char3 __const_func convert_char3_rtz(uint3);
char3 __const_func convert_char3_sat_rtz(uint3);
char3 __const_func convert_char3_rtp(uint3);
char3 __const_func convert_char3_sat_rtp(uint3);
char3 __const_func convert_char3_rtn(uint3);
char3 __const_func convert_char3_sat_rtn(uint3);
char3 __const_func convert_char3(uint3);
char3 __const_func convert_char3_sat(uint3);
char3 __const_func convert_char3_rte(long3);
char3 __const_func convert_char3_sat_rte(long3);
char3 __const_func convert_char3_rtz(long3);
char3 __const_func convert_char3_sat_rtz(long3);
char3 __const_func convert_char3_rtp(long3);
char3 __const_func convert_char3_sat_rtp(long3);
char3 __const_func convert_char3_rtn(long3);
char3 __const_func convert_char3_sat_rtn(long3);
char3 __const_func convert_char3(long3);
char3 __const_func convert_char3_sat(long3);
char3 __const_func convert_char3_rte(ulong3);
char3 __const_func convert_char3_sat_rte(ulong3);
char3 __const_func convert_char3_rtz(ulong3);
char3 __const_func convert_char3_sat_rtz(ulong3);
char3 __const_func convert_char3_rtp(ulong3);
char3 __const_func convert_char3_sat_rtp(ulong3);
char3 __const_func convert_char3_rtn(ulong3);
char3 __const_func convert_char3_sat_rtn(ulong3);
char3 __const_func convert_char3(ulong3);
char3 __const_func convert_char3_sat(ulong3);
char3 __const_func convert_char3_rte(float3);
char3 __const_func convert_char3_sat_rte(float3);
char3 __const_func convert_char3_rtz(float3);
char3 __const_func convert_char3_sat_rtz(float3);
char3 __const_func convert_char3_rtp(float3);
char3 __const_func convert_char3_sat_rtp(float3);
char3 __const_func convert_char3_rtn(float3);
char3 __const_func convert_char3_sat_rtn(float3);
char3 __const_func convert_char3(float3);
char3 __const_func convert_char3_sat(float3);
uchar3 __const_func convert_uchar3_rte(char3);
uchar3 __const_func convert_uchar3_sat_rte(char3);
uchar3 __const_func convert_uchar3_rtz(char3);
uchar3 __const_func convert_uchar3_sat_rtz(char3);
uchar3 __const_func convert_uchar3_rtp(char3);
uchar3 __const_func convert_uchar3_sat_rtp(char3);
uchar3 __const_func convert_uchar3_rtn(char3);
uchar3 __const_func convert_uchar3_sat_rtn(char3);
uchar3 __const_func convert_uchar3(char3);
uchar3 __const_func convert_uchar3_sat(char3);
uchar3 __const_func convert_uchar3_rte(uchar3);
uchar3 __const_func convert_uchar3_sat_rte(uchar3);
uchar3 __const_func convert_uchar3_rtz(uchar3);
uchar3 __const_func convert_uchar3_sat_rtz(uchar3);
uchar3 __const_func convert_uchar3_rtp(uchar3);
uchar3 __const_func convert_uchar3_sat_rtp(uchar3);
uchar3 __const_func convert_uchar3_rtn(uchar3);
uchar3 __const_func convert_uchar3_sat_rtn(uchar3);
uchar3 __const_func convert_uchar3(uchar3);
uchar3 __const_func convert_uchar3_sat(uchar3);
uchar3 __const_func convert_uchar3_rte(short3);
uchar3 __const_func convert_uchar3_sat_rte(short3);
uchar3 __const_func convert_uchar3_rtz(short3);
uchar3 __const_func convert_uchar3_sat_rtz(short3);
uchar3 __const_func convert_uchar3_rtp(short3);
uchar3 __const_func convert_uchar3_sat_rtp(short3);
uchar3 __const_func convert_uchar3_rtn(short3);
uchar3 __const_func convert_uchar3_sat_rtn(short3);
uchar3 __const_func convert_uchar3(short3);
uchar3 __const_func convert_uchar3_sat(short3);
uchar3 __const_func convert_uchar3_rte(ushort3);
uchar3 __const_func convert_uchar3_sat_rte(ushort3);
uchar3 __const_func convert_uchar3_rtz(ushort3);
uchar3 __const_func convert_uchar3_sat_rtz(ushort3);
uchar3 __const_func convert_uchar3_rtp(ushort3);
uchar3 __const_func convert_uchar3_sat_rtp(ushort3);
uchar3 __const_func convert_uchar3_rtn(ushort3);
uchar3 __const_func convert_uchar3_sat_rtn(ushort3);
uchar3 __const_func convert_uchar3(ushort3);
uchar3 __const_func convert_uchar3_sat(ushort3);
uchar3 __const_func convert_uchar3_rte(int3);
uchar3 __const_func convert_uchar3_sat_rte(int3);
uchar3 __const_func convert_uchar3_rtz(int3);
uchar3 __const_func convert_uchar3_sat_rtz(int3);
uchar3 __const_func convert_uchar3_rtp(int3);
uchar3 __const_func convert_uchar3_sat_rtp(int3);
uchar3 __const_func convert_uchar3_rtn(int3);
uchar3 __const_func convert_uchar3_sat_rtn(int3);
uchar3 __const_func convert_uchar3(int3);
uchar3 __const_func convert_uchar3_sat(int3);
uchar3 __const_func convert_uchar3_rte(uint3);
uchar3 __const_func convert_uchar3_sat_rte(uint3);
uchar3 __const_func convert_uchar3_rtz(uint3);
uchar3 __const_func convert_uchar3_sat_rtz(uint3);
uchar3 __const_func convert_uchar3_rtp(uint3);
uchar3 __const_func convert_uchar3_sat_rtp(uint3);
uchar3 __const_func convert_uchar3_rtn(uint3);
uchar3 __const_func convert_uchar3_sat_rtn(uint3);
uchar3 __const_func convert_uchar3(uint3);
uchar3 __const_func convert_uchar3_sat(uint3);
uchar3 __const_func convert_uchar3_rte(long3);
uchar3 __const_func convert_uchar3_sat_rte(long3);
uchar3 __const_func convert_uchar3_rtz(long3);
uchar3 __const_func convert_uchar3_sat_rtz(long3);
uchar3 __const_func convert_uchar3_rtp(long3);
uchar3 __const_func convert_uchar3_sat_rtp(long3);
uchar3 __const_func convert_uchar3_rtn(long3);
uchar3 __const_func convert_uchar3_sat_rtn(long3);
uchar3 __const_func convert_uchar3(long3);
uchar3 __const_func convert_uchar3_sat(long3);
uchar3 __const_func convert_uchar3_rte(ulong3);
uchar3 __const_func convert_uchar3_sat_rte(ulong3);
uchar3 __const_func convert_uchar3_rtz(ulong3);
uchar3 __const_func convert_uchar3_sat_rtz(ulong3);
uchar3 __const_func convert_uchar3_rtp(ulong3);
uchar3 __const_func convert_uchar3_sat_rtp(ulong3);
uchar3 __const_func convert_uchar3_rtn(ulong3);
uchar3 __const_func convert_uchar3_sat_rtn(ulong3);
uchar3 __const_func convert_uchar3(ulong3);
uchar3 __const_func convert_uchar3_sat(ulong3);
uchar3 __const_func convert_uchar3_rte(float3);
uchar3 __const_func convert_uchar3_sat_rte(float3);
uchar3 __const_func convert_uchar3_rtz(float3);
uchar3 __const_func convert_uchar3_sat_rtz(float3);
uchar3 __const_func convert_uchar3_rtp(float3);
uchar3 __const_func convert_uchar3_sat_rtp(float3);
uchar3 __const_func convert_uchar3_rtn(float3);
uchar3 __const_func convert_uchar3_sat_rtn(float3);
uchar3 __const_func convert_uchar3(float3);
uchar3 __const_func convert_uchar3_sat(float3);
short3 __const_func convert_short3_rte(char3);
short3 __const_func convert_short3_sat_rte(char3);
short3 __const_func convert_short3_rtz(char3);
short3 __const_func convert_short3_sat_rtz(char3);
short3 __const_func convert_short3_rtp(char3);
short3 __const_func convert_short3_sat_rtp(char3);
short3 __const_func convert_short3_rtn(char3);
short3 __const_func convert_short3_sat_rtn(char3);
short3 __const_func convert_short3(char3);
short3 __const_func convert_short3_sat(char3);
short3 __const_func convert_short3_rte(uchar3);
short3 __const_func convert_short3_sat_rte(uchar3);
short3 __const_func convert_short3_rtz(uchar3);
short3 __const_func convert_short3_sat_rtz(uchar3);
short3 __const_func convert_short3_rtp(uchar3);
short3 __const_func convert_short3_sat_rtp(uchar3);
short3 __const_func convert_short3_rtn(uchar3);
short3 __const_func convert_short3_sat_rtn(uchar3);
short3 __const_func convert_short3(uchar3);
short3 __const_func convert_short3_sat(uchar3);
short3 __const_func convert_short3_rte(short3);
short3 __const_func convert_short3_sat_rte(short3);
short3 __const_func convert_short3_rtz(short3);
short3 __const_func convert_short3_sat_rtz(short3);
short3 __const_func convert_short3_rtp(short3);
short3 __const_func convert_short3_sat_rtp(short3);
short3 __const_func convert_short3_rtn(short3);
short3 __const_func convert_short3_sat_rtn(short3);
short3 __const_func convert_short3(short3);
short3 __const_func convert_short3_sat(short3);
short3 __const_func convert_short3_rte(ushort3);
short3 __const_func convert_short3_sat_rte(ushort3);
short3 __const_func convert_short3_rtz(ushort3);
short3 __const_func convert_short3_sat_rtz(ushort3);
short3 __const_func convert_short3_rtp(ushort3);
short3 __const_func convert_short3_sat_rtp(ushort3);
short3 __const_func convert_short3_rtn(ushort3);
short3 __const_func convert_short3_sat_rtn(ushort3);
short3 __const_func convert_short3(ushort3);
short3 __const_func convert_short3_sat(ushort3);
short3 __const_func convert_short3_rte(int3);
short3 __const_func convert_short3_sat_rte(int3);
short3 __const_func convert_short3_rtz(int3);
short3 __const_func convert_short3_sat_rtz(int3);
short3 __const_func convert_short3_rtp(int3);
short3 __const_func convert_short3_sat_rtp(int3);
short3 __const_func convert_short3_rtn(int3);
short3 __const_func convert_short3_sat_rtn(int3);
short3 __const_func convert_short3(int3);
short3 __const_func convert_short3_sat(int3);
short3 __const_func convert_short3_rte(uint3);
short3 __const_func convert_short3_sat_rte(uint3);
short3 __const_func convert_short3_rtz(uint3);
short3 __const_func convert_short3_sat_rtz(uint3);
short3 __const_func convert_short3_rtp(uint3);
short3 __const_func convert_short3_sat_rtp(uint3);
short3 __const_func convert_short3_rtn(uint3);
short3 __const_func convert_short3_sat_rtn(uint3);
short3 __const_func convert_short3(uint3);
short3 __const_func convert_short3_sat(uint3);
short3 __const_func convert_short3_rte(long3);
short3 __const_func convert_short3_sat_rte(long3);
short3 __const_func convert_short3_rtz(long3);
short3 __const_func convert_short3_sat_rtz(long3);
short3 __const_func convert_short3_rtp(long3);
short3 __const_func convert_short3_sat_rtp(long3);
short3 __const_func convert_short3_rtn(long3);
short3 __const_func convert_short3_sat_rtn(long3);
short3 __const_func convert_short3(long3);
short3 __const_func convert_short3_sat(long3);
short3 __const_func convert_short3_rte(ulong3);
short3 __const_func convert_short3_sat_rte(ulong3);
short3 __const_func convert_short3_rtz(ulong3);
short3 __const_func convert_short3_sat_rtz(ulong3);
short3 __const_func convert_short3_rtp(ulong3);
short3 __const_func convert_short3_sat_rtp(ulong3);
short3 __const_func convert_short3_rtn(ulong3);
short3 __const_func convert_short3_sat_rtn(ulong3);
short3 __const_func convert_short3(ulong3);
short3 __const_func convert_short3_sat(ulong3);
short3 __const_func convert_short3_rte(float3);
short3 __const_func convert_short3_sat_rte(float3);
short3 __const_func convert_short3_rtz(float3);
short3 __const_func convert_short3_sat_rtz(float3);
short3 __const_func convert_short3_rtp(float3);
short3 __const_func convert_short3_sat_rtp(float3);
short3 __const_func convert_short3_rtn(float3);
short3 __const_func convert_short3_sat_rtn(float3);
short3 __const_func convert_short3(float3);
short3 __const_func convert_short3_sat(float3);
ushort3 __const_func convert_ushort3_rte(char3);
ushort3 __const_func convert_ushort3_sat_rte(char3);
ushort3 __const_func convert_ushort3_rtz(char3);
ushort3 __const_func convert_ushort3_sat_rtz(char3);
ushort3 __const_func convert_ushort3_rtp(char3);
ushort3 __const_func convert_ushort3_sat_rtp(char3);
ushort3 __const_func convert_ushort3_rtn(char3);
ushort3 __const_func convert_ushort3_sat_rtn(char3);
ushort3 __const_func convert_ushort3(char3);
ushort3 __const_func convert_ushort3_sat(char3);
ushort3 __const_func convert_ushort3_rte(uchar3);
ushort3 __const_func convert_ushort3_sat_rte(uchar3);
ushort3 __const_func convert_ushort3_rtz(uchar3);
ushort3 __const_func convert_ushort3_sat_rtz(uchar3);
ushort3 __const_func convert_ushort3_rtp(uchar3);
ushort3 __const_func convert_ushort3_sat_rtp(uchar3);
ushort3 __const_func convert_ushort3_rtn(uchar3);
ushort3 __const_func convert_ushort3_sat_rtn(uchar3);
ushort3 __const_func convert_ushort3(uchar3);
ushort3 __const_func convert_ushort3_sat(uchar3);
ushort3 __const_func convert_ushort3_rte(short3);
ushort3 __const_func convert_ushort3_sat_rte(short3);
ushort3 __const_func convert_ushort3_rtz(short3);
ushort3 __const_func convert_ushort3_sat_rtz(short3);
ushort3 __const_func convert_ushort3_rtp(short3);
ushort3 __const_func convert_ushort3_sat_rtp(short3);
ushort3 __const_func convert_ushort3_rtn(short3);
ushort3 __const_func convert_ushort3_sat_rtn(short3);
ushort3 __const_func convert_ushort3(short3);
ushort3 __const_func convert_ushort3_sat(short3);
ushort3 __const_func convert_ushort3_rte(ushort3);
ushort3 __const_func convert_ushort3_sat_rte(ushort3);
ushort3 __const_func convert_ushort3_rtz(ushort3);
ushort3 __const_func convert_ushort3_sat_rtz(ushort3);
ushort3 __const_func convert_ushort3_rtp(ushort3);
ushort3 __const_func convert_ushort3_sat_rtp(ushort3);
ushort3 __const_func convert_ushort3_rtn(ushort3);
ushort3 __const_func convert_ushort3_sat_rtn(ushort3);
ushort3 __const_func convert_ushort3(ushort3);
ushort3 __const_func convert_ushort3_sat(ushort3);
ushort3 __const_func convert_ushort3_rte(int3);
ushort3 __const_func convert_ushort3_sat_rte(int3);
ushort3 __const_func convert_ushort3_rtz(int3);
ushort3 __const_func convert_ushort3_sat_rtz(int3);
ushort3 __const_func convert_ushort3_rtp(int3);
ushort3 __const_func convert_ushort3_sat_rtp(int3);
ushort3 __const_func convert_ushort3_rtn(int3);
ushort3 __const_func convert_ushort3_sat_rtn(int3);
ushort3 __const_func convert_ushort3(int3);
ushort3 __const_func convert_ushort3_sat(int3);
ushort3 __const_func convert_ushort3_rte(uint3);
ushort3 __const_func convert_ushort3_sat_rte(uint3);
ushort3 __const_func convert_ushort3_rtz(uint3);
ushort3 __const_func convert_ushort3_sat_rtz(uint3);
ushort3 __const_func convert_ushort3_rtp(uint3);
ushort3 __const_func convert_ushort3_sat_rtp(uint3);
ushort3 __const_func convert_ushort3_rtn(uint3);
ushort3 __const_func convert_ushort3_sat_rtn(uint3);
ushort3 __const_func convert_ushort3(uint3);
ushort3 __const_func convert_ushort3_sat(uint3);
ushort3 __const_func convert_ushort3_rte(long3);
ushort3 __const_func convert_ushort3_sat_rte(long3);
ushort3 __const_func convert_ushort3_rtz(long3);
ushort3 __const_func convert_ushort3_sat_rtz(long3);
ushort3 __const_func convert_ushort3_rtp(long3);
ushort3 __const_func convert_ushort3_sat_rtp(long3);
ushort3 __const_func convert_ushort3_rtn(long3);
ushort3 __const_func convert_ushort3_sat_rtn(long3);
ushort3 __const_func convert_ushort3(long3);
ushort3 __const_func convert_ushort3_sat(long3);
ushort3 __const_func convert_ushort3_rte(ulong3);
ushort3 __const_func convert_ushort3_sat_rte(ulong3);
ushort3 __const_func convert_ushort3_rtz(ulong3);
ushort3 __const_func convert_ushort3_sat_rtz(ulong3);
ushort3 __const_func convert_ushort3_rtp(ulong3);
ushort3 __const_func convert_ushort3_sat_rtp(ulong3);
ushort3 __const_func convert_ushort3_rtn(ulong3);
ushort3 __const_func convert_ushort3_sat_rtn(ulong3);
ushort3 __const_func convert_ushort3(ulong3);
ushort3 __const_func convert_ushort3_sat(ulong3);
ushort3 __const_func convert_ushort3_rte(float3);
ushort3 __const_func convert_ushort3_sat_rte(float3);
ushort3 __const_func convert_ushort3_rtz(float3);
ushort3 __const_func convert_ushort3_sat_rtz(float3);
ushort3 __const_func convert_ushort3_rtp(float3);
ushort3 __const_func convert_ushort3_sat_rtp(float3);
ushort3 __const_func convert_ushort3_rtn(float3);
ushort3 __const_func convert_ushort3_sat_rtn(float3);
ushort3 __const_func convert_ushort3(float3);
ushort3 __const_func convert_ushort3_sat(float3);
int3 __const_func convert_int3_rte(char3);
int3 __const_func convert_int3_sat_rte(char3);
int3 __const_func convert_int3_rtz(char3);
int3 __const_func convert_int3_sat_rtz(char3);
int3 __const_func convert_int3_rtp(char3);
int3 __const_func convert_int3_sat_rtp(char3);
int3 __const_func convert_int3_rtn(char3);
int3 __const_func convert_int3_sat_rtn(char3);
int3 __const_func convert_int3(char3);
int3 __const_func convert_int3_sat(char3);
int3 __const_func convert_int3_rte(uchar3);
int3 __const_func convert_int3_sat_rte(uchar3);
int3 __const_func convert_int3_rtz(uchar3);
int3 __const_func convert_int3_sat_rtz(uchar3);
int3 __const_func convert_int3_rtp(uchar3);
int3 __const_func convert_int3_sat_rtp(uchar3);
int3 __const_func convert_int3_rtn(uchar3);
int3 __const_func convert_int3_sat_rtn(uchar3);
int3 __const_func convert_int3(uchar3);
int3 __const_func convert_int3_sat(uchar3);
int3 __const_func convert_int3_rte(short3);
int3 __const_func convert_int3_sat_rte(short3);
int3 __const_func convert_int3_rtz(short3);
int3 __const_func convert_int3_sat_rtz(short3);
int3 __const_func convert_int3_rtp(short3);
int3 __const_func convert_int3_sat_rtp(short3);
int3 __const_func convert_int3_rtn(short3);
int3 __const_func convert_int3_sat_rtn(short3);
int3 __const_func convert_int3(short3);
int3 __const_func convert_int3_sat(short3);
int3 __const_func convert_int3_rte(ushort3);
int3 __const_func convert_int3_sat_rte(ushort3);
int3 __const_func convert_int3_rtz(ushort3);
int3 __const_func convert_int3_sat_rtz(ushort3);
int3 __const_func convert_int3_rtp(ushort3);
int3 __const_func convert_int3_sat_rtp(ushort3);
int3 __const_func convert_int3_rtn(ushort3);
int3 __const_func convert_int3_sat_rtn(ushort3);
int3 __const_func convert_int3(ushort3);
int3 __const_func convert_int3_sat(ushort3);
int3 __const_func convert_int3_rte(int3);
int3 __const_func convert_int3_sat_rte(int3);
int3 __const_func convert_int3_rtz(int3);
int3 __const_func convert_int3_sat_rtz(int3);
int3 __const_func convert_int3_rtp(int3);
int3 __const_func convert_int3_sat_rtp(int3);
int3 __const_func convert_int3_rtn(int3);
int3 __const_func convert_int3_sat_rtn(int3);
int3 __const_func convert_int3(int3);
int3 __const_func convert_int3_sat(int3);
int3 __const_func convert_int3_rte(uint3);
int3 __const_func convert_int3_sat_rte(uint3);
int3 __const_func convert_int3_rtz(uint3);
int3 __const_func convert_int3_sat_rtz(uint3);
int3 __const_func convert_int3_rtp(uint3);
int3 __const_func convert_int3_sat_rtp(uint3);
int3 __const_func convert_int3_rtn(uint3);
int3 __const_func convert_int3_sat_rtn(uint3);
int3 __const_func convert_int3(uint3);
int3 __const_func convert_int3_sat(uint3);
int3 __const_func convert_int3_rte(long3);
int3 __const_func convert_int3_sat_rte(long3);
int3 __const_func convert_int3_rtz(long3);
int3 __const_func convert_int3_sat_rtz(long3);
int3 __const_func convert_int3_rtp(long3);
int3 __const_func convert_int3_sat_rtp(long3);
int3 __const_func convert_int3_rtn(long3);
int3 __const_func convert_int3_sat_rtn(long3);
int3 __const_func convert_int3(long3);
int3 __const_func convert_int3_sat(long3);
int3 __const_func convert_int3_rte(ulong3);
int3 __const_func convert_int3_sat_rte(ulong3);
int3 __const_func convert_int3_rtz(ulong3);
int3 __const_func convert_int3_sat_rtz(ulong3);
int3 __const_func convert_int3_rtp(ulong3);
int3 __const_func convert_int3_sat_rtp(ulong3);
int3 __const_func convert_int3_rtn(ulong3);
int3 __const_func convert_int3_sat_rtn(ulong3);
int3 __const_func convert_int3(ulong3);
int3 __const_func convert_int3_sat(ulong3);
int3 __const_func convert_int3_rte(float3);
int3 __const_func convert_int3_sat_rte(float3);
int3 __const_func convert_int3_rtz(float3);
int3 __const_func convert_int3_sat_rtz(float3);
int3 __const_func convert_int3_rtp(float3);
int3 __const_func convert_int3_sat_rtp(float3);
int3 __const_func convert_int3_rtn(float3);
int3 __const_func convert_int3_sat_rtn(float3);
int3 __const_func convert_int3(float3);
int3 __const_func convert_int3_sat(float3);
uint3 __const_func convert_uint3_rte(char3);
uint3 __const_func convert_uint3_sat_rte(char3);
uint3 __const_func convert_uint3_rtz(char3);
uint3 __const_func convert_uint3_sat_rtz(char3);
uint3 __const_func convert_uint3_rtp(char3);
uint3 __const_func convert_uint3_sat_rtp(char3);
uint3 __const_func convert_uint3_rtn(char3);
uint3 __const_func convert_uint3_sat_rtn(char3);
uint3 __const_func convert_uint3(char3);
uint3 __const_func convert_uint3_sat(char3);
uint3 __const_func convert_uint3_rte(uchar3);
uint3 __const_func convert_uint3_sat_rte(uchar3);
uint3 __const_func convert_uint3_rtz(uchar3);
uint3 __const_func convert_uint3_sat_rtz(uchar3);
uint3 __const_func convert_uint3_rtp(uchar3);
uint3 __const_func convert_uint3_sat_rtp(uchar3);
uint3 __const_func convert_uint3_rtn(uchar3);
uint3 __const_func convert_uint3_sat_rtn(uchar3);
uint3 __const_func convert_uint3(uchar3);
uint3 __const_func convert_uint3_sat(uchar3);
uint3 __const_func convert_uint3_rte(short3);
uint3 __const_func convert_uint3_sat_rte(short3);
uint3 __const_func convert_uint3_rtz(short3);
uint3 __const_func convert_uint3_sat_rtz(short3);
uint3 __const_func convert_uint3_rtp(short3);
uint3 __const_func convert_uint3_sat_rtp(short3);
uint3 __const_func convert_uint3_rtn(short3);
uint3 __const_func convert_uint3_sat_rtn(short3);
uint3 __const_func convert_uint3(short3);
uint3 __const_func convert_uint3_sat(short3);
uint3 __const_func convert_uint3_rte(ushort3);
uint3 __const_func convert_uint3_sat_rte(ushort3);
uint3 __const_func convert_uint3_rtz(ushort3);
uint3 __const_func convert_uint3_sat_rtz(ushort3);
uint3 __const_func convert_uint3_rtp(ushort3);
uint3 __const_func convert_uint3_sat_rtp(ushort3);
uint3 __const_func convert_uint3_rtn(ushort3);
uint3 __const_func convert_uint3_sat_rtn(ushort3);
uint3 __const_func convert_uint3(ushort3);
uint3 __const_func convert_uint3_sat(ushort3);
uint3 __const_func convert_uint3_rte(int3);
uint3 __const_func convert_uint3_sat_rte(int3);
uint3 __const_func convert_uint3_rtz(int3);
uint3 __const_func convert_uint3_sat_rtz(int3);
uint3 __const_func convert_uint3_rtp(int3);
uint3 __const_func convert_uint3_sat_rtp(int3);
uint3 __const_func convert_uint3_rtn(int3);
uint3 __const_func convert_uint3_sat_rtn(int3);
uint3 __const_func convert_uint3(int3);
uint3 __const_func convert_uint3_sat(int3);
uint3 __const_func convert_uint3_rte(uint3);
uint3 __const_func convert_uint3_sat_rte(uint3);
uint3 __const_func convert_uint3_rtz(uint3);
uint3 __const_func convert_uint3_sat_rtz(uint3);
uint3 __const_func convert_uint3_rtp(uint3);
uint3 __const_func convert_uint3_sat_rtp(uint3);
uint3 __const_func convert_uint3_rtn(uint3);
uint3 __const_func convert_uint3_sat_rtn(uint3);
uint3 __const_func convert_uint3(uint3);
uint3 __const_func convert_uint3_sat(uint3);
uint3 __const_func convert_uint3_rte(long3);
uint3 __const_func convert_uint3_sat_rte(long3);
uint3 __const_func convert_uint3_rtz(long3);
uint3 __const_func convert_uint3_sat_rtz(long3);
uint3 __const_func convert_uint3_rtp(long3);
uint3 __const_func convert_uint3_sat_rtp(long3);
uint3 __const_func convert_uint3_rtn(long3);
uint3 __const_func convert_uint3_sat_rtn(long3);
uint3 __const_func convert_uint3(long3);
uint3 __const_func convert_uint3_sat(long3);
uint3 __const_func convert_uint3_rte(ulong3);
uint3 __const_func convert_uint3_sat_rte(ulong3);
uint3 __const_func convert_uint3_rtz(ulong3);
uint3 __const_func convert_uint3_sat_rtz(ulong3);
uint3 __const_func convert_uint3_rtp(ulong3);
uint3 __const_func convert_uint3_sat_rtp(ulong3);
uint3 __const_func convert_uint3_rtn(ulong3);
uint3 __const_func convert_uint3_sat_rtn(ulong3);
uint3 __const_func convert_uint3(ulong3);
uint3 __const_func convert_uint3_sat(ulong3);
uint3 __const_func convert_uint3_rte(float3);
uint3 __const_func convert_uint3_sat_rte(float3);
uint3 __const_func convert_uint3_rtz(float3);
uint3 __const_func convert_uint3_sat_rtz(float3);
uint3 __const_func convert_uint3_rtp(float3);
uint3 __const_func convert_uint3_sat_rtp(float3);
uint3 __const_func convert_uint3_rtn(float3);
uint3 __const_func convert_uint3_sat_rtn(float3);
uint3 __const_func convert_uint3(float3);
uint3 __const_func convert_uint3_sat(float3);
long3 __const_func convert_long3_rte(char3);
long3 __const_func convert_long3_sat_rte(char3);
long3 __const_func convert_long3_rtz(char3);
long3 __const_func convert_long3_sat_rtz(char3);
long3 __const_func convert_long3_rtp(char3);
long3 __const_func convert_long3_sat_rtp(char3);
long3 __const_func convert_long3_rtn(char3);
long3 __const_func convert_long3_sat_rtn(char3);
long3 __const_func convert_long3(char3);
long3 __const_func convert_long3_sat(char3);
long3 __const_func convert_long3_rte(uchar3);
long3 __const_func convert_long3_sat_rte(uchar3);
long3 __const_func convert_long3_rtz(uchar3);
long3 __const_func convert_long3_sat_rtz(uchar3);
long3 __const_func convert_long3_rtp(uchar3);
long3 __const_func convert_long3_sat_rtp(uchar3);
long3 __const_func convert_long3_rtn(uchar3);
long3 __const_func convert_long3_sat_rtn(uchar3);
long3 __const_func convert_long3(uchar3);
long3 __const_func convert_long3_sat(uchar3);
long3 __const_func convert_long3_rte(short3);
long3 __const_func convert_long3_sat_rte(short3);
long3 __const_func convert_long3_rtz(short3);
long3 __const_func convert_long3_sat_rtz(short3);
long3 __const_func convert_long3_rtp(short3);
long3 __const_func convert_long3_sat_rtp(short3);
long3 __const_func convert_long3_rtn(short3);
long3 __const_func convert_long3_sat_rtn(short3);
long3 __const_func convert_long3(short3);
long3 __const_func convert_long3_sat(short3);
long3 __const_func convert_long3_rte(ushort3);
long3 __const_func convert_long3_sat_rte(ushort3);
long3 __const_func convert_long3_rtz(ushort3);
long3 __const_func convert_long3_sat_rtz(ushort3);
long3 __const_func convert_long3_rtp(ushort3);
long3 __const_func convert_long3_sat_rtp(ushort3);
long3 __const_func convert_long3_rtn(ushort3);
long3 __const_func convert_long3_sat_rtn(ushort3);
long3 __const_func convert_long3(ushort3);
long3 __const_func convert_long3_sat(ushort3);
long3 __const_func convert_long3_rte(int3);
long3 __const_func convert_long3_sat_rte(int3);
long3 __const_func convert_long3_rtz(int3);
long3 __const_func convert_long3_sat_rtz(int3);
long3 __const_func convert_long3_rtp(int3);
long3 __const_func convert_long3_sat_rtp(int3);
long3 __const_func convert_long3_rtn(int3);
long3 __const_func convert_long3_sat_rtn(int3);
long3 __const_func convert_long3(int3);
long3 __const_func convert_long3_sat(int3);
long3 __const_func convert_long3_rte(uint3);
long3 __const_func convert_long3_sat_rte(uint3);
long3 __const_func convert_long3_rtz(uint3);
long3 __const_func convert_long3_sat_rtz(uint3);
long3 __const_func convert_long3_rtp(uint3);
long3 __const_func convert_long3_sat_rtp(uint3);
long3 __const_func convert_long3_rtn(uint3);
long3 __const_func convert_long3_sat_rtn(uint3);
long3 __const_func convert_long3(uint3);
long3 __const_func convert_long3_sat(uint3);
long3 __const_func convert_long3_rte(long3);
long3 __const_func convert_long3_sat_rte(long3);
long3 __const_func convert_long3_rtz(long3);
long3 __const_func convert_long3_sat_rtz(long3);
long3 __const_func convert_long3_rtp(long3);
long3 __const_func convert_long3_sat_rtp(long3);
long3 __const_func convert_long3_rtn(long3);
long3 __const_func convert_long3_sat_rtn(long3);
long3 __const_func convert_long3(long3);
long3 __const_func convert_long3_sat(long3);
long3 __const_func convert_long3_rte(ulong3);
long3 __const_func convert_long3_sat_rte(ulong3);
long3 __const_func convert_long3_rtz(ulong3);
long3 __const_func convert_long3_sat_rtz(ulong3);
long3 __const_func convert_long3_rtp(ulong3);
long3 __const_func convert_long3_sat_rtp(ulong3);
long3 __const_func convert_long3_rtn(ulong3);
long3 __const_func convert_long3_sat_rtn(ulong3);
long3 __const_func convert_long3(ulong3);
long3 __const_func convert_long3_sat(ulong3);
long3 __const_func convert_long3_rte(float3);
long3 __const_func convert_long3_sat_rte(float3);
long3 __const_func convert_long3_rtz(float3);
long3 __const_func convert_long3_sat_rtz(float3);
long3 __const_func convert_long3_rtp(float3);
long3 __const_func convert_long3_sat_rtp(float3);
long3 __const_func convert_long3_rtn(float3);
long3 __const_func convert_long3_sat_rtn(float3);
long3 __const_func convert_long3(float3);
long3 __const_func convert_long3_sat(float3);
ulong3 __const_func convert_ulong3_rte(char3);
ulong3 __const_func convert_ulong3_sat_rte(char3);
ulong3 __const_func convert_ulong3_rtz(char3);
ulong3 __const_func convert_ulong3_sat_rtz(char3);
ulong3 __const_func convert_ulong3_rtp(char3);
ulong3 __const_func convert_ulong3_sat_rtp(char3);
ulong3 __const_func convert_ulong3_rtn(char3);
ulong3 __const_func convert_ulong3_sat_rtn(char3);
ulong3 __const_func convert_ulong3(char3);
ulong3 __const_func convert_ulong3_sat(char3);
ulong3 __const_func convert_ulong3_rte(uchar3);
ulong3 __const_func convert_ulong3_sat_rte(uchar3);
ulong3 __const_func convert_ulong3_rtz(uchar3);
ulong3 __const_func convert_ulong3_sat_rtz(uchar3);
ulong3 __const_func convert_ulong3_rtp(uchar3);
ulong3 __const_func convert_ulong3_sat_rtp(uchar3);
ulong3 __const_func convert_ulong3_rtn(uchar3);
ulong3 __const_func convert_ulong3_sat_rtn(uchar3);
ulong3 __const_func convert_ulong3(uchar3);
ulong3 __const_func convert_ulong3_sat(uchar3);
ulong3 __const_func convert_ulong3_rte(short3);
ulong3 __const_func convert_ulong3_sat_rte(short3);
ulong3 __const_func convert_ulong3_rtz(short3);
ulong3 __const_func convert_ulong3_sat_rtz(short3);
ulong3 __const_func convert_ulong3_rtp(short3);
ulong3 __const_func convert_ulong3_sat_rtp(short3);
ulong3 __const_func convert_ulong3_rtn(short3);
ulong3 __const_func convert_ulong3_sat_rtn(short3);
ulong3 __const_func convert_ulong3(short3);
ulong3 __const_func convert_ulong3_sat(short3);
ulong3 __const_func convert_ulong3_rte(ushort3);
ulong3 __const_func convert_ulong3_sat_rte(ushort3);
ulong3 __const_func convert_ulong3_rtz(ushort3);
ulong3 __const_func convert_ulong3_sat_rtz(ushort3);
ulong3 __const_func convert_ulong3_rtp(ushort3);
ulong3 __const_func convert_ulong3_sat_rtp(ushort3);
ulong3 __const_func convert_ulong3_rtn(ushort3);
ulong3 __const_func convert_ulong3_sat_rtn(ushort3);
ulong3 __const_func convert_ulong3(ushort3);
ulong3 __const_func convert_ulong3_sat(ushort3);
ulong3 __const_func convert_ulong3_rte(int3);
ulong3 __const_func convert_ulong3_sat_rte(int3);
ulong3 __const_func convert_ulong3_rtz(int3);
ulong3 __const_func convert_ulong3_sat_rtz(int3);
ulong3 __const_func convert_ulong3_rtp(int3);
ulong3 __const_func convert_ulong3_sat_rtp(int3);
ulong3 __const_func convert_ulong3_rtn(int3);
ulong3 __const_func convert_ulong3_sat_rtn(int3);
ulong3 __const_func convert_ulong3(int3);
ulong3 __const_func convert_ulong3_sat(int3);
ulong3 __const_func convert_ulong3_rte(uint3);
ulong3 __const_func convert_ulong3_sat_rte(uint3);
ulong3 __const_func convert_ulong3_rtz(uint3);
ulong3 __const_func convert_ulong3_sat_rtz(uint3);
ulong3 __const_func convert_ulong3_rtp(uint3);
ulong3 __const_func convert_ulong3_sat_rtp(uint3);
ulong3 __const_func convert_ulong3_rtn(uint3);
ulong3 __const_func convert_ulong3_sat_rtn(uint3);
ulong3 __const_func convert_ulong3(uint3);
ulong3 __const_func convert_ulong3_sat(uint3);
ulong3 __const_func convert_ulong3_rte(long3);
ulong3 __const_func convert_ulong3_sat_rte(long3);
ulong3 __const_func convert_ulong3_rtz(long3);
ulong3 __const_func convert_ulong3_sat_rtz(long3);
ulong3 __const_func convert_ulong3_rtp(long3);
ulong3 __const_func convert_ulong3_sat_rtp(long3);
ulong3 __const_func convert_ulong3_rtn(long3);
ulong3 __const_func convert_ulong3_sat_rtn(long3);
ulong3 __const_func convert_ulong3(long3);
ulong3 __const_func convert_ulong3_sat(long3);
ulong3 __const_func convert_ulong3_rte(ulong3);
ulong3 __const_func convert_ulong3_sat_rte(ulong3);
ulong3 __const_func convert_ulong3_rtz(ulong3);
ulong3 __const_func convert_ulong3_sat_rtz(ulong3);
ulong3 __const_func convert_ulong3_rtp(ulong3);
ulong3 __const_func convert_ulong3_sat_rtp(ulong3);
ulong3 __const_func convert_ulong3_rtn(ulong3);
ulong3 __const_func convert_ulong3_sat_rtn(ulong3);
ulong3 __const_func convert_ulong3(ulong3);
ulong3 __const_func convert_ulong3_sat(ulong3);
ulong3 __const_func convert_ulong3_rte(float3);
ulong3 __const_func convert_ulong3_sat_rte(float3);
ulong3 __const_func convert_ulong3_rtz(float3);
ulong3 __const_func convert_ulong3_sat_rtz(float3);
ulong3 __const_func convert_ulong3_rtp(float3);
ulong3 __const_func convert_ulong3_sat_rtp(float3);
ulong3 __const_func convert_ulong3_rtn(float3);
ulong3 __const_func convert_ulong3_sat_rtn(float3);
ulong3 __const_func convert_ulong3(float3);
ulong3 __const_func convert_ulong3_sat(float3);
float3 __const_func convert_float3_rte(char3);
float3 __const_func convert_float3_rtz(char3);
float3 __const_func convert_float3_rtp(char3);
float3 __const_func convert_float3_rtn(char3);
float3 __const_func convert_float3(char3);
float3 __const_func convert_float3_rte(uchar3);
float3 __const_func convert_float3_rtz(uchar3);
float3 __const_func convert_float3_rtp(uchar3);
float3 __const_func convert_float3_rtn(uchar3);
float3 __const_func convert_float3(uchar3);
float3 __const_func convert_float3_rte(short3);
float3 __const_func convert_float3_rtz(short3);
float3 __const_func convert_float3_rtp(short3);
float3 __const_func convert_float3_rtn(short3);
float3 __const_func convert_float3(short3);
float3 __const_func convert_float3_rte(ushort3);
float3 __const_func convert_float3_rtz(ushort3);
float3 __const_func convert_float3_rtp(ushort3);
float3 __const_func convert_float3_rtn(ushort3);
float3 __const_func convert_float3(ushort3);
float3 __const_func convert_float3_rte(int3);
float3 __const_func convert_float3_rtz(int3);
float3 __const_func convert_float3_rtp(int3);
float3 __const_func convert_float3_rtn(int3);
float3 __const_func convert_float3(int3);
float3 __const_func convert_float3_rte(uint3);
float3 __const_func convert_float3_rtz(uint3);
float3 __const_func convert_float3_rtp(uint3);
float3 __const_func convert_float3_rtn(uint3);
float3 __const_func convert_float3(uint3);
float3 __const_func convert_float3_rte(long3);
float3 __const_func convert_float3_rtz(long3);
float3 __const_func convert_float3_rtp(long3);
float3 __const_func convert_float3_rtn(long3);
float3 __const_func convert_float3(long3);
float3 __const_func convert_float3_rte(ulong3);
float3 __const_func convert_float3_rtz(ulong3);
float3 __const_func convert_float3_rtp(ulong3);
float3 __const_func convert_float3_rtn(ulong3);
float3 __const_func convert_float3(ulong3);
float3 __const_func convert_float3_rte(float3);
float3 __const_func convert_float3_rtz(float3);
float3 __const_func convert_float3_rtp(float3);
float3 __const_func convert_float3_rtn(float3);
float3 __const_func convert_float3(float3);
char4 __const_func convert_char4_rte(char4);
char4 __const_func convert_char4_sat_rte(char4);
char4 __const_func convert_char4_rtz(char4);
char4 __const_func convert_char4_sat_rtz(char4);
char4 __const_func convert_char4_rtp(char4);
char4 __const_func convert_char4_sat_rtp(char4);
char4 __const_func convert_char4_rtn(char4);
char4 __const_func convert_char4_sat_rtn(char4);
char4 __const_func convert_char4(char4);
char4 __const_func convert_char4_sat(char4);
char4 __const_func convert_char4_rte(uchar4);
char4 __const_func convert_char4_sat_rte(uchar4);
char4 __const_func convert_char4_rtz(uchar4);
char4 __const_func convert_char4_sat_rtz(uchar4);
char4 __const_func convert_char4_rtp(uchar4);
char4 __const_func convert_char4_sat_rtp(uchar4);
char4 __const_func convert_char4_rtn(uchar4);
char4 __const_func convert_char4_sat_rtn(uchar4);
char4 __const_func convert_char4(uchar4);
char4 __const_func convert_char4_sat(uchar4);
char4 __const_func convert_char4_rte(short4);
char4 __const_func convert_char4_sat_rte(short4);
char4 __const_func convert_char4_rtz(short4);
char4 __const_func convert_char4_sat_rtz(short4);
char4 __const_func convert_char4_rtp(short4);
char4 __const_func convert_char4_sat_rtp(short4);
char4 __const_func convert_char4_rtn(short4);
char4 __const_func convert_char4_sat_rtn(short4);
char4 __const_func convert_char4(short4);
char4 __const_func convert_char4_sat(short4);
char4 __const_func convert_char4_rte(ushort4);
char4 __const_func convert_char4_sat_rte(ushort4);
char4 __const_func convert_char4_rtz(ushort4);
char4 __const_func convert_char4_sat_rtz(ushort4);
char4 __const_func convert_char4_rtp(ushort4);
char4 __const_func convert_char4_sat_rtp(ushort4);
char4 __const_func convert_char4_rtn(ushort4);
char4 __const_func convert_char4_sat_rtn(ushort4);
char4 __const_func convert_char4(ushort4);
char4 __const_func convert_char4_sat(ushort4);
char4 __const_func convert_char4_rte(int4);
char4 __const_func convert_char4_sat_rte(int4);
char4 __const_func convert_char4_rtz(int4);
char4 __const_func convert_char4_sat_rtz(int4);
char4 __const_func convert_char4_rtp(int4);
char4 __const_func convert_char4_sat_rtp(int4);
char4 __const_func convert_char4_rtn(int4);
char4 __const_func convert_char4_sat_rtn(int4);
char4 __const_func convert_char4(int4);
char4 __const_func convert_char4_sat(int4);
char4 __const_func convert_char4_rte(uint4);
char4 __const_func convert_char4_sat_rte(uint4);
char4 __const_func convert_char4_rtz(uint4);
char4 __const_func convert_char4_sat_rtz(uint4);
char4 __const_func convert_char4_rtp(uint4);
char4 __const_func convert_char4_sat_rtp(uint4);
char4 __const_func convert_char4_rtn(uint4);
char4 __const_func convert_char4_sat_rtn(uint4);
char4 __const_func convert_char4(uint4);
char4 __const_func convert_char4_sat(uint4);
char4 __const_func convert_char4_rte(long4);
char4 __const_func convert_char4_sat_rte(long4);
char4 __const_func convert_char4_rtz(long4);
char4 __const_func convert_char4_sat_rtz(long4);
char4 __const_func convert_char4_rtp(long4);
char4 __const_func convert_char4_sat_rtp(long4);
char4 __const_func convert_char4_rtn(long4);
char4 __const_func convert_char4_sat_rtn(long4);
char4 __const_func convert_char4(long4);
char4 __const_func convert_char4_sat(long4);
char4 __const_func convert_char4_rte(ulong4);
char4 __const_func convert_char4_sat_rte(ulong4);
char4 __const_func convert_char4_rtz(ulong4);
char4 __const_func convert_char4_sat_rtz(ulong4);
char4 __const_func convert_char4_rtp(ulong4);
char4 __const_func convert_char4_sat_rtp(ulong4);
char4 __const_func convert_char4_rtn(ulong4);
char4 __const_func convert_char4_sat_rtn(ulong4);
char4 __const_func convert_char4(ulong4);
char4 __const_func convert_char4_sat(ulong4);
char4 __const_func convert_char4_rte(float4);
char4 __const_func convert_char4_sat_rte(float4);
char4 __const_func convert_char4_rtz(float4);
char4 __const_func convert_char4_sat_rtz(float4);
char4 __const_func convert_char4_rtp(float4);
char4 __const_func convert_char4_sat_rtp(float4);
char4 __const_func convert_char4_rtn(float4);
char4 __const_func convert_char4_sat_rtn(float4);
char4 __const_func convert_char4(float4);
char4 __const_func convert_char4_sat(float4);
uchar4 __const_func convert_uchar4_rte(char4);
uchar4 __const_func convert_uchar4_sat_rte(char4);
uchar4 __const_func convert_uchar4_rtz(char4);
uchar4 __const_func convert_uchar4_sat_rtz(char4);
uchar4 __const_func convert_uchar4_rtp(char4);
uchar4 __const_func convert_uchar4_sat_rtp(char4);
uchar4 __const_func convert_uchar4_rtn(char4);
uchar4 __const_func convert_uchar4_sat_rtn(char4);
uchar4 __const_func convert_uchar4(char4);
uchar4 __const_func convert_uchar4_sat(char4);
uchar4 __const_func convert_uchar4_rte(uchar4);
uchar4 __const_func convert_uchar4_sat_rte(uchar4);
uchar4 __const_func convert_uchar4_rtz(uchar4);
uchar4 __const_func convert_uchar4_sat_rtz(uchar4);
uchar4 __const_func convert_uchar4_rtp(uchar4);
uchar4 __const_func convert_uchar4_sat_rtp(uchar4);
uchar4 __const_func convert_uchar4_rtn(uchar4);
uchar4 __const_func convert_uchar4_sat_rtn(uchar4);
uchar4 __const_func convert_uchar4(uchar4);
uchar4 __const_func convert_uchar4_sat(uchar4);
uchar4 __const_func convert_uchar4_rte(short4);
uchar4 __const_func convert_uchar4_sat_rte(short4);
uchar4 __const_func convert_uchar4_rtz(short4);
uchar4 __const_func convert_uchar4_sat_rtz(short4);
uchar4 __const_func convert_uchar4_rtp(short4);
uchar4 __const_func convert_uchar4_sat_rtp(short4);
uchar4 __const_func convert_uchar4_rtn(short4);
uchar4 __const_func convert_uchar4_sat_rtn(short4);
uchar4 __const_func convert_uchar4(short4);
uchar4 __const_func convert_uchar4_sat(short4);
uchar4 __const_func convert_uchar4_rte(ushort4);
uchar4 __const_func convert_uchar4_sat_rte(ushort4);
uchar4 __const_func convert_uchar4_rtz(ushort4);
uchar4 __const_func convert_uchar4_sat_rtz(ushort4);
uchar4 __const_func convert_uchar4_rtp(ushort4);
uchar4 __const_func convert_uchar4_sat_rtp(ushort4);
uchar4 __const_func convert_uchar4_rtn(ushort4);
uchar4 __const_func convert_uchar4_sat_rtn(ushort4);
uchar4 __const_func convert_uchar4(ushort4);
uchar4 __const_func convert_uchar4_sat(ushort4);
uchar4 __const_func convert_uchar4_rte(int4);
uchar4 __const_func convert_uchar4_sat_rte(int4);
uchar4 __const_func convert_uchar4_rtz(int4);
uchar4 __const_func convert_uchar4_sat_rtz(int4);
uchar4 __const_func convert_uchar4_rtp(int4);
uchar4 __const_func convert_uchar4_sat_rtp(int4);
uchar4 __const_func convert_uchar4_rtn(int4);
uchar4 __const_func convert_uchar4_sat_rtn(int4);
uchar4 __const_func convert_uchar4(int4);
uchar4 __const_func convert_uchar4_sat(int4);
uchar4 __const_func convert_uchar4_rte(uint4);
uchar4 __const_func convert_uchar4_sat_rte(uint4);
uchar4 __const_func convert_uchar4_rtz(uint4);
uchar4 __const_func convert_uchar4_sat_rtz(uint4);
uchar4 __const_func convert_uchar4_rtp(uint4);
uchar4 __const_func convert_uchar4_sat_rtp(uint4);
uchar4 __const_func convert_uchar4_rtn(uint4);
uchar4 __const_func convert_uchar4_sat_rtn(uint4);
uchar4 __const_func convert_uchar4(uint4);
uchar4 __const_func convert_uchar4_sat(uint4);
uchar4 __const_func convert_uchar4_rte(long4);
uchar4 __const_func convert_uchar4_sat_rte(long4);
uchar4 __const_func convert_uchar4_rtz(long4);
uchar4 __const_func convert_uchar4_sat_rtz(long4);
uchar4 __const_func convert_uchar4_rtp(long4);
uchar4 __const_func convert_uchar4_sat_rtp(long4);
uchar4 __const_func convert_uchar4_rtn(long4);
uchar4 __const_func convert_uchar4_sat_rtn(long4);
uchar4 __const_func convert_uchar4(long4);
uchar4 __const_func convert_uchar4_sat(long4);
uchar4 __const_func convert_uchar4_rte(ulong4);
uchar4 __const_func convert_uchar4_sat_rte(ulong4);
uchar4 __const_func convert_uchar4_rtz(ulong4);
uchar4 __const_func convert_uchar4_sat_rtz(ulong4);
uchar4 __const_func convert_uchar4_rtp(ulong4);
uchar4 __const_func convert_uchar4_sat_rtp(ulong4);
uchar4 __const_func convert_uchar4_rtn(ulong4);
uchar4 __const_func convert_uchar4_sat_rtn(ulong4);
uchar4 __const_func convert_uchar4(ulong4);
uchar4 __const_func convert_uchar4_sat(ulong4);
uchar4 __const_func convert_uchar4_rte(float4);
uchar4 __const_func convert_uchar4_sat_rte(float4);
uchar4 __const_func convert_uchar4_rtz(float4);
uchar4 __const_func convert_uchar4_sat_rtz(float4);
uchar4 __const_func convert_uchar4_rtp(float4);
uchar4 __const_func convert_uchar4_sat_rtp(float4);
uchar4 __const_func convert_uchar4_rtn(float4);
uchar4 __const_func convert_uchar4_sat_rtn(float4);
uchar4 __const_func convert_uchar4(float4);
uchar4 __const_func convert_uchar4_sat(float4);
short4 __const_func convert_short4_rte(char4);
short4 __const_func convert_short4_sat_rte(char4);
short4 __const_func convert_short4_rtz(char4);
short4 __const_func convert_short4_sat_rtz(char4);
short4 __const_func convert_short4_rtp(char4);
short4 __const_func convert_short4_sat_rtp(char4);
short4 __const_func convert_short4_rtn(char4);
short4 __const_func convert_short4_sat_rtn(char4);
short4 __const_func convert_short4(char4);
short4 __const_func convert_short4_sat(char4);
short4 __const_func convert_short4_rte(uchar4);
short4 __const_func convert_short4_sat_rte(uchar4);
short4 __const_func convert_short4_rtz(uchar4);
short4 __const_func convert_short4_sat_rtz(uchar4);
short4 __const_func convert_short4_rtp(uchar4);
short4 __const_func convert_short4_sat_rtp(uchar4);
short4 __const_func convert_short4_rtn(uchar4);
short4 __const_func convert_short4_sat_rtn(uchar4);
short4 __const_func convert_short4(uchar4);
short4 __const_func convert_short4_sat(uchar4);
short4 __const_func convert_short4_rte(short4);
short4 __const_func convert_short4_sat_rte(short4);
short4 __const_func convert_short4_rtz(short4);
short4 __const_func convert_short4_sat_rtz(short4);
short4 __const_func convert_short4_rtp(short4);
short4 __const_func convert_short4_sat_rtp(short4);
short4 __const_func convert_short4_rtn(short4);
short4 __const_func convert_short4_sat_rtn(short4);
short4 __const_func convert_short4(short4);
short4 __const_func convert_short4_sat(short4);
short4 __const_func convert_short4_rte(ushort4);
short4 __const_func convert_short4_sat_rte(ushort4);
short4 __const_func convert_short4_rtz(ushort4);
short4 __const_func convert_short4_sat_rtz(ushort4);
short4 __const_func convert_short4_rtp(ushort4);
short4 __const_func convert_short4_sat_rtp(ushort4);
short4 __const_func convert_short4_rtn(ushort4);
short4 __const_func convert_short4_sat_rtn(ushort4);
short4 __const_func convert_short4(ushort4);
short4 __const_func convert_short4_sat(ushort4);
short4 __const_func convert_short4_rte(int4);
short4 __const_func convert_short4_sat_rte(int4);
short4 __const_func convert_short4_rtz(int4);
short4 __const_func convert_short4_sat_rtz(int4);
short4 __const_func convert_short4_rtp(int4);
short4 __const_func convert_short4_sat_rtp(int4);
short4 __const_func convert_short4_rtn(int4);
short4 __const_func convert_short4_sat_rtn(int4);
short4 __const_func convert_short4(int4);
short4 __const_func convert_short4_sat(int4);
short4 __const_func convert_short4_rte(uint4);
short4 __const_func convert_short4_sat_rte(uint4);
short4 __const_func convert_short4_rtz(uint4);
short4 __const_func convert_short4_sat_rtz(uint4);
short4 __const_func convert_short4_rtp(uint4);
short4 __const_func convert_short4_sat_rtp(uint4);
short4 __const_func convert_short4_rtn(uint4);
short4 __const_func convert_short4_sat_rtn(uint4);
short4 __const_func convert_short4(uint4);
short4 __const_func convert_short4_sat(uint4);
short4 __const_func convert_short4_rte(long4);
short4 __const_func convert_short4_sat_rte(long4);
short4 __const_func convert_short4_rtz(long4);
short4 __const_func convert_short4_sat_rtz(long4);
short4 __const_func convert_short4_rtp(long4);
short4 __const_func convert_short4_sat_rtp(long4);
short4 __const_func convert_short4_rtn(long4);
short4 __const_func convert_short4_sat_rtn(long4);
short4 __const_func convert_short4(long4);
short4 __const_func convert_short4_sat(long4);
short4 __const_func convert_short4_rte(ulong4);
short4 __const_func convert_short4_sat_rte(ulong4);
short4 __const_func convert_short4_rtz(ulong4);
short4 __const_func convert_short4_sat_rtz(ulong4);
short4 __const_func convert_short4_rtp(ulong4);
short4 __const_func convert_short4_sat_rtp(ulong4);
short4 __const_func convert_short4_rtn(ulong4);
short4 __const_func convert_short4_sat_rtn(ulong4);
short4 __const_func convert_short4(ulong4);
short4 __const_func convert_short4_sat(ulong4);
short4 __const_func convert_short4_rte(float4);
short4 __const_func convert_short4_sat_rte(float4);
short4 __const_func convert_short4_rtz(float4);
short4 __const_func convert_short4_sat_rtz(float4);
short4 __const_func convert_short4_rtp(float4);
short4 __const_func convert_short4_sat_rtp(float4);
short4 __const_func convert_short4_rtn(float4);
short4 __const_func convert_short4_sat_rtn(float4);
short4 __const_func convert_short4(float4);
short4 __const_func convert_short4_sat(float4);
ushort4 __const_func convert_ushort4_rte(char4);
ushort4 __const_func convert_ushort4_sat_rte(char4);
ushort4 __const_func convert_ushort4_rtz(char4);
ushort4 __const_func convert_ushort4_sat_rtz(char4);
ushort4 __const_func convert_ushort4_rtp(char4);
ushort4 __const_func convert_ushort4_sat_rtp(char4);
ushort4 __const_func convert_ushort4_rtn(char4);
ushort4 __const_func convert_ushort4_sat_rtn(char4);
ushort4 __const_func convert_ushort4(char4);
ushort4 __const_func convert_ushort4_sat(char4);
ushort4 __const_func convert_ushort4_rte(uchar4);
ushort4 __const_func convert_ushort4_sat_rte(uchar4);
ushort4 __const_func convert_ushort4_rtz(uchar4);
ushort4 __const_func convert_ushort4_sat_rtz(uchar4);
ushort4 __const_func convert_ushort4_rtp(uchar4);
ushort4 __const_func convert_ushort4_sat_rtp(uchar4);
ushort4 __const_func convert_ushort4_rtn(uchar4);
ushort4 __const_func convert_ushort4_sat_rtn(uchar4);
ushort4 __const_func convert_ushort4(uchar4);
ushort4 __const_func convert_ushort4_sat(uchar4);
ushort4 __const_func convert_ushort4_rte(short4);
ushort4 __const_func convert_ushort4_sat_rte(short4);
ushort4 __const_func convert_ushort4_rtz(short4);
ushort4 __const_func convert_ushort4_sat_rtz(short4);
ushort4 __const_func convert_ushort4_rtp(short4);
ushort4 __const_func convert_ushort4_sat_rtp(short4);
ushort4 __const_func convert_ushort4_rtn(short4);
ushort4 __const_func convert_ushort4_sat_rtn(short4);
ushort4 __const_func convert_ushort4(short4);
ushort4 __const_func convert_ushort4_sat(short4);
ushort4 __const_func convert_ushort4_rte(ushort4);
ushort4 __const_func convert_ushort4_sat_rte(ushort4);
ushort4 __const_func convert_ushort4_rtz(ushort4);
ushort4 __const_func convert_ushort4_sat_rtz(ushort4);
ushort4 __const_func convert_ushort4_rtp(ushort4);
ushort4 __const_func convert_ushort4_sat_rtp(ushort4);
ushort4 __const_func convert_ushort4_rtn(ushort4);
ushort4 __const_func convert_ushort4_sat_rtn(ushort4);
ushort4 __const_func convert_ushort4(ushort4);
ushort4 __const_func convert_ushort4_sat(ushort4);
ushort4 __const_func convert_ushort4_rte(int4);
ushort4 __const_func convert_ushort4_sat_rte(int4);
ushort4 __const_func convert_ushort4_rtz(int4);
ushort4 __const_func convert_ushort4_sat_rtz(int4);
ushort4 __const_func convert_ushort4_rtp(int4);
ushort4 __const_func convert_ushort4_sat_rtp(int4);
ushort4 __const_func convert_ushort4_rtn(int4);
ushort4 __const_func convert_ushort4_sat_rtn(int4);
ushort4 __const_func convert_ushort4(int4);
ushort4 __const_func convert_ushort4_sat(int4);
ushort4 __const_func convert_ushort4_rte(uint4);
ushort4 __const_func convert_ushort4_sat_rte(uint4);
ushort4 __const_func convert_ushort4_rtz(uint4);
ushort4 __const_func convert_ushort4_sat_rtz(uint4);
ushort4 __const_func convert_ushort4_rtp(uint4);
ushort4 __const_func convert_ushort4_sat_rtp(uint4);
ushort4 __const_func convert_ushort4_rtn(uint4);
ushort4 __const_func convert_ushort4_sat_rtn(uint4);
ushort4 __const_func convert_ushort4(uint4);
ushort4 __const_func convert_ushort4_sat(uint4);
ushort4 __const_func convert_ushort4_rte(long4);
ushort4 __const_func convert_ushort4_sat_rte(long4);
ushort4 __const_func convert_ushort4_rtz(long4);
ushort4 __const_func convert_ushort4_sat_rtz(long4);
ushort4 __const_func convert_ushort4_rtp(long4);
ushort4 __const_func convert_ushort4_sat_rtp(long4);
ushort4 __const_func convert_ushort4_rtn(long4);
ushort4 __const_func convert_ushort4_sat_rtn(long4);
ushort4 __const_func convert_ushort4(long4);
ushort4 __const_func convert_ushort4_sat(long4);
ushort4 __const_func convert_ushort4_rte(ulong4);
ushort4 __const_func convert_ushort4_sat_rte(ulong4);
ushort4 __const_func convert_ushort4_rtz(ulong4);
ushort4 __const_func convert_ushort4_sat_rtz(ulong4);
ushort4 __const_func convert_ushort4_rtp(ulong4);
ushort4 __const_func convert_ushort4_sat_rtp(ulong4);
ushort4 __const_func convert_ushort4_rtn(ulong4);
ushort4 __const_func convert_ushort4_sat_rtn(ulong4);
ushort4 __const_func convert_ushort4(ulong4);
ushort4 __const_func convert_ushort4_sat(ulong4);
ushort4 __const_func convert_ushort4_rte(float4);
ushort4 __const_func convert_ushort4_sat_rte(float4);
ushort4 __const_func convert_ushort4_rtz(float4);
ushort4 __const_func convert_ushort4_sat_rtz(float4);
ushort4 __const_func convert_ushort4_rtp(float4);
ushort4 __const_func convert_ushort4_sat_rtp(float4);
ushort4 __const_func convert_ushort4_rtn(float4);
ushort4 __const_func convert_ushort4_sat_rtn(float4);
ushort4 __const_func convert_ushort4(float4);
ushort4 __const_func convert_ushort4_sat(float4);
int4 __const_func convert_int4_rte(char4);
int4 __const_func convert_int4_sat_rte(char4);
int4 __const_func convert_int4_rtz(char4);
int4 __const_func convert_int4_sat_rtz(char4);
int4 __const_func convert_int4_rtp(char4);
int4 __const_func convert_int4_sat_rtp(char4);
int4 __const_func convert_int4_rtn(char4);
int4 __const_func convert_int4_sat_rtn(char4);
int4 __const_func convert_int4(char4);
int4 __const_func convert_int4_sat(char4);
int4 __const_func convert_int4_rte(uchar4);
int4 __const_func convert_int4_sat_rte(uchar4);
int4 __const_func convert_int4_rtz(uchar4);
int4 __const_func convert_int4_sat_rtz(uchar4);
int4 __const_func convert_int4_rtp(uchar4);
int4 __const_func convert_int4_sat_rtp(uchar4);
int4 __const_func convert_int4_rtn(uchar4);
int4 __const_func convert_int4_sat_rtn(uchar4);
int4 __const_func convert_int4(uchar4);
int4 __const_func convert_int4_sat(uchar4);
int4 __const_func convert_int4_rte(short4);
int4 __const_func convert_int4_sat_rte(short4);
int4 __const_func convert_int4_rtz(short4);
int4 __const_func convert_int4_sat_rtz(short4);
int4 __const_func convert_int4_rtp(short4);
int4 __const_func convert_int4_sat_rtp(short4);
int4 __const_func convert_int4_rtn(short4);
int4 __const_func convert_int4_sat_rtn(short4);
int4 __const_func convert_int4(short4);
int4 __const_func convert_int4_sat(short4);
int4 __const_func convert_int4_rte(ushort4);
int4 __const_func convert_int4_sat_rte(ushort4);
int4 __const_func convert_int4_rtz(ushort4);
int4 __const_func convert_int4_sat_rtz(ushort4);
int4 __const_func convert_int4_rtp(ushort4);
int4 __const_func convert_int4_sat_rtp(ushort4);
int4 __const_func convert_int4_rtn(ushort4);
int4 __const_func convert_int4_sat_rtn(ushort4);
int4 __const_func convert_int4(ushort4);
int4 __const_func convert_int4_sat(ushort4);
int4 __const_func convert_int4_rte(int4);
int4 __const_func convert_int4_sat_rte(int4);
int4 __const_func convert_int4_rtz(int4);
int4 __const_func convert_int4_sat_rtz(int4);
int4 __const_func convert_int4_rtp(int4);
int4 __const_func convert_int4_sat_rtp(int4);
int4 __const_func convert_int4_rtn(int4);
int4 __const_func convert_int4_sat_rtn(int4);
int4 __const_func convert_int4(int4);
int4 __const_func convert_int4_sat(int4);
int4 __const_func convert_int4_rte(uint4);
int4 __const_func convert_int4_sat_rte(uint4);
int4 __const_func convert_int4_rtz(uint4);
int4 __const_func convert_int4_sat_rtz(uint4);
int4 __const_func convert_int4_rtp(uint4);
int4 __const_func convert_int4_sat_rtp(uint4);
int4 __const_func convert_int4_rtn(uint4);
int4 __const_func convert_int4_sat_rtn(uint4);
int4 __const_func convert_int4(uint4);
int4 __const_func convert_int4_sat(uint4);
int4 __const_func convert_int4_rte(long4);
int4 __const_func convert_int4_sat_rte(long4);
int4 __const_func convert_int4_rtz(long4);
int4 __const_func convert_int4_sat_rtz(long4);
int4 __const_func convert_int4_rtp(long4);
int4 __const_func convert_int4_sat_rtp(long4);
int4 __const_func convert_int4_rtn(long4);
int4 __const_func convert_int4_sat_rtn(long4);
int4 __const_func convert_int4(long4);
int4 __const_func convert_int4_sat(long4);
int4 __const_func convert_int4_rte(ulong4);
int4 __const_func convert_int4_sat_rte(ulong4);
int4 __const_func convert_int4_rtz(ulong4);
int4 __const_func convert_int4_sat_rtz(ulong4);
int4 __const_func convert_int4_rtp(ulong4);
int4 __const_func convert_int4_sat_rtp(ulong4);
int4 __const_func convert_int4_rtn(ulong4);
int4 __const_func convert_int4_sat_rtn(ulong4);
int4 __const_func convert_int4(ulong4);
int4 __const_func convert_int4_sat(ulong4);
int4 __const_func convert_int4_rte(float4);
int4 __const_func convert_int4_sat_rte(float4);
int4 __const_func convert_int4_rtz(float4);
int4 __const_func convert_int4_sat_rtz(float4);
int4 __const_func convert_int4_rtp(float4);
int4 __const_func convert_int4_sat_rtp(float4);
int4 __const_func convert_int4_rtn(float4);
int4 __const_func convert_int4_sat_rtn(float4);
int4 __const_func convert_int4(float4);
int4 __const_func convert_int4_sat(float4);
uint4 __const_func convert_uint4_rte(char4);
uint4 __const_func convert_uint4_sat_rte(char4);
uint4 __const_func convert_uint4_rtz(char4);
uint4 __const_func convert_uint4_sat_rtz(char4);
uint4 __const_func convert_uint4_rtp(char4);
uint4 __const_func convert_uint4_sat_rtp(char4);
uint4 __const_func convert_uint4_rtn(char4);
uint4 __const_func convert_uint4_sat_rtn(char4);
uint4 __const_func convert_uint4(char4);
uint4 __const_func convert_uint4_sat(char4);
uint4 __const_func convert_uint4_rte(uchar4);
uint4 __const_func convert_uint4_sat_rte(uchar4);
uint4 __const_func convert_uint4_rtz(uchar4);
uint4 __const_func convert_uint4_sat_rtz(uchar4);
uint4 __const_func convert_uint4_rtp(uchar4);
uint4 __const_func convert_uint4_sat_rtp(uchar4);
uint4 __const_func convert_uint4_rtn(uchar4);
uint4 __const_func convert_uint4_sat_rtn(uchar4);
uint4 __const_func convert_uint4(uchar4);
uint4 __const_func convert_uint4_sat(uchar4);
uint4 __const_func convert_uint4_rte(short4);
uint4 __const_func convert_uint4_sat_rte(short4);
uint4 __const_func convert_uint4_rtz(short4);
uint4 __const_func convert_uint4_sat_rtz(short4);
uint4 __const_func convert_uint4_rtp(short4);
uint4 __const_func convert_uint4_sat_rtp(short4);
uint4 __const_func convert_uint4_rtn(short4);
uint4 __const_func convert_uint4_sat_rtn(short4);
uint4 __const_func convert_uint4(short4);
uint4 __const_func convert_uint4_sat(short4);
uint4 __const_func convert_uint4_rte(ushort4);
uint4 __const_func convert_uint4_sat_rte(ushort4);
uint4 __const_func convert_uint4_rtz(ushort4);
uint4 __const_func convert_uint4_sat_rtz(ushort4);
uint4 __const_func convert_uint4_rtp(ushort4);
uint4 __const_func convert_uint4_sat_rtp(ushort4);
uint4 __const_func convert_uint4_rtn(ushort4);
uint4 __const_func convert_uint4_sat_rtn(ushort4);
uint4 __const_func convert_uint4(ushort4);
uint4 __const_func convert_uint4_sat(ushort4);
uint4 __const_func convert_uint4_rte(int4);
uint4 __const_func convert_uint4_sat_rte(int4);
uint4 __const_func convert_uint4_rtz(int4);
uint4 __const_func convert_uint4_sat_rtz(int4);
uint4 __const_func convert_uint4_rtp(int4);
uint4 __const_func convert_uint4_sat_rtp(int4);
uint4 __const_func convert_uint4_rtn(int4);
uint4 __const_func convert_uint4_sat_rtn(int4);
uint4 __const_func convert_uint4(int4);
uint4 __const_func convert_uint4_sat(int4);
uint4 __const_func convert_uint4_rte(uint4);
uint4 __const_func convert_uint4_sat_rte(uint4);
uint4 __const_func convert_uint4_rtz(uint4);
uint4 __const_func convert_uint4_sat_rtz(uint4);
uint4 __const_func convert_uint4_rtp(uint4);
uint4 __const_func convert_uint4_sat_rtp(uint4);
uint4 __const_func convert_uint4_rtn(uint4);
uint4 __const_func convert_uint4_sat_rtn(uint4);
uint4 __const_func convert_uint4(uint4);
uint4 __const_func convert_uint4_sat(uint4);
uint4 __const_func convert_uint4_rte(long4);
uint4 __const_func convert_uint4_sat_rte(long4);
uint4 __const_func convert_uint4_rtz(long4);
uint4 __const_func convert_uint4_sat_rtz(long4);
uint4 __const_func convert_uint4_rtp(long4);
uint4 __const_func convert_uint4_sat_rtp(long4);
uint4 __const_func convert_uint4_rtn(long4);
uint4 __const_func convert_uint4_sat_rtn(long4);
uint4 __const_func convert_uint4(long4);
uint4 __const_func convert_uint4_sat(long4);
uint4 __const_func convert_uint4_rte(ulong4);
uint4 __const_func convert_uint4_sat_rte(ulong4);
uint4 __const_func convert_uint4_rtz(ulong4);
uint4 __const_func convert_uint4_sat_rtz(ulong4);
uint4 __const_func convert_uint4_rtp(ulong4);
uint4 __const_func convert_uint4_sat_rtp(ulong4);
uint4 __const_func convert_uint4_rtn(ulong4);
uint4 __const_func convert_uint4_sat_rtn(ulong4);
uint4 __const_func convert_uint4(ulong4);
uint4 __const_func convert_uint4_sat(ulong4);
uint4 __const_func convert_uint4_rte(float4);
uint4 __const_func convert_uint4_sat_rte(float4);
uint4 __const_func convert_uint4_rtz(float4);
uint4 __const_func convert_uint4_sat_rtz(float4);
uint4 __const_func convert_uint4_rtp(float4);
uint4 __const_func convert_uint4_sat_rtp(float4);
uint4 __const_func convert_uint4_rtn(float4);
uint4 __const_func convert_uint4_sat_rtn(float4);
uint4 __const_func convert_uint4(float4);
uint4 __const_func convert_uint4_sat(float4);
long4 __const_func convert_long4_rte(char4);
long4 __const_func convert_long4_sat_rte(char4);
long4 __const_func convert_long4_rtz(char4);
long4 __const_func convert_long4_sat_rtz(char4);
long4 __const_func convert_long4_rtp(char4);
long4 __const_func convert_long4_sat_rtp(char4);
long4 __const_func convert_long4_rtn(char4);
long4 __const_func convert_long4_sat_rtn(char4);
long4 __const_func convert_long4(char4);
long4 __const_func convert_long4_sat(char4);
long4 __const_func convert_long4_rte(uchar4);
long4 __const_func convert_long4_sat_rte(uchar4);
long4 __const_func convert_long4_rtz(uchar4);
long4 __const_func convert_long4_sat_rtz(uchar4);
long4 __const_func convert_long4_rtp(uchar4);
long4 __const_func convert_long4_sat_rtp(uchar4);
long4 __const_func convert_long4_rtn(uchar4);
long4 __const_func convert_long4_sat_rtn(uchar4);
long4 __const_func convert_long4(uchar4);
long4 __const_func convert_long4_sat(uchar4);
long4 __const_func convert_long4_rte(short4);
long4 __const_func convert_long4_sat_rte(short4);
long4 __const_func convert_long4_rtz(short4);
long4 __const_func convert_long4_sat_rtz(short4);
long4 __const_func convert_long4_rtp(short4);
long4 __const_func convert_long4_sat_rtp(short4);
long4 __const_func convert_long4_rtn(short4);
long4 __const_func convert_long4_sat_rtn(short4);
long4 __const_func convert_long4(short4);
long4 __const_func convert_long4_sat(short4);
long4 __const_func convert_long4_rte(ushort4);
long4 __const_func convert_long4_sat_rte(ushort4);
long4 __const_func convert_long4_rtz(ushort4);
long4 __const_func convert_long4_sat_rtz(ushort4);
long4 __const_func convert_long4_rtp(ushort4);
long4 __const_func convert_long4_sat_rtp(ushort4);
long4 __const_func convert_long4_rtn(ushort4);
long4 __const_func convert_long4_sat_rtn(ushort4);
long4 __const_func convert_long4(ushort4);
long4 __const_func convert_long4_sat(ushort4);
long4 __const_func convert_long4_rte(int4);
long4 __const_func convert_long4_sat_rte(int4);
long4 __const_func convert_long4_rtz(int4);
long4 __const_func convert_long4_sat_rtz(int4);
long4 __const_func convert_long4_rtp(int4);
long4 __const_func convert_long4_sat_rtp(int4);
long4 __const_func convert_long4_rtn(int4);
long4 __const_func convert_long4_sat_rtn(int4);
long4 __const_func convert_long4(int4);
long4 __const_func convert_long4_sat(int4);
long4 __const_func convert_long4_rte(uint4);
long4 __const_func convert_long4_sat_rte(uint4);
long4 __const_func convert_long4_rtz(uint4);
long4 __const_func convert_long4_sat_rtz(uint4);
long4 __const_func convert_long4_rtp(uint4);
long4 __const_func convert_long4_sat_rtp(uint4);
long4 __const_func convert_long4_rtn(uint4);
long4 __const_func convert_long4_sat_rtn(uint4);
long4 __const_func convert_long4(uint4);
long4 __const_func convert_long4_sat(uint4);
long4 __const_func convert_long4_rte(long4);
long4 __const_func convert_long4_sat_rte(long4);
long4 __const_func convert_long4_rtz(long4);
long4 __const_func convert_long4_sat_rtz(long4);
long4 __const_func convert_long4_rtp(long4);
long4 __const_func convert_long4_sat_rtp(long4);
long4 __const_func convert_long4_rtn(long4);
long4 __const_func convert_long4_sat_rtn(long4);
long4 __const_func convert_long4(long4);
long4 __const_func convert_long4_sat(long4);
long4 __const_func convert_long4_rte(ulong4);
long4 __const_func convert_long4_sat_rte(ulong4);
long4 __const_func convert_long4_rtz(ulong4);
long4 __const_func convert_long4_sat_rtz(ulong4);
long4 __const_func convert_long4_rtp(ulong4);
long4 __const_func convert_long4_sat_rtp(ulong4);
long4 __const_func convert_long4_rtn(ulong4);
long4 __const_func convert_long4_sat_rtn(ulong4);
long4 __const_func convert_long4(ulong4);
long4 __const_func convert_long4_sat(ulong4);
long4 __const_func convert_long4_rte(float4);
long4 __const_func convert_long4_sat_rte(float4);
long4 __const_func convert_long4_rtz(float4);
long4 __const_func convert_long4_sat_rtz(float4);
long4 __const_func convert_long4_rtp(float4);
long4 __const_func convert_long4_sat_rtp(float4);
long4 __const_func convert_long4_rtn(float4);
long4 __const_func convert_long4_sat_rtn(float4);
long4 __const_func convert_long4(float4);
long4 __const_func convert_long4_sat(float4);
ulong4 __const_func convert_ulong4_rte(char4);
ulong4 __const_func convert_ulong4_sat_rte(char4);
ulong4 __const_func convert_ulong4_rtz(char4);
ulong4 __const_func convert_ulong4_sat_rtz(char4);
ulong4 __const_func convert_ulong4_rtp(char4);
ulong4 __const_func convert_ulong4_sat_rtp(char4);
ulong4 __const_func convert_ulong4_rtn(char4);
ulong4 __const_func convert_ulong4_sat_rtn(char4);
ulong4 __const_func convert_ulong4(char4);
ulong4 __const_func convert_ulong4_sat(char4);
ulong4 __const_func convert_ulong4_rte(uchar4);
ulong4 __const_func convert_ulong4_sat_rte(uchar4);
ulong4 __const_func convert_ulong4_rtz(uchar4);
ulong4 __const_func convert_ulong4_sat_rtz(uchar4);
ulong4 __const_func convert_ulong4_rtp(uchar4);
ulong4 __const_func convert_ulong4_sat_rtp(uchar4);
ulong4 __const_func convert_ulong4_rtn(uchar4);
ulong4 __const_func convert_ulong4_sat_rtn(uchar4);
ulong4 __const_func convert_ulong4(uchar4);
ulong4 __const_func convert_ulong4_sat(uchar4);
ulong4 __const_func convert_ulong4_rte(short4);
ulong4 __const_func convert_ulong4_sat_rte(short4);
ulong4 __const_func convert_ulong4_rtz(short4);
ulong4 __const_func convert_ulong4_sat_rtz(short4);
ulong4 __const_func convert_ulong4_rtp(short4);
ulong4 __const_func convert_ulong4_sat_rtp(short4);
ulong4 __const_func convert_ulong4_rtn(short4);
ulong4 __const_func convert_ulong4_sat_rtn(short4);
ulong4 __const_func convert_ulong4(short4);
ulong4 __const_func convert_ulong4_sat(short4);
ulong4 __const_func convert_ulong4_rte(ushort4);
ulong4 __const_func convert_ulong4_sat_rte(ushort4);
ulong4 __const_func convert_ulong4_rtz(ushort4);
ulong4 __const_func convert_ulong4_sat_rtz(ushort4);
ulong4 __const_func convert_ulong4_rtp(ushort4);
ulong4 __const_func convert_ulong4_sat_rtp(ushort4);
ulong4 __const_func convert_ulong4_rtn(ushort4);
ulong4 __const_func convert_ulong4_sat_rtn(ushort4);
ulong4 __const_func convert_ulong4(ushort4);
ulong4 __const_func convert_ulong4_sat(ushort4);
ulong4 __const_func convert_ulong4_rte(int4);
ulong4 __const_func convert_ulong4_sat_rte(int4);
ulong4 __const_func convert_ulong4_rtz(int4);
ulong4 __const_func convert_ulong4_sat_rtz(int4);
ulong4 __const_func convert_ulong4_rtp(int4);
ulong4 __const_func convert_ulong4_sat_rtp(int4);
ulong4 __const_func convert_ulong4_rtn(int4);
ulong4 __const_func convert_ulong4_sat_rtn(int4);
ulong4 __const_func convert_ulong4(int4);
ulong4 __const_func convert_ulong4_sat(int4);
ulong4 __const_func convert_ulong4_rte(uint4);
ulong4 __const_func convert_ulong4_sat_rte(uint4);
ulong4 __const_func convert_ulong4_rtz(uint4);
ulong4 __const_func convert_ulong4_sat_rtz(uint4);
ulong4 __const_func convert_ulong4_rtp(uint4);
ulong4 __const_func convert_ulong4_sat_rtp(uint4);
ulong4 __const_func convert_ulong4_rtn(uint4);
ulong4 __const_func convert_ulong4_sat_rtn(uint4);
ulong4 __const_func convert_ulong4(uint4);
ulong4 __const_func convert_ulong4_sat(uint4);
ulong4 __const_func convert_ulong4_rte(long4);
ulong4 __const_func convert_ulong4_sat_rte(long4);
ulong4 __const_func convert_ulong4_rtz(long4);
ulong4 __const_func convert_ulong4_sat_rtz(long4);
ulong4 __const_func convert_ulong4_rtp(long4);
ulong4 __const_func convert_ulong4_sat_rtp(long4);
ulong4 __const_func convert_ulong4_rtn(long4);
ulong4 __const_func convert_ulong4_sat_rtn(long4);
ulong4 __const_func convert_ulong4(long4);
ulong4 __const_func convert_ulong4_sat(long4);
ulong4 __const_func convert_ulong4_rte(ulong4);
ulong4 __const_func convert_ulong4_sat_rte(ulong4);
ulong4 __const_func convert_ulong4_rtz(ulong4);
ulong4 __const_func convert_ulong4_sat_rtz(ulong4);
ulong4 __const_func convert_ulong4_rtp(ulong4);
ulong4 __const_func convert_ulong4_sat_rtp(ulong4);
ulong4 __const_func convert_ulong4_rtn(ulong4);
ulong4 __const_func convert_ulong4_sat_rtn(ulong4);
ulong4 __const_func convert_ulong4(ulong4);
ulong4 __const_func convert_ulong4_sat(ulong4);
ulong4 __const_func convert_ulong4_rte(float4);
ulong4 __const_func convert_ulong4_sat_rte(float4);
ulong4 __const_func convert_ulong4_rtz(float4);
ulong4 __const_func convert_ulong4_sat_rtz(float4);
ulong4 __const_func convert_ulong4_rtp(float4);
ulong4 __const_func convert_ulong4_sat_rtp(float4);
ulong4 __const_func convert_ulong4_rtn(float4);
ulong4 __const_func convert_ulong4_sat_rtn(float4);
ulong4 __const_func convert_ulong4(float4);
ulong4 __const_func convert_ulong4_sat(float4);
float4 __const_func convert_float4_rte(char4);
float4 __const_func convert_float4_rtz(char4);
float4 __const_func convert_float4_rtp(char4);
float4 __const_func convert_float4_rtn(char4);
float4 __const_func convert_float4(char4);
float4 __const_func convert_float4_rte(uchar4);
float4 __const_func convert_float4_rtz(uchar4);
float4 __const_func convert_float4_rtp(uchar4);
float4 __const_func convert_float4_rtn(uchar4);
float4 __const_func convert_float4(uchar4);
float4 __const_func convert_float4_rte(short4);
float4 __const_func convert_float4_rtz(short4);
float4 __const_func convert_float4_rtp(short4);
float4 __const_func convert_float4_rtn(short4);
float4 __const_func convert_float4(short4);
float4 __const_func convert_float4_rte(ushort4);
float4 __const_func convert_float4_rtz(ushort4);
float4 __const_func convert_float4_rtp(ushort4);
float4 __const_func convert_float4_rtn(ushort4);
float4 __const_func convert_float4(ushort4);
float4 __const_func convert_float4_rte(int4);
float4 __const_func convert_float4_rtz(int4);
float4 __const_func convert_float4_rtp(int4);
float4 __const_func convert_float4_rtn(int4);
float4 __const_func convert_float4(int4);
float4 __const_func convert_float4_rte(uint4);
float4 __const_func convert_float4_rtz(uint4);
float4 __const_func convert_float4_rtp(uint4);
float4 __const_func convert_float4_rtn(uint4);
float4 __const_func convert_float4(uint4);
float4 __const_func convert_float4_rte(long4);
float4 __const_func convert_float4_rtz(long4);
float4 __const_func convert_float4_rtp(long4);
float4 __const_func convert_float4_rtn(long4);
float4 __const_func convert_float4(long4);
float4 __const_func convert_float4_rte(ulong4);
float4 __const_func convert_float4_rtz(ulong4);
float4 __const_func convert_float4_rtp(ulong4);
float4 __const_func convert_float4_rtn(ulong4);
float4 __const_func convert_float4(ulong4);
float4 __const_func convert_float4_rte(float4);
float4 __const_func convert_float4_rtz(float4);
float4 __const_func convert_float4_rtp(float4);
float4 __const_func convert_float4_rtn(float4);
float4 __const_func convert_float4(float4);
char8 __const_func convert_char8_rte(char8);
char8 __const_func convert_char8_sat_rte(char8);
char8 __const_func convert_char8_rtz(char8);
char8 __const_func convert_char8_sat_rtz(char8);
char8 __const_func convert_char8_rtp(char8);
char8 __const_func convert_char8_sat_rtp(char8);
char8 __const_func convert_char8_rtn(char8);
char8 __const_func convert_char8_sat_rtn(char8);
char8 __const_func convert_char8(char8);
char8 __const_func convert_char8_sat(char8);
char8 __const_func convert_char8_rte(uchar8);
char8 __const_func convert_char8_sat_rte(uchar8);
char8 __const_func convert_char8_rtz(uchar8);
char8 __const_func convert_char8_sat_rtz(uchar8);
char8 __const_func convert_char8_rtp(uchar8);
char8 __const_func convert_char8_sat_rtp(uchar8);
char8 __const_func convert_char8_rtn(uchar8);
char8 __const_func convert_char8_sat_rtn(uchar8);
char8 __const_func convert_char8(uchar8);
char8 __const_func convert_char8_sat(uchar8);
char8 __const_func convert_char8_rte(short8);
char8 __const_func convert_char8_sat_rte(short8);
char8 __const_func convert_char8_rtz(short8);
char8 __const_func convert_char8_sat_rtz(short8);
char8 __const_func convert_char8_rtp(short8);
char8 __const_func convert_char8_sat_rtp(short8);
char8 __const_func convert_char8_rtn(short8);
char8 __const_func convert_char8_sat_rtn(short8);
char8 __const_func convert_char8(short8);
char8 __const_func convert_char8_sat(short8);
char8 __const_func convert_char8_rte(ushort8);
char8 __const_func convert_char8_sat_rte(ushort8);
char8 __const_func convert_char8_rtz(ushort8);
char8 __const_func convert_char8_sat_rtz(ushort8);
char8 __const_func convert_char8_rtp(ushort8);
char8 __const_func convert_char8_sat_rtp(ushort8);
char8 __const_func convert_char8_rtn(ushort8);
char8 __const_func convert_char8_sat_rtn(ushort8);
char8 __const_func convert_char8(ushort8);
char8 __const_func convert_char8_sat(ushort8);
char8 __const_func convert_char8_rte(int8);
char8 __const_func convert_char8_sat_rte(int8);
char8 __const_func convert_char8_rtz(int8);
char8 __const_func convert_char8_sat_rtz(int8);
char8 __const_func convert_char8_rtp(int8);
char8 __const_func convert_char8_sat_rtp(int8);
char8 __const_func convert_char8_rtn(int8);
char8 __const_func convert_char8_sat_rtn(int8);
char8 __const_func convert_char8(int8);
char8 __const_func convert_char8_sat(int8);
char8 __const_func convert_char8_rte(uint8);
char8 __const_func convert_char8_sat_rte(uint8);
char8 __const_func convert_char8_rtz(uint8);
char8 __const_func convert_char8_sat_rtz(uint8);
char8 __const_func convert_char8_rtp(uint8);
char8 __const_func convert_char8_sat_rtp(uint8);
char8 __const_func convert_char8_rtn(uint8);
char8 __const_func convert_char8_sat_rtn(uint8);
char8 __const_func convert_char8(uint8);
char8 __const_func convert_char8_sat(uint8);
char8 __const_func convert_char8_rte(long8);
char8 __const_func convert_char8_sat_rte(long8);
char8 __const_func convert_char8_rtz(long8);
char8 __const_func convert_char8_sat_rtz(long8);
char8 __const_func convert_char8_rtp(long8);
char8 __const_func convert_char8_sat_rtp(long8);
char8 __const_func convert_char8_rtn(long8);
char8 __const_func convert_char8_sat_rtn(long8);
char8 __const_func convert_char8(long8);
char8 __const_func convert_char8_sat(long8);
char8 __const_func convert_char8_rte(ulong8);
char8 __const_func convert_char8_sat_rte(ulong8);
char8 __const_func convert_char8_rtz(ulong8);
char8 __const_func convert_char8_sat_rtz(ulong8);
char8 __const_func convert_char8_rtp(ulong8);
char8 __const_func convert_char8_sat_rtp(ulong8);
char8 __const_func convert_char8_rtn(ulong8);
char8 __const_func convert_char8_sat_rtn(ulong8);
char8 __const_func convert_char8(ulong8);
char8 __const_func convert_char8_sat(ulong8);
char8 __const_func convert_char8_rte(float8);
char8 __const_func convert_char8_sat_rte(float8);
char8 __const_func convert_char8_rtz(float8);
char8 __const_func convert_char8_sat_rtz(float8);
char8 __const_func convert_char8_rtp(float8);
char8 __const_func convert_char8_sat_rtp(float8);
char8 __const_func convert_char8_rtn(float8);
char8 __const_func convert_char8_sat_rtn(float8);
char8 __const_func convert_char8(float8);
char8 __const_func convert_char8_sat(float8);
uchar8 __const_func convert_uchar8_rte(char8);
uchar8 __const_func convert_uchar8_sat_rte(char8);
uchar8 __const_func convert_uchar8_rtz(char8);
uchar8 __const_func convert_uchar8_sat_rtz(char8);
uchar8 __const_func convert_uchar8_rtp(char8);
uchar8 __const_func convert_uchar8_sat_rtp(char8);
uchar8 __const_func convert_uchar8_rtn(char8);
uchar8 __const_func convert_uchar8_sat_rtn(char8);
uchar8 __const_func convert_uchar8(char8);
uchar8 __const_func convert_uchar8_sat(char8);
uchar8 __const_func convert_uchar8_rte(uchar8);
uchar8 __const_func convert_uchar8_sat_rte(uchar8);
uchar8 __const_func convert_uchar8_rtz(uchar8);
uchar8 __const_func convert_uchar8_sat_rtz(uchar8);
uchar8 __const_func convert_uchar8_rtp(uchar8);
uchar8 __const_func convert_uchar8_sat_rtp(uchar8);
uchar8 __const_func convert_uchar8_rtn(uchar8);
uchar8 __const_func convert_uchar8_sat_rtn(uchar8);
uchar8 __const_func convert_uchar8(uchar8);
uchar8 __const_func convert_uchar8_sat(uchar8);
uchar8 __const_func convert_uchar8_rte(short8);
uchar8 __const_func convert_uchar8_sat_rte(short8);
uchar8 __const_func convert_uchar8_rtz(short8);
uchar8 __const_func convert_uchar8_sat_rtz(short8);
uchar8 __const_func convert_uchar8_rtp(short8);
uchar8 __const_func convert_uchar8_sat_rtp(short8);
uchar8 __const_func convert_uchar8_rtn(short8);
uchar8 __const_func convert_uchar8_sat_rtn(short8);
uchar8 __const_func convert_uchar8(short8);
uchar8 __const_func convert_uchar8_sat(short8);
uchar8 __const_func convert_uchar8_rte(ushort8);
uchar8 __const_func convert_uchar8_sat_rte(ushort8);
uchar8 __const_func convert_uchar8_rtz(ushort8);
uchar8 __const_func convert_uchar8_sat_rtz(ushort8);
uchar8 __const_func convert_uchar8_rtp(ushort8);
uchar8 __const_func convert_uchar8_sat_rtp(ushort8);
uchar8 __const_func convert_uchar8_rtn(ushort8);
uchar8 __const_func convert_uchar8_sat_rtn(ushort8);
uchar8 __const_func convert_uchar8(ushort8);
uchar8 __const_func convert_uchar8_sat(ushort8);
uchar8 __const_func convert_uchar8_rte(int8);
uchar8 __const_func convert_uchar8_sat_rte(int8);
uchar8 __const_func convert_uchar8_rtz(int8);
uchar8 __const_func convert_uchar8_sat_rtz(int8);
uchar8 __const_func convert_uchar8_rtp(int8);
uchar8 __const_func convert_uchar8_sat_rtp(int8);
uchar8 __const_func convert_uchar8_rtn(int8);
uchar8 __const_func convert_uchar8_sat_rtn(int8);
uchar8 __const_func convert_uchar8(int8);
uchar8 __const_func convert_uchar8_sat(int8);
uchar8 __const_func convert_uchar8_rte(uint8);
uchar8 __const_func convert_uchar8_sat_rte(uint8);
uchar8 __const_func convert_uchar8_rtz(uint8);
uchar8 __const_func convert_uchar8_sat_rtz(uint8);
uchar8 __const_func convert_uchar8_rtp(uint8);
uchar8 __const_func convert_uchar8_sat_rtp(uint8);
uchar8 __const_func convert_uchar8_rtn(uint8);
uchar8 __const_func convert_uchar8_sat_rtn(uint8);
uchar8 __const_func convert_uchar8(uint8);
uchar8 __const_func convert_uchar8_sat(uint8);
uchar8 __const_func convert_uchar8_rte(long8);
uchar8 __const_func convert_uchar8_sat_rte(long8);
uchar8 __const_func convert_uchar8_rtz(long8);
uchar8 __const_func convert_uchar8_sat_rtz(long8);
uchar8 __const_func convert_uchar8_rtp(long8);
uchar8 __const_func convert_uchar8_sat_rtp(long8);
uchar8 __const_func convert_uchar8_rtn(long8);
uchar8 __const_func convert_uchar8_sat_rtn(long8);
uchar8 __const_func convert_uchar8(long8);
uchar8 __const_func convert_uchar8_sat(long8);
uchar8 __const_func convert_uchar8_rte(ulong8);
uchar8 __const_func convert_uchar8_sat_rte(ulong8);
uchar8 __const_func convert_uchar8_rtz(ulong8);
uchar8 __const_func convert_uchar8_sat_rtz(ulong8);
uchar8 __const_func convert_uchar8_rtp(ulong8);
uchar8 __const_func convert_uchar8_sat_rtp(ulong8);
uchar8 __const_func convert_uchar8_rtn(ulong8);
uchar8 __const_func convert_uchar8_sat_rtn(ulong8);
uchar8 __const_func convert_uchar8(ulong8);
uchar8 __const_func convert_uchar8_sat(ulong8);
uchar8 __const_func convert_uchar8_rte(float8);
uchar8 __const_func convert_uchar8_sat_rte(float8);
uchar8 __const_func convert_uchar8_rtz(float8);
uchar8 __const_func convert_uchar8_sat_rtz(float8);
uchar8 __const_func convert_uchar8_rtp(float8);
uchar8 __const_func convert_uchar8_sat_rtp(float8);
uchar8 __const_func convert_uchar8_rtn(float8);
uchar8 __const_func convert_uchar8_sat_rtn(float8);
uchar8 __const_func convert_uchar8(float8);
uchar8 __const_func convert_uchar8_sat(float8);
short8 __const_func convert_short8_rte(char8);
short8 __const_func convert_short8_sat_rte(char8);
short8 __const_func convert_short8_rtz(char8);
short8 __const_func convert_short8_sat_rtz(char8);
short8 __const_func convert_short8_rtp(char8);
short8 __const_func convert_short8_sat_rtp(char8);
short8 __const_func convert_short8_rtn(char8);
short8 __const_func convert_short8_sat_rtn(char8);
short8 __const_func convert_short8(char8);
short8 __const_func convert_short8_sat(char8);
short8 __const_func convert_short8_rte(uchar8);
short8 __const_func convert_short8_sat_rte(uchar8);
short8 __const_func convert_short8_rtz(uchar8);
short8 __const_func convert_short8_sat_rtz(uchar8);
short8 __const_func convert_short8_rtp(uchar8);
short8 __const_func convert_short8_sat_rtp(uchar8);
short8 __const_func convert_short8_rtn(uchar8);
short8 __const_func convert_short8_sat_rtn(uchar8);
short8 __const_func convert_short8(uchar8);
short8 __const_func convert_short8_sat(uchar8);
short8 __const_func convert_short8_rte(short8);
short8 __const_func convert_short8_sat_rte(short8);
short8 __const_func convert_short8_rtz(short8);
short8 __const_func convert_short8_sat_rtz(short8);
short8 __const_func convert_short8_rtp(short8);
short8 __const_func convert_short8_sat_rtp(short8);
short8 __const_func convert_short8_rtn(short8);
short8 __const_func convert_short8_sat_rtn(short8);
short8 __const_func convert_short8(short8);
short8 __const_func convert_short8_sat(short8);
short8 __const_func convert_short8_rte(ushort8);
short8 __const_func convert_short8_sat_rte(ushort8);
short8 __const_func convert_short8_rtz(ushort8);
short8 __const_func convert_short8_sat_rtz(ushort8);
short8 __const_func convert_short8_rtp(ushort8);
short8 __const_func convert_short8_sat_rtp(ushort8);
short8 __const_func convert_short8_rtn(ushort8);
short8 __const_func convert_short8_sat_rtn(ushort8);
short8 __const_func convert_short8(ushort8);
short8 __const_func convert_short8_sat(ushort8);
short8 __const_func convert_short8_rte(int8);
short8 __const_func convert_short8_sat_rte(int8);
short8 __const_func convert_short8_rtz(int8);
short8 __const_func convert_short8_sat_rtz(int8);
short8 __const_func convert_short8_rtp(int8);
short8 __const_func convert_short8_sat_rtp(int8);
short8 __const_func convert_short8_rtn(int8);
short8 __const_func convert_short8_sat_rtn(int8);
short8 __const_func convert_short8(int8);
short8 __const_func convert_short8_sat(int8);
short8 __const_func convert_short8_rte(uint8);
short8 __const_func convert_short8_sat_rte(uint8);
short8 __const_func convert_short8_rtz(uint8);
short8 __const_func convert_short8_sat_rtz(uint8);
short8 __const_func convert_short8_rtp(uint8);
short8 __const_func convert_short8_sat_rtp(uint8);
short8 __const_func convert_short8_rtn(uint8);
short8 __const_func convert_short8_sat_rtn(uint8);
short8 __const_func convert_short8(uint8);
short8 __const_func convert_short8_sat(uint8);
short8 __const_func convert_short8_rte(long8);
short8 __const_func convert_short8_sat_rte(long8);
short8 __const_func convert_short8_rtz(long8);
short8 __const_func convert_short8_sat_rtz(long8);
short8 __const_func convert_short8_rtp(long8);
short8 __const_func convert_short8_sat_rtp(long8);
short8 __const_func convert_short8_rtn(long8);
short8 __const_func convert_short8_sat_rtn(long8);
short8 __const_func convert_short8(long8);
short8 __const_func convert_short8_sat(long8);
short8 __const_func convert_short8_rte(ulong8);
short8 __const_func convert_short8_sat_rte(ulong8);
short8 __const_func convert_short8_rtz(ulong8);
short8 __const_func convert_short8_sat_rtz(ulong8);
short8 __const_func convert_short8_rtp(ulong8);
short8 __const_func convert_short8_sat_rtp(ulong8);
short8 __const_func convert_short8_rtn(ulong8);
short8 __const_func convert_short8_sat_rtn(ulong8);
short8 __const_func convert_short8(ulong8);
short8 __const_func convert_short8_sat(ulong8);
short8 __const_func convert_short8_rte(float8);
short8 __const_func convert_short8_sat_rte(float8);
short8 __const_func convert_short8_rtz(float8);
short8 __const_func convert_short8_sat_rtz(float8);
short8 __const_func convert_short8_rtp(float8);
short8 __const_func convert_short8_sat_rtp(float8);
short8 __const_func convert_short8_rtn(float8);
short8 __const_func convert_short8_sat_rtn(float8);
short8 __const_func convert_short8(float8);
short8 __const_func convert_short8_sat(float8);
ushort8 __const_func convert_ushort8_rte(char8);
ushort8 __const_func convert_ushort8_sat_rte(char8);
ushort8 __const_func convert_ushort8_rtz(char8);
ushort8 __const_func convert_ushort8_sat_rtz(char8);
ushort8 __const_func convert_ushort8_rtp(char8);
ushort8 __const_func convert_ushort8_sat_rtp(char8);
ushort8 __const_func convert_ushort8_rtn(char8);
ushort8 __const_func convert_ushort8_sat_rtn(char8);
ushort8 __const_func convert_ushort8(char8);
ushort8 __const_func convert_ushort8_sat(char8);
ushort8 __const_func convert_ushort8_rte(uchar8);
ushort8 __const_func convert_ushort8_sat_rte(uchar8);
ushort8 __const_func convert_ushort8_rtz(uchar8);
ushort8 __const_func convert_ushort8_sat_rtz(uchar8);
ushort8 __const_func convert_ushort8_rtp(uchar8);
ushort8 __const_func convert_ushort8_sat_rtp(uchar8);
ushort8 __const_func convert_ushort8_rtn(uchar8);
ushort8 __const_func convert_ushort8_sat_rtn(uchar8);
ushort8 __const_func convert_ushort8(uchar8);
ushort8 __const_func convert_ushort8_sat(uchar8);
ushort8 __const_func convert_ushort8_rte(short8);
ushort8 __const_func convert_ushort8_sat_rte(short8);
ushort8 __const_func convert_ushort8_rtz(short8);
ushort8 __const_func convert_ushort8_sat_rtz(short8);
ushort8 __const_func convert_ushort8_rtp(short8);
ushort8 __const_func convert_ushort8_sat_rtp(short8);
ushort8 __const_func convert_ushort8_rtn(short8);
ushort8 __const_func convert_ushort8_sat_rtn(short8);
ushort8 __const_func convert_ushort8(short8);
ushort8 __const_func convert_ushort8_sat(short8);
ushort8 __const_func convert_ushort8_rte(ushort8);
ushort8 __const_func convert_ushort8_sat_rte(ushort8);
ushort8 __const_func convert_ushort8_rtz(ushort8);
ushort8 __const_func convert_ushort8_sat_rtz(ushort8);
ushort8 __const_func convert_ushort8_rtp(ushort8);
ushort8 __const_func convert_ushort8_sat_rtp(ushort8);
ushort8 __const_func convert_ushort8_rtn(ushort8);
ushort8 __const_func convert_ushort8_sat_rtn(ushort8);
ushort8 __const_func convert_ushort8(ushort8);
ushort8 __const_func convert_ushort8_sat(ushort8);
ushort8 __const_func convert_ushort8_rte(int8);
ushort8 __const_func convert_ushort8_sat_rte(int8);
ushort8 __const_func convert_ushort8_rtz(int8);
ushort8 __const_func convert_ushort8_sat_rtz(int8);
ushort8 __const_func convert_ushort8_rtp(int8);
ushort8 __const_func convert_ushort8_sat_rtp(int8);
ushort8 __const_func convert_ushort8_rtn(int8);
ushort8 __const_func convert_ushort8_sat_rtn(int8);
ushort8 __const_func convert_ushort8(int8);
ushort8 __const_func convert_ushort8_sat(int8);
ushort8 __const_func convert_ushort8_rte(uint8);
ushort8 __const_func convert_ushort8_sat_rte(uint8);
ushort8 __const_func convert_ushort8_rtz(uint8);
ushort8 __const_func convert_ushort8_sat_rtz(uint8);
ushort8 __const_func convert_ushort8_rtp(uint8);
ushort8 __const_func convert_ushort8_sat_rtp(uint8);
ushort8 __const_func convert_ushort8_rtn(uint8);
ushort8 __const_func convert_ushort8_sat_rtn(uint8);
ushort8 __const_func convert_ushort8(uint8);
ushort8 __const_func convert_ushort8_sat(uint8);
ushort8 __const_func convert_ushort8_rte(long8);
ushort8 __const_func convert_ushort8_sat_rte(long8);
ushort8 __const_func convert_ushort8_rtz(long8);
ushort8 __const_func convert_ushort8_sat_rtz(long8);
ushort8 __const_func convert_ushort8_rtp(long8);
ushort8 __const_func convert_ushort8_sat_rtp(long8);
ushort8 __const_func convert_ushort8_rtn(long8);
ushort8 __const_func convert_ushort8_sat_rtn(long8);
ushort8 __const_func convert_ushort8(long8);
ushort8 __const_func convert_ushort8_sat(long8);
ushort8 __const_func convert_ushort8_rte(ulong8);
ushort8 __const_func convert_ushort8_sat_rte(ulong8);
ushort8 __const_func convert_ushort8_rtz(ulong8);
ushort8 __const_func convert_ushort8_sat_rtz(ulong8);
ushort8 __const_func convert_ushort8_rtp(ulong8);
ushort8 __const_func convert_ushort8_sat_rtp(ulong8);
ushort8 __const_func convert_ushort8_rtn(ulong8);
ushort8 __const_func convert_ushort8_sat_rtn(ulong8);
ushort8 __const_func convert_ushort8(ulong8);
ushort8 __const_func convert_ushort8_sat(ulong8);
ushort8 __const_func convert_ushort8_rte(float8);
ushort8 __const_func convert_ushort8_sat_rte(float8);
ushort8 __const_func convert_ushort8_rtz(float8);
ushort8 __const_func convert_ushort8_sat_rtz(float8);
ushort8 __const_func convert_ushort8_rtp(float8);
ushort8 __const_func convert_ushort8_sat_rtp(float8);
ushort8 __const_func convert_ushort8_rtn(float8);
ushort8 __const_func convert_ushort8_sat_rtn(float8);
ushort8 __const_func convert_ushort8(float8);
ushort8 __const_func convert_ushort8_sat(float8);
int8 __const_func convert_int8_rte(char8);
int8 __const_func convert_int8_sat_rte(char8);
int8 __const_func convert_int8_rtz(char8);
int8 __const_func convert_int8_sat_rtz(char8);
int8 __const_func convert_int8_rtp(char8);
int8 __const_func convert_int8_sat_rtp(char8);
int8 __const_func convert_int8_rtn(char8);
int8 __const_func convert_int8_sat_rtn(char8);
int8 __const_func convert_int8(char8);
int8 __const_func convert_int8_sat(char8);
int8 __const_func convert_int8_rte(uchar8);
int8 __const_func convert_int8_sat_rte(uchar8);
int8 __const_func convert_int8_rtz(uchar8);
int8 __const_func convert_int8_sat_rtz(uchar8);
int8 __const_func convert_int8_rtp(uchar8);
int8 __const_func convert_int8_sat_rtp(uchar8);
int8 __const_func convert_int8_rtn(uchar8);
int8 __const_func convert_int8_sat_rtn(uchar8);
int8 __const_func convert_int8(uchar8);
int8 __const_func convert_int8_sat(uchar8);
int8 __const_func convert_int8_rte(short8);
int8 __const_func convert_int8_sat_rte(short8);
int8 __const_func convert_int8_rtz(short8);
int8 __const_func convert_int8_sat_rtz(short8);
int8 __const_func convert_int8_rtp(short8);
int8 __const_func convert_int8_sat_rtp(short8);
int8 __const_func convert_int8_rtn(short8);
int8 __const_func convert_int8_sat_rtn(short8);
int8 __const_func convert_int8(short8);
int8 __const_func convert_int8_sat(short8);
int8 __const_func convert_int8_rte(ushort8);
int8 __const_func convert_int8_sat_rte(ushort8);
int8 __const_func convert_int8_rtz(ushort8);
int8 __const_func convert_int8_sat_rtz(ushort8);
int8 __const_func convert_int8_rtp(ushort8);
int8 __const_func convert_int8_sat_rtp(ushort8);
int8 __const_func convert_int8_rtn(ushort8);
int8 __const_func convert_int8_sat_rtn(ushort8);
int8 __const_func convert_int8(ushort8);
int8 __const_func convert_int8_sat(ushort8);
int8 __const_func convert_int8_rte(int8);
int8 __const_func convert_int8_sat_rte(int8);
int8 __const_func convert_int8_rtz(int8);
int8 __const_func convert_int8_sat_rtz(int8);
int8 __const_func convert_int8_rtp(int8);
int8 __const_func convert_int8_sat_rtp(int8);
int8 __const_func convert_int8_rtn(int8);
int8 __const_func convert_int8_sat_rtn(int8);
int8 __const_func convert_int8(int8);
int8 __const_func convert_int8_sat(int8);
int8 __const_func convert_int8_rte(uint8);
int8 __const_func convert_int8_sat_rte(uint8);
int8 __const_func convert_int8_rtz(uint8);
int8 __const_func convert_int8_sat_rtz(uint8);
int8 __const_func convert_int8_rtp(uint8);
int8 __const_func convert_int8_sat_rtp(uint8);
int8 __const_func convert_int8_rtn(uint8);
int8 __const_func convert_int8_sat_rtn(uint8);
int8 __const_func convert_int8(uint8);
int8 __const_func convert_int8_sat(uint8);
int8 __const_func convert_int8_rte(long8);
int8 __const_func convert_int8_sat_rte(long8);
int8 __const_func convert_int8_rtz(long8);
int8 __const_func convert_int8_sat_rtz(long8);
int8 __const_func convert_int8_rtp(long8);
int8 __const_func convert_int8_sat_rtp(long8);
int8 __const_func convert_int8_rtn(long8);
int8 __const_func convert_int8_sat_rtn(long8);
int8 __const_func convert_int8(long8);
int8 __const_func convert_int8_sat(long8);
int8 __const_func convert_int8_rte(ulong8);
int8 __const_func convert_int8_sat_rte(ulong8);
int8 __const_func convert_int8_rtz(ulong8);
int8 __const_func convert_int8_sat_rtz(ulong8);
int8 __const_func convert_int8_rtp(ulong8);
int8 __const_func convert_int8_sat_rtp(ulong8);
int8 __const_func convert_int8_rtn(ulong8);
int8 __const_func convert_int8_sat_rtn(ulong8);
int8 __const_func convert_int8(ulong8);
int8 __const_func convert_int8_sat(ulong8);
int8 __const_func convert_int8_rte(float8);
int8 __const_func convert_int8_sat_rte(float8);
int8 __const_func convert_int8_rtz(float8);
int8 __const_func convert_int8_sat_rtz(float8);
int8 __const_func convert_int8_rtp(float8);
int8 __const_func convert_int8_sat_rtp(float8);
int8 __const_func convert_int8_rtn(float8);
int8 __const_func convert_int8_sat_rtn(float8);
int8 __const_func convert_int8(float8);
int8 __const_func convert_int8_sat(float8);
uint8 __const_func convert_uint8_rte(char8);
uint8 __const_func convert_uint8_sat_rte(char8);
uint8 __const_func convert_uint8_rtz(char8);
uint8 __const_func convert_uint8_sat_rtz(char8);
uint8 __const_func convert_uint8_rtp(char8);
uint8 __const_func convert_uint8_sat_rtp(char8);
uint8 __const_func convert_uint8_rtn(char8);
uint8 __const_func convert_uint8_sat_rtn(char8);
uint8 __const_func convert_uint8(char8);
uint8 __const_func convert_uint8_sat(char8);
uint8 __const_func convert_uint8_rte(uchar8);
uint8 __const_func convert_uint8_sat_rte(uchar8);
uint8 __const_func convert_uint8_rtz(uchar8);
uint8 __const_func convert_uint8_sat_rtz(uchar8);
uint8 __const_func convert_uint8_rtp(uchar8);
uint8 __const_func convert_uint8_sat_rtp(uchar8);
uint8 __const_func convert_uint8_rtn(uchar8);
uint8 __const_func convert_uint8_sat_rtn(uchar8);
uint8 __const_func convert_uint8(uchar8);
uint8 __const_func convert_uint8_sat(uchar8);
uint8 __const_func convert_uint8_rte(short8);
uint8 __const_func convert_uint8_sat_rte(short8);
uint8 __const_func convert_uint8_rtz(short8);
uint8 __const_func convert_uint8_sat_rtz(short8);
uint8 __const_func convert_uint8_rtp(short8);
uint8 __const_func convert_uint8_sat_rtp(short8);
uint8 __const_func convert_uint8_rtn(short8);
uint8 __const_func convert_uint8_sat_rtn(short8);
uint8 __const_func convert_uint8(short8);
uint8 __const_func convert_uint8_sat(short8);
uint8 __const_func convert_uint8_rte(ushort8);
uint8 __const_func convert_uint8_sat_rte(ushort8);
uint8 __const_func convert_uint8_rtz(ushort8);
uint8 __const_func convert_uint8_sat_rtz(ushort8);
uint8 __const_func convert_uint8_rtp(ushort8);
uint8 __const_func convert_uint8_sat_rtp(ushort8);
uint8 __const_func convert_uint8_rtn(ushort8);
uint8 __const_func convert_uint8_sat_rtn(ushort8);
uint8 __const_func convert_uint8(ushort8);
uint8 __const_func convert_uint8_sat(ushort8);
uint8 __const_func convert_uint8_rte(int8);
uint8 __const_func convert_uint8_sat_rte(int8);
uint8 __const_func convert_uint8_rtz(int8);
uint8 __const_func convert_uint8_sat_rtz(int8);
uint8 __const_func convert_uint8_rtp(int8);
uint8 __const_func convert_uint8_sat_rtp(int8);
uint8 __const_func convert_uint8_rtn(int8);
uint8 __const_func convert_uint8_sat_rtn(int8);
uint8 __const_func convert_uint8(int8);
uint8 __const_func convert_uint8_sat(int8);
uint8 __const_func convert_uint8_rte(uint8);
uint8 __const_func convert_uint8_sat_rte(uint8);
uint8 __const_func convert_uint8_rtz(uint8);
uint8 __const_func convert_uint8_sat_rtz(uint8);
uint8 __const_func convert_uint8_rtp(uint8);
uint8 __const_func convert_uint8_sat_rtp(uint8);
uint8 __const_func convert_uint8_rtn(uint8);
uint8 __const_func convert_uint8_sat_rtn(uint8);
uint8 __const_func convert_uint8(uint8);
uint8 __const_func convert_uint8_sat(uint8);
uint8 __const_func convert_uint8_rte(long8);
uint8 __const_func convert_uint8_sat_rte(long8);
uint8 __const_func convert_uint8_rtz(long8);
uint8 __const_func convert_uint8_sat_rtz(long8);
uint8 __const_func convert_uint8_rtp(long8);
uint8 __const_func convert_uint8_sat_rtp(long8);
uint8 __const_func convert_uint8_rtn(long8);
uint8 __const_func convert_uint8_sat_rtn(long8);
uint8 __const_func convert_uint8(long8);
uint8 __const_func convert_uint8_sat(long8);
uint8 __const_func convert_uint8_rte(ulong8);
uint8 __const_func convert_uint8_sat_rte(ulong8);
uint8 __const_func convert_uint8_rtz(ulong8);
uint8 __const_func convert_uint8_sat_rtz(ulong8);
uint8 __const_func convert_uint8_rtp(ulong8);
uint8 __const_func convert_uint8_sat_rtp(ulong8);
uint8 __const_func convert_uint8_rtn(ulong8);
uint8 __const_func convert_uint8_sat_rtn(ulong8);
uint8 __const_func convert_uint8(ulong8);
uint8 __const_func convert_uint8_sat(ulong8);
uint8 __const_func convert_uint8_rte(float8);
uint8 __const_func convert_uint8_sat_rte(float8);
uint8 __const_func convert_uint8_rtz(float8);
uint8 __const_func convert_uint8_sat_rtz(float8);
uint8 __const_func convert_uint8_rtp(float8);
uint8 __const_func convert_uint8_sat_rtp(float8);
uint8 __const_func convert_uint8_rtn(float8);
uint8 __const_func convert_uint8_sat_rtn(float8);
uint8 __const_func convert_uint8(float8);
uint8 __const_func convert_uint8_sat(float8);
long8 __const_func convert_long8_rte(char8);
long8 __const_func convert_long8_sat_rte(char8);
long8 __const_func convert_long8_rtz(char8);
long8 __const_func convert_long8_sat_rtz(char8);
long8 __const_func convert_long8_rtp(char8);
long8 __const_func convert_long8_sat_rtp(char8);
long8 __const_func convert_long8_rtn(char8);
long8 __const_func convert_long8_sat_rtn(char8);
long8 __const_func convert_long8(char8);
long8 __const_func convert_long8_sat(char8);
long8 __const_func convert_long8_rte(uchar8);
long8 __const_func convert_long8_sat_rte(uchar8);
long8 __const_func convert_long8_rtz(uchar8);
long8 __const_func convert_long8_sat_rtz(uchar8);
long8 __const_func convert_long8_rtp(uchar8);
long8 __const_func convert_long8_sat_rtp(uchar8);
long8 __const_func convert_long8_rtn(uchar8);
long8 __const_func convert_long8_sat_rtn(uchar8);
long8 __const_func convert_long8(uchar8);
long8 __const_func convert_long8_sat(uchar8);
long8 __const_func convert_long8_rte(short8);
long8 __const_func convert_long8_sat_rte(short8);
long8 __const_func convert_long8_rtz(short8);
long8 __const_func convert_long8_sat_rtz(short8);
long8 __const_func convert_long8_rtp(short8);
long8 __const_func convert_long8_sat_rtp(short8);
long8 __const_func convert_long8_rtn(short8);
long8 __const_func convert_long8_sat_rtn(short8);
long8 __const_func convert_long8(short8);
long8 __const_func convert_long8_sat(short8);
long8 __const_func convert_long8_rte(ushort8);
long8 __const_func convert_long8_sat_rte(ushort8);
long8 __const_func convert_long8_rtz(ushort8);
long8 __const_func convert_long8_sat_rtz(ushort8);
long8 __const_func convert_long8_rtp(ushort8);
long8 __const_func convert_long8_sat_rtp(ushort8);
long8 __const_func convert_long8_rtn(ushort8);
long8 __const_func convert_long8_sat_rtn(ushort8);
long8 __const_func convert_long8(ushort8);
long8 __const_func convert_long8_sat(ushort8);
long8 __const_func convert_long8_rte(int8);
long8 __const_func convert_long8_sat_rte(int8);
long8 __const_func convert_long8_rtz(int8);
long8 __const_func convert_long8_sat_rtz(int8);
long8 __const_func convert_long8_rtp(int8);
long8 __const_func convert_long8_sat_rtp(int8);
long8 __const_func convert_long8_rtn(int8);
long8 __const_func convert_long8_sat_rtn(int8);
long8 __const_func convert_long8(int8);
long8 __const_func convert_long8_sat(int8);
long8 __const_func convert_long8_rte(uint8);
long8 __const_func convert_long8_sat_rte(uint8);
long8 __const_func convert_long8_rtz(uint8);
long8 __const_func convert_long8_sat_rtz(uint8);
long8 __const_func convert_long8_rtp(uint8);
long8 __const_func convert_long8_sat_rtp(uint8);
long8 __const_func convert_long8_rtn(uint8);
long8 __const_func convert_long8_sat_rtn(uint8);
long8 __const_func convert_long8(uint8);
long8 __const_func convert_long8_sat(uint8);
long8 __const_func convert_long8_rte(long8);
long8 __const_func convert_long8_sat_rte(long8);
long8 __const_func convert_long8_rtz(long8);
long8 __const_func convert_long8_sat_rtz(long8);
long8 __const_func convert_long8_rtp(long8);
long8 __const_func convert_long8_sat_rtp(long8);
long8 __const_func convert_long8_rtn(long8);
long8 __const_func convert_long8_sat_rtn(long8);
long8 __const_func convert_long8(long8);
long8 __const_func convert_long8_sat(long8);
long8 __const_func convert_long8_rte(ulong8);
long8 __const_func convert_long8_sat_rte(ulong8);
long8 __const_func convert_long8_rtz(ulong8);
long8 __const_func convert_long8_sat_rtz(ulong8);
long8 __const_func convert_long8_rtp(ulong8);
long8 __const_func convert_long8_sat_rtp(ulong8);
long8 __const_func convert_long8_rtn(ulong8);
long8 __const_func convert_long8_sat_rtn(ulong8);
long8 __const_func convert_long8(ulong8);
long8 __const_func convert_long8_sat(ulong8);
long8 __const_func convert_long8_rte(float8);
long8 __const_func convert_long8_sat_rte(float8);
long8 __const_func convert_long8_rtz(float8);
long8 __const_func convert_long8_sat_rtz(float8);
long8 __const_func convert_long8_rtp(float8);
long8 __const_func convert_long8_sat_rtp(float8);
long8 __const_func convert_long8_rtn(float8);
long8 __const_func convert_long8_sat_rtn(float8);
long8 __const_func convert_long8(float8);
long8 __const_func convert_long8_sat(float8);
ulong8 __const_func convert_ulong8_rte(char8);
ulong8 __const_func convert_ulong8_sat_rte(char8);
ulong8 __const_func convert_ulong8_rtz(char8);
ulong8 __const_func convert_ulong8_sat_rtz(char8);
ulong8 __const_func convert_ulong8_rtp(char8);
ulong8 __const_func convert_ulong8_sat_rtp(char8);
ulong8 __const_func convert_ulong8_rtn(char8);
ulong8 __const_func convert_ulong8_sat_rtn(char8);
ulong8 __const_func convert_ulong8(char8);
ulong8 __const_func convert_ulong8_sat(char8);
ulong8 __const_func convert_ulong8_rte(uchar8);
ulong8 __const_func convert_ulong8_sat_rte(uchar8);
ulong8 __const_func convert_ulong8_rtz(uchar8);
ulong8 __const_func convert_ulong8_sat_rtz(uchar8);
ulong8 __const_func convert_ulong8_rtp(uchar8);
ulong8 __const_func convert_ulong8_sat_rtp(uchar8);
ulong8 __const_func convert_ulong8_rtn(uchar8);
ulong8 __const_func convert_ulong8_sat_rtn(uchar8);
ulong8 __const_func convert_ulong8(uchar8);
ulong8 __const_func convert_ulong8_sat(uchar8);
ulong8 __const_func convert_ulong8_rte(short8);
ulong8 __const_func convert_ulong8_sat_rte(short8);
ulong8 __const_func convert_ulong8_rtz(short8);
ulong8 __const_func convert_ulong8_sat_rtz(short8);
ulong8 __const_func convert_ulong8_rtp(short8);
ulong8 __const_func convert_ulong8_sat_rtp(short8);
ulong8 __const_func convert_ulong8_rtn(short8);
ulong8 __const_func convert_ulong8_sat_rtn(short8);
ulong8 __const_func convert_ulong8(short8);
ulong8 __const_func convert_ulong8_sat(short8);
ulong8 __const_func convert_ulong8_rte(ushort8);
ulong8 __const_func convert_ulong8_sat_rte(ushort8);
ulong8 __const_func convert_ulong8_rtz(ushort8);
ulong8 __const_func convert_ulong8_sat_rtz(ushort8);
ulong8 __const_func convert_ulong8_rtp(ushort8);
ulong8 __const_func convert_ulong8_sat_rtp(ushort8);
ulong8 __const_func convert_ulong8_rtn(ushort8);
ulong8 __const_func convert_ulong8_sat_rtn(ushort8);
ulong8 __const_func convert_ulong8(ushort8);
ulong8 __const_func convert_ulong8_sat(ushort8);
ulong8 __const_func convert_ulong8_rte(int8);
ulong8 __const_func convert_ulong8_sat_rte(int8);
ulong8 __const_func convert_ulong8_rtz(int8);
ulong8 __const_func convert_ulong8_sat_rtz(int8);
ulong8 __const_func convert_ulong8_rtp(int8);
ulong8 __const_func convert_ulong8_sat_rtp(int8);
ulong8 __const_func convert_ulong8_rtn(int8);
ulong8 __const_func convert_ulong8_sat_rtn(int8);
ulong8 __const_func convert_ulong8(int8);
ulong8 __const_func convert_ulong8_sat(int8);
ulong8 __const_func convert_ulong8_rte(uint8);
ulong8 __const_func convert_ulong8_sat_rte(uint8);
ulong8 __const_func convert_ulong8_rtz(uint8);
ulong8 __const_func convert_ulong8_sat_rtz(uint8);
ulong8 __const_func convert_ulong8_rtp(uint8);
ulong8 __const_func convert_ulong8_sat_rtp(uint8);
ulong8 __const_func convert_ulong8_rtn(uint8);
ulong8 __const_func convert_ulong8_sat_rtn(uint8);
ulong8 __const_func convert_ulong8(uint8);
ulong8 __const_func convert_ulong8_sat(uint8);
ulong8 __const_func convert_ulong8_rte(long8);
ulong8 __const_func convert_ulong8_sat_rte(long8);
ulong8 __const_func convert_ulong8_rtz(long8);
ulong8 __const_func convert_ulong8_sat_rtz(long8);
ulong8 __const_func convert_ulong8_rtp(long8);
ulong8 __const_func convert_ulong8_sat_rtp(long8);
ulong8 __const_func convert_ulong8_rtn(long8);
ulong8 __const_func convert_ulong8_sat_rtn(long8);
ulong8 __const_func convert_ulong8(long8);
ulong8 __const_func convert_ulong8_sat(long8);
ulong8 __const_func convert_ulong8_rte(ulong8);
ulong8 __const_func convert_ulong8_sat_rte(ulong8);
ulong8 __const_func convert_ulong8_rtz(ulong8);
ulong8 __const_func convert_ulong8_sat_rtz(ulong8);
ulong8 __const_func convert_ulong8_rtp(ulong8);
ulong8 __const_func convert_ulong8_sat_rtp(ulong8);
ulong8 __const_func convert_ulong8_rtn(ulong8);
ulong8 __const_func convert_ulong8_sat_rtn(ulong8);
ulong8 __const_func convert_ulong8(ulong8);
ulong8 __const_func convert_ulong8_sat(ulong8);
ulong8 __const_func convert_ulong8_rte(float8);
ulong8 __const_func convert_ulong8_sat_rte(float8);
ulong8 __const_func convert_ulong8_rtz(float8);
ulong8 __const_func convert_ulong8_sat_rtz(float8);
ulong8 __const_func convert_ulong8_rtp(float8);
ulong8 __const_func convert_ulong8_sat_rtp(float8);
ulong8 __const_func convert_ulong8_rtn(float8);
ulong8 __const_func convert_ulong8_sat_rtn(float8);
ulong8 __const_func convert_ulong8(float8);
ulong8 __const_func convert_ulong8_sat(float8);
float8 __const_func convert_float8_rte(char8);
float8 __const_func convert_float8_rtz(char8);
float8 __const_func convert_float8_rtp(char8);
float8 __const_func convert_float8_rtn(char8);
float8 __const_func convert_float8(char8);
float8 __const_func convert_float8_rte(uchar8);
float8 __const_func convert_float8_rtz(uchar8);
float8 __const_func convert_float8_rtp(uchar8);
float8 __const_func convert_float8_rtn(uchar8);
float8 __const_func convert_float8(uchar8);
float8 __const_func convert_float8_rte(short8);
float8 __const_func convert_float8_rtz(short8);
float8 __const_func convert_float8_rtp(short8);
float8 __const_func convert_float8_rtn(short8);
float8 __const_func convert_float8(short8);
float8 __const_func convert_float8_rte(ushort8);
float8 __const_func convert_float8_rtz(ushort8);
float8 __const_func convert_float8_rtp(ushort8);
float8 __const_func convert_float8_rtn(ushort8);
float8 __const_func convert_float8(ushort8);
float8 __const_func convert_float8_rte(int8);
float8 __const_func convert_float8_rtz(int8);
float8 __const_func convert_float8_rtp(int8);
float8 __const_func convert_float8_rtn(int8);
float8 __const_func convert_float8(int8);
float8 __const_func convert_float8_rte(uint8);
float8 __const_func convert_float8_rtz(uint8);
float8 __const_func convert_float8_rtp(uint8);
float8 __const_func convert_float8_rtn(uint8);
float8 __const_func convert_float8(uint8);
float8 __const_func convert_float8_rte(long8);
float8 __const_func convert_float8_rtz(long8);
float8 __const_func convert_float8_rtp(long8);
float8 __const_func convert_float8_rtn(long8);
float8 __const_func convert_float8(long8);
float8 __const_func convert_float8_rte(ulong8);
float8 __const_func convert_float8_rtz(ulong8);
float8 __const_func convert_float8_rtp(ulong8);
float8 __const_func convert_float8_rtn(ulong8);
float8 __const_func convert_float8(ulong8);
float8 __const_func convert_float8_rte(float8);
float8 __const_func convert_float8_rtz(float8);
float8 __const_func convert_float8_rtp(float8);
float8 __const_func convert_float8_rtn(float8);
float8 __const_func convert_float8(float8);
char16 __const_func convert_char16_rte(char16);
char16 __const_func convert_char16_sat_rte(char16);
char16 __const_func convert_char16_rtz(char16);
char16 __const_func convert_char16_sat_rtz(char16);
char16 __const_func convert_char16_rtp(char16);
char16 __const_func convert_char16_sat_rtp(char16);
char16 __const_func convert_char16_rtn(char16);
char16 __const_func convert_char16_sat_rtn(char16);
char16 __const_func convert_char16(char16);
char16 __const_func convert_char16_sat(char16);
char16 __const_func convert_char16_rte(uchar16);
char16 __const_func convert_char16_sat_rte(uchar16);
char16 __const_func convert_char16_rtz(uchar16);
char16 __const_func convert_char16_sat_rtz(uchar16);
char16 __const_func convert_char16_rtp(uchar16);
char16 __const_func convert_char16_sat_rtp(uchar16);
char16 __const_func convert_char16_rtn(uchar16);
char16 __const_func convert_char16_sat_rtn(uchar16);
char16 __const_func convert_char16(uchar16);
char16 __const_func convert_char16_sat(uchar16);
char16 __const_func convert_char16_rte(short16);
char16 __const_func convert_char16_sat_rte(short16);
char16 __const_func convert_char16_rtz(short16);
char16 __const_func convert_char16_sat_rtz(short16);
char16 __const_func convert_char16_rtp(short16);
char16 __const_func convert_char16_sat_rtp(short16);
char16 __const_func convert_char16_rtn(short16);
char16 __const_func convert_char16_sat_rtn(short16);
char16 __const_func convert_char16(short16);
char16 __const_func convert_char16_sat(short16);
char16 __const_func convert_char16_rte(ushort16);
char16 __const_func convert_char16_sat_rte(ushort16);
char16 __const_func convert_char16_rtz(ushort16);
char16 __const_func convert_char16_sat_rtz(ushort16);
char16 __const_func convert_char16_rtp(ushort16);
char16 __const_func convert_char16_sat_rtp(ushort16);
char16 __const_func convert_char16_rtn(ushort16);
char16 __const_func convert_char16_sat_rtn(ushort16);
char16 __const_func convert_char16(ushort16);
char16 __const_func convert_char16_sat(ushort16);
char16 __const_func convert_char16_rte(int16);
char16 __const_func convert_char16_sat_rte(int16);
char16 __const_func convert_char16_rtz(int16);
char16 __const_func convert_char16_sat_rtz(int16);
char16 __const_func convert_char16_rtp(int16);
char16 __const_func convert_char16_sat_rtp(int16);
char16 __const_func convert_char16_rtn(int16);
char16 __const_func convert_char16_sat_rtn(int16);
char16 __const_func convert_char16(int16);
char16 __const_func convert_char16_sat(int16);
char16 __const_func convert_char16_rte(uint16);
char16 __const_func convert_char16_sat_rte(uint16);
char16 __const_func convert_char16_rtz(uint16);
char16 __const_func convert_char16_sat_rtz(uint16);
char16 __const_func convert_char16_rtp(uint16);
char16 __const_func convert_char16_sat_rtp(uint16);
char16 __const_func convert_char16_rtn(uint16);
char16 __const_func convert_char16_sat_rtn(uint16);
char16 __const_func convert_char16(uint16);
char16 __const_func convert_char16_sat(uint16);
char16 __const_func convert_char16_rte(long16);
char16 __const_func convert_char16_sat_rte(long16);
char16 __const_func convert_char16_rtz(long16);
char16 __const_func convert_char16_sat_rtz(long16);
char16 __const_func convert_char16_rtp(long16);
char16 __const_func convert_char16_sat_rtp(long16);
char16 __const_func convert_char16_rtn(long16);
char16 __const_func convert_char16_sat_rtn(long16);
char16 __const_func convert_char16(long16);
char16 __const_func convert_char16_sat(long16);
char16 __const_func convert_char16_rte(ulong16);
char16 __const_func convert_char16_sat_rte(ulong16);
char16 __const_func convert_char16_rtz(ulong16);
char16 __const_func convert_char16_sat_rtz(ulong16);
char16 __const_func convert_char16_rtp(ulong16);
char16 __const_func convert_char16_sat_rtp(ulong16);
char16 __const_func convert_char16_rtn(ulong16);
char16 __const_func convert_char16_sat_rtn(ulong16);
char16 __const_func convert_char16(ulong16);
char16 __const_func convert_char16_sat(ulong16);
char16 __const_func convert_char16_rte(float16);
char16 __const_func convert_char16_sat_rte(float16);
char16 __const_func convert_char16_rtz(float16);
char16 __const_func convert_char16_sat_rtz(float16);
char16 __const_func convert_char16_rtp(float16);
char16 __const_func convert_char16_sat_rtp(float16);
char16 __const_func convert_char16_rtn(float16);
char16 __const_func convert_char16_sat_rtn(float16);
char16 __const_func convert_char16(float16);
char16 __const_func convert_char16_sat(float16);
uchar16 __const_func convert_uchar16_rte(char16);
uchar16 __const_func convert_uchar16_sat_rte(char16);
uchar16 __const_func convert_uchar16_rtz(char16);
uchar16 __const_func convert_uchar16_sat_rtz(char16);
uchar16 __const_func convert_uchar16_rtp(char16);
uchar16 __const_func convert_uchar16_sat_rtp(char16);
uchar16 __const_func convert_uchar16_rtn(char16);
uchar16 __const_func convert_uchar16_sat_rtn(char16);
uchar16 __const_func convert_uchar16(char16);
uchar16 __const_func convert_uchar16_sat(char16);
uchar16 __const_func convert_uchar16_rte(uchar16);
uchar16 __const_func convert_uchar16_sat_rte(uchar16);
uchar16 __const_func convert_uchar16_rtz(uchar16);
uchar16 __const_func convert_uchar16_sat_rtz(uchar16);
uchar16 __const_func convert_uchar16_rtp(uchar16);
uchar16 __const_func convert_uchar16_sat_rtp(uchar16);
uchar16 __const_func convert_uchar16_rtn(uchar16);
uchar16 __const_func convert_uchar16_sat_rtn(uchar16);
uchar16 __const_func convert_uchar16(uchar16);
uchar16 __const_func convert_uchar16_sat(uchar16);
uchar16 __const_func convert_uchar16_rte(short16);
uchar16 __const_func convert_uchar16_sat_rte(short16);
uchar16 __const_func convert_uchar16_rtz(short16);
uchar16 __const_func convert_uchar16_sat_rtz(short16);
uchar16 __const_func convert_uchar16_rtp(short16);
uchar16 __const_func convert_uchar16_sat_rtp(short16);
uchar16 __const_func convert_uchar16_rtn(short16);
uchar16 __const_func convert_uchar16_sat_rtn(short16);
uchar16 __const_func convert_uchar16(short16);
uchar16 __const_func convert_uchar16_sat(short16);
uchar16 __const_func convert_uchar16_rte(ushort16);
uchar16 __const_func convert_uchar16_sat_rte(ushort16);
uchar16 __const_func convert_uchar16_rtz(ushort16);
uchar16 __const_func convert_uchar16_sat_rtz(ushort16);
uchar16 __const_func convert_uchar16_rtp(ushort16);
uchar16 __const_func convert_uchar16_sat_rtp(ushort16);
uchar16 __const_func convert_uchar16_rtn(ushort16);
uchar16 __const_func convert_uchar16_sat_rtn(ushort16);
uchar16 __const_func convert_uchar16(ushort16);
uchar16 __const_func convert_uchar16_sat(ushort16);
uchar16 __const_func convert_uchar16_rte(int16);
uchar16 __const_func convert_uchar16_sat_rte(int16);
uchar16 __const_func convert_uchar16_rtz(int16);
uchar16 __const_func convert_uchar16_sat_rtz(int16);
uchar16 __const_func convert_uchar16_rtp(int16);
uchar16 __const_func convert_uchar16_sat_rtp(int16);
uchar16 __const_func convert_uchar16_rtn(int16);
uchar16 __const_func convert_uchar16_sat_rtn(int16);
uchar16 __const_func convert_uchar16(int16);
uchar16 __const_func convert_uchar16_sat(int16);
uchar16 __const_func convert_uchar16_rte(uint16);
uchar16 __const_func convert_uchar16_sat_rte(uint16);
uchar16 __const_func convert_uchar16_rtz(uint16);
uchar16 __const_func convert_uchar16_sat_rtz(uint16);
uchar16 __const_func convert_uchar16_rtp(uint16);
uchar16 __const_func convert_uchar16_sat_rtp(uint16);
uchar16 __const_func convert_uchar16_rtn(uint16);
uchar16 __const_func convert_uchar16_sat_rtn(uint16);
uchar16 __const_func convert_uchar16(uint16);
uchar16 __const_func convert_uchar16_sat(uint16);
uchar16 __const_func convert_uchar16_rte(long16);
uchar16 __const_func convert_uchar16_sat_rte(long16);
uchar16 __const_func convert_uchar16_rtz(long16);
uchar16 __const_func convert_uchar16_sat_rtz(long16);
uchar16 __const_func convert_uchar16_rtp(long16);
uchar16 __const_func convert_uchar16_sat_rtp(long16);
uchar16 __const_func convert_uchar16_rtn(long16);
uchar16 __const_func convert_uchar16_sat_rtn(long16);
uchar16 __const_func convert_uchar16(long16);
uchar16 __const_func convert_uchar16_sat(long16);
uchar16 __const_func convert_uchar16_rte(ulong16);
uchar16 __const_func convert_uchar16_sat_rte(ulong16);
uchar16 __const_func convert_uchar16_rtz(ulong16);
uchar16 __const_func convert_uchar16_sat_rtz(ulong16);
uchar16 __const_func convert_uchar16_rtp(ulong16);
uchar16 __const_func convert_uchar16_sat_rtp(ulong16);
uchar16 __const_func convert_uchar16_rtn(ulong16);
uchar16 __const_func convert_uchar16_sat_rtn(ulong16);
uchar16 __const_func convert_uchar16(ulong16);
uchar16 __const_func convert_uchar16_sat(ulong16);
uchar16 __const_func convert_uchar16_rte(float16);
uchar16 __const_func convert_uchar16_sat_rte(float16);
uchar16 __const_func convert_uchar16_rtz(float16);
uchar16 __const_func convert_uchar16_sat_rtz(float16);
uchar16 __const_func convert_uchar16_rtp(float16);
uchar16 __const_func convert_uchar16_sat_rtp(float16);
uchar16 __const_func convert_uchar16_rtn(float16);
uchar16 __const_func convert_uchar16_sat_rtn(float16);
uchar16 __const_func convert_uchar16(float16);
uchar16 __const_func convert_uchar16_sat(float16);
short16 __const_func convert_short16_rte(char16);
short16 __const_func convert_short16_sat_rte(char16);
short16 __const_func convert_short16_rtz(char16);
short16 __const_func convert_short16_sat_rtz(char16);
short16 __const_func convert_short16_rtp(char16);
short16 __const_func convert_short16_sat_rtp(char16);
short16 __const_func convert_short16_rtn(char16);
short16 __const_func convert_short16_sat_rtn(char16);
short16 __const_func convert_short16(char16);
short16 __const_func convert_short16_sat(char16);
short16 __const_func convert_short16_rte(uchar16);
short16 __const_func convert_short16_sat_rte(uchar16);
short16 __const_func convert_short16_rtz(uchar16);
short16 __const_func convert_short16_sat_rtz(uchar16);
short16 __const_func convert_short16_rtp(uchar16);
short16 __const_func convert_short16_sat_rtp(uchar16);
short16 __const_func convert_short16_rtn(uchar16);
short16 __const_func convert_short16_sat_rtn(uchar16);
short16 __const_func convert_short16(uchar16);
short16 __const_func convert_short16_sat(uchar16);
short16 __const_func convert_short16_rte(short16);
short16 __const_func convert_short16_sat_rte(short16);
short16 __const_func convert_short16_rtz(short16);
short16 __const_func convert_short16_sat_rtz(short16);
short16 __const_func convert_short16_rtp(short16);
short16 __const_func convert_short16_sat_rtp(short16);
short16 __const_func convert_short16_rtn(short16);
short16 __const_func convert_short16_sat_rtn(short16);
short16 __const_func convert_short16(short16);
short16 __const_func convert_short16_sat(short16);
short16 __const_func convert_short16_rte(ushort16);
short16 __const_func convert_short16_sat_rte(ushort16);
short16 __const_func convert_short16_rtz(ushort16);
short16 __const_func convert_short16_sat_rtz(ushort16);
short16 __const_func convert_short16_rtp(ushort16);
short16 __const_func convert_short16_sat_rtp(ushort16);
short16 __const_func convert_short16_rtn(ushort16);
short16 __const_func convert_short16_sat_rtn(ushort16);
short16 __const_func convert_short16(ushort16);
short16 __const_func convert_short16_sat(ushort16);
short16 __const_func convert_short16_rte(int16);
short16 __const_func convert_short16_sat_rte(int16);
short16 __const_func convert_short16_rtz(int16);
short16 __const_func convert_short16_sat_rtz(int16);
short16 __const_func convert_short16_rtp(int16);
short16 __const_func convert_short16_sat_rtp(int16);
short16 __const_func convert_short16_rtn(int16);
short16 __const_func convert_short16_sat_rtn(int16);
short16 __const_func convert_short16(int16);
short16 __const_func convert_short16_sat(int16);
short16 __const_func convert_short16_rte(uint16);
short16 __const_func convert_short16_sat_rte(uint16);
short16 __const_func convert_short16_rtz(uint16);
short16 __const_func convert_short16_sat_rtz(uint16);
short16 __const_func convert_short16_rtp(uint16);
short16 __const_func convert_short16_sat_rtp(uint16);
short16 __const_func convert_short16_rtn(uint16);
short16 __const_func convert_short16_sat_rtn(uint16);
short16 __const_func convert_short16(uint16);
short16 __const_func convert_short16_sat(uint16);
short16 __const_func convert_short16_rte(long16);
short16 __const_func convert_short16_sat_rte(long16);
short16 __const_func convert_short16_rtz(long16);
short16 __const_func convert_short16_sat_rtz(long16);
short16 __const_func convert_short16_rtp(long16);
short16 __const_func convert_short16_sat_rtp(long16);
short16 __const_func convert_short16_rtn(long16);
short16 __const_func convert_short16_sat_rtn(long16);
short16 __const_func convert_short16(long16);
short16 __const_func convert_short16_sat(long16);
short16 __const_func convert_short16_rte(ulong16);
short16 __const_func convert_short16_sat_rte(ulong16);
short16 __const_func convert_short16_rtz(ulong16);
short16 __const_func convert_short16_sat_rtz(ulong16);
short16 __const_func convert_short16_rtp(ulong16);
short16 __const_func convert_short16_sat_rtp(ulong16);
short16 __const_func convert_short16_rtn(ulong16);
short16 __const_func convert_short16_sat_rtn(ulong16);
short16 __const_func convert_short16(ulong16);
short16 __const_func convert_short16_sat(ulong16);
short16 __const_func convert_short16_rte(float16);
short16 __const_func convert_short16_sat_rte(float16);
short16 __const_func convert_short16_rtz(float16);
short16 __const_func convert_short16_sat_rtz(float16);
short16 __const_func convert_short16_rtp(float16);
short16 __const_func convert_short16_sat_rtp(float16);
short16 __const_func convert_short16_rtn(float16);
short16 __const_func convert_short16_sat_rtn(float16);
short16 __const_func convert_short16(float16);
short16 __const_func convert_short16_sat(float16);
ushort16 __const_func convert_ushort16_rte(char16);
ushort16 __const_func convert_ushort16_sat_rte(char16);
ushort16 __const_func convert_ushort16_rtz(char16);
ushort16 __const_func convert_ushort16_sat_rtz(char16);
ushort16 __const_func convert_ushort16_rtp(char16);
ushort16 __const_func convert_ushort16_sat_rtp(char16);
ushort16 __const_func convert_ushort16_rtn(char16);
ushort16 __const_func convert_ushort16_sat_rtn(char16);
ushort16 __const_func convert_ushort16(char16);
ushort16 __const_func convert_ushort16_sat(char16);
ushort16 __const_func convert_ushort16_rte(uchar16);
ushort16 __const_func convert_ushort16_sat_rte(uchar16);
ushort16 __const_func convert_ushort16_rtz(uchar16);
ushort16 __const_func convert_ushort16_sat_rtz(uchar16);
ushort16 __const_func convert_ushort16_rtp(uchar16);
ushort16 __const_func convert_ushort16_sat_rtp(uchar16);
ushort16 __const_func convert_ushort16_rtn(uchar16);
ushort16 __const_func convert_ushort16_sat_rtn(uchar16);
ushort16 __const_func convert_ushort16(uchar16);
ushort16 __const_func convert_ushort16_sat(uchar16);
ushort16 __const_func convert_ushort16_rte(short16);
ushort16 __const_func convert_ushort16_sat_rte(short16);
ushort16 __const_func convert_ushort16_rtz(short16);
ushort16 __const_func convert_ushort16_sat_rtz(short16);
ushort16 __const_func convert_ushort16_rtp(short16);
ushort16 __const_func convert_ushort16_sat_rtp(short16);
ushort16 __const_func convert_ushort16_rtn(short16);
ushort16 __const_func convert_ushort16_sat_rtn(short16);
ushort16 __const_func convert_ushort16(short16);
ushort16 __const_func convert_ushort16_sat(short16);
ushort16 __const_func convert_ushort16_rte(ushort16);
ushort16 __const_func convert_ushort16_sat_rte(ushort16);
ushort16 __const_func convert_ushort16_rtz(ushort16);
ushort16 __const_func convert_ushort16_sat_rtz(ushort16);
ushort16 __const_func convert_ushort16_rtp(ushort16);
ushort16 __const_func convert_ushort16_sat_rtp(ushort16);
ushort16 __const_func convert_ushort16_rtn(ushort16);
ushort16 __const_func convert_ushort16_sat_rtn(ushort16);
ushort16 __const_func convert_ushort16(ushort16);
ushort16 __const_func convert_ushort16_sat(ushort16);
ushort16 __const_func convert_ushort16_rte(int16);
ushort16 __const_func convert_ushort16_sat_rte(int16);
ushort16 __const_func convert_ushort16_rtz(int16);
ushort16 __const_func convert_ushort16_sat_rtz(int16);
ushort16 __const_func convert_ushort16_rtp(int16);
ushort16 __const_func convert_ushort16_sat_rtp(int16);
ushort16 __const_func convert_ushort16_rtn(int16);
ushort16 __const_func convert_ushort16_sat_rtn(int16);
ushort16 __const_func convert_ushort16(int16);
ushort16 __const_func convert_ushort16_sat(int16);
ushort16 __const_func convert_ushort16_rte(uint16);
ushort16 __const_func convert_ushort16_sat_rte(uint16);
ushort16 __const_func convert_ushort16_rtz(uint16);
ushort16 __const_func convert_ushort16_sat_rtz(uint16);
ushort16 __const_func convert_ushort16_rtp(uint16);
ushort16 __const_func convert_ushort16_sat_rtp(uint16);
ushort16 __const_func convert_ushort16_rtn(uint16);
ushort16 __const_func convert_ushort16_sat_rtn(uint16);
ushort16 __const_func convert_ushort16(uint16);
ushort16 __const_func convert_ushort16_sat(uint16);
ushort16 __const_func convert_ushort16_rte(long16);
ushort16 __const_func convert_ushort16_sat_rte(long16);
ushort16 __const_func convert_ushort16_rtz(long16);
ushort16 __const_func convert_ushort16_sat_rtz(long16);
ushort16 __const_func convert_ushort16_rtp(long16);
ushort16 __const_func convert_ushort16_sat_rtp(long16);
ushort16 __const_func convert_ushort16_rtn(long16);
ushort16 __const_func convert_ushort16_sat_rtn(long16);
ushort16 __const_func convert_ushort16(long16);
ushort16 __const_func convert_ushort16_sat(long16);
ushort16 __const_func convert_ushort16_rte(ulong16);
ushort16 __const_func convert_ushort16_sat_rte(ulong16);
ushort16 __const_func convert_ushort16_rtz(ulong16);
ushort16 __const_func convert_ushort16_sat_rtz(ulong16);
ushort16 __const_func convert_ushort16_rtp(ulong16);
ushort16 __const_func convert_ushort16_sat_rtp(ulong16);
ushort16 __const_func convert_ushort16_rtn(ulong16);
ushort16 __const_func convert_ushort16_sat_rtn(ulong16);
ushort16 __const_func convert_ushort16(ulong16);
ushort16 __const_func convert_ushort16_sat(ulong16);
ushort16 __const_func convert_ushort16_rte(float16);
ushort16 __const_func convert_ushort16_sat_rte(float16);
ushort16 __const_func convert_ushort16_rtz(float16);
ushort16 __const_func convert_ushort16_sat_rtz(float16);
ushort16 __const_func convert_ushort16_rtp(float16);
ushort16 __const_func convert_ushort16_sat_rtp(float16);
ushort16 __const_func convert_ushort16_rtn(float16);
ushort16 __const_func convert_ushort16_sat_rtn(float16);
ushort16 __const_func convert_ushort16(float16);
ushort16 __const_func convert_ushort16_sat(float16);
int16 __const_func convert_int16_rte(char16);
int16 __const_func convert_int16_sat_rte(char16);
int16 __const_func convert_int16_rtz(char16);
int16 __const_func convert_int16_sat_rtz(char16);
int16 __const_func convert_int16_rtp(char16);
int16 __const_func convert_int16_sat_rtp(char16);
int16 __const_func convert_int16_rtn(char16);
int16 __const_func convert_int16_sat_rtn(char16);
int16 __const_func convert_int16(char16);
int16 __const_func convert_int16_sat(char16);
int16 __const_func convert_int16_rte(uchar16);
int16 __const_func convert_int16_sat_rte(uchar16);
int16 __const_func convert_int16_rtz(uchar16);
int16 __const_func convert_int16_sat_rtz(uchar16);
int16 __const_func convert_int16_rtp(uchar16);
int16 __const_func convert_int16_sat_rtp(uchar16);
int16 __const_func convert_int16_rtn(uchar16);
int16 __const_func convert_int16_sat_rtn(uchar16);
int16 __const_func convert_int16(uchar16);
int16 __const_func convert_int16_sat(uchar16);
int16 __const_func convert_int16_rte(short16);
int16 __const_func convert_int16_sat_rte(short16);
int16 __const_func convert_int16_rtz(short16);
int16 __const_func convert_int16_sat_rtz(short16);
int16 __const_func convert_int16_rtp(short16);
int16 __const_func convert_int16_sat_rtp(short16);
int16 __const_func convert_int16_rtn(short16);
int16 __const_func convert_int16_sat_rtn(short16);
int16 __const_func convert_int16(short16);
int16 __const_func convert_int16_sat(short16);
int16 __const_func convert_int16_rte(ushort16);
int16 __const_func convert_int16_sat_rte(ushort16);
int16 __const_func convert_int16_rtz(ushort16);
int16 __const_func convert_int16_sat_rtz(ushort16);
int16 __const_func convert_int16_rtp(ushort16);
int16 __const_func convert_int16_sat_rtp(ushort16);
int16 __const_func convert_int16_rtn(ushort16);
int16 __const_func convert_int16_sat_rtn(ushort16);
int16 __const_func convert_int16(ushort16);
int16 __const_func convert_int16_sat(ushort16);
int16 __const_func convert_int16_rte(int16);
int16 __const_func convert_int16_sat_rte(int16);
int16 __const_func convert_int16_rtz(int16);
int16 __const_func convert_int16_sat_rtz(int16);
int16 __const_func convert_int16_rtp(int16);
int16 __const_func convert_int16_sat_rtp(int16);
int16 __const_func convert_int16_rtn(int16);
int16 __const_func convert_int16_sat_rtn(int16);
int16 __const_func convert_int16(int16);
int16 __const_func convert_int16_sat(int16);
int16 __const_func convert_int16_rte(uint16);
int16 __const_func convert_int16_sat_rte(uint16);
int16 __const_func convert_int16_rtz(uint16);
int16 __const_func convert_int16_sat_rtz(uint16);
int16 __const_func convert_int16_rtp(uint16);
int16 __const_func convert_int16_sat_rtp(uint16);
int16 __const_func convert_int16_rtn(uint16);
int16 __const_func convert_int16_sat_rtn(uint16);
int16 __const_func convert_int16(uint16);
int16 __const_func convert_int16_sat(uint16);
int16 __const_func convert_int16_rte(long16);
int16 __const_func convert_int16_sat_rte(long16);
int16 __const_func convert_int16_rtz(long16);
int16 __const_func convert_int16_sat_rtz(long16);
int16 __const_func convert_int16_rtp(long16);
int16 __const_func convert_int16_sat_rtp(long16);
int16 __const_func convert_int16_rtn(long16);
int16 __const_func convert_int16_sat_rtn(long16);
int16 __const_func convert_int16(long16);
int16 __const_func convert_int16_sat(long16);
int16 __const_func convert_int16_rte(ulong16);
int16 __const_func convert_int16_sat_rte(ulong16);
int16 __const_func convert_int16_rtz(ulong16);
int16 __const_func convert_int16_sat_rtz(ulong16);
int16 __const_func convert_int16_rtp(ulong16);
int16 __const_func convert_int16_sat_rtp(ulong16);
int16 __const_func convert_int16_rtn(ulong16);
int16 __const_func convert_int16_sat_rtn(ulong16);
int16 __const_func convert_int16(ulong16);
int16 __const_func convert_int16_sat(ulong16);
int16 __const_func convert_int16_rte(float16);
int16 __const_func convert_int16_sat_rte(float16);
int16 __const_func convert_int16_rtz(float16);
int16 __const_func convert_int16_sat_rtz(float16);
int16 __const_func convert_int16_rtp(float16);
int16 __const_func convert_int16_sat_rtp(float16);
int16 __const_func convert_int16_rtn(float16);
int16 __const_func convert_int16_sat_rtn(float16);
int16 __const_func convert_int16(float16);
int16 __const_func convert_int16_sat(float16);
uint16 __const_func convert_uint16_rte(char16);
uint16 __const_func convert_uint16_sat_rte(char16);
uint16 __const_func convert_uint16_rtz(char16);
uint16 __const_func convert_uint16_sat_rtz(char16);
uint16 __const_func convert_uint16_rtp(char16);
uint16 __const_func convert_uint16_sat_rtp(char16);
uint16 __const_func convert_uint16_rtn(char16);
uint16 __const_func convert_uint16_sat_rtn(char16);
uint16 __const_func convert_uint16(char16);
uint16 __const_func convert_uint16_sat(char16);
uint16 __const_func convert_uint16_rte(uchar16);
uint16 __const_func convert_uint16_sat_rte(uchar16);
uint16 __const_func convert_uint16_rtz(uchar16);
uint16 __const_func convert_uint16_sat_rtz(uchar16);
uint16 __const_func convert_uint16_rtp(uchar16);
uint16 __const_func convert_uint16_sat_rtp(uchar16);
uint16 __const_func convert_uint16_rtn(uchar16);
uint16 __const_func convert_uint16_sat_rtn(uchar16);
uint16 __const_func convert_uint16(uchar16);
uint16 __const_func convert_uint16_sat(uchar16);
uint16 __const_func convert_uint16_rte(short16);
uint16 __const_func convert_uint16_sat_rte(short16);
uint16 __const_func convert_uint16_rtz(short16);
uint16 __const_func convert_uint16_sat_rtz(short16);
uint16 __const_func convert_uint16_rtp(short16);
uint16 __const_func convert_uint16_sat_rtp(short16);
uint16 __const_func convert_uint16_rtn(short16);
uint16 __const_func convert_uint16_sat_rtn(short16);
uint16 __const_func convert_uint16(short16);
uint16 __const_func convert_uint16_sat(short16);
uint16 __const_func convert_uint16_rte(ushort16);
uint16 __const_func convert_uint16_sat_rte(ushort16);
uint16 __const_func convert_uint16_rtz(ushort16);
uint16 __const_func convert_uint16_sat_rtz(ushort16);
uint16 __const_func convert_uint16_rtp(ushort16);
uint16 __const_func convert_uint16_sat_rtp(ushort16);
uint16 __const_func convert_uint16_rtn(ushort16);
uint16 __const_func convert_uint16_sat_rtn(ushort16);
uint16 __const_func convert_uint16(ushort16);
uint16 __const_func convert_uint16_sat(ushort16);
uint16 __const_func convert_uint16_rte(int16);
uint16 __const_func convert_uint16_sat_rte(int16);
uint16 __const_func convert_uint16_rtz(int16);
uint16 __const_func convert_uint16_sat_rtz(int16);
uint16 __const_func convert_uint16_rtp(int16);
uint16 __const_func convert_uint16_sat_rtp(int16);
uint16 __const_func convert_uint16_rtn(int16);
uint16 __const_func convert_uint16_sat_rtn(int16);
uint16 __const_func convert_uint16(int16);
uint16 __const_func convert_uint16_sat(int16);
uint16 __const_func convert_uint16_rte(uint16);
uint16 __const_func convert_uint16_sat_rte(uint16);
uint16 __const_func convert_uint16_rtz(uint16);
uint16 __const_func convert_uint16_sat_rtz(uint16);
uint16 __const_func convert_uint16_rtp(uint16);
uint16 __const_func convert_uint16_sat_rtp(uint16);
uint16 __const_func convert_uint16_rtn(uint16);
uint16 __const_func convert_uint16_sat_rtn(uint16);
uint16 __const_func convert_uint16(uint16);
uint16 __const_func convert_uint16_sat(uint16);
uint16 __const_func convert_uint16_rte(long16);
uint16 __const_func convert_uint16_sat_rte(long16);
uint16 __const_func convert_uint16_rtz(long16);
uint16 __const_func convert_uint16_sat_rtz(long16);
uint16 __const_func convert_uint16_rtp(long16);
uint16 __const_func convert_uint16_sat_rtp(long16);
uint16 __const_func convert_uint16_rtn(long16);
uint16 __const_func convert_uint16_sat_rtn(long16);
uint16 __const_func convert_uint16(long16);
uint16 __const_func convert_uint16_sat(long16);
uint16 __const_func convert_uint16_rte(ulong16);
uint16 __const_func convert_uint16_sat_rte(ulong16);
uint16 __const_func convert_uint16_rtz(ulong16);
uint16 __const_func convert_uint16_sat_rtz(ulong16);
uint16 __const_func convert_uint16_rtp(ulong16);
uint16 __const_func convert_uint16_sat_rtp(ulong16);
uint16 __const_func convert_uint16_rtn(ulong16);
uint16 __const_func convert_uint16_sat_rtn(ulong16);
uint16 __const_func convert_uint16(ulong16);
uint16 __const_func convert_uint16_sat(ulong16);
uint16 __const_func convert_uint16_rte(float16);
uint16 __const_func convert_uint16_sat_rte(float16);
uint16 __const_func convert_uint16_rtz(float16);
uint16 __const_func convert_uint16_sat_rtz(float16);
uint16 __const_func convert_uint16_rtp(float16);
uint16 __const_func convert_uint16_sat_rtp(float16);
uint16 __const_func convert_uint16_rtn(float16);
uint16 __const_func convert_uint16_sat_rtn(float16);
uint16 __const_func convert_uint16(float16);
uint16 __const_func convert_uint16_sat(float16);
long16 __const_func convert_long16_rte(char16);
long16 __const_func convert_long16_sat_rte(char16);
long16 __const_func convert_long16_rtz(char16);
long16 __const_func convert_long16_sat_rtz(char16);
long16 __const_func convert_long16_rtp(char16);
long16 __const_func convert_long16_sat_rtp(char16);
long16 __const_func convert_long16_rtn(char16);
long16 __const_func convert_long16_sat_rtn(char16);
long16 __const_func convert_long16(char16);
long16 __const_func convert_long16_sat(char16);
long16 __const_func convert_long16_rte(uchar16);
long16 __const_func convert_long16_sat_rte(uchar16);
long16 __const_func convert_long16_rtz(uchar16);
long16 __const_func convert_long16_sat_rtz(uchar16);
long16 __const_func convert_long16_rtp(uchar16);
long16 __const_func convert_long16_sat_rtp(uchar16);
long16 __const_func convert_long16_rtn(uchar16);
long16 __const_func convert_long16_sat_rtn(uchar16);
long16 __const_func convert_long16(uchar16);
long16 __const_func convert_long16_sat(uchar16);
long16 __const_func convert_long16_rte(short16);
long16 __const_func convert_long16_sat_rte(short16);
long16 __const_func convert_long16_rtz(short16);
long16 __const_func convert_long16_sat_rtz(short16);
long16 __const_func convert_long16_rtp(short16);
long16 __const_func convert_long16_sat_rtp(short16);
long16 __const_func convert_long16_rtn(short16);
long16 __const_func convert_long16_sat_rtn(short16);
long16 __const_func convert_long16(short16);
long16 __const_func convert_long16_sat(short16);
long16 __const_func convert_long16_rte(ushort16);
long16 __const_func convert_long16_sat_rte(ushort16);
long16 __const_func convert_long16_rtz(ushort16);
long16 __const_func convert_long16_sat_rtz(ushort16);
long16 __const_func convert_long16_rtp(ushort16);
long16 __const_func convert_long16_sat_rtp(ushort16);
long16 __const_func convert_long16_rtn(ushort16);
long16 __const_func convert_long16_sat_rtn(ushort16);
long16 __const_func convert_long16(ushort16);
long16 __const_func convert_long16_sat(ushort16);
long16 __const_func convert_long16_rte(int16);
long16 __const_func convert_long16_sat_rte(int16);
long16 __const_func convert_long16_rtz(int16);
long16 __const_func convert_long16_sat_rtz(int16);
long16 __const_func convert_long16_rtp(int16);
long16 __const_func convert_long16_sat_rtp(int16);
long16 __const_func convert_long16_rtn(int16);
long16 __const_func convert_long16_sat_rtn(int16);
long16 __const_func convert_long16(int16);
long16 __const_func convert_long16_sat(int16);
long16 __const_func convert_long16_rte(uint16);
long16 __const_func convert_long16_sat_rte(uint16);
long16 __const_func convert_long16_rtz(uint16);
long16 __const_func convert_long16_sat_rtz(uint16);
long16 __const_func convert_long16_rtp(uint16);
long16 __const_func convert_long16_sat_rtp(uint16);
long16 __const_func convert_long16_rtn(uint16);
long16 __const_func convert_long16_sat_rtn(uint16);
long16 __const_func convert_long16(uint16);
long16 __const_func convert_long16_sat(uint16);
long16 __const_func convert_long16_rte(long16);
long16 __const_func convert_long16_sat_rte(long16);
long16 __const_func convert_long16_rtz(long16);
long16 __const_func convert_long16_sat_rtz(long16);
long16 __const_func convert_long16_rtp(long16);
long16 __const_func convert_long16_sat_rtp(long16);
long16 __const_func convert_long16_rtn(long16);
long16 __const_func convert_long16_sat_rtn(long16);
long16 __const_func convert_long16(long16);
long16 __const_func convert_long16_sat(long16);
long16 __const_func convert_long16_rte(ulong16);
long16 __const_func convert_long16_sat_rte(ulong16);
long16 __const_func convert_long16_rtz(ulong16);
long16 __const_func convert_long16_sat_rtz(ulong16);
long16 __const_func convert_long16_rtp(ulong16);
long16 __const_func convert_long16_sat_rtp(ulong16);
long16 __const_func convert_long16_rtn(ulong16);
long16 __const_func convert_long16_sat_rtn(ulong16);
long16 __const_func convert_long16(ulong16);
long16 __const_func convert_long16_sat(ulong16);
long16 __const_func convert_long16_rte(float16);
long16 __const_func convert_long16_sat_rte(float16);
long16 __const_func convert_long16_rtz(float16);
long16 __const_func convert_long16_sat_rtz(float16);
long16 __const_func convert_long16_rtp(float16);
long16 __const_func convert_long16_sat_rtp(float16);
long16 __const_func convert_long16_rtn(float16);
long16 __const_func convert_long16_sat_rtn(float16);
long16 __const_func convert_long16(float16);
long16 __const_func convert_long16_sat(float16);
ulong16 __const_func convert_ulong16_rte(char16);
ulong16 __const_func convert_ulong16_sat_rte(char16);
ulong16 __const_func convert_ulong16_rtz(char16);
ulong16 __const_func convert_ulong16_sat_rtz(char16);
ulong16 __const_func convert_ulong16_rtp(char16);
ulong16 __const_func convert_ulong16_sat_rtp(char16);
ulong16 __const_func convert_ulong16_rtn(char16);
ulong16 __const_func convert_ulong16_sat_rtn(char16);
ulong16 __const_func convert_ulong16(char16);
ulong16 __const_func convert_ulong16_sat(char16);
ulong16 __const_func convert_ulong16_rte(uchar16);
ulong16 __const_func convert_ulong16_sat_rte(uchar16);
ulong16 __const_func convert_ulong16_rtz(uchar16);
ulong16 __const_func convert_ulong16_sat_rtz(uchar16);
ulong16 __const_func convert_ulong16_rtp(uchar16);
ulong16 __const_func convert_ulong16_sat_rtp(uchar16);
ulong16 __const_func convert_ulong16_rtn(uchar16);
ulong16 __const_func convert_ulong16_sat_rtn(uchar16);
ulong16 __const_func convert_ulong16(uchar16);
ulong16 __const_func convert_ulong16_sat(uchar16);
ulong16 __const_func convert_ulong16_rte(short16);
ulong16 __const_func convert_ulong16_sat_rte(short16);
ulong16 __const_func convert_ulong16_rtz(short16);
ulong16 __const_func convert_ulong16_sat_rtz(short16);
ulong16 __const_func convert_ulong16_rtp(short16);
ulong16 __const_func convert_ulong16_sat_rtp(short16);
ulong16 __const_func convert_ulong16_rtn(short16);
ulong16 __const_func convert_ulong16_sat_rtn(short16);
ulong16 __const_func convert_ulong16(short16);
ulong16 __const_func convert_ulong16_sat(short16);
ulong16 __const_func convert_ulong16_rte(ushort16);
ulong16 __const_func convert_ulong16_sat_rte(ushort16);
ulong16 __const_func convert_ulong16_rtz(ushort16);
ulong16 __const_func convert_ulong16_sat_rtz(ushort16);
ulong16 __const_func convert_ulong16_rtp(ushort16);
ulong16 __const_func convert_ulong16_sat_rtp(ushort16);
ulong16 __const_func convert_ulong16_rtn(ushort16);
ulong16 __const_func convert_ulong16_sat_rtn(ushort16);
ulong16 __const_func convert_ulong16(ushort16);
ulong16 __const_func convert_ulong16_sat(ushort16);
ulong16 __const_func convert_ulong16_rte(int16);
ulong16 __const_func convert_ulong16_sat_rte(int16);
ulong16 __const_func convert_ulong16_rtz(int16);
ulong16 __const_func convert_ulong16_sat_rtz(int16);
ulong16 __const_func convert_ulong16_rtp(int16);
ulong16 __const_func convert_ulong16_sat_rtp(int16);
ulong16 __const_func convert_ulong16_rtn(int16);
ulong16 __const_func convert_ulong16_sat_rtn(int16);
ulong16 __const_func convert_ulong16(int16);
ulong16 __const_func convert_ulong16_sat(int16);
ulong16 __const_func convert_ulong16_rte(uint16);
ulong16 __const_func convert_ulong16_sat_rte(uint16);
ulong16 __const_func convert_ulong16_rtz(uint16);
ulong16 __const_func convert_ulong16_sat_rtz(uint16);
ulong16 __const_func convert_ulong16_rtp(uint16);
ulong16 __const_func convert_ulong16_sat_rtp(uint16);
ulong16 __const_func convert_ulong16_rtn(uint16);
ulong16 __const_func convert_ulong16_sat_rtn(uint16);
ulong16 __const_func convert_ulong16(uint16);
ulong16 __const_func convert_ulong16_sat(uint16);
ulong16 __const_func convert_ulong16_rte(long16);
ulong16 __const_func convert_ulong16_sat_rte(long16);
ulong16 __const_func convert_ulong16_rtz(long16);
ulong16 __const_func convert_ulong16_sat_rtz(long16);
ulong16 __const_func convert_ulong16_rtp(long16);
ulong16 __const_func convert_ulong16_sat_rtp(long16);
ulong16 __const_func convert_ulong16_rtn(long16);
ulong16 __const_func convert_ulong16_sat_rtn(long16);
ulong16 __const_func convert_ulong16(long16);
ulong16 __const_func convert_ulong16_sat(long16);
ulong16 __const_func convert_ulong16_rte(ulong16);
ulong16 __const_func convert_ulong16_sat_rte(ulong16);
ulong16 __const_func convert_ulong16_rtz(ulong16);
ulong16 __const_func convert_ulong16_sat_rtz(ulong16);
ulong16 __const_func convert_ulong16_rtp(ulong16);
ulong16 __const_func convert_ulong16_sat_rtp(ulong16);
ulong16 __const_func convert_ulong16_rtn(ulong16);
ulong16 __const_func convert_ulong16_sat_rtn(ulong16);
ulong16 __const_func convert_ulong16(ulong16);
ulong16 __const_func convert_ulong16_sat(ulong16);
ulong16 __const_func convert_ulong16_rte(float16);
ulong16 __const_func convert_ulong16_sat_rte(float16);
ulong16 __const_func convert_ulong16_rtz(float16);
ulong16 __const_func convert_ulong16_sat_rtz(float16);
ulong16 __const_func convert_ulong16_rtp(float16);
ulong16 __const_func convert_ulong16_sat_rtp(float16);
ulong16 __const_func convert_ulong16_rtn(float16);
ulong16 __const_func convert_ulong16_sat_rtn(float16);
ulong16 __const_func convert_ulong16(float16);
ulong16 __const_func convert_ulong16_sat(float16);
float16 __const_func convert_float16_rte(char16);
float16 __const_func convert_float16_rtz(char16);
float16 __const_func convert_float16_rtp(char16);
float16 __const_func convert_float16_rtn(char16);
float16 __const_func convert_float16(char16);
float16 __const_func convert_float16_rte(uchar16);
float16 __const_func convert_float16_rtz(uchar16);
float16 __const_func convert_float16_rtp(uchar16);
float16 __const_func convert_float16_rtn(uchar16);
float16 __const_func convert_float16(uchar16);
float16 __const_func convert_float16_rte(short16);
float16 __const_func convert_float16_rtz(short16);
float16 __const_func convert_float16_rtp(short16);
float16 __const_func convert_float16_rtn(short16);
float16 __const_func convert_float16(short16);
float16 __const_func convert_float16_rte(ushort16);
float16 __const_func convert_float16_rtz(ushort16);
float16 __const_func convert_float16_rtp(ushort16);
float16 __const_func convert_float16_rtn(ushort16);
float16 __const_func convert_float16(ushort16);
float16 __const_func convert_float16_rte(int16);
float16 __const_func convert_float16_rtz(int16);
float16 __const_func convert_float16_rtp(int16);
float16 __const_func convert_float16_rtn(int16);
float16 __const_func convert_float16(int16);
float16 __const_func convert_float16_rte(uint16);
float16 __const_func convert_float16_rtz(uint16);
float16 __const_func convert_float16_rtp(uint16);
float16 __const_func convert_float16_rtn(uint16);
float16 __const_func convert_float16(uint16);
float16 __const_func convert_float16_rte(long16);
float16 __const_func convert_float16_rtz(long16);
float16 __const_func convert_float16_rtp(long16);
float16 __const_func convert_float16_rtn(long16);
float16 __const_func convert_float16(long16);
float16 __const_func convert_float16_rte(ulong16);
float16 __const_func convert_float16_rtz(ulong16);
float16 __const_func convert_float16_rtp(ulong16);
float16 __const_func convert_float16_rtn(ulong16);
float16 __const_func convert_float16(ulong16);
float16 __const_func convert_float16_rte(float16);
float16 __const_func convert_float16_rtz(float16);
float16 __const_func convert_float16_rtp(float16);
float16 __const_func convert_float16_rtn(float16);
float16 __const_func convert_float16(float16);

// Conversions with double data type parameters or return value.

#ifdef cl_khr_fp64
char __const_func convert_char(double);
char __const_func convert_char_rte(double);
char __const_func convert_char_rtn(double);
char __const_func convert_char_rtp(double);
char __const_func convert_char_rtz(double);
char __const_func convert_char_sat(double);
char __const_func convert_char_sat_rte(double);
char __const_func convert_char_sat_rtn(double);
char __const_func convert_char_sat_rtp(double);
char __const_func convert_char_sat_rtz(double);
char2 __const_func convert_char2(double2);
char2 __const_func convert_char2_rte(double2);
char2 __const_func convert_char2_rtn(double2);
char2 __const_func convert_char2_rtp(double2);
char2 __const_func convert_char2_rtz(double2);
char2 __const_func convert_char2_sat(double2);
char2 __const_func convert_char2_sat_rte(double2);
char2 __const_func convert_char2_sat_rtn(double2);
char2 __const_func convert_char2_sat_rtp(double2);
char2 __const_func convert_char2_sat_rtz(double2);
char3 __const_func convert_char3(double3);
char3 __const_func convert_char3_rte(double3);
char3 __const_func convert_char3_rtn(double3);
char3 __const_func convert_char3_rtp(double3);
char3 __const_func convert_char3_rtz(double3);
char3 __const_func convert_char3_sat(double3);
char3 __const_func convert_char3_sat_rte(double3);
char3 __const_func convert_char3_sat_rtn(double3);
char3 __const_func convert_char3_sat_rtp(double3);
char3 __const_func convert_char3_sat_rtz(double3);
char4 __const_func convert_char4(double4);
char4 __const_func convert_char4_rte(double4);
char4 __const_func convert_char4_rtn(double4);
char4 __const_func convert_char4_rtp(double4);
char4 __const_func convert_char4_rtz(double4);
char4 __const_func convert_char4_sat(double4);
char4 __const_func convert_char4_sat_rte(double4);
char4 __const_func convert_char4_sat_rtn(double4);
char4 __const_func convert_char4_sat_rtp(double4);
char4 __const_func convert_char4_sat_rtz(double4);
char8 __const_func convert_char8(double8);
char8 __const_func convert_char8_rte(double8);
char8 __const_func convert_char8_rtn(double8);
char8 __const_func convert_char8_rtp(double8);
char8 __const_func convert_char8_rtz(double8);
char8 __const_func convert_char8_sat(double8);
char8 __const_func convert_char8_sat_rte(double8);
char8 __const_func convert_char8_sat_rtn(double8);
char8 __const_func convert_char8_sat_rtp(double8);
char8 __const_func convert_char8_sat_rtz(double8);
char16 __const_func convert_char16(double16);
char16 __const_func convert_char16_rte(double16);
char16 __const_func convert_char16_rtn(double16);
char16 __const_func convert_char16_rtp(double16);
char16 __const_func convert_char16_rtz(double16);
char16 __const_func convert_char16_sat(double16);
char16 __const_func convert_char16_sat_rte(double16);
char16 __const_func convert_char16_sat_rtn(double16);
char16 __const_func convert_char16_sat_rtp(double16);
char16 __const_func convert_char16_sat_rtz(double16);

uchar __const_func convert_uchar(double);
uchar __const_func convert_uchar_rte(double);
uchar __const_func convert_uchar_rtn(double);
uchar __const_func convert_uchar_rtp(double);
uchar __const_func convert_uchar_rtz(double);
uchar __const_func convert_uchar_sat(double);
uchar __const_func convert_uchar_sat_rte(double);
uchar __const_func convert_uchar_sat_rtn(double);
uchar __const_func convert_uchar_sat_rtp(double);
uchar __const_func convert_uchar_sat_rtz(double);
uchar2 __const_func convert_uchar2(double2);
uchar2 __const_func convert_uchar2_rte(double2);
uchar2 __const_func convert_uchar2_rtn(double2);
uchar2 __const_func convert_uchar2_rtp(double2);
uchar2 __const_func convert_uchar2_rtz(double2);
uchar2 __const_func convert_uchar2_sat(double2);
uchar2 __const_func convert_uchar2_sat_rte(double2);
uchar2 __const_func convert_uchar2_sat_rtn(double2);
uchar2 __const_func convert_uchar2_sat_rtp(double2);
uchar2 __const_func convert_uchar2_sat_rtz(double2);
uchar3 __const_func convert_uchar3(double3);
uchar3 __const_func convert_uchar3_rte(double3);
uchar3 __const_func convert_uchar3_rtn(double3);
uchar3 __const_func convert_uchar3_rtp(double3);
uchar3 __const_func convert_uchar3_rtz(double3);
uchar3 __const_func convert_uchar3_sat(double3);
uchar3 __const_func convert_uchar3_sat_rte(double3);
uchar3 __const_func convert_uchar3_sat_rtn(double3);
uchar3 __const_func convert_uchar3_sat_rtp(double3);
uchar3 __const_func convert_uchar3_sat_rtz(double3);
uchar4 __const_func convert_uchar4(double4);
uchar4 __const_func convert_uchar4_rte(double4);
uchar4 __const_func convert_uchar4_rtn(double4);
uchar4 __const_func convert_uchar4_rtp(double4);
uchar4 __const_func convert_uchar4_rtz(double4);
uchar4 __const_func convert_uchar4_sat(double4);
uchar4 __const_func convert_uchar4_sat_rte(double4);
uchar4 __const_func convert_uchar4_sat_rtn(double4);
uchar4 __const_func convert_uchar4_sat_rtp(double4);
uchar4 __const_func convert_uchar4_sat_rtz(double4);
uchar8 __const_func convert_uchar8(double8);
uchar8 __const_func convert_uchar8_rte(double8);
uchar8 __const_func convert_uchar8_rtn(double8);
uchar8 __const_func convert_uchar8_rtp(double8);
uchar8 __const_func convert_uchar8_rtz(double8);
uchar8 __const_func convert_uchar8_sat(double8);
uchar8 __const_func convert_uchar8_sat_rte(double8);
uchar8 __const_func convert_uchar8_sat_rtn(double8);
uchar8 __const_func convert_uchar8_sat_rtp(double8);
uchar8 __const_func convert_uchar8_sat_rtz(double8);
uchar16 __const_func convert_uchar16(double16);
uchar16 __const_func convert_uchar16_rte(double16);
uchar16 __const_func convert_uchar16_rtn(double16);
uchar16 __const_func convert_uchar16_rtp(double16);
uchar16 __const_func convert_uchar16_rtz(double16);
uchar16 __const_func convert_uchar16_sat(double16);
uchar16 __const_func convert_uchar16_sat_rte(double16);
uchar16 __const_func convert_uchar16_sat_rtn(double16);
uchar16 __const_func convert_uchar16_sat_rtp(double16);
uchar16 __const_func convert_uchar16_sat_rtz(double16);

short __const_func convert_short(double);
short __const_func convert_short_rte(double);
short __const_func convert_short_rtn(double);
short __const_func convert_short_rtp(double);
short __const_func convert_short_rtz(double);
short __const_func convert_short_sat(double);
short __const_func convert_short_sat_rte(double);
short __const_func convert_short_sat_rtn(double);
short __const_func convert_short_sat_rtp(double);
short __const_func convert_short_sat_rtz(double);
short2 __const_func convert_short2(double2);
short2 __const_func convert_short2_rte(double2);
short2 __const_func convert_short2_rtn(double2);
short2 __const_func convert_short2_rtp(double2);
short2 __const_func convert_short2_rtz(double2);
short2 __const_func convert_short2_sat(double2);
short2 __const_func convert_short2_sat_rte(double2);
short2 __const_func convert_short2_sat_rtn(double2);
short2 __const_func convert_short2_sat_rtp(double2);
short2 __const_func convert_short2_sat_rtz(double2);
short3 __const_func convert_short3(double3);
short3 __const_func convert_short3_rte(double3);
short3 __const_func convert_short3_rtn(double3);
short3 __const_func convert_short3_rtp(double3);
short3 __const_func convert_short3_rtz(double3);
short3 __const_func convert_short3_sat(double3);
short3 __const_func convert_short3_sat_rte(double3);
short3 __const_func convert_short3_sat_rtn(double3);
short3 __const_func convert_short3_sat_rtp(double3);
short3 __const_func convert_short3_sat_rtz(double3);
short4 __const_func convert_short4(double4);
short4 __const_func convert_short4_rte(double4);
short4 __const_func convert_short4_rtn(double4);
short4 __const_func convert_short4_rtp(double4);
short4 __const_func convert_short4_rtz(double4);
short4 __const_func convert_short4_sat(double4);
short4 __const_func convert_short4_sat_rte(double4);
short4 __const_func convert_short4_sat_rtn(double4);
short4 __const_func convert_short4_sat_rtp(double4);
short4 __const_func convert_short4_sat_rtz(double4);
short8 __const_func convert_short8(double8);
short8 __const_func convert_short8_rte(double8);
short8 __const_func convert_short8_rtn(double8);
short8 __const_func convert_short8_rtp(double8);
short8 __const_func convert_short8_rtz(double8);
short8 __const_func convert_short8_sat(double8);
short8 __const_func convert_short8_sat_rte(double8);
short8 __const_func convert_short8_sat_rtn(double8);
short8 __const_func convert_short8_sat_rtp(double8);
short8 __const_func convert_short8_sat_rtz(double8);
short16 __const_func convert_short16(double16);
short16 __const_func convert_short16_rte(double16);
short16 __const_func convert_short16_rtn(double16);
short16 __const_func convert_short16_rtp(double16);
short16 __const_func convert_short16_rtz(double16);
short16 __const_func convert_short16_sat(double16);
short16 __const_func convert_short16_sat_rte(double16);
short16 __const_func convert_short16_sat_rtn(double16);
short16 __const_func convert_short16_sat_rtp(double16);
short16 __const_func convert_short16_sat_rtz(double16);

ushort __const_func convert_ushort(double);
ushort __const_func convert_ushort_rte(double);
ushort __const_func convert_ushort_rtn(double);
ushort __const_func convert_ushort_rtp(double);
ushort __const_func convert_ushort_rtz(double);
ushort __const_func convert_ushort_sat(double);
ushort __const_func convert_ushort_sat_rte(double);
ushort __const_func convert_ushort_sat_rtn(double);
ushort __const_func convert_ushort_sat_rtp(double);
ushort __const_func convert_ushort_sat_rtz(double);
ushort2 __const_func convert_ushort2(double2);
ushort2 __const_func convert_ushort2_rte(double2);
ushort2 __const_func convert_ushort2_rtn(double2);
ushort2 __const_func convert_ushort2_rtp(double2);
ushort2 __const_func convert_ushort2_rtz(double2);
ushort2 __const_func convert_ushort2_sat(double2);
ushort2 __const_func convert_ushort2_sat_rte(double2);
ushort2 __const_func convert_ushort2_sat_rtn(double2);
ushort2 __const_func convert_ushort2_sat_rtp(double2);
ushort2 __const_func convert_ushort2_sat_rtz(double2);
ushort3 __const_func convert_ushort3(double3);
ushort3 __const_func convert_ushort3_rte(double3);
ushort3 __const_func convert_ushort3_rtn(double3);
ushort3 __const_func convert_ushort3_rtp(double3);
ushort3 __const_func convert_ushort3_rtz(double3);
ushort3 __const_func convert_ushort3_sat(double3);
ushort3 __const_func convert_ushort3_sat_rte(double3);
ushort3 __const_func convert_ushort3_sat_rtn(double3);
ushort3 __const_func convert_ushort3_sat_rtp(double3);
ushort3 __const_func convert_ushort3_sat_rtz(double3);
ushort4 __const_func convert_ushort4(double4);
ushort4 __const_func convert_ushort4_rte(double4);
ushort4 __const_func convert_ushort4_rtn(double4);
ushort4 __const_func convert_ushort4_rtp(double4);
ushort4 __const_func convert_ushort4_rtz(double4);
ushort4 __const_func convert_ushort4_sat(double4);
ushort4 __const_func convert_ushort4_sat_rte(double4);
ushort4 __const_func convert_ushort4_sat_rtn(double4);
ushort4 __const_func convert_ushort4_sat_rtp(double4);
ushort4 __const_func convert_ushort4_sat_rtz(double4);
ushort8 __const_func convert_ushort8(double8);
ushort8 __const_func convert_ushort8_rte(double8);
ushort8 __const_func convert_ushort8_rtn(double8);
ushort8 __const_func convert_ushort8_rtp(double8);
ushort8 __const_func convert_ushort8_rtz(double8);
ushort8 __const_func convert_ushort8_sat(double8);
ushort8 __const_func convert_ushort8_sat_rte(double8);
ushort8 __const_func convert_ushort8_sat_rtn(double8);
ushort8 __const_func convert_ushort8_sat_rtp(double8);
ushort8 __const_func convert_ushort8_sat_rtz(double8);
ushort16 __const_func convert_ushort16(double16);
ushort16 __const_func convert_ushort16_rte(double16);
ushort16 __const_func convert_ushort16_rtn(double16);
ushort16 __const_func convert_ushort16_rtp(double16);
ushort16 __const_func convert_ushort16_rtz(double16);
ushort16 __const_func convert_ushort16_sat(double16);
ushort16 __const_func convert_ushort16_sat_rte(double16);
ushort16 __const_func convert_ushort16_sat_rtn(double16);
ushort16 __const_func convert_ushort16_sat_rtp(double16);
ushort16 __const_func convert_ushort16_sat_rtz(double16);

int __const_func convert_int(double);
int __const_func convert_int_rte(double);
int __const_func convert_int_rtn(double);
int __const_func convert_int_rtp(double);
int __const_func convert_int_rtz(double);
int __const_func convert_int_sat(double);
int __const_func convert_int_sat_rte(double);
int __const_func convert_int_sat_rtn(double);
int __const_func convert_int_sat_rtp(double);
int __const_func convert_int_sat_rtz(double);
int2 __const_func convert_int2(double2);
int2 __const_func convert_int2_rte(double2);
int2 __const_func convert_int2_rtn(double2);
int2 __const_func convert_int2_rtp(double2);
int2 __const_func convert_int2_rtz(double2);
int2 __const_func convert_int2_sat(double2);
int2 __const_func convert_int2_sat_rte(double2);
int2 __const_func convert_int2_sat_rtn(double2);
int2 __const_func convert_int2_sat_rtp(double2);
int2 __const_func convert_int2_sat_rtz(double2);
int3 __const_func convert_int3(double3);
int3 __const_func convert_int3_rte(double3);
int3 __const_func convert_int3_rtn(double3);
int3 __const_func convert_int3_rtp(double3);
int3 __const_func convert_int3_rtz(double3);
int3 __const_func convert_int3_sat(double3);
int3 __const_func convert_int3_sat_rte(double3);
int3 __const_func convert_int3_sat_rtn(double3);
int3 __const_func convert_int3_sat_rtp(double3);
int3 __const_func convert_int3_sat_rtz(double3);
int4 __const_func convert_int4(double4);
int4 __const_func convert_int4_rte(double4);
int4 __const_func convert_int4_rtn(double4);
int4 __const_func convert_int4_rtp(double4);
int4 __const_func convert_int4_rtz(double4);
int4 __const_func convert_int4_sat(double4);
int4 __const_func convert_int4_sat_rte(double4);
int4 __const_func convert_int4_sat_rtn(double4);
int4 __const_func convert_int4_sat_rtp(double4);
int4 __const_func convert_int4_sat_rtz(double4);
int8 __const_func convert_int8(double8);
int8 __const_func convert_int8_rte(double8);
int8 __const_func convert_int8_rtn(double8);
int8 __const_func convert_int8_rtp(double8);
int8 __const_func convert_int8_rtz(double8);
int8 __const_func convert_int8_sat(double8);
int8 __const_func convert_int8_sat_rte(double8);
int8 __const_func convert_int8_sat_rtn(double8);
int8 __const_func convert_int8_sat_rtp(double8);
int8 __const_func convert_int8_sat_rtz(double8);
int16 __const_func convert_int16(double16);
int16 __const_func convert_int16_rte(double16);
int16 __const_func convert_int16_rtn(double16);
int16 __const_func convert_int16_rtp(double16);
int16 __const_func convert_int16_rtz(double16);
int16 __const_func convert_int16_sat(double16);
int16 __const_func convert_int16_sat_rte(double16);
int16 __const_func convert_int16_sat_rtn(double16);
int16 __const_func convert_int16_sat_rtp(double16);
int16 __const_func convert_int16_sat_rtz(double16);

uint __const_func convert_uint(double);
uint __const_func convert_uint_rte(double);
uint __const_func convert_uint_rtn(double);
uint __const_func convert_uint_rtp(double);
uint __const_func convert_uint_rtz(double);
uint __const_func convert_uint_sat(double);
uint __const_func convert_uint_sat_rte(double);
uint __const_func convert_uint_sat_rtn(double);
uint __const_func convert_uint_sat_rtp(double);
uint __const_func convert_uint_sat_rtz(double);
uint2 __const_func convert_uint2(double2);
uint2 __const_func convert_uint2_rte(double2);
uint2 __const_func convert_uint2_rtn(double2);
uint2 __const_func convert_uint2_rtp(double2);
uint2 __const_func convert_uint2_rtz(double2);
uint2 __const_func convert_uint2_sat(double2);
uint2 __const_func convert_uint2_sat_rte(double2);
uint2 __const_func convert_uint2_sat_rtn(double2);
uint2 __const_func convert_uint2_sat_rtp(double2);
uint2 __const_func convert_uint2_sat_rtz(double2);
uint3 __const_func convert_uint3(double3);
uint3 __const_func convert_uint3_rte(double3);
uint3 __const_func convert_uint3_rtn(double3);
uint3 __const_func convert_uint3_rtp(double3);
uint3 __const_func convert_uint3_rtz(double3);
uint3 __const_func convert_uint3_sat(double3);
uint3 __const_func convert_uint3_sat_rte(double3);
uint3 __const_func convert_uint3_sat_rtn(double3);
uint3 __const_func convert_uint3_sat_rtp(double3);
uint3 __const_func convert_uint3_sat_rtz(double3);
uint4 __const_func convert_uint4(double4);
uint4 __const_func convert_uint4_rte(double4);
uint4 __const_func convert_uint4_rtn(double4);
uint4 __const_func convert_uint4_rtp(double4);
uint4 __const_func convert_uint4_rtz(double4);
uint4 __const_func convert_uint4_sat(double4);
uint4 __const_func convert_uint4_sat_rte(double4);
uint4 __const_func convert_uint4_sat_rtn(double4);
uint4 __const_func convert_uint4_sat_rtp(double4);
uint4 __const_func convert_uint4_sat_rtz(double4);
uint8 __const_func convert_uint8(double8);
uint8 __const_func convert_uint8_rte(double8);
uint8 __const_func convert_uint8_rtn(double8);
uint8 __const_func convert_uint8_rtp(double8);
uint8 __const_func convert_uint8_rtz(double8);
uint8 __const_func convert_uint8_sat(double8);
uint8 __const_func convert_uint8_sat_rte(double8);
uint8 __const_func convert_uint8_sat_rtn(double8);
uint8 __const_func convert_uint8_sat_rtp(double8);
uint8 __const_func convert_uint8_sat_rtz(double8);
uint16 __const_func convert_uint16(double16);
uint16 __const_func convert_uint16_rte(double16);
uint16 __const_func convert_uint16_rtn(double16);
uint16 __const_func convert_uint16_rtp(double16);
uint16 __const_func convert_uint16_rtz(double16);
uint16 __const_func convert_uint16_sat(double16);
uint16 __const_func convert_uint16_sat_rte(double16);
uint16 __const_func convert_uint16_sat_rtn(double16);
uint16 __const_func convert_uint16_sat_rtp(double16);
uint16 __const_func convert_uint16_sat_rtz(double16);

long __const_func convert_long(double);
long __const_func convert_long_rte(double);
long __const_func convert_long_rtn(double);
long __const_func convert_long_rtp(double);
long __const_func convert_long_rtz(double);
long __const_func convert_long_sat(double);
long __const_func convert_long_sat_rte(double);
long __const_func convert_long_sat_rtn(double);
long __const_func convert_long_sat_rtp(double);
long __const_func convert_long_sat_rtz(double);
long2 __const_func convert_long2(double2);
long2 __const_func convert_long2_rte(double2);
long2 __const_func convert_long2_rtn(double2);
long2 __const_func convert_long2_rtp(double2);
long2 __const_func convert_long2_rtz(double2);
long2 __const_func convert_long2_sat(double2);
long2 __const_func convert_long2_sat_rte(double2);
long2 __const_func convert_long2_sat_rtn(double2);
long2 __const_func convert_long2_sat_rtp(double2);
long2 __const_func convert_long2_sat_rtz(double2);
long3 __const_func convert_long3(double3);
long3 __const_func convert_long3_rte(double3);
long3 __const_func convert_long3_rtn(double3);
long3 __const_func convert_long3_rtp(double3);
long3 __const_func convert_long3_rtz(double3);
long3 __const_func convert_long3_sat(double3);
long3 __const_func convert_long3_sat_rte(double3);
long3 __const_func convert_long3_sat_rtn(double3);
long3 __const_func convert_long3_sat_rtp(double3);
long3 __const_func convert_long3_sat_rtz(double3);
long4 __const_func convert_long4(double4);
long4 __const_func convert_long4_rte(double4);
long4 __const_func convert_long4_rtn(double4);
long4 __const_func convert_long4_rtp(double4);
long4 __const_func convert_long4_rtz(double4);
long4 __const_func convert_long4_sat(double4);
long4 __const_func convert_long4_sat_rte(double4);
long4 __const_func convert_long4_sat_rtn(double4);
long4 __const_func convert_long4_sat_rtp(double4);
long4 __const_func convert_long4_sat_rtz(double4);
long8 __const_func convert_long8(double8);
long8 __const_func convert_long8_rte(double8);
long8 __const_func convert_long8_rtn(double8);
long8 __const_func convert_long8_rtp(double8);
long8 __const_func convert_long8_rtz(double8);
long8 __const_func convert_long8_sat(double8);
long8 __const_func convert_long8_sat_rte(double8);
long8 __const_func convert_long8_sat_rtn(double8);
long8 __const_func convert_long8_sat_rtp(double8);
long8 __const_func convert_long8_sat_rtz(double8);
long16 __const_func convert_long16(double16);
long16 __const_func convert_long16_rte(double16);
long16 __const_func convert_long16_rtn(double16);
long16 __const_func convert_long16_rtp(double16);
long16 __const_func convert_long16_rtz(double16);
long16 __const_func convert_long16_sat(double16);
long16 __const_func convert_long16_sat_rte(double16);
long16 __const_func convert_long16_sat_rtn(double16);
long16 __const_func convert_long16_sat_rtp(double16);
long16 __const_func convert_long16_sat_rtz(double16);

ulong __const_func convert_ulong(double);
ulong __const_func convert_ulong_rte(double);
ulong __const_func convert_ulong_rtn(double);
ulong __const_func convert_ulong_rtp(double);
ulong __const_func convert_ulong_rtz(double);
ulong __const_func convert_ulong_sat(double);
ulong __const_func convert_ulong_sat_rte(double);
ulong __const_func convert_ulong_sat_rtn(double);
ulong __const_func convert_ulong_sat_rtp(double);
ulong __const_func convert_ulong_sat_rtz(double);
ulong2 __const_func convert_ulong2(double2);
ulong2 __const_func convert_ulong2_rte(double2);
ulong2 __const_func convert_ulong2_rtn(double2);
ulong2 __const_func convert_ulong2_rtp(double2);
ulong2 __const_func convert_ulong2_rtz(double2);
ulong2 __const_func convert_ulong2_sat(double2);
ulong2 __const_func convert_ulong2_sat_rte(double2);
ulong2 __const_func convert_ulong2_sat_rtn(double2);
ulong2 __const_func convert_ulong2_sat_rtp(double2);
ulong2 __const_func convert_ulong2_sat_rtz(double2);
ulong3 __const_func convert_ulong3(double3);
ulong3 __const_func convert_ulong3_rte(double3);
ulong3 __const_func convert_ulong3_rtn(double3);
ulong3 __const_func convert_ulong3_rtp(double3);
ulong3 __const_func convert_ulong3_rtz(double3);
ulong3 __const_func convert_ulong3_sat(double3);
ulong3 __const_func convert_ulong3_sat_rte(double3);
ulong3 __const_func convert_ulong3_sat_rtn(double3);
ulong3 __const_func convert_ulong3_sat_rtp(double3);
ulong3 __const_func convert_ulong3_sat_rtz(double3);
ulong4 __const_func convert_ulong4(double4);
ulong4 __const_func convert_ulong4_rte(double4);
ulong4 __const_func convert_ulong4_rtn(double4);
ulong4 __const_func convert_ulong4_rtp(double4);
ulong4 __const_func convert_ulong4_rtz(double4);
ulong4 __const_func convert_ulong4_sat(double4);
ulong4 __const_func convert_ulong4_sat_rte(double4);
ulong4 __const_func convert_ulong4_sat_rtn(double4);
ulong4 __const_func convert_ulong4_sat_rtp(double4);
ulong4 __const_func convert_ulong4_sat_rtz(double4);
ulong8 __const_func convert_ulong8(double8);
ulong8 __const_func convert_ulong8_rte(double8);
ulong8 __const_func convert_ulong8_rtn(double8);
ulong8 __const_func convert_ulong8_rtp(double8);
ulong8 __const_func convert_ulong8_rtz(double8);
ulong8 __const_func convert_ulong8_sat(double8);
ulong8 __const_func convert_ulong8_sat_rte(double8);
ulong8 __const_func convert_ulong8_sat_rtn(double8);
ulong8 __const_func convert_ulong8_sat_rtp(double8);
ulong8 __const_func convert_ulong8_sat_rtz(double8);
ulong16 __const_func convert_ulong16(double16);
ulong16 __const_func convert_ulong16_rte(double16);
ulong16 __const_func convert_ulong16_rtn(double16);
ulong16 __const_func convert_ulong16_rtp(double16);
ulong16 __const_func convert_ulong16_rtz(double16);
ulong16 __const_func convert_ulong16_sat(double16);
ulong16 __const_func convert_ulong16_sat_rte(double16);
ulong16 __const_func convert_ulong16_sat_rtn(double16);
ulong16 __const_func convert_ulong16_sat_rtp(double16);
ulong16 __const_func convert_ulong16_sat_rtz(double16);

float __const_func convert_float(double);
float __const_func convert_float_rte(double);
float __const_func convert_float_rtn(double);
float __const_func convert_float_rtp(double);
float __const_func convert_float_rtz(double);
float2 __const_func convert_float2(double2);
float2 __const_func convert_float2_rte(double2);
float2 __const_func convert_float2_rtn(double2);
float2 __const_func convert_float2_rtp(double2);
float2 __const_func convert_float2_rtz(double2);
float3 __const_func convert_float3(double3);
float3 __const_func convert_float3_rte(double3);
float3 __const_func convert_float3_rtn(double3);
float3 __const_func convert_float3_rtp(double3);
float3 __const_func convert_float3_rtz(double3);
float4 __const_func convert_float4(double4);
float4 __const_func convert_float4_rte(double4);
float4 __const_func convert_float4_rtn(double4);
float4 __const_func convert_float4_rtp(double4);
float4 __const_func convert_float4_rtz(double4);
float8 __const_func convert_float8(double8);
float8 __const_func convert_float8_rte(double8);
float8 __const_func convert_float8_rtn(double8);
float8 __const_func convert_float8_rtp(double8);
float8 __const_func convert_float8_rtz(double8);
float16 __const_func convert_float16(double16);
float16 __const_func convert_float16_rte(double16);
float16 __const_func convert_float16_rtn(double16);
float16 __const_func convert_float16_rtp(double16);
float16 __const_func convert_float16_rtz(double16);

double __const_func convert_double(char);
double __const_func convert_double(double);
double __const_func convert_double(float);
double __const_func convert_double(int);
double __const_func convert_double(long);
double __const_func convert_double(short);
double __const_func convert_double(uchar);
double __const_func convert_double(uint);
double __const_func convert_double(ulong);
double __const_func convert_double(ushort);
double __const_func convert_double_rte(char);
double __const_func convert_double_rte(double);
double __const_func convert_double_rte(float);
double __const_func convert_double_rte(int);
double __const_func convert_double_rte(long);
double __const_func convert_double_rte(short);
double __const_func convert_double_rte(uchar);
double __const_func convert_double_rte(uint);
double __const_func convert_double_rte(ulong);
double __const_func convert_double_rte(ushort);
double __const_func convert_double_rtn(char);
double __const_func convert_double_rtn(double);
double __const_func convert_double_rtn(float);
double __const_func convert_double_rtn(int);
double __const_func convert_double_rtn(long);
double __const_func convert_double_rtn(short);
double __const_func convert_double_rtn(uchar);
double __const_func convert_double_rtn(uint);
double __const_func convert_double_rtn(ulong);
double __const_func convert_double_rtn(ushort);
double __const_func convert_double_rtp(char);
double __const_func convert_double_rtp(double);
double __const_func convert_double_rtp(float);
double __const_func convert_double_rtp(int);
double __const_func convert_double_rtp(long);
double __const_func convert_double_rtp(short);
double __const_func convert_double_rtp(uchar);
double __const_func convert_double_rtp(uint);
double __const_func convert_double_rtp(ulong);
double __const_func convert_double_rtp(ushort);
double __const_func convert_double_rtz(char);
double __const_func convert_double_rtz(double);
double __const_func convert_double_rtz(float);
double __const_func convert_double_rtz(int);
double __const_func convert_double_rtz(long);
double __const_func convert_double_rtz(short);
double __const_func convert_double_rtz(uchar);
double __const_func convert_double_rtz(uint);
double __const_func convert_double_rtz(ulong);
double __const_func convert_double_rtz(ushort);
double2 __const_func convert_double2(char2);
double2 __const_func convert_double2(double2);
double2 __const_func convert_double2(float2);
double2 __const_func convert_double2(int2);
double2 __const_func convert_double2(long2);
double2 __const_func convert_double2(short2);
double2 __const_func convert_double2(uchar2);
double2 __const_func convert_double2(uint2);
double2 __const_func convert_double2(ulong2);
double2 __const_func convert_double2(ushort2);
double2 __const_func convert_double2_rte(char2);
double2 __const_func convert_double2_rte(double2);
double2 __const_func convert_double2_rte(float2);
double2 __const_func convert_double2_rte(int2);
double2 __const_func convert_double2_rte(long2);
double2 __const_func convert_double2_rte(short2);
double2 __const_func convert_double2_rte(uchar2);
double2 __const_func convert_double2_rte(uint2);
double2 __const_func convert_double2_rte(ulong2);
double2 __const_func convert_double2_rte(ushort2);
double2 __const_func convert_double2_rtn(char2);
double2 __const_func convert_double2_rtn(double2);
double2 __const_func convert_double2_rtn(float2);
double2 __const_func convert_double2_rtn(int2);
double2 __const_func convert_double2_rtn(long2);
double2 __const_func convert_double2_rtn(short2);
double2 __const_func convert_double2_rtn(uchar2);
double2 __const_func convert_double2_rtn(uint2);
double2 __const_func convert_double2_rtn(ulong2);
double2 __const_func convert_double2_rtn(ushort2);
double2 __const_func convert_double2_rtp(char2);
double2 __const_func convert_double2_rtp(double2);
double2 __const_func convert_double2_rtp(float2);
double2 __const_func convert_double2_rtp(int2);
double2 __const_func convert_double2_rtp(long2);
double2 __const_func convert_double2_rtp(short2);
double2 __const_func convert_double2_rtp(uchar2);
double2 __const_func convert_double2_rtp(uint2);
double2 __const_func convert_double2_rtp(ulong2);
double2 __const_func convert_double2_rtp(ushort2);
double2 __const_func convert_double2_rtz(char2);
double2 __const_func convert_double2_rtz(double2);
double2 __const_func convert_double2_rtz(float2);
double2 __const_func convert_double2_rtz(int2);
double2 __const_func convert_double2_rtz(long2);
double2 __const_func convert_double2_rtz(short2);
double2 __const_func convert_double2_rtz(uchar2);
double2 __const_func convert_double2_rtz(uint2);
double2 __const_func convert_double2_rtz(ulong2);
double2 __const_func convert_double2_rtz(ushort2);
double3 __const_func convert_double3(char3);
double3 __const_func convert_double3(double3);
double3 __const_func convert_double3(float3);
double3 __const_func convert_double3(int3);
double3 __const_func convert_double3(long3);
double3 __const_func convert_double3(short3);
double3 __const_func convert_double3(uchar3);
double3 __const_func convert_double3(uint3);
double3 __const_func convert_double3(ulong3);
double3 __const_func convert_double3(ushort3);
double3 __const_func convert_double3_rte(char3);
double3 __const_func convert_double3_rte(double3);
double3 __const_func convert_double3_rte(float3);
double3 __const_func convert_double3_rte(int3);
double3 __const_func convert_double3_rte(long3);
double3 __const_func convert_double3_rte(short3);
double3 __const_func convert_double3_rte(uchar3);
double3 __const_func convert_double3_rte(uint3);
double3 __const_func convert_double3_rte(ulong3);
double3 __const_func convert_double3_rte(ushort3);
double3 __const_func convert_double3_rtn(char3);
double3 __const_func convert_double3_rtn(double3);
double3 __const_func convert_double3_rtn(float3);
double3 __const_func convert_double3_rtn(int3);
double3 __const_func convert_double3_rtn(long3);
double3 __const_func convert_double3_rtn(short3);
double3 __const_func convert_double3_rtn(uchar3);
double3 __const_func convert_double3_rtn(uint3);
double3 __const_func convert_double3_rtn(ulong3);
double3 __const_func convert_double3_rtn(ushort3);
double3 __const_func convert_double3_rtp(char3);
double3 __const_func convert_double3_rtp(double3);
double3 __const_func convert_double3_rtp(float3);
double3 __const_func convert_double3_rtp(int3);
double3 __const_func convert_double3_rtp(long3);
double3 __const_func convert_double3_rtp(short3);
double3 __const_func convert_double3_rtp(uchar3);
double3 __const_func convert_double3_rtp(uint3);
double3 __const_func convert_double3_rtp(ulong3);
double3 __const_func convert_double3_rtp(ushort3);
double3 __const_func convert_double3_rtz(char3);
double3 __const_func convert_double3_rtz(double3);
double3 __const_func convert_double3_rtz(float3);
double3 __const_func convert_double3_rtz(int3);
double3 __const_func convert_double3_rtz(long3);
double3 __const_func convert_double3_rtz(short3);
double3 __const_func convert_double3_rtz(uchar3);
double3 __const_func convert_double3_rtz(uint3);
double3 __const_func convert_double3_rtz(ulong3);
double3 __const_func convert_double3_rtz(ushort3);
double4 __const_func convert_double4(char4);
double4 __const_func convert_double4(double4);
double4 __const_func convert_double4(float4);
double4 __const_func convert_double4(int4);
double4 __const_func convert_double4(long4);
double4 __const_func convert_double4(short4);
double4 __const_func convert_double4(uchar4);
double4 __const_func convert_double4(uint4);
double4 __const_func convert_double4(ulong4);
double4 __const_func convert_double4(ushort4);
double4 __const_func convert_double4_rte(char4);
double4 __const_func convert_double4_rte(double4);
double4 __const_func convert_double4_rte(float4);
double4 __const_func convert_double4_rte(int4);
double4 __const_func convert_double4_rte(long4);
double4 __const_func convert_double4_rte(short4);
double4 __const_func convert_double4_rte(uchar4);
double4 __const_func convert_double4_rte(uint4);
double4 __const_func convert_double4_rte(ulong4);
double4 __const_func convert_double4_rte(ushort4);
double4 __const_func convert_double4_rtn(char4);
double4 __const_func convert_double4_rtn(double4);
double4 __const_func convert_double4_rtn(float4);
double4 __const_func convert_double4_rtn(int4);
double4 __const_func convert_double4_rtn(long4);
double4 __const_func convert_double4_rtn(short4);
double4 __const_func convert_double4_rtn(uchar4);
double4 __const_func convert_double4_rtn(uint4);
double4 __const_func convert_double4_rtn(ulong4);
double4 __const_func convert_double4_rtn(ushort4);
double4 __const_func convert_double4_rtp(char4);
double4 __const_func convert_double4_rtp(double4);
double4 __const_func convert_double4_rtp(float4);
double4 __const_func convert_double4_rtp(int4);
double4 __const_func convert_double4_rtp(long4);
double4 __const_func convert_double4_rtp(short4);
double4 __const_func convert_double4_rtp(uchar4);
double4 __const_func convert_double4_rtp(uint4);
double4 __const_func convert_double4_rtp(ulong4);
double4 __const_func convert_double4_rtp(ushort4);
double4 __const_func convert_double4_rtz(char4);
double4 __const_func convert_double4_rtz(double4);
double4 __const_func convert_double4_rtz(float4);
double4 __const_func convert_double4_rtz(int4);
double4 __const_func convert_double4_rtz(long4);
double4 __const_func convert_double4_rtz(short4);
double4 __const_func convert_double4_rtz(uchar4);
double4 __const_func convert_double4_rtz(uint4);
double4 __const_func convert_double4_rtz(ulong4);
double4 __const_func convert_double4_rtz(ushort4);
double8 __const_func convert_double8(char8);
double8 __const_func convert_double8(double8);
double8 __const_func convert_double8(float8);
double8 __const_func convert_double8(int8);
double8 __const_func convert_double8(long8);
double8 __const_func convert_double8(short8);
double8 __const_func convert_double8(uchar8);
double8 __const_func convert_double8(uint8);
double8 __const_func convert_double8(ulong8);
double8 __const_func convert_double8(ushort8);
double8 __const_func convert_double8_rte(char8);
double8 __const_func convert_double8_rte(double8);
double8 __const_func convert_double8_rte(float8);
double8 __const_func convert_double8_rte(int8);
double8 __const_func convert_double8_rte(long8);
double8 __const_func convert_double8_rte(short8);
double8 __const_func convert_double8_rte(uchar8);
double8 __const_func convert_double8_rte(uint8);
double8 __const_func convert_double8_rte(ulong8);
double8 __const_func convert_double8_rte(ushort8);
double8 __const_func convert_double8_rtn(char8);
double8 __const_func convert_double8_rtn(double8);
double8 __const_func convert_double8_rtn(float8);
double8 __const_func convert_double8_rtn(int8);
double8 __const_func convert_double8_rtn(long8);
double8 __const_func convert_double8_rtn(short8);
double8 __const_func convert_double8_rtn(uchar8);
double8 __const_func convert_double8_rtn(uint8);
double8 __const_func convert_double8_rtn(ulong8);
double8 __const_func convert_double8_rtn(ushort8);
double8 __const_func convert_double8_rtp(char8);
double8 __const_func convert_double8_rtp(double8);
double8 __const_func convert_double8_rtp(float8);
double8 __const_func convert_double8_rtp(int8);
double8 __const_func convert_double8_rtp(long8);
double8 __const_func convert_double8_rtp(short8);
double8 __const_func convert_double8_rtp(uchar8);
double8 __const_func convert_double8_rtp(uint8);
double8 __const_func convert_double8_rtp(ulong8);
double8 __const_func convert_double8_rtp(ushort8);
double8 __const_func convert_double8_rtz(char8);
double8 __const_func convert_double8_rtz(double8);
double8 __const_func convert_double8_rtz(float8);
double8 __const_func convert_double8_rtz(int8);
double8 __const_func convert_double8_rtz(long8);
double8 __const_func convert_double8_rtz(short8);
double8 __const_func convert_double8_rtz(uchar8);
double8 __const_func convert_double8_rtz(uint8);
double8 __const_func convert_double8_rtz(ulong8);
double8 __const_func convert_double8_rtz(ushort8);
double16 __const_func convert_double16(char16);
double16 __const_func convert_double16(double16);
double16 __const_func convert_double16(float16);
double16 __const_func convert_double16(int16);
double16 __const_func convert_double16(long16);
double16 __const_func convert_double16(short16);
double16 __const_func convert_double16(uchar16);
double16 __const_func convert_double16(uint16);
double16 __const_func convert_double16(ulong16);
double16 __const_func convert_double16(ushort16);
double16 __const_func convert_double16_rte(char16);
double16 __const_func convert_double16_rte(double16);
double16 __const_func convert_double16_rte(float16);
double16 __const_func convert_double16_rte(int16);
double16 __const_func convert_double16_rte(long16);
double16 __const_func convert_double16_rte(short16);
double16 __const_func convert_double16_rte(uchar16);
double16 __const_func convert_double16_rte(uint16);
double16 __const_func convert_double16_rte(ulong16);
double16 __const_func convert_double16_rte(ushort16);
double16 __const_func convert_double16_rtn(char16);
double16 __const_func convert_double16_rtn(double16);
double16 __const_func convert_double16_rtn(float16);
double16 __const_func convert_double16_rtn(int16);
double16 __const_func convert_double16_rtn(long16);
double16 __const_func convert_double16_rtn(short16);
double16 __const_func convert_double16_rtn(uchar16);
double16 __const_func convert_double16_rtn(uint16);
double16 __const_func convert_double16_rtn(ulong16);
double16 __const_func convert_double16_rtn(ushort16);
double16 __const_func convert_double16_rtp(char16);
double16 __const_func convert_double16_rtp(double16);
double16 __const_func convert_double16_rtp(float16);
double16 __const_func convert_double16_rtp(int16);
double16 __const_func convert_double16_rtp(long16);
double16 __const_func convert_double16_rtp(short16);
double16 __const_func convert_double16_rtp(uchar16);
double16 __const_func convert_double16_rtp(uint16);
double16 __const_func convert_double16_rtp(ulong16);
double16 __const_func convert_double16_rtp(ushort16);
double16 __const_func convert_double16_rtz(char16);
double16 __const_func convert_double16_rtz(double16);
double16 __const_func convert_double16_rtz(float16);
double16 __const_func convert_double16_rtz(int16);
double16 __const_func convert_double16_rtz(long16);
double16 __const_func convert_double16_rtz(short16);
double16 __const_func convert_double16_rtz(uchar16);
double16 __const_func convert_double16_rtz(uint16);
double16 __const_func convert_double16_rtz(ulong16);
double16 __const_func convert_double16_rtz(ushort16);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
// Convert half types to non-double types.
uchar __const_func convert_uchar(half);
uchar __const_func convert_uchar_rte(half);
uchar __const_func convert_uchar_rtp(half);
uchar __const_func convert_uchar_rtn(half);
uchar __const_func convert_uchar_rtz(half);
uchar __const_func convert_uchar_sat(half);
uchar __const_func convert_uchar_sat_rte(half);
uchar __const_func convert_uchar_sat_rtp(half);
uchar __const_func convert_uchar_sat_rtn(half);
uchar __const_func convert_uchar_sat_rtz(half);
uchar2 __const_func convert_uchar2(half2);
uchar2 __const_func convert_uchar2_rte(half2);
uchar2 __const_func convert_uchar2_rtp(half2);
uchar2 __const_func convert_uchar2_rtn(half2);
uchar2 __const_func convert_uchar2_rtz(half2);
uchar2 __const_func convert_uchar2_sat(half2);
uchar2 __const_func convert_uchar2_sat_rte(half2);
uchar2 __const_func convert_uchar2_sat_rtp(half2);
uchar2 __const_func convert_uchar2_sat_rtn(half2);
uchar2 __const_func convert_uchar2_sat_rtz(half2);
uchar3 __const_func convert_uchar3(half3);
uchar3 __const_func convert_uchar3_rte(half3);
uchar3 __const_func convert_uchar3_rtp(half3);
uchar3 __const_func convert_uchar3_rtn(half3);
uchar3 __const_func convert_uchar3_rtz(half3);
uchar3 __const_func convert_uchar3_sat(half3);
uchar3 __const_func convert_uchar3_sat_rte(half3);
uchar3 __const_func convert_uchar3_sat_rtp(half3);
uchar3 __const_func convert_uchar3_sat_rtn(half3);
uchar3 __const_func convert_uchar3_sat_rtz(half3);
uchar4 __const_func convert_uchar4(half4);
uchar4 __const_func convert_uchar4_rte(half4);
uchar4 __const_func convert_uchar4_rtp(half4);
uchar4 __const_func convert_uchar4_rtn(half4);
uchar4 __const_func convert_uchar4_rtz(half4);
uchar4 __const_func convert_uchar4_sat(half4);
uchar4 __const_func convert_uchar4_sat_rte(half4);
uchar4 __const_func convert_uchar4_sat_rtp(half4);
uchar4 __const_func convert_uchar4_sat_rtn(half4);
uchar4 __const_func convert_uchar4_sat_rtz(half4);
uchar8 __const_func convert_uchar8(half8);
uchar8 __const_func convert_uchar8_rte(half8);
uchar8 __const_func convert_uchar8_rtp(half8);
uchar8 __const_func convert_uchar8_rtn(half8);
uchar8 __const_func convert_uchar8_rtz(half8);
uchar8 __const_func convert_uchar8_sat(half8);
uchar8 __const_func convert_uchar8_sat_rte(half8);
uchar8 __const_func convert_uchar8_sat_rtp(half8);
uchar8 __const_func convert_uchar8_sat_rtn(half8);
uchar8 __const_func convert_uchar8_sat_rtz(half8);
uchar16 __const_func convert_uchar16(half16);
uchar16 __const_func convert_uchar16_rte(half16);
uchar16 __const_func convert_uchar16_rtp(half16);
uchar16 __const_func convert_uchar16_rtn(half16);
uchar16 __const_func convert_uchar16_rtz(half16);
uchar16 __const_func convert_uchar16_sat(half16);
uchar16 __const_func convert_uchar16_sat_rte(half16);
uchar16 __const_func convert_uchar16_sat_rtp(half16);
uchar16 __const_func convert_uchar16_sat_rtn(half16);
uchar16 __const_func convert_uchar16_sat_rtz(half16);
ushort __const_func convert_ushort(half);
ushort __const_func convert_ushort_rte(half);
ushort __const_func convert_ushort_rtp(half);
ushort __const_func convert_ushort_rtn(half);
ushort __const_func convert_ushort_rtz(half);
ushort __const_func convert_ushort_sat(half);
ushort __const_func convert_ushort_sat_rte(half);
ushort __const_func convert_ushort_sat_rtp(half);
ushort __const_func convert_ushort_sat_rtn(half);
ushort __const_func convert_ushort_sat_rtz(half);
ushort2 __const_func convert_ushort2(half2);
ushort2 __const_func convert_ushort2_rte(half2);
ushort2 __const_func convert_ushort2_rtp(half2);
ushort2 __const_func convert_ushort2_rtn(half2);
ushort2 __const_func convert_ushort2_rtz(half2);
ushort2 __const_func convert_ushort2_sat(half2);
ushort2 __const_func convert_ushort2_sat_rte(half2);
ushort2 __const_func convert_ushort2_sat_rtp(half2);
ushort2 __const_func convert_ushort2_sat_rtn(half2);
ushort2 __const_func convert_ushort2_sat_rtz(half2);
ushort3 __const_func convert_ushort3(half3);
ushort3 __const_func convert_ushort3_rte(half3);
ushort3 __const_func convert_ushort3_rtp(half3);
ushort3 __const_func convert_ushort3_rtn(half3);
ushort3 __const_func convert_ushort3_rtz(half3);
ushort3 __const_func convert_ushort3_sat(half3);
ushort3 __const_func convert_ushort3_sat_rte(half3);
ushort3 __const_func convert_ushort3_sat_rtp(half3);
ushort3 __const_func convert_ushort3_sat_rtn(half3);
ushort3 __const_func convert_ushort3_sat_rtz(half3);
ushort4 __const_func convert_ushort4(half4);
ushort4 __const_func convert_ushort4_rte(half4);
ushort4 __const_func convert_ushort4_rtp(half4);
ushort4 __const_func convert_ushort4_rtn(half4);
ushort4 __const_func convert_ushort4_rtz(half4);
ushort4 __const_func convert_ushort4_sat(half4);
ushort4 __const_func convert_ushort4_sat_rte(half4);
ushort4 __const_func convert_ushort4_sat_rtp(half4);
ushort4 __const_func convert_ushort4_sat_rtn(half4);
ushort4 __const_func convert_ushort4_sat_rtz(half4);
ushort8 __const_func convert_ushort8(half8);
ushort8 __const_func convert_ushort8_rte(half8);
ushort8 __const_func convert_ushort8_rtp(half8);
ushort8 __const_func convert_ushort8_rtn(half8);
ushort8 __const_func convert_ushort8_rtz(half8);
ushort8 __const_func convert_ushort8_sat(half8);
ushort8 __const_func convert_ushort8_sat_rte(half8);
ushort8 __const_func convert_ushort8_sat_rtp(half8);
ushort8 __const_func convert_ushort8_sat_rtn(half8);
ushort8 __const_func convert_ushort8_sat_rtz(half8);
ushort16 __const_func convert_ushort16(half16);
ushort16 __const_func convert_ushort16_rte(half16);
ushort16 __const_func convert_ushort16_rtp(half16);
ushort16 __const_func convert_ushort16_rtn(half16);
ushort16 __const_func convert_ushort16_rtz(half16);
ushort16 __const_func convert_ushort16_sat(half16);
ushort16 __const_func convert_ushort16_sat_rte(half16);
ushort16 __const_func convert_ushort16_sat_rtp(half16);
ushort16 __const_func convert_ushort16_sat_rtn(half16);
ushort16 __const_func convert_ushort16_sat_rtz(half16);
uint __const_func convert_uint(half);
uint __const_func convert_uint_rte(half);
uint __const_func convert_uint_rtp(half);
uint __const_func convert_uint_rtn(half);
uint __const_func convert_uint_rtz(half);
uint __const_func convert_uint_sat(half);
uint __const_func convert_uint_sat_rte(half);
uint __const_func convert_uint_sat_rtp(half);
uint __const_func convert_uint_sat_rtn(half);
uint __const_func convert_uint_sat_rtz(half);
uint2 __const_func convert_uint2(half2);
uint2 __const_func convert_uint2_rte(half2);
uint2 __const_func convert_uint2_rtp(half2);
uint2 __const_func convert_uint2_rtn(half2);
uint2 __const_func convert_uint2_rtz(half2);
uint2 __const_func convert_uint2_sat(half2);
uint2 __const_func convert_uint2_sat_rte(half2);
uint2 __const_func convert_uint2_sat_rtp(half2);
uint2 __const_func convert_uint2_sat_rtn(half2);
uint2 __const_func convert_uint2_sat_rtz(half2);
uint3 __const_func convert_uint3(half3);
uint3 __const_func convert_uint3_rte(half3);
uint3 __const_func convert_uint3_rtp(half3);
uint3 __const_func convert_uint3_rtn(half3);
uint3 __const_func convert_uint3_rtz(half3);
uint3 __const_func convert_uint3_sat(half3);
uint3 __const_func convert_uint3_sat_rte(half3);
uint3 __const_func convert_uint3_sat_rtp(half3);
uint3 __const_func convert_uint3_sat_rtn(half3);
uint3 __const_func convert_uint3_sat_rtz(half3);
uint4 __const_func convert_uint4(half4);
uint4 __const_func convert_uint4_rte(half4);
uint4 __const_func convert_uint4_rtp(half4);
uint4 __const_func convert_uint4_rtn(half4);
uint4 __const_func convert_uint4_rtz(half4);
uint4 __const_func convert_uint4_sat(half4);
uint4 __const_func convert_uint4_sat_rte(half4);
uint4 __const_func convert_uint4_sat_rtp(half4);
uint4 __const_func convert_uint4_sat_rtn(half4);
uint4 __const_func convert_uint4_sat_rtz(half4);
uint8 __const_func convert_uint8(half8);
uint8 __const_func convert_uint8_rte(half8);
uint8 __const_func convert_uint8_rtp(half8);
uint8 __const_func convert_uint8_rtn(half8);
uint8 __const_func convert_uint8_rtz(half8);
uint8 __const_func convert_uint8_sat(half8);
uint8 __const_func convert_uint8_sat_rte(half8);
uint8 __const_func convert_uint8_sat_rtp(half8);
uint8 __const_func convert_uint8_sat_rtn(half8);
uint8 __const_func convert_uint8_sat_rtz(half8);
uint16 __const_func convert_uint16(half16);
uint16 __const_func convert_uint16_rte(half16);
uint16 __const_func convert_uint16_rtp(half16);
uint16 __const_func convert_uint16_rtn(half16);
uint16 __const_func convert_uint16_rtz(half16);
uint16 __const_func convert_uint16_sat(half16);
uint16 __const_func convert_uint16_sat_rte(half16);
uint16 __const_func convert_uint16_sat_rtp(half16);
uint16 __const_func convert_uint16_sat_rtn(half16);
uint16 __const_func convert_uint16_sat_rtz(half16);
ulong __const_func convert_ulong(half);
ulong __const_func convert_ulong_rte(half);
ulong __const_func convert_ulong_rtp(half);
ulong __const_func convert_ulong_rtn(half);
ulong __const_func convert_ulong_rtz(half);
ulong __const_func convert_ulong_sat(half);
ulong __const_func convert_ulong_sat_rte(half);
ulong __const_func convert_ulong_sat_rtp(half);
ulong __const_func convert_ulong_sat_rtn(half);
ulong __const_func convert_ulong_sat_rtz(half);
ulong2 __const_func convert_ulong2(half2);
ulong2 __const_func convert_ulong2_rte(half2);
ulong2 __const_func convert_ulong2_rtp(half2);
ulong2 __const_func convert_ulong2_rtn(half2);
ulong2 __const_func convert_ulong2_rtz(half2);
ulong2 __const_func convert_ulong2_sat(half2);
ulong2 __const_func convert_ulong2_sat_rte(half2);
ulong2 __const_func convert_ulong2_sat_rtp(half2);
ulong2 __const_func convert_ulong2_sat_rtn(half2);
ulong2 __const_func convert_ulong2_sat_rtz(half2);
ulong3 __const_func convert_ulong3(half3);
ulong3 __const_func convert_ulong3_rte(half3);
ulong3 __const_func convert_ulong3_rtp(half3);
ulong3 __const_func convert_ulong3_rtn(half3);
ulong3 __const_func convert_ulong3_rtz(half3);
ulong3 __const_func convert_ulong3_sat(half3);
ulong3 __const_func convert_ulong3_sat_rte(half3);
ulong3 __const_func convert_ulong3_sat_rtp(half3);
ulong3 __const_func convert_ulong3_sat_rtn(half3);
ulong3 __const_func convert_ulong3_sat_rtz(half3);
ulong4 __const_func convert_ulong4(half4);
ulong4 __const_func convert_ulong4_rte(half4);
ulong4 __const_func convert_ulong4_rtp(half4);
ulong4 __const_func convert_ulong4_rtn(half4);
ulong4 __const_func convert_ulong4_rtz(half4);
ulong4 __const_func convert_ulong4_sat(half4);
ulong4 __const_func convert_ulong4_sat_rte(half4);
ulong4 __const_func convert_ulong4_sat_rtp(half4);
ulong4 __const_func convert_ulong4_sat_rtn(half4);
ulong4 __const_func convert_ulong4_sat_rtz(half4);
ulong8 __const_func convert_ulong8(half8);
ulong8 __const_func convert_ulong8_rte(half8);
ulong8 __const_func convert_ulong8_rtp(half8);
ulong8 __const_func convert_ulong8_rtn(half8);
ulong8 __const_func convert_ulong8_rtz(half8);
ulong8 __const_func convert_ulong8_sat(half8);
ulong8 __const_func convert_ulong8_sat_rte(half8);
ulong8 __const_func convert_ulong8_sat_rtp(half8);
ulong8 __const_func convert_ulong8_sat_rtn(half8);
ulong8 __const_func convert_ulong8_sat_rtz(half8);
ulong16 __const_func convert_ulong16(half16);
ulong16 __const_func convert_ulong16_rte(half16);
ulong16 __const_func convert_ulong16_rtp(half16);
ulong16 __const_func convert_ulong16_rtn(half16);
ulong16 __const_func convert_ulong16_rtz(half16);
ulong16 __const_func convert_ulong16_sat(half16);
ulong16 __const_func convert_ulong16_sat_rte(half16);
ulong16 __const_func convert_ulong16_sat_rtp(half16);
ulong16 __const_func convert_ulong16_sat_rtn(half16);
ulong16 __const_func convert_ulong16_sat_rtz(half16);
char __const_func convert_char(half);
char __const_func convert_char_rte(half);
char __const_func convert_char_rtp(half);
char __const_func convert_char_rtn(half);
char __const_func convert_char_rtz(half);
char __const_func convert_char_sat(half);
char __const_func convert_char_sat_rte(half);
char __const_func convert_char_sat_rtp(half);
char __const_func convert_char_sat_rtn(half);
char __const_func convert_char_sat_rtz(half);
char2 __const_func convert_char2(half2);
char2 __const_func convert_char2_rte(half2);
char2 __const_func convert_char2_rtp(half2);
char2 __const_func convert_char2_rtn(half2);
char2 __const_func convert_char2_rtz(half2);
char2 __const_func convert_char2_sat(half2);
char2 __const_func convert_char2_sat_rte(half2);
char2 __const_func convert_char2_sat_rtp(half2);
char2 __const_func convert_char2_sat_rtn(half2);
char2 __const_func convert_char2_sat_rtz(half2);
char3 __const_func convert_char3(half3);
char3 __const_func convert_char3_rte(half3);
char3 __const_func convert_char3_rtp(half3);
char3 __const_func convert_char3_rtn(half3);
char3 __const_func convert_char3_rtz(half3);
char3 __const_func convert_char3_sat(half3);
char3 __const_func convert_char3_sat_rte(half3);
char3 __const_func convert_char3_sat_rtp(half3);
char3 __const_func convert_char3_sat_rtn(half3);
char3 __const_func convert_char3_sat_rtz(half3);
char4 __const_func convert_char4(half4);
char4 __const_func convert_char4_rte(half4);
char4 __const_func convert_char4_rtp(half4);
char4 __const_func convert_char4_rtn(half4);
char4 __const_func convert_char4_rtz(half4);
char4 __const_func convert_char4_sat(half4);
char4 __const_func convert_char4_sat_rte(half4);
char4 __const_func convert_char4_sat_rtp(half4);
char4 __const_func convert_char4_sat_rtn(half4);
char4 __const_func convert_char4_sat_rtz(half4);
char8 __const_func convert_char8(half8);
char8 __const_func convert_char8_rte(half8);
char8 __const_func convert_char8_rtp(half8);
char8 __const_func convert_char8_rtn(half8);
char8 __const_func convert_char8_rtz(half8);
char8 __const_func convert_char8_sat(half8);
char8 __const_func convert_char8_sat_rte(half8);
char8 __const_func convert_char8_sat_rtp(half8);
char8 __const_func convert_char8_sat_rtn(half8);
char8 __const_func convert_char8_sat_rtz(half8);
char16 __const_func convert_char16(half16);
char16 __const_func convert_char16_rte(half16);
char16 __const_func convert_char16_rtp(half16);
char16 __const_func convert_char16_rtn(half16);
char16 __const_func convert_char16_rtz(half16);
char16 __const_func convert_char16_sat(half16);
char16 __const_func convert_char16_sat_rte(half16);
char16 __const_func convert_char16_sat_rtp(half16);
char16 __const_func convert_char16_sat_rtn(half16);
char16 __const_func convert_char16_sat_rtz(half16);
short __const_func convert_short(half);
short __const_func convert_short_rte(half);
short __const_func convert_short_rtp(half);
short __const_func convert_short_rtn(half);
short __const_func convert_short_rtz(half);
short __const_func convert_short_sat(half);
short __const_func convert_short_sat_rte(half);
short __const_func convert_short_sat_rtp(half);
short __const_func convert_short_sat_rtn(half);
short __const_func convert_short_sat_rtz(half);
short2 __const_func convert_short2(half2);
short2 __const_func convert_short2_rte(half2);
short2 __const_func convert_short2_rtp(half2);
short2 __const_func convert_short2_rtn(half2);
short2 __const_func convert_short2_rtz(half2);
short2 __const_func convert_short2_sat(half2);
short2 __const_func convert_short2_sat_rte(half2);
short2 __const_func convert_short2_sat_rtp(half2);
short2 __const_func convert_short2_sat_rtn(half2);
short2 __const_func convert_short2_sat_rtz(half2);
short3 __const_func convert_short3(half3);
short3 __const_func convert_short3_rte(half3);
short3 __const_func convert_short3_rtp(half3);
short3 __const_func convert_short3_rtn(half3);
short3 __const_func convert_short3_rtz(half3);
short3 __const_func convert_short3_sat(half3);
short3 __const_func convert_short3_sat_rte(half3);
short3 __const_func convert_short3_sat_rtp(half3);
short3 __const_func convert_short3_sat_rtn(half3);
short3 __const_func convert_short3_sat_rtz(half3);
short4 __const_func convert_short4(half4);
short4 __const_func convert_short4_rte(half4);
short4 __const_func convert_short4_rtp(half4);
short4 __const_func convert_short4_rtn(half4);
short4 __const_func convert_short4_rtz(half4);
short4 __const_func convert_short4_sat(half4);
short4 __const_func convert_short4_sat_rte(half4);
short4 __const_func convert_short4_sat_rtp(half4);
short4 __const_func convert_short4_sat_rtn(half4);
short4 __const_func convert_short4_sat_rtz(half4);
short8 __const_func convert_short8(half8);
short8 __const_func convert_short8_rte(half8);
short8 __const_func convert_short8_rtp(half8);
short8 __const_func convert_short8_rtn(half8);
short8 __const_func convert_short8_rtz(half8);
short8 __const_func convert_short8_sat(half8);
short8 __const_func convert_short8_sat_rte(half8);
short8 __const_func convert_short8_sat_rtp(half8);
short8 __const_func convert_short8_sat_rtn(half8);
short8 __const_func convert_short8_sat_rtz(half8);
short16 __const_func convert_short16(half16);
short16 __const_func convert_short16_rte(half16);
short16 __const_func convert_short16_rtp(half16);
short16 __const_func convert_short16_rtn(half16);
short16 __const_func convert_short16_rtz(half16);
short16 __const_func convert_short16_sat(half16);
short16 __const_func convert_short16_sat_rte(half16);
short16 __const_func convert_short16_sat_rtp(half16);
short16 __const_func convert_short16_sat_rtn(half16);
short16 __const_func convert_short16_sat_rtz(half16);
int __const_func convert_int(half);
int __const_func convert_int_rte(half);
int __const_func convert_int_rtp(half);
int __const_func convert_int_rtn(half);
int __const_func convert_int_rtz(half);
int __const_func convert_int_sat(half);
int __const_func convert_int_sat_rte(half);
int __const_func convert_int_sat_rtp(half);
int __const_func convert_int_sat_rtn(half);
int __const_func convert_int_sat_rtz(half);
int2 __const_func convert_int2(half2);
int2 __const_func convert_int2_rte(half2);
int2 __const_func convert_int2_rtp(half2);
int2 __const_func convert_int2_rtn(half2);
int2 __const_func convert_int2_rtz(half2);
int2 __const_func convert_int2_sat(half2);
int2 __const_func convert_int2_sat_rte(half2);
int2 __const_func convert_int2_sat_rtp(half2);
int2 __const_func convert_int2_sat_rtn(half2);
int2 __const_func convert_int2_sat_rtz(half2);
int3 __const_func convert_int3(half3);
int3 __const_func convert_int3_rte(half3);
int3 __const_func convert_int3_rtp(half3);
int3 __const_func convert_int3_rtn(half3);
int3 __const_func convert_int3_rtz(half3);
int3 __const_func convert_int3_sat(half3);
int3 __const_func convert_int3_sat_rte(half3);
int3 __const_func convert_int3_sat_rtp(half3);
int3 __const_func convert_int3_sat_rtn(half3);
int3 __const_func convert_int3_sat_rtz(half3);
int4 __const_func convert_int4(half4);
int4 __const_func convert_int4_rte(half4);
int4 __const_func convert_int4_rtp(half4);
int4 __const_func convert_int4_rtn(half4);
int4 __const_func convert_int4_rtz(half4);
int4 __const_func convert_int4_sat(half4);
int4 __const_func convert_int4_sat_rte(half4);
int4 __const_func convert_int4_sat_rtp(half4);
int4 __const_func convert_int4_sat_rtn(half4);
int4 __const_func convert_int4_sat_rtz(half4);
int8 __const_func convert_int8(half8);
int8 __const_func convert_int8_rte(half8);
int8 __const_func convert_int8_rtp(half8);
int8 __const_func convert_int8_rtn(half8);
int8 __const_func convert_int8_rtz(half8);
int8 __const_func convert_int8_sat(half8);
int8 __const_func convert_int8_sat_rte(half8);
int8 __const_func convert_int8_sat_rtp(half8);
int8 __const_func convert_int8_sat_rtn(half8);
int8 __const_func convert_int8_sat_rtz(half8);
int16 __const_func convert_int16(half16);
int16 __const_func convert_int16_rte(half16);
int16 __const_func convert_int16_rtp(half16);
int16 __const_func convert_int16_rtn(half16);
int16 __const_func convert_int16_rtz(half16);
int16 __const_func convert_int16_sat(half16);
int16 __const_func convert_int16_sat_rte(half16);
int16 __const_func convert_int16_sat_rtp(half16);
int16 __const_func convert_int16_sat_rtn(half16);
int16 __const_func convert_int16_sat_rtz(half16);
long __const_func convert_long(half);
long __const_func convert_long_rte(half);
long __const_func convert_long_rtp(half);
long __const_func convert_long_rtn(half);
long __const_func convert_long_rtz(half);
long __const_func convert_long_sat(half);
long __const_func convert_long_sat_rte(half);
long __const_func convert_long_sat_rtp(half);
long __const_func convert_long_sat_rtn(half);
long __const_func convert_long_sat_rtz(half);
long2 __const_func convert_long2(half2);
long2 __const_func convert_long2_rte(half2);
long2 __const_func convert_long2_rtp(half2);
long2 __const_func convert_long2_rtn(half2);
long2 __const_func convert_long2_rtz(half2);
long2 __const_func convert_long2_sat(half2);
long2 __const_func convert_long2_sat_rte(half2);
long2 __const_func convert_long2_sat_rtp(half2);
long2 __const_func convert_long2_sat_rtn(half2);
long2 __const_func convert_long2_sat_rtz(half2);
long3 __const_func convert_long3(half3);
long3 __const_func convert_long3_rte(half3);
long3 __const_func convert_long3_rtp(half3);
long3 __const_func convert_long3_rtn(half3);
long3 __const_func convert_long3_rtz(half3);
long3 __const_func convert_long3_sat(half3);
long3 __const_func convert_long3_sat_rte(half3);
long3 __const_func convert_long3_sat_rtp(half3);
long3 __const_func convert_long3_sat_rtn(half3);
long3 __const_func convert_long3_sat_rtz(half3);
long4 __const_func convert_long4(half4);
long4 __const_func convert_long4_rte(half4);
long4 __const_func convert_long4_rtp(half4);
long4 __const_func convert_long4_rtn(half4);
long4 __const_func convert_long4_rtz(half4);
long4 __const_func convert_long4_sat(half4);
long4 __const_func convert_long4_sat_rte(half4);
long4 __const_func convert_long4_sat_rtp(half4);
long4 __const_func convert_long4_sat_rtn(half4);
long4 __const_func convert_long4_sat_rtz(half4);
long8 __const_func convert_long8(half8);
long8 __const_func convert_long8_rte(half8);
long8 __const_func convert_long8_rtp(half8);
long8 __const_func convert_long8_rtn(half8);
long8 __const_func convert_long8_rtz(half8);
long8 __const_func convert_long8_sat(half8);
long8 __const_func convert_long8_sat_rte(half8);
long8 __const_func convert_long8_sat_rtp(half8);
long8 __const_func convert_long8_sat_rtn(half8);
long8 __const_func convert_long8_sat_rtz(half8);
long16 __const_func convert_long16(half16);
long16 __const_func convert_long16_rte(half16);
long16 __const_func convert_long16_rtp(half16);
long16 __const_func convert_long16_rtn(half16);
long16 __const_func convert_long16_rtz(half16);
long16 __const_func convert_long16_sat(half16);
long16 __const_func convert_long16_sat_rte(half16);
long16 __const_func convert_long16_sat_rtp(half16);
long16 __const_func convert_long16_sat_rtn(half16);
long16 __const_func convert_long16_sat_rtz(half16);
float __const_func convert_float(half);
float __const_func convert_float_rte(half);
float __const_func convert_float_rtp(half);
float __const_func convert_float_rtn(half);
float __const_func convert_float_rtz(half);
float2 __const_func convert_float2(half2);
float2 __const_func convert_float2_rte(half2);
float2 __const_func convert_float2_rtp(half2);
float2 __const_func convert_float2_rtn(half2);
float2 __const_func convert_float2_rtz(half2);
float3 __const_func convert_float3(half3);
float3 __const_func convert_float3_rte(half3);
float3 __const_func convert_float3_rtp(half3);
float3 __const_func convert_float3_rtn(half3);
float3 __const_func convert_float3_rtz(half3);
float4 __const_func convert_float4(half4);
float4 __const_func convert_float4_rte(half4);
float4 __const_func convert_float4_rtp(half4);
float4 __const_func convert_float4_rtn(half4);
float4 __const_func convert_float4_rtz(half4);
float8 __const_func convert_float8(half8);
float8 __const_func convert_float8_rte(half8);
float8 __const_func convert_float8_rtp(half8);
float8 __const_func convert_float8_rtn(half8);
float8 __const_func convert_float8_rtz(half8);
float16 __const_func convert_float16(half16);
float16 __const_func convert_float16_rte(half16);
float16 __const_func convert_float16_rtp(half16);
float16 __const_func convert_float16_rtn(half16);
float16 __const_func convert_float16_rtz(half16);

// Convert non-double types to half types.
half __const_func convert_half(uchar);
half __const_func convert_half(ushort);
half __const_func convert_half(uint);
half __const_func convert_half(ulong);
half __const_func convert_half(char);
half __const_func convert_half(short);
half __const_func convert_half(int);
half __const_func convert_half(long);
half __const_func convert_half(float);
half __const_func convert_half(half);
half __const_func convert_half_rte(uchar);
half __const_func convert_half_rte(ushort);
half __const_func convert_half_rte(uint);
half __const_func convert_half_rte(ulong);
half __const_func convert_half_rte(char);
half __const_func convert_half_rte(short);
half __const_func convert_half_rte(int);
half __const_func convert_half_rte(long);
half __const_func convert_half_rte(float);
half __const_func convert_half_rte(half);
half __const_func convert_half_rtp(uchar);
half __const_func convert_half_rtp(ushort);
half __const_func convert_half_rtp(uint);
half __const_func convert_half_rtp(ulong);
half __const_func convert_half_rtp(char);
half __const_func convert_half_rtp(short);
half __const_func convert_half_rtp(int);
half __const_func convert_half_rtp(long);
half __const_func convert_half_rtp(float);
half __const_func convert_half_rtp(half);
half __const_func convert_half_rtn(uchar);
half __const_func convert_half_rtn(ushort);
half __const_func convert_half_rtn(uint);
half __const_func convert_half_rtn(ulong);
half __const_func convert_half_rtn(char);
half __const_func convert_half_rtn(short);
half __const_func convert_half_rtn(int);
half __const_func convert_half_rtn(long);
half __const_func convert_half_rtn(float);
half __const_func convert_half_rtn(half);
half __const_func convert_half_rtz(uchar);
half __const_func convert_half_rtz(ushort);
half __const_func convert_half_rtz(uint);
half __const_func convert_half_rtz(ulong);
half __const_func convert_half_rtz(char);
half __const_func convert_half_rtz(short);
half __const_func convert_half_rtz(int);
half __const_func convert_half_rtz(long);
half __const_func convert_half_rtz(float);
half __const_func convert_half_rtz(half);
half2 __const_func convert_half2(char2);
half2 __const_func convert_half2(uchar2);
half2 __const_func convert_half2(short2);
half2 __const_func convert_half2(ushort2);
half2 __const_func convert_half2(int2);
half2 __const_func convert_half2(uint2);
half2 __const_func convert_half2(long2);
half2 __const_func convert_half2(ulong2);
half2 __const_func convert_half2(float2);
half2 __const_func convert_half2(half2);
half2 __const_func convert_half2_rte(char2);
half2 __const_func convert_half2_rte(uchar2);
half2 __const_func convert_half2_rte(short2);
half2 __const_func convert_half2_rte(ushort2);
half2 __const_func convert_half2_rte(int2);
half2 __const_func convert_half2_rte(uint2);
half2 __const_func convert_half2_rte(long2);
half2 __const_func convert_half2_rte(ulong2);
half2 __const_func convert_half2_rte(float2);
half2 __const_func convert_half2_rte(half2);
half2 __const_func convert_half2_rtp(char2);
half2 __const_func convert_half2_rtp(uchar2);
half2 __const_func convert_half2_rtp(short2);
half2 __const_func convert_half2_rtp(ushort2);
half2 __const_func convert_half2_rtp(int2);
half2 __const_func convert_half2_rtp(uint2);
half2 __const_func convert_half2_rtp(long2);
half2 __const_func convert_half2_rtp(ulong2);
half2 __const_func convert_half2_rtp(float2);
half2 __const_func convert_half2_rtp(half2);
half2 __const_func convert_half2_rtn(char2);
half2 __const_func convert_half2_rtn(uchar2);
half2 __const_func convert_half2_rtn(short2);
half2 __const_func convert_half2_rtn(ushort2);
half2 __const_func convert_half2_rtn(int2);
half2 __const_func convert_half2_rtn(uint2);
half2 __const_func convert_half2_rtn(long2);
half2 __const_func convert_half2_rtn(ulong2);
half2 __const_func convert_half2_rtn(float2);
half2 __const_func convert_half2_rtn(half2);
half2 __const_func convert_half2_rtz(char2);
half2 __const_func convert_half2_rtz(uchar2);
half2 __const_func convert_half2_rtz(short2);
half2 __const_func convert_half2_rtz(ushort2);
half2 __const_func convert_half2_rtz(int2);
half2 __const_func convert_half2_rtz(uint2);
half2 __const_func convert_half2_rtz(long2);
half2 __const_func convert_half2_rtz(ulong2);
half2 __const_func convert_half2_rtz(float2);
half2 __const_func convert_half2_rtz(half2);
half3 __const_func convert_half3(char3);
half3 __const_func convert_half3(uchar3);
half3 __const_func convert_half3(short3);
half3 __const_func convert_half3(ushort3);
half3 __const_func convert_half3(int3);
half3 __const_func convert_half3(uint3);
half3 __const_func convert_half3(long3);
half3 __const_func convert_half3(ulong3);
half3 __const_func convert_half3(float3);
half3 __const_func convert_half3(half3);
half3 __const_func convert_half3_rte(char3);
half3 __const_func convert_half3_rte(uchar3);
half3 __const_func convert_half3_rte(short3);
half3 __const_func convert_half3_rte(ushort3);
half3 __const_func convert_half3_rte(int3);
half3 __const_func convert_half3_rte(uint3);
half3 __const_func convert_half3_rte(long3);
half3 __const_func convert_half3_rte(ulong3);
half3 __const_func convert_half3_rte(float3);
half3 __const_func convert_half3_rte(half3);
half3 __const_func convert_half3_rtp(char3);
half3 __const_func convert_half3_rtp(uchar3);
half3 __const_func convert_half3_rtp(short3);
half3 __const_func convert_half3_rtp(ushort3);
half3 __const_func convert_half3_rtp(int3);
half3 __const_func convert_half3_rtp(uint3);
half3 __const_func convert_half3_rtp(long3);
half3 __const_func convert_half3_rtp(ulong3);
half3 __const_func convert_half3_rtp(float3);
half3 __const_func convert_half3_rtp(half3);
half3 __const_func convert_half3_rtn(char3);
half3 __const_func convert_half3_rtn(uchar3);
half3 __const_func convert_half3_rtn(short3);
half3 __const_func convert_half3_rtn(ushort3);
half3 __const_func convert_half3_rtn(int3);
half3 __const_func convert_half3_rtn(uint3);
half3 __const_func convert_half3_rtn(long3);
half3 __const_func convert_half3_rtn(ulong3);
half3 __const_func convert_half3_rtn(float3);
half3 __const_func convert_half3_rtn(half3);
half3 __const_func convert_half3_rtz(char3);
half3 __const_func convert_half3_rtz(uchar3);
half3 __const_func convert_half3_rtz(short3);
half3 __const_func convert_half3_rtz(ushort3);
half3 __const_func convert_half3_rtz(int3);
half3 __const_func convert_half3_rtz(uint3);
half3 __const_func convert_half3_rtz(long3);
half3 __const_func convert_half3_rtz(ulong3);
half3 __const_func convert_half3_rtz(float3);
half3 __const_func convert_half3_rtz(half3);
half4 __const_func convert_half4(char4);
half4 __const_func convert_half4(uchar4);
half4 __const_func convert_half4(short4);
half4 __const_func convert_half4(ushort4);
half4 __const_func convert_half4(int4);
half4 __const_func convert_half4(uint4);
half4 __const_func convert_half4(long4);
half4 __const_func convert_half4(ulong4);
half4 __const_func convert_half4(float4);
half4 __const_func convert_half4(half4);
half4 __const_func convert_half4_rte(char4);
half4 __const_func convert_half4_rte(uchar4);
half4 __const_func convert_half4_rte(short4);
half4 __const_func convert_half4_rte(ushort4);
half4 __const_func convert_half4_rte(int4);
half4 __const_func convert_half4_rte(uint4);
half4 __const_func convert_half4_rte(long4);
half4 __const_func convert_half4_rte(ulong4);
half4 __const_func convert_half4_rte(float4);
half4 __const_func convert_half4_rte(half4);
half4 __const_func convert_half4_rtp(char4);
half4 __const_func convert_half4_rtp(uchar4);
half4 __const_func convert_half4_rtp(short4);
half4 __const_func convert_half4_rtp(ushort4);
half4 __const_func convert_half4_rtp(int4);
half4 __const_func convert_half4_rtp(uint4);
half4 __const_func convert_half4_rtp(long4);
half4 __const_func convert_half4_rtp(ulong4);
half4 __const_func convert_half4_rtp(float4);
half4 __const_func convert_half4_rtp(half4);
half4 __const_func convert_half4_rtn(char4);
half4 __const_func convert_half4_rtn(uchar4);
half4 __const_func convert_half4_rtn(short4);
half4 __const_func convert_half4_rtn(ushort4);
half4 __const_func convert_half4_rtn(int4);
half4 __const_func convert_half4_rtn(uint4);
half4 __const_func convert_half4_rtn(long4);
half4 __const_func convert_half4_rtn(ulong4);
half4 __const_func convert_half4_rtn(float4);
half4 __const_func convert_half4_rtn(half4);
half4 __const_func convert_half4_rtz(char4);
half4 __const_func convert_half4_rtz(uchar4);
half4 __const_func convert_half4_rtz(short4);
half4 __const_func convert_half4_rtz(ushort4);
half4 __const_func convert_half4_rtz(int4);
half4 __const_func convert_half4_rtz(uint4);
half4 __const_func convert_half4_rtz(long4);
half4 __const_func convert_half4_rtz(ulong4);
half4 __const_func convert_half4_rtz(float4);
half4 __const_func convert_half4_rtz(half4);
half8 __const_func convert_half8(char8);
half8 __const_func convert_half8(uchar8);
half8 __const_func convert_half8(short8);
half8 __const_func convert_half8(ushort8);
half8 __const_func convert_half8(int8);
half8 __const_func convert_half8(uint8);
half8 __const_func convert_half8(long8);
half8 __const_func convert_half8(ulong8);
half8 __const_func convert_half8(float8);
half8 __const_func convert_half8(half8);
half8 __const_func convert_half8_rte(char8);
half8 __const_func convert_half8_rte(uchar8);
half8 __const_func convert_half8_rte(short8);
half8 __const_func convert_half8_rte(ushort8);
half8 __const_func convert_half8_rte(int8);
half8 __const_func convert_half8_rte(uint8);
half8 __const_func convert_half8_rte(long8);
half8 __const_func convert_half8_rte(ulong8);
half8 __const_func convert_half8_rte(float8);
half8 __const_func convert_half8_rte(half8);
half8 __const_func convert_half8_rtp(char8);
half8 __const_func convert_half8_rtp(uchar8);
half8 __const_func convert_half8_rtp(short8);
half8 __const_func convert_half8_rtp(ushort8);
half8 __const_func convert_half8_rtp(int8);
half8 __const_func convert_half8_rtp(uint8);
half8 __const_func convert_half8_rtp(long8);
half8 __const_func convert_half8_rtp(ulong8);
half8 __const_func convert_half8_rtp(float8);
half8 __const_func convert_half8_rtp(half8);
half8 __const_func convert_half8_rtn(char8);
half8 __const_func convert_half8_rtn(uchar8);
half8 __const_func convert_half8_rtn(short8);
half8 __const_func convert_half8_rtn(ushort8);
half8 __const_func convert_half8_rtn(int8);
half8 __const_func convert_half8_rtn(uint8);
half8 __const_func convert_half8_rtn(long8);
half8 __const_func convert_half8_rtn(ulong8);
half8 __const_func convert_half8_rtn(float8);
half8 __const_func convert_half8_rtn(half8);
half8 __const_func convert_half8_rtz(char8);
half8 __const_func convert_half8_rtz(uchar8);
half8 __const_func convert_half8_rtz(short8);
half8 __const_func convert_half8_rtz(ushort8);
half8 __const_func convert_half8_rtz(int8);
half8 __const_func convert_half8_rtz(uint8);
half8 __const_func convert_half8_rtz(long8);
half8 __const_func convert_half8_rtz(ulong8);
half8 __const_func convert_half8_rtz(float8);
half8 __const_func convert_half8_rtz(half8);
half16 __const_func convert_half16(char16);
half16 __const_func convert_half16(uchar16);
half16 __const_func convert_half16(short16);
half16 __const_func convert_half16(ushort16);
half16 __const_func convert_half16(int16);
half16 __const_func convert_half16(uint16);
half16 __const_func convert_half16(long16);
half16 __const_func convert_half16(ulong16);
half16 __const_func convert_half16(float16);
half16 __const_func convert_half16(half16);
half16 __const_func convert_half16_rte(char16);
half16 __const_func convert_half16_rte(uchar16);
half16 __const_func convert_half16_rte(short16);
half16 __const_func convert_half16_rte(ushort16);
half16 __const_func convert_half16_rte(int16);
half16 __const_func convert_half16_rte(uint16);
half16 __const_func convert_half16_rte(long16);
half16 __const_func convert_half16_rte(ulong16);
half16 __const_func convert_half16_rte(float16);
half16 __const_func convert_half16_rte(half16);
half16 __const_func convert_half16_rtp(char16);
half16 __const_func convert_half16_rtp(uchar16);
half16 __const_func convert_half16_rtp(short16);
half16 __const_func convert_half16_rtp(ushort16);
half16 __const_func convert_half16_rtp(int16);
half16 __const_func convert_half16_rtp(uint16);
half16 __const_func convert_half16_rtp(long16);
half16 __const_func convert_half16_rtp(ulong16);
half16 __const_func convert_half16_rtp(float16);
half16 __const_func convert_half16_rtp(half16);
half16 __const_func convert_half16_rtn(char16);
half16 __const_func convert_half16_rtn(uchar16);
half16 __const_func convert_half16_rtn(short16);
half16 __const_func convert_half16_rtn(ushort16);
half16 __const_func convert_half16_rtn(int16);
half16 __const_func convert_half16_rtn(uint16);
half16 __const_func convert_half16_rtn(long16);
half16 __const_func convert_half16_rtn(ulong16);
half16 __const_func convert_half16_rtn(float16);
half16 __const_func convert_half16_rtn(half16);
half16 __const_func convert_half16_rtz(char16);
half16 __const_func convert_half16_rtz(uchar16);
half16 __const_func convert_half16_rtz(short16);
half16 __const_func convert_half16_rtz(ushort16);
half16 __const_func convert_half16_rtz(int16);
half16 __const_func convert_half16_rtz(uint16);
half16 __const_func convert_half16_rtz(long16);
half16 __const_func convert_half16_rtz(ulong16);
half16 __const_func convert_half16_rtz(float16);
half16 __const_func convert_half16_rtz(half16);

// Convert half types to double types.
#ifdef cl_khr_fp64
double __const_func convert_double(half);
double __const_func convert_double_rte(half);
double __const_func convert_double_rtp(half);
double __const_func convert_double_rtn(half);
double __const_func convert_double_rtz(half);
double2 __const_func convert_double2(half2);
double2 __const_func convert_double2_rte(half2);
double2 __const_func convert_double2_rtp(half2);
double2 __const_func convert_double2_rtn(half2);
double2 __const_func convert_double2_rtz(half2);
double3 __const_func convert_double3(half3);
double3 __const_func convert_double3_rte(half3);
double3 __const_func convert_double3_rtp(half3);
double3 __const_func convert_double3_rtn(half3);
double3 __const_func convert_double3_rtz(half3);
double4 __const_func convert_double4(half4);
double4 __const_func convert_double4_rte(half4);
double4 __const_func convert_double4_rtp(half4);
double4 __const_func convert_double4_rtn(half4);
double4 __const_func convert_double4_rtz(half4);
double8 __const_func convert_double8(half8);
double8 __const_func convert_double8_rte(half8);
double8 __const_func convert_double8_rtp(half8);
double8 __const_func convert_double8_rtn(half8);
double8 __const_func convert_double8_rtz(half8);
double16 __const_func convert_double16(half16);
double16 __const_func convert_double16_rte(half16);
double16 __const_func convert_double16_rtp(half16);
double16 __const_func convert_double16_rtn(half16);
double16 __const_func convert_double16_rtz(half16);

// Convert double types to half types.
half __const_func convert_half(double);
half __const_func convert_half_rte(double);
half __const_func convert_half_rtp(double);
half __const_func convert_half_rtn(double);
half __const_func convert_half_rtz(double);
half2 __const_func convert_half2(double2);
half2 __const_func convert_half2_rte(double2);
half2 __const_func convert_half2_rtp(double2);
half2 __const_func convert_half2_rtn(double2);
half2 __const_func convert_half2_rtz(double2);
half3 __const_func convert_half3(double3);
half3 __const_func convert_half3_rte(double3);
half3 __const_func convert_half3_rtp(double3);
half3 __const_func convert_half3_rtn(double3);
half3 __const_func convert_half3_rtz(double3);
half4 __const_func convert_half4(double4);
half4 __const_func convert_half4_rte(double4);
half4 __const_func convert_half4_rtp(double4);
half4 __const_func convert_half4_rtn(double4);
half4 __const_func convert_half4_rtz(double4);
half8 __const_func convert_half8(double8);
half8 __const_func convert_half8_rte(double8);
half8 __const_func convert_half8_rtp(double8);
half8 __const_func convert_half8_rtn(double8);
half8 __const_func convert_half8_rtz(double8);
half16 __const_func convert_half16(double16);
half16 __const_func convert_half16_rte(double16);
half16 __const_func convert_half16_rtp(double16);
half16 __const_func convert_half16_rtn(double16);
half16 __const_func convert_half16_rtz(double16);
#endif //cl_khr_fp64

#endif // cl_khr_fp16

/**
 * OpenCL v1.1/1.2/2.0 s6.2.4.2 - as_type operators
 * Reinterprets a data type as another data type of the same size
 */
char __const_func as_char(char);
char __const_func as_char(uchar);

char2 __const_func as_char2(char2);
char2 __const_func as_char2(uchar2);
char2 __const_func as_char2(short);
char2 __const_func as_char2(ushort);

char3 __const_func as_char3(char3);
char3 __const_func as_char3(char4);
char3 __const_func as_char3(uchar3);
char3 __const_func as_char3(uchar4);
char3 __const_func as_char3(short2);
char3 __const_func as_char3(ushort2);
char3 __const_func as_char3(int);
char3 __const_func as_char3(uint);
char3 __const_func as_char3(float);

char4 __const_func as_char4(char3);
char4 __const_func as_char4(char4);
char4 __const_func as_char4(uchar3);
char4 __const_func as_char4(uchar4);
char4 __const_func as_char4(short2);
char4 __const_func as_char4(ushort2);
char4 __const_func as_char4(int);
char4 __const_func as_char4(uint);
char4 __const_func as_char4(float);

char8 __const_func as_char8(char8);
char8 __const_func as_char8(uchar8);
char8 __const_func as_char8(short3);
char8 __const_func as_char8(short4);
char8 __const_func as_char8(ushort3);
char8 __const_func as_char8(ushort4);
char8 __const_func as_char8(int2);
char8 __const_func as_char8(uint2);
char8 __const_func as_char8(long);
char8 __const_func as_char8(ulong);
char8 __const_func as_char8(float2);

char16 __const_func as_char16(char16);
char16 __const_func as_char16(uchar16);
char16 __const_func as_char16(short8);
char16 __const_func as_char16(ushort8);
char16 __const_func as_char16(int3);
char16 __const_func as_char16(int4);
char16 __const_func as_char16(uint3);
char16 __const_func as_char16(uint4);
char16 __const_func as_char16(long2);
char16 __const_func as_char16(ulong2);
char16 __const_func as_char16(float3);
char16 __const_func as_char16(float4);

uchar __const_func as_uchar(char);
uchar __const_func as_uchar(uchar);

uchar2 __const_func as_uchar2(char2);
uchar2 __const_func as_uchar2(uchar2);
uchar2 __const_func as_uchar2(short);
uchar2 __const_func as_uchar2(ushort);

uchar3 __const_func as_uchar3(char3);
uchar3 __const_func as_uchar3(char4);
uchar3 __const_func as_uchar3(uchar3);
uchar3 __const_func as_uchar3(uchar4);
uchar3 __const_func as_uchar3(short2);
uchar3 __const_func as_uchar3(ushort2);
uchar3 __const_func as_uchar3(int);
uchar3 __const_func as_uchar3(uint);
uchar3 __const_func as_uchar3(float);

uchar4 __const_func as_uchar4(char3);
uchar4 __const_func as_uchar4(char4);
uchar4 __const_func as_uchar4(uchar3);
uchar4 __const_func as_uchar4(uchar4);
uchar4 __const_func as_uchar4(short2);
uchar4 __const_func as_uchar4(ushort2);
uchar4 __const_func as_uchar4(int);
uchar4 __const_func as_uchar4(uint);
uchar4 __const_func as_uchar4(float);

uchar8 __const_func as_uchar8(char8);
uchar8 __const_func as_uchar8(uchar8);
uchar8 __const_func as_uchar8(short3);
uchar8 __const_func as_uchar8(short4);
uchar8 __const_func as_uchar8(ushort3);
uchar8 __const_func as_uchar8(ushort4);
uchar8 __const_func as_uchar8(int2);
uchar8 __const_func as_uchar8(uint2);
uchar8 __const_func as_uchar8(long);
uchar8 __const_func as_uchar8(ulong);
uchar8 __const_func as_uchar8(float2);

uchar16 __const_func as_uchar16(char16);
uchar16 __const_func as_uchar16(uchar16);
uchar16 __const_func as_uchar16(short8);
uchar16 __const_func as_uchar16(ushort8);
uchar16 __const_func as_uchar16(int3);
uchar16 __const_func as_uchar16(int4);
uchar16 __const_func as_uchar16(uint3);
uchar16 __const_func as_uchar16(uint4);
uchar16 __const_func as_uchar16(long2);
uchar16 __const_func as_uchar16(ulong2);
uchar16 __const_func as_uchar16(float3);
uchar16 __const_func as_uchar16(float4);

short __const_func as_short(char2);
short __const_func as_short(uchar2);
short __const_func as_short(short);
short __const_func as_short(ushort);

short2 __const_func as_short2(char3);
short2 __const_func as_short2(char4);
short2 __const_func as_short2(uchar3);
short2 __const_func as_short2(uchar4);
short2 __const_func as_short2(short2);
short2 __const_func as_short2(ushort2);
short2 __const_func as_short2(int);
short2 __const_func as_short2(uint);
short2 __const_func as_short2(float);

short3 __const_func as_short3(char8);
short3 __const_func as_short3(uchar8);
short3 __const_func as_short3(short3);
short3 __const_func as_short3(short4);
short3 __const_func as_short3(ushort3);
short3 __const_func as_short3(ushort4);
short3 __const_func as_short3(int2);
short3 __const_func as_short3(uint2);
short3 __const_func as_short3(long);
short3 __const_func as_short3(ulong);
short3 __const_func as_short3(float2);

short4 __const_func as_short4(char8);
short4 __const_func as_short4(uchar8);
short4 __const_func as_short4(short3);
short4 __const_func as_short4(short4);
short4 __const_func as_short4(ushort3);
short4 __const_func as_short4(ushort4);
short4 __const_func as_short4(int2);
short4 __const_func as_short4(uint2);
short4 __const_func as_short4(long);
short4 __const_func as_short4(ulong);
short4 __const_func as_short4(float2);

short8 __const_func as_short8(char16);
short8 __const_func as_short8(uchar16);
short8 __const_func as_short8(short8);
short8 __const_func as_short8(ushort8);
short8 __const_func as_short8(int3);
short8 __const_func as_short8(int4);
short8 __const_func as_short8(uint3);
short8 __const_func as_short8(uint4);
short8 __const_func as_short8(long2);
short8 __const_func as_short8(ulong2);
short8 __const_func as_short8(float3);
short8 __const_func as_short8(float4);

short16 __const_func as_short16(short16);
short16 __const_func as_short16(ushort16);
short16 __const_func as_short16(int8);
short16 __const_func as_short16(uint8);
short16 __const_func as_short16(long3);
short16 __const_func as_short16(long4);
short16 __const_func as_short16(ulong3);
short16 __const_func as_short16(ulong4);
short16 __const_func as_short16(float8);

ushort __const_func as_ushort(char2);
ushort __const_func as_ushort(uchar2);
ushort __const_func as_ushort(short);
ushort __const_func as_ushort(ushort);

ushort2 __const_func as_ushort2(char3);
ushort2 __const_func as_ushort2(char4);
ushort2 __const_func as_ushort2(uchar3);
ushort2 __const_func as_ushort2(uchar4);
ushort2 __const_func as_ushort2(short2);
ushort2 __const_func as_ushort2(ushort2);
ushort2 __const_func as_ushort2(int);
ushort2 __const_func as_ushort2(uint);
ushort2 __const_func as_ushort2(float);

ushort3 __const_func as_ushort3(char8);
ushort3 __const_func as_ushort3(uchar8);
ushort3 __const_func as_ushort3(short3);
ushort3 __const_func as_ushort3(short4);
ushort3 __const_func as_ushort3(ushort3);
ushort3 __const_func as_ushort3(ushort4);
ushort3 __const_func as_ushort3(int2);
ushort3 __const_func as_ushort3(uint2);
ushort3 __const_func as_ushort3(long);
ushort3 __const_func as_ushort3(ulong);
ushort3 __const_func as_ushort3(float2);

ushort4 __const_func as_ushort4(char8);
ushort4 __const_func as_ushort4(uchar8);
ushort4 __const_func as_ushort4(short3);
ushort4 __const_func as_ushort4(short4);
ushort4 __const_func as_ushort4(ushort3);
ushort4 __const_func as_ushort4(ushort4);
ushort4 __const_func as_ushort4(int2);
ushort4 __const_func as_ushort4(uint2);
ushort4 __const_func as_ushort4(long);
ushort4 __const_func as_ushort4(ulong);
ushort4 __const_func as_ushort4(float2);

ushort8 __const_func as_ushort8(char16);
ushort8 __const_func as_ushort8(uchar16);
ushort8 __const_func as_ushort8(short8);
ushort8 __const_func as_ushort8(ushort8);
ushort8 __const_func as_ushort8(int3);
ushort8 __const_func as_ushort8(int4);
ushort8 __const_func as_ushort8(uint3);
ushort8 __const_func as_ushort8(uint4);
ushort8 __const_func as_ushort8(long2);
ushort8 __const_func as_ushort8(ulong2);
ushort8 __const_func as_ushort8(float3);
ushort8 __const_func as_ushort8(float4);

ushort16 __const_func as_ushort16(short16);
ushort16 __const_func as_ushort16(ushort16);
ushort16 __const_func as_ushort16(int8);
ushort16 __const_func as_ushort16(uint8);
ushort16 __const_func as_ushort16(long3);
ushort16 __const_func as_ushort16(long4);
ushort16 __const_func as_ushort16(ulong3);
ushort16 __const_func as_ushort16(ulong4);
ushort16 __const_func as_ushort16(float8);

int __const_func as_int(char3);
int __const_func as_int(char4);
int __const_func as_int(uchar3);
int __const_func as_int(uchar4);
int __const_func as_int(short2);
int __const_func as_int(ushort2);
int __const_func as_int(int);
int __const_func as_int(uint);
int __const_func as_int(float);

int2 __const_func as_int2(char8);
int2 __const_func as_int2(uchar8);
int2 __const_func as_int2(short3);
int2 __const_func as_int2(short4);
int2 __const_func as_int2(ushort3);
int2 __const_func as_int2(ushort4);
int2 __const_func as_int2(int2);
int2 __const_func as_int2(uint2);
int2 __const_func as_int2(long);
int2 __const_func as_int2(ulong);
int2 __const_func as_int2(float2);

int3 __const_func as_int3(char16);
int3 __const_func as_int3(uchar16);
int3 __const_func as_int3(short8);
int3 __const_func as_int3(ushort8);
int3 __const_func as_int3(int3);
int3 __const_func as_int3(int4);
int3 __const_func as_int3(uint3);
int3 __const_func as_int3(uint4);
int3 __const_func as_int3(long2);
int3 __const_func as_int3(ulong2);
int3 __const_func as_int3(float3);
int3 __const_func as_int3(float4);

int4 __const_func as_int4(char16);
int4 __const_func as_int4(uchar16);
int4 __const_func as_int4(short8);
int4 __const_func as_int4(ushort8);
int4 __const_func as_int4(int3);
int4 __const_func as_int4(int4);
int4 __const_func as_int4(uint3);
int4 __const_func as_int4(uint4);
int4 __const_func as_int4(long2);
int4 __const_func as_int4(ulong2);
int4 __const_func as_int4(float3);
int4 __const_func as_int4(float4);

int8 __const_func as_int8(short16);
int8 __const_func as_int8(ushort16);
int8 __const_func as_int8(int8);
int8 __const_func as_int8(uint8);
int8 __const_func as_int8(long3);
int8 __const_func as_int8(long4);
int8 __const_func as_int8(ulong3);
int8 __const_func as_int8(ulong4);
int8 __const_func as_int8(float8);

int16 __const_func as_int16(int16);
int16 __const_func as_int16(uint16);
int16 __const_func as_int16(long8);
int16 __const_func as_int16(ulong8);
int16 __const_func as_int16(float16);

uint __const_func as_uint(char3);
uint __const_func as_uint(char4);
uint __const_func as_uint(uchar3);
uint __const_func as_uint(uchar4);
uint __const_func as_uint(short2);
uint __const_func as_uint(ushort2);
uint __const_func as_uint(int);
uint __const_func as_uint(uint);
uint __const_func as_uint(float);

uint2 __const_func as_uint2(char8);
uint2 __const_func as_uint2(uchar8);
uint2 __const_func as_uint2(short3);
uint2 __const_func as_uint2(short4);
uint2 __const_func as_uint2(ushort3);
uint2 __const_func as_uint2(ushort4);
uint2 __const_func as_uint2(int2);
uint2 __const_func as_uint2(uint2);
uint2 __const_func as_uint2(long);
uint2 __const_func as_uint2(ulong);
uint2 __const_func as_uint2(float2);

uint3 __const_func as_uint3(char16);
uint3 __const_func as_uint3(uchar16);
uint3 __const_func as_uint3(short8);
uint3 __const_func as_uint3(ushort8);
uint3 __const_func as_uint3(int3);
uint3 __const_func as_uint3(int4);
uint3 __const_func as_uint3(uint3);
uint3 __const_func as_uint3(uint4);
uint3 __const_func as_uint3(long2);
uint3 __const_func as_uint3(ulong2);
uint3 __const_func as_uint3(float3);
uint3 __const_func as_uint3(float4);

uint4 __const_func as_uint4(char16);
uint4 __const_func as_uint4(uchar16);
uint4 __const_func as_uint4(short8);
uint4 __const_func as_uint4(ushort8);
uint4 __const_func as_uint4(int3);
uint4 __const_func as_uint4(int4);
uint4 __const_func as_uint4(uint3);
uint4 __const_func as_uint4(uint4);
uint4 __const_func as_uint4(long2);
uint4 __const_func as_uint4(ulong2);
uint4 __const_func as_uint4(float3);
uint4 __const_func as_uint4(float4);

uint8 __const_func as_uint8(short16);
uint8 __const_func as_uint8(ushort16);
uint8 __const_func as_uint8(int8);
uint8 __const_func as_uint8(uint8);
uint8 __const_func as_uint8(long3);
uint8 __const_func as_uint8(long4);
uint8 __const_func as_uint8(ulong3);
uint8 __const_func as_uint8(ulong4);
uint8 __const_func as_uint8(float8);

uint16 __const_func as_uint16(int16);
uint16 __const_func as_uint16(uint16);
uint16 __const_func as_uint16(long8);
uint16 __const_func as_uint16(ulong8);
uint16 __const_func as_uint16(float16);

long __const_func as_long(char8);
long __const_func as_long(uchar8);
long __const_func as_long(short3);
long __const_func as_long(short4);
long __const_func as_long(ushort3);
long __const_func as_long(ushort4);
long __const_func as_long(int2);
long __const_func as_long(uint2);
long __const_func as_long(long);
long __const_func as_long(ulong);
long __const_func as_long(float2);

long2 __const_func as_long2(char16);
long2 __const_func as_long2(uchar16);
long2 __const_func as_long2(short8);
long2 __const_func as_long2(ushort8);
long2 __const_func as_long2(int3);
long2 __const_func as_long2(int4);
long2 __const_func as_long2(uint3);
long2 __const_func as_long2(uint4);
long2 __const_func as_long2(long2);
long2 __const_func as_long2(ulong2);
long2 __const_func as_long2(float3);
long2 __const_func as_long2(float4);

long3 __const_func as_long3(short16);
long3 __const_func as_long3(ushort16);
long3 __const_func as_long3(int8);
long3 __const_func as_long3(uint8);
long3 __const_func as_long3(long3);
long3 __const_func as_long3(long4);
long3 __const_func as_long3(ulong3);
long3 __const_func as_long3(ulong4);
long3 __const_func as_long3(float8);

long4 __const_func as_long4(short16);
long4 __const_func as_long4(ushort16);
long4 __const_func as_long4(int8);
long4 __const_func as_long4(uint8);
long4 __const_func as_long4(long3);
long4 __const_func as_long4(long4);
long4 __const_func as_long4(ulong3);
long4 __const_func as_long4(ulong4);
long4 __const_func as_long4(float8);

long8 __const_func as_long8(int16);
long8 __const_func as_long8(uint16);
long8 __const_func as_long8(long8);
long8 __const_func as_long8(ulong8);
long8 __const_func as_long8(float16);

long16 __const_func as_long16(long16);
long16 __const_func as_long16(ulong16);

ulong __const_func as_ulong(char8);
ulong __const_func as_ulong(uchar8);
ulong __const_func as_ulong(short3);
ulong __const_func as_ulong(short4);
ulong __const_func as_ulong(ushort3);
ulong __const_func as_ulong(ushort4);
ulong __const_func as_ulong(int2);
ulong __const_func as_ulong(uint2);
ulong __const_func as_ulong(long);
ulong __const_func as_ulong(ulong);
ulong __const_func as_ulong(float2);

ulong2 __const_func as_ulong2(char16);
ulong2 __const_func as_ulong2(uchar16);
ulong2 __const_func as_ulong2(short8);
ulong2 __const_func as_ulong2(ushort8);
ulong2 __const_func as_ulong2(int3);
ulong2 __const_func as_ulong2(int4);
ulong2 __const_func as_ulong2(uint3);
ulong2 __const_func as_ulong2(uint4);
ulong2 __const_func as_ulong2(long2);
ulong2 __const_func as_ulong2(ulong2);
ulong2 __const_func as_ulong2(float3);
ulong2 __const_func as_ulong2(float4);

ulong3 __const_func as_ulong3(short16);
ulong3 __const_func as_ulong3(ushort16);
ulong3 __const_func as_ulong3(int8);
ulong3 __const_func as_ulong3(uint8);
ulong3 __const_func as_ulong3(long3);
ulong3 __const_func as_ulong3(long4);
ulong3 __const_func as_ulong3(ulong3);
ulong3 __const_func as_ulong3(ulong4);
ulong3 __const_func as_ulong3(float8);

ulong4 __const_func as_ulong4(short16);
ulong4 __const_func as_ulong4(ushort16);
ulong4 __const_func as_ulong4(int8);
ulong4 __const_func as_ulong4(uint8);
ulong4 __const_func as_ulong4(long3);
ulong4 __const_func as_ulong4(long4);
ulong4 __const_func as_ulong4(ulong3);
ulong4 __const_func as_ulong4(ulong4);
ulong4 __const_func as_ulong4(float8);

ulong8 __const_func as_ulong8(int16);
ulong8 __const_func as_ulong8(uint16);
ulong8 __const_func as_ulong8(long8);
ulong8 __const_func as_ulong8(ulong8);
ulong8 __const_func as_ulong8(float16);

ulong16 __const_func as_ulong16(long16);
ulong16 __const_func as_ulong16(ulong16);

float __const_func as_float(char3);
float __const_func as_float(char4);
float __const_func as_float(uchar3);
float __const_func as_float(uchar4);
float __const_func as_float(short2);
float __const_func as_float(ushort2);
float __const_func as_float(int);
float __const_func as_float(uint);
float __const_func as_float(float);

float2 __const_func as_float2(char8);
float2 __const_func as_float2(uchar8);
float2 __const_func as_float2(short3);
float2 __const_func as_float2(short4);
float2 __const_func as_float2(ushort3);
float2 __const_func as_float2(ushort4);
float2 __const_func as_float2(int2);
float2 __const_func as_float2(uint2);
float2 __const_func as_float2(long);
float2 __const_func as_float2(ulong);
float2 __const_func as_float2(float2);

float3 __const_func as_float3(char16);
float3 __const_func as_float3(uchar16);
float3 __const_func as_float3(short8);
float3 __const_func as_float3(ushort8);
float3 __const_func as_float3(int3);
float3 __const_func as_float3(int4);
float3 __const_func as_float3(uint3);
float3 __const_func as_float3(uint4);
float3 __const_func as_float3(long2);
float3 __const_func as_float3(ulong2);
float3 __const_func as_float3(float3);
float3 __const_func as_float3(float4);

float4 __const_func as_float4(char16);
float4 __const_func as_float4(uchar16);
float4 __const_func as_float4(short8);
float4 __const_func as_float4(ushort8);
float4 __const_func as_float4(int3);
float4 __const_func as_float4(int4);
float4 __const_func as_float4(uint3);
float4 __const_func as_float4(uint4);
float4 __const_func as_float4(long2);
float4 __const_func as_float4(ulong2);
float4 __const_func as_float4(float3);
float4 __const_func as_float4(float4);

float8 __const_func as_float8(short16);
float8 __const_func as_float8(ushort16);
float8 __const_func as_float8(int8);
float8 __const_func as_float8(uint8);
float8 __const_func as_float8(long3);
float8 __const_func as_float8(long4);
float8 __const_func as_float8(ulong3);
float8 __const_func as_float8(ulong4);
float8 __const_func as_float8(float8);

float16 __const_func as_float16(int16);
float16 __const_func as_float16(uint16);
float16 __const_func as_float16(long8);
float16 __const_func as_float16(ulong8);
float16 __const_func as_float16(float16);

#ifdef cl_khr_fp64
char8 __const_func as_char8(double);
char16 __const_func as_char16(double2);
uchar8 __const_func as_uchar8(double);
uchar16 __const_func as_uchar16(double2);
short3 __const_func as_short3(double);
short4 __const_func as_short4(double);
short8 __const_func as_short8(double2);
short16 __const_func as_short16(double3);
short16 __const_func as_short16(double4);
ushort3 __const_func as_ushort3(double);
ushort4 __const_func as_ushort4(double);
ushort8 __const_func as_ushort8(double2);
ushort16 __const_func as_ushort16(double3);
ushort16 __const_func as_ushort16(double4);
int2 __const_func as_int2(double);
int3 __const_func as_int3(double2);
int4 __const_func as_int4(double2);
int8 __const_func as_int8(double3);
int8 __const_func as_int8(double4);
int16 __const_func as_int16(double8);
uint2 __const_func as_uint2(double);
uint3 __const_func as_uint3(double2);
uint4 __const_func as_uint4(double2);
uint8 __const_func as_uint8(double3);
uint8 __const_func as_uint8(double4);
uint16 __const_func as_uint16(double8);
long __const_func as_long(double);
long2 __const_func as_long2(double2);
long3 __const_func as_long3(double3);
long3 __const_func as_long3(double4);
long4 __const_func as_long4(double3);
long4 __const_func as_long4(double4);
long8 __const_func as_long8(double8);
long16 __const_func as_long16(double16);
ulong __const_func as_ulong(double);
ulong2 __const_func as_ulong2(double2);
ulong3 __const_func as_ulong3(double3);
ulong3 __const_func as_ulong3(double4);
ulong4 __const_func as_ulong4(double3);
ulong4 __const_func as_ulong4(double4);
ulong8 __const_func as_ulong8(double8);
ulong16 __const_func as_ulong16(double16);
float2 __const_func as_float2(double);
float3 __const_func as_float3(double2);
float4 __const_func as_float4(double2);
float8 __const_func as_float8(double3);
float8 __const_func as_float8(double4);
float16 __const_func as_float16(double8);
double __const_func as_double(char8);
double __const_func as_double(uchar8);
double __const_func as_double(short3);
double __const_func as_double(short4);
double __const_func as_double(ushort3);
double __const_func as_double(ushort4);
double __const_func as_double(int2);
double __const_func as_double(uint2);
double __const_func as_double(long);
double __const_func as_double(ulong);
double __const_func as_double(float2);
double __const_func as_double(double);
double2 __const_func as_double2(char16);
double2 __const_func as_double2(uchar16);
double2 __const_func as_double2(short8);
double2 __const_func as_double2(ushort8);
double2 __const_func as_double2(int3);
double2 __const_func as_double2(int4);
double2 __const_func as_double2(uint3);
double2 __const_func as_double2(uint4);
double2 __const_func as_double2(long2);
double2 __const_func as_double2(ulong2);
double2 __const_func as_double2(float3);
double2 __const_func as_double2(float4);
double2 __const_func as_double2(double2);
double3 __const_func as_double3(short16);
double3 __const_func as_double3(ushort16);
double3 __const_func as_double3(int8);
double3 __const_func as_double3(uint8);
double3 __const_func as_double3(long3);
double3 __const_func as_double3(long4);
double3 __const_func as_double3(ulong3);
double3 __const_func as_double3(ulong4);
double3 __const_func as_double3(float8);
double3 __const_func as_double3(double3);
double3 __const_func as_double3(double4);
double4 __const_func as_double4(short16);
double4 __const_func as_double4(ushort16);
double4 __const_func as_double4(int8);
double4 __const_func as_double4(uint8);
double4 __const_func as_double4(long3);
double4 __const_func as_double4(long4);
double4 __const_func as_double4(ulong3);
double4 __const_func as_double4(ulong4);
double4 __const_func as_double4(float8);
double4 __const_func as_double4(double3);
double4 __const_func as_double4(double4);
double8 __const_func as_double8(int16);
double8 __const_func as_double8(uint16);
double8 __const_func as_double8(long8);
double8 __const_func as_double8(ulong8);
double8 __const_func as_double8(float16);
double8 __const_func as_double8(double8);
double16 __const_func as_double16(long16);
double16 __const_func as_double16(ulong16);
double16 __const_func as_double16(double16);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
char2 __const_func as_char2(half);
char3 __const_func as_char3(half2);
char4 __const_func as_char4(half2);
char8 __const_func as_char8(half3);
char8 __const_func as_char8(half4);
char16 __const_func as_char16(half8);
uchar2 __const_func as_uchar2(half);
uchar3 __const_func as_uchar3(half2);
uchar4 __const_func as_uchar4(half2);
uchar8 __const_func as_uchar8(half3);
uchar8 __const_func as_uchar8(half4);
uchar16 __const_func as_uchar16(half8);
short __const_func as_short(half);
short2 __const_func as_short2(half2);
short3 __const_func as_short3(half3);
short3 __const_func as_short3(half4);
short4 __const_func as_short4(half3);
short4 __const_func as_short4(half4);
short8 __const_func as_short8(half8);
short16 __const_func as_short16(half16);
ushort __const_func as_ushort(half);
ushort2 __const_func as_ushort2(half2);
ushort3 __const_func as_ushort3(half3);
ushort3 __const_func as_ushort3(half4);
ushort4 __const_func as_ushort4(half3);
ushort4 __const_func as_ushort4(half4);
ushort8 __const_func as_ushort8(half8);
ushort16 __const_func as_ushort16(half16);
int __const_func as_int(half2);
int2 __const_func as_int2(half3);
int2 __const_func as_int2(half4);
int3 __const_func as_int3(half8);
int4 __const_func as_int4(half8);
int8 __const_func as_int8(half16);
uint __const_func as_uint(half2);
uint2 __const_func as_uint2(half3);
uint2 __const_func as_uint2(half4);
uint3 __const_func as_uint3(half8);
uint4 __const_func as_uint4(half8);
uint8 __const_func as_uint8(half16);
long __const_func as_long(half3);
long __const_func as_long(half4);
long2 __const_func as_long2(half8);
long3 __const_func as_long3(half16);
long4 __const_func as_long4(half16);
ulong __const_func as_ulong(half3);
ulong __const_func as_ulong(half4);
ulong2 __const_func as_ulong2(half8);
ulong3 __const_func as_ulong3(half16);
ulong4 __const_func as_ulong4(half16);
half __const_func as_half(char2);
half __const_func as_half(uchar2);
half __const_func as_half(short);
half __const_func as_half(ushort);
half __const_func as_half(half);
half2 __const_func as_half2(char3);
half2 __const_func as_half2(char4);
half2 __const_func as_half2(uchar3);
half2 __const_func as_half2(uchar4);
half2 __const_func as_half2(short2);
half2 __const_func as_half2(ushort2);
half2 __const_func as_half2(int);
half2 __const_func as_half2(uint);
half2 __const_func as_half2(half2);
half2 __const_func as_half2(float);
half3 __const_func as_half3(char8);
half3 __const_func as_half3(uchar8);
half3 __const_func as_half3(short3);
half3 __const_func as_half3(short4);
half3 __const_func as_half3(ushort3);
half3 __const_func as_half3(ushort4);
half3 __const_func as_half3(int2);
half3 __const_func as_half3(uint2);
half3 __const_func as_half3(long);
half3 __const_func as_half3(ulong);
half3 __const_func as_half3(half3);
half3 __const_func as_half3(half4);
half3 __const_func as_half3(float2);
half4 __const_func as_half4(char8);
half4 __const_func as_half4(uchar8);
half4 __const_func as_half4(short3);
half4 __const_func as_half4(short4);
half4 __const_func as_half4(ushort3);
half4 __const_func as_half4(ushort4);
half4 __const_func as_half4(int2);
half4 __const_func as_half4(uint2);
half4 __const_func as_half4(long);
half4 __const_func as_half4(ulong);
half4 __const_func as_half4(half3);
half4 __const_func as_half4(half4);
half4 __const_func as_half4(float2);
half8 __const_func as_half8(char16);
half8 __const_func as_half8(uchar16);
half8 __const_func as_half8(short8);
half8 __const_func as_half8(ushort8);
half8 __const_func as_half8(int3);
half8 __const_func as_half8(int4);
half8 __const_func as_half8(uint3);
half8 __const_func as_half8(uint4);
half8 __const_func as_half8(long2);
half8 __const_func as_half8(ulong2);
half8 __const_func as_half8(half8);
half8 __const_func as_half8(float3);
half8 __const_func as_half8(float4);
half16 __const_func as_half16(short16);
half16 __const_func as_half16(ushort16);
half16 __const_func as_half16(int8);
half16 __const_func as_half16(uint8);
half16 __const_func as_half16(long3);
half16 __const_func as_half16(long4);
half16 __const_func as_half16(ulong3);
half16 __const_func as_half16(ulong4);
half16 __const_func as_half16(half16);
half16 __const_func as_half16(float8);
float __const_func as_float(half2);
float2 __const_func as_float2(half3);
float2 __const_func as_float2(half4);
float3 __const_func as_float3(half8);
float4 __const_func as_float4(half8);
float8 __const_func as_float8(half16);

#ifdef cl_khr_fp64
half3 __const_func as_half3(double);
half4 __const_func as_half4(double);
half8 __const_func as_half8(double2);
half16 __const_func as_half16(double3);
half16 __const_func as_half16(double4);
double __const_func as_double(half3);
double __const_func as_double(half4);
double2 __const_func as_double2(half8);
double3 __const_func as_double3(half16);
double4 __const_func as_double4(half16);
#endif //cl_khr_fp64
#endif //cl_khr_fp16

// OpenCL v1.1 s6.9, v1.2/2.0 s6.10 - Function qualifiers

#define __kernel_exec(X, typen) __kernel \
	__attribute__((work_group_size_hint(X, 1, 1))) \
	__attribute__((vec_type_hint(typen)))

#define kernel_exec(X, typen) __kernel \
	__attribute__((work_group_size_hint(X, 1, 1))) \
	__attribute__((vec_type_hint(typen)))

// OpenCL v1.1 s6.11.1, v1.2 s6.12.1, v2.0 s6.13.1 - Work-item Functions

/**
 * Returns the number of dimensions in use. This is the
 * value given to the work_dim argument specified in
 * clEnqueueNDRangeKernel.
 * For clEnqueueTask, this returns 1.
 */
uint __const_func get_work_dim(void);

/**
 * Returns the number of global work-items specified for
 * dimension identified by dimindx. This value is given by
 * the global_work_size argument to
 * clEnqueueNDRangeKernel. Valid values of dimindx
 * are 0 to get_work_dim() - 1. For other values of
 * dimindx, get_global_size() returns 1.
 * For clEnqueueTask, this always returns 1.
 */
size_t __const_func get_global_size(uint dimindx);

/**
 * Returns the unique global work-item ID value for
 * dimension identified by dimindx. The global work-item
 * ID specifies the work-item ID based on the number of
 * global work-items specified to execute the kernel. Valid
 * values of dimindx are 0 to get_work_dim() - 1. For
 * other values of dimindx, get_global_id() returns 0.
 * For clEnqueueTask, this returns 0.
 */
size_t __const_func get_global_id(uint dimindx);

/**
 * Returns the number of local work-items specified in
 * dimension identified by dimindx. This value is given by
 * the local_work_size argument to
 * clEnqueueNDRangeKernel if local_work_size is not
 * NULL; otherwise the OpenCL implementation chooses
 * an appropriate local_work_size value which is returned
 * by this function. Valid values of dimindx are 0 to
 * get_work_dim() - 1. For other values of dimindx,
 * get_local_size() returns 1.
 * For clEnqueueTask, this always returns 1.
 */
size_t __const_func get_local_size(uint dimindx);

/**
 * Returns the unique local work-item ID i.e. a work-item
 * within a specific work-group for dimension identified by
 * dimindx. Valid values of dimindx are 0 to
 * get_work_dim() - 1. For other values of dimindx,
 * get_local_id() returns 0.
 * For clEnqueueTask, this returns 0.
 */
size_t __const_func get_local_id(uint dimindx);

/**
 * Returns the number of work-groups that will execute a
 * kernel for dimension identified by dimindx.
 * Valid values of dimindx are 0 to get_work_dim() - 1.
 * For other values of dimindx, get_num_groups () returns
 * 1.
 * For clEnqueueTask, this always returns 1.
 */
size_t __const_func get_num_groups(uint dimindx);

/**
 * get_group_id returns the work-group ID which is a
 * number from 0 .. get_num_groups(dimindx) - 1.
 * Valid values of dimindx are 0 to get_work_dim() - 1.
 * For other values, get_group_id() returns 0.
 * For clEnqueueTask, this returns 0.
 */
size_t __const_func get_group_id(uint dimindx);

/**
 * get_global_offset returns the offset values specified in
 * global_work_offset argument to
 * clEnqueueNDRangeKernel.
 * Valid values of dimindx are 0 to get_work_dim() - 1.
 * For other values, get_global_offset() returns 0.
 * For clEnqueueTask, this returns 0.
 */
size_t __const_func get_global_offset(uint dimindx);

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
size_t __overload get_enqueued_local_size(uint dimindx);
size_t __overload get_global_linear_id(void);
size_t __overload get_local_linear_id(void);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL v1.1 s6.11.2, v1.2 s6.12.2, v2.0 s6.13.2 - Math functions

/**
 * Arc cosine function.
 */
float __const_func acos(float);
float2 __const_func acos(float2);
float3 __const_func acos(float3);
float4 __const_func acos(float4);
float8 __const_func acos(float8);
float16 __const_func acos(float16);
#ifdef cl_khr_fp64
double __const_func acos(double);
double2 __const_func acos(double2);
double3 __const_func acos(double3);
double4 __const_func acos(double4);
double8 __const_func acos(double8);
double16 __const_func acos(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func acos(half);
half2 __const_func acos(half2);
half3 __const_func acos(half3);
half4 __const_func acos(half4);
half8 __const_func acos(half8);
half16 __const_func acos(half16);
#endif //cl_khr_fp16

/**
 * Inverse hyperbolic cosine.
 */
float __const_func acosh(float);
float2 __const_func acosh(float2);
float3 __const_func acosh(float3);
float4 __const_func acosh(float4);
float8 __const_func acosh(float8);
float16 __const_func acosh(float16);
#ifdef cl_khr_fp64
double __const_func acosh(double);
double2 __const_func acosh(double2);
double3 __const_func acosh(double3);
double4 __const_func acosh(double4);
double8 __const_func acosh(double8);
double16 __const_func acosh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func acosh(half);
half2 __const_func acosh(half2);
half3 __const_func acosh(half3);
half4 __const_func acosh(half4);
half8 __const_func acosh(half8);
half16 __const_func acosh(half16);
#endif //cl_khr_fp16

/**
 * Compute acos (x) / PI.
 */
float __const_func acospi(float x);
float2 __const_func acospi(float2 x);
float3 __const_func acospi(float3 x);
float4 __const_func acospi(float4 x);
float8 __const_func acospi(float8 x);
float16 __const_func acospi(float16 x);
#ifdef cl_khr_fp64
double __const_func acospi(double x);
double2 __const_func acospi(double2 x);
double3 __const_func acospi(double3 x);
double4 __const_func acospi(double4 x);
double8 __const_func acospi(double8 x);
double16 __const_func acospi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func acospi(half x);
half2 __const_func acospi(half2 x);
half3 __const_func acospi(half3 x);
half4 __const_func acospi(half4 x);
half8 __const_func acospi(half8 x);
half16 __const_func acospi(half16 x);
#endif //cl_khr_fp16

/**
 * Arc sine function.
 */
float __const_func asin(float);
float2 __const_func asin(float2);
float3 __const_func asin(float3);
float4 __const_func asin(float4);
float8 __const_func asin(float8);
float16 __const_func asin(float16);
#ifdef cl_khr_fp64
double __const_func asin(double);
double2 __const_func asin(double2);
double3 __const_func asin(double3);
double4 __const_func asin(double4);
double8 __const_func asin(double8);
double16 __const_func asin(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func asin(half);
half2 __const_func asin(half2);
half3 __const_func asin(half3);
half4 __const_func asin(half4);
half8 __const_func asin(half8);
half16 __const_func asin(half16);
#endif //cl_khr_fp16

/**
 * Inverse hyperbolic sine.
 */
float __const_func asinh(float);
float2 __const_func asinh(float2);
float3 __const_func asinh(float3);
float4 __const_func asinh(float4);
float8 __const_func asinh(float8);
float16 __const_func asinh(float16);
#ifdef cl_khr_fp64
double __const_func asinh(double);
double2 __const_func asinh(double2);
double3 __const_func asinh(double3);
double4 __const_func asinh(double4);
double8 __const_func asinh(double8);
double16 __const_func asinh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func asinh(half);
half2 __const_func asinh(half2);
half3 __const_func asinh(half3);
half4 __const_func asinh(half4);
half8 __const_func asinh(half8);
half16 __const_func asinh(half16);
#endif //cl_khr_fp16

/**
 * Compute asin (x) / PI.
 */
float __const_func asinpi(float x);
float2 __const_func asinpi(float2 x);
float3 __const_func asinpi(float3 x);
float4 __const_func asinpi(float4 x);
float8 __const_func asinpi(float8 x);
float16 __const_func asinpi(float16 x);
#ifdef cl_khr_fp64
double __const_func asinpi(double x);
double2 __const_func asinpi(double2 x);
double3 __const_func asinpi(double3 x);
double4 __const_func asinpi(double4 x);
double8 __const_func asinpi(double8 x);
double16 __const_func asinpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func asinpi(half x);
half2 __const_func asinpi(half2 x);
half3 __const_func asinpi(half3 x);
half4 __const_func asinpi(half4 x);
half8 __const_func asinpi(half8 x);
half16 __const_func asinpi(half16 x);
#endif //cl_khr_fp16

/**
 * Arc tangent function.
 */
float __const_func atan(float y_over_x);
float2 __const_func atan(float2 y_over_x);
float3 __const_func atan(float3 y_over_x);
float4 __const_func atan(float4 y_over_x);
float8 __const_func atan(float8 y_over_x);
float16 __const_func atan(float16 y_over_x);
#ifdef cl_khr_fp64
double __const_func atan(double y_over_x);
double2 __const_func atan(double2 y_over_x);
double3 __const_func atan(double3 y_over_x);
double4 __const_func atan(double4 y_over_x);
double8 __const_func atan(double8 y_over_x);
double16 __const_func atan(double16 y_over_x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func atan(half y_over_x);
half2 __const_func atan(half2 y_over_x);
half3 __const_func atan(half3 y_over_x);
half4 __const_func atan(half4 y_over_x);
half8 __const_func atan(half8 y_over_x);
half16 __const_func atan(half16 y_over_x);
#endif //cl_khr_fp16

/**
 * Arc tangent of y / x.
 */
float __const_func atan2(float y, float x);
float2 __const_func atan2(float2 y, float2 x);
float3 __const_func atan2(float3 y, float3 x);
float4 __const_func atan2(float4 y, float4 x);
float8 __const_func atan2(float8 y, float8 x);
float16 __const_func atan2(float16 y, float16 x);
#ifdef cl_khr_fp64
double __const_func atan2(double y, double x);
double2 __const_func atan2(double2 y, double2 x);
double3 __const_func atan2(double3 y, double3 x);
double4 __const_func atan2(double4 y, double4 x);
double8 __const_func atan2(double8 y, double8 x);
double16 __const_func atan2(double16 y, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func atan2(half y, half x);
half2 __const_func atan2(half2 y, half2 x);
half3 __const_func atan2(half3 y, half3 x);
half4 __const_func atan2(half4 y, half4 x);
half8 __const_func atan2(half8 y, half8 x);
half16 __const_func atan2(half16 y, half16 x);
#endif //cl_khr_fp16

/**
 * Hyperbolic arc tangent.
 */
float __const_func atanh(float);
float2 __const_func atanh(float2);
float3 __const_func atanh(float3);
float4 __const_func atanh(float4);
float8 __const_func atanh(float8);
float16 __const_func atanh(float16);
#ifdef cl_khr_fp64
double __const_func atanh(double);
double2 __const_func atanh(double2);
double3 __const_func atanh(double3);
double4 __const_func atanh(double4);
double8 __const_func atanh(double8);
double16 __const_func atanh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func atanh(half);
half2 __const_func atanh(half2);
half3 __const_func atanh(half3);
half4 __const_func atanh(half4);
half8 __const_func atanh(half8);
half16 __const_func atanh(half16);
#endif //cl_khr_fp16

/**
 * Compute atan (x) / PI.
 */
float __const_func atanpi(float x);
float2 __const_func atanpi(float2 x);
float3 __const_func atanpi(float3 x);
float4 __const_func atanpi(float4 x);
float8 __const_func atanpi(float8 x);
float16 __const_func atanpi(float16 x);
#ifdef cl_khr_fp64
double __const_func atanpi(double x);
double2 __const_func atanpi(double2 x);
double3 __const_func atanpi(double3 x);
double4 __const_func atanpi(double4 x);
double8 __const_func atanpi(double8 x);
double16 __const_func atanpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func atanpi(half x);
half2 __const_func atanpi(half2 x);
half3 __const_func atanpi(half3 x);
half4 __const_func atanpi(half4 x);
half8 __const_func atanpi(half8 x);
half16 __const_func atanpi(half16 x);
#endif //cl_khr_fp16

/**
 * Compute atan2 (y, x) / PI.
 */
float __const_func atan2pi(float y, float x);
float2 __const_func atan2pi(float2 y, float2 x);
float3 __const_func atan2pi(float3 y, float3 x);
float4 __const_func atan2pi(float4 y, float4 x);
float8 __const_func atan2pi(float8 y, float8 x);
float16 __const_func atan2pi(float16 y, float16 x);
#ifdef cl_khr_fp64
double __const_func atan2pi(double y, double x);
double2 __const_func atan2pi(double2 y, double2 x);
double3 __const_func atan2pi(double3 y, double3 x);
double4 __const_func atan2pi(double4 y, double4 x);
double8 __const_func atan2pi(double8 y, double8 x);
double16 __const_func atan2pi(double16 y, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func atan2pi(half y, half x);
half2 __const_func atan2pi(half2 y, half2 x);
half3 __const_func atan2pi(half3 y, half3 x);
half4 __const_func atan2pi(half4 y, half4 x);
half8 __const_func atan2pi(half8 y, half8 x);
half16 __const_func atan2pi(half16 y, half16 x);
#endif //cl_khr_fp16

/**
 * Compute cube-root.
 */
float __const_func cbrt(float);
float2 __const_func cbrt(float2);
float3 __const_func cbrt(float3);
float4 __const_func cbrt(float4);
float8 __const_func cbrt(float8);
float16 __const_func cbrt(float16);
#ifdef cl_khr_fp64
double __const_func cbrt(double);
double2 __const_func cbrt(double2);
double3 __const_func cbrt(double3);
double4 __const_func cbrt(double4);
double8 __const_func cbrt(double8);
double16 __const_func cbrt(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func cbrt(half);
half2 __const_func cbrt(half2);
half3 __const_func cbrt(half3);
half4 __const_func cbrt(half4);
half8 __const_func cbrt(half8);
half16 __const_func cbrt(half16);
#endif //cl_khr_fp16

/**
 * Round to integral value using the round to positive
 * infinity rounding mode.
 */
float __const_func ceil(float);
float2 __const_func ceil(float2);
float3 __const_func ceil(float3);
float4 __const_func ceil(float4);
float8 __const_func ceil(float8);
float16 __const_func ceil(float16);
#ifdef cl_khr_fp64
double __const_func ceil(double);
double2 __const_func ceil(double2);
double3 __const_func ceil(double3);
double4 __const_func ceil(double4);
double8 __const_func ceil(double8);
double16 __const_func ceil(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func ceil(half);
half2 __const_func ceil(half2);
half3 __const_func ceil(half3);
half4 __const_func ceil(half4);
half8 __const_func ceil(half8);
half16 __const_func ceil(half16);
#endif //cl_khr_fp16

/**
 * Returns x with its sign changed to match the sign of y.
 */
float __const_func copysign(float x, float y);
float2 __const_func copysign(float2 x, float2 y);
float3 __const_func copysign(float3 x, float3 y);
float4 __const_func copysign(float4 x, float4 y);
float8 __const_func copysign(float8 x, float8 y);
float16 __const_func copysign(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func copysign(double x, double y);
double2 __const_func copysign(double2 x, double2 y);
double3 __const_func copysign(double3 x, double3 y);
double4 __const_func copysign(double4 x, double4 y);
double8 __const_func copysign(double8 x, double8 y);
double16 __const_func copysign(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func copysign(half x, half y);
half2 __const_func copysign(half2 x, half2 y);
half3 __const_func copysign(half3 x, half3 y);
half4 __const_func copysign(half4 x, half4 y);
half8 __const_func copysign(half8 x, half8 y);
half16 __const_func copysign(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute cosine.
 */
float __const_func cos(float);
float2 __const_func cos(float2);
float3 __const_func cos(float3);
float4 __const_func cos(float4);
float8 __const_func cos(float8);
float16 __const_func cos(float16);
#ifdef cl_khr_fp64
double __const_func cos(double);
double2 __const_func cos(double2);
double3 __const_func cos(double3);
double4 __const_func cos(double4);
double8 __const_func cos(double8);
double16 __const_func cos(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func cos(half);
half2 __const_func cos(half2);
half3 __const_func cos(half3);
half4 __const_func cos(half4);
half8 __const_func cos(half8);
half16 __const_func cos(half16);
#endif //cl_khr_fp16

/**
 * Compute hyperbolic cosine.
 */
float __const_func cosh(float);
float2 __const_func cosh(float2);
float3 __const_func cosh(float3);
float4 __const_func cosh(float4);
float8 __const_func cosh(float8);
float16 __const_func cosh(float16);
#ifdef cl_khr_fp64
double __const_func cosh(double);
double2 __const_func cosh(double2);
double3 __const_func cosh(double3);
double4 __const_func cosh(double4);
double8 __const_func cosh(double8);
double16 __const_func cosh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func cosh(half);
half2 __const_func cosh(half2);
half3 __const_func cosh(half3);
half4 __const_func cosh(half4);
half8 __const_func cosh(half8);
half16 __const_func cosh(half16);
#endif //cl_khr_fp16

/**
 * Compute cos (PI * x).
 */
float __const_func cospi(float x);
float2 __const_func cospi(float2 x);
float3 __const_func cospi(float3 x);
float4 __const_func cospi(float4 x);
float8 __const_func cospi(float8 x);
float16 __const_func cospi(float16 x);
#ifdef cl_khr_fp64
double __const_func cospi(double x);
double2 __const_func cospi(double2 x);
double3 __const_func cospi(double3 x);
double4 __const_func cospi(double4 x);
double8 __const_func cospi(double8 x);
double16 __const_func cospi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func cospi(half x);
half2 __const_func cospi(half2 x);
half3 __const_func cospi(half3 x);
half4 __const_func cospi(half4 x);
half8 __const_func cospi(half8 x);
half16 __const_func cospi(half16 x);
#endif //cl_khr_fp16

/**
 * Complementary error function.
 */
float __const_func erfc(float);
float2 __const_func erfc(float2);
float3 __const_func erfc(float3);
float4 __const_func erfc(float4);
float8 __const_func erfc(float8);
float16 __const_func erfc(float16);
#ifdef cl_khr_fp64
double __const_func erfc(double);
double2 __const_func erfc(double2);
double3 __const_func erfc(double3);
double4 __const_func erfc(double4);
double8 __const_func erfc(double8);
double16 __const_func erfc(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func erfc(half);
half2 __const_func erfc(half2);
half3 __const_func erfc(half3);
half4 __const_func erfc(half4);
half8 __const_func erfc(half8);
half16 __const_func erfc(half16);
#endif //cl_khr_fp16

/**
 * Error function encountered in integrating the
 * normal distribution.
 */
float __const_func erf(float);
float2 __const_func erf(float2);
float3 __const_func erf(float3);
float4 __const_func erf(float4);
float8 __const_func erf(float8);
float16 __const_func erf(float16);
#ifdef cl_khr_fp64
double __const_func erf(double);
double2 __const_func erf(double2);
double3 __const_func erf(double3);
double4 __const_func erf(double4);
double8 __const_func erf(double8);
double16 __const_func erf(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func erf(half);
half2 __const_func erf(half2);
half3 __const_func erf(half3);
half4 __const_func erf(half4);
half8 __const_func erf(half8);
half16 __const_func erf(half16);
#endif //cl_khr_fp16

/**
 * Compute the base e exponential of x.
 */
float __const_func exp(float x);
float2 __const_func exp(float2 x);
float3 __const_func exp(float3 x);
float4 __const_func exp(float4 x);
float8 __const_func exp(float8 x);
float16 __const_func exp(float16 x);
#ifdef cl_khr_fp64
double __const_func exp(double x);
double2 __const_func exp(double2 x);
double3 __const_func exp(double3 x);
double4 __const_func exp(double4 x);
double8 __const_func exp(double8 x);
double16 __const_func exp(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func exp(half x);
half2 __const_func exp(half2 x);
half3 __const_func exp(half3 x);
half4 __const_func exp(half4 x);
half8 __const_func exp(half8 x);
half16 __const_func exp(half16 x);
#endif //cl_khr_fp16

/**
 * Exponential base 2 function.
 */
float __const_func exp2(float);
float2 __const_func exp2(float2);
float3 __const_func exp2(float3);
float4 __const_func exp2(float4);
float8 __const_func exp2(float8);
float16 __const_func exp2(float16);
#ifdef cl_khr_fp64
double __const_func exp2(double);
double2 __const_func exp2(double2);
double3 __const_func exp2(double3);
double4 __const_func exp2(double4);
double8 __const_func exp2(double8);
double16 __const_func exp2(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func exp2(half);
half2 __const_func exp2(half2);
half3 __const_func exp2(half3);
half4 __const_func exp2(half4);
half8 __const_func exp2(half8);
half16 __const_func exp2(half16);
#endif //cl_khr_fp16

/**
 * Exponential base 10 function.
 */
float __const_func exp10(float);
float2 __const_func exp10(float2);
float3 __const_func exp10(float3);
float4 __const_func exp10(float4);
float8 __const_func exp10(float8);
float16 __const_func exp10(float16);
#ifdef cl_khr_fp64
double __const_func exp10(double);
double2 __const_func exp10(double2);
double3 __const_func exp10(double3);
double4 __const_func exp10(double4);
double8 __const_func exp10(double8);
double16 __const_func exp10(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func exp10(half);
half2 __const_func exp10(half2);
half3 __const_func exp10(half3);
half4 __const_func exp10(half4);
half8 __const_func exp10(half8);
half16 __const_func exp10(half16);
#endif //cl_khr_fp16

/**
 * Compute e^x- 1.0.
 */
float __const_func expm1(float x);
float2 __const_func expm1(float2 x);
float3 __const_func expm1(float3 x);
float4 __const_func expm1(float4 x);
float8 __const_func expm1(float8 x);
float16 __const_func expm1(float16 x);
#ifdef cl_khr_fp64
double __const_func expm1(double x);
double2 __const_func expm1(double2 x);
double3 __const_func expm1(double3 x);
double4 __const_func expm1(double4 x);
double8 __const_func expm1(double8 x);
double16 __const_func expm1(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func expm1(half x);
half2 __const_func expm1(half2 x);
half3 __const_func expm1(half3 x);
half4 __const_func expm1(half4 x);
half8 __const_func expm1(half8 x);
half16 __const_func expm1(half16 x);
#endif //cl_khr_fp16

/**
 * Compute absolute value of a floating-point number.
 */
float __const_func fabs(float);
float2 __const_func fabs(float2);
float3 __const_func fabs(float3);
float4 __const_func fabs(float4);
float8 __const_func fabs(float8);
float16 __const_func fabs(float16);
#ifdef cl_khr_fp64
double __const_func fabs(double);
double2 __const_func fabs(double2);
double3 __const_func fabs(double3);
double4 __const_func fabs(double4);
double8 __const_func fabs(double8);
double16 __const_func fabs(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func fabs(half);
half2 __const_func fabs(half2);
half3 __const_func fabs(half3);
half4 __const_func fabs(half4);
half8 __const_func fabs(half8);
half16 __const_func fabs(half16);
#endif //cl_khr_fp16

/**
 * x - y if x > y, +0 if x is less than or equal to y.
 */
float __const_func fdim(float x, float y);
float2 __const_func fdim(float2 x, float2 y);
float3 __const_func fdim(float3 x, float3 y);
float4 __const_func fdim(float4 x, float4 y);
float8 __const_func fdim(float8 x, float8 y);
float16 __const_func fdim(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func fdim(double x, double y);
double2 __const_func fdim(double2 x, double2 y);
double3 __const_func fdim(double3 x, double3 y);
double4 __const_func fdim(double4 x, double4 y);
double8 __const_func fdim(double8 x, double8 y);
double16 __const_func fdim(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func fdim(half x, half y);
half2 __const_func fdim(half2 x, half2 y);
half3 __const_func fdim(half3 x, half3 y);
half4 __const_func fdim(half4 x, half4 y);
half8 __const_func fdim(half8 x, half8 y);
half16 __const_func fdim(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Round to integral value using the round to -ve
 * infinity rounding mode.
 */
float __const_func floor(float);
float2 __const_func floor(float2);
float3 __const_func floor(float3);
float4 __const_func floor(float4);
float8 __const_func floor(float8);
float16 __const_func floor(float16);
#ifdef cl_khr_fp64
double __const_func floor(double);
double2 __const_func floor(double2);
double3 __const_func floor(double3);
double4 __const_func floor(double4);
double8 __const_func floor(double8);
double16 __const_func floor(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func floor(half);
half2 __const_func floor(half2);
half3 __const_func floor(half3);
half4 __const_func floor(half4);
half8 __const_func floor(half8);
half16 __const_func floor(half16);
#endif //cl_khr_fp16

/**
 * Returns the correctly rounded floating-point
 * representation of the sum of c with the infinitely
 * precise product of a and b. Rounding of
 * intermediate products shall not occur. Edge case
 * behavior is per the IEEE 754-2008 standard.
 */
float __const_func fma(float a, float b, float c);
float2 __const_func fma(float2 a, float2 b, float2 c);
float3 __const_func fma(float3 a, float3 b, float3 c);
float4 __const_func fma(float4 a, float4 b, float4 c);
float8 __const_func fma(float8 a, float8 b, float8 c);
float16 __const_func fma(float16 a, float16 b, float16 c);
#ifdef cl_khr_fp64
double __const_func fma(double a, double b, double c);
double2 __const_func fma(double2 a, double2 b, double2 c);
double3 __const_func fma(double3 a, double3 b, double3 c);
double4 __const_func fma(double4 a, double4 b, double4 c);
double8 __const_func fma(double8 a, double8 b, double8 c);
double16 __const_func fma(double16 a, double16 b, double16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func fma(half a, half b, half c);
half2 __const_func fma(half2 a, half2 b, half2 c);
half3 __const_func fma(half3 a, half3 b, half3 c);
half4 __const_func fma(half4 a, half4 b, half4 c);
half8 __const_func fma(half8 a, half8 b, half8 c);
half16 __const_func fma(half16 a, half16 b, half16 c);
#endif //cl_khr_fp16

/**
 * Returns y if x < y, otherwise it returns x. If one
 * argument is a NaN, fmax() returns the other
 * argument. If both arguments are NaNs, fmax()
 * returns a NaN.
 */
float __const_func fmax(float x, float y);
float2 __const_func fmax(float2 x, float2 y);
float3 __const_func fmax(float3 x, float3 y);
float4 __const_func fmax(float4 x, float4 y);
float8 __const_func fmax(float8 x, float8 y);
float16 __const_func fmax(float16 x, float16 y);
float2 __const_func fmax(float2 x, float y);
float3 __const_func fmax(float3 x, float y);
float4 __const_func fmax(float4 x, float y);
float8 __const_func fmax(float8 x, float y);
float16 __const_func fmax(float16 x, float y);
#ifdef cl_khr_fp64
double __const_func fmax(double x, double y);
double2 __const_func fmax(double2 x, double2 y);
double3 __const_func fmax(double3 x, double3 y);
double4 __const_func fmax(double4 x, double4 y);
double8 __const_func fmax(double8 x, double8 y);
double16 __const_func fmax(double16 x, double16 y);
double2 __const_func fmax(double2 x, double y);
double3 __const_func fmax(double3 x, double y);
double4 __const_func fmax(double4 x, double y);
double8 __const_func fmax(double8 x, double y);
double16 __const_func fmax(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func fmax(half x, half y);
half2 __const_func fmax(half2 x, half2 y);
half3 __const_func fmax(half3 x, half3 y);
half4 __const_func fmax(half4 x, half4 y);
half8 __const_func fmax(half8 x, half8 y);
half16 __const_func fmax(half16 x, half16 y);
half2 __const_func fmax(half2 x, half y);
half3 __const_func fmax(half3 x, half y);
half4 __const_func fmax(half4 x, half y);
half8 __const_func fmax(half8 x, half y);
half16 __const_func fmax(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Returns y if y < x, otherwise it returns x. If one
 * argument is a NaN, fmin() returns the other
 * argument. If both arguments are NaNs, fmin()
 * returns a NaN.
 */
float __const_func fmin(float x, float y);
float2 __const_func fmin(float2 x, float2 y);
float3 __const_func fmin(float3 x, float3 y);
float4 __const_func fmin(float4 x, float4 y);
float8 __const_func fmin(float8 x, float8 y);
float16 __const_func fmin(float16 x, float16 y);
float2 __const_func fmin(float2 x, float y);
float3 __const_func fmin(float3 x, float y);
float4 __const_func fmin(float4 x, float y);
float8 __const_func fmin(float8 x, float y);
float16 __const_func fmin(float16 x, float y);
#ifdef cl_khr_fp64
double __const_func fmin(double x, double y);
double2 __const_func fmin(double2 x, double2 y);
double3 __const_func fmin(double3 x, double3 y);
double4 __const_func fmin(double4 x, double4 y);
double8 __const_func fmin(double8 x, double8 y);
double16 __const_func fmin(double16 x, double16 y);
double2 __const_func fmin(double2 x, double y);
double3 __const_func fmin(double3 x, double y);
double4 __const_func fmin(double4 x, double y);
double8 __const_func fmin(double8 x, double y);
double16 __const_func fmin(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func fmin(half x, half y);
half2 __const_func fmin(half2 x, half2 y);
half3 __const_func fmin(half3 x, half3 y);
half4 __const_func fmin(half4 x, half4 y);
half8 __const_func fmin(half8 x, half8 y);
half16 __const_func fmin(half16 x, half16 y);
half2 __const_func fmin(half2 x, half y);
half3 __const_func fmin(half3 x, half y);
half4 __const_func fmin(half4 x, half y);
half8 __const_func fmin(half8 x, half y);
half16 __const_func fmin(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Modulus. Returns x - y * trunc (x/y).
 */
float __const_func fmod(float x, float y);
float2 __const_func fmod(float2 x, float2 y);
float3 __const_func fmod(float3 x, float3 y);
float4 __const_func fmod(float4 x, float4 y);
float8 __const_func fmod(float8 x, float8 y);
float16 __const_func fmod(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func fmod(double x, double y);
double2 __const_func fmod(double2 x, double2 y);
double3 __const_func fmod(double3 x, double3 y);
double4 __const_func fmod(double4 x, double4 y);
double8 __const_func fmod(double8 x, double8 y);
double16 __const_func fmod(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func fmod(half x, half y);
half2 __const_func fmod(half2 x, half2 y);
half3 __const_func fmod(half3 x, half3 y);
half4 __const_func fmod(half4 x, half4 y);
half8 __const_func fmod(half8 x, half8 y);
half16 __const_func fmod(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns fmin(x - floor (x), 0x1.fffffep-1f ).
 * floor(x) is returned in iptr.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload fract(float x, float *iptr);
float2 __overload fract(float2 x, float2 *iptr);
float3 __overload fract(float3 x, float3 *iptr);
float4 __overload fract(float4 x, float4 *iptr);
float8 __overload fract(float8 x, float8 *iptr);
float16 __overload fract(float16 x, float16 *iptr);
#ifdef cl_khr_fp64
double __overload fract(double x, double *iptr);
double2 __overload fract(double2 x, double2 *iptr);
double3 __overload fract(double3 x, double3 *iptr);
double4 __overload fract(double4 x, double4 *iptr);
double8 __overload fract(double8 x, double8 *iptr);
double16 __overload fract(double16 x, double16 *iptr);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload fract(half x, half *iptr);
half2 __overload fract(half2 x, half2 *iptr);
half3 __overload fract(half3 x, half3 *iptr);
half4 __overload fract(half4 x, half4 *iptr);
half8 __overload fract(half8 x, half8 *iptr);
half16 __overload fract(half16 x, half16 *iptr);
#endif //cl_khr_fp16
#else
float __overload fract(float x, __global float *iptr);
float2 __overload fract(float2 x, __global float2 *iptr);
float3 __overload fract(float3 x, __global float3 *iptr);
float4 __overload fract(float4 x, __global float4 *iptr);
float8 __overload fract(float8 x, __global float8 *iptr);
float16 __overload fract(float16 x, __global float16 *iptr);
float __overload fract(float x, __local float *iptr);
float2 __overload fract(float2 x, __local float2 *iptr);
float3 __overload fract(float3 x, __local float3 *iptr);
float4 __overload fract(float4 x, __local float4 *iptr);
float8 __overload fract(float8 x, __local float8 *iptr);
float16 __overload fract(float16 x, __local float16 *iptr);
float __overload fract(float x, __private float *iptr);
float2 __overload fract(float2 x, __private float2 *iptr);
float3 __overload fract(float3 x, __private float3 *iptr);
float4 __overload fract(float4 x, __private float4 *iptr);
float8 __overload fract(float8 x, __private float8 *iptr);
float16 __overload fract(float16 x, __private float16 *iptr);
#ifdef cl_khr_fp64
double __overload fract(double x, __global double *iptr);
double2 __overload fract(double2 x, __global double2 *iptr);
double3 __overload fract(double3 x, __global double3 *iptr);
double4 __overload fract(double4 x, __global double4 *iptr);
double8 __overload fract(double8 x, __global double8 *iptr);
double16 __overload fract(double16 x, __global double16 *iptr);
double __overload fract(double x, __local double *iptr);
double2 __overload fract(double2 x, __local double2 *iptr);
double3 __overload fract(double3 x, __local double3 *iptr);
double4 __overload fract(double4 x, __local double4 *iptr);
double8 __overload fract(double8 x, __local double8 *iptr);
double16 __overload fract(double16 x, __local double16 *iptr);
double __overload fract(double x, __private double *iptr);
double2 __overload fract(double2 x, __private double2 *iptr);
double3 __overload fract(double3 x, __private double3 *iptr);
double4 __overload fract(double4 x, __private double4 *iptr);
double8 __overload fract(double8 x, __private double8 *iptr);
double16 __overload fract(double16 x, __private double16 *iptr);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload fract(half x, __global half *iptr);
half2 __overload fract(half2 x, __global half2 *iptr);
half3 __overload fract(half3 x, __global half3 *iptr);
half4 __overload fract(half4 x, __global half4 *iptr);
half8 __overload fract(half8 x, __global half8 *iptr);
half16 __overload fract(half16 x, __global half16 *iptr);
half __overload fract(half x, __local half *iptr);
half2 __overload fract(half2 x, __local half2 *iptr);
half3 __overload fract(half3 x, __local half3 *iptr);
half4 __overload fract(half4 x, __local half4 *iptr);
half8 __overload fract(half8 x, __local half8 *iptr);
half16 __overload fract(half16 x, __local half16 *iptr);
half __overload fract(half x, __private half *iptr);
half2 __overload fract(half2 x, __private half2 *iptr);
half3 __overload fract(half3 x, __private half3 *iptr);
half4 __overload fract(half4 x, __private half4 *iptr);
half8 __overload fract(half8 x, __private half8 *iptr);
half16 __overload fract(half16 x, __private half16 *iptr);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Extract mantissa and exponent from x. For each
 * component the mantissa returned is a float with
 * magnitude in the interval [1/2, 1) or 0. Each
 * component of x equals mantissa returned * 2^exp.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload frexp(float x, int *exp);
float2 __overload frexp(float2 x, int2 *exp);
float3 __overload frexp(float3 x, int3 *exp);
float4 __overload frexp(float4 x, int4 *exp);
float8 __overload frexp(float8 x, int8 *exp);
float16 __overload frexp(float16 x, int16 *exp);
#ifdef cl_khr_fp64
double __overload frexp(double x, int *exp);
double2 __overload frexp(double2 x, int2 *exp);
double3 __overload frexp(double3 x, int3 *exp);
double4 __overload frexp(double4 x, int4 *exp);
double8 __overload frexp(double8 x, int8 *exp);
double16 __overload frexp(double16 x, int16 *exp);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload frexp(half x, int *exp);
half2 __overload frexp(half2 x, int2 *exp);
half3 __overload frexp(half3 x, int3 *exp);
half4 __overload frexp(half4 x, int4 *exp);
half8 __overload frexp(half8 x, int8 *exp);
half16 __overload frexp(half16 x, int16 *exp);
#endif //cl_khr_fp16
#else
float __overload frexp(float x, __global int *exp);
float2 __overload frexp(float2 x, __global int2 *exp);
float3 __overload frexp(float3 x, __global int3 *exp);
float4 __overload frexp(float4 x, __global int4 *exp);
float8 __overload frexp(float8 x, __global int8 *exp);
float16 __overload frexp(float16 x, __global int16 *exp);
float __overload frexp(float x, __local int *exp);
float2 __overload frexp(float2 x, __local int2 *exp);
float3 __overload frexp(float3 x, __local int3 *exp);
float4 __overload frexp(float4 x, __local int4 *exp);
float8 __overload frexp(float8 x, __local int8 *exp);
float16 __overload frexp(float16 x, __local int16 *exp);
float __overload frexp(float x, __private int *exp);
float2 __overload frexp(float2 x, __private int2 *exp);
float3 __overload frexp(float3 x, __private int3 *exp);
float4 __overload frexp(float4 x, __private int4 *exp);
float8 __overload frexp(float8 x, __private int8 *exp);
float16 __overload frexp(float16 x, __private int16 *exp);
#ifdef cl_khr_fp64
double __overload frexp(double x, __global int *exp);
double2 __overload frexp(double2 x, __global int2 *exp);
double3 __overload frexp(double3 x, __global int3 *exp);
double4 __overload frexp(double4 x, __global int4 *exp);
double8 __overload frexp(double8 x, __global int8 *exp);
double16 __overload frexp(double16 x, __global int16 *exp);
double __overload frexp(double x, __local int *exp);
double2 __overload frexp(double2 x, __local int2 *exp);
double3 __overload frexp(double3 x, __local int3 *exp);
double4 __overload frexp(double4 x, __local int4 *exp);
double8 __overload frexp(double8 x, __local int8 *exp);
double16 __overload frexp(double16 x, __local int16 *exp);
double __overload frexp(double x, __private int *exp);
double2 __overload frexp(double2 x, __private int2 *exp);
double3 __overload frexp(double3 x, __private int3 *exp);
double4 __overload frexp(double4 x, __private int4 *exp);
double8 __overload frexp(double8 x, __private int8 *exp);
double16 __overload frexp(double16 x, __private int16 *exp);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload frexp(half x, __global int *exp);
half2 __overload frexp(half2 x, __global int2 *exp);
half3 __overload frexp(half3 x, __global int3 *exp);
half4 __overload frexp(half4 x, __global int4 *exp);
half8 __overload frexp(half8 x, __global int8 *exp);
half16 __overload frexp(half16 x, __global int16 *exp);
half __overload frexp(half x, __local int *exp);
half2 __overload frexp(half2 x, __local int2 *exp);
half3 __overload frexp(half3 x, __local int3 *exp);
half4 __overload frexp(half4 x, __local int4 *exp);
half8 __overload frexp(half8 x, __local int8 *exp);
half16 __overload frexp(half16 x, __local int16 *exp);
half __overload frexp(half x, __private int *exp);
half2 __overload frexp(half2 x, __private int2 *exp);
half3 __overload frexp(half3 x, __private int3 *exp);
half4 __overload frexp(half4 x, __private int4 *exp);
half8 __overload frexp(half8 x, __private int8 *exp);
half16 __overload frexp(half16 x, __private int16 *exp);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Compute the value of the square root of x^2+ y^2
 * without undue overflow or underflow.
 */
float __const_func hypot(float x, float y);
float2 __const_func hypot(float2 x, float2 y);
float3 __const_func hypot(float3 x, float3 y);
float4 __const_func hypot(float4 x, float4 y);
float8 __const_func hypot(float8 x, float8 y);
float16 __const_func hypot(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func hypot(double x, double y);
double2 __const_func hypot(double2 x, double2 y);
double3 __const_func hypot(double3 x, double3 y);
double4 __const_func hypot(double4 x, double4 y);
double8 __const_func hypot(double8 x, double8 y);
double16 __const_func hypot(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func hypot(half x, half y);
half2 __const_func hypot(half2 x, half2 y);
half3 __const_func hypot(half3 x, half3 y);
half4 __const_func hypot(half4 x, half4 y);
half8 __const_func hypot(half8 x, half8 y);
half16 __const_func hypot(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Return the exponent as an integer value.
 */
int __const_func ilogb(float x);
int2 __const_func ilogb(float2 x);
int3 __const_func ilogb(float3 x);
int4 __const_func ilogb(float4 x);
int8 __const_func ilogb(float8 x);
int16 __const_func ilogb(float16 x);
#ifdef cl_khr_fp64
int __const_func ilogb(double x);
int2 __const_func ilogb(double2 x);
int3 __const_func ilogb(double3 x);
int4 __const_func ilogb(double4 x);
int8 __const_func ilogb(double8 x);
int16 __const_func ilogb(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func ilogb(half x);
int2 __const_func ilogb(half2 x);
int3 __const_func ilogb(half3 x);
int4 __const_func ilogb(half4 x);
int8 __const_func ilogb(half8 x);
int16 __const_func ilogb(half16 x);
#endif //cl_khr_fp16

/**
 * Multiply x by 2 to the power n.
 */
float __const_func ldexp(float x, int n);
float2 __const_func ldexp(float2 x, int2 n);
float3 __const_func ldexp(float3 x, int3 n);
float4 __const_func ldexp(float4 x, int4 n);
float8 __const_func ldexp(float8 x, int8 n);
float16 __const_func ldexp(float16 x, int16 n);
float2 __const_func ldexp(float2 x, int n);
float3 __const_func ldexp(float3 x, int n);
float4 __const_func ldexp(float4 x, int n);
float8 __const_func ldexp(float8 x, int n);
float16 __const_func ldexp(float16 x, int n);
#ifdef cl_khr_fp64
double __const_func ldexp(double x, int n);
double2 __const_func ldexp(double2 x, int2 n);
double3 __const_func ldexp(double3 x, int3 n);
double4 __const_func ldexp(double4 x, int4 n);
double8 __const_func ldexp(double8 x, int8 n);
double16 __const_func ldexp(double16 x, int16 n);
double2 __const_func ldexp(double2 x, int n);
double3 __const_func ldexp(double3 x, int n);
double4 __const_func ldexp(double4 x, int n);
double8 __const_func ldexp(double8 x, int n);
double16 __const_func ldexp(double16 x, int n);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func ldexp(half x, int n);
half2 __const_func ldexp(half2 x, int2 n);
half3 __const_func ldexp(half3 x, int3 n);
half4 __const_func ldexp(half4 x, int4 n);
half8 __const_func ldexp(half8 x, int8 n);
half16 __const_func ldexp(half16 x, int16 n);
half2 __const_func ldexp(half2 x, int n);
half3 __const_func ldexp(half3 x, int n);
half4 __const_func ldexp(half4 x, int n);
half8 __const_func ldexp(half8 x, int n);
half16 __const_func ldexp(half16 x, int n);
#endif //cl_khr_fp16

/**
 * Log gamma function. Returns the natural
 * logarithm of the absolute value of the gamma
 * function. The sign of the gamma function is
 * returned in the signp argument of lgamma_r.
 */
float __const_func lgamma(float x);
float2 __const_func lgamma(float2 x);
float3 __const_func lgamma(float3 x);
float4 __const_func lgamma(float4 x);
float8 __const_func lgamma(float8 x);
float16 __const_func lgamma(float16 x);
#ifdef cl_khr_fp64
double __const_func lgamma(double x);
double2 __const_func lgamma(double2 x);
double3 __const_func lgamma(double3 x);
double4 __const_func lgamma(double4 x);
double8 __const_func lgamma(double8 x);
double16 __const_func lgamma(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func lgamma(half x);
half2 __const_func lgamma(half2 x);
half3 __const_func lgamma(half3 x);
half4 __const_func lgamma(half4 x);
half8 __const_func lgamma(half8 x);
half16 __const_func lgamma(half16 x);
#endif //cl_khr_fp16

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload lgamma_r(float x, int *signp);
float2 __overload lgamma_r(float2 x, int2 *signp);
float3 __overload lgamma_r(float3 x, int3 *signp);
float4 __overload lgamma_r(float4 x, int4 *signp);
float8 __overload lgamma_r(float8 x, int8 *signp);
float16 __overload lgamma_r(float16 x, int16 *signp);
#ifdef cl_khr_fp64
double __overload lgamma_r(double x, int *signp);
double2 __overload lgamma_r(double2 x, int2 *signp);
double3 __overload lgamma_r(double3 x, int3 *signp);
double4 __overload lgamma_r(double4 x, int4 *signp);
double8 __overload lgamma_r(double8 x, int8 *signp);
double16 __overload lgamma_r(double16 x, int16 *signp);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload lgamma_r(half x, int *signp);
half2 __overload lgamma_r(half2 x, int2 *signp);
half3 __overload lgamma_r(half3 x, int3 *signp);
half4 __overload lgamma_r(half4 x, int4 *signp);
half8 __overload lgamma_r(half8 x, int8 *signp);
half16 __overload lgamma_r(half16 x, int16 *signp);
#endif //cl_khr_fp16
#else
float __overload lgamma_r(float x, __global int *signp);
float2 __overload lgamma_r(float2 x, __global int2 *signp);
float3 __overload lgamma_r(float3 x, __global int3 *signp);
float4 __overload lgamma_r(float4 x, __global int4 *signp);
float8 __overload lgamma_r(float8 x, __global int8 *signp);
float16 __overload lgamma_r(float16 x, __global int16 *signp);
float __overload lgamma_r(float x, __local int *signp);
float2 __overload lgamma_r(float2 x, __local int2 *signp);
float3 __overload lgamma_r(float3 x, __local int3 *signp);
float4 __overload lgamma_r(float4 x, __local int4 *signp);
float8 __overload lgamma_r(float8 x, __local int8 *signp);
float16 __overload lgamma_r(float16 x, __local int16 *signp);
float __overload lgamma_r(float x, __private int *signp);
float2 __overload lgamma_r(float2 x, __private int2 *signp);
float3 __overload lgamma_r(float3 x, __private int3 *signp);
float4 __overload lgamma_r(float4 x, __private int4 *signp);
float8 __overload lgamma_r(float8 x, __private int8 *signp);
float16 __overload lgamma_r(float16 x, __private int16 *signp);
#ifdef cl_khr_fp64
double __overload lgamma_r(double x, __global int *signp);
double2 __overload lgamma_r(double2 x, __global int2 *signp);
double3 __overload lgamma_r(double3 x, __global int3 *signp);
double4 __overload lgamma_r(double4 x, __global int4 *signp);
double8 __overload lgamma_r(double8 x, __global int8 *signp);
double16 __overload lgamma_r(double16 x, __global int16 *signp);
double __overload lgamma_r(double x, __local int *signp);
double2 __overload lgamma_r(double2 x, __local int2 *signp);
double3 __overload lgamma_r(double3 x, __local int3 *signp);
double4 __overload lgamma_r(double4 x, __local int4 *signp);
double8 __overload lgamma_r(double8 x, __local int8 *signp);
double16 __overload lgamma_r(double16 x, __local int16 *signp);
double __overload lgamma_r(double x, __private int *signp);
double2 __overload lgamma_r(double2 x, __private int2 *signp);
double3 __overload lgamma_r(double3 x, __private int3 *signp);
double4 __overload lgamma_r(double4 x, __private int4 *signp);
double8 __overload lgamma_r(double8 x, __private int8 *signp);
double16 __overload lgamma_r(double16 x, __private int16 *signp);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload lgamma_r(half x, __global int *signp);
half2 __overload lgamma_r(half2 x, __global int2 *signp);
half3 __overload lgamma_r(half3 x, __global int3 *signp);
half4 __overload lgamma_r(half4 x, __global int4 *signp);
half8 __overload lgamma_r(half8 x, __global int8 *signp);
half16 __overload lgamma_r(half16 x, __global int16 *signp);
half __overload lgamma_r(half x, __local int *signp);
half2 __overload lgamma_r(half2 x, __local int2 *signp);
half3 __overload lgamma_r(half3 x, __local int3 *signp);
half4 __overload lgamma_r(half4 x, __local int4 *signp);
half8 __overload lgamma_r(half8 x, __local int8 *signp);
half16 __overload lgamma_r(half16 x, __local int16 *signp);
half __overload lgamma_r(half x, __private int *signp);
half2 __overload lgamma_r(half2 x, __private int2 *signp);
half3 __overload lgamma_r(half3 x, __private int3 *signp);
half4 __overload lgamma_r(half4 x, __private int4 *signp);
half8 __overload lgamma_r(half8 x, __private int8 *signp);
half16 __overload lgamma_r(half16 x, __private int16 *signp);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Compute natural logarithm.
 */
float __const_func log(float);
float2 __const_func log(float2);
float3 __const_func log(float3);
float4 __const_func log(float4);
float8 __const_func log(float8);
float16 __const_func log(float16);
#ifdef cl_khr_fp64
double __const_func log(double);
double2 __const_func log(double2);
double3 __const_func log(double3);
double4 __const_func log(double4);
double8 __const_func log(double8);
double16 __const_func log(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func log(half);
half2 __const_func log(half2);
half3 __const_func log(half3);
half4 __const_func log(half4);
half8 __const_func log(half8);
half16 __const_func log(half16);
#endif //cl_khr_fp16

/**
 * Compute a base 2 logarithm.
 */
float __const_func log2(float);
float2 __const_func log2(float2);
float3 __const_func log2(float3);
float4 __const_func log2(float4);
float8 __const_func log2(float8);
float16 __const_func log2(float16);
#ifdef cl_khr_fp64
double __const_func log2(double);
double2 __const_func log2(double2);
double3 __const_func log2(double3);
double4 __const_func log2(double4);
double8 __const_func log2(double8);
double16 __const_func log2(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func log2(half);
half2 __const_func log2(half2);
half3 __const_func log2(half3);
half4 __const_func log2(half4);
half8 __const_func log2(half8);
half16 __const_func log2(half16);
#endif //cl_khr_fp16

/**
 * Compute a base 10 logarithm.
 */
float __const_func log10(float);
float2 __const_func log10(float2);
float3 __const_func log10(float3);
float4 __const_func log10(float4);
float8 __const_func log10(float8);
float16 __const_func log10(float16);
#ifdef cl_khr_fp64
double __const_func log10(double);
double2 __const_func log10(double2);
double3 __const_func log10(double3);
double4 __const_func log10(double4);
double8 __const_func log10(double8);
double16 __const_func log10(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func log10(half);
half2 __const_func log10(half2);
half3 __const_func log10(half3);
half4 __const_func log10(half4);
half8 __const_func log10(half8);
half16 __const_func log10(half16);
#endif //cl_khr_fp16

/**
 * Compute a base e logarithm of (1.0 + x).
 */
float __const_func log1p(float x);
float2 __const_func log1p(float2 x);
float3 __const_func log1p(float3 x);
float4 __const_func log1p(float4 x);
float8 __const_func log1p(float8 x);
float16 __const_func log1p(float16 x);
#ifdef cl_khr_fp64
double __const_func log1p(double x);
double2 __const_func log1p(double2 x);
double3 __const_func log1p(double3 x);
double4 __const_func log1p(double4 x);
double8 __const_func log1p(double8 x);
double16 __const_func log1p(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func log1p(half x);
half2 __const_func log1p(half2 x);
half3 __const_func log1p(half3 x);
half4 __const_func log1p(half4 x);
half8 __const_func log1p(half8 x);
half16 __const_func log1p(half16 x);
#endif //cl_khr_fp16

/**
 * Compute the exponent of x, which is the integral
 * part of logr | x |.
 */
float __const_func logb(float x);
float2 __const_func logb(float2 x);
float3 __const_func logb(float3 x);
float4 __const_func logb(float4 x);
float8 __const_func logb(float8 x);
float16 __const_func logb(float16 x);
#ifdef cl_khr_fp64
double __const_func logb(double x);
double2 __const_func logb(double2 x);
double3 __const_func logb(double3 x);
double4 __const_func logb(double4 x);
double8 __const_func logb(double8 x);
double16 __const_func logb(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func logb(half x);
half2 __const_func logb(half2 x);
half3 __const_func logb(half3 x);
half4 __const_func logb(half4 x);
half8 __const_func logb(half8 x);
half16 __const_func logb(half16 x);
#endif //cl_khr_fp16

/**
 * mad approximates a * b + c. Whether or how the
 * product of a * b is rounded and how supernormal or
 * subnormal intermediate products are handled is not
 * defined. mad is intended to be used where speed is
 * preferred over accuracy.
 */
float __const_func mad(float a, float b, float c);
float2 __const_func mad(float2 a, float2 b, float2 c);
float3 __const_func mad(float3 a, float3 b, float3 c);
float4 __const_func mad(float4 a, float4 b, float4 c);
float8 __const_func mad(float8 a, float8 b, float8 c);
float16 __const_func mad(float16 a, float16 b, float16 c);
#ifdef cl_khr_fp64
double __const_func mad(double a, double b, double c);
double2 __const_func mad(double2 a, double2 b, double2 c);
double3 __const_func mad(double3 a, double3 b, double3 c);
double4 __const_func mad(double4 a, double4 b, double4 c);
double8 __const_func mad(double8 a, double8 b, double8 c);
double16 __const_func mad(double16 a, double16 b, double16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func mad(half a, half b, half c);
half2 __const_func mad(half2 a, half2 b, half2 c);
half3 __const_func mad(half3 a, half3 b, half3 c);
half4 __const_func mad(half4 a, half4 b, half4 c);
half8 __const_func mad(half8 a, half8 b, half8 c);
half16 __const_func mad(half16 a, half16 b, half16 c);
#endif //cl_khr_fp16

/**
 * Returns x if | x | > | y |, y if | y | > | x |, otherwise
 * fmax(x, y).
 */
float __const_func maxmag(float x, float y);
float2 __const_func maxmag(float2 x, float2 y);
float3 __const_func maxmag(float3 x, float3 y);
float4 __const_func maxmag(float4 x, float4 y);
float8 __const_func maxmag(float8 x, float8 y);
float16 __const_func maxmag(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func maxmag(double x, double y);
double2 __const_func maxmag(double2 x, double2 y);
double3 __const_func maxmag(double3 x, double3 y);
double4 __const_func maxmag(double4 x, double4 y);
double8 __const_func maxmag(double8 x, double8 y);
double16 __const_func maxmag(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func maxmag(half x, half y);
half2 __const_func maxmag(half2 x, half2 y);
half3 __const_func maxmag(half3 x, half3 y);
half4 __const_func maxmag(half4 x, half4 y);
half8 __const_func maxmag(half8 x, half8 y);
half16 __const_func maxmag(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns x if | x | < | y |, y if | y | < | x |, otherwise
 * fmin(x, y).
 */
float __const_func minmag(float x, float y);
float2 __const_func minmag(float2 x, float2 y);
float3 __const_func minmag(float3 x, float3 y);
float4 __const_func minmag(float4 x, float4 y);
float8 __const_func minmag(float8 x, float8 y);
float16 __const_func minmag(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func minmag(double x, double y);
double2 __const_func minmag(double2 x, double2 y);
double3 __const_func minmag(double3 x, double3 y);
double4 __const_func minmag(double4 x, double4 y);
double8 __const_func minmag(double8 x, double8 y);
double16 __const_func minmag(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func minmag(half x, half y);
half2 __const_func minmag(half2 x, half2 y);
half3 __const_func minmag(half3 x, half3 y);
half4 __const_func minmag(half4 x, half4 y);
half8 __const_func minmag(half8 x, half8 y);
half16 __const_func minmag(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Decompose a floating-point number. The modf
 * function breaks the argument x into integral and
 * fractional parts, each of which has the same sign as
 * the argument. It stores the integral part in the object
 * pointed to by iptr.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload modf(float x, float *iptr);
float2 __overload modf(float2 x, float2 *iptr);
float3 __overload modf(float3 x, float3 *iptr);
float4 __overload modf(float4 x, float4 *iptr);
float8 __overload modf(float8 x, float8 *iptr);
float16 __overload modf(float16 x, float16 *iptr);
#ifdef cl_khr_fp64
double __overload modf(double x, double *iptr);
double2 __overload modf(double2 x, double2 *iptr);
double3 __overload modf(double3 x, double3 *iptr);
double4 __overload modf(double4 x, double4 *iptr);
double8 __overload modf(double8 x, double8 *iptr);
double16 __overload modf(double16 x, double16 *iptr);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload modf(half x, half *iptr);
half2 __overload modf(half2 x, half2 *iptr);
half3 __overload modf(half3 x, half3 *iptr);
half4 __overload modf(half4 x, half4 *iptr);
half8 __overload modf(half8 x, half8 *iptr);
half16 __overload modf(half16 x, half16 *iptr);
#endif //cl_khr_fp16
#else
float __overload modf(float x, __global float *iptr);
float2 __overload modf(float2 x, __global float2 *iptr);
float3 __overload modf(float3 x, __global float3 *iptr);
float4 __overload modf(float4 x, __global float4 *iptr);
float8 __overload modf(float8 x, __global float8 *iptr);
float16 __overload modf(float16 x, __global float16 *iptr);
float __overload modf(float x, __local float *iptr);
float2 __overload modf(float2 x, __local float2 *iptr);
float3 __overload modf(float3 x, __local float3 *iptr);
float4 __overload modf(float4 x, __local float4 *iptr);
float8 __overload modf(float8 x, __local float8 *iptr);
float16 __overload modf(float16 x, __local float16 *iptr);
float __overload modf(float x, __private float *iptr);
float2 __overload modf(float2 x, __private float2 *iptr);
float3 __overload modf(float3 x, __private float3 *iptr);
float4 __overload modf(float4 x, __private float4 *iptr);
float8 __overload modf(float8 x, __private float8 *iptr);
float16 __overload modf(float16 x, __private float16 *iptr);
#ifdef cl_khr_fp64
double __overload modf(double x, __global double *iptr);
double2 __overload modf(double2 x, __global double2 *iptr);
double3 __overload modf(double3 x, __global double3 *iptr);
double4 __overload modf(double4 x, __global double4 *iptr);
double8 __overload modf(double8 x, __global double8 *iptr);
double16 __overload modf(double16 x, __global double16 *iptr);
double __overload modf(double x, __local double *iptr);
double2 __overload modf(double2 x, __local double2 *iptr);
double3 __overload modf(double3 x, __local double3 *iptr);
double4 __overload modf(double4 x, __local double4 *iptr);
double8 __overload modf(double8 x, __local double8 *iptr);
double16 __overload modf(double16 x, __local double16 *iptr);
double __overload modf(double x, __private double *iptr);
double2 __overload modf(double2 x, __private double2 *iptr);
double3 __overload modf(double3 x, __private double3 *iptr);
double4 __overload modf(double4 x, __private double4 *iptr);
double8 __overload modf(double8 x, __private double8 *iptr);
double16 __overload modf(double16 x, __private double16 *iptr);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload modf(half x, __global half *iptr);
half2 __overload modf(half2 x, __global half2 *iptr);
half3 __overload modf(half3 x, __global half3 *iptr);
half4 __overload modf(half4 x, __global half4 *iptr);
half8 __overload modf(half8 x, __global half8 *iptr);
half16 __overload modf(half16 x, __global half16 *iptr);
half __overload modf(half x, __local half *iptr);
half2 __overload modf(half2 x, __local half2 *iptr);
half3 __overload modf(half3 x, __local half3 *iptr);
half4 __overload modf(half4 x, __local half4 *iptr);
half8 __overload modf(half8 x, __local half8 *iptr);
half16 __overload modf(half16 x, __local half16 *iptr);
half __overload modf(half x, __private half *iptr);
half2 __overload modf(half2 x, __private half2 *iptr);
half3 __overload modf(half3 x, __private half3 *iptr);
half4 __overload modf(half4 x, __private half4 *iptr);
half8 __overload modf(half8 x, __private half8 *iptr);
half16 __overload modf(half16 x, __private half16 *iptr);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Returns a quiet NaN. The nancode may be placed
 * in the significand of the resulting NaN.
 */
float __const_func nan(uint nancode);
float2 __const_func nan(uint2 nancode);
float3 __const_func nan(uint3 nancode);
float4 __const_func nan(uint4 nancode);
float8 __const_func nan(uint8 nancode);
float16 __const_func nan(uint16 nancode);
#ifdef cl_khr_fp64
double __const_func nan(ulong nancode);
double2 __const_func nan(ulong2 nancode);
double3 __const_func nan(ulong3 nancode);
double4 __const_func nan(ulong4 nancode);
double8 __const_func nan(ulong8 nancode);
double16 __const_func nan(ulong16 nancode);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func nan(ushort nancode);
half2 __const_func nan(ushort2 nancode);
half3 __const_func nan(ushort3 nancode);
half4 __const_func nan(ushort4 nancode);
half8 __const_func nan(ushort8 nancode);
half16 __const_func nan(ushort16 nancode);
#endif //cl_khr_fp16

/**
 * Computes the next representable single-precision
 * floating-point value following x in the direction of
 * y. Thus, if y is less than x, nextafter() returns the
 * largest representable floating-point number less
 * than x.
 */
float __const_func nextafter(float x, float y);
float2 __const_func nextafter(float2 x, float2 y);
float3 __const_func nextafter(float3 x, float3 y);
float4 __const_func nextafter(float4 x, float4 y);
float8 __const_func nextafter(float8 x, float8 y);
float16 __const_func nextafter(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func nextafter(double x, double y);
double2 __const_func nextafter(double2 x, double2 y);
double3 __const_func nextafter(double3 x, double3 y);
double4 __const_func nextafter(double4 x, double4 y);
double8 __const_func nextafter(double8 x, double8 y);
double16 __const_func nextafter(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func nextafter(half x, half y);
half2 __const_func nextafter(half2 x, half2 y);
half3 __const_func nextafter(half3 x, half3 y);
half4 __const_func nextafter(half4 x, half4 y);
half8 __const_func nextafter(half8 x, half8 y);
half16 __const_func nextafter(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute x to the power y.
 */
float __const_func pow(float x, float y);
float2 __const_func pow(float2 x, float2 y);
float3 __const_func pow(float3 x, float3 y);
float4 __const_func pow(float4 x, float4 y);
float8 __const_func pow(float8 x, float8 y);
float16 __const_func pow(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func pow(double x, double y);
double2 __const_func pow(double2 x, double2 y);
double3 __const_func pow(double3 x, double3 y);
double4 __const_func pow(double4 x, double4 y);
double8 __const_func pow(double8 x, double8 y);
double16 __const_func pow(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func pow(half x, half y);
half2 __const_func pow(half2 x, half2 y);
half3 __const_func pow(half3 x, half3 y);
half4 __const_func pow(half4 x, half4 y);
half8 __const_func pow(half8 x, half8 y);
half16 __const_func pow(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute x to the power y, where y is an integer.
 */
float __const_func pown(float x, int y);
float2 __const_func pown(float2 x, int2 y);
float3 __const_func pown(float3 x, int3 y);
float4 __const_func pown(float4 x, int4 y);
float8 __const_func pown(float8 x, int8 y);
float16 __const_func pown(float16 x, int16 y);
#ifdef cl_khr_fp64
double __const_func pown(double x, int y);
double2 __const_func pown(double2 x, int2 y);
double3 __const_func pown(double3 x, int3 y);
double4 __const_func pown(double4 x, int4 y);
double8 __const_func pown(double8 x, int8 y);
double16 __const_func pown(double16 x, int16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func pown(half x, int y);
half2 __const_func pown(half2 x, int2 y);
half3 __const_func pown(half3 x, int3 y);
half4 __const_func pown(half4 x, int4 y);
half8 __const_func pown(half8 x, int8 y);
half16 __const_func pown(half16 x, int16 y);
#endif //cl_khr_fp16

/**
 * Compute x to the power y, where x is >= 0.
 */
float __const_func powr(float x, float y);
float2 __const_func powr(float2 x, float2 y);
float3 __const_func powr(float3 x, float3 y);
float4 __const_func powr(float4 x, float4 y);
float8 __const_func powr(float8 x, float8 y);
float16 __const_func powr(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func powr(double x, double y);
double2 __const_func powr(double2 x, double2 y);
double3 __const_func powr(double3 x, double3 y);
double4 __const_func powr(double4 x, double4 y);
double8 __const_func powr(double8 x, double8 y);
double16 __const_func powr(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func powr(half x, half y);
half2 __const_func powr(half2 x, half2 y);
half3 __const_func powr(half3 x, half3 y);
half4 __const_func powr(half4 x, half4 y);
half8 __const_func powr(half8 x, half8 y);
half16 __const_func powr(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute the value r such that r = x - n*y, where n
 * is the integer nearest the exact value of x/y. If there
 * are two integers closest to x/y, n shall be the even
 * one. If r is zero, it is given the same sign as x.
 */
float __const_func remainder(float x, float y);
float2 __const_func remainder(float2 x, float2 y);
float3 __const_func remainder(float3 x, float3 y);
float4 __const_func remainder(float4 x, float4 y);
float8 __const_func remainder(float8 x, float8 y);
float16 __const_func remainder(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func remainder(double x, double y);
double2 __const_func remainder(double2 x, double2 y);
double3 __const_func remainder(double3 x, double3 y);
double4 __const_func remainder(double4 x, double4 y);
double8 __const_func remainder(double8 x, double8 y);
double16 __const_func remainder(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func remainder(half x, half y);
half2 __const_func remainder(half2 x, half2 y);
half3 __const_func remainder(half3 x, half3 y);
half4 __const_func remainder(half4 x, half4 y);
half8 __const_func remainder(half8 x, half8 y);
half16 __const_func remainder(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * The remquo function computes the value r such
 * that r = x - n*y, where n is the integer nearest the
 * exact value of x/y. If there are two integers closest
 * to x/y, n shall be the even one. If r is zero, it is
 * given the same sign as x. This is the same value
 * that is returned by the remainder function.
 * remquo also calculates the lower seven bits of the
 * integral quotient x/y, and gives that value the same
 * sign as x/y. It stores this signed value in the object
 * pointed to by quo.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload remquo(float x, float y, int *quo);
float2 __overload remquo(float2 x, float2 y, int2 *quo);
float3 __overload remquo(float3 x, float3 y, int3 *quo);
float4 __overload remquo(float4 x, float4 y, int4 *quo);
float8 __overload remquo(float8 x, float8 y, int8 *quo);
float16 __overload remquo(float16 x, float16 y, int16 *quo);
#ifdef cl_khr_fp64
double __overload remquo(double x, double y, int *quo);
double2 __overload remquo(double2 x, double2 y, int2 *quo);
double3 __overload remquo(double3 x, double3 y, int3 *quo);
double4 __overload remquo(double4 x, double4 y, int4 *quo);
double8 __overload remquo(double8 x, double8 y, int8 *quo);
double16 __overload remquo(double16 x, double16 y, int16 *quo);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload remquo(half x, half y, int *quo);
half2 __overload remquo(half2 x, half2 y, int2 *quo);
half3 __overload remquo(half3 x, half3 y, int3 *quo);
half4 __overload remquo(half4 x, half4 y, int4 *quo);
half8 __overload remquo(half8 x, half8 y, int8 *quo);
half16 __overload remquo(half16 x, half16 y, int16 *quo);

#endif //cl_khr_fp16
#else
float __overload remquo(float x, float y, __global int *quo);
float2 __overload remquo(float2 x, float2 y, __global int2 *quo);
float3 __overload remquo(float3 x, float3 y, __global int3 *quo);
float4 __overload remquo(float4 x, float4 y, __global int4 *quo);
float8 __overload remquo(float8 x, float8 y, __global int8 *quo);
float16 __overload remquo(float16 x, float16 y, __global int16 *quo);
float __overload remquo(float x, float y, __local int *quo);
float2 __overload remquo(float2 x, float2 y, __local int2 *quo);
float3 __overload remquo(float3 x, float3 y, __local int3 *quo);
float4 __overload remquo(float4 x, float4 y, __local int4 *quo);
float8 __overload remquo(float8 x, float8 y, __local int8 *quo);
float16 __overload remquo(float16 x, float16 y, __local int16 *quo);
float __overload remquo(float x, float y, __private int *quo);
float2 __overload remquo(float2 x, float2 y, __private int2 *quo);
float3 __overload remquo(float3 x, float3 y, __private int3 *quo);
float4 __overload remquo(float4 x, float4 y, __private int4 *quo);
float8 __overload remquo(float8 x, float8 y, __private int8 *quo);
float16 __overload remquo(float16 x, float16 y, __private int16 *quo);
#ifdef cl_khr_fp64
double __overload remquo(double x, double y, __global int *quo);
double2 __overload remquo(double2 x, double2 y, __global int2 *quo);
double3 __overload remquo(double3 x, double3 y, __global int3 *quo);
double4 __overload remquo(double4 x, double4 y, __global int4 *quo);
double8 __overload remquo(double8 x, double8 y, __global int8 *quo);
double16 __overload remquo(double16 x, double16 y, __global int16 *quo);
double __overload remquo(double x, double y, __local int *quo);
double2 __overload remquo(double2 x, double2 y, __local int2 *quo);
double3 __overload remquo(double3 x, double3 y, __local int3 *quo);
double4 __overload remquo(double4 x, double4 y, __local int4 *quo);
double8 __overload remquo(double8 x, double8 y, __local int8 *quo);
double16 __overload remquo(double16 x, double16 y, __local int16 *quo);
double __overload remquo(double x, double y, __private int *quo);
double2 __overload remquo(double2 x, double2 y, __private int2 *quo);
double3 __overload remquo(double3 x, double3 y, __private int3 *quo);
double4 __overload remquo(double4 x, double4 y, __private int4 *quo);
double8 __overload remquo(double8 x, double8 y, __private int8 *quo);
double16 __overload remquo(double16 x, double16 y, __private int16 *quo);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload remquo(half x, half y, __global int *quo);
half2 __overload remquo(half2 x, half2 y, __global int2 *quo);
half3 __overload remquo(half3 x, half3 y, __global int3 *quo);
half4 __overload remquo(half4 x, half4 y, __global int4 *quo);
half8 __overload remquo(half8 x, half8 y, __global int8 *quo);
half16 __overload remquo(half16 x, half16 y, __global int16 *quo);
half __overload remquo(half x, half y, __local int *quo);
half2 __overload remquo(half2 x, half2 y, __local int2 *quo);
half3 __overload remquo(half3 x, half3 y, __local int3 *quo);
half4 __overload remquo(half4 x, half4 y, __local int4 *quo);
half8 __overload remquo(half8 x, half8 y, __local int8 *quo);
half16 __overload remquo(half16 x, half16 y, __local int16 *quo);
half __overload remquo(half x, half y, __private int *quo);
half2 __overload remquo(half2 x, half2 y, __private int2 *quo);
half3 __overload remquo(half3 x, half3 y, __private int3 *quo);
half4 __overload remquo(half4 x, half4 y, __private int4 *quo);
half8 __overload remquo(half8 x, half8 y, __private int8 *quo);
half16 __overload remquo(half16 x, half16 y, __private int16 *quo);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0
/**
 * Round to integral value (using round to nearest
 * even rounding mode) in floating-point format.
 * Refer to section 7.1 for description of rounding
 * modes.
 */
float __const_func rint(float);
float2 __const_func rint(float2);
float3 __const_func rint(float3);
float4 __const_func rint(float4);
float8 __const_func rint(float8);
float16 __const_func rint(float16);
#ifdef cl_khr_fp64
double __const_func rint(double);
double2 __const_func rint(double2);
double3 __const_func rint(double3);
double4 __const_func rint(double4);
double8 __const_func rint(double8);
double16 __const_func rint(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func rint(half);
half2 __const_func rint(half2);
half3 __const_func rint(half3);
half4 __const_func rint(half4);
half8 __const_func rint(half8);
half16 __const_func rint(half16);
#endif //cl_khr_fp16

/**
 * Compute x to the power 1/y.
 */
float __const_func rootn(float x, int y);
float2 __const_func rootn(float2 x, int2 y);
float3 __const_func rootn(float3 x, int3 y);
float4 __const_func rootn(float4 x, int4 y);
float8 __const_func rootn(float8 x, int8 y);
float16 __const_func rootn(float16 x, int16 y);
#ifdef cl_khr_fp64
double __const_func rootn(double x, int y);
double2 __const_func rootn(double2 x, int2 y);
double3 __const_func rootn(double3 x, int3 y);
double4 __const_func rootn(double4 x, int4 y);
double8 __const_func rootn(double8 x, int8 y);
double16 __const_func rootn(double16 x, int16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func rootn(half x, int y);
half2 __const_func rootn(half2 x, int2 y);
half3 __const_func rootn(half3 x, int3 y);
half4 __const_func rootn(half4 x, int4 y);
half8 __const_func rootn(half8 x, int8 y);
half16 __const_func rootn(half16 x, int16 y);
#endif //cl_khr_fp16

/**
 * Return the integral value nearest to x rounding
 * halfway cases away from zero, regardless of the
 * current rounding direction.
 */
float __const_func round(float x);
float2 __const_func round(float2 x);
float3 __const_func round(float3 x);
float4 __const_func round(float4 x);
float8 __const_func round(float8 x);
float16 __const_func round(float16 x);
#ifdef cl_khr_fp64
double __const_func round(double x);
double2 __const_func round(double2 x);
double3 __const_func round(double3 x);
double4 __const_func round(double4 x);
double8 __const_func round(double8 x);
double16 __const_func round(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func round(half x);
half2 __const_func round(half2 x);
half3 __const_func round(half3 x);
half4 __const_func round(half4 x);
half8 __const_func round(half8 x);
half16 __const_func round(half16 x);
#endif //cl_khr_fp16

/**
 * Compute inverse square root.
 */
float __const_func rsqrt(float);
float2 __const_func rsqrt(float2);
float3 __const_func rsqrt(float3);
float4 __const_func rsqrt(float4);
float8 __const_func rsqrt(float8);
float16 __const_func rsqrt(float16);
#ifdef cl_khr_fp64
double __const_func rsqrt(double);
double2 __const_func rsqrt(double2);
double3 __const_func rsqrt(double3);
double4 __const_func rsqrt(double4);
double8 __const_func rsqrt(double8);
double16 __const_func rsqrt(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func rsqrt(half);
half2 __const_func rsqrt(half2);
half3 __const_func rsqrt(half3);
half4 __const_func rsqrt(half4);
half8 __const_func rsqrt(half8);
half16 __const_func rsqrt(half16);
#endif //cl_khr_fp16

/**
 * Compute sine.
 */
float __const_func sin(float);
float2 __const_func sin(float2);
float3 __const_func sin(float3);
float4 __const_func sin(float4);
float8 __const_func sin(float8);
float16 __const_func sin(float16);
#ifdef cl_khr_fp64
double __const_func sin(double);
double2 __const_func sin(double2);
double3 __const_func sin(double3);
double4 __const_func sin(double4);
double8 __const_func sin(double8);
double16 __const_func sin(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func sin(half);
half2 __const_func sin(half2);
half3 __const_func sin(half3);
half4 __const_func sin(half4);
half8 __const_func sin(half8);
half16 __const_func sin(half16);
#endif //cl_khr_fp16

/**
 * Compute sine and cosine of x. The computed sine
 * is the return value and computed cosine is returned
 * in cosval.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload sincos(float x, float *cosval);
float2 __overload sincos(float2 x, float2 *cosval);
float3 __overload sincos(float3 x, float3 *cosval);
float4 __overload sincos(float4 x, float4 *cosval);
float8 __overload sincos(float8 x, float8 *cosval);
float16 __overload sincos(float16 x, float16 *cosval);
#ifdef cl_khr_fp64
double __overload sincos(double x, double *cosval);
double2 __overload sincos(double2 x, double2 *cosval);
double3 __overload sincos(double3 x, double3 *cosval);
double4 __overload sincos(double4 x, double4 *cosval);
double8 __overload sincos(double8 x, double8 *cosval);
double16 __overload sincos(double16 x, double16 *cosval);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload sincos(half x, half *cosval);
half2 __overload sincos(half2 x, half2 *cosval);
half3 __overload sincos(half3 x, half3 *cosval);
half4 __overload sincos(half4 x, half4 *cosval);
half8 __overload sincos(half8 x, half8 *cosval);
half16 __overload sincos(half16 x, half16 *cosval);
#endif //cl_khr_fp16
#else
float __overload sincos(float x, __global float *cosval);
float2 __overload sincos(float2 x, __global float2 *cosval);
float3 __overload sincos(float3 x, __global float3 *cosval);
float4 __overload sincos(float4 x, __global float4 *cosval);
float8 __overload sincos(float8 x, __global float8 *cosval);
float16 __overload sincos(float16 x, __global float16 *cosval);
float __overload sincos(float x, __local float *cosval);
float2 __overload sincos(float2 x, __local float2 *cosval);
float3 __overload sincos(float3 x, __local float3 *cosval);
float4 __overload sincos(float4 x, __local float4 *cosval);
float8 __overload sincos(float8 x, __local float8 *cosval);
float16 __overload sincos(float16 x, __local float16 *cosval);
float __overload sincos(float x, __private float *cosval);
float2 __overload sincos(float2 x, __private float2 *cosval);
float3 __overload sincos(float3 x, __private float3 *cosval);
float4 __overload sincos(float4 x, __private float4 *cosval);
float8 __overload sincos(float8 x, __private float8 *cosval);
float16 __overload sincos(float16 x, __private float16 *cosval);
#ifdef cl_khr_fp64
double __overload sincos(double x, __global double *cosval);
double2 __overload sincos(double2 x, __global double2 *cosval);
double3 __overload sincos(double3 x, __global double3 *cosval);
double4 __overload sincos(double4 x, __global double4 *cosval);
double8 __overload sincos(double8 x, __global double8 *cosval);
double16 __overload sincos(double16 x, __global double16 *cosval);
double __overload sincos(double x, __local double *cosval);
double2 __overload sincos(double2 x, __local double2 *cosval);
double3 __overload sincos(double3 x, __local double3 *cosval);
double4 __overload sincos(double4 x, __local double4 *cosval);
double8 __overload sincos(double8 x, __local double8 *cosval);
double16 __overload sincos(double16 x, __local double16 *cosval);
double __overload sincos(double x, __private double *cosval);
double2 __overload sincos(double2 x, __private double2 *cosval);
double3 __overload sincos(double3 x, __private double3 *cosval);
double4 __overload sincos(double4 x, __private double4 *cosval);
double8 __overload sincos(double8 x, __private double8 *cosval);
double16 __overload sincos(double16 x, __private double16 *cosval);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __overload sincos(half x, __global half *cosval);
half2 __overload sincos(half2 x, __global half2 *cosval);
half3 __overload sincos(half3 x, __global half3 *cosval);
half4 __overload sincos(half4 x, __global half4 *cosval);
half8 __overload sincos(half8 x, __global half8 *cosval);
half16 __overload sincos(half16 x, __global half16 *cosval);
half __overload sincos(half x, __local half *cosval);
half2 __overload sincos(half2 x, __local half2 *cosval);
half3 __overload sincos(half3 x, __local half3 *cosval);
half4 __overload sincos(half4 x, __local half4 *cosval);
half8 __overload sincos(half8 x, __local half8 *cosval);
half16 __overload sincos(half16 x, __local half16 *cosval);
half __overload sincos(half x, __private half *cosval);
half2 __overload sincos(half2 x, __private half2 *cosval);
half3 __overload sincos(half3 x, __private half3 *cosval);
half4 __overload sincos(half4 x, __private half4 *cosval);
half8 __overload sincos(half8 x, __private half8 *cosval);
half16 __overload sincos(half16 x, __private half16 *cosval);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Compute hyperbolic sine.
 */
float __const_func sinh(float);
float2 __const_func sinh(float2);
float3 __const_func sinh(float3);
float4 __const_func sinh(float4);
float8 __const_func sinh(float8);
float16 __const_func sinh(float16);
#ifdef cl_khr_fp64
double __const_func sinh(double);
double2 __const_func sinh(double2);
double3 __const_func sinh(double3);
double4 __const_func sinh(double4);
double8 __const_func sinh(double8);
double16 __const_func sinh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func sinh(half);
half2 __const_func sinh(half2);
half3 __const_func sinh(half3);
half4 __const_func sinh(half4);
half8 __const_func sinh(half8);
half16 __const_func sinh(half16);
#endif //cl_khr_fp16

/**
 * Compute sin (PI * x).
 */
float __const_func sinpi(float x);
float2 __const_func sinpi(float2 x);
float3 __const_func sinpi(float3 x);
float4 __const_func sinpi(float4 x);
float8 __const_func sinpi(float8 x);
float16 __const_func sinpi(float16 x);
#ifdef cl_khr_fp64
double __const_func sinpi(double x);
double2 __const_func sinpi(double2 x);
double3 __const_func sinpi(double3 x);
double4 __const_func sinpi(double4 x);
double8 __const_func sinpi(double8 x);
double16 __const_func sinpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func sinpi(half x);
half2 __const_func sinpi(half2 x);
half3 __const_func sinpi(half3 x);
half4 __const_func sinpi(half4 x);
half8 __const_func sinpi(half8 x);
half16 __const_func sinpi(half16 x);
#endif //cl_khr_fp16

/**
 * Compute square root.
 */
float __const_func sqrt(float);
float2 __const_func sqrt(float2);
float3 __const_func sqrt(float3);
float4 __const_func sqrt(float4);
float8 __const_func sqrt(float8);
float16 __const_func sqrt(float16);
#ifdef cl_khr_fp64
double __const_func sqrt(double);
double2 __const_func sqrt(double2);
double3 __const_func sqrt(double3);
double4 __const_func sqrt(double4);
double8 __const_func sqrt(double8);
double16 __const_func sqrt(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func sqrt(half);
half2 __const_func sqrt(half2);
half3 __const_func sqrt(half3);
half4 __const_func sqrt(half4);
half8 __const_func sqrt(half8);
half16 __const_func sqrt(half16);
#endif //cl_khr_fp16

/**
 * Compute tangent.
 */
float __const_func tan(float);
float2 __const_func tan(float2);
float3 __const_func tan(float3);
float4 __const_func tan(float4);
float8 __const_func tan(float8);
float16 __const_func tan(float16);
#ifdef cl_khr_fp64
double __const_func tan(double);
double2 __const_func tan(double2);
double3 __const_func tan(double3);
double4 __const_func tan(double4);
double8 __const_func tan(double8);
double16 __const_func tan(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func tan(half);
half2 __const_func tan(half2);
half3 __const_func tan(half3);
half4 __const_func tan(half4);
half8 __const_func tan(half8);
half16 __const_func tan(half16);
#endif //cl_khr_fp16

/**
 * Compute hyperbolic tangent.
 */
float __const_func tanh(float);
float2 __const_func tanh(float2);
float3 __const_func tanh(float3);
float4 __const_func tanh(float4);
float8 __const_func tanh(float8);
float16 __const_func tanh(float16);
#ifdef cl_khr_fp64
double __const_func tanh(double);
double2 __const_func tanh(double2);
double3 __const_func tanh(double3);
double4 __const_func tanh(double4);
double8 __const_func tanh(double8);
double16 __const_func tanh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func tanh(half);
half2 __const_func tanh(half2);
half3 __const_func tanh(half3);
half4 __const_func tanh(half4);
half8 __const_func tanh(half8);
half16 __const_func tanh(half16);
#endif //cl_khr_fp16

/**
 * Compute tan (PI * x).
 */
float __const_func tanpi(float x);
float2 __const_func tanpi(float2 x);
float3 __const_func tanpi(float3 x);
float4 __const_func tanpi(float4 x);
float8 __const_func tanpi(float8 x);
float16 __const_func tanpi(float16 x);
#ifdef cl_khr_fp64
double __const_func tanpi(double x);
double2 __const_func tanpi(double2 x);
double3 __const_func tanpi(double3 x);
double4 __const_func tanpi(double4 x);
double8 __const_func tanpi(double8 x);
double16 __const_func tanpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func tanpi(half x);
half2 __const_func tanpi(half2 x);
half3 __const_func tanpi(half3 x);
half4 __const_func tanpi(half4 x);
half8 __const_func tanpi(half8 x);
half16 __const_func tanpi(half16 x);
#endif //cl_khr_fp16

/**
 * Compute the gamma function.
 */
float __const_func tgamma(float);
float2 __const_func tgamma(float2);
float3 __const_func tgamma(float3);
float4 __const_func tgamma(float4);
float8 __const_func tgamma(float8);
float16 __const_func tgamma(float16);
#ifdef cl_khr_fp64
double __const_func tgamma(double);
double2 __const_func tgamma(double2);
double3 __const_func tgamma(double3);
double4 __const_func tgamma(double4);
double8 __const_func tgamma(double8);
double16 __const_func tgamma(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func tgamma(half);
half2 __const_func tgamma(half2);
half3 __const_func tgamma(half3);
half4 __const_func tgamma(half4);
half8 __const_func tgamma(half8);
half16 __const_func tgamma(half16);
#endif //cl_khr_fp16

/**
 * Round to integral value using the round to zero
 * rounding mode.
 */
float __const_func trunc(float);
float2 __const_func trunc(float2);
float3 __const_func trunc(float3);
float4 __const_func trunc(float4);
float8 __const_func trunc(float8);
float16 __const_func trunc(float16);
#ifdef cl_khr_fp64
double __const_func trunc(double);
double2 __const_func trunc(double2);
double3 __const_func trunc(double3);
double4 __const_func trunc(double4);
double8 __const_func trunc(double8);
double16 __const_func trunc(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func trunc(half);
half2 __const_func trunc(half2);
half3 __const_func trunc(half3);
half4 __const_func trunc(half4);
half8 __const_func trunc(half8);
half16 __const_func trunc(half16);
#endif //cl_khr_fp16

/**
 * Compute cosine. x must be in the range -2^16 ... +2^16.
 */
float __const_func half_cos(float x);
float2 __const_func half_cos(float2 x);
float3 __const_func half_cos(float3 x);
float4 __const_func half_cos(float4 x);
float8 __const_func half_cos(float8 x);
float16 __const_func half_cos(float16 x);

/**
 * Compute x / y.
 */
float __const_func half_divide(float x, float y);
float2 __const_func half_divide(float2 x, float2 y);
float3 __const_func half_divide(float3 x, float3 y);
float4 __const_func half_divide(float4 x, float4 y);
float8 __const_func half_divide(float8 x, float8 y);
float16 __const_func half_divide(float16 x, float16 y);

/**
 * Compute the base- e exponential of x.
 */
float __const_func half_exp(float x);
float2 __const_func half_exp(float2 x);
float3 __const_func half_exp(float3 x);
float4 __const_func half_exp(float4 x);
float8 __const_func half_exp(float8 x);
float16 __const_func half_exp(float16 x);

/**
 * Compute the base- 2 exponential of x.
 */
float __const_func half_exp2(float x);
float2 __const_func half_exp2(float2 x);
float3 __const_func half_exp2(float3 x);
float4 __const_func half_exp2(float4 x);
float8 __const_func half_exp2(float8 x);
float16 __const_func half_exp2(float16 x);

/**
 * Compute the base- 10 exponential of x.
 */
float __const_func half_exp10(float x);
float2 __const_func half_exp10(float2 x);
float3 __const_func half_exp10(float3 x);
float4 __const_func half_exp10(float4 x);
float8 __const_func half_exp10(float8 x);
float16 __const_func half_exp10(float16 x);

/**
 * Compute natural logarithm.
 */
float __const_func half_log(float x);
float2 __const_func half_log(float2 x);
float3 __const_func half_log(float3 x);
float4 __const_func half_log(float4 x);
float8 __const_func half_log(float8 x);
float16 __const_func half_log(float16 x);

/**
 * Compute a base 2 logarithm.
 */
float __const_func half_log2(float x);
float2 __const_func half_log2(float2 x);
float3 __const_func half_log2(float3 x);
float4 __const_func half_log2(float4 x);
float8 __const_func half_log2(float8 x);
float16 __const_func half_log2(float16 x);

/**
 * Compute a base 10 logarithm.
 */
float __const_func half_log10(float x);
float2 __const_func half_log10(float2 x);
float3 __const_func half_log10(float3 x);
float4 __const_func half_log10(float4 x);
float8 __const_func half_log10(float8 x);
float16 __const_func half_log10(float16 x);

/**
 * Compute x to the power y, where x is >= 0.
 */
float __const_func half_powr(float x, float y);
float2 __const_func half_powr(float2 x, float2 y);
float3 __const_func half_powr(float3 x, float3 y);
float4 __const_func half_powr(float4 x, float4 y);
float8 __const_func half_powr(float8 x, float8 y);
float16 __const_func half_powr(float16 x, float16 y);

/**
 * Compute reciprocal.
 */
float __const_func half_recip(float x);
float2 __const_func half_recip(float2 x);
float3 __const_func half_recip(float3 x);
float4 __const_func half_recip(float4 x);
float8 __const_func half_recip(float8 x);
float16 __const_func half_recip(float16 x);

/**
 * Compute inverse square root.
 */
float __const_func half_rsqrt(float x);
float2 __const_func half_rsqrt(float2 x);
float3 __const_func half_rsqrt(float3 x);
float4 __const_func half_rsqrt(float4 x);
float8 __const_func half_rsqrt(float8 x);
float16 __const_func half_rsqrt(float16 x);

/**
 * Compute sine. x must be in the range -2^16 ... +2^16.
 */
float __const_func half_sin(float x);
float2 __const_func half_sin(float2 x);
float3 __const_func half_sin(float3 x);
float4 __const_func half_sin(float4 x);
float8 __const_func half_sin(float8 x);
float16 __const_func half_sin(float16 x);

/**
 * Compute square root.
 */
float __const_func half_sqrt(float x);
float2 __const_func half_sqrt(float2 x);
float3 __const_func half_sqrt(float3 x);
float4 __const_func half_sqrt(float4 x);
float8 __const_func half_sqrt(float8 x);
float16 __const_func half_sqrt(float16 x);

/**
 * Compute tangent. x must be in the range -216 ... +216.
 */
float __const_func half_tan(float x);
float2 __const_func half_tan(float2 x);
float3 __const_func half_tan(float3 x);
float4 __const_func half_tan(float4 x);
float8 __const_func half_tan(float8 x);
float16 __const_func half_tan(float16 x);

/**
 * Compute cosine over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __const_func native_cos(float x);
float2 __const_func native_cos(float2 x);
float3 __const_func native_cos(float3 x);
float4 __const_func native_cos(float4 x);
float8 __const_func native_cos(float8 x);
float16 __const_func native_cos(float16 x);
#ifdef cl_khr_fp64
double __const_func native_cos(double x);
double2 __const_func native_cos(double2 x);
double3 __const_func native_cos(double3 x);
double4 __const_func native_cos(double4 x);
double8 __const_func native_cos(double8 x);
double16 __const_func native_cos(double16 x);
#endif //cl_khr_fp64

/**
 * Compute x / y over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __const_func native_divide(float x, float y);
float2 __const_func native_divide(float2 x, float2 y);
float3 __const_func native_divide(float3 x, float3 y);
float4 __const_func native_divide(float4 x, float4 y);
float8 __const_func native_divide(float8 x, float8 y);
float16 __const_func native_divide(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func native_divide(double x, double y);
double2 __const_func native_divide(double2 x, double2 y);
double3 __const_func native_divide(double3 x, double3 y);
double4 __const_func native_divide(double4 x, double4 y);
double8 __const_func native_divide(double8 x, double8 y);
double16 __const_func native_divide(double16 x, double16 y);
#endif //cl_khr_fp64

/**
 * Compute the base- e exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __const_func native_exp(float x);
float2 __const_func native_exp(float2 x);
float3 __const_func native_exp(float3 x);
float4 __const_func native_exp(float4 x);
float8 __const_func native_exp(float8 x);
float16 __const_func native_exp(float16 x);
#ifdef cl_khr_fp64
double __const_func native_exp(double x);
double2 __const_func native_exp(double2 x);
double3 __const_func native_exp(double3 x);
double4 __const_func native_exp(double4 x);
double8 __const_func native_exp(double8 x);
double16 __const_func native_exp(double16 x);
#endif //cl_khr_fp64

/**
 * Compute the base- 2 exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __const_func native_exp2(float x);
float2 __const_func native_exp2(float2 x);
float3 __const_func native_exp2(float3 x);
float4 __const_func native_exp2(float4 x);
float8 __const_func native_exp2(float8 x);
float16 __const_func native_exp2(float16 x);
#ifdef cl_khr_fp64
double __const_func native_exp2(double x);
double2 __const_func native_exp2(double2 x);
double3 __const_func native_exp2(double3 x);
double4 __const_func native_exp2(double4 x);
double8 __const_func native_exp2(double8 x);
double16 __const_func native_exp2(double16 x);
#endif //cl_khr_fp64

/**
 * Compute the base- 10 exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __const_func native_exp10(float x);
float2 __const_func native_exp10(float2 x);
float3 __const_func native_exp10(float3 x);
float4 __const_func native_exp10(float4 x);
float8 __const_func native_exp10(float8 x);
float16 __const_func native_exp10(float16 x);
#ifdef cl_khr_fp64
double __const_func native_exp10(double x);
double2 __const_func native_exp10(double2 x);
double3 __const_func native_exp10(double3 x);
double4 __const_func native_exp10(double4 x);
double8 __const_func native_exp10(double8 x);
double16 __const_func native_exp10(double16 x);
#endif //cl_khr_fp64

/**
 * Compute natural logarithm over an implementationdefined
 * range. The maximum error is implementation
 * defined.
 */
float __const_func native_log(float x);
float2 __const_func native_log(float2 x);
float3 __const_func native_log(float3 x);
float4 __const_func native_log(float4 x);
float8 __const_func native_log(float8 x);
float16 __const_func native_log(float16 x);
#ifdef cl_khr_fp64
double __const_func native_log(double x);
double2 __const_func native_log(double2 x);
double3 __const_func native_log(double3 x);
double4 __const_func native_log(double4 x);
double8 __const_func native_log(double8 x);
double16 __const_func native_log(double16 x);
#endif //cl_khr_fp64

/**
 * Compute a base 2 logarithm over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __const_func native_log2(float x);
float2 __const_func native_log2(float2 x);
float3 __const_func native_log2(float3 x);
float4 __const_func native_log2(float4 x);
float8 __const_func native_log2(float8 x);
float16 __const_func native_log2(float16 x);
#ifdef cl_khr_fp64
double __const_func native_log2(double x);
double2 __const_func native_log2(double2 x);
double3 __const_func native_log2(double3 x);
double4 __const_func native_log2(double4 x);
double8 __const_func native_log2(double8 x);
double16 __const_func native_log2(double16 x);
#endif //cl_khr_fp64

/**
 * Compute a base 10 logarithm over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __const_func native_log10(float x);
float2 __const_func native_log10(float2 x);
float3 __const_func native_log10(float3 x);
float4 __const_func native_log10(float4 x);
float8 __const_func native_log10(float8 x);
float16 __const_func native_log10(float16 x);
#ifdef cl_khr_fp64
double __const_func native_log10(double x);
double2 __const_func native_log10(double2 x);
double3 __const_func native_log10(double3 x);
double4 __const_func native_log10(double4 x);
double8 __const_func native_log10(double8 x);
double16 __const_func native_log10(double16 x);
#endif //cl_khr_fp64

/**
 * Compute x to the power y, where x is >= 0. The range of
 * x and y are implementation-defined. The maximum error
 * is implementation-defined.
 */
float __const_func native_powr(float x, float y);
float2 __const_func native_powr(float2 x, float2 y);
float3 __const_func native_powr(float3 x, float3 y);
float4 __const_func native_powr(float4 x, float4 y);
float8 __const_func native_powr(float8 x, float8 y);
float16 __const_func native_powr(float16 x, float16 y);
#ifdef cl_khr_fp64
double __const_func native_powr(double x, double y);
double2 __const_func native_powr(double2 x, double2 y);
double3 __const_func native_powr(double3 x, double3 y);
double4 __const_func native_powr(double4 x, double4 y);
double8 __const_func native_powr(double8 x, double8 y);
double16 __const_func native_powr(double16 x, double16 y);
#endif //cl_khr_fp64

/**
 * Compute reciprocal over an implementation-defined
 * range. The maximum error is implementation-defined.
 */
float __const_func native_recip(float x);
float2 __const_func native_recip(float2 x);
float3 __const_func native_recip(float3 x);
float4 __const_func native_recip(float4 x);
float8 __const_func native_recip(float8 x);
float16 __const_func native_recip(float16 x);
#ifdef cl_khr_fp64
double __const_func native_recip(double x);
double2 __const_func native_recip(double2 x);
double3 __const_func native_recip(double3 x);
double4 __const_func native_recip(double4 x);
double8 __const_func native_recip(double8 x);
double16 __const_func native_recip(double16 x);
#endif //cl_khr_fp64

/**
 * Compute inverse square root over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __const_func native_rsqrt(float x);
float2 __const_func native_rsqrt(float2 x);
float3 __const_func native_rsqrt(float3 x);
float4 __const_func native_rsqrt(float4 x);
float8 __const_func native_rsqrt(float8 x);
float16 __const_func native_rsqrt(float16 x);
#ifdef cl_khr_fp64
double __const_func native_rsqrt(double x);
double2 __const_func native_rsqrt(double2 x);
double3 __const_func native_rsqrt(double3 x);
double4 __const_func native_rsqrt(double4 x);
double8 __const_func native_rsqrt(double8 x);
double16 __const_func native_rsqrt(double16 x);
#endif //cl_khr_fp64

/**
 * Compute sine over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __const_func native_sin(float x);
float2 __const_func native_sin(float2 x);
float3 __const_func native_sin(float3 x);
float4 __const_func native_sin(float4 x);
float8 __const_func native_sin(float8 x);
float16 __const_func native_sin(float16 x);
#ifdef cl_khr_fp64
double __const_func native_sin(double x);
double2 __const_func native_sin(double2 x);
double3 __const_func native_sin(double3 x);
double4 __const_func native_sin(double4 x);
double8 __const_func native_sin(double8 x);
double16 __const_func native_sin(double16 x);
#endif //cl_khr_fp64

/**
 * Compute square root over an implementation-defined
 * range. The maximum error is implementation-defined.
 */
float __const_func native_sqrt(float x);
float2 __const_func native_sqrt(float2 x);
float3 __const_func native_sqrt(float3 x);
float4 __const_func native_sqrt(float4 x);
float8 __const_func native_sqrt(float8 x);
float16 __const_func native_sqrt(float16 x);
#ifdef cl_khr_fp64
double __const_func native_sqrt(double x);
double2 __const_func native_sqrt(double2 x);
double3 __const_func native_sqrt(double3 x);
double4 __const_func native_sqrt(double4 x);
double8 __const_func native_sqrt(double8 x);
double16 __const_func native_sqrt(double16 x);
#endif //cl_khr_fp64

/**
 * Compute tangent over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __const_func native_tan(float x);
float2 __const_func native_tan(float2 x);
float3 __const_func native_tan(float3 x);
float4 __const_func native_tan(float4 x);
float8 __const_func native_tan(float8 x);
float16 __const_func native_tan(float16 x);
#ifdef cl_khr_fp64
double __const_func native_tan(double x);
double2 __const_func native_tan(double2 x);
double3 __const_func native_tan(double3 x);
double4 __const_func native_tan(double4 x);
double8 __const_func native_tan(double8 x);
double16 __const_func native_tan(double16 x);
#endif //cl_khr_fp64

// OpenCL v1.1 s6.11.3, v1.2 s6.12.3, v2.0 s6.13.3 - Integer Functions

/**
 * Returns | x |.
 */
uchar __const_func abs(char x);
uchar __const_func abs(uchar x);
uchar2 __const_func abs(char2 x);
uchar2 __const_func abs(uchar2 x);
uchar3 __const_func abs(char3 x);
uchar3 __const_func abs(uchar3 x);
uchar4 __const_func abs(char4 x);
uchar4 __const_func abs(uchar4 x);
uchar8 __const_func abs(char8 x);
uchar8 __const_func abs(uchar8 x);
uchar16 __const_func abs(char16 x);
uchar16 __const_func abs(uchar16 x);
ushort __const_func abs(short x);
ushort __const_func abs(ushort x);
ushort2 __const_func abs(short2 x);
ushort2 __const_func abs(ushort2 x);
ushort3 __const_func abs(short3 x);
ushort3 __const_func abs(ushort3 x);
ushort4 __const_func abs(short4 x);
ushort4 __const_func abs(ushort4 x);
ushort8 __const_func abs(short8 x);
ushort8 __const_func abs(ushort8 x);
ushort16 __const_func abs(short16 x);
ushort16 __const_func abs(ushort16 x);
uint __const_func abs(int x);
uint __const_func abs(uint x);
uint2 __const_func abs(int2 x);
uint2 __const_func abs(uint2 x);
uint3 __const_func abs(int3 x);
uint3 __const_func abs(uint3 x);
uint4 __const_func abs(int4 x);
uint4 __const_func abs(uint4 x);
uint8 __const_func abs(int8 x);
uint8 __const_func abs(uint8 x);
uint16 __const_func abs(int16 x);
uint16 __const_func abs(uint16 x);
ulong __const_func abs(long x);
ulong __const_func abs(ulong x);
ulong2 __const_func abs(long2 x);
ulong2 __const_func abs(ulong2 x);
ulong3 __const_func abs(long3 x);
ulong3 __const_func abs(ulong3 x);
ulong4 __const_func abs(long4 x);
ulong4 __const_func abs(ulong4 x);
ulong8 __const_func abs(long8 x);
ulong8 __const_func abs(ulong8 x);
ulong16 __const_func abs(long16 x);
ulong16 __const_func abs(ulong16 x);

/**
 * Returns | x - y | without modulo overflow.
 */
uchar __const_func abs_diff(char x, char y);
uchar __const_func abs_diff(uchar x, uchar y);
uchar2 __const_func abs_diff(char2 x, char2 y);
uchar2 __const_func abs_diff(uchar2 x, uchar2 y);
uchar3 __const_func abs_diff(char3 x, char3 y);
uchar3 __const_func abs_diff(uchar3 x, uchar3 y);
uchar4 __const_func abs_diff(char4 x, char4 y);
uchar4 __const_func abs_diff(uchar4 x, uchar4 y);
uchar8 __const_func abs_diff(char8 x, char8 y);
uchar8 __const_func abs_diff(uchar8 x, uchar8 y);
uchar16 __const_func abs_diff(char16 x, char16 y);
uchar16 __const_func abs_diff(uchar16 x, uchar16 y);
ushort __const_func abs_diff(short x, short y);
ushort __const_func abs_diff(ushort x, ushort y);
ushort2 __const_func abs_diff(short2 x, short2 y);
ushort2 __const_func abs_diff(ushort2 x, ushort2 y);
ushort3 __const_func abs_diff(short3 x, short3 y);
ushort3 __const_func abs_diff(ushort3 x, ushort3 y);
ushort4 __const_func abs_diff(short4 x, short4 y);
ushort4 __const_func abs_diff(ushort4 x, ushort4 y);
ushort8 __const_func abs_diff(short8 x, short8 y);
ushort8 __const_func abs_diff(ushort8 x, ushort8 y);
ushort16 __const_func abs_diff(short16 x, short16 y);
ushort16 __const_func abs_diff(ushort16 x, ushort16 y);
uint __const_func abs_diff(int x, int y);
uint __const_func abs_diff(uint x, uint y);
uint2 __const_func abs_diff(int2 x, int2 y);
uint2 __const_func abs_diff(uint2 x, uint2 y);
uint3 __const_func abs_diff(int3 x, int3 y);
uint3 __const_func abs_diff(uint3 x, uint3 y);
uint4 __const_func abs_diff(int4 x, int4 y);
uint4 __const_func abs_diff(uint4 x, uint4 y);
uint8 __const_func abs_diff(int8 x, int8 y);
uint8 __const_func abs_diff(uint8 x, uint8 y);
uint16 __const_func abs_diff(int16 x, int16 y);
uint16 __const_func abs_diff(uint16 x, uint16 y);
ulong __const_func abs_diff(long x, long y);
ulong __const_func abs_diff(ulong x, ulong y);
ulong2 __const_func abs_diff(long2 x, long2 y);
ulong2 __const_func abs_diff(ulong2 x, ulong2 y);
ulong3 __const_func abs_diff(long3 x, long3 y);
ulong3 __const_func abs_diff(ulong3 x, ulong3 y);
ulong4 __const_func abs_diff(long4 x, long4 y);
ulong4 __const_func abs_diff(ulong4 x, ulong4 y);
ulong8 __const_func abs_diff(long8 x, long8 y);
ulong8 __const_func abs_diff(ulong8 x, ulong8 y);
ulong16 __const_func abs_diff(long16 x, long16 y);
ulong16 __const_func abs_diff(ulong16 x, ulong16 y);

/**
 * Returns x + y and saturates the result.
 */
char __const_func add_sat(char x, char y);
uchar __const_func add_sat(uchar x, uchar y);
char2 __const_func add_sat(char2 x, char2 y);
uchar2 __const_func add_sat(uchar2 x, uchar2 y);
char3 __const_func add_sat(char3 x, char3 y);
uchar3 __const_func add_sat(uchar3 x, uchar3 y);
char4 __const_func add_sat(char4 x, char4 y);
uchar4 __const_func add_sat(uchar4 x, uchar4 y);
char8 __const_func add_sat(char8 x, char8 y);
uchar8 __const_func add_sat(uchar8 x, uchar8 y);
char16 __const_func add_sat(char16 x, char16 y);
uchar16 __const_func add_sat(uchar16 x, uchar16 y);
short __const_func add_sat(short x, short y);
ushort __const_func add_sat(ushort x, ushort y);
short2 __const_func add_sat(short2 x, short2 y);
ushort2 __const_func add_sat(ushort2 x, ushort2 y);
short3 __const_func add_sat(short3 x, short3 y);
ushort3 __const_func add_sat(ushort3 x, ushort3 y);
short4 __const_func add_sat(short4 x, short4 y);
ushort4 __const_func add_sat(ushort4 x, ushort4 y);
short8 __const_func add_sat(short8 x, short8 y);
ushort8 __const_func add_sat(ushort8 x, ushort8 y);
short16 __const_func add_sat(short16 x, short16 y);
ushort16 __const_func add_sat(ushort16 x, ushort16 y);
int __const_func add_sat(int x, int y);
uint __const_func add_sat(uint x, uint y);
int2 __const_func add_sat(int2 x, int2 y);
uint2 __const_func add_sat(uint2 x, uint2 y);
int3 __const_func add_sat(int3 x, int3 y);
uint3 __const_func add_sat(uint3 x, uint3 y);
int4 __const_func add_sat(int4 x, int4 y);
uint4 __const_func add_sat(uint4 x, uint4 y);
int8 __const_func add_sat(int8 x, int8 y);
uint8 __const_func add_sat(uint8 x, uint8 y);
int16 __const_func add_sat(int16 x, int16 y);
uint16 __const_func add_sat(uint16 x, uint16 y);
long __const_func add_sat(long x, long y);
ulong __const_func add_sat(ulong x, ulong y);
long2 __const_func add_sat(long2 x, long2 y);
ulong2 __const_func add_sat(ulong2 x, ulong2 y);
long3 __const_func add_sat(long3 x, long3 y);
ulong3 __const_func add_sat(ulong3 x, ulong3 y);
long4 __const_func add_sat(long4 x, long4 y);
ulong4 __const_func add_sat(ulong4 x, ulong4 y);
long8 __const_func add_sat(long8 x, long8 y);
ulong8 __const_func add_sat(ulong8 x, ulong8 y);
long16 __const_func add_sat(long16 x, long16 y);
ulong16 __const_func add_sat(ulong16 x, ulong16 y);

/**
 * Returns (x + y) >> 1. The intermediate sum does
 * not modulo overflow.
 */
char __const_func hadd(char x, char y);
uchar __const_func hadd(uchar x, uchar y);
char2 __const_func hadd(char2 x, char2 y);
uchar2 __const_func hadd(uchar2 x, uchar2 y);
char3 __const_func hadd(char3 x, char3 y);
uchar3 __const_func hadd(uchar3 x, uchar3 y);
char4 __const_func hadd(char4 x, char4 y);
uchar4 __const_func hadd(uchar4 x, uchar4 y);
char8 __const_func hadd(char8 x, char8 y);
uchar8 __const_func hadd(uchar8 x, uchar8 y);
char16 __const_func hadd(char16 x, char16 y);
uchar16 __const_func hadd(uchar16 x, uchar16 y);
short __const_func hadd(short x, short y);
ushort __const_func hadd(ushort x, ushort y);
short2 __const_func hadd(short2 x, short2 y);
ushort2 __const_func hadd(ushort2 x, ushort2 y);
short3 __const_func hadd(short3 x, short3 y);
ushort3 __const_func hadd(ushort3 x, ushort3 y);
short4 __const_func hadd(short4 x, short4 y);
ushort4 __const_func hadd(ushort4 x, ushort4 y);
short8 __const_func hadd(short8 x, short8 y);
ushort8 __const_func hadd(ushort8 x, ushort8 y);
short16 __const_func hadd(short16 x, short16 y);
ushort16 __const_func hadd(ushort16 x, ushort16 y);
int __const_func hadd(int x, int y);
uint __const_func hadd(uint x, uint y);
int2 __const_func hadd(int2 x, int2 y);
uint2 __const_func hadd(uint2 x, uint2 y);
int3 __const_func hadd(int3 x, int3 y);
uint3 __const_func hadd(uint3 x, uint3 y);
int4 __const_func hadd(int4 x, int4 y);
uint4 __const_func hadd(uint4 x, uint4 y);
int8 __const_func hadd(int8 x, int8 y);
uint8 __const_func hadd(uint8 x, uint8 y);
int16 __const_func hadd(int16 x, int16 y);
uint16 __const_func hadd(uint16 x, uint16 y);
long __const_func hadd(long x, long y);
ulong __const_func hadd(ulong x, ulong y);
long2 __const_func hadd(long2 x, long2 y);
ulong2 __const_func hadd(ulong2 x, ulong2 y);
long3 __const_func hadd(long3 x, long3 y);
ulong3 __const_func hadd(ulong3 x, ulong3 y);
long4 __const_func hadd(long4 x, long4 y);
ulong4 __const_func hadd(ulong4 x, ulong4 y);
long8 __const_func hadd(long8 x, long8 y);
ulong8 __const_func hadd(ulong8 x, ulong8 y);
long16 __const_func hadd(long16 x, long16 y);
ulong16 __const_func hadd(ulong16 x, ulong16 y);

/**
 * Returns (x + y + 1) >> 1. The intermediate sum
 * does not modulo overflow.
 */
char __const_func rhadd(char x, char y);
uchar __const_func rhadd(uchar x, uchar y);
char2 __const_func rhadd(char2 x, char2 y);
uchar2 __const_func rhadd(uchar2 x, uchar2 y);
char3 __const_func rhadd(char3 x, char3 y);
uchar3 __const_func rhadd(uchar3 x, uchar3 y);
char4 __const_func rhadd(char4 x, char4 y);
uchar4 __const_func rhadd(uchar4 x, uchar4 y);
char8 __const_func rhadd(char8 x, char8 y);
uchar8 __const_func rhadd(uchar8 x, uchar8 y);
char16 __const_func rhadd(char16 x, char16 y);
uchar16 __const_func rhadd(uchar16 x, uchar16 y);
short __const_func rhadd(short x, short y);
ushort __const_func rhadd(ushort x, ushort y);
short2 __const_func rhadd(short2 x, short2 y);
ushort2 __const_func rhadd(ushort2 x, ushort2 y);
short3 __const_func rhadd(short3 x, short3 y);
ushort3 __const_func rhadd(ushort3 x, ushort3 y);
short4 __const_func rhadd(short4 x, short4 y);
ushort4 __const_func rhadd(ushort4 x, ushort4 y);
short8 __const_func rhadd(short8 x, short8 y);
ushort8 __const_func rhadd(ushort8 x, ushort8 y);
short16 __const_func rhadd(short16 x, short16 y);
ushort16 __const_func rhadd(ushort16 x, ushort16 y);
int __const_func rhadd(int x, int y);
uint __const_func rhadd(uint x, uint y);
int2 __const_func rhadd(int2 x, int2 y);
uint2 __const_func rhadd(uint2 x, uint2 y);
int3 __const_func rhadd(int3 x, int3 y);
uint3 __const_func rhadd(uint3 x, uint3 y);
int4 __const_func rhadd(int4 x, int4 y);
uint4 __const_func rhadd(uint4 x, uint4 y);
int8 __const_func rhadd(int8 x, int8 y);
uint8 __const_func rhadd(uint8 x, uint8 y);
int16 __const_func rhadd(int16 x, int16 y);
uint16 __const_func rhadd(uint16 x, uint16 y);
long __const_func rhadd(long x, long y);
ulong __const_func rhadd(ulong x, ulong y);
long2 __const_func rhadd(long2 x, long2 y);
ulong2 __const_func rhadd(ulong2 x, ulong2 y);
long3 __const_func rhadd(long3 x, long3 y);
ulong3 __const_func rhadd(ulong3 x, ulong3 y);
long4 __const_func rhadd(long4 x, long4 y);
ulong4 __const_func rhadd(ulong4 x, ulong4 y);
long8 __const_func rhadd(long8 x, long8 y);
ulong8 __const_func rhadd(ulong8 x, ulong8 y);
long16 __const_func rhadd(long16 x, long16 y);
ulong16 __const_func rhadd(ulong16 x, ulong16 y);

/**
 * Returns min(max(x, minval), maxval).
 * Results are undefined if minval > maxval.
 */
char __const_func clamp(char x, char minval, char maxval);
uchar __const_func clamp(uchar x, uchar minval, uchar maxval);
char2 __const_func clamp(char2 x, char2 minval, char2 maxval);
uchar2 __const_func clamp(uchar2 x, uchar2 minval, uchar2 maxval);
char3 __const_func clamp(char3 x, char3 minval, char3 maxval);
uchar3 __const_func clamp(uchar3 x, uchar3 minval, uchar3 maxval);
char4 __const_func clamp(char4 x, char4 minval, char4 maxval);
uchar4 __const_func clamp(uchar4 x, uchar4 minval, uchar4 maxval);
char8 __const_func clamp(char8 x, char8 minval, char8 maxval);
uchar8 __const_func clamp(uchar8 x, uchar8 minval, uchar8 maxval);
char16 __const_func clamp(char16 x, char16 minval, char16 maxval);
uchar16 __const_func clamp(uchar16 x, uchar16 minval, uchar16 maxval);
short __const_func clamp(short x, short minval, short maxval);
ushort __const_func clamp(ushort x, ushort minval, ushort maxval);
short2 __const_func clamp(short2 x, short2 minval, short2 maxval);
ushort2 __const_func clamp(ushort2 x, ushort2 minval, ushort2 maxval);
short3 __const_func clamp(short3 x, short3 minval, short3 maxval);
ushort3 __const_func clamp(ushort3 x, ushort3 minval, ushort3 maxval);
short4 __const_func clamp(short4 x, short4 minval, short4 maxval);
ushort4 __const_func clamp(ushort4 x, ushort4 minval, ushort4 maxval);
short8 __const_func clamp(short8 x, short8 minval, short8 maxval);
ushort8 __const_func clamp(ushort8 x, ushort8 minval, ushort8 maxval);
short16 __const_func clamp(short16 x, short16 minval, short16 maxval);
ushort16 __const_func clamp(ushort16 x, ushort16 minval, ushort16 maxval);
int __const_func clamp(int x, int minval, int maxval);
uint __const_func clamp(uint x, uint minval, uint maxval);
int2 __const_func clamp(int2 x, int2 minval, int2 maxval);
uint2 __const_func clamp(uint2 x, uint2 minval, uint2 maxval);
int3 __const_func clamp(int3 x, int3 minval, int3 maxval);
uint3 __const_func clamp(uint3 x, uint3 minval, uint3 maxval);
int4 __const_func clamp(int4 x, int4 minval, int4 maxval);
uint4 __const_func clamp(uint4 x, uint4 minval, uint4 maxval);
int8 __const_func clamp(int8 x, int8 minval, int8 maxval);
uint8 __const_func clamp(uint8 x, uint8 minval, uint8 maxval);
int16 __const_func clamp(int16 x, int16 minval, int16 maxval);
uint16 __const_func clamp(uint16 x, uint16 minval, uint16 maxval);
long __const_func clamp(long x, long minval, long maxval);
ulong __const_func clamp(ulong x, ulong minval, ulong maxval);
long2 __const_func clamp(long2 x, long2 minval, long2 maxval);
ulong2 __const_func clamp(ulong2 x, ulong2 minval, ulong2 maxval);
long3 __const_func clamp(long3 x, long3 minval, long3 maxval);
ulong3 __const_func clamp(ulong3 x, ulong3 minval, ulong3 maxval);
long4 __const_func clamp(long4 x, long4 minval, long4 maxval);
ulong4 __const_func clamp(ulong4 x, ulong4 minval, ulong4 maxval);
long8 __const_func clamp(long8 x, long8 minval, long8 maxval);
ulong8 __const_func clamp(ulong8 x, ulong8 minval, ulong8 maxval);
long16 __const_func clamp(long16 x, long16 minval, long16 maxval);
ulong16 __const_func clamp(ulong16 x, ulong16 minval, ulong16 maxval);
char __const_func clamp(char x, char minval, char maxval);
uchar __const_func clamp(uchar x, uchar minval, uchar maxval);
char2 __const_func clamp(char2 x, char minval, char maxval);
uchar2 __const_func clamp(uchar2 x, uchar minval, uchar maxval);
char3 __const_func clamp(char3 x, char minval, char maxval);
uchar3 __const_func clamp(uchar3 x, uchar minval, uchar maxval);
char4 __const_func clamp(char4 x, char minval, char maxval);
uchar4 __const_func clamp(uchar4 x, uchar minval, uchar maxval);
char8 __const_func clamp(char8 x, char minval, char maxval);
uchar8 __const_func clamp(uchar8 x, uchar minval, uchar maxval);
char16 __const_func clamp(char16 x, char minval, char maxval);
uchar16 __const_func clamp(uchar16 x, uchar minval, uchar maxval);
short __const_func clamp(short x, short minval, short maxval);
ushort __const_func clamp(ushort x, ushort minval, ushort maxval);
short2 __const_func clamp(short2 x, short minval, short maxval);
ushort2 __const_func clamp(ushort2 x, ushort minval, ushort maxval);
short3 __const_func clamp(short3 x, short minval, short maxval);
ushort3 __const_func clamp(ushort3 x, ushort minval, ushort maxval);
short4 __const_func clamp(short4 x, short minval, short maxval);
ushort4 __const_func clamp(ushort4 x, ushort minval, ushort maxval);
short8 __const_func clamp(short8 x, short minval, short maxval);
ushort8 __const_func clamp(ushort8 x, ushort minval, ushort maxval);
short16 __const_func clamp(short16 x, short minval, short maxval);
ushort16 __const_func clamp(ushort16 x, ushort minval, ushort maxval);
int __const_func clamp(int x, int minval, int maxval);
uint __const_func clamp(uint x, uint minval, uint maxval);
int2 __const_func clamp(int2 x, int minval, int maxval);
uint2 __const_func clamp(uint2 x, uint minval, uint maxval);
int3 __const_func clamp(int3 x, int minval, int maxval);
uint3 __const_func clamp(uint3 x, uint minval, uint maxval);
int4 __const_func clamp(int4 x, int minval, int maxval);
uint4 __const_func clamp(uint4 x, uint minval, uint maxval);
int8 __const_func clamp(int8 x, int minval, int maxval);
uint8 __const_func clamp(uint8 x, uint minval, uint maxval);
int16 __const_func clamp(int16 x, int minval, int maxval);
uint16 __const_func clamp(uint16 x, uint minval, uint maxval);
long __const_func clamp(long x, long minval, long maxval);
ulong __const_func clamp(ulong x, ulong minval, ulong maxval);
long2 __const_func clamp(long2 x, long minval, long maxval);
ulong2 __const_func clamp(ulong2 x, ulong minval, ulong maxval);
long3 __const_func clamp(long3 x, long minval, long maxval);
ulong3 __const_func clamp(ulong3 x, ulong minval, ulong maxval);
long4 __const_func clamp(long4 x, long minval, long maxval);
ulong4 __const_func clamp(ulong4 x, ulong minval, ulong maxval);
long8 __const_func clamp(long8 x, long minval, long maxval);
ulong8 __const_func clamp(ulong8 x, ulong minval, ulong maxval);
long16 __const_func clamp(long16 x, long minval, long maxval);
ulong16 __const_func clamp(ulong16 x, ulong minval, ulong maxval);

/**
 * Returns the number of leading 0-bits in x, starting
 * at the most significant bit position.
 */
char __const_func clz(char x);
uchar __const_func clz(uchar x);
char2 __const_func clz(char2 x);
uchar2 __const_func clz(uchar2 x);
char3 __const_func clz(char3 x);
uchar3 __const_func clz(uchar3 x);
char4 __const_func clz(char4 x);
uchar4 __const_func clz(uchar4 x);
char8 __const_func clz(char8 x);
uchar8 __const_func clz(uchar8 x);
char16 __const_func clz(char16 x);
uchar16 __const_func clz(uchar16 x);
short __const_func clz(short x);
ushort __const_func clz(ushort x);
short2 __const_func clz(short2 x);
ushort2 __const_func clz(ushort2 x);
short3 __const_func clz(short3 x);
ushort3 __const_func clz(ushort3 x);
short4 __const_func clz(short4 x);
ushort4 __const_func clz(ushort4 x);
short8 __const_func clz(short8 x);
ushort8 __const_func clz(ushort8 x);
short16 __const_func clz(short16 x);
ushort16 __const_func clz(ushort16 x);
int __const_func clz(int x);
uint __const_func clz(uint x);
int2 __const_func clz(int2 x);
uint2 __const_func clz(uint2 x);
int3 __const_func clz(int3 x);
uint3 __const_func clz(uint3 x);
int4 __const_func clz(int4 x);
uint4 __const_func clz(uint4 x);
int8 __const_func clz(int8 x);
uint8 __const_func clz(uint8 x);
int16 __const_func clz(int16 x);
uint16 __const_func clz(uint16 x);
long __const_func clz(long x);
ulong __const_func clz(ulong x);
long2 __const_func clz(long2 x);
ulong2 __const_func clz(ulong2 x);
long3 __const_func clz(long3 x);
ulong3 __const_func clz(ulong3 x);
long4 __const_func clz(long4 x);
ulong4 __const_func clz(ulong4 x);
long8 __const_func clz(long8 x);
ulong8 __const_func clz(ulong8 x);
long16 __const_func clz(long16 x);
ulong16 __const_func clz(ulong16 x);

/**
 * Returns the count of trailing 0-bits in x. If x is 0,
 * returns the size in bits of the type of x or
 * component type of x, if x is a vector.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
char __overload ctz(char x);
uchar __overload ctz(uchar x);
char2 __overload ctz(char2 x);
uchar2 __overload ctz(uchar2 x);
char3 __overload ctz(char3 x);
uchar3 __overload ctz(uchar3 x);
char4 __overload ctz(char4 x);
uchar4 __overload ctz(uchar4 x);
char8 __overload ctz(char8 x);
uchar8 __overload ctz(uchar8 x);
char16 __overload ctz(char16 x);
uchar16 __overload ctz(uchar16 x);
short __overload ctz(short x);
ushort __overload ctz(ushort x);
short2 __overload ctz(short2 x);
ushort2 __overload ctz(ushort2 x);
short3 __overload ctz(short3 x);
ushort3 __overload ctz(ushort3 x);
short4 __overload ctz(short4 x);
ushort4 __overload ctz(ushort4 x);
short8 __overload ctz(short8 x);
ushort8 __overload ctz(ushort8 x);
short16 __overload ctz(short16 x);
ushort16 __overload ctz(ushort16 x);
int __overload ctz(int x);
uint __overload ctz(uint x);
int2 __overload ctz(int2 x);
uint2 __overload ctz(uint2 x);
int3 __overload ctz(int3 x);
uint3 __overload ctz(uint3 x);
int4 __overload ctz(int4 x);
uint4 __overload ctz(uint4 x);
int8 __overload ctz(int8 x);
uint8 __overload ctz(uint8 x);
int16 __overload ctz(int16 x);
uint16 __overload ctz(uint16 x);
long __overload ctz(long x);
ulong __overload ctz(ulong x);
long2 __overload ctz(long2 x);
ulong2 __overload ctz(ulong2 x);
long3 __overload ctz(long3 x);
ulong3 __overload ctz(ulong3 x);
long4 __overload ctz(long4 x);
ulong4 __overload ctz(ulong4 x);
long8 __overload ctz(long8 x);
ulong8 __overload ctz(ulong8 x);
long16 __overload ctz(long16 x);
ulong16 __overload ctz(ulong16 x);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Returns mul_hi(a, b) + c.
 */
char __const_func mad_hi(char a, char b, char c);
uchar __const_func mad_hi(uchar a, uchar b, uchar c);
char2 __const_func mad_hi(char2 a, char2 b, char2 c);
uchar2 __const_func mad_hi(uchar2 a, uchar2 b, uchar2 c);
char3 __const_func mad_hi(char3 a, char3 b, char3 c);
uchar3 __const_func mad_hi(uchar3 a, uchar3 b, uchar3 c);
char4 __const_func mad_hi(char4 a, char4 b, char4 c);
uchar4 __const_func mad_hi(uchar4 a, uchar4 b, uchar4 c);
char8 __const_func mad_hi(char8 a, char8 b, char8 c);
uchar8 __const_func mad_hi(uchar8 a, uchar8 b, uchar8 c);
char16 __const_func mad_hi(char16 a, char16 b, char16 c);
uchar16 __const_func mad_hi(uchar16 a, uchar16 b, uchar16 c);
short __const_func mad_hi(short a, short b, short c);
ushort __const_func mad_hi(ushort a, ushort b, ushort c);
short2 __const_func mad_hi(short2 a, short2 b, short2 c);
ushort2 __const_func mad_hi(ushort2 a, ushort2 b, ushort2 c);
short3 __const_func mad_hi(short3 a, short3 b, short3 c);
ushort3 __const_func mad_hi(ushort3 a, ushort3 b, ushort3 c);
short4 __const_func mad_hi(short4 a, short4 b, short4 c);
ushort4 __const_func mad_hi(ushort4 a, ushort4 b, ushort4 c);
short8 __const_func mad_hi(short8 a, short8 b, short8 c);
ushort8 __const_func mad_hi(ushort8 a, ushort8 b, ushort8 c);
short16 __const_func mad_hi(short16 a, short16 b, short16 c);
ushort16 __const_func mad_hi(ushort16 a, ushort16 b, ushort16 c);
int __const_func mad_hi(int a, int b, int c);
uint __const_func mad_hi(uint a, uint b, uint c);
int2 __const_func mad_hi(int2 a, int2 b, int2 c);
uint2 __const_func mad_hi(uint2 a, uint2 b, uint2 c);
int3 __const_func mad_hi(int3 a, int3 b, int3 c);
uint3 __const_func mad_hi(uint3 a, uint3 b, uint3 c);
int4 __const_func mad_hi(int4 a, int4 b, int4 c);
uint4 __const_func mad_hi(uint4 a, uint4 b, uint4 c);
int8 __const_func mad_hi(int8 a, int8 b, int8 c);
uint8 __const_func mad_hi(uint8 a, uint8 b, uint8 c);
int16 __const_func mad_hi(int16 a, int16 b, int16 c);
uint16 __const_func mad_hi(uint16 a, uint16 b, uint16 c);
long __const_func mad_hi(long a, long b, long c);
ulong __const_func mad_hi(ulong a, ulong b, ulong c);
long2 __const_func mad_hi(long2 a, long2 b, long2 c);
ulong2 __const_func mad_hi(ulong2 a, ulong2 b, ulong2 c);
long3 __const_func mad_hi(long3 a, long3 b, long3 c);
ulong3 __const_func mad_hi(ulong3 a, ulong3 b, ulong3 c);
long4 __const_func mad_hi(long4 a, long4 b, long4 c);
ulong4 __const_func mad_hi(ulong4 a, ulong4 b, ulong4 c);
long8 __const_func mad_hi(long8 a, long8 b, long8 c);
ulong8 __const_func mad_hi(ulong8 a, ulong8 b, ulong8 c);
long16 __const_func mad_hi(long16 a, long16 b, long16 c);
ulong16 __const_func mad_hi(ulong16 a, ulong16 b, ulong16 c);

/**
 * Returns a * b + c and saturates the result.
 */
char __const_func mad_sat(char a, char b, char c);
uchar __const_func mad_sat(uchar a, uchar b, uchar c);
char2 __const_func mad_sat(char2 a, char2 b, char2 c);
uchar2 __const_func mad_sat(uchar2 a, uchar2 b, uchar2 c);
char3 __const_func mad_sat(char3 a, char3 b, char3 c);
uchar3 __const_func mad_sat(uchar3 a, uchar3 b, uchar3 c);
char4 __const_func mad_sat(char4 a, char4 b, char4 c);
uchar4 __const_func mad_sat(uchar4 a, uchar4 b, uchar4 c);
char8 __const_func mad_sat(char8 a, char8 b, char8 c);
uchar8 __const_func mad_sat(uchar8 a, uchar8 b, uchar8 c);
char16 __const_func mad_sat(char16 a, char16 b, char16 c);
uchar16 __const_func mad_sat(uchar16 a, uchar16 b, uchar16 c);
short __const_func mad_sat(short a, short b, short c);
ushort __const_func mad_sat(ushort a, ushort b, ushort c);
short2 __const_func mad_sat(short2 a, short2 b, short2 c);
ushort2 __const_func mad_sat(ushort2 a, ushort2 b, ushort2 c);
short3 __const_func mad_sat(short3 a, short3 b, short3 c);
ushort3 __const_func mad_sat(ushort3 a, ushort3 b, ushort3 c);
short4 __const_func mad_sat(short4 a, short4 b, short4 c);
ushort4 __const_func mad_sat(ushort4 a, ushort4 b, ushort4 c);
short8 __const_func mad_sat(short8 a, short8 b, short8 c);
ushort8 __const_func mad_sat(ushort8 a, ushort8 b, ushort8 c);
short16 __const_func mad_sat(short16 a, short16 b, short16 c);
ushort16 __const_func mad_sat(ushort16 a, ushort16 b, ushort16 c);
int __const_func mad_sat(int a, int b, int c);
uint __const_func mad_sat(uint a, uint b, uint c);
int2 __const_func mad_sat(int2 a, int2 b, int2 c);
uint2 __const_func mad_sat(uint2 a, uint2 b, uint2 c);
int3 __const_func mad_sat(int3 a, int3 b, int3 c);
uint3 __const_func mad_sat(uint3 a, uint3 b, uint3 c);
int4 __const_func mad_sat(int4 a, int4 b, int4 c);
uint4 __const_func mad_sat(uint4 a, uint4 b, uint4 c);
int8 __const_func mad_sat(int8 a, int8 b, int8 c);
uint8 __const_func mad_sat(uint8 a, uint8 b, uint8 c);
int16 __const_func mad_sat(int16 a, int16 b, int16 c);
uint16 __const_func mad_sat(uint16 a, uint16 b, uint16 c);
long __const_func mad_sat(long a, long b, long c);
ulong __const_func mad_sat(ulong a, ulong b, ulong c);
long2 __const_func mad_sat(long2 a, long2 b, long2 c);
ulong2 __const_func mad_sat(ulong2 a, ulong2 b, ulong2 c);
long3 __const_func mad_sat(long3 a, long3 b, long3 c);
ulong3 __const_func mad_sat(ulong3 a, ulong3 b, ulong3 c);
long4 __const_func mad_sat(long4 a, long4 b, long4 c);
ulong4 __const_func mad_sat(ulong4 a, ulong4 b, ulong4 c);
long8 __const_func mad_sat(long8 a, long8 b, long8 c);
ulong8 __const_func mad_sat(ulong8 a, ulong8 b, ulong8 c);
long16 __const_func mad_sat(long16 a, long16 b, long16 c);
ulong16 __const_func mad_sat(ulong16 a, ulong16 b, ulong16 c);

/**
 * Returns y if x < y, otherwise it returns x.
 */
char __const_func max(char x, char y);
uchar __const_func max(uchar x, uchar y);
char2 __const_func max(char2 x, char2 y);
uchar2 __const_func max(uchar2 x, uchar2 y);
char3 __const_func max(char3 x, char3 y);
uchar3 __const_func max(uchar3 x, uchar3 y);
char4 __const_func max(char4 x, char4 y);
uchar4 __const_func max(uchar4 x, uchar4 y);
char8 __const_func max(char8 x, char8 y);
uchar8 __const_func max(uchar8 x, uchar8 y);
char16 __const_func max(char16 x, char16 y);
uchar16 __const_func max(uchar16 x, uchar16 y);
short __const_func max(short x, short y);
ushort __const_func max(ushort x, ushort y);
short2 __const_func max(short2 x, short2 y);
ushort2 __const_func max(ushort2 x, ushort2 y);
short3 __const_func max(short3 x, short3 y);
ushort3 __const_func max(ushort3 x, ushort3 y);
short4 __const_func max(short4 x, short4 y);
ushort4 __const_func max(ushort4 x, ushort4 y);
short8 __const_func max(short8 x, short8 y);
ushort8 __const_func max(ushort8 x, ushort8 y);
short16 __const_func max(short16 x, short16 y);
ushort16 __const_func max(ushort16 x, ushort16 y);
int __const_func max(int x, int y);
uint __const_func max(uint x, uint y);
int2 __const_func max(int2 x, int2 y);
uint2 __const_func max(uint2 x, uint2 y);
int3 __const_func max(int3 x, int3 y);
uint3 __const_func max(uint3 x, uint3 y);
int4 __const_func max(int4 x, int4 y);
uint4 __const_func max(uint4 x, uint4 y);
int8 __const_func max(int8 x, int8 y);
uint8 __const_func max(uint8 x, uint8 y);
int16 __const_func max(int16 x, int16 y);
uint16 __const_func max(uint16 x, uint16 y);
long __const_func max(long x, long y);
ulong __const_func max(ulong x, ulong y);
long2 __const_func max(long2 x, long2 y);
ulong2 __const_func max(ulong2 x, ulong2 y);
long3 __const_func max(long3 x, long3 y);
ulong3 __const_func max(ulong3 x, ulong3 y);
long4 __const_func max(long4 x, long4 y);
ulong4 __const_func max(ulong4 x, ulong4 y);
long8 __const_func max(long8 x, long8 y);
ulong8 __const_func max(ulong8 x, ulong8 y);
long16 __const_func max(long16 x, long16 y);
ulong16 __const_func max(ulong16 x, ulong16 y);
char __const_func max(char x, char y);
uchar __const_func max(uchar x, uchar y);
char2 __const_func max(char2 x, char y);
uchar2 __const_func max(uchar2 x, uchar y);
char3 __const_func max(char3 x, char y);
uchar3 __const_func max(uchar3 x, uchar y);
char4 __const_func max(char4 x, char y);
uchar4 __const_func max(uchar4 x, uchar y);
char8 __const_func max(char8 x, char y);
uchar8 __const_func max(uchar8 x, uchar y);
char16 __const_func max(char16 x, char y);
uchar16 __const_func max(uchar16 x, uchar y);
short __const_func max(short x, short y);
ushort __const_func max(ushort x, ushort y);
short2 __const_func max(short2 x, short y);
ushort2 __const_func max(ushort2 x, ushort y);
short3 __const_func max(short3 x, short y);
ushort3 __const_func max(ushort3 x, ushort y);
short4 __const_func max(short4 x, short y);
ushort4 __const_func max(ushort4 x, ushort y);
short8 __const_func max(short8 x, short y);
ushort8 __const_func max(ushort8 x, ushort y);
short16 __const_func max(short16 x, short y);
ushort16 __const_func max(ushort16 x, ushort y);
int __const_func max(int x, int y);
uint __const_func max(uint x, uint y);
int2 __const_func max(int2 x, int y);
uint2 __const_func max(uint2 x, uint y);
int3 __const_func max(int3 x, int y);
uint3 __const_func max(uint3 x, uint y);
int4 __const_func max(int4 x, int y);
uint4 __const_func max(uint4 x, uint y);
int8 __const_func max(int8 x, int y);
uint8 __const_func max(uint8 x, uint y);
int16 __const_func max(int16 x, int y);
uint16 __const_func max(uint16 x, uint y);
long __const_func max(long x, long y);
ulong __const_func max(ulong x, ulong y);
long2 __const_func max(long2 x, long y);
ulong2 __const_func max(ulong2 x, ulong y);
long3 __const_func max(long3 x, long y);
ulong3 __const_func max(ulong3 x, ulong y);
long4 __const_func max(long4 x, long y);
ulong4 __const_func max(ulong4 x, ulong y);
long8 __const_func max(long8 x, long y);
ulong8 __const_func max(ulong8 x, ulong y);
long16 __const_func max(long16 x, long y);
ulong16 __const_func max(ulong16 x, ulong y);

/**
 * Returns y if y < x, otherwise it returns x.
 */
char __const_func min(char x, char y);
uchar __const_func min(uchar x, uchar y);
char2 __const_func min(char2 x, char2 y);
uchar2 __const_func min(uchar2 x, uchar2 y);
char3 __const_func min(char3 x, char3 y);
uchar3 __const_func min(uchar3 x, uchar3 y);
char4 __const_func min(char4 x, char4 y);
uchar4 __const_func min(uchar4 x, uchar4 y);
char8 __const_func min(char8 x, char8 y);
uchar8 __const_func min(uchar8 x, uchar8 y);
char16 __const_func min(char16 x, char16 y);
uchar16 __const_func min(uchar16 x, uchar16 y);
short __const_func min(short x, short y);
ushort __const_func min(ushort x, ushort y);
short2 __const_func min(short2 x, short2 y);
ushort2 __const_func min(ushort2 x, ushort2 y);
short3 __const_func min(short3 x, short3 y);
ushort3 __const_func min(ushort3 x, ushort3 y);
short4 __const_func min(short4 x, short4 y);
ushort4 __const_func min(ushort4 x, ushort4 y);
short8 __const_func min(short8 x, short8 y);
ushort8 __const_func min(ushort8 x, ushort8 y);
short16 __const_func min(short16 x, short16 y);
ushort16 __const_func min(ushort16 x, ushort16 y);
int __const_func min(int x, int y);
uint __const_func min(uint x, uint y);
int2 __const_func min(int2 x, int2 y);
uint2 __const_func min(uint2 x, uint2 y);
int3 __const_func min(int3 x, int3 y);
uint3 __const_func min(uint3 x, uint3 y);
int4 __const_func min(int4 x, int4 y);
uint4 __const_func min(uint4 x, uint4 y);
int8 __const_func min(int8 x, int8 y);
uint8 __const_func min(uint8 x, uint8 y);
int16 __const_func min(int16 x, int16 y);
uint16 __const_func min(uint16 x, uint16 y);
long __const_func min(long x, long y);
ulong __const_func min(ulong x, ulong y);
long2 __const_func min(long2 x, long2 y);
ulong2 __const_func min(ulong2 x, ulong2 y);
long3 __const_func min(long3 x, long3 y);
ulong3 __const_func min(ulong3 x, ulong3 y);
long4 __const_func min(long4 x, long4 y);
ulong4 __const_func min(ulong4 x, ulong4 y);
long8 __const_func min(long8 x, long8 y);
ulong8 __const_func min(ulong8 x, ulong8 y);
long16 __const_func min(long16 x, long16 y);
ulong16 __const_func min(ulong16 x, ulong16 y);
char __const_func min(char x, char y);
uchar __const_func min(uchar x, uchar y);
char2 __const_func min(char2 x, char y);
uchar2 __const_func min(uchar2 x, uchar y);
char3 __const_func min(char3 x, char y);
uchar3 __const_func min(uchar3 x, uchar y);
char4 __const_func min(char4 x, char y);
uchar4 __const_func min(uchar4 x, uchar y);
char8 __const_func min(char8 x, char y);
uchar8 __const_func min(uchar8 x, uchar y);
char16 __const_func min(char16 x, char y);
uchar16 __const_func min(uchar16 x, uchar y);
short __const_func min(short x, short y);
ushort __const_func min(ushort x, ushort y);
short2 __const_func min(short2 x, short y);
ushort2 __const_func min(ushort2 x, ushort y);
short3 __const_func min(short3 x, short y);
ushort3 __const_func min(ushort3 x, ushort y);
short4 __const_func min(short4 x, short y);
ushort4 __const_func min(ushort4 x, ushort y);
short8 __const_func min(short8 x, short y);
ushort8 __const_func min(ushort8 x, ushort y);
short16 __const_func min(short16 x, short y);
ushort16 __const_func min(ushort16 x, ushort y);
int __const_func min(int x, int y);
uint __const_func min(uint x, uint y);
int2 __const_func min(int2 x, int y);
uint2 __const_func min(uint2 x, uint y);
int3 __const_func min(int3 x, int y);
uint3 __const_func min(uint3 x, uint y);
int4 __const_func min(int4 x, int y);
uint4 __const_func min(uint4 x, uint y);
int8 __const_func min(int8 x, int y);
uint8 __const_func min(uint8 x, uint y);
int16 __const_func min(int16 x, int y);
uint16 __const_func min(uint16 x, uint y);
long __const_func min(long x, long y);
ulong __const_func min(ulong x, ulong y);
long2 __const_func min(long2 x, long y);
ulong2 __const_func min(ulong2 x, ulong y);
long3 __const_func min(long3 x, long y);
ulong3 __const_func min(ulong3 x, ulong y);
long4 __const_func min(long4 x, long y);
ulong4 __const_func min(ulong4 x, ulong y);
long8 __const_func min(long8 x, long y);
ulong8 __const_func min(ulong8 x, ulong y);
long16 __const_func min(long16 x, long y);
ulong16 __const_func min(ulong16 x, ulong y);

/**
 * Computes x * y and returns the high half of the
 * product of x and y.
 */
char __const_func mul_hi(char x, char y);
uchar __const_func mul_hi(uchar x, uchar y);
char2 __const_func mul_hi(char2 x, char2 y);
uchar2 __const_func mul_hi(uchar2 x, uchar2 y);
char3 __const_func mul_hi(char3 x, char3 y);
uchar3 __const_func mul_hi(uchar3 x, uchar3 y);
char4 __const_func mul_hi(char4 x, char4 y);
uchar4 __const_func mul_hi(uchar4 x, uchar4 y);
char8 __const_func mul_hi(char8 x, char8 y);
uchar8 __const_func mul_hi(uchar8 x, uchar8 y);
char16 __const_func mul_hi(char16 x, char16 y);
uchar16 __const_func mul_hi(uchar16 x, uchar16 y);
short __const_func mul_hi(short x, short y);
ushort __const_func mul_hi(ushort x, ushort y);
short2 __const_func mul_hi(short2 x, short2 y);
ushort2 __const_func mul_hi(ushort2 x, ushort2 y);
short3 __const_func mul_hi(short3 x, short3 y);
ushort3 __const_func mul_hi(ushort3 x, ushort3 y);
short4 __const_func mul_hi(short4 x, short4 y);
ushort4 __const_func mul_hi(ushort4 x, ushort4 y);
short8 __const_func mul_hi(short8 x, short8 y);
ushort8 __const_func mul_hi(ushort8 x, ushort8 y);
short16 __const_func mul_hi(short16 x, short16 y);
ushort16 __const_func mul_hi(ushort16 x, ushort16 y);
int __const_func mul_hi(int x, int y);
uint __const_func mul_hi(uint x, uint y);
int2 __const_func mul_hi(int2 x, int2 y);
uint2 __const_func mul_hi(uint2 x, uint2 y);
int3 __const_func mul_hi(int3 x, int3 y);
uint3 __const_func mul_hi(uint3 x, uint3 y);
int4 __const_func mul_hi(int4 x, int4 y);
uint4 __const_func mul_hi(uint4 x, uint4 y);
int8 __const_func mul_hi(int8 x, int8 y);
uint8 __const_func mul_hi(uint8 x, uint8 y);
int16 __const_func mul_hi(int16 x, int16 y);
uint16 __const_func mul_hi(uint16 x, uint16 y);
long __const_func mul_hi(long x, long y);
ulong __const_func mul_hi(ulong x, ulong y);
long2 __const_func mul_hi(long2 x, long2 y);
ulong2 __const_func mul_hi(ulong2 x, ulong2 y);
long3 __const_func mul_hi(long3 x, long3 y);
ulong3 __const_func mul_hi(ulong3 x, ulong3 y);
long4 __const_func mul_hi(long4 x, long4 y);
ulong4 __const_func mul_hi(ulong4 x, ulong4 y);
long8 __const_func mul_hi(long8 x, long8 y);
ulong8 __const_func mul_hi(ulong8 x, ulong8 y);
long16 __const_func mul_hi(long16 x, long16 y);
ulong16 __const_func mul_hi(ulong16 x, ulong16 y);

/**
 * For each element in v, the bits are shifted left by
 * the number of bits given by the corresponding
 * element in i (subject to usual shift modulo rules
 * described in section 6.3). Bits shifted off the left
 * side of the element are shifted back in from the
 * right.
 */
char __const_func rotate(char v, char i);
uchar __const_func rotate(uchar v, uchar i);
char2 __const_func rotate(char2 v, char2 i);
uchar2 __const_func rotate(uchar2 v, uchar2 i);
char3 __const_func rotate(char3 v, char3 i);
uchar3 __const_func rotate(uchar3 v, uchar3 i);
char4 __const_func rotate(char4 v, char4 i);
uchar4 __const_func rotate(uchar4 v, uchar4 i);
char8 __const_func rotate(char8 v, char8 i);
uchar8 __const_func rotate(uchar8 v, uchar8 i);
char16 __const_func rotate(char16 v, char16 i);
uchar16 __const_func rotate(uchar16 v, uchar16 i);
short __const_func rotate(short v, short i);
ushort __const_func rotate(ushort v, ushort i);
short2 __const_func rotate(short2 v, short2 i);
ushort2 __const_func rotate(ushort2 v, ushort2 i);
short3 __const_func rotate(short3 v, short3 i);
ushort3 __const_func rotate(ushort3 v, ushort3 i);
short4 __const_func rotate(short4 v, short4 i);
ushort4 __const_func rotate(ushort4 v, ushort4 i);
short8 __const_func rotate(short8 v, short8 i);
ushort8 __const_func rotate(ushort8 v, ushort8 i);
short16 __const_func rotate(short16 v, short16 i);
ushort16 __const_func rotate(ushort16 v, ushort16 i);
int __const_func rotate(int v, int i);
uint __const_func rotate(uint v, uint i);
int2 __const_func rotate(int2 v, int2 i);
uint2 __const_func rotate(uint2 v, uint2 i);
int3 __const_func rotate(int3 v, int3 i);
uint3 __const_func rotate(uint3 v, uint3 i);
int4 __const_func rotate(int4 v, int4 i);
uint4 __const_func rotate(uint4 v, uint4 i);
int8 __const_func rotate(int8 v, int8 i);
uint8 __const_func rotate(uint8 v, uint8 i);
int16 __const_func rotate(int16 v, int16 i);
uint16 __const_func rotate(uint16 v, uint16 i);
long __const_func rotate(long v, long i);
ulong __const_func rotate(ulong v, ulong i);
long2 __const_func rotate(long2 v, long2 i);
ulong2 __const_func rotate(ulong2 v, ulong2 i);
long3 __const_func rotate(long3 v, long3 i);
ulong3 __const_func rotate(ulong3 v, ulong3 i);
long4 __const_func rotate(long4 v, long4 i);
ulong4 __const_func rotate(ulong4 v, ulong4 i);
long8 __const_func rotate(long8 v, long8 i);
ulong8 __const_func rotate(ulong8 v, ulong8 i);
long16 __const_func rotate(long16 v, long16 i);
ulong16 __const_func rotate(ulong16 v, ulong16 i);

/**
 * Returns x - y and saturates the result.
 */
char __const_func sub_sat(char x, char y);
uchar __const_func sub_sat(uchar x, uchar y);
char2 __const_func sub_sat(char2 x, char2 y);
uchar2 __const_func sub_sat(uchar2 x, uchar2 y);
char3 __const_func sub_sat(char3 x, char3 y);
uchar3 __const_func sub_sat(uchar3 x, uchar3 y);
char4 __const_func sub_sat(char4 x, char4 y);
uchar4 __const_func sub_sat(uchar4 x, uchar4 y);
char8 __const_func sub_sat(char8 x, char8 y);
uchar8 __const_func sub_sat(uchar8 x, uchar8 y);
char16 __const_func sub_sat(char16 x, char16 y);
uchar16 __const_func sub_sat(uchar16 x, uchar16 y);
short __const_func sub_sat(short x, short y);
ushort __const_func sub_sat(ushort x, ushort y);
short2 __const_func sub_sat(short2 x, short2 y);
ushort2 __const_func sub_sat(ushort2 x, ushort2 y);
short3 __const_func sub_sat(short3 x, short3 y);
ushort3 __const_func sub_sat(ushort3 x, ushort3 y);
short4 __const_func sub_sat(short4 x, short4 y);
ushort4 __const_func sub_sat(ushort4 x, ushort4 y);
short8 __const_func sub_sat(short8 x, short8 y);
ushort8 __const_func sub_sat(ushort8 x, ushort8 y);
short16 __const_func sub_sat(short16 x, short16 y);
ushort16 __const_func sub_sat(ushort16 x, ushort16 y);
int __const_func sub_sat(int x, int y);
uint __const_func sub_sat(uint x, uint y);
int2 __const_func sub_sat(int2 x, int2 y);
uint2 __const_func sub_sat(uint2 x, uint2 y);
int3 __const_func sub_sat(int3 x, int3 y);
uint3 __const_func sub_sat(uint3 x, uint3 y);
int4 __const_func sub_sat(int4 x, int4 y);
uint4 __const_func sub_sat(uint4 x, uint4 y);
int8 __const_func sub_sat(int8 x, int8 y);
uint8 __const_func sub_sat(uint8 x, uint8 y);
int16 __const_func sub_sat(int16 x, int16 y);
uint16 __const_func sub_sat(uint16 x, uint16 y);
long __const_func sub_sat(long x, long y);
ulong __const_func sub_sat(ulong x, ulong y);
long2 __const_func sub_sat(long2 x, long2 y);
ulong2 __const_func sub_sat(ulong2 x, ulong2 y);
long3 __const_func sub_sat(long3 x, long3 y);
ulong3 __const_func sub_sat(ulong3 x, ulong3 y);
long4 __const_func sub_sat(long4 x, long4 y);
ulong4 __const_func sub_sat(ulong4 x, ulong4 y);
long8 __const_func sub_sat(long8 x, long8 y);
ulong8 __const_func sub_sat(ulong8 x, ulong8 y);
long16 __const_func sub_sat(long16 x, long16 y);
ulong16 __const_func sub_sat(ulong16 x, ulong16 y);

/**
 * result[i] = ((short)hi[i] << 8) | lo[i]
 * result[i] = ((ushort)hi[i] << 8) | lo[i]
 */
short __const_func upsample(char hi, uchar lo);
ushort __const_func upsample(uchar hi, uchar lo);
short2 __const_func upsample(char2 hi, uchar2 lo);
short3 __const_func upsample(char3 hi, uchar3 lo);
short4 __const_func upsample(char4 hi, uchar4 lo);
short8 __const_func upsample(char8 hi, uchar8 lo);
short16 __const_func upsample(char16 hi, uchar16 lo);
ushort2 __const_func upsample(uchar2 hi, uchar2 lo);
ushort3 __const_func upsample(uchar3 hi, uchar3 lo);
ushort4 __const_func upsample(uchar4 hi, uchar4 lo);
ushort8 __const_func upsample(uchar8 hi, uchar8 lo);
ushort16 __const_func upsample(uchar16 hi, uchar16 lo);

/**
 * result[i] = ((int)hi[i] << 16) | lo[i]
 * result[i] = ((uint)hi[i] << 16) | lo[i]
 */
int __const_func upsample(short hi, ushort lo);
uint __const_func upsample(ushort hi, ushort lo);
int2 __const_func upsample(short2 hi, ushort2 lo);
int3 __const_func upsample(short3 hi, ushort3 lo);
int4 __const_func upsample(short4 hi, ushort4 lo);
int8 __const_func upsample(short8 hi, ushort8 lo);
int16 __const_func upsample(short16 hi, ushort16 lo);
uint2 __const_func upsample(ushort2 hi, ushort2 lo);
uint3 __const_func upsample(ushort3 hi, ushort3 lo);
uint4 __const_func upsample(ushort4 hi, ushort4 lo);
uint8 __const_func upsample(ushort8 hi, ushort8 lo);
uint16 __const_func upsample(ushort16 hi, ushort16 lo);
/**
 * result[i] = ((long)hi[i] << 32) | lo[i]
 * result[i] = ((ulong)hi[i] << 32) | lo[i]
 */
long __const_func upsample(int hi, uint lo);
ulong __const_func upsample(uint hi, uint lo);
long2 __const_func upsample(int2 hi, uint2 lo);
long3 __const_func upsample(int3 hi, uint3 lo);
long4 __const_func upsample(int4 hi, uint4 lo);
long8 __const_func upsample(int8 hi, uint8 lo);
long16 __const_func upsample(int16 hi, uint16 lo);
ulong2 __const_func upsample(uint2 hi, uint2 lo);
ulong3 __const_func upsample(uint3 hi, uint3 lo);
ulong4 __const_func upsample(uint4 hi, uint4 lo);
ulong8 __const_func upsample(uint8 hi, uint8 lo);
ulong16 __const_func upsample(uint16 hi, uint16 lo);

/*
 * popcount(x): returns the number of set bit in x
 */
char __const_func popcount(char x);
uchar __const_func popcount(uchar x);
char2 __const_func popcount(char2 x);
uchar2 __const_func popcount(uchar2 x);
char3 __const_func popcount(char3 x);
uchar3 __const_func popcount(uchar3 x);
char4 __const_func popcount(char4 x);
uchar4 __const_func popcount(uchar4 x);
char8 __const_func popcount(char8 x);
uchar8 __const_func popcount(uchar8 x);
char16 __const_func popcount(char16 x);
uchar16 __const_func popcount(uchar16 x);
short __const_func popcount(short x);
ushort __const_func popcount(ushort x);
short2 __const_func popcount(short2 x);
ushort2 __const_func popcount(ushort2 x);
short3 __const_func popcount(short3 x);
ushort3 __const_func popcount(ushort3 x);
short4 __const_func popcount(short4 x);
ushort4 __const_func popcount(ushort4 x);
short8 __const_func popcount(short8 x);
ushort8 __const_func popcount(ushort8 x);
short16 __const_func popcount(short16 x);
ushort16 __const_func popcount(ushort16 x);
int __const_func popcount(int x);
uint __const_func popcount(uint x);
int2 __const_func popcount(int2 x);
uint2 __const_func popcount(uint2 x);
int3 __const_func popcount(int3 x);
uint3 __const_func popcount(uint3 x);
int4 __const_func popcount(int4 x);
uint4 __const_func popcount(uint4 x);
int8 __const_func popcount(int8 x);
uint8 __const_func popcount(uint8 x);
int16 __const_func popcount(int16 x);
uint16 __const_func popcount(uint16 x);
long __const_func popcount(long x);
ulong __const_func popcount(ulong x);
long2 __const_func popcount(long2 x);
ulong2 __const_func popcount(ulong2 x);
long3 __const_func popcount(long3 x);
ulong3 __const_func popcount(ulong3 x);
long4 __const_func popcount(long4 x);
ulong4 __const_func popcount(ulong4 x);
long8 __const_func popcount(long8 x);
ulong8 __const_func popcount(ulong8 x);
long16 __const_func popcount(long16 x);
ulong16 __const_func popcount(ulong16 x);

/**
 * Multiply two 24-bit integer values x and y and add
 * the 32-bit integer result to the 32-bit integer z.
 * Refer to definition of mul24 to see how the 24-bit
 * integer multiplication is performed.
 */
int __const_func mad24(int x, int y, int z);
uint __const_func mad24(uint x, uint y, uint z);
int2 __const_func mad24(int2 x, int2 y, int2 z);
uint2 __const_func mad24(uint2 x, uint2 y, uint2 z);
int3 __const_func mad24(int3 x, int3 y, int3 z);
uint3 __const_func mad24(uint3 x, uint3 y, uint3 z);
int4 __const_func mad24(int4 x, int4 y, int4 z);
uint4 __const_func mad24(uint4 x, uint4 y, uint4 z);
int8 __const_func mad24(int8 x, int8 y, int8 z);
uint8 __const_func mad24(uint8 x, uint8 y, uint8 z);
int16 __const_func mad24(int16 x, int16 y, int16 z);
uint16 __const_func mad24(uint16 x, uint16 y, uint16 z);

/**
 * Multiply two 24-bit integer values x and y. x and y
 * are 32-bit integers but only the low 24-bits are used
 * to perform the multiplication. mul24 should only
 * be used when values in x and y are in the range [-
 * 2^23, 2^23-1] if x and y are signed integers and in the
 * range [0, 2^24-1] if x and y are unsigned integers. If
 * x and y are not in this range, the multiplication
 * result is implementation-defined.
 */
int __const_func mul24(int x, int y);
uint __const_func mul24(uint x, uint y);
int2 __const_func mul24(int2 x, int2 y);
uint2 __const_func mul24(uint2 x, uint2 y);
int3 __const_func mul24(int3 x, int3 y);
uint3 __const_func mul24(uint3 x, uint3 y);
int4 __const_func mul24(int4 x, int4 y);
uint4 __const_func mul24(uint4 x, uint4 y);
int8 __const_func mul24(int8 x, int8 y);
uint8 __const_func mul24(uint8 x, uint8 y);
int16 __const_func mul24(int16 x, int16 y);
uint16 __const_func mul24(uint16 x, uint16 y);

// OpenCL v1.1 s6.11.4, v1.2 s6.12.4, v2.0 s6.13.4 - Common Functions

/**
 * Returns fmin(fmax(x, minval), maxval).
 * Results are undefined if minval > maxval.
 */
float __const_func clamp(float x, float minval, float maxval);
float2 __const_func clamp(float2 x, float2 minval, float2 maxval);
float3 __const_func clamp(float3 x, float3 minval, float3 maxval);
float4 __const_func clamp(float4 x, float4 minval, float4 maxval);
float8 __const_func clamp(float8 x, float8 minval, float8 maxval);
float16 __const_func clamp(float16 x, float16 minval, float16 maxval);
float2 __const_func clamp(float2 x, float minval, float maxval);
float3 __const_func clamp(float3 x, float minval, float maxval);
float4 __const_func clamp(float4 x, float minval, float maxval);
float8 __const_func clamp(float8 x, float minval, float maxval);
float16 __const_func clamp(float16 x, float minval, float maxval);
#ifdef cl_khr_fp64
double __const_func clamp(double x, double minval, double maxval);
double2 __const_func clamp(double2 x, double2 minval, double2 maxval);
double3 __const_func clamp(double3 x, double3 minval, double3 maxval);
double4 __const_func clamp(double4 x, double4 minval, double4 maxval);
double8 __const_func clamp(double8 x, double8 minval, double8 maxval);
double16 __const_func clamp(double16 x, double16 minval, double16 maxval);
double2 __const_func clamp(double2 x, double minval, double maxval);
double3 __const_func clamp(double3 x, double minval, double maxval);
double4 __const_func clamp(double4 x, double minval, double maxval);
double8 __const_func clamp(double8 x, double minval, double maxval);
double16 __const_func clamp(double16 x, double minval, double maxval);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func clamp(half x, half minval, half maxval);
half2 __const_func clamp(half2 x, half2 minval, half2 maxval);
half3 __const_func clamp(half3 x, half3 minval, half3 maxval);
half4 __const_func clamp(half4 x, half4 minval, half4 maxval);
half8 __const_func clamp(half8 x, half8 minval, half8 maxval);
half16 __const_func clamp(half16 x, half16 minval, half16 maxval);
half2 __const_func clamp(half2 x, half minval, half maxval);
half3 __const_func clamp(half3 x, half minval, half maxval);
half4 __const_func clamp(half4 x, half minval, half maxval);
half8 __const_func clamp(half8 x, half minval, half maxval);
half16 __const_func clamp(half16 x, half minval, half maxval);
#endif //cl_khr_fp16

/**
 * Converts radians to degrees, i.e. (180 / PI) *
 * radians.
 */
float __const_func degrees(float radians);
float2 __const_func degrees(float2 radians);
float3 __const_func degrees(float3 radians);
float4 __const_func degrees(float4 radians);
float8 __const_func degrees(float8 radians);
float16 __const_func degrees(float16 radians);
#ifdef cl_khr_fp64
double __const_func degrees(double radians);
double2 __const_func degrees(double2 radians);
double3 __const_func degrees(double3 radians);
double4 __const_func degrees(double4 radians);
double8 __const_func degrees(double8 radians);
double16 __const_func degrees(double16 radians);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func degrees(half radians);
half2 __const_func degrees(half2 radians);
half3 __const_func degrees(half3 radians);
half4 __const_func degrees(half4 radians);
half8 __const_func degrees(half8 radians);
half16 __const_func degrees(half16 radians);
#endif //cl_khr_fp16

/**
 * Returns y if x < y, otherwise it returns x. If x and y
 * are infinite or NaN, the return values are undefined.
 */
float __const_func max(float x, float y);
float2 __const_func max(float2 x, float2 y);
float3 __const_func max(float3 x, float3 y);
float4 __const_func max(float4 x, float4 y);
float8 __const_func max(float8 x, float8 y);
float16 __const_func max(float16 x, float16 y);
float2 __const_func max(float2 x, float y);
float3 __const_func max(float3 x, float y);
float4 __const_func max(float4 x, float y);
float8 __const_func max(float8 x, float y);
float16 __const_func max(float16 x, float y);
#ifdef cl_khr_fp64
double __const_func max(double x, double y);
double2 __const_func max(double2 x, double2 y);
double3 __const_func max(double3 x, double3 y);
double4 __const_func max(double4 x, double4 y);
double8 __const_func max(double8 x, double8 y);
double16 __const_func max(double16 x, double16 y);
double2 __const_func max(double2 x, double y);
double3 __const_func max(double3 x, double y);
double4 __const_func max(double4 x, double y);
double8 __const_func max(double8 x, double y);
double16 __const_func max(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func max(half x, half y);
half2 __const_func max(half2 x, half2 y);
half3 __const_func max(half3 x, half3 y);
half4 __const_func max(half4 x, half4 y);
half8 __const_func max(half8 x, half8 y);
half16 __const_func max(half16 x, half16 y);
half2 __const_func max(half2 x, half y);
half3 __const_func max(half3 x, half y);
half4 __const_func max(half4 x, half y);
half8 __const_func max(half8 x, half y);
half16 __const_func max(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Returns y if y < x, otherwise it returns x. If x and y
 * are infinite or NaN, the return values are undefined.
 */
float __const_func min(float x, float y);
float2 __const_func min(float2 x, float2 y);
float3 __const_func min(float3 x, float3 y);
float4 __const_func min(float4 x, float4 y);
float8 __const_func min(float8 x, float8 y);
float16 __const_func min(float16 x, float16 y);
float2 __const_func min(float2 x, float y);
float3 __const_func min(float3 x, float y);
float4 __const_func min(float4 x, float y);
float8 __const_func min(float8 x, float y);
float16 __const_func min(float16 x, float y);
#ifdef cl_khr_fp64
double __const_func min(double x, double y);
double2 __const_func min(double2 x, double2 y);
double3 __const_func min(double3 x, double3 y);
double4 __const_func min(double4 x, double4 y);
double8 __const_func min(double8 x, double8 y);
double16 __const_func min(double16 x, double16 y);
double2 __const_func min(double2 x, double y);
double3 __const_func min(double3 x, double y);
double4 __const_func min(double4 x, double y);
double8 __const_func min(double8 x, double y);
double16 __const_func min(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func min(half x, half y);
half2 __const_func min(half2 x, half2 y);
half3 __const_func min(half3 x, half3 y);
half4 __const_func min(half4 x, half4 y);
half8 __const_func min(half8 x, half8 y);
half16 __const_func min(half16 x, half16 y);
half2 __const_func min(half2 x, half y);
half3 __const_func min(half3 x, half y);
half4 __const_func min(half4 x, half y);
half8 __const_func min(half8 x, half y);
half16 __const_func min(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Returns the linear blend of x & y implemented as:
 * x + (y - x) * a
 * a must be a value in the range 0.0 ... 1.0. If a is not
 * in the range 0.0 ... 1.0, the return values are
 * undefined.
 */
float __const_func mix(float x, float y, float a);
float2 __const_func mix(float2 x, float2 y, float2 a);
float3 __const_func mix(float3 x, float3 y, float3 a);
float4 __const_func mix(float4 x, float4 y, float4 a);
float8 __const_func mix(float8 x, float8 y, float8 a);
float16 __const_func mix(float16 x, float16 y, float16 a);
float2 __const_func mix(float2 x, float2 y, float a);
float3 __const_func mix(float3 x, float3 y, float a);
float4 __const_func mix(float4 x, float4 y, float a);
float8 __const_func mix(float8 x, float8 y, float a);
float16 __const_func mix(float16 x, float16 y, float a);
#ifdef cl_khr_fp64
double __const_func mix(double x, double y, double a);
double2 __const_func mix(double2 x, double2 y, double2 a);
double3 __const_func mix(double3 x, double3 y, double3 a);
double4 __const_func mix(double4 x, double4 y, double4 a);
double8 __const_func mix(double8 x, double8 y, double8 a);
double16 __const_func mix(double16 x, double16 y, double16 a);
double2 __const_func mix(double2 x, double2 y, double a);
double3 __const_func mix(double3 x, double3 y, double a);
double4 __const_func mix(double4 x, double4 y, double a);
double8 __const_func mix(double8 x, double8 y, double a);
double16 __const_func mix(double16 x, double16 y, double a);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func mix(half x, half y, half a);
half2 __const_func mix(half2 x, half2 y, half2 a);
half3 __const_func mix(half3 x, half3 y, half3 a);
half4 __const_func mix(half4 x, half4 y, half4 a);
half8 __const_func mix(half8 x, half8 y, half8 a);
half16 __const_func mix(half16 x, half16 y, half16 a);
half2 __const_func mix(half2 x, half2 y, half a);
half3 __const_func mix(half3 x, half3 y, half a);
half4 __const_func mix(half4 x, half4 y, half a);
half8 __const_func mix(half8 x, half8 y, half a);
half16 __const_func mix(half16 x, half16 y, half a);
#endif //cl_khr_fp16

/**
 * Converts degrees to radians, i.e. (PI / 180) *
 * degrees.
 */
float __const_func radians(float degrees);
float2 __const_func radians(float2 degrees);
float3 __const_func radians(float3 degrees);
float4 __const_func radians(float4 degrees);
float8 __const_func radians(float8 degrees);
float16 __const_func radians(float16 degrees);
#ifdef cl_khr_fp64
double __const_func radians(double degrees);
double2 __const_func radians(double2 degrees);
double3 __const_func radians(double3 degrees);
double4 __const_func radians(double4 degrees);
double8 __const_func radians(double8 degrees);
double16 __const_func radians(double16 degrees);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func radians(half degrees);
half2 __const_func radians(half2 degrees);
half3 __const_func radians(half3 degrees);
half4 __const_func radians(half4 degrees);
half8 __const_func radians(half8 degrees);
half16 __const_func radians(half16 degrees);
#endif //cl_khr_fp16

/**
 * Returns 0.0 if x < edge, otherwise it returns 1.0.
 */
float __const_func step(float edge, float x);
float2 __const_func step(float2 edge, float2 x);
float3 __const_func step(float3 edge, float3 x);
float4 __const_func step(float4 edge, float4 x);
float8 __const_func step(float8 edge, float8 x);
float16 __const_func step(float16 edge, float16 x);
float2 __const_func step(float edge, float2 x);
float3 __const_func step(float edge, float3 x);
float4 __const_func step(float edge, float4 x);
float8 __const_func step(float edge, float8 x);
float16 __const_func step(float edge, float16 x);
#ifdef cl_khr_fp64
double __const_func step(double edge, double x);
double2 __const_func step(double2 edge, double2 x);
double3 __const_func step(double3 edge, double3 x);
double4 __const_func step(double4 edge, double4 x);
double8 __const_func step(double8 edge, double8 x);
double16 __const_func step(double16 edge, double16 x);
double2 __const_func step(double edge, double2 x);
double3 __const_func step(double edge, double3 x);
double4 __const_func step(double edge, double4 x);
double8 __const_func step(double edge, double8 x);
double16 __const_func step(double edge, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func step(half edge, half x);
half2 __const_func step(half2 edge, half2 x);
half3 __const_func step(half3 edge, half3 x);
half4 __const_func step(half4 edge, half4 x);
half8 __const_func step(half8 edge, half8 x);
half16 __const_func step(half16 edge, half16 x);
half __const_func step(half edge, half x);
half2 __const_func step(half edge, half2 x);
half3 __const_func step(half edge, half3 x);
half4 __const_func step(half edge, half4 x);
half8 __const_func step(half edge, half8 x);
half16 __const_func step(half edge, half16 x);
#endif //cl_khr_fp16

/**
 * Returns 0.0 if x <= edge0 and 1.0 if x >= edge1 and
 * performs smooth Hermite interpolation between 0
 * and 1when edge0 < x < edge1. This is useful in
 * cases where you would want a threshold function
 * with a smooth transition.
 * This is equivalent to:
 * gentype t;
 * t = clamp ((x - edge0) / (edge1 - edge0), 0, 1);
 * return t * t * (3 - 2 * t);
 * Results are undefined if edge0 >= edge1 or if x,
 * edge0 or edge1 is a NaN.
 */
float __const_func smoothstep(float edge0, float edge1, float x);
float2 __const_func smoothstep(float2 edge0, float2 edge1, float2 x);
float3 __const_func smoothstep(float3 edge0, float3 edge1, float3 x);
float4 __const_func smoothstep(float4 edge0, float4 edge1, float4 x);
float8 __const_func smoothstep(float8 edge0, float8 edge1, float8 x);
float16 __const_func smoothstep(float16 edge0, float16 edge1, float16 x);
float2 __const_func smoothstep(float edge0, float edge1, float2 x);
float3 __const_func smoothstep(float edge0, float edge1, float3 x);
float4 __const_func smoothstep(float edge0, float edge1, float4 x);
float8 __const_func smoothstep(float edge0, float edge1, float8 x);
float16 __const_func smoothstep(float edge0, float edge1, float16 x);
#ifdef cl_khr_fp64
double __const_func smoothstep(double edge0, double edge1, double x);
double2 __const_func smoothstep(double2 edge0, double2 edge1, double2 x);
double3 __const_func smoothstep(double3 edge0, double3 edge1, double3 x);
double4 __const_func smoothstep(double4 edge0, double4 edge1, double4 x);
double8 __const_func smoothstep(double8 edge0, double8 edge1, double8 x);
double16 __const_func smoothstep(double16 edge0, double16 edge1, double16 x);
double2 __const_func smoothstep(double edge0, double edge1, double2 x);
double3 __const_func smoothstep(double edge0, double edge1, double3 x);
double4 __const_func smoothstep(double edge0, double edge1, double4 x);
double8 __const_func smoothstep(double edge0, double edge1, double8 x);
double16 __const_func smoothstep(double edge0, double edge1, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func smoothstep(half edge0, half edge1, half x);
half2 __const_func smoothstep(half2 edge0, half2 edge1, half2 x);
half3 __const_func smoothstep(half3 edge0, half3 edge1, half3 x);
half4 __const_func smoothstep(half4 edge0, half4 edge1, half4 x);
half8 __const_func smoothstep(half8 edge0, half8 edge1, half8 x);
half16 __const_func smoothstep(half16 edge0, half16 edge1, half16 x);
half __const_func smoothstep(half edge0, half edge1, half x);
half2 __const_func smoothstep(half edge0, half edge1, half2 x);
half3 __const_func smoothstep(half edge0, half edge1, half3 x);
half4 __const_func smoothstep(half edge0, half edge1, half4 x);
half8 __const_func smoothstep(half edge0, half edge1, half8 x);
half16 __const_func smoothstep(half edge0, half edge1, half16 x);
#endif //cl_khr_fp16

/**
 * Returns 1.0 if x > 0, -0.0 if x = -0.0, +0.0 if x =
 * +0.0, or -1.0 if x < 0. Returns 0.0 if x is a NaN.
 */
float __const_func sign(float x);
float2 __const_func sign(float2 x);
float3 __const_func sign(float3 x);
float4 __const_func sign(float4 x);
float8 __const_func sign(float8 x);
float16 __const_func sign(float16 x);
#ifdef cl_khr_fp64
double __const_func sign(double x);
double2 __const_func sign(double2 x);
double3 __const_func sign(double3 x);
double4 __const_func sign(double4 x);
double8 __const_func sign(double8 x);
double16 __const_func sign(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func sign(half x);
half2 __const_func sign(half2 x);
half3 __const_func sign(half3 x);
half4 __const_func sign(half4 x);
half8 __const_func sign(half8 x);
half16 __const_func sign(half16 x);
#endif //cl_khr_fp16

// OpenCL v1.1 s6.11.5, v1.2 s6.12.5, v2.0 s6.13.5 - Geometric Functions

/**
 * Returns the cross product of p0.xyz and p1.xyz. The
 * w component of float4 result returned will be 0.0.
 */
float4 __const_func cross(float4 p0, float4 p1);
float3 __const_func cross(float3 p0, float3 p1);
#ifdef cl_khr_fp64
double4 __const_func cross(double4 p0, double4 p1);
double3 __const_func cross(double3 p0, double3 p1);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half4 __const_func cross(half4 p0, half4 p1);
half3 __const_func cross(half3 p0, half3 p1);
#endif //cl_khr_fp16

/**
 * Compute dot product.
 */
float __const_func dot(float p0, float p1);
float __const_func dot(float2 p0, float2 p1);
float __const_func dot(float3 p0, float3 p1);
float __const_func dot(float4 p0, float4 p1);
#ifdef cl_khr_fp64
double __const_func dot(double p0, double p1);
double __const_func dot(double2 p0, double2 p1);
double __const_func dot(double3 p0, double3 p1);
double __const_func dot(double4 p0, double4 p1);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func dot(half p0, half p1);
half __const_func dot(half2 p0, half2 p1);
half __const_func dot(half3 p0, half3 p1);
half __const_func dot(half4 p0, half4 p1);
#endif //cl_khr_fp16

/**
 * Returns the distance between p0 and p1. This is
 * calculated as length(p0 - p1).
 */
float __const_func distance(float p0, float p1);
float __const_func distance(float2 p0, float2 p1);
float __const_func distance(float3 p0, float3 p1);
float __const_func distance(float4 p0, float4 p1);
#ifdef cl_khr_fp64
double __const_func distance(double p0, double p1);
double __const_func distance(double2 p0, double2 p1);
double __const_func distance(double3 p0, double3 p1);
double __const_func distance(double4 p0, double4 p1);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func distance(half p0, half p1);
half __const_func distance(half2 p0, half2 p1);
half __const_func distance(half3 p0, half3 p1);
half __const_func distance(half4 p0, half4 p1);
#endif //cl_khr_fp16

/**
 * Return the length of vector p, i.e.,
 * sqrt(p.x2 + p.y 2 + ...)
 */
float __const_func length(float p);
float __const_func length(float2 p);
float __const_func length(float3 p);
float __const_func length(float4 p);
#ifdef cl_khr_fp64
double __const_func length(double p);
double __const_func length(double2 p);
double __const_func length(double3 p);
double __const_func length(double4 p);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func length(half p);
half __const_func length(half2 p);
half __const_func length(half3 p);
half __const_func length(half4 p);
#endif //cl_khr_fp16

/**
 * Returns a vector in the same direction as p but with a
 * length of 1.
 */
float __const_func normalize(float p);
float2 __const_func normalize(float2 p);
float3 __const_func normalize(float3 p);
float4 __const_func normalize(float4 p);
#ifdef cl_khr_fp64
double __const_func normalize(double p);
double2 __const_func normalize(double2 p);
double3 __const_func normalize(double3 p);
double4 __const_func normalize(double4 p);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func normalize(half p);
half2 __const_func normalize(half2 p);
half3 __const_func normalize(half3 p);
half4 __const_func normalize(half4 p);
#endif //cl_khr_fp16

/**
 * Returns fast_length(p0 - p1).
 */
float __const_func fast_distance(float p0, float p1);
float __const_func fast_distance(float2 p0, float2 p1);
float __const_func fast_distance(float3 p0, float3 p1);
float __const_func fast_distance(float4 p0, float4 p1);
#ifdef cl_khr_fp16
half __const_func fast_distance(half p0, half p1);
half __const_func fast_distance(half2 p0, half2 p1);
half __const_func fast_distance(half3 p0, half3 p1);
half __const_func fast_distance(half4 p0, half4 p1);
#endif //cl_khr_fp16

/**
 * Returns the length of vector p computed as:
 * half_sqrt(p.x2 + p.y2 + ...)
 */
float __const_func fast_length(float p);
float __const_func fast_length(float2 p);
float __const_func fast_length(float3 p);
float __const_func fast_length(float4 p);
#ifdef cl_khr_fp16
half __const_func fast_length(half p);
half __const_func fast_length(half2 p);
half __const_func fast_length(half3 p);
half __const_func fast_length(half4 p);
#endif //cl_khr_fp16

/**
 * Returns a vector in the same direction as p but with a
 * length of 1. fast_normalize is computed as:
 * p * half_rsqrt (p.x^2 + p.y^2 + ... )
 * The result shall be within 8192 ulps error from the
 * infinitely precise result of
 * if (all(p == 0.0f))
 * result = p;
 * else
 * result = p / sqrt (p.x^2 + p.y^2 + ...);
 * with the following exceptions:
 * 1) If the sum of squares is greater than FLT_MAX
 * then the value of the floating-point values in the
 * result vector are undefined.
 * 2) If the sum of squares is less than FLT_MIN then
 * the implementation may return back p.
 * 3) If the device is in "denorms are flushed to zero"
 * mode, individual operand elements with magnitude
 * less than sqrt(FLT_MIN) may be flushed to zero
 * before proceeding with the calculation.
 */
float __const_func fast_normalize(float p);
float2 __const_func fast_normalize(float2 p);
float3 __const_func fast_normalize(float3 p);
float4 __const_func fast_normalize(float4 p);
#ifdef cl_khr_fp16
half __const_func fast_normalize(half p);
half2 __const_func fast_normalize(half2 p);
half3 __const_func fast_normalize(half3 p);
half4 __const_func fast_normalize(half4 p);
#endif //cl_khr_fp16

// OpenCL v1.1 s6.11.6, v1.2 s6.12.6, v2.0 s6.13.6 - Relational Functions

/**
 * intn isequal (floatn x, floatn y)
 * Returns the component-wise compare of x == y.
 */
int __const_func isequal(float x, float y);
int2 __const_func isequal(float2 x, float2 y);
int3 __const_func isequal(float3 x, float3 y);
int4 __const_func isequal(float4 x, float4 y);
int8 __const_func isequal(float8 x, float8 y);
int16 __const_func isequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func isequal(double x, double y);
long2 __const_func isequal(double2 x, double2 y);
long3 __const_func isequal(double3 x, double3 y);
long4 __const_func isequal(double4 x, double4 y);
long8 __const_func isequal(double8 x, double8 y);
long16 __const_func isequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isequal(half x, half y);
short2 __const_func isequal(half2 x, half2 y);
short3 __const_func isequal(half3 x, half3 y);
short4 __const_func isequal(half4 x, half4 y);
short8 __const_func isequal(half8 x, half8 y);
short16 __const_func isequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x != y.
 */
int __const_func isnotequal(float x, float y);
int2 __const_func isnotequal(float2 x, float2 y);
int3 __const_func isnotequal(float3 x, float3 y);
int4 __const_func isnotequal(float4 x, float4 y);
int8 __const_func isnotequal(float8 x, float8 y);
int16 __const_func isnotequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func isnotequal(double x, double y);
long2 __const_func isnotequal(double2 x, double2 y);
long3 __const_func isnotequal(double3 x, double3 y);
long4 __const_func isnotequal(double4 x, double4 y);
long8 __const_func isnotequal(double8 x, double8 y);
long16 __const_func isnotequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isnotequal(half x, half y);
short2 __const_func isnotequal(half2 x, half2 y);
short3 __const_func isnotequal(half3 x, half3 y);
short4 __const_func isnotequal(half4 x, half4 y);
short8 __const_func isnotequal(half8 x, half8 y);
short16 __const_func isnotequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x > y.
 */
int __const_func isgreater(float x, float y);
int2 __const_func isgreater(float2 x, float2 y);
int3 __const_func isgreater(float3 x, float3 y);
int4 __const_func isgreater(float4 x, float4 y);
int8 __const_func isgreater(float8 x, float8 y);
int16 __const_func isgreater(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func isgreater(double x, double y);
long2 __const_func isgreater(double2 x, double2 y);
long3 __const_func isgreater(double3 x, double3 y);
long4 __const_func isgreater(double4 x, double4 y);
long8 __const_func isgreater(double8 x, double8 y);
long16 __const_func isgreater(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isgreater(half x, half y);
short2 __const_func isgreater(half2 x, half2 y);
short3 __const_func isgreater(half3 x, half3 y);
short4 __const_func isgreater(half4 x, half4 y);
short8 __const_func isgreater(half8 x, half8 y);
short16 __const_func isgreater(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x >= y.
 */
int __const_func isgreaterequal(float x, float y);
int2 __const_func isgreaterequal(float2 x, float2 y);
int3 __const_func isgreaterequal(float3 x, float3 y);
int4 __const_func isgreaterequal(float4 x, float4 y);
int8 __const_func isgreaterequal(float8 x, float8 y);
int16 __const_func isgreaterequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func isgreaterequal(double x, double y);
long2 __const_func isgreaterequal(double2 x, double2 y);
long3 __const_func isgreaterequal(double3 x, double3 y);
long4 __const_func isgreaterequal(double4 x, double4 y);
long8 __const_func isgreaterequal(double8 x, double8 y);
long16 __const_func isgreaterequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isgreaterequal(half x, half y);
short2 __const_func isgreaterequal(half2 x, half2 y);
short3 __const_func isgreaterequal(half3 x, half3 y);
short4 __const_func isgreaterequal(half4 x, half4 y);
short8 __const_func isgreaterequal(half8 x, half8 y);
short16 __const_func isgreaterequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x < y.
 */
int __const_func isless(float x, float y);
int2 __const_func isless(float2 x, float2 y);
int3 __const_func isless(float3 x, float3 y);
int4 __const_func isless(float4 x, float4 y);
int8 __const_func isless(float8 x, float8 y);
int16 __const_func isless(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func isless(double x, double y);
long2 __const_func isless(double2 x, double2 y);
long3 __const_func isless(double3 x, double3 y);
long4 __const_func isless(double4 x, double4 y);
long8 __const_func isless(double8 x, double8 y);
long16 __const_func isless(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isless(half x, half y);
short2 __const_func isless(half2 x, half2 y);
short3 __const_func isless(half3 x, half3 y);
short4 __const_func isless(half4 x, half4 y);
short8 __const_func isless(half8 x, half8 y);
short16 __const_func isless(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x <= y.
 */
int __const_func islessequal(float x, float y);
int2 __const_func islessequal(float2 x, float2 y);
int3 __const_func islessequal(float3 x, float3 y);
int4 __const_func islessequal(float4 x, float4 y);
int8 __const_func islessequal(float8 x, float8 y);
int16 __const_func islessequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func islessequal(double x, double y);
long2 __const_func islessequal(double2 x, double2 y);
long3 __const_func islessequal(double3 x, double3 y);
long4 __const_func islessequal(double4 x, double4 y);
long8 __const_func islessequal(double8 x, double8 y);
long16 __const_func islessequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func islessequal(half x, half y);
short2 __const_func islessequal(half2 x, half2 y);
short3 __const_func islessequal(half3 x, half3 y);
short4 __const_func islessequal(half4 x, half4 y);
short8 __const_func islessequal(half8 x, half8 y);
short16 __const_func islessequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of
 * (x < y) || (x > y) .
 */
int __const_func islessgreater(float x, float y);
int2 __const_func islessgreater(float2 x, float2 y);
int3 __const_func islessgreater(float3 x, float3 y);
int4 __const_func islessgreater(float4 x, float4 y);
int8 __const_func islessgreater(float8 x, float8 y);
int16 __const_func islessgreater(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func islessgreater(double x, double y);
long2 __const_func islessgreater(double2 x, double2 y);
long3 __const_func islessgreater(double3 x, double3 y);
long4 __const_func islessgreater(double4 x, double4 y);
long8 __const_func islessgreater(double8 x, double8 y);
long16 __const_func islessgreater(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func islessgreater(half x, half y);
short2 __const_func islessgreater(half2 x, half2 y);
short3 __const_func islessgreater(half3 x, half3 y);
short4 __const_func islessgreater(half4 x, half4 y);
short8 __const_func islessgreater(half8 x, half8 y);
short16 __const_func islessgreater(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Test for finite value.
 */
int __const_func isfinite(float);
int2 __const_func isfinite(float2);
int3 __const_func isfinite(float3);
int4 __const_func isfinite(float4);
int8 __const_func isfinite(float8);
int16 __const_func isfinite(float16);
#ifdef cl_khr_fp64
int __const_func isfinite(double);
long2 __const_func isfinite(double2);
long3 __const_func isfinite(double3);
long4 __const_func isfinite(double4);
long8 __const_func isfinite(double8);
long16 __const_func isfinite(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isfinite(half);
short2 __const_func isfinite(half2);
short3 __const_func isfinite(half3);
short4 __const_func isfinite(half4);
short8 __const_func isfinite(half8);
short16 __const_func isfinite(half16);
#endif //cl_khr_fp16

/**
 * Test for infinity value (+ve or -ve) .
 */
int __const_func isinf(float);
int2 __const_func isinf(float2);
int3 __const_func isinf(float3);
int4 __const_func isinf(float4);
int8 __const_func isinf(float8);
int16 __const_func isinf(float16);
#ifdef cl_khr_fp64
int __const_func isinf(double);
long2 __const_func isinf(double2);
long3 __const_func isinf(double3);
long4 __const_func isinf(double4);
long8 __const_func isinf(double8);
long16 __const_func isinf(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isinf(half);
short2 __const_func isinf(half2);
short3 __const_func isinf(half3);
short4 __const_func isinf(half4);
short8 __const_func isinf(half8);
short16 __const_func isinf(half16);
#endif //cl_khr_fp16

/**
 * Test for a NaN.
 */
int __const_func isnan(float);
int2 __const_func isnan(float2);
int3 __const_func isnan(float3);
int4 __const_func isnan(float4);
int8 __const_func isnan(float8);
int16 __const_func isnan(float16);
#ifdef cl_khr_fp64
int __const_func isnan(double);
long2 __const_func isnan(double2);
long3 __const_func isnan(double3);
long4 __const_func isnan(double4);
long8 __const_func isnan(double8);
long16 __const_func isnan(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isnan(half);
short2 __const_func isnan(half2);
short3 __const_func isnan(half3);
short4 __const_func isnan(half4);
short8 __const_func isnan(half8);
short16 __const_func isnan(half16);
#endif //cl_khr_fp16

/**
 * Test for a normal value.
 */
int __const_func isnormal(float);
int2 __const_func isnormal(float2);
int3 __const_func isnormal(float3);
int4 __const_func isnormal(float4);
int8 __const_func isnormal(float8);
int16 __const_func isnormal(float16);
#ifdef cl_khr_fp64
int __const_func isnormal(double);
long2 __const_func isnormal(double2);
long3 __const_func isnormal(double3);
long4 __const_func isnormal(double4);
long8 __const_func isnormal(double8);
long16 __const_func isnormal(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isnormal(half);
short2 __const_func isnormal(half2);
short3 __const_func isnormal(half3);
short4 __const_func isnormal(half4);
short8 __const_func isnormal(half8);
short16 __const_func isnormal(half16);
#endif //cl_khr_fp16

/**
 * Test if arguments are ordered. isordered() takes
 * arguments x and y, and returns the result
 * isequal(x, x) && isequal(y, y).
 */
int __const_func isordered(float x, float y);
int2 __const_func isordered(float2 x, float2 y);
int3 __const_func isordered(float3 x, float3 y);
int4 __const_func isordered(float4 x, float4 y);
int8 __const_func isordered(float8 x, float8 y);
int16 __const_func isordered(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func isordered(double x, double y);
long2 __const_func isordered(double2 x, double2 y);
long3 __const_func isordered(double3 x, double3 y);
long4 __const_func isordered(double4 x, double4 y);
long8 __const_func isordered(double8 x, double8 y);
long16 __const_func isordered(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isordered(half x, half y);
short2 __const_func isordered(half2 x, half2 y);
short3 __const_func isordered(half3 x, half3 y);
short4 __const_func isordered(half4 x, half4 y);
short8 __const_func isordered(half8 x, half8 y);
short16 __const_func isordered(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Test if arguments are unordered. isunordered()
 * takes arguments x and y, returning non-zero if x or y
 * is NaN, and zero otherwise.
 */
int __const_func isunordered(float x, float y);
int2 __const_func isunordered(float2 x, float2 y);
int3 __const_func isunordered(float3 x, float3 y);
int4 __const_func isunordered(float4 x, float4 y);
int8 __const_func isunordered(float8 x, float8 y);
int16 __const_func isunordered(float16 x, float16 y);
#ifdef cl_khr_fp64
int __const_func isunordered(double x, double y);
long2 __const_func isunordered(double2 x, double2 y);
long3 __const_func isunordered(double3 x, double3 y);
long4 __const_func isunordered(double4 x, double4 y);
long8 __const_func isunordered(double8 x, double8 y);
long16 __const_func isunordered(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func isunordered(half x, half y);
short2 __const_func isunordered(half2 x, half2 y);
short3 __const_func isunordered(half3 x, half3 y);
short4 __const_func isunordered(half4 x, half4 y);
short8 __const_func isunordered(half8 x, half8 y);
short16 __const_func isunordered(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Test for sign bit. The scalar version of the function
 * returns a 1 if the sign bit in the float is set else returns
 * 0. The vector version of the function returns the
 * following for each component in floatn: a -1 if the
 * sign bit in the float is set else returns 0.
 */
int __const_func signbit(float);
int2 __const_func signbit(float2);
int3 __const_func signbit(float3);
int4 __const_func signbit(float4);
int8 __const_func signbit(float8);
int16 __const_func signbit(float16);
#ifdef cl_khr_fp64
int __const_func signbit(double);
long2 __const_func signbit(double2);
long3 __const_func signbit(double3);
long4 __const_func signbit(double4);
long8 __const_func signbit(double8);
long16 __const_func signbit(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __const_func signbit(half);
short2 __const_func signbit(half2);
short3 __const_func signbit(half3);
short4 __const_func signbit(half4);
short8 __const_func signbit(half8);
short16 __const_func signbit(half16);
#endif //cl_khr_fp16

/**
 * Returns 1 if the most significant bit in any component
 * of x is set; otherwise returns 0.
 */
int __const_func any(char x);
int __const_func any(char2 x);
int __const_func any(char3 x);
int __const_func any(char4 x);
int __const_func any(char8 x);
int __const_func any(char16 x);
int __const_func any(short x);
int __const_func any(short2 x);
int __const_func any(short3 x);
int __const_func any(short4 x);
int __const_func any(short8 x);
int __const_func any(short16 x);
int __const_func any(int x);
int __const_func any(int2 x);
int __const_func any(int3 x);
int __const_func any(int4 x);
int __const_func any(int8 x);
int __const_func any(int16 x);
int __const_func any(long x);
int __const_func any(long2 x);
int __const_func any(long3 x);
int __const_func any(long4 x);
int __const_func any(long8 x);
int __const_func any(long16 x);

/**
 * Returns 1 if the most significant bit in all components
 * of x is set; otherwise returns 0.
 */
int __const_func all(char x);
int __const_func all(char2 x);
int __const_func all(char3 x);
int __const_func all(char4 x);
int __const_func all(char8 x);
int __const_func all(char16 x);
int __const_func all(short x);
int __const_func all(short2 x);
int __const_func all(short3 x);
int __const_func all(short4 x);
int __const_func all(short8 x);
int __const_func all(short16 x);
int __const_func all(int x);
int __const_func all(int2 x);
int __const_func all(int3 x);
int __const_func all(int4 x);
int __const_func all(int8 x);
int __const_func all(int16 x);
int __const_func all(long x);
int __const_func all(long2 x);
int __const_func all(long3 x);
int __const_func all(long4 x);
int __const_func all(long8 x);
int __const_func all(long16 x);

/**
 * Each bit of the result is the corresponding bit of a if
 * the corresponding bit of c is 0. Otherwise it is the
 * corresponding bit of b.
 */
char __const_func bitselect(char a, char b, char c);
uchar __const_func bitselect(uchar a, uchar b, uchar c);
char2 __const_func bitselect(char2 a, char2 b, char2 c);
uchar2 __const_func bitselect(uchar2 a, uchar2 b, uchar2 c);
char3 __const_func bitselect(char3 a, char3 b, char3 c);
uchar3 __const_func bitselect(uchar3 a, uchar3 b, uchar3 c);
char4 __const_func bitselect(char4 a, char4 b, char4 c);
uchar4 __const_func bitselect(uchar4 a, uchar4 b, uchar4 c);
char8 __const_func bitselect(char8 a, char8 b, char8 c);
uchar8 __const_func bitselect(uchar8 a, uchar8 b, uchar8 c);
char16 __const_func bitselect(char16 a, char16 b, char16 c);
uchar16 __const_func bitselect(uchar16 a, uchar16 b, uchar16 c);
short __const_func bitselect(short a, short b, short c);
ushort __const_func bitselect(ushort a, ushort b, ushort c);
short2 __const_func bitselect(short2 a, short2 b, short2 c);
ushort2 __const_func bitselect(ushort2 a, ushort2 b, ushort2 c);
short3 __const_func bitselect(short3 a, short3 b, short3 c);
ushort3 __const_func bitselect(ushort3 a, ushort3 b, ushort3 c);
short4 __const_func bitselect(short4 a, short4 b, short4 c);
ushort4 __const_func bitselect(ushort4 a, ushort4 b, ushort4 c);
short8 __const_func bitselect(short8 a, short8 b, short8 c);
ushort8 __const_func bitselect(ushort8 a, ushort8 b, ushort8 c);
short16 __const_func bitselect(short16 a, short16 b, short16 c);
ushort16 __const_func bitselect(ushort16 a, ushort16 b, ushort16 c);
int __const_func bitselect(int a, int b, int c);
uint __const_func bitselect(uint a, uint b, uint c);
int2 __const_func bitselect(int2 a, int2 b, int2 c);
uint2 __const_func bitselect(uint2 a, uint2 b, uint2 c);
int3 __const_func bitselect(int3 a, int3 b, int3 c);
uint3 __const_func bitselect(uint3 a, uint3 b, uint3 c);
int4 __const_func bitselect(int4 a, int4 b, int4 c);
uint4 __const_func bitselect(uint4 a, uint4 b, uint4 c);
int8 __const_func bitselect(int8 a, int8 b, int8 c);
uint8 __const_func bitselect(uint8 a, uint8 b, uint8 c);
int16 __const_func bitselect(int16 a, int16 b, int16 c);
uint16 __const_func bitselect(uint16 a, uint16 b, uint16 c);
long __const_func bitselect(long a, long b, long c);
ulong __const_func bitselect(ulong a, ulong b, ulong c);
long2 __const_func bitselect(long2 a, long2 b, long2 c);
ulong2 __const_func bitselect(ulong2 a, ulong2 b, ulong2 c);
long3 __const_func bitselect(long3 a, long3 b, long3 c);
ulong3 __const_func bitselect(ulong3 a, ulong3 b, ulong3 c);
long4 __const_func bitselect(long4 a, long4 b, long4 c);
ulong4 __const_func bitselect(ulong4 a, ulong4 b, ulong4 c);
long8 __const_func bitselect(long8 a, long8 b, long8 c);
ulong8 __const_func bitselect(ulong8 a, ulong8 b, ulong8 c);
long16 __const_func bitselect(long16 a, long16 b, long16 c);
ulong16 __const_func bitselect(ulong16 a, ulong16 b, ulong16 c);
float __const_func bitselect(float a, float b, float c);
float2 __const_func bitselect(float2 a, float2 b, float2 c);
float3 __const_func bitselect(float3 a, float3 b, float3 c);
float4 __const_func bitselect(float4 a, float4 b, float4 c);
float8 __const_func bitselect(float8 a, float8 b, float8 c);
float16 __const_func bitselect(float16 a, float16 b, float16 c);
#ifdef cl_khr_fp64
double __const_func bitselect(double a, double b, double c);
double2 __const_func bitselect(double2 a, double2 b, double2 c);
double3 __const_func bitselect(double3 a, double3 b, double3 c);
double4 __const_func bitselect(double4 a, double4 b, double4 c);
double8 __const_func bitselect(double8 a, double8 b, double8 c);
double16 __const_func bitselect(double16 a, double16 b, double16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func bitselect(half a, half b, half c);
half2 __const_func bitselect(half2 a, half2 b, half2 c);
half3 __const_func bitselect(half3 a, half3 b, half3 c);
half4 __const_func bitselect(half4 a, half4 b, half4 c);
half8 __const_func bitselect(half8 a, half8 b, half8 c);
half16 __const_func bitselect(half16 a, half16 b, half16 c);
#endif //cl_khr_fp16

/**
 * For each component of a vector type,
 * result[i] = if MSB of c[i] is set ? b[i] : a[i].
 * For a scalar type, result = c ? b : a.
 */
char __const_func select(char a, char b, char c);
uchar __const_func select(uchar a, uchar b, char c);
char2 __const_func select(char2 a, char2 b, char2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, char2 c);
char3 __const_func select(char3 a, char3 b, char3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, char3 c);
char4 __const_func select(char4 a, char4 b, char4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, char4 c);
char8 __const_func select(char8 a, char8 b, char8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, char8 c);
char16 __const_func select(char16 a, char16 b, char16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, char16 c);
short __const_func select(short a, short b, char c);
ushort __const_func select(ushort a, ushort b, char c);
short2 __const_func select(short2 a, short2 b, char2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, char2 c);
short3 __const_func select(short3 a, short3 b, char3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, char3 c);
short4 __const_func select(short4 a, short4 b, char4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, char4 c);
short8 __const_func select(short8 a, short8 b, char8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, char8 c);
short16 __const_func select(short16 a, short16 b, char16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, char16 c);
int __const_func select(int a, int b, char c);
uint __const_func select(uint a, uint b, char c);
int2 __const_func select(int2 a, int2 b, char2 c);
uint2 __const_func select(uint2 a, uint2 b, char2 c);
int3 __const_func select(int3 a, int3 b, char3 c);
uint3 __const_func select(uint3 a, uint3 b, char3 c);
int4 __const_func select(int4 a, int4 b, char4 c);
uint4 __const_func select(uint4 a, uint4 b, char4 c);
int8 __const_func select(int8 a, int8 b, char8 c);
uint8 __const_func select(uint8 a, uint8 b, char8 c);
int16 __const_func select(int16 a, int16 b, char16 c);
uint16 __const_func select(uint16 a, uint16 b, char16 c);
long __const_func select(long a, long b, char c);
ulong __const_func select(ulong a, ulong b, char c);
long2 __const_func select(long2 a, long2 b, char2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, char2 c);
long3 __const_func select(long3 a, long3 b, char3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, char3 c);
long4 __const_func select(long4 a, long4 b, char4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, char4 c);
long8 __const_func select(long8 a, long8 b, char8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, char8 c);
long16 __const_func select(long16 a, long16 b, char16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, char16 c);
float __const_func select(float a, float b, char c);
float2 __const_func select(float2 a, float2 b, char2 c);
float3 __const_func select(float3 a, float3 b, char3 c);
float4 __const_func select(float4 a, float4 b, char4 c);
float8 __const_func select(float8 a, float8 b, char8 c);
float16 __const_func select(float16 a, float16 b, char16 c);
char __const_func select(char a, char b, short c);
uchar __const_func select(uchar a, uchar b, short c);
char2 __const_func select(char2 a, char2 b, short2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, short2 c);
char3 __const_func select(char3 a, char3 b, short3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, short3 c);
char4 __const_func select(char4 a, char4 b, short4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, short4 c);
char8 __const_func select(char8 a, char8 b, short8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, short8 c);
char16 __const_func select(char16 a, char16 b, short16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, short16 c);
short __const_func select(short a, short b, short c);
ushort __const_func select(ushort a, ushort b, short c);
short2 __const_func select(short2 a, short2 b, short2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, short2 c);
short3 __const_func select(short3 a, short3 b, short3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, short3 c);
short4 __const_func select(short4 a, short4 b, short4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, short4 c);
short8 __const_func select(short8 a, short8 b, short8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, short8 c);
short16 __const_func select(short16 a, short16 b, short16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, short16 c);
int __const_func select(int a, int b, short c);
uint __const_func select(uint a, uint b, short c);
int2 __const_func select(int2 a, int2 b, short2 c);
uint2 __const_func select(uint2 a, uint2 b, short2 c);
int3 __const_func select(int3 a, int3 b, short3 c);
uint3 __const_func select(uint3 a, uint3 b, short3 c);
int4 __const_func select(int4 a, int4 b, short4 c);
uint4 __const_func select(uint4 a, uint4 b, short4 c);
int8 __const_func select(int8 a, int8 b, short8 c);
uint8 __const_func select(uint8 a, uint8 b, short8 c);
int16 __const_func select(int16 a, int16 b, short16 c);
uint16 __const_func select(uint16 a, uint16 b, short16 c);
long __const_func select(long a, long b, short c);
ulong __const_func select(ulong a, ulong b, short c);
long2 __const_func select(long2 a, long2 b, short2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, short2 c);
long3 __const_func select(long3 a, long3 b, short3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, short3 c);
long4 __const_func select(long4 a, long4 b, short4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, short4 c);
long8 __const_func select(long8 a, long8 b, short8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, short8 c);
long16 __const_func select(long16 a, long16 b, short16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, short16 c);
float __const_func select(float a, float b, short c);
float2 __const_func select(float2 a, float2 b, short2 c);
float3 __const_func select(float3 a, float3 b, short3 c);
float4 __const_func select(float4 a, float4 b, short4 c);
float8 __const_func select(float8 a, float8 b, short8 c);
float16 __const_func select(float16 a, float16 b, short16 c);
char __const_func select(char a, char b, int c);
uchar __const_func select(uchar a, uchar b, int c);
char2 __const_func select(char2 a, char2 b, int2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, int2 c);
char3 __const_func select(char3 a, char3 b, int3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, int3 c);
char4 __const_func select(char4 a, char4 b, int4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, int4 c);
char8 __const_func select(char8 a, char8 b, int8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, int8 c);
char16 __const_func select(char16 a, char16 b, int16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, int16 c);
short __const_func select(short a, short b, int c);
ushort __const_func select(ushort a, ushort b, int c);
short2 __const_func select(short2 a, short2 b, int2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, int2 c);
short3 __const_func select(short3 a, short3 b, int3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, int3 c);
short4 __const_func select(short4 a, short4 b, int4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, int4 c);
short8 __const_func select(short8 a, short8 b, int8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, int8 c);
short16 __const_func select(short16 a, short16 b, int16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, int16 c);
int __const_func select(int a, int b, int c);
uint __const_func select(uint a, uint b, int c);
int2 __const_func select(int2 a, int2 b, int2 c);
uint2 __const_func select(uint2 a, uint2 b, int2 c);
int3 __const_func select(int3 a, int3 b, int3 c);
uint3 __const_func select(uint3 a, uint3 b, int3 c);
int4 __const_func select(int4 a, int4 b, int4 c);
uint4 __const_func select(uint4 a, uint4 b, int4 c);
int8 __const_func select(int8 a, int8 b, int8 c);
uint8 __const_func select(uint8 a, uint8 b, int8 c);
int16 __const_func select(int16 a, int16 b, int16 c);
uint16 __const_func select(uint16 a, uint16 b, int16 c);
long __const_func select(long a, long b, int c);
ulong __const_func select(ulong a, ulong b, int c);
long2 __const_func select(long2 a, long2 b, int2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, int2 c);
long3 __const_func select(long3 a, long3 b, int3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, int3 c);
long4 __const_func select(long4 a, long4 b, int4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, int4 c);
long8 __const_func select(long8 a, long8 b, int8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, int8 c);
long16 __const_func select(long16 a, long16 b, int16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, int16 c);
float __const_func select(float a, float b, int c);
float2 __const_func select(float2 a, float2 b, int2 c);
float3 __const_func select(float3 a, float3 b, int3 c);
float4 __const_func select(float4 a, float4 b, int4 c);
float8 __const_func select(float8 a, float8 b, int8 c);
float16 __const_func select(float16 a, float16 b, int16 c);
char __const_func select(char a, char b, long c);
uchar __const_func select(uchar a, uchar b, long c);
char2 __const_func select(char2 a, char2 b, long2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, long2 c);
char3 __const_func select(char3 a, char3 b, long3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, long3 c);
char4 __const_func select(char4 a, char4 b, long4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, long4 c);
char8 __const_func select(char8 a, char8 b, long8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, long8 c);
char16 __const_func select(char16 a, char16 b, long16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, long16 c);
short __const_func select(short a, short b, long c);
ushort __const_func select(ushort a, ushort b, long c);
short2 __const_func select(short2 a, short2 b, long2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, long2 c);
short3 __const_func select(short3 a, short3 b, long3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, long3 c);
short4 __const_func select(short4 a, short4 b, long4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, long4 c);
short8 __const_func select(short8 a, short8 b, long8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, long8 c);
short16 __const_func select(short16 a, short16 b, long16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, long16 c);
int __const_func select(int a, int b, long c);
uint __const_func select(uint a, uint b, long c);
int2 __const_func select(int2 a, int2 b, long2 c);
uint2 __const_func select(uint2 a, uint2 b, long2 c);
int3 __const_func select(int3 a, int3 b, long3 c);
uint3 __const_func select(uint3 a, uint3 b, long3 c);
int4 __const_func select(int4 a, int4 b, long4 c);
uint4 __const_func select(uint4 a, uint4 b, long4 c);
int8 __const_func select(int8 a, int8 b, long8 c);
uint8 __const_func select(uint8 a, uint8 b, long8 c);
int16 __const_func select(int16 a, int16 b, long16 c);
uint16 __const_func select(uint16 a, uint16 b, long16 c);
long __const_func select(long a, long b, long c);
ulong __const_func select(ulong a, ulong b, long c);
long2 __const_func select(long2 a, long2 b, long2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, long2 c);
long3 __const_func select(long3 a, long3 b, long3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, long3 c);
long4 __const_func select(long4 a, long4 b, long4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, long4 c);
long8 __const_func select(long8 a, long8 b, long8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, long8 c);
long16 __const_func select(long16 a, long16 b, long16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, long16 c);
float __const_func select(float a, float b, long c);
float2 __const_func select(float2 a, float2 b, long2 c);
float3 __const_func select(float3 a, float3 b, long3 c);
float4 __const_func select(float4 a, float4 b, long4 c);
float8 __const_func select(float8 a, float8 b, long8 c);
float16 __const_func select(float16 a, float16 b, long16 c);
char __const_func select(char a, char b, uchar c);
uchar __const_func select(uchar a, uchar b, uchar c);
char2 __const_func select(char2 a, char2 b, uchar2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, uchar2 c);
char3 __const_func select(char3 a, char3 b, uchar3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, uchar3 c);
char4 __const_func select(char4 a, char4 b, uchar4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, uchar4 c);
char8 __const_func select(char8 a, char8 b, uchar8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, uchar8 c);
char16 __const_func select(char16 a, char16 b, uchar16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, uchar16 c);
short __const_func select(short a, short b, uchar c);
ushort __const_func select(ushort a, ushort b, uchar c);
short2 __const_func select(short2 a, short2 b, uchar2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, uchar2 c);
short3 __const_func select(short3 a, short3 b, uchar3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, uchar3 c);
short4 __const_func select(short4 a, short4 b, uchar4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, uchar4 c);
short8 __const_func select(short8 a, short8 b, uchar8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, uchar8 c);
short16 __const_func select(short16 a, short16 b, uchar16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, uchar16 c);
int __const_func select(int a, int b, uchar c);
uint __const_func select(uint a, uint b, uchar c);
int2 __const_func select(int2 a, int2 b, uchar2 c);
uint2 __const_func select(uint2 a, uint2 b, uchar2 c);
int3 __const_func select(int3 a, int3 b, uchar3 c);
uint3 __const_func select(uint3 a, uint3 b, uchar3 c);
int4 __const_func select(int4 a, int4 b, uchar4 c);
uint4 __const_func select(uint4 a, uint4 b, uchar4 c);
int8 __const_func select(int8 a, int8 b, uchar8 c);
uint8 __const_func select(uint8 a, uint8 b, uchar8 c);
int16 __const_func select(int16 a, int16 b, uchar16 c);
uint16 __const_func select(uint16 a, uint16 b, uchar16 c);
long __const_func select(long a, long b, uchar c);
ulong __const_func select(ulong a, ulong b, uchar c);
long2 __const_func select(long2 a, long2 b, uchar2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, uchar2 c);
long3 __const_func select(long3 a, long3 b, uchar3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, uchar3 c);
long4 __const_func select(long4 a, long4 b, uchar4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, uchar4 c);
long8 __const_func select(long8 a, long8 b, uchar8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, uchar8 c);
long16 __const_func select(long16 a, long16 b, uchar16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, uchar16 c);
float __const_func select(float a, float b, uchar c);
float2 __const_func select(float2 a, float2 b, uchar2 c);
float3 __const_func select(float3 a, float3 b, uchar3 c);
float4 __const_func select(float4 a, float4 b, uchar4 c);
float8 __const_func select(float8 a, float8 b, uchar8 c);
float16 __const_func select(float16 a, float16 b, uchar16 c);
char __const_func select(char a, char b, ushort c);
uchar __const_func select(uchar a, uchar b, ushort c);
char2 __const_func select(char2 a, char2 b, ushort2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, ushort2 c);
char3 __const_func select(char3 a, char3 b, ushort3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, ushort3 c);
char4 __const_func select(char4 a, char4 b, ushort4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, ushort4 c);
char8 __const_func select(char8 a, char8 b, ushort8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, ushort8 c);
char16 __const_func select(char16 a, char16 b, ushort16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, ushort16 c);
short __const_func select(short a, short b, ushort c);
ushort __const_func select(ushort a, ushort b, ushort c);
short2 __const_func select(short2 a, short2 b, ushort2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, ushort2 c);
short3 __const_func select(short3 a, short3 b, ushort3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, ushort3 c);
short4 __const_func select(short4 a, short4 b, ushort4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, ushort4 c);
short8 __const_func select(short8 a, short8 b, ushort8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, ushort8 c);
short16 __const_func select(short16 a, short16 b, ushort16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, ushort16 c);
int __const_func select(int a, int b, ushort c);
uint __const_func select(uint a, uint b, ushort c);
int2 __const_func select(int2 a, int2 b, ushort2 c);
uint2 __const_func select(uint2 a, uint2 b, ushort2 c);
int3 __const_func select(int3 a, int3 b, ushort3 c);
uint3 __const_func select(uint3 a, uint3 b, ushort3 c);
int4 __const_func select(int4 a, int4 b, ushort4 c);
uint4 __const_func select(uint4 a, uint4 b, ushort4 c);
int8 __const_func select(int8 a, int8 b, ushort8 c);
uint8 __const_func select(uint8 a, uint8 b, ushort8 c);
int16 __const_func select(int16 a, int16 b, ushort16 c);
uint16 __const_func select(uint16 a, uint16 b, ushort16 c);
long __const_func select(long a, long b, ushort c);
ulong __const_func select(ulong a, ulong b, ushort c);
long2 __const_func select(long2 a, long2 b, ushort2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, ushort2 c);
long3 __const_func select(long3 a, long3 b, ushort3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, ushort3 c);
long4 __const_func select(long4 a, long4 b, ushort4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, ushort4 c);
long8 __const_func select(long8 a, long8 b, ushort8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, ushort8 c);
long16 __const_func select(long16 a, long16 b, ushort16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, ushort16 c);
float __const_func select(float a, float b, ushort c);
float2 __const_func select(float2 a, float2 b, ushort2 c);
float3 __const_func select(float3 a, float3 b, ushort3 c);
float4 __const_func select(float4 a, float4 b, ushort4 c);
float8 __const_func select(float8 a, float8 b, ushort8 c);
float16 __const_func select(float16 a, float16 b, ushort16 c);
char __const_func select(char a, char b, uint c);
uchar __const_func select(uchar a, uchar b, uint c);
char2 __const_func select(char2 a, char2 b, uint2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, uint2 c);
char3 __const_func select(char3 a, char3 b, uint3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, uint3 c);
char4 __const_func select(char4 a, char4 b, uint4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, uint4 c);
char8 __const_func select(char8 a, char8 b, uint8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, uint8 c);
char16 __const_func select(char16 a, char16 b, uint16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, uint16 c);
short __const_func select(short a, short b, uint c);
ushort __const_func select(ushort a, ushort b, uint c);
short2 __const_func select(short2 a, short2 b, uint2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, uint2 c);
short3 __const_func select(short3 a, short3 b, uint3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, uint3 c);
short4 __const_func select(short4 a, short4 b, uint4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, uint4 c);
short8 __const_func select(short8 a, short8 b, uint8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, uint8 c);
short16 __const_func select(short16 a, short16 b, uint16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, uint16 c);
int __const_func select(int a, int b, uint c);
uint __const_func select(uint a, uint b, uint c);
int2 __const_func select(int2 a, int2 b, uint2 c);
uint2 __const_func select(uint2 a, uint2 b, uint2 c);
int3 __const_func select(int3 a, int3 b, uint3 c);
uint3 __const_func select(uint3 a, uint3 b, uint3 c);
int4 __const_func select(int4 a, int4 b, uint4 c);
uint4 __const_func select(uint4 a, uint4 b, uint4 c);
int8 __const_func select(int8 a, int8 b, uint8 c);
uint8 __const_func select(uint8 a, uint8 b, uint8 c);
int16 __const_func select(int16 a, int16 b, uint16 c);
uint16 __const_func select(uint16 a, uint16 b, uint16 c);
long __const_func select(long a, long b, uint c);
ulong __const_func select(ulong a, ulong b, uint c);
long2 __const_func select(long2 a, long2 b, uint2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, uint2 c);
long3 __const_func select(long3 a, long3 b, uint3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, uint3 c);
long4 __const_func select(long4 a, long4 b, uint4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, uint4 c);
long8 __const_func select(long8 a, long8 b, uint8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, uint8 c);
long16 __const_func select(long16 a, long16 b, uint16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, uint16 c);
float __const_func select(float a, float b, uint c);
float2 __const_func select(float2 a, float2 b, uint2 c);
float3 __const_func select(float3 a, float3 b, uint3 c);
float4 __const_func select(float4 a, float4 b, uint4 c);
float8 __const_func select(float8 a, float8 b, uint8 c);
float16 __const_func select(float16 a, float16 b, uint16 c);
char __const_func select(char a, char b, ulong c);
uchar __const_func select(uchar a, uchar b, ulong c);
char2 __const_func select(char2 a, char2 b, ulong2 c);
uchar2 __const_func select(uchar2 a, uchar2 b, ulong2 c);
char3 __const_func select(char3 a, char3 b, ulong3 c);
uchar3 __const_func select(uchar3 a, uchar3 b, ulong3 c);
char4 __const_func select(char4 a, char4 b, ulong4 c);
uchar4 __const_func select(uchar4 a, uchar4 b, ulong4 c);
char8 __const_func select(char8 a, char8 b, ulong8 c);
uchar8 __const_func select(uchar8 a, uchar8 b, ulong8 c);
char16 __const_func select(char16 a, char16 b, ulong16 c);
uchar16 __const_func select(uchar16 a, uchar16 b, ulong16 c);
short __const_func select(short a, short b, ulong c);
ushort __const_func select(ushort a, ushort b, ulong c);
short2 __const_func select(short2 a, short2 b, ulong2 c);
ushort2 __const_func select(ushort2 a, ushort2 b, ulong2 c);
short3 __const_func select(short3 a, short3 b, ulong3 c);
ushort3 __const_func select(ushort3 a, ushort3 b, ulong3 c);
short4 __const_func select(short4 a, short4 b, ulong4 c);
ushort4 __const_func select(ushort4 a, ushort4 b, ulong4 c);
short8 __const_func select(short8 a, short8 b, ulong8 c);
ushort8 __const_func select(ushort8 a, ushort8 b, ulong8 c);
short16 __const_func select(short16 a, short16 b, ulong16 c);
ushort16 __const_func select(ushort16 a, ushort16 b, ulong16 c);
int __const_func select(int a, int b, ulong c);
uint __const_func select(uint a, uint b, ulong c);
int2 __const_func select(int2 a, int2 b, ulong2 c);
uint2 __const_func select(uint2 a, uint2 b, ulong2 c);
int3 __const_func select(int3 a, int3 b, ulong3 c);
uint3 __const_func select(uint3 a, uint3 b, ulong3 c);
int4 __const_func select(int4 a, int4 b, ulong4 c);
uint4 __const_func select(uint4 a, uint4 b, ulong4 c);
int8 __const_func select(int8 a, int8 b, ulong8 c);
uint8 __const_func select(uint8 a, uint8 b, ulong8 c);
int16 __const_func select(int16 a, int16 b, ulong16 c);
uint16 __const_func select(uint16 a, uint16 b, ulong16 c);
long __const_func select(long a, long b, ulong c);
ulong __const_func select(ulong a, ulong b, ulong c);
long2 __const_func select(long2 a, long2 b, ulong2 c);
ulong2 __const_func select(ulong2 a, ulong2 b, ulong2 c);
long3 __const_func select(long3 a, long3 b, ulong3 c);
ulong3 __const_func select(ulong3 a, ulong3 b, ulong3 c);
long4 __const_func select(long4 a, long4 b, ulong4 c);
ulong4 __const_func select(ulong4 a, ulong4 b, ulong4 c);
long8 __const_func select(long8 a, long8 b, ulong8 c);
ulong8 __const_func select(ulong8 a, ulong8 b, ulong8 c);
long16 __const_func select(long16 a, long16 b, ulong16 c);
ulong16 __const_func select(ulong16 a, ulong16 b, ulong16 c);
float __const_func select(float a, float b, ulong c);
float2 __const_func select(float2 a, float2 b, ulong2 c);
float3 __const_func select(float3 a, float3 b, ulong3 c);
float4 __const_func select(float4 a, float4 b, ulong4 c);
float8 __const_func select(float8 a, float8 b, ulong8 c);
float16 __const_func select(float16 a, float16 b, ulong16 c);
#ifdef cl_khr_fp64
double __const_func select(double a, double b, long c);
double2 __const_func select(double2 a, double2 b, long2 c);
double3 __const_func select(double3 a, double3 b, long3 c);
double4 __const_func select(double4 a, double4 b, long4 c);
double8 __const_func select(double8 a, double8 b, long8 c);
double16 __const_func select(double16 a, double16 b, long16 c);
double __const_func select(double a, double b, ulong c);
double2 __const_func select(double2 a, double2 b, ulong2 c);
double3 __const_func select(double3 a, double3 b, ulong3 c);
double4 __const_func select(double4 a, double4 b, ulong4 c);
double8 __const_func select(double8 a, double8 b, ulong8 c);
double16 __const_func select(double16 a, double16 b, ulong16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __const_func select(half a, half b, short c);
half2 __const_func select(half2 a, half2 b, short2 c);
half3 __const_func select(half3 a, half3 b, short3 c);
half4 __const_func select(half4 a, half4 b, short4 c);
half8 __const_func select(half8 a, half8 b, short8 c);
half16 __const_func select(half16 a, half16 b, short16 c);
half __const_func select(half a, half b, ushort c);
half2 __const_func select(half2 a, half2 b, ushort2 c);
half3 __const_func select(half3 a, half3 b, ushort3 c);
half4 __const_func select(half4 a, half4 b, ushort4 c);
half8 __const_func select(half8 a, half8 b, ushort8 c);
half16 __const_func select(half16 a, half16 b, ushort16 c);
#endif //cl_khr_fp16

// OpenCL v1.1 s6.11.7, v1.2 s6.12.7, v2.0 s6.13.7 - Vector Data Load and Store Functions

/**
 * Return sizeof (gentypen) bytes of data read
 * from address (p + (offset * n)). The address
 * computed as (p + (offset * n)) must be 8-bit
 * aligned if gentype is char, uchar; 16-bit
 * aligned if gentype is short, ushort; 32-bit
 * aligned if gentype is int, uint, float; 64-bit
 * aligned if gentype is long, ulong.
 */

char2 __overload vload2(size_t offset, const __constant char *p);
uchar2 __overload vload2(size_t offset, const __constant uchar *p);
short2 __overload vload2(size_t offset, const __constant short *p);
ushort2 __overload vload2(size_t offset, const __constant ushort *p);
int2 __overload vload2(size_t offset, const __constant int *p);
uint2 __overload vload2(size_t offset, const __constant uint *p);
long2 __overload vload2(size_t offset, const __constant long *p);
ulong2 __overload vload2(size_t offset, const __constant ulong *p);
float2 __overload vload2(size_t offset, const __constant float *p);
char3 __overload vload3(size_t offset, const __constant char *p);
uchar3 __overload vload3(size_t offset, const __constant uchar *p);
short3 __overload vload3(size_t offset, const __constant short *p);
ushort3 __overload vload3(size_t offset, const __constant ushort *p);
int3 __overload vload3(size_t offset, const __constant int *p);
uint3 __overload vload3(size_t offset, const __constant uint *p);
long3 __overload vload3(size_t offset, const __constant long *p);
ulong3 __overload vload3(size_t offset, const __constant ulong *p);
float3 __overload vload3(size_t offset, const __constant float *p);
char4 __overload vload4(size_t offset, const __constant char *p);
uchar4 __overload vload4(size_t offset, const __constant uchar *p);
short4 __overload vload4(size_t offset, const __constant short *p);
ushort4 __overload vload4(size_t offset, const __constant ushort *p);
int4 __overload vload4(size_t offset, const __constant int *p);
uint4 __overload vload4(size_t offset, const __constant uint *p);
long4 __overload vload4(size_t offset, const __constant long *p);
ulong4 __overload vload4(size_t offset, const __constant ulong *p);
float4 __overload vload4(size_t offset, const __constant float *p);
char8 __overload vload8(size_t offset, const __constant char *p);
uchar8 __overload vload8(size_t offset, const __constant uchar *p);
short8 __overload vload8(size_t offset, const __constant short *p);
ushort8 __overload vload8(size_t offset, const __constant ushort *p);
int8 __overload vload8(size_t offset, const __constant int *p);
uint8 __overload vload8(size_t offset, const __constant uint *p);
long8 __overload vload8(size_t offset, const __constant long *p);
ulong8 __overload vload8(size_t offset, const __constant ulong *p);
float8 __overload vload8(size_t offset, const __constant float *p);
char16 __overload vload16(size_t offset, const __constant char *p);
uchar16 __overload vload16(size_t offset, const __constant uchar *p);
short16 __overload vload16(size_t offset, const __constant short *p);
ushort16 __overload vload16(size_t offset, const __constant ushort *p);
int16 __overload vload16(size_t offset, const __constant int *p);
uint16 __overload vload16(size_t offset, const __constant uint *p);
long16 __overload vload16(size_t offset, const __constant long *p);
ulong16 __overload vload16(size_t offset, const __constant ulong *p);
float16 __overload vload16(size_t offset, const __constant float *p);
#ifdef cl_khr_fp64
double2 __overload vload2(size_t offset, const __constant double *p);
double3 __overload vload3(size_t offset, const __constant double *p);
double4 __overload vload4(size_t offset, const __constant double *p);
double8 __overload vload8(size_t offset, const __constant double *p);
double16 __overload vload16(size_t offset, const __constant double *p);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half __overload vload(size_t offset, const __constant half *p);
half2 __overload vload2(size_t offset, const __constant half *p);
half3 __overload vload3(size_t offset, const __constant half *p);
half4 __overload vload4(size_t offset, const __constant half *p);
half8 __overload vload8(size_t offset, const __constant half *p);
half16 __overload vload16(size_t offset, const __constant half *p);
#endif //cl_khr_fp16

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
char2 __overload vload2(size_t offset, const char *p);
uchar2 __overload vload2(size_t offset, const uchar *p);
short2 __overload vload2(size_t offset, const short *p);
ushort2 __overload vload2(size_t offset, const ushort *p);
int2 __overload vload2(size_t offset, const int *p);
uint2 __overload vload2(size_t offset, const uint *p);
long2 __overload vload2(size_t offset, const long *p);
ulong2 __overload vload2(size_t offset, const ulong *p);
float2 __overload vload2(size_t offset, const float *p);
char3 __overload vload3(size_t offset, const char *p);
uchar3 __overload vload3(size_t offset, const uchar *p);
short3 __overload vload3(size_t offset, const short *p);
ushort3 __overload vload3(size_t offset, const ushort *p);
int3 __overload vload3(size_t offset, const int *p);
uint3 __overload vload3(size_t offset, const uint *p);
long3 __overload vload3(size_t offset, const long *p);
ulong3 __overload vload3(size_t offset, const ulong *p);
float3 __overload vload3(size_t offset, const float *p);
char4 __overload vload4(size_t offset, const char *p);
uchar4 __overload vload4(size_t offset, const uchar *p);
short4 __overload vload4(size_t offset, const short *p);
ushort4 __overload vload4(size_t offset, const ushort *p);
int4 __overload vload4(size_t offset, const int *p);
uint4 __overload vload4(size_t offset, const uint *p);
long4 __overload vload4(size_t offset, const long *p);
ulong4 __overload vload4(size_t offset, const ulong *p);
float4 __overload vload4(size_t offset, const float *p);
char8 __overload vload8(size_t offset, const char *p);
uchar8 __overload vload8(size_t offset, const uchar *p);
short8 __overload vload8(size_t offset, const short *p);
ushort8 __overload vload8(size_t offset, const ushort *p);
int8 __overload vload8(size_t offset, const int *p);
uint8 __overload vload8(size_t offset, const uint *p);
long8 __overload vload8(size_t offset, const long *p);
ulong8 __overload vload8(size_t offset, const ulong *p);
float8 __overload vload8(size_t offset, const float *p);
char16 __overload vload16(size_t offset, const char *p);
uchar16 __overload vload16(size_t offset, const uchar *p);
short16 __overload vload16(size_t offset, const short *p);
ushort16 __overload vload16(size_t offset, const ushort *p);
int16 __overload vload16(size_t offset, const int *p);
uint16 __overload vload16(size_t offset, const uint *p);
long16 __overload vload16(size_t offset, const long *p);
ulong16 __overload vload16(size_t offset, const ulong *p);
float16 __overload vload16(size_t offset, const float *p);

#ifdef cl_khr_fp64
double2 __overload vload2(size_t offset, const double *p);
double3 __overload vload3(size_t offset, const double *p);
double4 __overload vload4(size_t offset, const double *p);
double8 __overload vload8(size_t offset, const double *p);
double16 __overload vload16(size_t offset, const double *p);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half __overload vload(size_t offset, const half *p);
half2 __overload vload2(size_t offset, const half *p);
half3 __overload vload3(size_t offset, const half *p);
half4 __overload vload4(size_t offset, const half *p);
half8 __overload vload8(size_t offset, const half *p);
half16 __overload vload16(size_t offset, const half *p);
#endif //cl_khr_fp16
#else
char2 __overload vload2(size_t offset, const __global char *p);
uchar2 __overload vload2(size_t offset, const __global uchar *p);
short2 __overload vload2(size_t offset, const __global short *p);
ushort2 __overload vload2(size_t offset, const __global ushort *p);
int2 __overload vload2(size_t offset, const __global int *p);
uint2 __overload vload2(size_t offset, const __global uint *p);
long2 __overload vload2(size_t offset, const __global long *p);
ulong2 __overload vload2(size_t offset, const __global ulong *p);
float2 __overload vload2(size_t offset, const __global float *p);
char3 __overload vload3(size_t offset, const __global char *p);
uchar3 __overload vload3(size_t offset, const __global uchar *p);
short3 __overload vload3(size_t offset, const __global short *p);
ushort3 __overload vload3(size_t offset, const __global ushort *p);
int3 __overload vload3(size_t offset, const __global int *p);
uint3 __overload vload3(size_t offset, const __global uint *p);
long3 __overload vload3(size_t offset, const __global long *p);
ulong3 __overload vload3(size_t offset, const __global ulong *p);
float3 __overload vload3(size_t offset, const __global float *p);
char4 __overload vload4(size_t offset, const __global char *p);
uchar4 __overload vload4(size_t offset, const __global uchar *p);
short4 __overload vload4(size_t offset, const __global short *p);
ushort4 __overload vload4(size_t offset, const __global ushort *p);
int4 __overload vload4(size_t offset, const __global int *p);
uint4 __overload vload4(size_t offset, const __global uint *p);
long4 __overload vload4(size_t offset, const __global long *p);
ulong4 __overload vload4(size_t offset, const __global ulong *p);
float4 __overload vload4(size_t offset, const __global float *p);
char8 __overload vload8(size_t offset, const __global char *p);
uchar8 __overload vload8(size_t offset, const __global uchar *p);
short8 __overload vload8(size_t offset, const __global short *p);
ushort8 __overload vload8(size_t offset, const __global ushort *p);
int8 __overload vload8(size_t offset, const __global int *p);
uint8 __overload vload8(size_t offset, const __global uint *p);
long8 __overload vload8(size_t offset, const __global long *p);
ulong8 __overload vload8(size_t offset, const __global ulong *p);
float8 __overload vload8(size_t offset, const __global float *p);
char16 __overload vload16(size_t offset, const __global char *p);
uchar16 __overload vload16(size_t offset, const __global uchar *p);
short16 __overload vload16(size_t offset, const __global short *p);
ushort16 __overload vload16(size_t offset, const __global ushort *p);
int16 __overload vload16(size_t offset, const __global int *p);
uint16 __overload vload16(size_t offset, const __global uint *p);
long16 __overload vload16(size_t offset, const __global long *p);
ulong16 __overload vload16(size_t offset, const __global ulong *p);
float16 __overload vload16(size_t offset, const __global float *p);
char2 __overload vload2(size_t offset, const __local char *p);
uchar2 __overload vload2(size_t offset, const __local uchar *p);
short2 __overload vload2(size_t offset, const __local short *p);
ushort2 __overload vload2(size_t offset, const __local ushort *p);
int2 __overload vload2(size_t offset, const __local int *p);
uint2 __overload vload2(size_t offset, const __local uint *p);
long2 __overload vload2(size_t offset, const __local long *p);
ulong2 __overload vload2(size_t offset, const __local ulong *p);
float2 __overload vload2(size_t offset, const __local float *p);
char3 __overload vload3(size_t offset, const __local char *p);
uchar3 __overload vload3(size_t offset, const __local uchar *p);
short3 __overload vload3(size_t offset, const __local short *p);
ushort3 __overload vload3(size_t offset, const __local ushort *p);
int3 __overload vload3(size_t offset, const __local int *p);
uint3 __overload vload3(size_t offset, const __local uint *p);
long3 __overload vload3(size_t offset, const __local long *p);
ulong3 __overload vload3(size_t offset, const __local ulong *p);
float3 __overload vload3(size_t offset, const __local float *p);
char4 __overload vload4(size_t offset, const __local char *p);
uchar4 __overload vload4(size_t offset, const __local uchar *p);
short4 __overload vload4(size_t offset, const __local short *p);
ushort4 __overload vload4(size_t offset, const __local ushort *p);
int4 __overload vload4(size_t offset, const __local int *p);
uint4 __overload vload4(size_t offset, const __local uint *p);
long4 __overload vload4(size_t offset, const __local long *p);
ulong4 __overload vload4(size_t offset, const __local ulong *p);
float4 __overload vload4(size_t offset, const __local float *p);
char8 __overload vload8(size_t offset, const __local char *p);
uchar8 __overload vload8(size_t offset, const __local uchar *p);
short8 __overload vload8(size_t offset, const __local short *p);
ushort8 __overload vload8(size_t offset, const __local ushort *p);
int8 __overload vload8(size_t offset, const __local int *p);
uint8 __overload vload8(size_t offset, const __local uint *p);
long8 __overload vload8(size_t offset, const __local long *p);
ulong8 __overload vload8(size_t offset, const __local ulong *p);
float8 __overload vload8(size_t offset, const __local float *p);
char16 __overload vload16(size_t offset, const __local char *p);
uchar16 __overload vload16(size_t offset, const __local uchar *p);
short16 __overload vload16(size_t offset, const __local short *p);
ushort16 __overload vload16(size_t offset, const __local ushort *p);
int16 __overload vload16(size_t offset, const __local int *p);
uint16 __overload vload16(size_t offset, const __local uint *p);
long16 __overload vload16(size_t offset, const __local long *p);
ulong16 __overload vload16(size_t offset, const __local ulong *p);
float16 __overload vload16(size_t offset, const __local float *p);
char2 __overload vload2(size_t offset, const __private char *p);
uchar2 __overload vload2(size_t offset, const __private uchar *p);
short2 __overload vload2(size_t offset, const __private short *p);
ushort2 __overload vload2(size_t offset, const __private ushort *p);
int2 __overload vload2(size_t offset, const __private int *p);
uint2 __overload vload2(size_t offset, const __private uint *p);
long2 __overload vload2(size_t offset, const __private long *p);
ulong2 __overload vload2(size_t offset, const __private ulong *p);
float2 __overload vload2(size_t offset, const __private float *p);
char3 __overload vload3(size_t offset, const __private char *p);
uchar3 __overload vload3(size_t offset, const __private uchar *p);
short3 __overload vload3(size_t offset, const __private short *p);
ushort3 __overload vload3(size_t offset, const __private ushort *p);
int3 __overload vload3(size_t offset, const __private int *p);
uint3 __overload vload3(size_t offset, const __private uint *p);
long3 __overload vload3(size_t offset, const __private long *p);
ulong3 __overload vload3(size_t offset, const __private ulong *p);
float3 __overload vload3(size_t offset, const __private float *p);
char4 __overload vload4(size_t offset, const __private char *p);
uchar4 __overload vload4(size_t offset, const __private uchar *p);
short4 __overload vload4(size_t offset, const __private short *p);
ushort4 __overload vload4(size_t offset, const __private ushort *p);
int4 __overload vload4(size_t offset, const __private int *p);
uint4 __overload vload4(size_t offset, const __private uint *p);
long4 __overload vload4(size_t offset, const __private long *p);
ulong4 __overload vload4(size_t offset, const __private ulong *p);
float4 __overload vload4(size_t offset, const __private float *p);
char8 __overload vload8(size_t offset, const __private char *p);
uchar8 __overload vload8(size_t offset, const __private uchar *p);
short8 __overload vload8(size_t offset, const __private short *p);
ushort8 __overload vload8(size_t offset, const __private ushort *p);
int8 __overload vload8(size_t offset, const __private int *p);
uint8 __overload vload8(size_t offset, const __private uint *p);
long8 __overload vload8(size_t offset, const __private long *p);
ulong8 __overload vload8(size_t offset, const __private ulong *p);
float8 __overload vload8(size_t offset, const __private float *p);
char16 __overload vload16(size_t offset, const __private char *p);
uchar16 __overload vload16(size_t offset, const __private uchar *p);
short16 __overload vload16(size_t offset, const __private short *p);
ushort16 __overload vload16(size_t offset, const __private ushort *p);
int16 __overload vload16(size_t offset, const __private int *p);
uint16 __overload vload16(size_t offset, const __private uint *p);
long16 __overload vload16(size_t offset, const __private long *p);
ulong16 __overload vload16(size_t offset, const __private ulong *p);
float16 __overload vload16(size_t offset, const __private float *p);

#ifdef cl_khr_fp64
double2 __overload vload2(size_t offset, const __global double *p);
double3 __overload vload3(size_t offset, const __global double *p);
double4 __overload vload4(size_t offset, const __global double *p);
double8 __overload vload8(size_t offset, const __global double *p);
double16 __overload vload16(size_t offset, const __global double *p);
double2 __overload vload2(size_t offset, const __local double *p);
double3 __overload vload3(size_t offset, const __local double *p);
double4 __overload vload4(size_t offset, const __local double *p);
double8 __overload vload8(size_t offset, const __local double *p);
double16 __overload vload16(size_t offset, const __local double *p);
double2 __overload vload2(size_t offset, const __private double *p);
double3 __overload vload3(size_t offset, const __private double *p);
double4 __overload vload4(size_t offset, const __private double *p);
double8 __overload vload8(size_t offset, const __private double *p);
double16 __overload vload16(size_t offset, const __private double *p);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half __overload vload(size_t offset, const __global half *p);
half2 __overload vload2(size_t offset, const __global half *p);
half3 __overload vload3(size_t offset, const __global half *p);
half4 __overload vload4(size_t offset, const __global half *p);
half8 __overload vload8(size_t offset, const __global half *p);
half16 __overload vload16(size_t offset, const __global half *p);
half __overload vload(size_t offset, const __local half *p);
half2 __overload vload2(size_t offset, const __local half *p);
half3 __overload vload3(size_t offset, const __local half *p);
half4 __overload vload4(size_t offset, const __local half *p);
half8 __overload vload8(size_t offset, const __local half *p);
half16 __overload vload16(size_t offset, const __local half *p);
half __overload vload(size_t offset, const __private half *p);
half2 __overload vload2(size_t offset, const __private half *p);
half3 __overload vload3(size_t offset, const __private half *p);
half4 __overload vload4(size_t offset, const __private half *p);
half8 __overload vload8(size_t offset, const __private half *p);
half16 __overload vload16(size_t offset, const __private half *p);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Write sizeof (gentypen) bytes given by data
 * to address (p + (offset * n)). The address
 * computed as (p + (offset * n)) must be 8-bit
 * aligned if gentype is char, uchar; 16-bit
 * aligned if gentype is short, ushort; 32-bit
 * aligned if gentype is int, uint, float; 64-bit
 * aligned if gentype is long, ulong.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
void __overload vstore2(char2 data, size_t offset, char *p);
void __overload vstore2(uchar2 data, size_t offset, uchar *p);
void __overload vstore2(short2 data, size_t offset, short *p);
void __overload vstore2(ushort2 data, size_t offset, ushort *p);
void __overload vstore2(int2 data, size_t offset, int *p);
void __overload vstore2(uint2 data, size_t offset, uint *p);
void __overload vstore2(long2 data, size_t offset, long *p);
void __overload vstore2(ulong2 data, size_t offset, ulong *p);
void __overload vstore2(float2 data, size_t offset, float *p);
void __overload vstore3(char3 data, size_t offset, char *p);
void __overload vstore3(uchar3 data, size_t offset, uchar *p);
void __overload vstore3(short3 data, size_t offset, short *p);
void __overload vstore3(ushort3 data, size_t offset, ushort *p);
void __overload vstore3(int3 data, size_t offset, int *p);
void __overload vstore3(uint3 data, size_t offset, uint *p);
void __overload vstore3(long3 data, size_t offset, long *p);
void __overload vstore3(ulong3 data, size_t offset, ulong *p);
void __overload vstore3(float3 data, size_t offset, float *p);
void __overload vstore4(char4 data, size_t offset, char *p);
void __overload vstore4(uchar4 data, size_t offset, uchar *p);
void __overload vstore4(short4 data, size_t offset, short *p);
void __overload vstore4(ushort4 data, size_t offset, ushort *p);
void __overload vstore4(int4 data, size_t offset, int *p);
void __overload vstore4(uint4 data, size_t offset, uint *p);
void __overload vstore4(long4 data, size_t offset, long *p);
void __overload vstore4(ulong4 data, size_t offset, ulong *p);
void __overload vstore4(float4 data, size_t offset, float *p);
void __overload vstore8(char8 data, size_t offset, char *p);
void __overload vstore8(uchar8 data, size_t offset, uchar *p);
void __overload vstore8(short8 data, size_t offset, short *p);
void __overload vstore8(ushort8 data, size_t offset, ushort *p);
void __overload vstore8(int8 data, size_t offset, int *p);
void __overload vstore8(uint8 data, size_t offset, uint *p);
void __overload vstore8(long8 data, size_t offset, long *p);
void __overload vstore8(ulong8 data, size_t offset, ulong *p);
void __overload vstore8(float8 data, size_t offset, float *p);
void __overload vstore16(char16 data, size_t offset, char *p);
void __overload vstore16(uchar16 data, size_t offset, uchar *p);
void __overload vstore16(short16 data, size_t offset, short *p);
void __overload vstore16(ushort16 data, size_t offset, ushort *p);
void __overload vstore16(int16 data, size_t offset, int *p);
void __overload vstore16(uint16 data, size_t offset, uint *p);
void __overload vstore16(long16 data, size_t offset, long *p);
void __overload vstore16(ulong16 data, size_t offset, ulong *p);
void __overload vstore16(float16 data, size_t offset, float *p);
#ifdef cl_khr_fp64
void __overload vstore2(double2 data, size_t offset, double *p);
void __overload vstore3(double3 data, size_t offset, double *p);
void __overload vstore4(double4 data, size_t offset, double *p);
void __overload vstore8(double8 data, size_t offset, double *p);
void __overload vstore16(double16 data, size_t offset, double *p);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
void __overload vstore(half data, size_t offset, half *p);
void __overload vstore2(half2 data, size_t offset, half *p);
void __overload vstore3(half3 data, size_t offset, half *p);
void __overload vstore4(half4 data, size_t offset, half *p);
void __overload vstore8(half8 data, size_t offset, half *p);
void __overload vstore16(half16 data, size_t offset, half *p);
#endif //cl_khr_fp16
#else
void __overload vstore2(char2 data, size_t offset, __global char *p);
void __overload vstore2(uchar2 data, size_t offset, __global uchar *p);
void __overload vstore2(short2 data, size_t offset, __global short *p);
void __overload vstore2(ushort2 data, size_t offset, __global ushort *p);
void __overload vstore2(int2 data, size_t offset, __global int *p);
void __overload vstore2(uint2 data, size_t offset, __global uint *p);
void __overload vstore2(long2 data, size_t offset, __global long *p);
void __overload vstore2(ulong2 data, size_t offset, __global ulong *p);
void __overload vstore2(float2 data, size_t offset, __global float *p);
void __overload vstore3(char3 data, size_t offset, __global char *p);
void __overload vstore3(uchar3 data, size_t offset, __global uchar *p);
void __overload vstore3(short3 data, size_t offset, __global short *p);
void __overload vstore3(ushort3 data, size_t offset, __global ushort *p);
void __overload vstore3(int3 data, size_t offset, __global int *p);
void __overload vstore3(uint3 data, size_t offset, __global uint *p);
void __overload vstore3(long3 data, size_t offset, __global long *p);
void __overload vstore3(ulong3 data, size_t offset, __global ulong *p);
void __overload vstore3(float3 data, size_t offset, __global float *p);
void __overload vstore4(char4 data, size_t offset, __global char *p);
void __overload vstore4(uchar4 data, size_t offset, __global uchar *p);
void __overload vstore4(short4 data, size_t offset, __global short *p);
void __overload vstore4(ushort4 data, size_t offset, __global ushort *p);
void __overload vstore4(int4 data, size_t offset, __global int *p);
void __overload vstore4(uint4 data, size_t offset, __global uint *p);
void __overload vstore4(long4 data, size_t offset, __global long *p);
void __overload vstore4(ulong4 data, size_t offset, __global ulong *p);
void __overload vstore4(float4 data, size_t offset, __global float *p);
void __overload vstore8(char8 data, size_t offset, __global char *p);
void __overload vstore8(uchar8 data, size_t offset, __global uchar *p);
void __overload vstore8(short8 data, size_t offset, __global short *p);
void __overload vstore8(ushort8 data, size_t offset, __global ushort *p);
void __overload vstore8(int8 data, size_t offset, __global int *p);
void __overload vstore8(uint8 data, size_t offset, __global uint *p);
void __overload vstore8(long8 data, size_t offset, __global long *p);
void __overload vstore8(ulong8 data, size_t offset, __global ulong *p);
void __overload vstore8(float8 data, size_t offset, __global float *p);
void __overload vstore16(char16 data, size_t offset, __global char *p);
void __overload vstore16(uchar16 data, size_t offset, __global uchar *p);
void __overload vstore16(short16 data, size_t offset, __global short *p);
void __overload vstore16(ushort16 data, size_t offset, __global ushort *p);
void __overload vstore16(int16 data, size_t offset, __global int *p);
void __overload vstore16(uint16 data, size_t offset, __global uint *p);
void __overload vstore16(long16 data, size_t offset, __global long *p);
void __overload vstore16(ulong16 data, size_t offset, __global ulong *p);
void __overload vstore16(float16 data, size_t offset, __global float *p);
void __overload vstore2(char2 data, size_t offset, __local char *p);
void __overload vstore2(uchar2 data, size_t offset, __local uchar *p);
void __overload vstore2(short2 data, size_t offset, __local short *p);
void __overload vstore2(ushort2 data, size_t offset, __local ushort *p);
void __overload vstore2(int2 data, size_t offset, __local int *p);
void __overload vstore2(uint2 data, size_t offset, __local uint *p);
void __overload vstore2(long2 data, size_t offset, __local long *p);
void __overload vstore2(ulong2 data, size_t offset, __local ulong *p);
void __overload vstore2(float2 data, size_t offset, __local float *p);
void __overload vstore3(char3 data, size_t offset, __local char *p);
void __overload vstore3(uchar3 data, size_t offset, __local uchar *p);
void __overload vstore3(short3 data, size_t offset, __local short *p);
void __overload vstore3(ushort3 data, size_t offset, __local ushort *p);
void __overload vstore3(int3 data, size_t offset, __local int *p);
void __overload vstore3(uint3 data, size_t offset, __local uint *p);
void __overload vstore3(long3 data, size_t offset, __local long *p);
void __overload vstore3(ulong3 data, size_t offset, __local ulong *p);
void __overload vstore3(float3 data, size_t offset, __local float *p);
void __overload vstore4(char4 data, size_t offset, __local char *p);
void __overload vstore4(uchar4 data, size_t offset, __local uchar *p);
void __overload vstore4(short4 data, size_t offset, __local short *p);
void __overload vstore4(ushort4 data, size_t offset, __local ushort *p);
void __overload vstore4(int4 data, size_t offset, __local int *p);
void __overload vstore4(uint4 data, size_t offset, __local uint *p);
void __overload vstore4(long4 data, size_t offset, __local long *p);
void __overload vstore4(ulong4 data, size_t offset, __local ulong *p);
void __overload vstore4(float4 data, size_t offset, __local float *p);
void __overload vstore8(char8 data, size_t offset, __local char *p);
void __overload vstore8(uchar8 data, size_t offset, __local uchar *p);
void __overload vstore8(short8 data, size_t offset, __local short *p);
void __overload vstore8(ushort8 data, size_t offset, __local ushort *p);
void __overload vstore8(int8 data, size_t offset, __local int *p);
void __overload vstore8(uint8 data, size_t offset, __local uint *p);
void __overload vstore8(long8 data, size_t offset, __local long *p);
void __overload vstore8(ulong8 data, size_t offset, __local ulong *p);
void __overload vstore8(float8 data, size_t offset, __local float *p);
void __overload vstore16(char16 data, size_t offset, __local char *p);
void __overload vstore16(uchar16 data, size_t offset, __local uchar *p);
void __overload vstore16(short16 data, size_t offset, __local short *p);
void __overload vstore16(ushort16 data, size_t offset, __local ushort *p);
void __overload vstore16(int16 data, size_t offset, __local int *p);
void __overload vstore16(uint16 data, size_t offset, __local uint *p);
void __overload vstore16(long16 data, size_t offset, __local long *p);
void __overload vstore16(ulong16 data, size_t offset, __local ulong *p);
void __overload vstore16(float16 data, size_t offset, __local float *p);
void __overload vstore2(char2 data, size_t offset, __private char *p);
void __overload vstore2(uchar2 data, size_t offset, __private uchar *p);
void __overload vstore2(short2 data, size_t offset, __private short *p);
void __overload vstore2(ushort2 data, size_t offset, __private ushort *p);
void __overload vstore2(int2 data, size_t offset, __private int *p);
void __overload vstore2(uint2 data, size_t offset, __private uint *p);
void __overload vstore2(long2 data, size_t offset, __private long *p);
void __overload vstore2(ulong2 data, size_t offset, __private ulong *p);
void __overload vstore2(float2 data, size_t offset, __private float *p);
void __overload vstore3(char3 data, size_t offset, __private char *p);
void __overload vstore3(uchar3 data, size_t offset, __private uchar *p);
void __overload vstore3(short3 data, size_t offset, __private short *p);
void __overload vstore3(ushort3 data, size_t offset, __private ushort *p);
void __overload vstore3(int3 data, size_t offset, __private int *p);
void __overload vstore3(uint3 data, size_t offset, __private uint *p);
void __overload vstore3(long3 data, size_t offset, __private long *p);
void __overload vstore3(ulong3 data, size_t offset, __private ulong *p);
void __overload vstore3(float3 data, size_t offset, __private float *p);
void __overload vstore4(char4 data, size_t offset, __private char *p);
void __overload vstore4(uchar4 data, size_t offset, __private uchar *p);
void __overload vstore4(short4 data, size_t offset, __private short *p);
void __overload vstore4(ushort4 data, size_t offset, __private ushort *p);
void __overload vstore4(int4 data, size_t offset, __private int *p);
void __overload vstore4(uint4 data, size_t offset, __private uint *p);
void __overload vstore4(long4 data, size_t offset, __private long *p);
void __overload vstore4(ulong4 data, size_t offset, __private ulong *p);
void __overload vstore4(float4 data, size_t offset, __private float *p);
void __overload vstore8(char8 data, size_t offset, __private char *p);
void __overload vstore8(uchar8 data, size_t offset, __private uchar *p);
void __overload vstore8(short8 data, size_t offset, __private short *p);
void __overload vstore8(ushort8 data, size_t offset, __private ushort *p);
void __overload vstore8(int8 data, size_t offset, __private int *p);
void __overload vstore8(uint8 data, size_t offset, __private uint *p);
void __overload vstore8(long8 data, size_t offset, __private long *p);
void __overload vstore8(ulong8 data, size_t offset, __private ulong *p);
void __overload vstore8(float8 data, size_t offset, __private float *p);
void __overload vstore16(char16 data, size_t offset, __private char *p);
void __overload vstore16(uchar16 data, size_t offset, __private uchar *p);
void __overload vstore16(short16 data, size_t offset, __private short *p);
void __overload vstore16(ushort16 data, size_t offset, __private ushort *p);
void __overload vstore16(int16 data, size_t offset, __private int *p);
void __overload vstore16(uint16 data, size_t offset, __private uint *p);
void __overload vstore16(long16 data, size_t offset, __private long *p);
void __overload vstore16(ulong16 data, size_t offset, __private ulong *p);
void __overload vstore16(float16 data, size_t offset, __private float *p);
#ifdef cl_khr_fp64
void __overload vstore2(double2 data, size_t offset, __global double *p);
void __overload vstore3(double3 data, size_t offset, __global double *p);
void __overload vstore4(double4 data, size_t offset, __global double *p);
void __overload vstore8(double8 data, size_t offset, __global double *p);
void __overload vstore16(double16 data, size_t offset, __global double *p);
void __overload vstore2(double2 data, size_t offset, __local double *p);
void __overload vstore3(double3 data, size_t offset, __local double *p);
void __overload vstore4(double4 data, size_t offset, __local double *p);
void __overload vstore8(double8 data, size_t offset, __local double *p);
void __overload vstore16(double16 data, size_t offset, __local double *p);
void __overload vstore2(double2 data, size_t offset, __private double *p);
void __overload vstore3(double3 data, size_t offset, __private double *p);
void __overload vstore4(double4 data, size_t offset, __private double *p);
void __overload vstore8(double8 data, size_t offset, __private double *p);
void __overload vstore16(double16 data, size_t offset, __private double *p);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
void __overload vstore(half data, size_t offset, __global half *p);
void __overload vstore2(half2 data, size_t offset, __global half *p);
void __overload vstore3(half3 data, size_t offset, __global half *p);
void __overload vstore4(half4 data, size_t offset, __global half *p);
void __overload vstore8(half8 data, size_t offset, __global half *p);
void __overload vstore16(half16 data, size_t offset, __global half *p);
void __overload vstore(half data, size_t offset, __local half *p);
void __overload vstore2(half2 data, size_t offset, __local half *p);
void __overload vstore3(half3 data, size_t offset, __local half *p);
void __overload vstore4(half4 data, size_t offset, __local half *p);
void __overload vstore8(half8 data, size_t offset, __local half *p);
void __overload vstore16(half16 data, size_t offset, __local half *p);
void __overload vstore(half data, size_t offset, __private half *p);
void __overload vstore2(half2 data, size_t offset, __private half *p);
void __overload vstore3(half3 data, size_t offset, __private half *p);
void __overload vstore4(half4 data, size_t offset, __private half *p);
void __overload vstore8(half8 data, size_t offset, __private half *p);
void __overload vstore16(half16 data, size_t offset, __private half *p);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Read sizeof (half) bytes of data from address
 * (p + offset). The data read is interpreted as a
 * half value. The half value is converted to a
 * float value and the float value is returned.
 * The read address computed as (p + offset)
 * must be 16-bit aligned.
 */
float __overload vload_half(size_t offset, const __constant half *p);
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload vload_half(size_t offset, const half *p);
#else
float __overload vload_half(size_t offset, const __global half *p);
float __overload vload_half(size_t offset, const __local half *p);
float __overload vload_half(size_t offset, const __private half *p);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Read sizeof (halfn) bytes of data from address
 * (p + (offset * n)). The data read is interpreted
 * as a halfn value. The halfn value read is
 * converted to a floatn value and the floatn
 * value is returned. The read address computed
 * as (p + (offset * n)) must be 16-bit aligned.
 */
float2 __overload vload_half2(size_t offset, const __constant half *p);
float3 __overload vload_half3(size_t offset, const __constant half *p);
float4 __overload vload_half4(size_t offset, const __constant half *p);
float8 __overload vload_half8(size_t offset, const __constant half *p);
float16 __overload vload_half16(size_t offset, const __constant half *p);
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float2 __overload vload_half2(size_t offset, const half *p);
float3 __overload vload_half3(size_t offset, const half *p);
float4 __overload vload_half4(size_t offset, const half *p);
float8 __overload vload_half8(size_t offset, const half *p);
float16 __overload vload_half16(size_t offset, const half *p);
#else
float2 __overload vload_half2(size_t offset, const __global half *p);
float3 __overload vload_half3(size_t offset, const __global half *p);
float4 __overload vload_half4(size_t offset, const __global half *p);
float8 __overload vload_half8(size_t offset, const __global half *p);
float16 __overload vload_half16(size_t offset, const __global half *p);
float2 __overload vload_half2(size_t offset, const __local half *p);
float3 __overload vload_half3(size_t offset, const __local half *p);
float4 __overload vload_half4(size_t offset, const __local half *p);
float8 __overload vload_half8(size_t offset, const __local half *p);
float16 __overload vload_half16(size_t offset, const __local half *p);
float2 __overload vload_half2(size_t offset, const __private half *p);
float3 __overload vload_half3(size_t offset, const __private half *p);
float4 __overload vload_half4(size_t offset, const __private half *p);
float8 __overload vload_half8(size_t offset, const __private half *p);
float16 __overload vload_half16(size_t offset, const __private half *p);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * The float value given by data is first
 * converted to a half value using the appropriate
 * rounding mode. The half value is then written
 * to address computed as (p + offset). The
 * address computed as (p + offset) must be 16-
 * bit aligned.
 * vstore_half use the current rounding mode.
 * The default current rounding mode is round to
 * nearest even.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
void __overload vstore_half(float data, size_t offset, half *p);
void __overload vstore_half_rte(float data, size_t offset, half *p);
void __overload vstore_half_rtz(float data, size_t offset, half *p);
void __overload vstore_half_rtp(float data, size_t offset, half *p);
void __overload vstore_half_rtn(float data, size_t offset, half *p);
#ifdef cl_khr_fp64
void __overload vstore_half(double data, size_t offset, half *p);
void __overload vstore_half_rte(double data, size_t offset, half *p);
void __overload vstore_half_rtz(double data, size_t offset, half *p);
void __overload vstore_half_rtp(double data, size_t offset, half *p);
void __overload vstore_half_rtn(double data, size_t offset, half *p);
#endif //cl_khr_fp64
#else
void __overload vstore_half(float data, size_t offset, __global half *p);
void __overload vstore_half_rte(float data, size_t offset, __global half *p);
void __overload vstore_half_rtz(float data, size_t offset, __global half *p);
void __overload vstore_half_rtp(float data, size_t offset, __global half *p);
void __overload vstore_half_rtn(float data, size_t offset, __global half *p);
void __overload vstore_half(float data, size_t offset, __local half *p);
void __overload vstore_half_rte(float data, size_t offset, __local half *p);
void __overload vstore_half_rtz(float data, size_t offset, __local half *p);
void __overload vstore_half_rtp(float data, size_t offset, __local half *p);
void __overload vstore_half_rtn(float data, size_t offset, __local half *p);
void __overload vstore_half(float data, size_t offset, __private half *p);
void __overload vstore_half_rte(float data, size_t offset, __private half *p);
void __overload vstore_half_rtz(float data, size_t offset, __private half *p);
void __overload vstore_half_rtp(float data, size_t offset, __private half *p);
void __overload vstore_half_rtn(float data, size_t offset, __private half *p);
#ifdef cl_khr_fp64
void __overload vstore_half(double data, size_t offset, __global half *p);
void __overload vstore_half_rte(double data, size_t offset, __global half *p);
void __overload vstore_half_rtz(double data, size_t offset, __global half *p);
void __overload vstore_half_rtp(double data, size_t offset, __global half *p);
void __overload vstore_half_rtn(double data, size_t offset, __global half *p);
void __overload vstore_half(double data, size_t offset, __local half *p);
void __overload vstore_half_rte(double data, size_t offset, __local half *p);
void __overload vstore_half_rtz(double data, size_t offset, __local half *p);
void __overload vstore_half_rtp(double data, size_t offset, __local half *p);
void __overload vstore_half_rtn(double data, size_t offset, __local half *p);
void __overload vstore_half(double data, size_t offset, __private half *p);
void __overload vstore_half_rte(double data, size_t offset, __private half *p);
void __overload vstore_half_rtz(double data, size_t offset, __private half *p);
void __overload vstore_half_rtp(double data, size_t offset, __private half *p);
void __overload vstore_half_rtn(double data, size_t offset, __private half *p);
#endif //cl_khr_fp64
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * The floatn value given by data is converted to
 * a halfn value using the appropriate rounding
 * mode. The halfn value is then written to
 * address computed as (p + (offset * n)). The
 * address computed as (p + (offset * n)) must be
 * 16-bit aligned.
 * vstore_halfn uses the current rounding mode.
 * The default current rounding mode is round to
 * nearest even.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
void __overload vstore_half2(float2 data, size_t offset, half *p);
void __overload vstore_half3(float3 data, size_t offset, half *p);
void __overload vstore_half4(float4 data, size_t offset, half *p);
void __overload vstore_half8(float8 data, size_t offset, half *p);
void __overload vstore_half16(float16 data, size_t offset, half *p);
void __overload vstore_half2_rte(float2 data, size_t offset, half *p);
void __overload vstore_half3_rte(float3 data, size_t offset, half *p);
void __overload vstore_half4_rte(float4 data, size_t offset, half *p);
void __overload vstore_half8_rte(float8 data, size_t offset, half *p);
void __overload vstore_half16_rte(float16 data, size_t offset, half *p);
void __overload vstore_half2_rtz(float2 data, size_t offset, half *p);
void __overload vstore_half3_rtz(float3 data, size_t offset, half *p);
void __overload vstore_half4_rtz(float4 data, size_t offset, half *p);
void __overload vstore_half8_rtz(float8 data, size_t offset, half *p);
void __overload vstore_half16_rtz(float16 data, size_t offset, half *p);
void __overload vstore_half2_rtp(float2 data, size_t offset, half *p);
void __overload vstore_half3_rtp(float3 data, size_t offset, half *p);
void __overload vstore_half4_rtp(float4 data, size_t offset, half *p);
void __overload vstore_half8_rtp(float8 data, size_t offset, half *p);
void __overload vstore_half16_rtp(float16 data, size_t offset, half *p);
void __overload vstore_half2_rtn(float2 data, size_t offset, half *p);
void __overload vstore_half3_rtn(float3 data, size_t offset, half *p);
void __overload vstore_half4_rtn(float4 data, size_t offset, half *p);
void __overload vstore_half8_rtn(float8 data, size_t offset, half *p);
void __overload vstore_half16_rtn(float16 data, size_t offset, half *p);
#ifdef cl_khr_fp64
void __overload vstore_half2(double2 data, size_t offset, half *p);
void __overload vstore_half3(double3 data, size_t offset, half *p);
void __overload vstore_half4(double4 data, size_t offset, half *p);
void __overload vstore_half8(double8 data, size_t offset, half *p);
void __overload vstore_half16(double16 data, size_t offset, half *p);
void __overload vstore_half2_rte(double2 data, size_t offset, half *p);
void __overload vstore_half3_rte(double3 data, size_t offset, half *p);
void __overload vstore_half4_rte(double4 data, size_t offset, half *p);
void __overload vstore_half8_rte(double8 data, size_t offset, half *p);
void __overload vstore_half16_rte(double16 data, size_t offset, half *p);
void __overload vstore_half2_rtz(double2 data, size_t offset, half *p);
void __overload vstore_half3_rtz(double3 data, size_t offset, half *p);
void __overload vstore_half4_rtz(double4 data, size_t offset, half *p);
void __overload vstore_half8_rtz(double8 data, size_t offset, half *p);
void __overload vstore_half16_rtz(double16 data, size_t offset, half *p);
void __overload vstore_half2_rtp(double2 data, size_t offset, half *p);
void __overload vstore_half3_rtp(double3 data, size_t offset, half *p);
void __overload vstore_half4_rtp(double4 data, size_t offset, half *p);
void __overload vstore_half8_rtp(double8 data, size_t offset, half *p);
void __overload vstore_half16_rtp(double16 data, size_t offset, half *p);
void __overload vstore_half2_rtn(double2 data, size_t offset, half *p);
void __overload vstore_half3_rtn(double3 data, size_t offset, half *p);
void __overload vstore_half4_rtn(double4 data, size_t offset, half *p);
void __overload vstore_half8_rtn(double8 data, size_t offset, half *p);
void __overload vstore_half16_rtn(double16 data, size_t offset, half *p);
#endif //cl_khr_fp64
#else
void __overload vstore_half2(float2 data, size_t offset, __global half *p);
void __overload vstore_half3(float3 data, size_t offset, __global half *p);
void __overload vstore_half4(float4 data, size_t offset, __global half *p);
void __overload vstore_half8(float8 data, size_t offset, __global half *p);
void __overload vstore_half16(float16 data, size_t offset, __global half *p);
void __overload vstore_half2_rte(float2 data, size_t offset, __global half *p);
void __overload vstore_half3_rte(float3 data, size_t offset, __global half *p);
void __overload vstore_half4_rte(float4 data, size_t offset, __global half *p);
void __overload vstore_half8_rte(float8 data, size_t offset, __global half *p);
void __overload vstore_half16_rte(float16 data, size_t offset, __global half *p);
void __overload vstore_half2_rtz(float2 data, size_t offset, __global half *p);
void __overload vstore_half3_rtz(float3 data, size_t offset, __global half *p);
void __overload vstore_half4_rtz(float4 data, size_t offset, __global half *p);
void __overload vstore_half8_rtz(float8 data, size_t offset, __global half *p);
void __overload vstore_half16_rtz(float16 data, size_t offset, __global half *p);
void __overload vstore_half2_rtp(float2 data, size_t offset, __global half *p);
void __overload vstore_half3_rtp(float3 data, size_t offset, __global half *p);
void __overload vstore_half4_rtp(float4 data, size_t offset, __global half *p);
void __overload vstore_half8_rtp(float8 data, size_t offset, __global half *p);
void __overload vstore_half16_rtp(float16 data, size_t offset, __global half *p);
void __overload vstore_half2_rtn(float2 data, size_t offset, __global half *p);
void __overload vstore_half3_rtn(float3 data, size_t offset, __global half *p);
void __overload vstore_half4_rtn(float4 data, size_t offset, __global half *p);
void __overload vstore_half8_rtn(float8 data, size_t offset, __global half *p);
void __overload vstore_half16_rtn(float16 data, size_t offset, __global half *p);
void __overload vstore_half2(float2 data, size_t offset, __local half *p);
void __overload vstore_half3(float3 data, size_t offset, __local half *p);
void __overload vstore_half4(float4 data, size_t offset, __local half *p);
void __overload vstore_half8(float8 data, size_t offset, __local half *p);
void __overload vstore_half16(float16 data, size_t offset, __local half *p);
void __overload vstore_half2_rte(float2 data, size_t offset, __local half *p);
void __overload vstore_half3_rte(float3 data, size_t offset, __local half *p);
void __overload vstore_half4_rte(float4 data, size_t offset, __local half *p);
void __overload vstore_half8_rte(float8 data, size_t offset, __local half *p);
void __overload vstore_half16_rte(float16 data, size_t offset, __local half *p);
void __overload vstore_half2_rtz(float2 data, size_t offset, __local half *p);
void __overload vstore_half3_rtz(float3 data, size_t offset, __local half *p);
void __overload vstore_half4_rtz(float4 data, size_t offset, __local half *p);
void __overload vstore_half8_rtz(float8 data, size_t offset, __local half *p);
void __overload vstore_half16_rtz(float16 data, size_t offset, __local half *p);
void __overload vstore_half2_rtp(float2 data, size_t offset, __local half *p);
void __overload vstore_half3_rtp(float3 data, size_t offset, __local half *p);
void __overload vstore_half4_rtp(float4 data, size_t offset, __local half *p);
void __overload vstore_half8_rtp(float8 data, size_t offset, __local half *p);
void __overload vstore_half16_rtp(float16 data, size_t offset, __local half *p);
void __overload vstore_half2_rtn(float2 data, size_t offset, __local half *p);
void __overload vstore_half3_rtn(float3 data, size_t offset, __local half *p);
void __overload vstore_half4_rtn(float4 data, size_t offset, __local half *p);
void __overload vstore_half8_rtn(float8 data, size_t offset, __local half *p);
void __overload vstore_half16_rtn(float16 data, size_t offset, __local half *p);
void __overload vstore_half2(float2 data, size_t offset, __private half *p);
void __overload vstore_half3(float3 data, size_t offset, __private half *p);
void __overload vstore_half4(float4 data, size_t offset, __private half *p);
void __overload vstore_half8(float8 data, size_t offset, __private half *p);
void __overload vstore_half16(float16 data, size_t offset, __private half *p);
void __overload vstore_half2_rte(float2 data, size_t offset, __private half *p);
void __overload vstore_half3_rte(float3 data, size_t offset, __private half *p);
void __overload vstore_half4_rte(float4 data, size_t offset, __private half *p);
void __overload vstore_half8_rte(float8 data, size_t offset, __private half *p);
void __overload vstore_half16_rte(float16 data, size_t offset, __private half *p);
void __overload vstore_half2_rtz(float2 data, size_t offset, __private half *p);
void __overload vstore_half3_rtz(float3 data, size_t offset, __private half *p);
void __overload vstore_half4_rtz(float4 data, size_t offset, __private half *p);
void __overload vstore_half8_rtz(float8 data, size_t offset, __private half *p);
void __overload vstore_half16_rtz(float16 data, size_t offset, __private half *p);
void __overload vstore_half2_rtp(float2 data, size_t offset, __private half *p);
void __overload vstore_half3_rtp(float3 data, size_t offset, __private half *p);
void __overload vstore_half4_rtp(float4 data, size_t offset, __private half *p);
void __overload vstore_half8_rtp(float8 data, size_t offset, __private half *p);
void __overload vstore_half16_rtp(float16 data, size_t offset, __private half *p);
void __overload vstore_half2_rtn(float2 data, size_t offset, __private half *p);
void __overload vstore_half3_rtn(float3 data, size_t offset, __private half *p);
void __overload vstore_half4_rtn(float4 data, size_t offset, __private half *p);
void __overload vstore_half8_rtn(float8 data, size_t offset, __private half *p);
void __overload vstore_half16_rtn(float16 data, size_t offset, __private half *p);
#ifdef cl_khr_fp64
void __overload vstore_half2(double2 data, size_t offset, __global half *p);
void __overload vstore_half3(double3 data, size_t offset, __global half *p);
void __overload vstore_half4(double4 data, size_t offset, __global half *p);
void __overload vstore_half8(double8 data, size_t offset, __global half *p);
void __overload vstore_half16(double16 data, size_t offset, __global half *p);
void __overload vstore_half2_rte(double2 data, size_t offset, __global half *p);
void __overload vstore_half3_rte(double3 data, size_t offset, __global half *p);
void __overload vstore_half4_rte(double4 data, size_t offset, __global half *p);
void __overload vstore_half8_rte(double8 data, size_t offset, __global half *p);
void __overload vstore_half16_rte(double16 data, size_t offset, __global half *p);
void __overload vstore_half2_rtz(double2 data, size_t offset, __global half *p);
void __overload vstore_half3_rtz(double3 data, size_t offset, __global half *p);
void __overload vstore_half4_rtz(double4 data, size_t offset, __global half *p);
void __overload vstore_half8_rtz(double8 data, size_t offset, __global half *p);
void __overload vstore_half16_rtz(double16 data, size_t offset, __global half *p);
void __overload vstore_half2_rtp(double2 data, size_t offset, __global half *p);
void __overload vstore_half3_rtp(double3 data, size_t offset, __global half *p);
void __overload vstore_half4_rtp(double4 data, size_t offset, __global half *p);
void __overload vstore_half8_rtp(double8 data, size_t offset, __global half *p);
void __overload vstore_half16_rtp(double16 data, size_t offset, __global half *p);
void __overload vstore_half2_rtn(double2 data, size_t offset, __global half *p);
void __overload vstore_half3_rtn(double3 data, size_t offset, __global half *p);
void __overload vstore_half4_rtn(double4 data, size_t offset, __global half *p);
void __overload vstore_half8_rtn(double8 data, size_t offset, __global half *p);
void __overload vstore_half16_rtn(double16 data, size_t offset, __global half *p);
void __overload vstore_half2(double2 data, size_t offset, __local half *p);
void __overload vstore_half3(double3 data, size_t offset, __local half *p);
void __overload vstore_half4(double4 data, size_t offset, __local half *p);
void __overload vstore_half8(double8 data, size_t offset, __local half *p);
void __overload vstore_half16(double16 data, size_t offset, __local half *p);
void __overload vstore_half2_rte(double2 data, size_t offset, __local half *p);
void __overload vstore_half3_rte(double3 data, size_t offset, __local half *p);
void __overload vstore_half4_rte(double4 data, size_t offset, __local half *p);
void __overload vstore_half8_rte(double8 data, size_t offset, __local half *p);
void __overload vstore_half16_rte(double16 data, size_t offset, __local half *p);
void __overload vstore_half2_rtz(double2 data, size_t offset, __local half *p);
void __overload vstore_half3_rtz(double3 data, size_t offset, __local half *p);
void __overload vstore_half4_rtz(double4 data, size_t offset, __local half *p);
void __overload vstore_half8_rtz(double8 data, size_t offset, __local half *p);
void __overload vstore_half16_rtz(double16 data, size_t offset, __local half *p);
void __overload vstore_half2_rtp(double2 data, size_t offset, __local half *p);
void __overload vstore_half3_rtp(double3 data, size_t offset, __local half *p);
void __overload vstore_half4_rtp(double4 data, size_t offset, __local half *p);
void __overload vstore_half8_rtp(double8 data, size_t offset, __local half *p);
void __overload vstore_half16_rtp(double16 data, size_t offset, __local half *p);
void __overload vstore_half2_rtn(double2 data, size_t offset, __local half *p);
void __overload vstore_half3_rtn(double3 data, size_t offset, __local half *p);
void __overload vstore_half4_rtn(double4 data, size_t offset, __local half *p);
void __overload vstore_half8_rtn(double8 data, size_t offset, __local half *p);
void __overload vstore_half16_rtn(double16 data, size_t offset, __local half *p);
void __overload vstore_half2(double2 data, size_t offset, __private half *p);
void __overload vstore_half3(double3 data, size_t offset, __private half *p);
void __overload vstore_half4(double4 data, size_t offset, __private half *p);
void __overload vstore_half8(double8 data, size_t offset, __private half *p);
void __overload vstore_half16(double16 data, size_t offset, __private half *p);
void __overload vstore_half2_rte(double2 data, size_t offset, __private half *p);
void __overload vstore_half3_rte(double3 data, size_t offset, __private half *p);
void __overload vstore_half4_rte(double4 data, size_t offset, __private half *p);
void __overload vstore_half8_rte(double8 data, size_t offset, __private half *p);
void __overload vstore_half16_rte(double16 data, size_t offset, __private half *p);
void __overload vstore_half2_rtz(double2 data, size_t offset, __private half *p);
void __overload vstore_half3_rtz(double3 data, size_t offset, __private half *p);
void __overload vstore_half4_rtz(double4 data, size_t offset, __private half *p);
void __overload vstore_half8_rtz(double8 data, size_t offset, __private half *p);
void __overload vstore_half16_rtz(double16 data, size_t offset, __private half *p);
void __overload vstore_half2_rtp(double2 data, size_t offset, __private half *p);
void __overload vstore_half3_rtp(double3 data, size_t offset, __private half *p);
void __overload vstore_half4_rtp(double4 data, size_t offset, __private half *p);
void __overload vstore_half8_rtp(double8 data, size_t offset, __private half *p);
void __overload vstore_half16_rtp(double16 data, size_t offset, __private half *p);
void __overload vstore_half2_rtn(double2 data, size_t offset, __private half *p);
void __overload vstore_half3_rtn(double3 data, size_t offset, __private half *p);
void __overload vstore_half4_rtn(double4 data, size_t offset, __private half *p);
void __overload vstore_half8_rtn(double8 data, size_t offset, __private half *p);
void __overload vstore_half16_rtn(double16 data, size_t offset, __private half *p);
#endif //cl_khr_fp64
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * For n = 1, 2, 4, 8 and 16 read sizeof (halfn)
 * bytes of data from address (p + (offset * n)).
 * The data read is interpreted as a halfn value.
 * The halfn value read is converted to a floatn
 * value and the floatn value is returned.
 * The address computed as (p + (offset * n))
 * must be aligned to sizeof (halfn) bytes.
 * For n = 3, vloada_half3 reads a half3 from
 * address (p + (offset * 4)) and returns a float3.
 * The address computed as (p + (offset * 4))
 * must be aligned to sizeof (half) * 4 bytes.
 */
float __overload vloada_half(size_t offset, const __constant half *p);
float2 __overload vloada_half2(size_t offset, const __constant half *p);
float3 __overload vloada_half3(size_t offset, const __constant half *p);
float4 __overload vloada_half4(size_t offset, const __constant half *p);
float8 __overload vloada_half8(size_t offset, const __constant half *p);
float16 __overload vloada_half16(size_t offset, const __constant half *p);
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float __overload vloada_half(size_t offset, const half *p);
float2 __overload vloada_half2(size_t offset, const half *p);
float3 __overload vloada_half3(size_t offset, const half *p);
float4 __overload vloada_half4(size_t offset, const half *p);
float8 __overload vloada_half8(size_t offset, const half *p);
float16 __overload vloada_half16(size_t offset, const half *p);
#else
float __overload vloada_half(size_t offset, const __global half *p);
float2 __overload vloada_half2(size_t offset, const __global half *p);
float3 __overload vloada_half3(size_t offset, const __global half *p);
float4 __overload vloada_half4(size_t offset, const __global half *p);
float8 __overload vloada_half8(size_t offset, const __global half *p);
float16 __overload vloada_half16(size_t offset, const __global half *p);
float __overload vloada_half(size_t offset, const __local half *p);
float2 __overload vloada_half2(size_t offset, const __local half *p);
float3 __overload vloada_half3(size_t offset, const __local half *p);
float4 __overload vloada_half4(size_t offset, const __local half *p);
float8 __overload vloada_half8(size_t offset, const __local half *p);
float16 __overload vloada_half16(size_t offset, const __local half *p);
float __overload vloada_half(size_t offset, const __private half *p);
float2 __overload vloada_half2(size_t offset, const __private half *p);
float3 __overload vloada_half3(size_t offset, const __private half *p);
float4 __overload vloada_half4(size_t offset, const __private half *p);
float8 __overload vloada_half8(size_t offset, const __private half *p);
float16 __overload vloada_half16(size_t offset, const __private half *p);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * The floatn value given by data is converted to
 * a halfn value using the appropriate rounding
 * mode.
 * For n = 1, 2, 4, 8 and 16, the halfn value is
 * written to the address computed as (p + (offset
 * * n)). The address computed as (p + (offset *
 * n)) must be aligned to sizeof (halfn) bytes.
 * For n = 3, the half3 value is written to the
 * address computed as (p + (offset * 4)). The
 * address computed as (p + (offset * 4)) must be
 * aligned to sizeof (half) * 4 bytes.
 * vstorea_halfn uses the current rounding
 * mode. The default current rounding mode is
 * round to nearest even.
 */
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
void __overload vstorea_half(float data, size_t offset, half *p);
void __overload vstorea_half2(float2 data, size_t offset, half *p);
void __overload vstorea_half3(float3 data, size_t offset, half *p);
void __overload vstorea_half4(float4 data, size_t offset, half *p);
void __overload vstorea_half8(float8 data, size_t offset, half *p);
void __overload vstorea_half16(float16 data, size_t offset, half *p);

void __overload vstorea_half_rte(float data, size_t offset, half *p);
void __overload vstorea_half2_rte(float2 data, size_t offset, half *p);
void __overload vstorea_half3_rte(float3 data, size_t offset, half *p);
void __overload vstorea_half4_rte(float4 data, size_t offset, half *p);
void __overload vstorea_half8_rte(float8 data, size_t offset, half *p);
void __overload vstorea_half16_rte(float16 data, size_t offset, half *p);

void __overload vstorea_half_rtz(float data, size_t offset, half *p);
void __overload vstorea_half2_rtz(float2 data, size_t offset, half *p);
void __overload vstorea_half3_rtz(float3 data, size_t offset, half *p);
void __overload vstorea_half4_rtz(float4 data, size_t offset, half *p);
void __overload vstorea_half8_rtz(float8 data, size_t offset, half *p);
void __overload vstorea_half16_rtz(float16 data, size_t offset, half *p);

void __overload vstorea_half_rtp(float data, size_t offset, half *p);
void __overload vstorea_half2_rtp(float2 data, size_t offset, half *p);
void __overload vstorea_half3_rtp(float3 data, size_t offset, half *p);
void __overload vstorea_half4_rtp(float4 data, size_t offset, half *p);
void __overload vstorea_half8_rtp(float8 data, size_t offset, half *p);
void __overload vstorea_half16_rtp(float16 data, size_t offset, half *p);

void __overload vstorea_half_rtn(float data, size_t offset, half *p);
void __overload vstorea_half2_rtn(float2 data, size_t offset, half *p);
void __overload vstorea_half3_rtn(float3 data, size_t offset, half *p);
void __overload vstorea_half4_rtn(float4 data, size_t offset, half *p);
void __overload vstorea_half8_rtn(float8 data, size_t offset, half *p);
void __overload vstorea_half16_rtn(float16 data, size_t offset, half *p);

#ifdef cl_khr_fp64
void __overload vstorea_half(double data, size_t offset, half *p);
void __overload vstorea_half2(double2 data, size_t offset, half *p);
void __overload vstorea_half3(double3 data, size_t offset, half *p);
void __overload vstorea_half4(double4 data, size_t offset, half *p);
void __overload vstorea_half8(double8 data, size_t offset, half *p);
void __overload vstorea_half16(double16 data, size_t offset, half *p);

void __overload vstorea_half_rte(double data, size_t offset, half *p);
void __overload vstorea_half2_rte(double2 data, size_t offset, half *p);
void __overload vstorea_half3_rte(double3 data, size_t offset, half *p);
void __overload vstorea_half4_rte(double4 data, size_t offset, half *p);
void __overload vstorea_half8_rte(double8 data, size_t offset, half *p);
void __overload vstorea_half16_rte(double16 data, size_t offset, half *p);

void __overload vstorea_half_rtz(double data, size_t offset, half *p);
void __overload vstorea_half2_rtz(double2 data, size_t offset, half *p);
void __overload vstorea_half3_rtz(double3 data, size_t offset, half *p);
void __overload vstorea_half4_rtz(double4 data, size_t offset, half *p);
void __overload vstorea_half8_rtz(double8 data, size_t offset, half *p);
void __overload vstorea_half16_rtz(double16 data, size_t offset, half *p);

void __overload vstorea_half_rtp(double data, size_t offset, half *p);
void __overload vstorea_half2_rtp(double2 data, size_t offset, half *p);
void __overload vstorea_half3_rtp(double3 data, size_t offset, half *p);
void __overload vstorea_half4_rtp(double4 data, size_t offset, half *p);
void __overload vstorea_half8_rtp(double8 data, size_t offset, half *p);
void __overload vstorea_half16_rtp(double16 data, size_t offset, half *p);

void __overload vstorea_half_rtn(double data, size_t offset, half *p);
void __overload vstorea_half2_rtn(double2 data, size_t offset, half *p);
void __overload vstorea_half3_rtn(double3 data, size_t offset, half *p);
void __overload vstorea_half4_rtn(double4 data, size_t offset, half *p);
void __overload vstorea_half8_rtn(double8 data, size_t offset, half *p);
void __overload vstorea_half16_rtn(double16 data, size_t offset, half *p);
#endif //cl_khr_fp64

#else
void __overload vstorea_half(float data, size_t offset, __global half *p);
void __overload vstorea_half2(float2 data, size_t offset, __global half *p);
void __overload vstorea_half3(float3 data, size_t offset, __global half *p);
void __overload vstorea_half4(float4 data, size_t offset, __global half *p);
void __overload vstorea_half8(float8 data, size_t offset, __global half *p);
void __overload vstorea_half16(float16 data, size_t offset, __global half *p);

void __overload vstorea_half_rte(float data, size_t offset, __global half *p);
void __overload vstorea_half2_rte(float2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rte(float3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rte(float4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rte(float8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rte(float16 data, size_t offset, __global half *p);

void __overload vstorea_half_rtz(float data, size_t offset, __global half *p);
void __overload vstorea_half2_rtz(float2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rtz(float3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rtz(float4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rtz(float8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rtz(float16 data, size_t offset, __global half *p);

void __overload vstorea_half_rtp(float data, size_t offset, __global half *p);
void __overload vstorea_half2_rtp(float2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rtp(float3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rtp(float4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rtp(float8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rtp(float16 data, size_t offset, __global half *p);

void __overload vstorea_half_rtn(float data, size_t offset, __global half *p);
void __overload vstorea_half2_rtn(float2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rtn(float3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rtn(float4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rtn(float8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rtn(float16 data, size_t offset, __global half *p);

void __overload vstorea_half(float data, size_t offset, __local half *p);
void __overload vstorea_half2(float2 data, size_t offset, __local half *p);
void __overload vstorea_half3(float3 data, size_t offset, __local half *p);
void __overload vstorea_half4(float4 data, size_t offset, __local half *p);
void __overload vstorea_half8(float8 data, size_t offset, __local half *p);
void __overload vstorea_half16(float16 data, size_t offset, __local half *p);

void __overload vstorea_half_rte(float data, size_t offset, __local half *p);
void __overload vstorea_half2_rte(float2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rte(float3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rte(float4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rte(float8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rte(float16 data, size_t offset, __local half *p);

void __overload vstorea_half_rtz(float data, size_t offset, __local half *p);
void __overload vstorea_half2_rtz(float2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rtz(float3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rtz(float4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rtz(float8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rtz(float16 data, size_t offset, __local half *p);

void __overload vstorea_half_rtp(float data, size_t offset, __local half *p);
void __overload vstorea_half2_rtp(float2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rtp(float3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rtp(float4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rtp(float8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rtp(float16 data, size_t offset, __local half *p);

void __overload vstorea_half_rtn(float data, size_t offset, __local half *p);
void __overload vstorea_half2_rtn(float2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rtn(float3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rtn(float4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rtn(float8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rtn(float16 data, size_t offset, __local half *p);

void __overload vstorea_half(float data, size_t offset, __private half *p);
void __overload vstorea_half2(float2 data, size_t offset, __private half *p);
void __overload vstorea_half3(float3 data, size_t offset, __private half *p);
void __overload vstorea_half4(float4 data, size_t offset, __private half *p);
void __overload vstorea_half8(float8 data, size_t offset, __private half *p);
void __overload vstorea_half16(float16 data, size_t offset, __private half *p);

void __overload vstorea_half_rte(float data, size_t offset, __private half *p);
void __overload vstorea_half2_rte(float2 data, size_t offset, __private half *p);
void __overload vstorea_half3_rte(float3 data, size_t offset, __private half *p);
void __overload vstorea_half4_rte(float4 data, size_t offset, __private half *p);
void __overload vstorea_half8_rte(float8 data, size_t offset, __private half *p);
void __overload vstorea_half16_rte(float16 data, size_t offset, __private half *p);

void __overload vstorea_half_rtz(float data, size_t offset, __private half *p);
void __overload vstorea_half2_rtz(float2 data, size_t offset, __private half *p);
void __overload vstorea_half3_rtz(float3 data, size_t offset, __private half *p);
void __overload vstorea_half4_rtz(float4 data, size_t offset, __private half *p);
void __overload vstorea_half8_rtz(float8 data, size_t offset, __private half *p);
void __overload vstorea_half16_rtz(float16 data, size_t offset, __private half *p);

void __overload vstorea_half_rtp(float data, size_t offset, __private half *p);
void __overload vstorea_half2_rtp(float2 data, size_t offset, __private half *p);
void __overload vstorea_half3_rtp(float3 data, size_t offset, __private half *p);
void __overload vstorea_half4_rtp(float4 data, size_t offset, __private half *p);
void __overload vstorea_half8_rtp(float8 data, size_t offset, __private half *p);
void __overload vstorea_half16_rtp(float16 data, size_t offset, __private half *p);

void __overload vstorea_half_rtn(float data, size_t offset, __private half *p);
void __overload vstorea_half2_rtn(float2 data, size_t offset, __private half *p);
void __overload vstorea_half3_rtn(float3 data, size_t offset, __private half *p);
void __overload vstorea_half4_rtn(float4 data, size_t offset, __private half *p);
void __overload vstorea_half8_rtn(float8 data, size_t offset, __private half *p);
void __overload vstorea_half16_rtn(float16 data, size_t offset, __private half *p);

#ifdef cl_khr_fp64
void __overload vstorea_half(double data, size_t offset, __global half *p);
void __overload vstorea_half2(double2 data, size_t offset, __global half *p);
void __overload vstorea_half3(double3 data, size_t offset, __global half *p);
void __overload vstorea_half4(double4 data, size_t offset, __global half *p);
void __overload vstorea_half8(double8 data, size_t offset, __global half *p);
void __overload vstorea_half16(double16 data, size_t offset, __global half *p);

void __overload vstorea_half_rte(double data, size_t offset, __global half *p);
void __overload vstorea_half2_rte(double2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rte(double3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rte(double4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rte(double8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rte(double16 data, size_t offset, __global half *p);

void __overload vstorea_half_rtz(double data, size_t offset, __global half *p);
void __overload vstorea_half2_rtz(double2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rtz(double3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rtz(double4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rtz(double8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rtz(double16 data, size_t offset, __global half *p);

void __overload vstorea_half_rtp(double data, size_t offset, __global half *p);
void __overload vstorea_half2_rtp(double2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rtp(double3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rtp(double4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rtp(double8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rtp(double16 data, size_t offset, __global half *p);

void __overload vstorea_half_rtn(double data, size_t offset, __global half *p);
void __overload vstorea_half2_rtn(double2 data, size_t offset, __global half *p);
void __overload vstorea_half3_rtn(double3 data, size_t offset, __global half *p);
void __overload vstorea_half4_rtn(double4 data, size_t offset, __global half *p);
void __overload vstorea_half8_rtn(double8 data, size_t offset, __global half *p);
void __overload vstorea_half16_rtn(double16 data, size_t offset, __global half *p);

void __overload vstorea_half(double data, size_t offset, __local half *p);
void __overload vstorea_half2(double2 data, size_t offset, __local half *p);
void __overload vstorea_half3(double3 data, size_t offset, __local half *p);
void __overload vstorea_half4(double4 data, size_t offset, __local half *p);
void __overload vstorea_half8(double8 data, size_t offset, __local half *p);
void __overload vstorea_half16(double16 data, size_t offset, __local half *p);

void __overload vstorea_half_rte(double data, size_t offset, __local half *p);
void __overload vstorea_half2_rte(double2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rte(double3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rte(double4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rte(double8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rte(double16 data, size_t offset, __local half *p);

void __overload vstorea_half_rtz(double data, size_t offset, __local half *p);
void __overload vstorea_half2_rtz(double2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rtz(double3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rtz(double4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rtz(double8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rtz(double16 data, size_t offset, __local half *p);

void __overload vstorea_half_rtp(double data, size_t offset, __local half *p);
void __overload vstorea_half2_rtp(double2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rtp(double3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rtp(double4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rtp(double8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rtp(double16 data, size_t offset, __local half *p);

void __overload vstorea_half_rtn(double data, size_t offset, __local half *p);
void __overload vstorea_half2_rtn(double2 data, size_t offset, __local half *p);
void __overload vstorea_half3_rtn(double3 data, size_t offset, __local half *p);
void __overload vstorea_half4_rtn(double4 data, size_t offset, __local half *p);
void __overload vstorea_half8_rtn(double8 data, size_t offset, __local half *p);
void __overload vstorea_half16_rtn(double16 data, size_t offset, __local half *p);

void __overload vstorea_half(double data, size_t offset, __private half *p);
void __overload vstorea_half2(double2 data, size_t offset, __private half *p);
void __overload vstorea_half3(double3 data, size_t offset, __private half *p);
void __overload vstorea_half4(double4 data, size_t offset, __private half *p);
void __overload vstorea_half8(double8 data, size_t offset, __private half *p);
void __overload vstorea_half16(double16 data, size_t offset, __private half *p);

void __overload vstorea_half_rte(double data, size_t offset, __private half *p);
void __overload vstorea_half2_rte(double2 data, size_t offset, __private half *p);
void __overload vstorea_half3_rte(double3 data, size_t offset, __private half *p);
void __overload vstorea_half4_rte(double4 data, size_t offset, __private half *p);
void __overload vstorea_half8_rte(double8 data, size_t offset, __private half *p);
void __overload vstorea_half16_rte(double16 data, size_t offset, __private half *p);

void __overload vstorea_half_rtz(double data, size_t offset, __private half *p);
void __overload vstorea_half2_rtz(double2 data, size_t offset, __private half *p);
void __overload vstorea_half3_rtz(double3 data, size_t offset, __private half *p);
void __overload vstorea_half4_rtz(double4 data, size_t offset, __private half *p);
void __overload vstorea_half8_rtz(double8 data, size_t offset, __private half *p);
void __overload vstorea_half16_rtz(double16 data, size_t offset, __private half *p);

void __overload vstorea_half_rtp(double data, size_t offset, __private half *p);
void __overload vstorea_half2_rtp(double2 data, size_t offset, __private half *p);
void __overload vstorea_half3_rtp(double3 data, size_t offset, __private half *p);
void __overload vstorea_half4_rtp(double4 data, size_t offset, __private half *p);
void __overload vstorea_half8_rtp(double8 data, size_t offset, __private half *p);
void __overload vstorea_half16_rtp(double16 data, size_t offset, __private half *p);

void __overload vstorea_half_rtn(double data, size_t offset, __private half *p);
void __overload vstorea_half2_rtn(double2 data,size_t offset, __private half *p);
void __overload vstorea_half3_rtn(double3 data,size_t offset, __private half *p);
void __overload vstorea_half4_rtn(double4 data,size_t offset, __private half *p);
void __overload vstorea_half8_rtn(double8 data,size_t offset, __private half *p);
void __overload vstorea_half16_rtn(double16 data,size_t offset, __private half *p);
#endif //cl_khr_fp64
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL v1.1 s6.11.8, v1.2 s6.12.8, v2.0 s6.13.8 - Synchronization Functions

// Flag type and values for barrier, mem_fence, read_mem_fence, write_mem_fence
typedef uint cl_mem_fence_flags;

/**
 * Queue a memory fence to ensure correct
 * ordering of memory operations to local memory
 */
#define CLK_LOCAL_MEM_FENCE    0x01

/**
 * Queue a memory fence to ensure correct
 * ordering of memory operations to global memory
 */
#define CLK_GLOBAL_MEM_FENCE   0x02

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
/**
 * Queue a memory fence to ensure correct ordering of memory
 * operations between work-items of a work-group to
 * image memory.
 */
#define CLK_IMAGE_MEM_FENCE  0x04
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * All work-items in a work-group executing the kernel
 * on a processor must execute this function before any
 * are allowed to continue execution beyond the barrier.
 * This function must be encountered by all work-items in
 * a work-group executing the kernel.
 * If barrier is inside a conditional statement, then all
 * work-items must enter the conditional if any work-item
 * enters the conditional statement and executes the
 * barrier.
 * If barrer is inside a loop, all work-items must execute
 * the barrier for each iteration of the loop before any are
 * allowed to continue execution beyond the barrier.
 * The barrier function also queues a memory fence
 * (reads and writes) to ensure correct ordering of
 * memory operations to local or global memory.
 * The flags argument specifies the memory address space
 * and can be set to a combination of the following literal
 * values.
 * CLK_LOCAL_MEM_FENCE - The barrier function
 * will either flush any variables stored in local memory
 * or queue a memory fence to ensure correct ordering of
 * memory operations to local memory.
 * CLK_GLOBAL_MEM_FENCE - The barrier function
 * will queue a memory fence to ensure correct ordering
 * of memory operations to global memory. This can be
 * useful when work-items, for example, write to buffer or
 * image objects and then want to read the updated data.
 */

void __overload barrier(cl_mem_fence_flags flags);

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0

typedef enum memory_scope
{
  memory_scope_work_item,
  memory_scope_work_group,
  memory_scope_device,
  memory_scope_all_svm_devices,
  memory_scope_sub_group
} memory_scope;

void __overload work_group_barrier(cl_mem_fence_flags flags, memory_scope scope);
void __overload work_group_barrier(cl_mem_fence_flags flags);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL v1.1 s6.11.9, v1.2 s6.12.9 - Explicit Memory Fence Functions

/**
 * Orders loads and stores of a work-item
 * executing a kernel. This means that loads
 * and stores preceding the mem_fence will
 * be committed to memory before any loads
 * and stores following the mem_fence.
 * The flags argument specifies the memory
 * address space and can be set to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE.
 */
void __overload mem_fence(cl_mem_fence_flags flags);

/**
 * Read memory barrier that orders only
 * loads.
 * The flags argument specifies the memory
 * address space and can be set to to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE.
 */
void __overload read_mem_fence(cl_mem_fence_flags flags);

/**
 * Write memory barrier that orders only
 * stores.
 * The flags argument specifies the memory
 * address space and can be set to to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE.
 */
void __overload write_mem_fence(cl_mem_fence_flags flags);

// OpenCL v2.0 s6.13.9 - Address Space Qualifier Functions

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
cl_mem_fence_flags __overload get_fence(const void *ptr);
cl_mem_fence_flags __overload get_fence(void *ptr);

// Builtin functions to_global, to_local, and to_private need to be declared as Clang builtin functions
// and checked in Sema since they should be declared as
//   addr gentype* to_addr (gentype*);
// where gentype is builtin type or user defined type.

#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL v1.1 s6.11.10, v1.2 s6.12.10, v2.0 s6.13.10 - Async Copies from Global to Local Memory, Local to Global Memory, and Prefetch

/**
 * event_t async_work_group_copy (
 * __global gentype *dst,
 * const __local gentype *src,
 * size_t num_elements,
 * event_t event)
 * Perform an async copy of num_elements
 * gentype elements from src to dst. The async
 * copy is performed by all work-items in a workgroup
 * and this built-in function must therefore
 * be encountered by all work-items in a workgroup
 * executing the kernel with the same
 * argument values; otherwise the results are
 * undefined.
 * Returns an event object that can be used by
 * wait_group_events to wait for the async copy
 * to finish. The event argument can also be used
 * to associate the async_work_group_copy with
 * a previous async copy allowing an event to be
 * shared by multiple async copies; otherwise event
 * should be zero.
 * If event argument is non-zero, the event object
 * supplied in event argument will be returned.
 * This function does not perform any implicit
 * synchronization of source data such as using a
 * barrier before performing the copy.
 */
event_t __overload async_work_group_copy(__local char *dst, const __global char *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uchar *dst, const __global uchar *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local short *dst, const __global short *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ushort *dst, const __global ushort *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local int *dst, const __global int *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uint *dst, const __global uint *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local long *dst, const __global long *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ulong *dst, const __global ulong *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local float *dst, const __global float *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local char2 *dst, const __global char2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uchar2 *dst, const __global uchar2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local short2 *dst, const __global short2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ushort2 *dst, const __global ushort2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local int2 *dst, const __global int2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uint2 *dst, const __global uint2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local long2 *dst, const __global long2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ulong2 *dst, const __global ulong2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local float2 *dst, const __global float2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local char3 *dst, const __global char3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uchar3 *dst, const __global uchar3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local short3 *dst, const __global short3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ushort3 *dst, const __global ushort3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local int3 *dst, const __global int3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uint3 *dst, const __global uint3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local long3 *dst, const __global long3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ulong3 *dst, const __global ulong3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local float3 *dst, const __global float3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local char4 *dst, const __global char4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uchar4 *dst, const __global uchar4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local short4 *dst, const __global short4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ushort4 *dst, const __global ushort4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local int4 *dst, const __global int4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uint4 *dst, const __global uint4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local long4 *dst, const __global long4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ulong4 *dst, const __global ulong4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local float4 *dst, const __global float4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local char8 *dst, const __global char8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uchar8 *dst, const __global uchar8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local short8 *dst, const __global short8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ushort8 *dst, const __global ushort8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local int8 *dst, const __global int8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uint8 *dst, const __global uint8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local long8 *dst, const __global long8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ulong8 *dst, const __global ulong8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local float8 *dst, const __global float8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local char16 *dst, const __global char16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uchar16 *dst, const __global uchar16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local short16 *dst, const __global short16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ushort16 *dst, const __global ushort16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local int16 *dst, const __global int16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local uint16 *dst, const __global uint16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local long16 *dst, const __global long16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local ulong16 *dst, const __global ulong16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local float16 *dst, const __global float16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global char *dst, const __local char *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uchar *dst, const __local uchar *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global short *dst, const __local short *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ushort *dst, const __local ushort *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global int *dst, const __local int *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uint *dst, const __local uint *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global long *dst, const __local long *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ulong *dst, const __local ulong *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global float *dst, const __local float *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global char2 *dst, const __local char2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uchar2 *dst, const __local uchar2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global short2 *dst, const __local short2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ushort2 *dst, const __local ushort2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global int2 *dst, const __local int2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uint2 *dst, const __local uint2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global long2 *dst, const __local long2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ulong2 *dst, const __local ulong2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global float2 *dst, const __local float2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global char3 *dst, const __local char3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uchar3 *dst, const __local uchar3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global short3 *dst, const __local short3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ushort3 *dst, const __local ushort3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global int3 *dst, const __local int3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uint3 *dst, const __local uint3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global long3 *dst, const __local long3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ulong3 *dst, const __local ulong3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global float3 *dst, const __local float3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global char4 *dst, const __local char4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uchar4 *dst, const __local uchar4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global short4 *dst, const __local short4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ushort4 *dst, const __local ushort4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global int4 *dst, const __local int4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uint4 *dst, const __local uint4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global long4 *dst, const __local long4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ulong4 *dst, const __local ulong4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global float4 *dst, const __local float4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global char8 *dst, const __local char8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uchar8 *dst, const __local uchar8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global short8 *dst, const __local short8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ushort8 *dst, const __local ushort8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global int8 *dst, const __local int8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uint8 *dst, const __local uint8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global long8 *dst, const __local long8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ulong8 *dst, const __local ulong8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global float8 *dst, const __local float8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global char16 *dst, const __local char16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uchar16 *dst, const __local uchar16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global short16 *dst, const __local short16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ushort16 *dst, const __local ushort16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global int16 *dst, const __local int16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global uint16 *dst, const __local uint16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global long16 *dst, const __local long16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global ulong16 *dst, const __local ulong16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global float16 *dst, const __local float16 *src, size_t num_elements, event_t event);
#ifdef cl_khr_fp64
event_t __overload async_work_group_copy(__local double *dst, const __global double *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local double2 *dst, const __global double2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local double3 *dst, const __global double3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local double4 *dst, const __global double4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local double8 *dst, const __global double8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local double16 *dst, const __global double16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global double *dst, const __local double *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global double2 *dst, const __local double2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global double3 *dst, const __local double3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global double4 *dst, const __local double4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global double8 *dst, const __local double8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global double16 *dst, const __local double16 *src, size_t num_elements, event_t event);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
event_t __overload async_work_group_copy(__local half *dst, const __global half *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local half2 *dst, const __global half2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local half3 *dst, const __global half3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local half4 *dst, const __global half4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local half8 *dst, const __global half8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__local half16 *dst, const __global half16 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global half *dst, const __local half *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global half2 *dst, const __local half2 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global half3 *dst, const __local half3 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global half4 *dst, const __local half4 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global half8 *dst, const __local half8 *src, size_t num_elements, event_t event);
event_t __overload async_work_group_copy(__global half16 *dst, const __local half16 *src, size_t num_elements, event_t event);
#endif //cl_khr_fp16

/**
 * Perform an async gather of num_elements
 * gentype elements from src to dst. The
 * src_stride is the stride in elements for each
 * gentype element read from src. The dst_stride
 * is the stride in elements for each gentype
 * element written to dst. The async gather is
 * performed by all work-items in a work-group.
 * This built-in function must therefore be
 * encountered by all work-items in a work-group
 * executing the kernel with the same argument
 * values; otherwise the results are undefined.
 * Returns an event object that can be used by
 * wait_group_events to wait for the async copy
 * to finish. The event argument can also be used
 * to associate the
 * async_work_group_strided_copy with a
 * previous async copy allowing an event to be
 * shared by multiple async copies; otherwise event
 * should be zero.
 * If event argument is non-zero, the event object
 * supplied in event argument will be returned.
 * This function does not perform any implicit
 * synchronization of source data such as using a
 * barrier before performing the copy.
 */
event_t __overload async_work_group_strided_copy(__local char *dst, const __global char *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uchar *dst, const __global uchar *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local short *dst, const __global short *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ushort *dst, const __global ushort *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local int *dst, const __global int *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uint *dst, const __global uint *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local long *dst, const __global long *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ulong *dst, const __global ulong *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local float *dst, const __global float *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local char2 *dst, const __global char2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uchar2 *dst, const __global uchar2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local short2 *dst, const __global short2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ushort2 *dst, const __global ushort2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local int2 *dst, const __global int2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uint2 *dst, const __global uint2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local long2 *dst, const __global long2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ulong2 *dst, const __global ulong2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local float2 *dst, const __global float2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local char3 *dst, const __global char3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uchar3 *dst, const __global uchar3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local short3 *dst, const __global short3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ushort3 *dst, const __global ushort3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local int3 *dst, const __global int3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uint3 *dst, const __global uint3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local long3 *dst, const __global long3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ulong3 *dst, const __global ulong3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local float3 *dst, const __global float3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local char4 *dst, const __global char4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uchar4 *dst, const __global uchar4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local short4 *dst, const __global short4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ushort4 *dst, const __global ushort4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local int4 *dst, const __global int4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uint4 *dst, const __global uint4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local long4 *dst, const __global long4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ulong4 *dst, const __global ulong4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local float4 *dst, const __global float4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local char8 *dst, const __global char8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uchar8 *dst, const __global uchar8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local short8 *dst, const __global short8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ushort8 *dst, const __global ushort8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local int8 *dst, const __global int8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uint8 *dst, const __global uint8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local long8 *dst, const __global long8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ulong8 *dst, const __global ulong8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local float8 *dst, const __global float8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local char16 *dst, const __global char16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uchar16 *dst, const __global uchar16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local short16 *dst, const __global short16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ushort16 *dst, const __global ushort16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local int16 *dst, const __global int16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local uint16 *dst, const __global uint16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local long16 *dst, const __global long16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local ulong16 *dst, const __global ulong16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local float16 *dst, const __global float16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global char *dst, const __local char *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uchar *dst, const __local uchar *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global short *dst, const __local short *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ushort *dst, const __local ushort *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global int *dst, const __local int *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uint *dst, const __local uint *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global long *dst, const __local long *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ulong *dst, const __local ulong *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global float *dst, const __local float *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global char2 *dst, const __local char2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uchar2 *dst, const __local uchar2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global short2 *dst, const __local short2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ushort2 *dst, const __local ushort2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global int2 *dst, const __local int2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uint2 *dst, const __local uint2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global long2 *dst, const __local long2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ulong2 *dst, const __local ulong2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global float2 *dst, const __local float2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global char3 *dst, const __local char3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uchar3 *dst, const __local uchar3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global short3 *dst, const __local short3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ushort3 *dst, const __local ushort3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global int3 *dst, const __local int3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uint3 *dst, const __local uint3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global long3 *dst, const __local long3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ulong3 *dst, const __local ulong3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global float3 *dst, const __local float3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global char4 *dst, const __local char4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uchar4 *dst, const __local uchar4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global short4 *dst, const __local short4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ushort4 *dst, const __local ushort4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global int4 *dst, const __local int4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uint4 *dst, const __local uint4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global long4 *dst, const __local long4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ulong4 *dst, const __local ulong4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global float4 *dst, const __local float4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global char8 *dst, const __local char8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uchar8 *dst, const __local uchar8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global short8 *dst, const __local short8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ushort8 *dst, const __local ushort8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global int8 *dst, const __local int8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uint8 *dst, const __local uint8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global long8 *dst, const __local long8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ulong8 *dst, const __local ulong8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global float8 *dst, const __local float8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global char16 *dst, const __local char16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uchar16 *dst, const __local uchar16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global short16 *dst, const __local short16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ushort16 *dst, const __local ushort16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global int16 *dst, const __local int16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global uint16 *dst, const __local uint16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global long16 *dst, const __local long16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global ulong16 *dst, const __local ulong16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global float16 *dst, const __local float16 *src, size_t num_elements, size_t dst_stride, event_t event);
#ifdef cl_khr_fp64
event_t __overload async_work_group_strided_copy(__local double *dst, const __global double *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local double2 *dst, const __global double2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local double3 *dst, const __global double3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local double4 *dst, const __global double4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local double8 *dst, const __global double8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local double16 *dst, const __global double16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global double *dst, const __local double *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global double2 *dst, const __local double2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global double3 *dst, const __local double3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global double4 *dst, const __local double4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global double8 *dst, const __local double8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global double16 *dst, const __local double16 *src, size_t num_elements, size_t dst_stride, event_t event);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
event_t __overload async_work_group_strided_copy(__local half *dst, const __global half *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local half2 *dst, const __global half2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local half3 *dst, const __global half3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local half4 *dst, const __global half4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local half8 *dst, const __global half8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__local half16 *dst, const __global half16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global half *dst, const __local half *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global half2 *dst, const __local half2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global half3 *dst, const __local half3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global half4 *dst, const __local half4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global half8 *dst, const __local half8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __overload async_work_group_strided_copy(__global half16 *dst, const __local half16 *src, size_t num_elements, size_t dst_stride, event_t event);
#endif //cl_khr_fp16

/**
 * Wait for events that identify the
 * async_work_group_copy operations to
 * complete. The event objects specified in
 * event_list will be released after the wait is
 * performed.
 * This function must be encountered by all workitems
 * in a work-group executing the kernel with
 * the same num_events and event objects specified
 * in event_list; otherwise the results are undefined.
 */
void __overload wait_group_events(int num_events, event_t *event_list);

/**
 * Prefetch num_elements * sizeof(gentype)
 * bytes into the global cache. The prefetch
 * instruction is applied to a work-item in a workgroup
 * and does not affect the functional
 * behavior of the kernel.
 */
void __overload prefetch(const __global char *p, size_t num_elements);
void __overload prefetch(const __global uchar *p, size_t num_elements);
void __overload prefetch(const __global short *p, size_t num_elements);
void __overload prefetch(const __global ushort *p, size_t num_elements);
void __overload prefetch(const __global int *p, size_t num_elements);
void __overload prefetch(const __global uint *p, size_t num_elements);
void __overload prefetch(const __global long *p, size_t num_elements);
void __overload prefetch(const __global ulong *p, size_t num_elements);
void __overload prefetch(const __global float *p, size_t num_elements);
void __overload prefetch(const __global char2 *p, size_t num_elements);
void __overload prefetch(const __global uchar2 *p, size_t num_elements);
void __overload prefetch(const __global short2 *p, size_t num_elements);
void __overload prefetch(const __global ushort2 *p, size_t num_elements);
void __overload prefetch(const __global int2 *p, size_t num_elements);
void __overload prefetch(const __global uint2 *p, size_t num_elements);
void __overload prefetch(const __global long2 *p, size_t num_elements);
void __overload prefetch(const __global ulong2 *p, size_t num_elements);
void __overload prefetch(const __global float2 *p, size_t num_elements);
void __overload prefetch(const __global char3 *p, size_t num_elements);
void __overload prefetch(const __global uchar3 *p, size_t num_elements);
void __overload prefetch(const __global short3 *p, size_t num_elements);
void __overload prefetch(const __global ushort3 *p, size_t num_elements);
void __overload prefetch(const __global int3 *p, size_t num_elements);
void __overload prefetch(const __global uint3 *p, size_t num_elements);
void __overload prefetch(const __global long3 *p, size_t num_elements);
void __overload prefetch(const __global ulong3 *p, size_t num_elements);
void __overload prefetch(const __global float3 *p, size_t num_elements);
void __overload prefetch(const __global char4 *p, size_t num_elements);
void __overload prefetch(const __global uchar4 *p, size_t num_elements);
void __overload prefetch(const __global short4 *p, size_t num_elements);
void __overload prefetch(const __global ushort4 *p, size_t num_elements);
void __overload prefetch(const __global int4 *p, size_t num_elements);
void __overload prefetch(const __global uint4 *p, size_t num_elements);
void __overload prefetch(const __global long4 *p, size_t num_elements);
void __overload prefetch(const __global ulong4 *p, size_t num_elements);
void __overload prefetch(const __global float4 *p, size_t num_elements);
void __overload prefetch(const __global char8 *p, size_t num_elements);
void __overload prefetch(const __global uchar8 *p, size_t num_elements);
void __overload prefetch(const __global short8 *p, size_t num_elements);
void __overload prefetch(const __global ushort8 *p, size_t num_elements);
void __overload prefetch(const __global int8 *p, size_t num_elements);
void __overload prefetch(const __global uint8 *p, size_t num_elements);
void __overload prefetch(const __global long8 *p, size_t num_elements);
void __overload prefetch(const __global ulong8 *p, size_t num_elements);
void __overload prefetch(const __global float8 *p, size_t num_elements);
void __overload prefetch(const __global char16 *p, size_t num_elements);
void __overload prefetch(const __global uchar16 *p, size_t num_elements);
void __overload prefetch(const __global short16 *p, size_t num_elements);
void __overload prefetch(const __global ushort16 *p, size_t num_elements);
void __overload prefetch(const __global int16 *p, size_t num_elements);
void __overload prefetch(const __global uint16 *p, size_t num_elements);
void __overload prefetch(const __global long16 *p, size_t num_elements);
void __overload prefetch(const __global ulong16 *p, size_t num_elements);
void __overload prefetch(const __global float16 *p, size_t num_elements);
#ifdef cl_khr_fp64
void __overload prefetch(const __global double *p, size_t num_elements);
void __overload prefetch(const __global double2 *p, size_t num_elements);
void __overload prefetch(const __global double3 *p, size_t num_elements);
void __overload prefetch(const __global double4 *p, size_t num_elements);
void __overload prefetch(const __global double8 *p, size_t num_elements);
void __overload prefetch(const __global double16 *p, size_t num_elements);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
void __overload prefetch(const __global half *p, size_t num_elements);
void __overload prefetch(const __global half2 *p, size_t num_elements);
void __overload prefetch(const __global half3 *p, size_t num_elements);
void __overload prefetch(const __global half4 *p, size_t num_elements);
void __overload prefetch(const __global half8 *p, size_t num_elements);
void __overload prefetch(const __global half16 *p, size_t num_elements);
#endif // cl_khr_fp16

// OpenCL v1.1 s6.11.1, v1.2 s6.12.11 - Atomic Functions

#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#pragma OPENCL EXTENSION cl_khr_int64_base_atomics : enable
#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : enable
#endif
/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old + val) and store result at location
 * pointed by p. The function returns old.
 */
int __overload atomic_add(volatile __global int *p, int val);
unsigned int __overload atomic_add(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_add(volatile __local int *p, int val);
unsigned int __overload atomic_add(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_global_int32_base_atomics)
int __overload atom_add(volatile __global int *p, int val);
unsigned int __overload atom_add(volatile __global unsigned int *p, unsigned int val);
#endif
#if defined(cl_khr_local_int32_base_atomics)
int __overload atom_add(volatile __local int *p, int val);
unsigned int __overload atom_add(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __overload atom_add(volatile __global long *p, long val);
unsigned long __overload atom_add(volatile __global unsigned long *p, unsigned long val);
long __overload atom_add(volatile __local long *p, long val);
unsigned long __overload atom_add(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old) stored at location pointed by p.
 * Compute (old - val) and store result at location pointed by p. The function
 * returns old.
 */
int __overload atomic_sub(volatile __global int *p, int val);
unsigned int __overload atomic_sub(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_sub(volatile __local int *p, int val);
unsigned int __overload atomic_sub(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_global_int32_base_atomics)
int __overload atom_sub(volatile __global int *p, int val);
unsigned int __overload atom_sub(volatile __global unsigned int *p, unsigned int val);
#endif
#if defined(cl_khr_local_int32_base_atomics)
int __overload atom_sub(volatile __local int *p, int val);
unsigned int __overload atom_sub(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __overload atom_sub(volatile __global long *p, long val);
unsigned long __overload atom_sub(volatile __global unsigned long *p, unsigned long val);
long __overload atom_sub(volatile __local long *p, long val);
unsigned long __overload atom_sub(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Swaps the old value stored at location p
 * with new value given by val. Returns old
 * value.
 */
int __overload atomic_xchg(volatile __global int *p, int val);
unsigned int __overload atomic_xchg(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_xchg(volatile __local int *p, int val);
unsigned int __overload atomic_xchg(volatile __local unsigned int *p, unsigned int val);
float __overload atomic_xchg(volatile __global float *p, float val);
float __overload atomic_xchg(volatile __local float *p, float val);

#if defined(cl_khr_global_int32_base_atomics)
int __overload atom_xchg(volatile __global int *p, int val);
int __overload atom_xchg(volatile __local int *p, int val);
#endif
#if defined(cl_khr_local_int32_base_atomics)
unsigned int __overload atom_xchg(volatile __global unsigned int *p, unsigned int val);
unsigned int __overload atom_xchg(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __overload atom_xchg(volatile __global long *p, long val);
long __overload atom_xchg(volatile __local long *p, long val);
unsigned long __overload atom_xchg(volatile __global unsigned long *p, unsigned long val);
unsigned long __overload atom_xchg(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old + 1) and store result at location
 * pointed by p. The function returns old.
 */
int __overload atomic_inc(volatile __global int *p);
unsigned int __overload atomic_inc(volatile __global unsigned int *p);
int __overload atomic_inc(volatile __local int *p);
unsigned int __overload atomic_inc(volatile __local unsigned int *p);

#if defined(cl_khr_global_int32_base_atomics)
int __overload atom_inc(volatile __global int *p);
unsigned int __overload atom_inc(volatile __global unsigned int *p);
#endif
#if defined(cl_khr_local_int32_base_atomics)
int __overload atom_inc(volatile __local int *p);
unsigned int __overload atom_inc(volatile __local unsigned int *p);
#endif

#if defined(cl_khr_int64_base_atomics)
long __overload atom_inc(volatile __global long *p);
unsigned long __overload atom_inc(volatile __global unsigned long *p);
long __overload atom_inc(volatile __local long *p);
unsigned long __overload atom_inc(volatile __local unsigned long *p);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old - 1) and store result at location
 * pointed by p. The function returns old.
 */
int __overload atomic_dec(volatile __global int *p);
unsigned int __overload atomic_dec(volatile __global unsigned int *p);
int __overload atomic_dec(volatile __local int *p);
unsigned int __overload atomic_dec(volatile __local unsigned int *p);

#if defined(cl_khr_global_int32_base_atomics)
int __overload atom_dec(volatile __global int *p);
unsigned int __overload atom_dec(volatile __global unsigned int *p);
#endif
#if defined(cl_khr_local_int32_base_atomics)
int __overload atom_dec(volatile __local int *p);
unsigned int __overload atom_dec(volatile __local unsigned int *p);
#endif

#if defined(cl_khr_int64_base_atomics)
long __overload atom_dec(volatile __global long *p);
unsigned long __overload atom_dec(volatile __global unsigned long *p);
long __overload atom_dec(volatile __local long *p);
unsigned long __overload atom_dec(volatile __local unsigned long *p);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old == cmp) ? val : old and store result at
 * location pointed by p. The function
 * returns old.
 */
int __overload atomic_cmpxchg(volatile __global int *p, int cmp, int val);
unsigned int __overload atomic_cmpxchg(volatile __global unsigned int *p, unsigned int cmp, unsigned int val);
int __overload atomic_cmpxchg(volatile __local int *p, int cmp, int val);
unsigned int __overload atomic_cmpxchg(volatile __local unsigned int *p, unsigned int cmp, unsigned int val);

#if defined(cl_khr_global_int32_base_atomics)
int __overload atom_cmpxchg(volatile __global int *p, int cmp, int val);
unsigned int __overload atom_cmpxchg(volatile __global unsigned int *p, unsigned int cmp, unsigned int val);
#endif
#if defined(cl_khr_local_int32_base_atomics)
int __overload atom_cmpxchg(volatile __local int *p, int cmp, int val);
unsigned int __overload atom_cmpxchg(volatile __local unsigned int *p, unsigned int cmp, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __overload atom_cmpxchg(volatile __global long *p, long cmp, long val);
unsigned long __overload atom_cmpxchg(volatile __global unsigned long *p, unsigned long cmp, unsigned long val);
long __overload atom_cmpxchg(volatile __local long *p, long cmp, long val);
unsigned long __overload atom_cmpxchg(volatile __local unsigned long *p, unsigned long cmp, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * min(old, val) and store minimum value at
 * location pointed by p. The function
 * returns old.
 */
int __overload atomic_min(volatile __global int *p, int val);
unsigned int __overload atomic_min(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_min(volatile __local int *p, int val);
unsigned int __overload atomic_min(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_global_int32_extended_atomics)
int __overload atom_min(volatile __global int *p, int val);
unsigned int __overload atom_min(volatile __global unsigned int *p, unsigned int val);
#endif
#if defined(cl_khr_local_int32_extended_atomics)
int __overload atom_min(volatile __local int *p, int val);
unsigned int __overload atom_min(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __overload atom_min(volatile __global long *p, long val);
unsigned long __overload atom_min(volatile __global unsigned long *p, unsigned long val);
#endif
#if defined(cl_khr_local_int32_extended_atomics)
long __overload atom_min(volatile __local long *p, long val);
unsigned long __overload atom_min(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * max(old, val) and store maximum value at
 * location pointed by p. The function
 * returns old.
 */
int __overload atomic_max(volatile __global int *p, int val);
unsigned int __overload atomic_max(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_max(volatile __local int *p, int val);
unsigned int __overload atomic_max(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_global_int32_extended_atomics)
int __overload atom_max(volatile __global int *p, int val);
unsigned int __overload atom_max(volatile __global unsigned int *p, unsigned int val);
#endif
#if defined(cl_khr_local_int32_extended_atomics)
int __overload atom_max(volatile __local int *p, int val);
unsigned int __overload atom_max(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __overload atom_max(volatile __global long *p, long val);
unsigned long __overload atom_max(volatile __global unsigned long *p, unsigned long val);
long __overload atom_max(volatile __local long *p, long val);
unsigned long __overload atom_max(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old & val) and store result at location
 * pointed by p. The function returns old.
 */
int __overload atomic_and(volatile __global int *p, int val);
unsigned int __overload atomic_and(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_and(volatile __local int *p, int val);
unsigned int __overload atomic_and(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_global_int32_extended_atomics)
int __overload atom_and(volatile __global int *p, int val);
unsigned int __overload atom_and(volatile __global unsigned int *p, unsigned int val);
#endif
#if defined(cl_khr_local_int32_extended_atomics)
int __overload atom_and(volatile __local int *p, int val);
unsigned int __overload atom_and(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __overload atom_and(volatile __global long *p, long val);
unsigned long __overload atom_and(volatile __global unsigned long *p, unsigned long val);
long __overload atom_and(volatile __local long *p, long val);
unsigned long __overload atom_and(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old | val) and store result at location
 * pointed by p. The function returns old.
 */
int __overload atomic_or(volatile __global int *p, int val);
unsigned int __overload atomic_or(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_or(volatile __local int *p, int val);
unsigned int __overload atomic_or(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_global_int32_extended_atomics)
int __overload atom_or(volatile __global int *p, int val);
unsigned int __overload atom_or(volatile __global unsigned int *p, unsigned int val);
#endif
#if defined(cl_khr_local_int32_extended_atomics)
int __overload atom_or(volatile __local int *p, int val);
unsigned int __overload atom_or(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __overload atom_or(volatile __global long *p, long val);
unsigned long __overload atom_or(volatile __global unsigned long *p, unsigned long val);
long __overload atom_or(volatile __local long *p, long val);
unsigned long __overload atom_or(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old ^ val) and store result at location
 * pointed by p. The function returns old.
 */
int __overload atomic_xor(volatile __global int *p, int val);
unsigned int __overload atomic_xor(volatile __global unsigned int *p, unsigned int val);
int __overload atomic_xor(volatile __local int *p, int val);
unsigned int __overload atomic_xor(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_global_int32_extended_atomics)
int __overload atom_xor(volatile __global int *p, int val);
unsigned int __overload atom_xor(volatile __global unsigned int *p, unsigned int val);
#endif
#if defined(cl_khr_local_int32_extended_atomics)
int __overload atom_xor(volatile __local int *p, int val);
unsigned int __overload atom_xor(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#pragma OPENCL EXTENSION cl_khr_int64_base_atomics : disable
#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : disable
#endif

// OpenCL v2.0 s6.13.11 - Atomics Functions

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
#ifndef ATOMIC_VAR_INIT
#define ATOMIC_VAR_INIT(x) (x)
#endif //ATOMIC_VAR_INIT
#define ATOMIC_FLAG_INIT 0

// enum values aligned with what clang uses in EmitAtomicExpr()
typedef enum memory_order
{
  memory_order_relaxed,
  memory_order_acquire,
  memory_order_release,
  memory_order_acq_rel,
  memory_order_seq_cst
} memory_order;

// double atomics support requires extensions cl_khr_int64_base_atomics and cl_khr_int64_extended_atomics
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#pragma OPENCL EXTENSION cl_khr_int64_base_atomics : enable
#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : enable
#endif

// atomic_init()
void __overload atomic_init(volatile atomic_int *object, int value);
void __overload atomic_init(volatile atomic_uint *object, uint value);
void __overload atomic_init(volatile atomic_float *object, float value);
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
void __overload atomic_init(volatile atomic_long *object, long value);
void __overload atomic_init(volatile atomic_ulong *object, ulong value);
#ifdef cl_khr_fp64
void __overload atomic_init(volatile atomic_double *object, double value);
#endif //cl_khr_fp64
#endif

// atomic_work_item_fence()
void __overload atomic_work_item_fence(cl_mem_fence_flags flags, memory_order order, memory_scope scope);

// atomic_fetch()

// OpenCL v2.0 s6.13.11.7.5:
// add/sub: atomic type argument can be uintptr_t/intptr_t, value type argument can be ptrdiff_t.
// or/xor/and: atomic type argument can be intptr_t/uintptr_t, value type argument can be intptr_t/uintptr_t.
int __overload atomic_fetch_add(volatile atomic_int *object, int operand);
int __overload atomic_fetch_add_explicit(volatile atomic_int *object, int operand, memory_order order);
int __overload atomic_fetch_add_explicit(volatile atomic_int *object, int operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_add(volatile atomic_uint *object, uint operand);
uint __overload atomic_fetch_add_explicit(volatile atomic_uint *object, uint operand, memory_order order);
uint __overload atomic_fetch_add_explicit(volatile atomic_uint *object, uint operand, memory_order order, memory_scope scope);
uintptr_t __overload atomic_fetch_add(volatile atomic_uintptr_t *object, ptrdiff_t operand);
uintptr_t __overload atomic_fetch_add_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order);
uintptr_t __overload atomic_fetch_add_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order, memory_scope scope);
int __overload atomic_fetch_sub(volatile atomic_int *object, int operand);
int __overload atomic_fetch_sub_explicit(volatile atomic_int *object, int operand, memory_order order);
int __overload atomic_fetch_sub_explicit(volatile atomic_int *object, int operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_sub(volatile atomic_uint *object, uint operand);
uint __overload atomic_fetch_sub_explicit(volatile atomic_uint *object, uint operand, memory_order order);
uint __overload atomic_fetch_sub_explicit(volatile atomic_uint *object, uint operand, memory_order order, memory_scope scope);
uintptr_t __overload atomic_fetch_sub(volatile atomic_uintptr_t *object, ptrdiff_t operand);
uintptr_t __overload atomic_fetch_sub_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order);
uintptr_t __overload atomic_fetch_sub_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order, memory_scope scope);
int __overload atomic_fetch_or(volatile atomic_int *object, int operand);
int __overload atomic_fetch_or_explicit(volatile atomic_int *object, int operand, memory_order order);
int __overload atomic_fetch_or_explicit(volatile atomic_int *object, int operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_or(volatile atomic_uint *object, uint operand);
uint __overload atomic_fetch_or_explicit(volatile atomic_uint *object, uint operand, memory_order order);
uint __overload atomic_fetch_or_explicit(volatile atomic_uint *object, uint operand, memory_order order, memory_scope scope);
uintptr_t __overload atomic_fetch_or(volatile atomic_uintptr_t *object, ptrdiff_t operand);
uintptr_t __overload atomic_fetch_or_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order);
uintptr_t __overload atomic_fetch_or_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order, memory_scope scope);
int __overload atomic_fetch_xor(volatile atomic_int *object, int operand);
int __overload atomic_fetch_xor_explicit(volatile atomic_int *object, int operand, memory_order order);
int __overload atomic_fetch_xor_explicit(volatile atomic_int *object, int operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_xor(volatile atomic_uint *object, uint operand);
uint __overload atomic_fetch_xor_explicit(volatile atomic_uint *object, uint operand, memory_order order);
uint __overload atomic_fetch_xor_explicit(volatile atomic_uint *object, uint operand, memory_order order, memory_scope scope);
uintptr_t __overload atomic_fetch_xor(volatile atomic_uintptr_t *object, ptrdiff_t operand);
uintptr_t __overload atomic_fetch_xor_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order);
uintptr_t __overload atomic_fetch_xor_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order, memory_scope scope);
int __overload atomic_fetch_and(volatile atomic_int *object, int operand);
int __overload atomic_fetch_and_explicit(volatile atomic_int *object, int operand, memory_order order);
int __overload atomic_fetch_and_explicit(volatile atomic_int *object, int operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_and(volatile atomic_uint *object, uint operand);
uint __overload atomic_fetch_and_explicit(volatile atomic_uint *object, uint operand, memory_order order);
uint __overload atomic_fetch_and_explicit(volatile atomic_uint *object, uint operand, memory_order order, memory_scope scope);
uintptr_t __overload atomic_fetch_and(volatile atomic_uintptr_t *object, ptrdiff_t operand);
uintptr_t __overload atomic_fetch_and_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order);
uintptr_t __overload atomic_fetch_and_explicit(volatile atomic_uintptr_t *object, ptrdiff_t operand, memory_order order, memory_scope scope);
intptr_t __overload atomic_fetch_or(volatile atomic_intptr_t *object, uintptr_t operand);
intptr_t __overload atomic_fetch_or_explicit(volatile atomic_intptr_t *object, uintptr_t operand, memory_order order);
intptr_t __overload atomic_fetch_or_explicit(volatile atomic_intptr_t *object, uintptr_t operand, memory_order order, memory_scope scope);
intptr_t __overload atomic_fetch_xor(volatile atomic_intptr_t *object, uintptr_t operand);
intptr_t __overload atomic_fetch_xor_explicit(volatile atomic_intptr_t *object, uintptr_t operand, memory_order order);
intptr_t __overload atomic_fetch_xor_explicit(volatile atomic_intptr_t *object, uintptr_t operand, memory_order order, memory_scope scope);
intptr_t __overload atomic_fetch_and(volatile atomic_intptr_t *object, uintptr_t operand);
intptr_t __overload atomic_fetch_and_explicit(volatile atomic_intptr_t *object, uintptr_t operand, memory_order order);
intptr_t __overload atomic_fetch_and_explicit(volatile atomic_intptr_t *object, uintptr_t operand, memory_order order, memory_scope scope);

// atomic_fetch_min/max()

int __overload atomic_fetch_min(volatile atomic_int *object, int operand);
int __overload atomic_fetch_min_explicit(volatile atomic_int *object, int operand, memory_order order);
int __overload atomic_fetch_min_explicit(volatile atomic_int *object, int operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_min(volatile atomic_uint *object, uint operand);
uint __overload atomic_fetch_min_explicit(volatile atomic_uint *object, uint operand, memory_order order);
uint __overload atomic_fetch_min_explicit(volatile atomic_uint *object, uint operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_min(volatile atomic_uint *object, int operand);
uint __overload atomic_fetch_min_explicit(volatile atomic_uint *object, int operand, memory_order order);
uint __overload atomic_fetch_min_explicit(volatile atomic_uint *object, int operand, memory_order order, memory_scope scope);
int __overload atomic_fetch_max(volatile atomic_int *object, int operand);
int __overload atomic_fetch_max_explicit(volatile atomic_int *object, int operand, memory_order order);
int __overload atomic_fetch_max_explicit(volatile atomic_int *object, int operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_max(volatile atomic_uint *object, uint operand);
uint __overload atomic_fetch_max_explicit(volatile atomic_uint *object, uint operand, memory_order order);
uint __overload atomic_fetch_max_explicit(volatile atomic_uint *object, uint operand, memory_order order, memory_scope scope);
uint __overload atomic_fetch_max(volatile atomic_uint *object, int operand);
uint __overload atomic_fetch_max_explicit(volatile atomic_uint *object, int operand, memory_order order);
uint __overload atomic_fetch_max_explicit(volatile atomic_uint *object, int operand, memory_order order, memory_scope scope);

// atomic_store()

void __overload atomic_store(volatile atomic_int *object, int desired);
void __overload atomic_store_explicit(volatile atomic_int *object, int desired, memory_order order);
void __overload atomic_store_explicit(volatile atomic_int *object, int desired, memory_order order, memory_scope scope);
void __overload atomic_store(volatile atomic_uint *object, uint desired);
void __overload atomic_store_explicit(volatile atomic_uint *object, uint desired, memory_order order);
void __overload atomic_store_explicit(volatile atomic_uint *object, uint desired, memory_order order, memory_scope scope);
void __overload atomic_store(volatile atomic_float *object, float desired);
void __overload atomic_store_explicit(volatile atomic_float *object, float desired, memory_order order);
void __overload atomic_store_explicit(volatile atomic_float *object, float desired, memory_order order, memory_scope scope);
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#ifdef cl_khr_fp64
void __overload atomic_store(volatile atomic_double *object, double desired);
void __overload atomic_store_explicit(volatile atomic_double *object, double desired, memory_order order);
void __overload atomic_store_explicit(volatile atomic_double *object, double desired, memory_order order, memory_scope scope);
#endif //cl_khr_fp64
void __overload atomic_store(volatile atomic_long *object, long desired);
void __overload atomic_store_explicit(volatile atomic_long *object, long desired, memory_order order);
void __overload atomic_store_explicit(volatile atomic_long *object, long desired, memory_order order, memory_scope scope);
void __overload atomic_store(volatile atomic_ulong *object, ulong desired);
void __overload atomic_store_explicit(volatile atomic_ulong *object, ulong desired, memory_order order);
void __overload atomic_store_explicit(volatile atomic_ulong *object, ulong desired, memory_order order, memory_scope scope);
#endif

// atomic_load()

int __overload atomic_load(volatile atomic_int *object);
int __overload atomic_load_explicit(volatile atomic_int *object, memory_order order);
int __overload atomic_load_explicit(volatile atomic_int *object, memory_order order, memory_scope scope);
uint __overload atomic_load(volatile atomic_uint *object);
uint __overload atomic_load_explicit(volatile atomic_uint *object, memory_order order);
uint __overload atomic_load_explicit(volatile atomic_uint *object, memory_order order, memory_scope scope);
float __overload atomic_load(volatile atomic_float *object);
float __overload atomic_load_explicit(volatile atomic_float *object, memory_order order);
float __overload atomic_load_explicit(volatile atomic_float *object, memory_order order, memory_scope scope);
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#ifdef cl_khr_fp64
double __overload atomic_load(volatile atomic_double *object);
double __overload atomic_load_explicit(volatile atomic_double *object, memory_order order);
double __overload atomic_load_explicit(volatile atomic_double *object, memory_order order, memory_scope scope);
#endif //cl_khr_fp64
long __overload atomic_load(volatile atomic_long *object);
long __overload atomic_load_explicit(volatile atomic_long *object, memory_order order);
long __overload atomic_load_explicit(volatile atomic_long *object, memory_order order, memory_scope scope);
ulong __overload atomic_load(volatile atomic_ulong *object);
ulong __overload atomic_load_explicit(volatile atomic_ulong *object, memory_order order);
ulong __overload atomic_load_explicit(volatile atomic_ulong *object, memory_order order, memory_scope scope);
#endif

// atomic_exchange()

int __overload atomic_exchange(volatile atomic_int *object, int desired);
int __overload atomic_exchange_explicit(volatile atomic_int *object, int desired, memory_order order);
int __overload atomic_exchange_explicit(volatile atomic_int *object, int desired, memory_order order, memory_scope scope);
uint __overload atomic_exchange(volatile atomic_uint *object, uint desired);
uint __overload atomic_exchange_explicit(volatile atomic_uint *object, uint desired, memory_order order);
uint __overload atomic_exchange_explicit(volatile atomic_uint *object, uint desired, memory_order order, memory_scope scope);
float __overload atomic_exchange(volatile atomic_float *object, float desired);
float __overload atomic_exchange_explicit(volatile atomic_float *object, float desired, memory_order order);
float __overload atomic_exchange_explicit(volatile atomic_float *object, float desired, memory_order order, memory_scope scope);
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#ifdef cl_khr_fp64
double __overload atomic_exchange(volatile atomic_double *object, double desired);
double __overload atomic_exchange_explicit(volatile atomic_double *object, double desired, memory_order order);
double __overload atomic_exchange_explicit(volatile atomic_double *object, double desired, memory_order order, memory_scope scope);
#endif //cl_khr_fp64
long __overload atomic_exchange(volatile atomic_long *object, long desired);
long __overload atomic_exchange_explicit(volatile atomic_long *object, long desired, memory_order order);
long __overload atomic_exchange_explicit(volatile atomic_long *object, long desired, memory_order order, memory_scope scope);
ulong __overload atomic_exchange(volatile atomic_ulong *object, ulong desired);
ulong __overload atomic_exchange_explicit(volatile atomic_ulong *object, ulong desired, memory_order order);
ulong __overload atomic_exchange_explicit(volatile atomic_ulong *object, ulong desired, memory_order order, memory_scope scope);
#endif

// atomic_compare_exchange_strong() and atomic_compare_exchange_weak()

bool __overload atomic_compare_exchange_strong(volatile atomic_int *object, int *expected, int desired);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_int *object, int *expected,
                                                                                 int desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_int *object, int *expected,
                                                                                 int desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_strong(volatile atomic_uint *object, uint *expected, uint desired);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_uint *object, uint *expected,
                                                                                 uint desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_uint *object, uint *expected,
                                                                                 uint desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_weak(volatile atomic_int *object, int *expected, int desired);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_int *object, int *expected,
                                                                                 int desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_int *object, int *expected,
                                                                                 int desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_weak(volatile atomic_uint *object, uint *expected, uint desired);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_uint *object, uint *expected,
                                                                                 uint desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_uint *object, uint *expected,
                                                                                 uint desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_strong(volatile atomic_float *object, float *expected, float desired);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_float *object, float *expected,
                                                                                 float desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_float *object, float *expected,
                                                                                 float desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_weak(volatile atomic_float *object, float *expected, float desired);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_float *object, float *expected,
                                                                                 float desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_float *object, float *expected,
                                                                                 float desired, memory_order success, memory_order failure, memory_scope scope);
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#ifdef cl_khr_fp64
bool __overload atomic_compare_exchange_strong(volatile atomic_double *object, double *expected, double desired);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_double *object, double *expected,
                                                                                 double desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_double *object, double *expected,
                                                                                 double desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_weak(volatile atomic_double *object, double *expected, double desired);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_double *object, double *expected,
                                                                                 double desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_double *object, double *expected,
                                                                                 double desired, memory_order success, memory_order failure, memory_scope scope);
#endif //cl_khr_fp64
bool __overload atomic_compare_exchange_strong(volatile atomic_long *object, long *expected, long desired);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_long *object, long *expected,
                                                                                 long desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_long *object, long *expected,
                                                                                 long desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_weak(volatile atomic_long *object, long *expected, long desired);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_long *object, long *expected,
                                                                                 long desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_long *object, long *expected,
                                                                                 long desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_strong(volatile atomic_ulong *object, ulong *expected, ulong desired);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_ulong *object, ulong *expected,
                                                                                 ulong desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_strong_explicit(volatile atomic_ulong *object, ulong *expected,
                                                                                 ulong desired, memory_order success, memory_order failure, memory_scope scope);
bool __overload atomic_compare_exchange_weak(volatile atomic_ulong *object, ulong *expected, ulong desired);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_ulong *object, ulong *expected,
                                                                                 ulong desired, memory_order success, memory_order failure);
bool __overload atomic_compare_exchange_weak_explicit(volatile atomic_ulong *object, ulong *expected,
                                                                                 ulong desired, memory_order success, memory_order failure, memory_scope scope);
#endif

// atomic_flag_test_and_set() and atomic_flag_clear()

bool __overload atomic_flag_test_and_set(volatile atomic_flag *object);
bool __overload atomic_flag_test_and_set_explicit(volatile atomic_flag *object, memory_order order);
bool __overload atomic_flag_test_and_set_explicit(volatile atomic_flag *object, memory_order order, memory_scope scope);
void __overload atomic_flag_clear(volatile atomic_flag *object);
void __overload atomic_flag_clear_explicit(volatile atomic_flag *object, memory_order order);
void __overload atomic_flag_clear_explicit(volatile atomic_flag *object, memory_order order, memory_scope scope);

#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL v1.1 s6.11.12, v1.2 s6.12.12, v2.0 s6.13.12 - Miscellaneous Vector Functions

/**
 * The shuffle and shuffle2 built-in functions construct
 * a permutation of elements from one or two input
 * vectors respectively that are of the same type,
 * returning a vector with the same element type as the
 * input and length that is the same as the shuffle mask.
 * The size of each element in the mask must match the
 * size of each element in the result. For shuffle, only
 * the ilogb(2m-1) least significant bits of each mask
 * element are considered. For shuffle2, only the
 * ilogb(2m-1)+1 least significant bits of each mask
 * element are considered. Other bits in the mask shall
 * be ignored.
 * The elements of the input vectors are numbered from
 * left to right across one or both of the vectors. For this
 * purpose, the number of elements in a vector is given
 * by vec_step(gentypem). The shuffle mask operand
 * specifies, for each element of the result vector, which
 * element of the one or two input vectors the result
 * element gets.
 * Examples:
 * uint4 mask = (uint4)(3, 2,
 * 1, 0);
 * float4 a;
 * float4 r = shuffle(a, mask);
 * // r.s0123 = a.wzyx
 * uint8 mask = (uint8)(0, 1, 2, 3,
 * 4, 5, 6, 7);
 * float4 a, b;
 * float8 r = shuffle2(a, b, mask);
 * // r.s0123 = a.xyzw
 * // r.s4567 = b.xyzw
 * uint4 mask;
 * float8 a;
 * float4 b;
 * b = shuffle(a, mask);
 * Examples that are not valid are:
 * uint8 mask;
 * short16 a;
 * short8 b;
 * b = shuffle(a, mask); <- not valid
 */
char2 __const_func shuffle(char2 x, uchar2 mask);
char2 __const_func shuffle(char4 x, uchar2 mask);
char2 __const_func shuffle(char8 x, uchar2 mask);
char2 __const_func shuffle(char16 x, uchar2 mask);

uchar2 __const_func shuffle(uchar2 x, uchar2 mask);
uchar2 __const_func shuffle(uchar4 x, uchar2 mask);
uchar2 __const_func shuffle(uchar8 x, uchar2 mask);
uchar2 __const_func shuffle(uchar16 x, uchar2 mask);

short2 __const_func shuffle(short2 x, ushort2 mask);
short2 __const_func shuffle(short4 x, ushort2 mask);
short2 __const_func shuffle(short8 x, ushort2 mask);
short2 __const_func shuffle(short16 x, ushort2 mask);

ushort2 __const_func shuffle(ushort2 x, ushort2 mask);
ushort2 __const_func shuffle(ushort4 x, ushort2 mask);
ushort2 __const_func shuffle(ushort8 x, ushort2 mask);
ushort2 __const_func shuffle(ushort16 x, ushort2 mask);

int2 __const_func shuffle(int2 x, uint2 mask);
int2 __const_func shuffle(int4 x, uint2 mask);
int2 __const_func shuffle(int8 x, uint2 mask);
int2 __const_func shuffle(int16 x, uint2 mask);

uint2 __const_func shuffle(uint2 x, uint2 mask);
uint2 __const_func shuffle(uint4 x, uint2 mask);
uint2 __const_func shuffle(uint8 x, uint2 mask);
uint2 __const_func shuffle(uint16 x, uint2 mask);

long2 __const_func shuffle(long2 x, ulong2 mask);
long2 __const_func shuffle(long4 x, ulong2 mask);
long2 __const_func shuffle(long8 x, ulong2 mask);
long2 __const_func shuffle(long16 x, ulong2 mask);

ulong2 __const_func shuffle(ulong2 x, ulong2 mask);
ulong2 __const_func shuffle(ulong4 x, ulong2 mask);
ulong2 __const_func shuffle(ulong8 x, ulong2 mask);
ulong2 __const_func shuffle(ulong16 x, ulong2 mask);

float2 __const_func shuffle(float2 x, uint2 mask);
float2 __const_func shuffle(float4 x, uint2 mask);
float2 __const_func shuffle(float8 x, uint2 mask);
float2 __const_func shuffle(float16 x, uint2 mask);

char4 __const_func shuffle(char2 x, uchar4 mask);
char4 __const_func shuffle(char4 x, uchar4 mask);
char4 __const_func shuffle(char8 x, uchar4 mask);
char4 __const_func shuffle(char16 x, uchar4 mask);

uchar4 __const_func shuffle(uchar2 x, uchar4 mask);
uchar4 __const_func shuffle(uchar4 x, uchar4 mask);
uchar4 __const_func shuffle(uchar8 x, uchar4 mask);
uchar4 __const_func shuffle(uchar16 x, uchar4 mask);

short4 __const_func shuffle(short2 x, ushort4 mask);
short4 __const_func shuffle(short4 x, ushort4 mask);
short4 __const_func shuffle(short8 x, ushort4 mask);
short4 __const_func shuffle(short16 x, ushort4 mask);

ushort4 __const_func shuffle(ushort2 x, ushort4 mask);
ushort4 __const_func shuffle(ushort4 x, ushort4 mask);
ushort4 __const_func shuffle(ushort8 x, ushort4 mask);
ushort4 __const_func shuffle(ushort16 x, ushort4 mask);

int4 __const_func shuffle(int2 x, uint4 mask);
int4 __const_func shuffle(int4 x, uint4 mask);
int4 __const_func shuffle(int8 x, uint4 mask);
int4 __const_func shuffle(int16 x, uint4 mask);

uint4 __const_func shuffle(uint2 x, uint4 mask);
uint4 __const_func shuffle(uint4 x, uint4 mask);
uint4 __const_func shuffle(uint8 x, uint4 mask);
uint4 __const_func shuffle(uint16 x, uint4 mask);

long4 __const_func shuffle(long2 x, ulong4 mask);
long4 __const_func shuffle(long4 x, ulong4 mask);
long4 __const_func shuffle(long8 x, ulong4 mask);
long4 __const_func shuffle(long16 x, ulong4 mask);

ulong4 __const_func shuffle(ulong2 x, ulong4 mask);
ulong4 __const_func shuffle(ulong4 x, ulong4 mask);
ulong4 __const_func shuffle(ulong8 x, ulong4 mask);
ulong4 __const_func shuffle(ulong16 x, ulong4 mask);

float4 __const_func shuffle(float2 x, uint4 mask);
float4 __const_func shuffle(float4 x, uint4 mask);
float4 __const_func shuffle(float8 x, uint4 mask);
float4 __const_func shuffle(float16 x, uint4 mask);

char8 __const_func shuffle(char2 x, uchar8 mask);
char8 __const_func shuffle(char4 x, uchar8 mask);
char8 __const_func shuffle(char8 x, uchar8 mask);
char8 __const_func shuffle(char16 x, uchar8 mask);

uchar8 __const_func shuffle(uchar2 x, uchar8 mask);
uchar8 __const_func shuffle(uchar4 x, uchar8 mask);
uchar8 __const_func shuffle(uchar8 x, uchar8 mask);
uchar8 __const_func shuffle(uchar16 x, uchar8 mask);

short8 __const_func shuffle(short2 x, ushort8 mask);
short8 __const_func shuffle(short4 x, ushort8 mask);
short8 __const_func shuffle(short8 x, ushort8 mask);
short8 __const_func shuffle(short16 x, ushort8 mask);

ushort8 __const_func shuffle(ushort2 x, ushort8 mask);
ushort8 __const_func shuffle(ushort4 x, ushort8 mask);
ushort8 __const_func shuffle(ushort8 x, ushort8 mask);
ushort8 __const_func shuffle(ushort16 x, ushort8 mask);

int8 __const_func shuffle(int2 x, uint8 mask);
int8 __const_func shuffle(int4 x, uint8 mask);
int8 __const_func shuffle(int8 x, uint8 mask);
int8 __const_func shuffle(int16 x, uint8 mask);

uint8 __const_func shuffle(uint2 x, uint8 mask);
uint8 __const_func shuffle(uint4 x, uint8 mask);
uint8 __const_func shuffle(uint8 x, uint8 mask);
uint8 __const_func shuffle(uint16 x, uint8 mask);

long8 __const_func shuffle(long2 x, ulong8 mask);
long8 __const_func shuffle(long4 x, ulong8 mask);
long8 __const_func shuffle(long8 x, ulong8 mask);
long8 __const_func shuffle(long16 x, ulong8 mask);

ulong8 __const_func shuffle(ulong2 x, ulong8 mask);
ulong8 __const_func shuffle(ulong4 x, ulong8 mask);
ulong8 __const_func shuffle(ulong8 x, ulong8 mask);
ulong8 __const_func shuffle(ulong16 x, ulong8 mask);

float8 __const_func shuffle(float2 x, uint8 mask);
float8 __const_func shuffle(float4 x, uint8 mask);
float8 __const_func shuffle(float8 x, uint8 mask);
float8 __const_func shuffle(float16 x, uint8 mask);

char16 __const_func shuffle(char2 x, uchar16 mask);
char16 __const_func shuffle(char4 x, uchar16 mask);
char16 __const_func shuffle(char8 x, uchar16 mask);
char16 __const_func shuffle(char16 x, uchar16 mask);

uchar16 __const_func shuffle(uchar2 x, uchar16 mask);
uchar16 __const_func shuffle(uchar4 x, uchar16 mask);
uchar16 __const_func shuffle(uchar8 x, uchar16 mask);
uchar16 __const_func shuffle(uchar16 x, uchar16 mask);

short16 __const_func shuffle(short2 x, ushort16 mask);
short16 __const_func shuffle(short4 x, ushort16 mask);
short16 __const_func shuffle(short8 x, ushort16 mask);
short16 __const_func shuffle(short16 x, ushort16 mask);

ushort16 __const_func shuffle(ushort2 x, ushort16 mask);
ushort16 __const_func shuffle(ushort4 x, ushort16 mask);
ushort16 __const_func shuffle(ushort8 x, ushort16 mask);
ushort16 __const_func shuffle(ushort16 x, ushort16 mask);

int16 __const_func shuffle(int2 x, uint16 mask);
int16 __const_func shuffle(int4 x, uint16 mask);
int16 __const_func shuffle(int8 x, uint16 mask);
int16 __const_func shuffle(int16 x, uint16 mask);

uint16 __const_func shuffle(uint2 x, uint16 mask);
uint16 __const_func shuffle(uint4 x, uint16 mask);
uint16 __const_func shuffle(uint8 x, uint16 mask);
uint16 __const_func shuffle(uint16 x, uint16 mask);

long16 __const_func shuffle(long2 x, ulong16 mask);
long16 __const_func shuffle(long4 x, ulong16 mask);
long16 __const_func shuffle(long8 x, ulong16 mask);
long16 __const_func shuffle(long16 x, ulong16 mask);

ulong16 __const_func shuffle(ulong2 x, ulong16 mask);
ulong16 __const_func shuffle(ulong4 x, ulong16 mask);
ulong16 __const_func shuffle(ulong8 x, ulong16 mask);
ulong16 __const_func shuffle(ulong16 x, ulong16 mask);

float16 __const_func shuffle(float2 x, uint16 mask);
float16 __const_func shuffle(float4 x, uint16 mask);
float16 __const_func shuffle(float8 x, uint16 mask);
float16 __const_func shuffle(float16 x, uint16 mask);

#ifdef cl_khr_fp64
double2 __const_func shuffle(double2 x, ulong2 mask);
double2 __const_func shuffle(double4 x, ulong2 mask);
double2 __const_func shuffle(double8 x, ulong2 mask);
double2 __const_func shuffle(double16 x, ulong2 mask);

double4 __const_func shuffle(double2 x, ulong4 mask);
double4 __const_func shuffle(double4 x, ulong4 mask);
double4 __const_func shuffle(double8 x, ulong4 mask);
double4 __const_func shuffle(double16 x, ulong4 mask);

double8 __const_func shuffle(double2 x, ulong8 mask);
double8 __const_func shuffle(double4 x, ulong8 mask);
double8 __const_func shuffle(double8 x, ulong8 mask);
double8 __const_func shuffle(double16 x, ulong8 mask);

double16 __const_func shuffle(double2 x, ulong16 mask);
double16 __const_func shuffle(double4 x, ulong16 mask);
double16 __const_func shuffle(double8 x, ulong16 mask);
double16 __const_func shuffle(double16 x, ulong16 mask);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half2 __const_func shuffle(half2 x, ushort2 mask);
half2 __const_func shuffle(half4 x, ushort2 mask);
half2 __const_func shuffle(half8 x, ushort2 mask);
half2 __const_func shuffle(half16 x, ushort2 mask);

half4 __const_func shuffle(half2 x, ushort4 mask);
half4 __const_func shuffle(half4 x, ushort4 mask);
half4 __const_func shuffle(half8 x, ushort4 mask);
half4 __const_func shuffle(half16 x, ushort4 mask);

half8 __const_func shuffle(half2 x, ushort8 mask);
half8 __const_func shuffle(half4 x, ushort8 mask);
half8 __const_func shuffle(half8 x, ushort8 mask);
half8 __const_func shuffle(half16 x, ushort8 mask);

half16 __const_func shuffle(half2 x, ushort16 mask);
half16 __const_func shuffle(half4 x, ushort16 mask);
half16 __const_func shuffle(half8 x, ushort16 mask);
half16 __const_func shuffle(half16 x, ushort16 mask);
#endif //cl_khr_fp16

char2 __const_func shuffle2(char2 x, char2 y, uchar2 mask);
char2 __const_func shuffle2(char4 x, char4 y, uchar2 mask);
char2 __const_func shuffle2(char8 x, char8 y, uchar2 mask);
char2 __const_func shuffle2(char16 x, char16 y, uchar2 mask);

uchar2 __const_func shuffle2(uchar2 x, uchar2 y, uchar2 mask);
uchar2 __const_func shuffle2(uchar4 x, uchar4 y, uchar2 mask);
uchar2 __const_func shuffle2(uchar8 x, uchar8 y, uchar2 mask);
uchar2 __const_func shuffle2(uchar16 x, uchar16 y, uchar2 mask);

short2 __const_func shuffle2(short2 x, short2 y, ushort2 mask);
short2 __const_func shuffle2(short4 x, short4 y, ushort2 mask);
short2 __const_func shuffle2(short8 x, short8 y, ushort2 mask);
short2 __const_func shuffle2(short16 x, short16 y, ushort2 mask);

ushort2 __const_func shuffle2(ushort2 x, ushort2 y, ushort2 mask);
ushort2 __const_func shuffle2(ushort4 x, ushort4 y, ushort2 mask);
ushort2 __const_func shuffle2(ushort8 x, ushort8 y, ushort2 mask);
ushort2 __const_func shuffle2(ushort16 x, ushort16 y, ushort2 mask);

int2 __const_func shuffle2(int2 x, int2 y, uint2 mask);
int2 __const_func shuffle2(int4 x, int4 y, uint2 mask);
int2 __const_func shuffle2(int8 x, int8 y, uint2 mask);
int2 __const_func shuffle2(int16 x, int16 y, uint2 mask);

uint2 __const_func shuffle2(uint2 x, uint2 y, uint2 mask);
uint2 __const_func shuffle2(uint4 x, uint4 y, uint2 mask);
uint2 __const_func shuffle2(uint8 x, uint8 y, uint2 mask);
uint2 __const_func shuffle2(uint16 x, uint16 y, uint2 mask);

long2 __const_func shuffle2(long2 x, long2 y, ulong2 mask);
long2 __const_func shuffle2(long4 x, long4 y, ulong2 mask);
long2 __const_func shuffle2(long8 x, long8 y, ulong2 mask);
long2 __const_func shuffle2(long16 x, long16 y, ulong2 mask);

ulong2 __const_func shuffle2(ulong2 x, ulong2 y, ulong2 mask);
ulong2 __const_func shuffle2(ulong4 x, ulong4 y, ulong2 mask);
ulong2 __const_func shuffle2(ulong8 x, ulong8 y, ulong2 mask);
ulong2 __const_func shuffle2(ulong16 x, ulong16 y, ulong2 mask);

float2 __const_func shuffle2(float2 x, float2 y, uint2 mask);
float2 __const_func shuffle2(float4 x, float4 y, uint2 mask);
float2 __const_func shuffle2(float8 x, float8 y, uint2 mask);
float2 __const_func shuffle2(float16 x, float16 y, uint2 mask);

char4 __const_func shuffle2(char2 x, char2 y, uchar4 mask);
char4 __const_func shuffle2(char4 x, char4 y, uchar4 mask);
char4 __const_func shuffle2(char8 x, char8 y, uchar4 mask);
char4 __const_func shuffle2(char16 x, char16 y, uchar4 mask);

uchar4 __const_func shuffle2(uchar2 x, uchar2 y, uchar4 mask);
uchar4 __const_func shuffle2(uchar4 x, uchar4 y, uchar4 mask);
uchar4 __const_func shuffle2(uchar8 x, uchar8 y, uchar4 mask);
uchar4 __const_func shuffle2(uchar16 x, uchar16 y, uchar4 mask);

short4 __const_func shuffle2(short2 x, short2 y, ushort4 mask);
short4 __const_func shuffle2(short4 x, short4 y, ushort4 mask);
short4 __const_func shuffle2(short8 x, short8 y, ushort4 mask);
short4 __const_func shuffle2(short16 x, short16 y, ushort4 mask);

ushort4 __const_func shuffle2(ushort2 x, ushort2 y, ushort4 mask);
ushort4 __const_func shuffle2(ushort4 x, ushort4 y, ushort4 mask);
ushort4 __const_func shuffle2(ushort8 x, ushort8 y, ushort4 mask);
ushort4 __const_func shuffle2(ushort16 x, ushort16 y, ushort4 mask);

int4 __const_func shuffle2(int2 x, int2 y, uint4 mask);
int4 __const_func shuffle2(int4 x, int4 y, uint4 mask);
int4 __const_func shuffle2(int8 x, int8 y, uint4 mask);
int4 __const_func shuffle2(int16 x, int16 y, uint4 mask);

uint4 __const_func shuffle2(uint2 x, uint2 y, uint4 mask);
uint4 __const_func shuffle2(uint4 x, uint4 y, uint4 mask);
uint4 __const_func shuffle2(uint8 x, uint8 y, uint4 mask);
uint4 __const_func shuffle2(uint16 x, uint16 y, uint4 mask);

long4 __const_func shuffle2(long2 x, long2 y, ulong4 mask);
long4 __const_func shuffle2(long4 x, long4 y, ulong4 mask);
long4 __const_func shuffle2(long8 x, long8 y, ulong4 mask);
long4 __const_func shuffle2(long16 x, long16 y, ulong4 mask);

ulong4 __const_func shuffle2(ulong2 x, ulong2 y, ulong4 mask);
ulong4 __const_func shuffle2(ulong4 x, ulong4 y, ulong4 mask);
ulong4 __const_func shuffle2(ulong8 x, ulong8 y, ulong4 mask);
ulong4 __const_func shuffle2(ulong16 x, ulong16 y, ulong4 mask);

float4 __const_func shuffle2(float2 x, float2 y, uint4 mask);
float4 __const_func shuffle2(float4 x, float4 y, uint4 mask);
float4 __const_func shuffle2(float8 x, float8 y, uint4 mask);
float4 __const_func shuffle2(float16 x, float16 y, uint4 mask);

char8 __const_func shuffle2(char2 x, char2 y, uchar8 mask);
char8 __const_func shuffle2(char4 x, char4 y, uchar8 mask);
char8 __const_func shuffle2(char8 x, char8 y, uchar8 mask);
char8 __const_func shuffle2(char16 x, char16 y, uchar8 mask);

uchar8 __const_func shuffle2(uchar2 x, uchar2 y, uchar8 mask);
uchar8 __const_func shuffle2(uchar4 x, uchar4 y, uchar8 mask);
uchar8 __const_func shuffle2(uchar8 x, uchar8 y, uchar8 mask);
uchar8 __const_func shuffle2(uchar16 x, uchar16 y, uchar8 mask);

short8 __const_func shuffle2(short2 x, short2 y, ushort8 mask);
short8 __const_func shuffle2(short4 x, short4 y, ushort8 mask);
short8 __const_func shuffle2(short8 x, short8 y, ushort8 mask);
short8 __const_func shuffle2(short16 x, short16 y, ushort8 mask);

ushort8 __const_func shuffle2(ushort2 x, ushort2 y, ushort8 mask);
ushort8 __const_func shuffle2(ushort4 x, ushort4 y, ushort8 mask);
ushort8 __const_func shuffle2(ushort8 x, ushort8 y, ushort8 mask);
ushort8 __const_func shuffle2(ushort16 x, ushort16 y, ushort8 mask);

int8 __const_func shuffle2(int2 x, int2 y, uint8 mask);
int8 __const_func shuffle2(int4 x, int4 y, uint8 mask);
int8 __const_func shuffle2(int8 x, int8 y, uint8 mask);
int8 __const_func shuffle2(int16 x, int16 y, uint8 mask);

uint8 __const_func shuffle2(uint2 x, uint2 y, uint8 mask);
uint8 __const_func shuffle2(uint4 x, uint4 y, uint8 mask);
uint8 __const_func shuffle2(uint8 x, uint8 y, uint8 mask);
uint8 __const_func shuffle2(uint16 x, uint16 y, uint8 mask);

long8 __const_func shuffle2(long2 x, long2 y, ulong8 mask);
long8 __const_func shuffle2(long4 x, long4 y, ulong8 mask);
long8 __const_func shuffle2(long8 x, long8 y, ulong8 mask);
long8 __const_func shuffle2(long16 x, long16 y, ulong8 mask);

ulong8 __const_func shuffle2(ulong2 x, ulong2 y, ulong8 mask);
ulong8 __const_func shuffle2(ulong4 x, ulong4 y, ulong8 mask);
ulong8 __const_func shuffle2(ulong8 x, ulong8 y, ulong8 mask);
ulong8 __const_func shuffle2(ulong16 x, ulong16 y, ulong8 mask);

float8 __const_func shuffle2(float2 x, float2 y, uint8 mask);
float8 __const_func shuffle2(float4 x, float4 y, uint8 mask);
float8 __const_func shuffle2(float8 x, float8 y, uint8 mask);
float8 __const_func shuffle2(float16 x, float16 y, uint8 mask);

char16 __const_func shuffle2(char2 x, char2 y, uchar16 mask);
char16 __const_func shuffle2(char4 x, char4 y, uchar16 mask);
char16 __const_func shuffle2(char8 x, char8 y, uchar16 mask);
char16 __const_func shuffle2(char16 x, char16 y, uchar16 mask);

uchar16 __const_func shuffle2(uchar2 x, uchar2 y, uchar16 mask);
uchar16 __const_func shuffle2(uchar4 x, uchar4 y, uchar16 mask);
uchar16 __const_func shuffle2(uchar8 x, uchar8 y, uchar16 mask);
uchar16 __const_func shuffle2(uchar16 x, uchar16 y, uchar16 mask);

short16 __const_func shuffle2(short2 x, short2 y, ushort16 mask);
short16 __const_func shuffle2(short4 x, short4 y, ushort16 mask);
short16 __const_func shuffle2(short8 x, short8 y, ushort16 mask);
short16 __const_func shuffle2(short16 x, short16 y, ushort16 mask);

ushort16 __const_func shuffle2(ushort2 x, ushort2 y, ushort16 mask);
ushort16 __const_func shuffle2(ushort4 x, ushort4 y, ushort16 mask);
ushort16 __const_func shuffle2(ushort8 x, ushort8 y, ushort16 mask);
ushort16 __const_func shuffle2(ushort16 x, ushort16 y, ushort16 mask);

int16 __const_func shuffle2(int2 x, int2 y, uint16 mask);
int16 __const_func shuffle2(int4 x, int4 y, uint16 mask);
int16 __const_func shuffle2(int8 x, int8 y, uint16 mask);
int16 __const_func shuffle2(int16 x, int16 y, uint16 mask);

uint16 __const_func shuffle2(uint2 x, uint2 y, uint16 mask);
uint16 __const_func shuffle2(uint4 x, uint4 y, uint16 mask);
uint16 __const_func shuffle2(uint8 x, uint8 y, uint16 mask);
uint16 __const_func shuffle2(uint16 x, uint16 y, uint16 mask);

long16 __const_func shuffle2(long2 x, long2 y, ulong16 mask);
long16 __const_func shuffle2(long4 x, long4 y, ulong16 mask);
long16 __const_func shuffle2(long8 x, long8 y, ulong16 mask);
long16 __const_func shuffle2(long16 x, long16 y, ulong16 mask);

ulong16 __const_func shuffle2(ulong2 x, ulong2 y, ulong16 mask);
ulong16 __const_func shuffle2(ulong4 x, ulong4 y, ulong16 mask);
ulong16 __const_func shuffle2(ulong8 x, ulong8 y, ulong16 mask);
ulong16 __const_func shuffle2(ulong16 x, ulong16 y, ulong16 mask);

float16 __const_func shuffle2(float2 x, float2 y, uint16 mask);
float16 __const_func shuffle2(float4 x, float4 y, uint16 mask);
float16 __const_func shuffle2(float8 x, float8 y, uint16 mask);
float16 __const_func shuffle2(float16 x, float16 y, uint16 mask);

#ifdef cl_khr_fp64
double2 __const_func shuffle2(double2 x, double2 y, ulong2 mask);
double2 __const_func shuffle2(double4 x, double4 y, ulong2 mask);
double2 __const_func shuffle2(double8 x, double8 y, ulong2 mask);
double2 __const_func shuffle2(double16 x, double16 y, ulong2 mask);

double4 __const_func shuffle2(double2 x, double2 y, ulong4 mask);
double4 __const_func shuffle2(double4 x, double4 y, ulong4 mask);
double4 __const_func shuffle2(double8 x, double8 y, ulong4 mask);
double4 __const_func shuffle2(double16 x, double16 y, ulong4 mask);

double8 __const_func shuffle2(double2 x, double2 y, ulong8 mask);
double8 __const_func shuffle2(double4 x, double4 y, ulong8 mask);
double8 __const_func shuffle2(double8 x, double8 y, ulong8 mask);
double8 __const_func shuffle2(double16 x, double16 y, ulong8 mask);

double16 __const_func shuffle2(double2 x, double2 y, ulong16 mask);
double16 __const_func shuffle2(double4 x, double4 y, ulong16 mask);
double16 __const_func shuffle2(double8 x, double8 y, ulong16 mask);
double16 __const_func shuffle2(double16 x, double16 y, ulong16 mask);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half2 __const_func shuffle2(half2 x, half2 y, ushort2 mask);
half2 __const_func shuffle2(half4 x, half4 y, ushort2 mask);
half2 __const_func shuffle2(half8 x, half8 y, ushort2 mask);
half2 __const_func shuffle2(half16 x, half16 y, ushort2 mask);

half4 __const_func shuffle2(half2 x, half2 y, ushort4 mask);
half4 __const_func shuffle2(half4 x, half4 y, ushort4 mask);
half4 __const_func shuffle2(half8 x, half8 y, ushort4 mask);
half4 __const_func shuffle2(half16 x, half16 y, ushort4 mask);

half8 __const_func shuffle2(half2 x, half2 y, ushort8 mask);
half8 __const_func shuffle2(half4 x, half4 y, ushort8 mask);
half8 __const_func shuffle2(half8 x, half8 y, ushort8 mask);
half8 __const_func shuffle2(half16 x, half16 y, ushort8 mask);

half16 __const_func shuffle2(half2 x, half2 y, ushort16 mask);
half16 __const_func shuffle2(half4 x, half4 y, ushort16 mask);
half16 __const_func shuffle2(half8 x, half8 y, ushort16 mask);
half16 __const_func shuffle2(half16 x, half16 y, ushort16 mask);
#endif //cl_khr_fp16

// OpenCL v1.2 s6.12.13, v2.0 s6.13.13 - printf

int printf(__constant const char* st, ...);

// OpenCL v1.1 s6.11.3, v1.2 s6.12.14, v2.0 s6.13.14 - Image Read and Write Functions

// These values need to match the runtime equivalent
//
// Addressing Mode.
//
#define CLK_ADDRESS_NONE                0
#define CLK_ADDRESS_CLAMP_TO_EDGE       2
#define CLK_ADDRESS_CLAMP               4
#define CLK_ADDRESS_REPEAT              6
#define CLK_ADDRESS_MIRRORED_REPEAT     8

//
// Coordination Normalization
//
#define CLK_NORMALIZED_COORDS_FALSE     0
#define CLK_NORMALIZED_COORDS_TRUE      1

//
// Filtering Mode.
//
#define CLK_FILTER_NEAREST              0x10
#define CLK_FILTER_LINEAR               0x20

/**
 * Use the coordinate (coord.xy) to do an element lookup in
 * the 2D image object specified by image.
 *
 * Use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in the 3D image object specified
 * by image. coord.w is ignored.
 *
 * Use the coordinate (coord.z) to index into the
 * 2D image array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 *
 * Use the coordinate (x) to do an element lookup in
 * the 1D image object specified by image.
 *
 * Use the coordinate (coord.y) to index into the
 * 1D image array object specified by image_array
 * and (coord.x) to do an element lookup in
 * the 1D image object specified by image.
 *
 * Use the coordinate (cood.xy) and sample to do an
 * element lookup in the 2D multi-sample image specified
 * by image.
 *
 * Use coord.xy and sample to do an element
 * lookup in the 2D multi-sample image layer
 * identified by index coord.z in the 2D multi-sample
 * image array specified by image.
 *
 * For mipmap images, use the mip-level specified by
 * the Level-of-Detail (lod) or use gradients for LOD
 * computation.
 *
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 *
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 *
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 *
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 *
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 *
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 *
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 
 * The read_image{f|i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 *
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float4 __overload read_imagef(read_only image2d_t image, sampler_t sampler, int2 coord);
float4 __overload read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord);

int4 __overload read_imagei(read_only image2d_t image, sampler_t sampler, int2 coord);
int4 __overload read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord);
uint4 __overload read_imageui(read_only image2d_t image, sampler_t sampler, int2 coord);
uint4 __overload read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord);

float4 __overload read_imagef(read_only image3d_t image, sampler_t sampler, int4 coord);
float4 __overload read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord);

int4 __overload read_imagei(read_only image3d_t image, sampler_t sampler, int4 coord);
int4 __overload read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord);
uint4 __overload read_imageui(read_only image3d_t image, sampler_t sampler, int4 coord);
uint4 __overload read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord);

float4 __overload read_imagef(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
float4 __overload read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);

int4 __overload read_imagei(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
int4 __overload read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);
uint4 __overload read_imageui(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
uint4 __overload read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);

float4 __overload read_imagef(read_only image1d_t image, sampler_t sampler, int coord);
float4 __overload read_imagef(read_only image1d_t image, sampler_t sampler, float coord);

int4 __overload read_imagei(read_only image1d_t image, sampler_t sampler, int coord);
int4 __overload read_imagei(read_only image1d_t image, sampler_t sampler, float coord);
uint4 __overload read_imageui(read_only image1d_t image, sampler_t sampler, int coord);
uint4 __overload read_imageui(read_only image1d_t image, sampler_t sampler, float coord);

float4 __overload read_imagef(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
float4 __overload read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);

int4 __overload read_imagei(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
int4 __overload read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);
uint4 __overload read_imageui(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
uint4 __overload read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);

#ifdef cl_khr_depth_images
float __overload read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord);
float __overload read_imagef(read_only image2d_depth_t image, sampler_t sampler, int2 coord);

float __overload read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord);
float __overload read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, int4 coord);
#endif //cl_khr_depth_images

#if defined(cl_khr_gl_msaa_sharing)
float4 __overload read_imagef(read_only image2d_msaa_t image, int2 coord, int sample);
int4 __overload read_imagei(read_only image2d_msaa_t image, int2 coord, int sample);
uint4 __overload read_imageui(read_only image2d_msaa_t image, int2 coord, int sample);

float __overload read_imagef(read_only image2d_msaa_depth_t image, int2 coord, int sample);

float4 __overload read_imagef(read_only image2d_array_msaa_t image, int4 coord, int sample);
int4 __overload read_imagei(read_only image2d_array_msaa_t image, int4 coord, int sample);
uint4 __overload read_imageui(read_only image2d_array_msaa_t image, int4 coord, int sample);

float __overload read_imagef(read_only image2d_array_msaa_depth_t image, int4 coord, int sample);
#endif //cl_khr_gl_msaa_sharing

// OpenCL Extension v2.0 s9.18 - Mipmaps
#ifdef cl_khr_mipmap_image

float4 __overload read_imagef(read_only image1d_t image, sampler_t sampler, float coord, float lod);
int4 __overload read_imagei(read_only image1d_t image, sampler_t sampler, float coord, float lod);
uint4 __overload read_imageui(read_only image1d_t image, sampler_t sampler, float coord, float lod);

float4 __overload read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

float __overload read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

float __overload read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord, float lod);

float4 __overload read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

float4 __overload read_imagef(read_only image1d_t image, sampler_t sampler, float coord, float gradientX, float gradientY);
int4 __overload read_imagei(read_only image1d_t image, sampler_t sampler, float coord, float gradientX, float gradientY);
uint4 __overload read_imageui(read_only image1d_t image, sampler_t sampler, float coord, float gradientX, float gradientY);

float4 __overload read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float gradientX, float gradientY);
int4 __overload read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float gradientX, float gradientY);
uint4 __overload read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float gradientX, float gradientY);

float4 __overload read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);
int4 __overload read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);
uint4 __overload read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);

float __overload read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);

float4 __overload read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);
int4 __overload read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);
uint4 __overload read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);

float __overload read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);

float4 __overload read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord, float4 gradientX, float4 gradientY);
int4 __overload read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord, float4 gradientX, float4 gradientY);
uint4 __overload read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord, float4 gradientX, float4 gradientY);

float4 __overload read_imagef(read_only image1d_t image, sampler_t sampler, float coord, float lod);
int4 __overload read_imagei(read_only image1d_t image, sampler_t sampler, float coord, float lod);
uint4 __overload read_imageui(read_only image1d_t image, sampler_t sampler, float coord, float lod);

float4 __overload read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

float __overload read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

float __overload read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord, float lod);

float4 __overload read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

#endif //cl_khr_mipmap_image

/**
* Sampler-less Image Access
*/

float4 __overload read_imagef(read_only image1d_t image, int coord);
int4 __overload read_imagei(read_only image1d_t image, int coord);
uint4 __overload read_imageui(read_only image1d_t image, int coord);

float4 __overload read_imagef(read_only image1d_buffer_t image, int coord);
int4 __overload read_imagei(read_only image1d_buffer_t image, int coord);
uint4 __overload read_imageui(read_only image1d_buffer_t image, int coord);

float4 __overload read_imagef(read_only image1d_array_t image, int2 coord);
int4 __overload read_imagei(read_only image1d_array_t image, int2 coord);
uint4 __overload read_imageui(read_only image1d_array_t image, int2 coord);

float4 __overload read_imagef(read_only image2d_t image, int2 coord);
int4 __overload read_imagei(read_only image2d_t image, int2 coord);
uint4 __overload read_imageui(read_only image2d_t image, int2 coord);

float4 __overload read_imagef(read_only image2d_array_t image, int4 coord);
int4 __overload read_imagei(read_only image2d_array_t image, int4 coord);
uint4 __overload read_imageui(read_only image2d_array_t image, int4 coord);

#ifdef cl_khr_depth_images
float __overload read_imagef(read_only image2d_depth_t image, int2 coord);
float __overload read_imagef(read_only image2d_array_depth_t image, int4 coord);
#endif //cl_khr_depth_images

float4 __overload read_imagef(read_only image3d_t image, int4 coord);
int4 __overload read_imagei(read_only image3d_t image, int4 coord);
uint4 __overload read_imageui(read_only image3d_t image, int4 coord);

// Image read functions returning half4 type
#ifdef cl_khr_fp16
half4 __overload read_imageh(read_only image1d_t image, sampler_t sampler, int coord);
half4 __overload read_imageh(read_only image1d_t image, sampler_t sampler, float coord);
half4 __overload read_imageh(read_only image1d_array_t image, sampler_t sampler, int2 coord);
half4 __overload read_imageh(read_only image1d_array_t image, sampler_t sampler, float2 coord);
half4 __overload read_imageh(read_only image2d_t image, sampler_t sampler, int2 coord);
half4 __overload read_imageh(read_only image2d_t image, sampler_t sampler, float2 coord);
half4 __overload read_imageh(read_only image3d_t image, sampler_t sampler, int4 coord);
half4 __overload read_imageh(read_only image3d_t image, sampler_t sampler, float4 coord);
half4 __overload read_imageh(read_only image2d_array_t image, sampler_t sampler, int4 coord);
half4 __overload read_imageh(read_only image2d_array_t image, sampler_t sampler, float4 coord);
half4 __overload read_imageh(read_only image1d_t image, int coord);
half4 __overload read_imageh(read_only image2d_t image, int2 coord);
half4 __overload read_imageh(read_only image3d_t image, int4 coord);
half4 __overload read_imageh(read_only image1d_array_t image, int2 coord);
half4 __overload read_imageh(read_only image2d_array_t image, int4 coord);
half4 __overload read_imageh(read_only image1d_buffer_t image, int coord);
#endif //cl_khr_fp16

// Image read functions for read_write images
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
float4 __overload read_imagef(read_write image1d_t image, int coord);
int4 __overload read_imagei(read_write image1d_t image, int coord);
uint4 __overload read_imageui(read_write image1d_t image, int coord);

float4 __overload read_imagef(read_write image1d_buffer_t image, int coord);
int4 __overload read_imagei(read_write image1d_buffer_t image, int coord);
uint4 __overload read_imageui(read_write image1d_buffer_t image, int coord);

float4 __overload read_imagef(read_write image1d_array_t image, int2 coord);
int4 __overload read_imagei(read_write image1d_array_t image, int2 coord);
uint4 __overload read_imageui(read_write image1d_array_t image, int2 coord);

float4 __overload read_imagef(read_write image2d_t image, int2 coord);
int4 __overload read_imagei(read_write image2d_t image, int2 coord);
uint4 __overload read_imageui(read_write image2d_t image, int2 coord);

float4 __overload read_imagef(read_write image2d_array_t image, int4 coord);
int4 __overload read_imagei(read_write image2d_array_t image, int4 coord);
uint4 __overload read_imageui(read_write image2d_array_t image, int4 coord);

float4 __overload read_imagef(read_write image3d_t image, int4 coord);
int4 __overload read_imagei(read_write image3d_t image, int4 coord);
uint4 __overload read_imageui(read_write image3d_t image, int4 coord);

#ifdef cl_khr_depth_images
float __overload read_imagef(read_write image2d_depth_t image, int2 coord);
float __overload read_imagef(read_write image2d_array_depth_t image, int4 coord);
#endif //cl_khr_depth_images

#if cl_khr_gl_msaa_sharing
float4 __overload read_imagef(read_write image2d_msaa_t image, int2 coord, int sample);
int4 __overload read_imagei(read_write image2d_msaa_t image, int2 coord, int sample);
uint4 __overload read_imageui(read_write image2d_msaa_t image, int2 coord, int sample);

float4 __overload read_imagef(read_write image2d_array_msaa_t image, int4 coord, int sample);
int4 __overload read_imagei(read_write image2d_array_msaa_t image, int4 coord, int sample);
uint4 __overload read_imageui(read_write image2d_array_msaa_t image, int4 coord, int sample);

float __overload read_imagef(read_write image2d_msaa_depth_t image, int2 coord, int sample);
float __overload read_imagef(read_write image2d_array_msaa_depth_t image, int4 coord, int sample);
#endif //cl_khr_gl_msaa_sharing

#ifdef cl_khr_mipmap_image
float4 __overload read_imagef(read_write image1d_t image, sampler_t sampler, float coord, float lod);
int4 __overload read_imagei(read_write image1d_t image, sampler_t sampler, float coord, float lod);
uint4 __overload read_imageui(read_write image1d_t image, sampler_t sampler, float coord, float lod);

float4 __overload read_imagef(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_write image2d_t image, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_write image2d_t image, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_write image2d_t image, sampler_t sampler, float2 coord, float lod);

float __overload read_imagef(read_write image2d_depth_t image, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

float __overload read_imagef(read_write image2d_array_depth_t image, sampler_t sampler, float4 coord, float lod);

float4 __overload read_imagef(read_write image3d_t image, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_write image3d_t image, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_write image3d_t image, sampler_t sampler, float4 coord, float lod);

float4 __overload read_imagef(read_write image1d_t image, sampler_t sampler, float coord, float gradientX, float gradientY);
int4 __overload read_imagei(read_write image1d_t image, sampler_t sampler, float coord, float gradientX, float gradientY);
uint4 __overload read_imageui(read_write image1d_t image, sampler_t sampler, float coord, float gradientX, float gradientY);

float4 __overload read_imagef(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float gradientX, float gradientY);
int4 __overload read_imagei(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float gradientX, float gradientY);
uint4 __overload read_imageui(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float gradientX, float gradientY);

float4 __overload read_imagef(read_write image2d_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);
int4 __overload read_imagei(read_write image2d_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);
uint4 __overload read_imageui(read_write image2d_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);

float __overload read_imagef(read_write image2d_depth_t image, sampler_t sampler, float2 coord, float2 gradientX, float2 gradientY);

float4 __overload read_imagef(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);
int4 __overload read_imagei(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);
uint4 __overload read_imageui(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);

float __overload read_imagef(read_write image2d_array_depth_t image, sampler_t sampler, float4 coord, float2 gradientX, float2 gradientY);

float4 __overload read_imagef(read_write image3d_t image, sampler_t sampler, float4 coord, float4 gradientX, float4 gradientY);
int4 __overload read_imagei(read_write image3d_t image, sampler_t sampler, float4 coord, float4 gradientX, float4 gradientY);
uint4 __overload read_imageui(read_write image3d_t image, sampler_t sampler, float4 coord, float4 gradientX, float4 gradientY);

float4 __overload read_imagef(read_write image1d_t image, sampler_t sampler, float coord, float lod);
int4 __overload read_imagei(read_write image1d_t image, sampler_t sampler, float coord, float lod);
uint4 __overload read_imageui(read_write image1d_t image, sampler_t sampler, float coord, float lod);

float4 __overload read_imagef(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_write image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_write image2d_t image, sampler_t sampler, float2 coord, float lod);
int4 __overload read_imagei(read_write image2d_t image, sampler_t sampler, float2 coord, float lod);
uint4 __overload read_imageui(read_write image2d_t image, sampler_t sampler, float2 coord, float lod);

float __overload read_imagef(read_write image2d_depth_t image, sampler_t sampler, float2 coord, float lod);

float4 __overload read_imagef(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_write image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

float __overload read_imagef(read_write image2d_array_depth_t image, sampler_t sampler, float4 coord, float lod);

float4 __overload read_imagef(read_write image3d_t image, sampler_t sampler, float4 coord, float lod);
int4 __overload read_imagei(read_write image3d_t image, sampler_t sampler, float4 coord, float lod);
uint4 __overload read_imageui(read_write image3d_t image, sampler_t sampler, float4 coord, float lod);
#endif //cl_khr_mipmap_image

// Image read functions returning half4 type
#ifdef cl_khr_fp16
half4 __overload read_imageh(read_write image1d_t image, int coord);
half4 __overload read_imageh(read_write image2d_t image, int2 coord);
half4 __overload read_imageh(read_write image3d_t image, int4 coord);
half4 __overload read_imageh(read_write image1d_array_t image, int2 coord);
half4 __overload read_imageh(read_write image2d_array_t image, int4 coord);
half4 __overload read_imageh(read_write image1d_buffer_t image, int coord);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Write color value to location specified by coordinate
 * (coord.x, coord.y) in the 2D image object specified by image.
 * (coord.x, coord.y) are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1, and 0
 * ... image height - 1.

 * Write color value to location specified by coordinate
 * (coord.x, coord.y) in the 2D image object specified by index
 * (coord.z) of the 2D image array object image_array.
 * (coord.x, coord.y) are considered to be unnormalized
 * coordinates and must be in the range 0 ... image width
 * - 1.
 *
 * Write color value to location specified by coordinate
 * (coord) in the 1D image (buffer) object specified by image.
 * coord is considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1.
 *
 * Write color value to location specified by coordinate
 * (coord.x) in the 1D image object specified by index
 * (coord.y) of the 1D image array object image_array.
 * x is considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1.
 *
 * Write color value to location specified by coordinate
 * (coord.x, coord.y, coord.z) in the 3D image object specified by image.
 * coord.x & coord.y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1, and 0
 * ... image height - 1.
 *
 * For mipmap images, use mip-level specified by lod.
 *
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 *
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 *
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 *
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 *
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x, y) coordinate
 * values that are not in the range (0 ... image width -1,
 * 0 ... image height - 1), respectively, is undefined.
 */
void __overload write_imagef(write_only image2d_t image, int2 coord, float4 color);
void __overload write_imagei(write_only image2d_t image, int2 coord, int4 color);
void __overload write_imageui(write_only image2d_t image, int2 coord, uint4 color);

void __overload write_imagef(write_only image2d_array_t image_array, int4 coord, float4 color);
void __overload write_imagei(write_only image2d_array_t image_array, int4 coord, int4 color);
void __overload write_imageui(write_only image2d_array_t image_array, int4 coord, uint4 color);

void __overload write_imagef(write_only image1d_t image, int coord, float4 color);
void __overload write_imagei(write_only image1d_t image, int coord, int4 color);
void __overload write_imageui(write_only image1d_t image, int coord, uint4 color);

void __overload write_imagef(write_only image1d_buffer_t image, int coord, float4 color);
void __overload write_imagei(write_only image1d_buffer_t image, int coord, int4 color);
void __overload write_imageui(write_only image1d_buffer_t image, int coord, uint4 color);

void __overload write_imagef(write_only image1d_array_t image_array, int2 coord, float4 color);
void __overload write_imagei(write_only image1d_array_t image_array, int2 coord, int4 color);
void __overload write_imageui(write_only image1d_array_t image_array, int2 coord, uint4 color);

void __overload write_imagef(write_only image3d_t image, int4 coord, float4 color);
void __overload write_imagei(write_only image3d_t image, int4 coord, int4 color);
void __overload write_imageui(write_only image3d_t image, int4 coord, uint4 color);

#ifdef cl_khr_depth_images
void __overload write_imagef(write_only image2d_depth_t image, int2 coord, float color);
void __overload write_imagef(write_only image2d_array_depth_t image, int4 coord, float color);
#endif //cl_khr_depth_images

// OpenCL Extension v2.0 s9.18 - Mipmaps
#ifdef cl_khr_mipmap_image
void __overload write_imagef(write_only image1d_t image, int coord, int lod, float4 color);
void __overload write_imagei(write_only image1d_t image, int coord, int lod, int4 color);
void __overload write_imageui(write_only image1d_t image, int coord, int lod, uint4 color);

void __overload write_imagef(write_only image1d_array_t image_array, int2 coord, int lod, float4 color);
void __overload write_imagei(write_only image1d_array_t image_array, int2 coord, int lod, int4 color);
void __overload write_imageui(write_only image1d_array_t image_array, int2 coord, int lod, uint4 color);

void __overload write_imagef(write_only image2d_t image, int2 coord, int lod, float4 color);
void __overload write_imagei(write_only image2d_t image, int2 coord, int lod, int4 color);
void __overload write_imageui(write_only image2d_t image, int2 coord, int lod, uint4 color);

void __overload write_imagef(write_only image2d_array_t image_array, int4 coord, int lod, float4 color);
void __overload write_imagei(write_only image2d_array_t image_array, int4 coord, int lod, int4 color);
void __overload write_imageui(write_only image2d_array_t image_array, int4 coord, int lod, uint4 color);

void __overload write_imagef(write_only image2d_depth_t image, int2 coord, int lod, float color);
void __overload write_imagef(write_only image2d_array_depth_t image, int4 coord, int lod, float color);

void __overload write_imagef(write_only image3d_t image, int4 coord, int lod, float4 color);
void __overload write_imagei(write_only image3d_t image, int4 coord, int lod, int4 color);
void __overload write_imageui(write_only image3d_t image, int4 coord, int lod, uint4 color);
#endif //cl_khr_mipmap_image

// Image write functions for half4 type
#ifdef cl_khr_fp16
void __overload write_imageh(write_only image1d_t image, int coord, half4 color);
void __overload write_imageh(write_only image2d_t image, int2 coord, half4 color);
void __overload write_imageh(write_only image3d_t image, int4 coord, half4 color);
void __overload write_imageh(write_only image1d_array_t image, int2 coord, half4 color);
void __overload write_imageh(write_only image2d_array_t image, int4 coord, half4 color);
void __overload write_imageh(write_only image1d_buffer_t image, int coord, half4 color);
#endif //cl_khr_fp16

// Image write functions for read_write images
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
void __overload write_imagef(read_write image2d_t image, int2 coord, float4 color);
void __overload write_imagei(read_write image2d_t image, int2 coord, int4 color);
void __overload write_imageui(read_write image2d_t image, int2 coord, uint4 color);

void __overload write_imagef(read_write image2d_array_t image_array, int4 coord, float4 color);
void __overload write_imagei(read_write image2d_array_t image_array, int4 coord, int4 color);
void __overload write_imageui(read_write image2d_array_t image_array, int4 coord, uint4 color);

void __overload write_imagef(read_write image1d_t image, int coord, float4 color);
void __overload write_imagei(read_write image1d_t image, int coord, int4 color);
void __overload write_imageui(read_write image1d_t image, int coord, uint4 color);

void __overload write_imagef(read_write image1d_buffer_t image, int coord, float4 color);
void __overload write_imagei(read_write image1d_buffer_t image, int coord, int4 color);
void __overload write_imageui(read_write image1d_buffer_t image, int coord, uint4 color);

void __overload write_imagef(read_write image1d_array_t image_array, int2 coord, float4 color);
void __overload write_imagei(read_write image1d_array_t image_array, int2 coord, int4 color);
void __overload write_imageui(read_write image1d_array_t image_array, int2 coord, uint4 color);

void __overload write_imagef(read_write image3d_t image, int4 coord, float4 color);
void __overload write_imagei(read_write image3d_t image, int4 coord, int4 color);
void __overload write_imageui(read_write image3d_t image, int4 coord, uint4 color);

#ifdef cl_khr_depth_images
void __overload write_imagef(read_write image2d_depth_t image, int2 coord, float color);
void __overload write_imagef(read_write image2d_array_depth_t image, int4 coord, float color);
#endif //cl_khr_depth_images

#ifdef cl_khr_mipmap_image
void __overload write_imagef(read_write image1d_t image, int coord, int lod, float4 color);
void __overload write_imagei(read_write image1d_t image, int coord, int lod, int4 color);
void __overload write_imageui(read_write image1d_t image, int coord, int lod, uint4 color);

void __overload write_imagef(read_write image1d_array_t image_array, int2 coord, int lod, float4 color);
void __overload write_imagei(read_write image1d_array_t image_array, int2 coord, int lod, int4 color);
void __overload write_imageui(read_write image1d_array_t image_array, int2 coord, int lod, uint4 color);

void __overload write_imagef(read_write image2d_t image, int2 coord, int lod, float4 color);
void __overload write_imagei(read_write image2d_t image, int2 coord, int lod, int4 color);
void __overload write_imageui(read_write image2d_t image, int2 coord, int lod, uint4 color);

void __overload write_imagef(read_write image2d_array_t image_array, int4 coord, int lod, float4 color);
void __overload write_imagei(read_write image2d_array_t image_array, int4 coord, int lod, int4 color);
void __overload write_imageui(read_write image2d_array_t image_array, int4 coord, int lod, uint4 color);

void __overload write_imagef(read_write image2d_depth_t image, int2 coord, int lod, float color);
void __overload write_imagef(read_write image2d_array_depth_t image, int4 coord, int lod, float color);

void __overload write_imagef(read_write image3d_t image, int4 coord, int lod, float4 color);
void __overload write_imagei(read_write image3d_t image, int4 coord, int lod, int4 color);
void __overload write_imageui(read_write image3d_t image, int4 coord, int lod, uint4 color);
#endif //cl_khr_mipmap_image

// Image write functions for half4 type
#ifdef cl_khr_fp16
void __overload write_imageh(read_write image1d_t image, int coord, half4 color);
void __overload write_imageh(read_write image2d_t image, int2 coord, half4 color);
void __overload write_imageh(read_write image3d_t image, int4 coord, half4 color);
void __overload write_imageh(read_write image1d_array_t image, int2 coord, half4 color);
void __overload write_imageh(read_write image2d_array_t image, int4 coord, half4 color);
void __overload write_imageh(read_write image1d_buffer_t image, int coord, half4 color);
#endif //cl_khr_fp16
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// Note: In OpenCL v1.0/1.1/1.2, image argument of image query builtin functions does not have
// access qualifier, which by default assume read_only access qualifier. Image query builtin
// functions with write_only image argument should also be declared.

/**
 * Return the image width in pixels.
 *
  */
int __const_func get_image_width(read_only image1d_t image);
int __const_func get_image_width(read_only image1d_buffer_t image);
int __const_func get_image_width(read_only image2d_t image);
int __const_func get_image_width(read_only image3d_t image);
int __const_func get_image_width(read_only image1d_array_t image);
int __const_func get_image_width(read_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_width(read_only image2d_depth_t image);
int __const_func get_image_width(read_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_width(read_only image2d_msaa_t image);
int __const_func get_image_width(read_only image2d_msaa_depth_t image);
int __const_func get_image_width(read_only image2d_array_msaa_t image);
int __const_func get_image_width(read_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

int __const_func get_image_width(write_only image1d_t image);
int __const_func get_image_width(write_only image1d_buffer_t image);
int __const_func get_image_width(write_only image2d_t image);
int __const_func get_image_width(write_only image3d_t image);
int __const_func get_image_width(write_only image1d_array_t image);
int __const_func get_image_width(write_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_width(write_only image2d_depth_t image);
int __const_func get_image_width(write_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_width(write_only image2d_msaa_t image);
int __const_func get_image_width(write_only image2d_msaa_depth_t image);
int __const_func get_image_width(write_only image2d_array_msaa_t image);
int __const_func get_image_width(write_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __const_func get_image_width(read_write image1d_t image);
int __const_func get_image_width(read_write image1d_buffer_t image);
int __const_func get_image_width(read_write image2d_t image);
int __const_func get_image_width(read_write image3d_t image);
int __const_func get_image_width(read_write image1d_array_t image);
int __const_func get_image_width(read_write image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_width(read_write image2d_depth_t image);
int __const_func get_image_width(read_write image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_width(read_write image2d_msaa_t image);
int __const_func get_image_width(read_write image2d_msaa_depth_t image);
int __const_func get_image_width(read_write image2d_array_msaa_t image);
int __const_func get_image_width(read_write image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Return the image height in pixels.
 */
int __const_func get_image_height(read_only image2d_t image);
int __const_func get_image_height(read_only image3d_t image);
int __const_func get_image_height(read_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_height(read_only image2d_depth_t image);
int __const_func get_image_height(read_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_height(read_only image2d_msaa_t image);
int __const_func get_image_height(read_only image2d_msaa_depth_t image);
int __const_func get_image_height(read_only image2d_array_msaa_t image);
int __const_func get_image_height(read_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

int __const_func get_image_height(write_only image2d_t image);
int __const_func get_image_height(write_only image3d_t image);
int __const_func get_image_height(write_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_height(write_only image2d_depth_t image);
int __const_func get_image_height(write_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_height(write_only image2d_msaa_t image);
int __const_func get_image_height(write_only image2d_msaa_depth_t image);
int __const_func get_image_height(write_only image2d_array_msaa_t image);
int __const_func get_image_height(write_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __const_func get_image_height(read_write image2d_t image);
int __const_func get_image_height(read_write image3d_t image);
int __const_func get_image_height(read_write image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_height(read_write image2d_depth_t image);
int __const_func get_image_height(read_write image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_height(read_write image2d_msaa_t image);
int __const_func get_image_height(read_write image2d_msaa_depth_t image);
int __const_func get_image_height(read_write image2d_array_msaa_t image);
int __const_func get_image_height(read_write image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Return the image depth in pixels.
 */
int __const_func get_image_depth(read_only image3d_t image);

int __const_func get_image_depth(write_only image3d_t image);

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __const_func get_image_depth(read_write image3d_t image);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL Extension v2.0 s9.18 - Mipmaps
#ifdef cl_khr_mipmap_image
/**
 * Return the image miplevels.
 */

int __overload get_image_num_mip_levels(read_only image1d_t image);
int __overload get_image_num_mip_levels(read_only image2d_t image);
int __overload get_image_num_mip_levels(read_only image3d_t image);

int __overload get_image_num_mip_levels(write_only image1d_t image);
int __overload get_image_num_mip_levels(write_only image2d_t image);
int __overload get_image_num_mip_levels(write_only image3d_t image);

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __overload get_image_num_mip_levels(read_write image1d_t image);
int __overload get_image_num_mip_levels(read_write image2d_t image);
int __overload get_image_num_mip_levels(read_write image3d_t image);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

int __overload get_image_num_mip_levels(read_only image1d_array_t image);
int __overload get_image_num_mip_levels(read_only image2d_array_t image);
int __overload get_image_num_mip_levels(read_only image2d_array_depth_t image);
int __overload get_image_num_mip_levels(read_only image2d_depth_t image);

int __overload get_image_num_mip_levels(write_only image1d_array_t image);
int __overload get_image_num_mip_levels(write_only image2d_array_t image);
int __overload get_image_num_mip_levels(write_only image2d_array_depth_t image);
int __overload get_image_num_mip_levels(write_only image2d_depth_t image);

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __overload get_image_num_mip_levels(read_write image1d_array_t image);
int __overload get_image_num_mip_levels(read_write image2d_array_t image);
int __overload get_image_num_mip_levels(read_write image2d_array_depth_t image);
int __overload get_image_num_mip_levels(read_write image2d_depth_t image);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

#endif //cl_khr_mipmap_image

/**
 * Return the channel data type. Valid values are:
 * CLK_SNORM_INT8
 * CLK_SNORM_INT16
 * CLK_UNORM_INT8
 * CLK_UNORM_INT16
 * CLK_UNORM_SHORT_565
 * CLK_UNORM_SHORT_555
 * CLK_UNORM_SHORT_101010
 * CLK_SIGNED_INT8
 * CLK_SIGNED_INT16
 * CLK_SIGNED_INT32
 * CLK_UNSIGNED_INT8
 * CLK_UNSIGNED_INT16
 * CLK_UNSIGNED_INT32
 * CLK_HALF_FLOAT
 * CLK_FLOAT
 */

//
// Channel Datatype.
//
#define CLK_SNORM_INT8        0x10D0
#define CLK_SNORM_INT16       0x10D1
#define CLK_UNORM_INT8        0x10D2
#define CLK_UNORM_INT16       0x10D3
#define CLK_UNORM_SHORT_565   0x10D4
#define CLK_UNORM_SHORT_555   0x10D5
#define CLK_UNORM_INT_101010  0x10D6
#define CLK_SIGNED_INT8       0x10D7
#define CLK_SIGNED_INT16      0x10D8
#define CLK_SIGNED_INT32      0x10D9
#define CLK_UNSIGNED_INT8     0x10DA
#define CLK_UNSIGNED_INT16    0x10DB
#define CLK_UNSIGNED_INT32    0x10DC
#define CLK_HALF_FLOAT        0x10DD
#define CLK_FLOAT             0x10DE
#define CLK_UNORM_INT24       0x10DF

int __const_func get_image_channel_data_type(read_only image1d_t image);
int __const_func get_image_channel_data_type(read_only image1d_buffer_t image);
int __const_func get_image_channel_data_type(read_only image2d_t image);
int __const_func get_image_channel_data_type(read_only image3d_t image);
int __const_func get_image_channel_data_type(read_only image1d_array_t image);
int __const_func get_image_channel_data_type(read_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_channel_data_type(read_only image2d_depth_t image);
int __const_func get_image_channel_data_type(read_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_channel_data_type(read_only image2d_msaa_t image);
int __const_func get_image_channel_data_type(read_only image2d_msaa_depth_t image);
int __const_func get_image_channel_data_type(read_only image2d_array_msaa_t image);
int __const_func get_image_channel_data_type(read_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

int __const_func get_image_channel_data_type(write_only image1d_t image);
int __const_func get_image_channel_data_type(write_only image1d_buffer_t image);
int __const_func get_image_channel_data_type(write_only image2d_t image);
int __const_func get_image_channel_data_type(write_only image3d_t image);
int __const_func get_image_channel_data_type(write_only image1d_array_t image);
int __const_func get_image_channel_data_type(write_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_channel_data_type(write_only image2d_depth_t image);
int __const_func get_image_channel_data_type(write_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_channel_data_type(write_only image2d_msaa_t image);
int __const_func get_image_channel_data_type(write_only image2d_msaa_depth_t image);
int __const_func get_image_channel_data_type(write_only image2d_array_msaa_t image);
int __const_func get_image_channel_data_type(write_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __const_func get_image_channel_data_type(read_write image1d_t image);
int __const_func get_image_channel_data_type(read_write image1d_buffer_t image);
int __const_func get_image_channel_data_type(read_write image2d_t image);
int __const_func get_image_channel_data_type(read_write image3d_t image);
int __const_func get_image_channel_data_type(read_write image1d_array_t image);
int __const_func get_image_channel_data_type(read_write image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_channel_data_type(read_write image2d_depth_t image);
int __const_func get_image_channel_data_type(read_write image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_channel_data_type(read_write image2d_msaa_t image);
int __const_func get_image_channel_data_type(read_write image2d_msaa_depth_t image);
int __const_func get_image_channel_data_type(read_write image2d_array_msaa_t image);
int __const_func get_image_channel_data_type(read_write image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Return the image channel order. Valid values are:
 * CLK_A
 * CLK_R
 * CLK_Rx
 * CLK_RG
 * CLK_RGx
 * CLK_RA
 * CLK_RGB
 * CLK_RGBx
 * CLK_RGBA
 * CLK_ARGB
 * CLK_BGRA
 * CLK_INTENSITY
 * CLK_LUMINANCE
 */
// Channel order, numbering must be aligned with cl_channel_order in cl.h
//
#define CLK_R         0x10B0
#define CLK_A         0x10B1
#define CLK_RG        0x10B2
#define CLK_RA        0x10B3
#define CLK_RGB       0x10B4
#define CLK_RGBA      0x10B5
#define CLK_BGRA      0x10B6
#define CLK_ARGB      0x10B7
#define CLK_INTENSITY 0x10B8
#define CLK_LUMINANCE 0x10B9
#define CLK_Rx                0x10BA
#define CLK_RGx               0x10BB
#define CLK_RGBx              0x10BC
#define CLK_DEPTH             0x10BD
#define CLK_DEPTH_STENCIL     0x10BE
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
#define CLK_sRGB              0x10BF
#define CLK_sRGBA             0x10C1
#define CLK_sRGBx             0x10C0
#define CLK_sBGRA             0x10C2
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

int __const_func get_image_channel_order(read_only image1d_t image);
int __const_func get_image_channel_order(read_only image1d_buffer_t image);
int __const_func get_image_channel_order(read_only image2d_t image);
int __const_func get_image_channel_order(read_only image3d_t image);
int __const_func get_image_channel_order(read_only image1d_array_t image);
int __const_func get_image_channel_order(read_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_channel_order(read_only image2d_depth_t image);
int __const_func get_image_channel_order(read_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_channel_order(read_only image2d_msaa_t image);
int __const_func get_image_channel_order(read_only image2d_msaa_depth_t image);
int __const_func get_image_channel_order(read_only image2d_array_msaa_t image);
int __const_func get_image_channel_order(read_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

int __const_func get_image_channel_order(write_only image1d_t image);
int __const_func get_image_channel_order(write_only image1d_buffer_t image);
int __const_func get_image_channel_order(write_only image2d_t image);
int __const_func get_image_channel_order(write_only image3d_t image);
int __const_func get_image_channel_order(write_only image1d_array_t image);
int __const_func get_image_channel_order(write_only image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_channel_order(write_only image2d_depth_t image);
int __const_func get_image_channel_order(write_only image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_channel_order(write_only image2d_msaa_t image);
int __const_func get_image_channel_order(write_only image2d_msaa_depth_t image);
int __const_func get_image_channel_order(write_only image2d_array_msaa_t image);
int __const_func get_image_channel_order(write_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __const_func get_image_channel_order(read_write image1d_t image);
int __const_func get_image_channel_order(read_write image1d_buffer_t image);
int __const_func get_image_channel_order(read_write image2d_t image);
int __const_func get_image_channel_order(read_write image3d_t image);
int __const_func get_image_channel_order(read_write image1d_array_t image);
int __const_func get_image_channel_order(read_write image2d_array_t image);
#ifdef cl_khr_depth_images
int __const_func get_image_channel_order(read_write image2d_depth_t image);
int __const_func get_image_channel_order(read_write image2d_array_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int __const_func get_image_channel_order(read_write image2d_msaa_t image);
int __const_func get_image_channel_order(read_write image2d_msaa_depth_t image);
int __const_func get_image_channel_order(read_write image2d_array_msaa_t image);
int __const_func get_image_channel_order(read_write image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Return the 2D image width and height as an int2
 * type. The width is returned in the x component, and
 * the height in the y component.
 */
int2 __const_func get_image_dim(read_only image2d_t image);
int2 __const_func get_image_dim(read_only image2d_array_t image);
#ifdef cl_khr_depth_images
int2 __const_func get_image_dim(read_only image2d_array_depth_t image);
int2 __const_func get_image_dim(read_only image2d_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int2 __const_func get_image_dim(read_only image2d_msaa_t image);
int2 __const_func get_image_dim(read_only image2d_msaa_depth_t image);
int2 __const_func get_image_dim(read_only image2d_array_msaa_t image);
int2 __const_func get_image_dim(read_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

int2 __const_func get_image_dim(write_only image2d_t image);
int2 __const_func get_image_dim(write_only image2d_array_t image);
#ifdef cl_khr_depth_images
int2 __const_func get_image_dim(write_only image2d_array_depth_t image);
int2 __const_func get_image_dim(write_only image2d_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int2 __const_func get_image_dim(write_only image2d_msaa_t image);
int2 __const_func get_image_dim(write_only image2d_msaa_depth_t image);
int2 __const_func get_image_dim(write_only image2d_array_msaa_t image);
int2 __const_func get_image_dim(write_only image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int2 __const_func get_image_dim(read_write image2d_t image);
int2 __const_func get_image_dim(read_write image2d_array_t image);
#ifdef cl_khr_depth_images
int2 __const_func get_image_dim(read_write image2d_array_depth_t image);
int2 __const_func get_image_dim(read_write image2d_depth_t image);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
int2 __const_func get_image_dim(read_write image2d_msaa_t image);
int2 __const_func get_image_dim(read_write image2d_msaa_depth_t image);
int2 __const_func get_image_dim(read_write image2d_array_msaa_t image);
int2 __const_func get_image_dim(read_write image2d_array_msaa_depth_t image);
#endif //cl_khr_gl_msaa_sharing
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Return the 3D image width, height, and depth as an
 * int4 type. The width is returned in the x
 * component, height in the y component, depth in the z
 * component and the w component is 0.
 */
int4 __const_func get_image_dim(read_only image3d_t image);
int4 __const_func get_image_dim(write_only image3d_t image);
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int4 __const_func get_image_dim(read_write image3d_t image);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
 * Return the image array size.
 */

size_t __const_func get_image_array_size(read_only image1d_array_t image_array);
size_t __const_func get_image_array_size(read_only image2d_array_t image_array);
#ifdef cl_khr_depth_images
size_t __const_func get_image_array_size(read_only image2d_array_depth_t image_array);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
size_t __const_func get_image_array_size(read_only image2d_array_msaa_t image_array);
size_t __const_func get_image_array_size(read_only image2d_array_msaa_depth_t image_array);
#endif //cl_khr_gl_msaa_sharing

size_t __const_func get_image_array_size(write_only image1d_array_t image_array);
size_t __const_func get_image_array_size(write_only image2d_array_t image_array);
#ifdef cl_khr_depth_images
size_t __const_func get_image_array_size(write_only image2d_array_depth_t image_array);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
size_t __const_func get_image_array_size(write_only image2d_array_msaa_t image_array);
size_t __const_func get_image_array_size(write_only image2d_array_msaa_depth_t image_array);
#endif //cl_khr_gl_msaa_sharing

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
size_t __const_func get_image_array_size(read_write image1d_array_t image_array);
size_t __const_func get_image_array_size(read_write image2d_array_t image_array);
#ifdef cl_khr_depth_images
size_t __const_func get_image_array_size(read_write image2d_array_depth_t image_array);
#endif //cl_khr_depth_images
#if defined(cl_khr_gl_msaa_sharing)
size_t __const_func get_image_array_size(read_write image2d_array_msaa_t image_array);
size_t __const_func get_image_array_size(read_write image2d_array_msaa_depth_t image_array);
#endif //cl_khr_gl_msaa_sharing
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

/**
* Return the number of samples associated with image
*/
#if defined(cl_khr_gl_msaa_sharing)
int __overload get_image_num_samples(read_only image2d_msaa_t image);
int __overload get_image_num_samples(read_only image2d_msaa_depth_t image);
int __overload get_image_num_samples(read_only image2d_array_msaa_depth_t image);
int __overload get_image_num_samples(read_only image2d_array_msaa_t image);
int __overload get_image_num_samples(read_only image2d_array_msaa_depth_t image);

int __overload get_image_num_samples(write_only image2d_msaa_t image);
int __overload get_image_num_samples(write_only image2d_msaa_depth_t image);
int __overload get_image_num_samples(write_only image2d_array_msaa_depth_t image);
int __overload get_image_num_samples(write_only image2d_array_msaa_t image);
int __overload get_image_num_samples(write_only image2d_array_msaa_depth_t image);

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __overload get_image_num_samples(read_write image2d_msaa_t image);
int __overload get_image_num_samples(read_write image2d_msaa_depth_t image);
int __overload get_image_num_samples(read_write image2d_array_msaa_depth_t image);
int __overload get_image_num_samples(read_write image2d_array_msaa_t image);
int __overload get_image_num_samples(read_write image2d_array_msaa_depth_t image);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0
#endif

// OpenCL v2.0 s6.13.15 - Work-group Functions

#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
int __overload work_group_all(int predicate);
int __overload work_group_any(int predicate);

#ifdef cl_khr_fp16
half __overload work_group_broadcast(half a, size_t local_id);
half __overload work_group_broadcast(half a, size_t x, size_t y);
half __overload work_group_broadcast(half a, size_t x, size_t y, size_t z);
#endif
int __overload work_group_broadcast(int a, size_t local_id);
int __overload work_group_broadcast(int a, size_t x, size_t y);
int __overload work_group_broadcast(int a, size_t x, size_t y, size_t z);
uint __overload work_group_broadcast(uint a, size_t local_id);
uint __overload work_group_broadcast(uint a, size_t x, size_t y);
uint __overload work_group_broadcast(uint a, size_t x, size_t y, size_t z);
long __overload work_group_broadcast(long a, size_t local_id);
long __overload work_group_broadcast(long a, size_t x, size_t y);
long __overload work_group_broadcast(long a, size_t x, size_t y, size_t z);
ulong __overload work_group_broadcast(ulong a, size_t local_id);
ulong __overload work_group_broadcast(ulong a, size_t x, size_t y);
ulong __overload work_group_broadcast(ulong a, size_t x, size_t y, size_t z);
float __overload work_group_broadcast(float a, size_t local_id);
float __overload work_group_broadcast(float a, size_t x, size_t y);
float __overload work_group_broadcast(float a, size_t x, size_t y, size_t z);
#ifdef cl_khr_fp64
double __overload work_group_broadcast(double a, size_t local_id);
double __overload work_group_broadcast(double a, size_t x, size_t y);
double __overload work_group_broadcast(double a, size_t x, size_t y, size_t z);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half __overload work_group_reduce_add(half x);
half __overload work_group_reduce_min(half x);
half __overload work_group_reduce_max(half x);
half __overload work_group_scan_exclusive_add(half x);
half __overload work_group_scan_exclusive_min(half x);
half __overload work_group_scan_exclusive_max(half x);
half __overload work_group_scan_inclusive_add(half x);
half __overload work_group_scan_inclusive_min(half x);
half __overload work_group_scan_inclusive_max(half x);
#endif
int __overload work_group_reduce_add(int x);
int __overload work_group_reduce_min(int x);
int __overload work_group_reduce_max(int x);
int __overload work_group_scan_exclusive_add(int x);
int __overload work_group_scan_exclusive_min(int x);
int __overload work_group_scan_exclusive_max(int x);
int __overload work_group_scan_inclusive_add(int x);
int __overload work_group_scan_inclusive_min(int x);
int __overload work_group_scan_inclusive_max(int x);
uint __overload work_group_reduce_add(uint x);
uint __overload work_group_reduce_min(uint x);
uint __overload work_group_reduce_max(uint x);
uint __overload work_group_scan_exclusive_add(uint x);
uint __overload work_group_scan_exclusive_min(uint x);
uint __overload work_group_scan_exclusive_max(uint x);
uint __overload work_group_scan_inclusive_add(uint x);
uint __overload work_group_scan_inclusive_min(uint x);
uint __overload work_group_scan_inclusive_max(uint x);
long __overload work_group_reduce_add(long x);
long __overload work_group_reduce_min(long x);
long __overload work_group_reduce_max(long x);
long __overload work_group_scan_exclusive_add(long x);
long __overload work_group_scan_exclusive_min(long x);
long __overload work_group_scan_exclusive_max(long x);
long __overload work_group_scan_inclusive_add(long x);
long __overload work_group_scan_inclusive_min(long x);
long __overload work_group_scan_inclusive_max(long x);
ulong __overload work_group_reduce_add(ulong x);
ulong __overload work_group_reduce_min(ulong x);
ulong __overload work_group_reduce_max(ulong x);
ulong __overload work_group_scan_exclusive_add(ulong x);
ulong __overload work_group_scan_exclusive_min(ulong x);
ulong __overload work_group_scan_exclusive_max(ulong x);
ulong __overload work_group_scan_inclusive_add(ulong x);
ulong __overload work_group_scan_inclusive_min(ulong x);
ulong __overload work_group_scan_inclusive_max(ulong x);
float __overload work_group_reduce_add(float x);
float __overload work_group_reduce_min(float x);
float __overload work_group_reduce_max(float x);
float __overload work_group_scan_exclusive_add(float x);
float __overload work_group_scan_exclusive_min(float x);
float __overload work_group_scan_exclusive_max(float x);
float __overload work_group_scan_inclusive_add(float x);
float __overload work_group_scan_inclusive_min(float x);
float __overload work_group_scan_inclusive_max(float x);
#ifdef cl_khr_fp64
double __overload work_group_reduce_add(double x);
double __overload work_group_reduce_min(double x);
double __overload work_group_reduce_max(double x);
double __overload work_group_scan_exclusive_add(double x);
double __overload work_group_scan_exclusive_min(double x);
double __overload work_group_scan_exclusive_max(double x);
double __overload work_group_scan_inclusive_add(double x);
double __overload work_group_scan_inclusive_min(double x);
double __overload work_group_scan_inclusive_max(double x);
#endif //cl_khr_fp64

#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL v2.0 s6.13.16 - Pipe Functions
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
#define PIPE_RESERVE_ID_VALID_BIT (1U << 30)
#define CLK_NULL_RESERVE_ID (__builtin_astype(((void*)(__SIZE_MAX__)), reserve_id_t))
bool __overload is_valid_reserve_id(reserve_id_t reserve_id);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0


// OpenCL v2.0 s6.13.17 - Enqueue Kernels
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0

#define CL_COMPLETE                                 0x0
#define CL_RUNNING                                  0x1
#define CL_SUBMITTED                                0x2
#define CL_QUEUED                                   0x3

// The value are defined according to their order in the spec.
#define CLK_SUCCESS                                 0
#define CLK_ENQUEUE_FAILURE                         -1
#define CLK_INVALID_QUEUE                           -2
#define CLK_INVALID_NDRANGE                         -3
#define CLK_INVALID_EVENT_WAIT_LIST                 -4
#define CLK_DEVICE_QUEUE_FULL                       -5
#define CLK_INVALID_ARG_SIZE                        -6
#define CLK_EVENT_ALLOCATION_FAILURE                -8
#define CLK_OUT_OF_RESOURCES                        -9

#define CLK_NULL_QUEUE                              0
#define CLK_NULL_EVENT (__builtin_astype(((void*)(__SIZE_MAX__)), clk_event_t))

// execution model related definitions
#define CLK_ENQUEUE_FLAGS_NO_WAIT                   0x0
#define CLK_ENQUEUE_FLAGS_WAIT_KERNEL               0x1
#define CLK_ENQUEUE_FLAGS_WAIT_WORK_GROUP           0x2

typedef int kernel_enqueue_flags_t;
typedef int clk_profiling_info;

// Profiling info name (see capture_event_profiling_info)
#define CLK_PROFILING_COMMAND_EXEC_TIME 0x1

#define MAX_WORK_DIM        3

// ToDo: Remove definition of ndrange_t in Clang as an opaque type and add back
// the following ndrange_t definition.
#if 0
typedef struct {
    unsigned int workDimension;
    size_t globalWorkOffset[MAX_WORK_DIM];
    size_t globalWorkSize[MAX_WORK_DIM];
    size_t localWorkSize[MAX_WORK_DIM];
} ndrange_t;
#endif

ndrange_t __overload ndrange_1D(size_t);
ndrange_t __overload ndrange_1D(size_t, size_t);
ndrange_t __overload ndrange_1D(size_t, size_t, size_t);

ndrange_t __overload ndrange_2D(const size_t[2]);
ndrange_t __overload ndrange_2D(const size_t[2], const size_t[2]);
ndrange_t __overload ndrange_2D(const size_t[2], const size_t[2], const size_t[2]);

ndrange_t __overload ndrange_3D(const size_t[3]);
ndrange_t __overload ndrange_3D(const size_t[3], const size_t[3]);
ndrange_t __overload ndrange_3D(const size_t[3], const size_t[3], const size_t[3]);

// ToDo: Add these functions as Clang builtins since they eed a special check of parameters to block.
uint __overload get_kernel_work_group_size(void (^block)(void));
uint __overload get_kernel_work_group_size(void (^block)(local void *, ...));
uint __overload get_kernel_preferred_work_group_size_multiple(void (^block)(void));
uint __overload get_kernel_preferred_work_group_size_multiple(void (^block)(local void *, ...));

int __overload enqueue_marker(queue_t, uint, const __private clk_event_t*, __private clk_event_t*);

void __overload retain_event(clk_event_t);

void __overload release_event(clk_event_t);

clk_event_t create_user_event(void);

void __overload set_user_event_status(clk_event_t e, int state);

bool is_valid_event (clk_event_t event);

void __overload capture_event_profiling_info(clk_event_t, clk_profiling_info, __global void* value);

queue_t __overload get_default_queue(void);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

// OpenCL Extension v2.0 s9.17 - Sub-groups

#if defined(cl_intel_subgroups) || defined(cl_khr_subgroups)
// Shared Sub Group Functions
uint    __overload get_sub_group_size(void);
uint    __overload get_max_sub_group_size(void);
uint    __overload get_num_sub_groups(void);
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
uint    __overload get_enqueued_num_sub_groups(void);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0
uint    __overload get_sub_group_id(void);
uint    __overload get_sub_group_local_id(void);

void    __overload sub_group_barrier(cl_mem_fence_flags flags);
#if __OPENCL_C_VERSION__ >= CL_VERSION_2_0
void    __overload sub_group_barrier(cl_mem_fence_flags flags, memory_scope scope);
#endif //__OPENCL_C_VERSION__ >= CL_VERSION_2_0

int     __overload sub_group_all(int predicate);
int     __overload sub_group_any(int predicate);

int     __overload sub_group_broadcast(int   x, uint sub_group_local_id);
uint    __overload sub_group_broadcast(uint  x, uint sub_group_local_id);
long    __overload sub_group_broadcast(long  x, uint sub_group_local_id);
ulong   __overload sub_group_broadcast(ulong x, uint sub_group_local_id);
float   __overload sub_group_broadcast(float x, uint sub_group_local_id);

int     __overload sub_group_reduce_add(int   x);
uint    __overload sub_group_reduce_add(uint  x);
long    __overload sub_group_reduce_add(long  x);
ulong   __overload sub_group_reduce_add(ulong x);
float   __overload sub_group_reduce_add(float x);
int     __overload sub_group_reduce_min(int   x);
uint    __overload sub_group_reduce_min(uint  x);
long    __overload sub_group_reduce_min(long  x);
ulong   __overload sub_group_reduce_min(ulong x);
float   __overload sub_group_reduce_min(float x);
int     __overload sub_group_reduce_max(int   x);
uint    __overload sub_group_reduce_max(uint  x);
long    __overload sub_group_reduce_max(long  x);
ulong   __overload sub_group_reduce_max(ulong x);
float   __overload sub_group_reduce_max(float x);

int     __overload sub_group_scan_exclusive_add(int   x);
uint    __overload sub_group_scan_exclusive_add(uint  x);
long    __overload sub_group_scan_exclusive_add(long  x);
ulong   __overload sub_group_scan_exclusive_add(ulong x);
float   __overload sub_group_scan_exclusive_add(float x);
int     __overload sub_group_scan_exclusive_min(int   x);
uint    __overload sub_group_scan_exclusive_min(uint  x);
long    __overload sub_group_scan_exclusive_min(long  x);
ulong   __overload sub_group_scan_exclusive_min(ulong x);
float   __overload sub_group_scan_exclusive_min(float x);
int     __overload sub_group_scan_exclusive_max(int   x);
uint    __overload sub_group_scan_exclusive_max(uint  x);
long    __overload sub_group_scan_exclusive_max(long  x);
ulong   __overload sub_group_scan_exclusive_max(ulong x);
float   __overload sub_group_scan_exclusive_max(float x);

int     __overload sub_group_scan_inclusive_add(int   x);
uint    __overload sub_group_scan_inclusive_add(uint  x);
long    __overload sub_group_scan_inclusive_add(long  x);
ulong   __overload sub_group_scan_inclusive_add(ulong x);
float   __overload sub_group_scan_inclusive_add(float x);
int     __overload sub_group_scan_inclusive_min(int   x);
uint    __overload sub_group_scan_inclusive_min(uint  x);
long    __overload sub_group_scan_inclusive_min(long  x);
ulong   __overload sub_group_scan_inclusive_min(ulong x);
float   __overload sub_group_scan_inclusive_min(float x);
int     __overload sub_group_scan_inclusive_max(int   x);
uint    __overload sub_group_scan_inclusive_max(uint  x);
long    __overload sub_group_scan_inclusive_max(long  x);
ulong   __overload sub_group_scan_inclusive_max(ulong x);
float   __overload sub_group_scan_inclusive_max(float x);

#ifdef cl_khr_fp16
half    __overload sub_group_broadcast(half x, uint sub_group_local_id);
half    __overload sub_group_reduce_add(half x);
half    __overload sub_group_reduce_min(half x);
half    __overload sub_group_reduce_max(half x);
half    __overload sub_group_scan_exclusive_add(half x);
half    __overload sub_group_scan_exclusive_min(half x);
half    __overload sub_group_scan_exclusive_max(half x);
half    __overload sub_group_scan_inclusive_add(half x);
half    __overload sub_group_scan_inclusive_min(half x);
half    __overload sub_group_scan_inclusive_max(half x);
#endif //cl_khr_fp16

#ifdef cl_khr_fp64
double  __overload sub_group_broadcast(double x, uint sub_group_local_id);
double  __overload sub_group_reduce_add(double x);
double  __overload sub_group_reduce_min(double x);
double  __overload sub_group_reduce_max(double x);
double  __overload sub_group_scan_exclusive_add(double x);
double  __overload sub_group_scan_exclusive_min(double x);
double  __overload sub_group_scan_exclusive_max(double x);
double  __overload sub_group_scan_inclusive_add(double x);
double  __overload sub_group_scan_inclusive_min(double x);
double  __overload sub_group_scan_inclusive_max(double x);
#endif //cl_khr_fp64

#endif //cl_khr_subgroups cl_intel_subgroups

// Disable any extensions we may have enabled previously.
#pragma OPENCL EXTENSION all : disable

#endif //_OPENCL_H_