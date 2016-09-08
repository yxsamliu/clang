// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -pedantic -fsyntax-only

#pragma OPENCL EXTENSION all : begin // expected-warning {{expected 'disable' - ignoring}}
#pragma OPENCL EXTENSION all : end // expected-warning {{expected 'disable' - ignoring}}

#pragma OPENCL EXTENSION my_ext : begin 

struct A {
  int a;
};

void f(void);

__attribute__((overloadable)) void g(long x);

#pragma OPENCL EXTENSION my_ext : end
#pragma OPENCL EXTENSION my_ext : end // expected-warning {{OpenCL extension end directive mismatches begin directive - ignoring}}

__attribute__((overloadable)) void g(void);

#pragma OPENCL EXTENSION my_ext : enable
void test_f1(void) {
  struct A test_A1;
  f();
  g(0);
}

#pragma OPENCL EXTENSION my_ext : disable 
void test_f2(void) {
  struct A test_A2; // expected-error {{use of type 'struct A' requires my_ext extension to be enabled}}
  f(); // expected-error {{use of declaration requires my_ext extension to be enabled}}
  g(0); // expected-error {{no matching function for call to 'g'}}
        // expected-note@-18 {{candidate disabled due to OpenCL extension}}
        // expected-note@-15 {{candidate function not viable: requires 0 arguments, but 1 was provided}}
}
