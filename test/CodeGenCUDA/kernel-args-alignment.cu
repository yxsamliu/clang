// RUN: %clang_cc1 --std=c++11 -triple x86_64-unknown-linux-gnu -emit-llvm -o - %s | \
// RUN:  FileCheck -check-prefixes=HOST,CHECK %s

// RUN: %clang_cc1 --std=c++11 -fcuda-is-device -triple nvptx64-nvidia-cuda \
// RUN:   -emit-llvm -o - %s | FileCheck -check-prefixes=DEVICE,CHECK,NVPTX %s

// RUN: %clang_cc1 --std=c++11 -fcuda-is-device -triple amdgcn-amd-amdhsa \
// RUN:   -emit-llvm -o - %s -DAMDGCN| FileCheck -check-prefixes=DEVICE,CHECK,AMDGCN %s

#include "Inputs/cuda.h"

struct U {
  short x;
} __attribute__((packed));

struct S {
  int *ptr;
  char a;
  U u;
};

// Clang should generate a packed LLVM struct for S (denoted by the <>s),
// otherwise this test isn't interesting.
// HOST: %struct.S = type <{ i32*, i8, %struct.U, [5 x i8] }>
// NVPTX: %struct.S = type <{ i32*, i8, %struct.U, [5 x i8] }>
// AMDGCN: %struct.S = type <{ i32 addrspace(4)*, i8, %struct.U, [5 x i8] }>

static_assert(alignof(S) == 8, "Unexpected alignment.");

// HOST-LABEL: @_Z6kernelc1SPi
// Marshalled kernel args should be:
//   1. offset 0, width 1
//   2. offset 8 (because alignof(S) == 8), width 16
//   3. offset 24, width 8
// HOST: call i32 @cudaSetupArgument({{[^,]*}}, i64 1, i64 0)
// HOST: call i32 @cudaSetupArgument({{[^,]*}}, i64 16, i64 8)
// HOST: call i32 @cudaSetupArgument({{[^,]*}}, i64 8, i64 24)

// DEVICE-LABEL: @_Z6kernelc1SPi
// NVPTX-SAME: i8{{[^,]*}}, %struct.S* byval align 8{{[^,]*}}, i32*
// AMDGCN-SAME: i8{{[^,]*}}, %struct.S* byval align 8{{[^,]*}}, i32 addrspace(4)*
__global__ void kernel(char a, S s, int *b) {}
