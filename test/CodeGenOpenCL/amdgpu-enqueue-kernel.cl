// RUN: %clang_cc1 %s -cl-std=CL2.0 -O0 -emit-llvm -o - -triple amdgcn | FileCheck %s --check-prefix=CHECK

// CHECK: %[[S1:struct.__amdgpu_block_arg_t.*]] = type { [3 x i64], [1 x i8] }
// CHECK: %[[S2:struct.__amdgpu_block_arg_t.*]] = type { [5 x i64], [1 x i8] }

typedef struct {int a;} ndrange_t;

// CHECK-LABEL: define amdgpu_kernel void @test
kernel void test(global char *a, char b, global long *c, long d) {
  queue_t default_queue;
  unsigned flags = 0;
  ndrange_t ndrange;
  
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(void) {
                 a[0] = b;
                 });
  
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(void) {
                 a[0] = b;
                 c[0] = d;
                 });
}

// CHECK-LABEL: define internal amdgpu_kernel void @__test_block_invoke
// CHECK-SAME: (%[[S1]] %{{.*}})
// CHECK: %block = bitcast %[[S1]]* %{{.*}} to <{ i32, i32, i8 addrspace(4)*, i8 addrspace(1)*, i8 }>*

// CHECK-LABEL: define internal amdgpu_kernel void @__test_block_invoke_2
// CHECK-SAME: (%[[S2]] %{{.*}})
// CHECK: %block = bitcast %[[S2]]* %{{.*}} to <{ i32, i32, i8 addrspace(4)*, i8 addrspace(1)*, i64 addrspace(1)*, i64, i8 }>*
