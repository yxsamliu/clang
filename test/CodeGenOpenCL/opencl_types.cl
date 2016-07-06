// RUN: %clang_cc1 %s -triple spir-unknown-unknown -emit-llvm -o - -O0 | FileCheck %s

#define CLK_ADDRESS_CLAMP_TO_EDGE       2
#define CLK_NORMALIZED_COORDS_TRUE      1
#define CLK_FILTER_NEAREST              0x10
#define CLK_FILTER_LINEAR               0x20

constant sampler_t glb_smp = CLK_ADDRESS_CLAMP_TO_EDGE|CLK_NORMALIZED_COORDS_TRUE|CLK_FILTER_NEAREST;
// CHECK: [[SAMP1:.+]] = internal addrspace(2) constant %__sampler_initializer { i32 1, i32 1, i32 0 }
// CHECK: glb_smp = global %__sampler_initializer addrspace(2)* [[SAMP1]]
// CHECK: [[SAMP2:.+]] = internal addrspace(2) constant %__sampler_initializer { i32 1, i32 1, i32 1 }

void fnc1(image1d_t img) {}
// CHECK: @fnc1(%opencl.image1d_ro_t addrspace(1)*

void fnc1arr(image1d_array_t img) {}
// CHECK: @fnc1arr(%opencl.image1d_array_ro_t addrspace(1)*

void fnc1buff(image1d_buffer_t img) {}
// CHECK: @fnc1buff(%opencl.image1d_buffer_ro_t addrspace(1)*

void fnc2(image2d_t img) {}
// CHECK: @fnc2(%opencl.image2d_ro_t addrspace(1)*

void fnc2arr(image2d_array_t img) {}
// CHECK: @fnc2arr(%opencl.image2d_array_ro_t addrspace(1)*

void fnc3(image3d_t img) {}
// CHECK: @fnc3(%opencl.image3d_ro_t addrspace(1)*

void fnc4smp(sampler_t s) {}
// CHECK-LABEL: define {{.*}}void @fnc4smp(%__sampler addrspace(2)*

kernel void foo(image1d_t img) {
  sampler_t smp = CLK_ADDRESS_CLAMP_TO_EDGE|CLK_NORMALIZED_COORDS_TRUE|CLK_FILTER_LINEAR;
  // CHECK: alloca %__sampler_initializer addrspace(2)*
  event_t evt;
  // CHECK: alloca %opencl.event_t*
  // CHECK: store %__sampler_initializer addrspace(2)* [[SAMP2]],
  fnc4smp(smp);
  // CHECK: call {{.*}}void @fnc4smp(%__sampler addrspace(2)*
  fnc4smp(glb_smp);
  // CHECK: call {{.*}}void @fnc4smp(%__sampler addrspace(2)*
}

void __attribute__((overloadable)) bad1(image1d_t b, image2d_t c, image2d_t d) {}
// CHECK-LABEL: @{{_Z4bad114ocl_image1d_ro14ocl_image2d_roS0_|"\\01\?bad1@@\$\$J0YAXPAUocl_image1d_ro@@PAUocl_image2d_ro@@1@Z"}}
