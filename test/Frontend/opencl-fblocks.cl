// RUN: %clang_cc1 %s -verify -fsyntax-only
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL1.1
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL1.2
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL2.0
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL2.0 -fno-blocks -DNO_BLOCK

void f(void (^g)(void)) {
#if __OPENCL_C_VERSION__ < CL_VERSION_20 || defined(NO_BLOCK)
  // expected-error:{{}}
#endif
}
