// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -pedantic -fsyntax-only

#pragma OPENCL EXTENSION example_extension : enable // expected-warning{{unknown extension}}

#pragma OPENCL EXTENSION example_extension : disable // expected-warning{{unknown extension}}

#pragma OPENCL EXTENSION example_extension : register

#pragma OPENCL EXTENSION example_extension : enable

#pragma OPENCL EXTENSION example_extension : disable
