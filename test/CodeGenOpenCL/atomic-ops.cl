// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -finclude-default-header -O0 -o - -triple=amdgcn-amd-amdhsa-opencl | FileCheck %s

// Also test serialization of atomic operations here, to avoid duplicating the test.
// RUN: %clang_cc1 %s -cl-std=CL2.0 -finclude-default-header -emit-pch -O0 -o %t -triple=amdgcn-amd-amdhsa-opencl
// RUN: %clang_cc1 %s -cl-std=CL2.0 -include-pch %t -O0 -triple=amdgcn-amd-amdhsa-opencl -emit-llvm -o - | FileCheck %s

#ifndef ALREADY_INCLUDED
#define ALREADY_INCLUDED

void fi1(atomic_int *i, int *j, int cmp, int ord1, int ord2) {
  int x;
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} singlethread seq_cst
  x = __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_work_item);
#if 0
  // CHECK: store atomic i32 %{{[.0-9A-Z_a-z]+}}, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} singlethread seq_cst
  __opencl_atomic_store(i, 1, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: atomicrmw and i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} singlethread seq_cst
  x = __opencl_atomic_fetch_and(i, 1, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: cmpxchg i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} singlethread acquire acquire
  x = __opencl_atomic_compare_exchange_strong(i, &cmp, 1, memory_order_acquire, memory_order_acquire, memory_scope_work_item);
  x = __opencl_atomic_compare_exchange_strong(i, &cmp, 1, ord1, ord2, memory_scope_work_item);
#endif
}
#endif
