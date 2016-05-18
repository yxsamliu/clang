// RUN: %clang_cc1 %s -verify -fsyntax-only
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL1.1
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL1.2
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL2.0
// RUN: %clang_cc1 %s -verify -fsyntax-only -fblocks -DBLOCKS
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL1.1 -fblocks -DBLOCKS
// RUN: %clang_cc1 %s -verify -fsyntax-only -cl-std=CL1.2 -fblocks -DBLOCKS

void f(void (^g)(void)) {
#if __OPENCL_C_VERSION__ < CL_VERSION_2_0 && !defined(BLOCKS)
  // expected-error@-2{{blocks support disabled - compile with -fblocks or pick a deployment target that supports them}}
#else
  // expected-no-diagnostics
#endif
}
