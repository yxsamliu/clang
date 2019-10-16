// REQUIRES: amdgpu-registered-target

// RUN: %clang_cc1 -triple amdgcn -fcuda-is-device -std=c++11 -x hip \
// RUN:     -fno-threadsafe-statics -emit-llvm -o - %s | FileCheck -check-prefixes=DEVICE,AMDGCN %s

//#include "Inputs/cuda.h"

#define __device__ __attribute__((device))
__device__ void f();
struct A {
  __device__ A() { f(); }
};

__device__ A a;
