// RUN: %clang_cc1 -emit-pch -o %t %s -triple spir-unknown-unknown
// RUN: %clang_cc1 -include-pch %t -fsyntax-only %s  -triple spir-unknown-unknown

#ifndef HEADER
#define HEADER
// Header.

#pragma OPENCL EXTENSION cl_khr_fp64 : enable
#pragma OPENCL EXTENSION my_ext_example : register

#else
// Using the header.

#pragma OPENCL EXTENSION my_extension : enable

void test(void) {
  double d;
}

#endif
