// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -pedantic -fsyntax-only

#pragma OPENCL EXTENSION cl_khr_fp16 : begin // expected-warning {{register supported OpenCL extension or optional core feature - ignoring}}
#pragma OPENCL EXTENSION cl_khr_fp16 : end

#pragma OPENCL EXTENSION all : begin // expected-warning {{expected 'disable' - ignoring}}
#pragma OPENCL EXTENSION all : end // expected-warning {{expected 'disable' - ignoring}}

#pragma OPENCL EXTENSION my_ext : enable // expected-warning {{unknown OpenCL extension 'my_ext' - ignoring}}
#pragma OPENCL EXTENSION my_ext : disable // expected-warning {{unknown OpenCL extension 'my_ext' - ignoring}}

#pragma OPENCL EXTENSION my_ext : begin 
struct A;
void f(void);
__attribute__((overloadable)) void g(long x);
#pragma OPENCL EXTENSION my_ext : end
__attribute__((overloadable)) void g(void);

#pragma OPENCL EXTENSION my_ext : enable
constant struct A* test_A1;
void test_f1(void) {
  f();
  g(0);
}

#pragma OPENCL EXTENSION my_ext : disable 
constant struct A* test_A2; // expected-error {{use of type 'struct A' requires my_ext extension to be enabled}}
void test_f2(void) {
  f(); // expected-error {{use of declaration requires my_ext extension to be enabled}}
  g(0); // expected-error {{no matching function for call to 'g'}}
        // expected-note@-16 {{candidate disabled due to OpenCL extension}}
        // expected-note@-15 {{candidate function not viable: requires 0 arguments, but 1 was provided}}
}
