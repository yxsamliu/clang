// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -pedantic -fsyntax-only

#pragma OPENCL EXTENSION cl_khr_fp16 : begin // expected-warning {{register supported OpenCL extension or optional core feature - ignoring}}
#pragma OPENCL EXTENSION cl_khr_fp16 : end

#pragma OPENCL EXTENSION all : begin // expected-warning {{expected 'disable' - ignoring}}
#pragma OPENCL EXTENSION all : end // expected-warning {{expected 'disable' - ignoring}}

#pragma OPENCL EXTENSION my_ext : enable // expected-warning {{unknown OpenCL extension 'my_ext' - ignoring}}
#pragma OPENCL EXTENSION my_ext : disable // expected-warning {{unknown OpenCL extension 'my_ext' - ignoring}}
#pragma OPENCL EXTENSION my_ext : begin 
#pragma OPENCL EXTENSION my_ext : end 
#pragma OPENCL EXTENSION my_ext : enable
#pragma OPENCL EXTENSION my_ext : disable 

