// RUN: echo "GPU binary would be here" > %t
// RUN: %clang_cc1 -triple x86_64-linux-gnu -emit-llvm %s -fcuda-include-gpubinary %t -o - | FileCheck -check-prefixes=CHECK,CUDA %s
// RUN: %clang_cc1 -triple x86_64-linux-gnu -emit-llvm %s -fcuda-include-gpubinary %t -o -  -DNOGLOBALS \
// RUN:   | FileCheck %s -check-prefix=NOGLOBALS
// RUN: %clang_cc1 -triple x86_64-linux-gnu -x hip -emit-llvm %s -o - | FileCheck %s -check-prefix=NOGPUBIN
// RUN: %clang_cc1 -triple x86_64-linux-gnu -x hip -emit-llvm %s -fcuda-include-gpubinary %t -o - | FileCheck -check-prefixes=CHECK,HIP %s
// RUN: %clang_cc1 -triple x86_64-linux-gnu -x hip -emit-llvm %s -fcuda-include-gpubinary %t -o -  -DNOGLOBALS \
// RUN:   | FileCheck %s -check-prefix=NOGLOBALS
// RUN: %clang_cc1 -triple x86_64-linux-gnu -x hip -emit-llvm %s -o - | FileCheck %s -check-prefix=NOGPUBIN

#include "Inputs/cuda.h"

#ifndef NOGLOBALS
// CHECK-DAG: @device_var = internal global i32
__device__ int device_var;

// CHECK-DAG: @constant_var = internal global i32
__constant__ int constant_var;

// CHECK-DAG: @shared_var = internal global i32
__shared__ int shared_var;

// Make sure host globals don't get internalized...
// CHECK-DAG: @host_var = global i32
int host_var;
// ... and that extern vars remain external.
// CHECK-DAG: @ext_host_var = external global i32
extern int ext_host_var;

// Shadows for external device-side variables are *definitions* of
// those variables.
// CHECK-DAG: @ext_device_var = internal global i32
extern __device__ int ext_device_var;
// CHECK-DAG: @ext_device_var = internal global i32
extern __constant__ int ext_constant_var;

void use_pointers() {
  int *p;
  p = &device_var;
  p = &constant_var;
  p = &shared_var;
  p = &host_var;
  p = &ext_device_var;
  p = &ext_constant_var;
  p = &ext_host_var;
}

// Make sure that all parts of GPU code init/cleanup are there:
// * constant unnamed string with the kernel name
// CHECK: private unnamed_addr constant{{.*}}kernelfunc{{.*}}\00"
// * constant unnamed string with GPU binary
// CHECK: private unnamed_addr constant{{.*GPU binary would be here.*}}\00"
// CHECK-SAME: section ".nv_fatbin", align 8
// * constant struct that wraps GPU binary
// CUDA: @__[[PREFIX:cuda]]_fatbin_wrapper = internal constant { i32, i32, i8*, i8* }
// HIP: @__[[PREFIX:hip]]_fatbin_wrapper = internal constant { i32, i32, i8*, i8* }
// CHECK-SAME: { i32 1180844977, i32 1, {{.*}}, i8* null }
// CHECK-SAME: section ".nvFatBinSegment"
// * variable to save GPU binary handle after initialization
// CHECK: @__[[PREFIX]]_gpubin_handle = internal global i8** null
// * Make sure our constructor/destructor was added to global ctor/dtor list.
// CHECK: @llvm.global_ctors = appending global {{.*}}@__[[PREFIX]]_module_ctor
// CHECK: @llvm.global_dtors = appending global {{.*}}@__[[PREFIX]]_module_dtor

// Test that we build the correct number of calls to cudaSetupArgument followed
// by a call to cudaLaunch.

// CHECK: define{{.*}}kernelfunc
// CHECK: call{{.*}}[[PREFIX]]SetupArgument
// CHECK: call{{.*}}[[PREFIX]]SetupArgument
// CHECK: call{{.*}}[[PREFIX]]SetupArgument
// CHECK: call{{.*}}[[PREFIX]]Launch
__global__ void kernelfunc(int i, int j, int k) {}

// Test that we've built correct kernel launch sequence.
// CHECK: define{{.*}}hostfunc
// CHECK: call{{.*}}[[PREFIX]]ConfigureCall
// CHECK: call{{.*}}kernelfunc
void hostfunc(void) { kernelfunc<<<1, 1>>>(1, 1, 1); }
#endif

// Test that we've built a function to register kernels and global vars.
// CHECK: define internal void @__[[PREFIX]]_register_globals
// CHECK: call{{.*}}[[PREFIX]]RegisterFunction(i8** %0, {{.*}}kernelfunc
// CHECK-DAG: call{{.*}}[[PREFIX]]RegisterVar(i8** %0, {{.*}}device_var{{.*}}i32 0, i32 4, i32 0, i32 0
// CHECK-DAG: call{{.*}}[[PREFIX]]RegisterVar(i8** %0, {{.*}}constant_var{{.*}}i32 0, i32 4, i32 1, i32 0
// CHECK-DAG: call{{.*}}[[PREFIX]]RegisterVar(i8** %0, {{.*}}ext_device_var{{.*}}i32 1, i32 4, i32 0, i32 0
// CHECK-DAG: call{{.*}}[[PREFIX]]RegisterVar(i8** %0, {{.*}}ext_constant_var{{.*}}i32 1, i32 4, i32 1, i32 0
// CHECK: ret void

// Test that we've built contructor..
// CHECK: define internal void @__[[PREFIX]]_module_ctor
//   .. that calls __[[PREFIX]]RegisterFatBinary(&__[[PREFIX]]_fatbin_wrapper)
// CHECK: call{{.*}}[[PREFIX]]RegisterFatBinary{{.*}}__[[PREFIX]]_fatbin_wrapper
//   .. stores return value in __[[PREFIX]]_gpubin_handle
// CHECK-NEXT: store{{.*}}__[[PREFIX]]_gpubin_handle
//   .. and then calls __[[PREFIX]]_register_globals
// CHECK-NEXT: call void @__[[PREFIX]]_register_globals

// Test that we've created destructor.
// CHECK: define internal void @__[[PREFIX]]_module_dtor
// CHECK: load{{.*}}__[[PREFIX]]_gpubin_handle
// CHECK-NEXT: call void @__[[PREFIX]]UnregisterFatBinary

// There should be no __[[PREFIX]]_register_globals if we have no
// device-side globals, but we still need to register GPU binary.
// Skip GPU binary string first.
// NOGLOBALS: @0 = private unnamed_addr constant{{.*}}
// NOGLOBALS-NOT: define internal void @__{{.*}}_register_globals
// NOGLOBALS: define internal void @__[[PREFIX:.*]]_module_ctor
// NOGLOBALS: call{{.*}}[[PREFIX]]RegisterFatBinary{{.*}}__[[PREFIX]]_fatbin_wrapper
// NOGLOBALS-NOT: call void @__[[PREFIX]]_register_globals
// NOGLOBALS: define internal void @__[[PREFIX]]_module_dtor
// NOGLOBALS: call void @__[[PREFIX]]UnregisterFatBinary

// There should be no constructors/destructors if we have no GPU binary.
// NOGPUBIN-NOT: define internal void @__[[PREFIX]]_register_globals
// NOGPUBIN-NOT: define internal void @__[[PREFIX]]_module_ctor
// NOGPUBIN-NOT: define internal void @__[[PREFIX]]_module_dtor
