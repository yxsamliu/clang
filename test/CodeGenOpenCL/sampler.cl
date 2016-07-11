// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 -Wspir-compat -verify -DCHECK_SAMPLER_VALUE | FileCheck %s
// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 -verify | FileCheck %s

#ifndef CHECK_SAMPLER_VALUE
// expected-no-diagnostics
#endif

#define CLK_ADDRESS_CLAMP_TO_EDGE       2
#define CLK_NORMALIZED_COORDS_TRUE      1
#define CLK_FILTER_NEAREST              0x10
#define CLK_FILTER_LINEAR               0x20

constant sampler_t glb_smp = CLK_ADDRESS_CLAMP_TO_EDGE | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_LINEAR;

constant sampler_t glb_smp2 = 0;
#ifdef CHECK_SAMPLER_VALUE
// expected-warning@-2{{sampler initializer has invalid Filter Mode bits}}
#endif

constant sampler_t glb_smp3 = 0x1f;
#ifdef CHECK_SAMPLER_VALUE
// expected-warning@-2{{sampler initializer has invalid Addressing Mode bits}}
#endif

// CHECK: %__sampler = type opaque

void fnc4smp(sampler_t s) {}
// CHECK: define spir_func void @fnc4smp(%__sampler addrspace(2)* %

kernel void foo() {
  sampler_t smp = CLK_ADDRESS_CLAMP_TO_EDGE | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_NEAREST;
  // CHECK-LABEL: define spir_kernel void @foo()
  // CHECK: [[smp_ptr:%[A-Za-z0-9_\.]+]] = alloca %__sampler addrspace(2)*
  // CHECK: [[SAMP:%[0-9]+]] = call %__sampler addrspace(2)* @__translate_sampler_initializer(i32 19)
  // CHECK: store %__sampler addrspace(2)* [[SAMP]], %__sampler addrspace(2)** [[smp_ptr]]

  fnc4smp(smp);
  // CHECK: [[SAMP:%[0-9]+]] = call %__sampler addrspace(2)* @__translate_sampler_initializer(i32 19)
  // CHECK: call spir_func void @fnc4smp(%__sampler addrspace(2)* [[SAMP]])

  fnc4smp(glb_smp);
  // CHECK: [[SAMP:%[0-9]+]] = call %__sampler addrspace(2)* @__translate_sampler_initializer(i32 35)
  // CHECK: call spir_func void @fnc4smp(%__sampler addrspace(2)* [[SAMP]])

  fnc4smp(glb_smp2);
  fnc4smp(glb_smp3);
}
