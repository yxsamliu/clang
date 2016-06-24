// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -pedantic -fsyntax-only

#pragma OPENCL EXTENSION cl_khr_fp16 : register // expected-warning {{register supported OpenCL extension or optional core feature - ignoring}}

#pragma OPENCL EXTENSION all : register /* expected-warning {{expected 'disable' - ignoring}} */

#pragma OPENCL EXTENSION my_ext : enable // expected-warning {{unknown OpenCL extension 'my_ext' - ignoring}}
#pragma OPENCL EXTENSION my_ext : disable // expected-warning {{unknown OpenCL extension 'my_ext' - ignoring}}
#pragma OPENCL EXTENSION my_ext : register
#pragma OPENCL EXTENSION my_ext : register // expected-warning {{register supported OpenCL extension or optional core feature - ignoring}}
#pragma OPENCL EXTENSION my_ext : enable
#pragma OPENCL EXTENSION my_ext : disable 

