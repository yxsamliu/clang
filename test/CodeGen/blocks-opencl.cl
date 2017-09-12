// RUN: %clang_cc1 -O0 %s -ffake-address-space-map -emit-llvm -o - -fblocks -triple x86_64-unknown-unknown | FileCheck %s
// RUN: %clang_cc1 -O0 %s -emit-llvm -o - -fblocks -triple amdgcn | FileCheck %s
// This used to crash due to trying to generate a bitcase from a cstring
// in the constant address space to i8* in AS0.

void dummy(float (^const op)(float)) {
}

// CHECK-NOT: @.str

kernel void test_block()
{
  float (^const X)(float) = ^(float x) {
    return x + 42.0f;
  };
  dummy(X);
}

