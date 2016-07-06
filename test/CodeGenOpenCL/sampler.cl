// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 | FileCheck %s

#define CLK_ADDRESS_CLAMP_TO_EDGE       2
#define CLK_NORMALIZED_COORDS_TRUE      1
#define CLK_FILTER_NEAREST              0x10
#define CLK_FILTER_LINEAR               0x20

constant sampler_t glb_smp = CLK_ADDRESS_CLAMP_TO_EDGE | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_LINEAR;

// CHECK: %__sampler_initializer = type { i32, i32, i32 }
// CHECK: %__sampler = type opaque
// CHECK: [[glb_smp_init:@[-a-zA-Z$._][-a-zA-Z$._0-9]*]] = internal addrspace(2) constant %__sampler_initializer { i32 1, i32 1, i32 1 }
// CHECK: @glb_smp = global %__sampler_initializer addrspace(2)* [[glb_smp_init]]
// CHECK: [[smp_init:@[-a-zA-Z$._][-a-zA-Z$._0-9]*]] = internal addrspace(2) constant %__sampler_initializer { i32 1, i32 1, i32 0 }

void fnc4smp(sampler_t s) {}
// CHECK: define spir_func void @fnc4smp(%__sampler addrspace(2)* %

kernel void foo() {
  sampler_t smp = CLK_ADDRESS_CLAMP_TO_EDGE | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_NEAREST;
  // CHECK-LABEL: define spir_kernel void @foo()
  // CHECK: [[smp_ptr:%[A-Za-z0-9_\.]+]] = alloca %__sampler_initializer addrspace(2)*
  // CHECK: store %__sampler_initializer addrspace(2)* [[smp_init]], %__sampler_initializer addrspace(2)** [[smp_ptr]]

  fnc4smp(smp);
  // CHECK: [[SINIT:%[0-9]+]] = load %__sampler_initializer addrspace(2)*, %__sampler_initializer addrspace(2)** [[smp_ptr]]
  // CHECK: [[SAMP:%[0-9]+]] = call %__sampler addrspace(2)* @__translate_sampler_initializer(%__sampler_initializer addrspace(2)* [[SINIT]])
  // CHECK: call spir_func void @fnc4smp(%__sampler addrspace(2)* [[SAMP]])

  fnc4smp(glb_smp);
  // CHECK: [[SINIT:%[0-9]+]] = load %__sampler_initializer addrspace(2)*, %__sampler_initializer addrspace(2)** @glb_smp
  // CHECK: [[SAMP:%[0-9]+]] = call %__sampler addrspace(2)* @__translate_sampler_initializer(%__sampler_initializer addrspace(2)* [[SINIT]])
  // CHECK: call spir_func void @fnc4smp(%__sampler addrspace(2)* [[SAMP]])
}
