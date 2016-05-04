// RUN: %clang_cc1 -verify -fsyntax-only %s
// RUN: %clang_cc1 -verify -fsyntax-only -cl-std=CL2.0 %s

void test(void) {
  global int *glob;
  local int *loc;
  constant int *con;

  glob = to_global(glob, loc);
#if __OPENCL_C_VERSION__ < CL_VERSION_2_0
  // expected-error@-2{{'to_global' needs OpenCL version 2.0 or above}}
#else
  // expected-error@-4{{invalid number of arguments to function: 'to_global'}}
#endif

  int x;
  glob = to_global(x);
#if __OPENCL_C_VERSION__ < CL_VERSION_2_0
  // expected-error@-2{{'to_global' needs OpenCL version 2.0 or above}}
#else
  // expected-error@-4{{invalid argument x to function: 'to_global'}}
#endif

  glob = to_global(con);
#if __OPENCL_C_VERSION__ < CL_VERSION_2_0
  // expected-error@-2{{'to_global' needs OpenCL version 2.0 or above}}
#else
  // expected-error@-4{{invalid argument con to function: 'to_global'}}
#endif

  loc = to_global(glob);
#if __OPENCL_C_VERSION__ < CL_VERSION_2_0
  // expected-error@-2{{'to_global' needs OpenCL version 2.0 or above}}
#else
  // expected-error@-4{{assigning '__global int *' to '__local int *' changes address space of pointer}}
#endif

}
