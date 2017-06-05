// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -O0 -o - -triple=amdgcn-amd-amdhsa-opencl | FileCheck %s

// Also test serialization of atomic operations here, to avoid duplicating the test.
// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-pch -O0 -o %t -triple=amdgcn-amd-amdhsa-opencl
// RUN: %clang_cc1 %s -cl-std=CL2.0 -include-pch %t -O0 -triple=amdgcn-amd-amdhsa-opencl -emit-llvm -o - | FileCheck %s

#ifndef ALREADY_INCLUDED
#define ALREADY_INCLUDED

typedef enum memory_order {
  memory_order_relaxed = __ATOMIC_RELAXED,
  memory_order_consume = __ATOMIC_CONSUME,
  memory_order_acquire = __ATOMIC_ACQUIRE,
  memory_order_release = __ATOMIC_RELEASE,
  memory_order_acq_rel = __ATOMIC_ACQ_REL,
  memory_order_seq_cst = __ATOMIC_SEQ_CST
} memory_order;

// ToDo: Currently LLVM only supports synchronization scope singlethread
// and crossthread (default). Add tests for OpenCL synchronization scopes
// after they are supported by LLVM.
typedef enum synch_scope
{
  synch_scope_single_thread,
  synch_scope_cross_thread,
  synch_scope_ocl_work_item,
  synch_scope_ocl_work_group,
  synch_scope_ocl_device,
  synch_scope_ocl_all_svm_devices,
  synch_scope_ocl_sub_group
} synch_scope;

void fi1(atomic_int *i, int *j, int cmp, int ord1, int ord2) {
  int x;
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} singlethread seq_cst
  x = __opencl_atomic_load(i, memory_order_seq_cst, synch_scope_single_thread);
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} seq_cst
  x = __opencl_atomic_load(i, memory_order_seq_cst, synch_scope_cross_thread);
  // CHECK: store atomic i32 %{{[.0-9A-Z_a-z]+}}, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} singlethread seq_cst
  __opencl_atomic_store(i, 1, memory_order_seq_cst, synch_scope_single_thread);
  // CHECK: atomicrmw and i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} singlethread seq_cst
  x = __c11_atomic_fetch_and(i, 1, memory_order_seq_cst, synch_scope_single_thread);
  // CHECK: cmpxchg i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} singlethread acquire acquire
  x = __c11_atomic_compare_exchange_strong(i, &cmp, 1, memory_order_acquire, memory_order_acquire, synch_scope_single_thread);
  x = __c11_atomic_compare_exchange_strong(i, &cmp, 1, ord1, ord2, synch_scope_single_thread);
}

#endif
