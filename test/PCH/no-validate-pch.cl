// RUN: %clang_cc1 -emit-pch -D TWO=2 -D X=4 -o %t %s -triple spir-unknown-unknown
// RUN: %clang_cc1 -include-pch %t -D THREE=3 -D X=5 -O0 -fno-validate-pch -fsyntax-only %s -triple spir-unknown-unknown
// RUN: not %clang_cc1 -include-pch %t -D THREE=3 -D X=5 -D VALIDATE -O0 -fsyntax-only %s -triple spir-unknown-unknown

#ifndef HEADER
#define HEADER
// Header.

#define ONE 1

#else
// Using the header.

void test(void) {
  int a = ONE;
  int b = TWO;
  int c = THREE;

#ifndef VALIDATE
#if X != 5
#error Definition of X is not overridden!
#endif

#ifdef __OPTIMIZE__
#error Optimization is not off!
#endif
#endif

}

#endif
