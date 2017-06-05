// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -finclude-default-header -O0 -o - -triple=amdgcn-amd-amdhsa-opencl | FileCheck %s

// Also test serialization of atomic operations here, to avoid duplicating the test.
// RUN: %clang_cc1 %s -cl-std=CL2.0 -finclude-default-header -emit-pch -O0 -o %t -triple=amdgcn-amd-amdhsa-opencl
// RUN: %clang_cc1 %s -cl-std=CL2.0 -finclude-default-header -include-pch %t -O0 -triple=amdgcn-amd-amdhsa-opencl -emit-llvm -o - | FileCheck %s

#ifndef ALREADY_INCLUDED
#define ALREADY_INCLUDED

atomic_int j;

void fi1(atomic_int *i) {
  // CHECK-LABEL: @fi1
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} syncscope("singlethread") seq_cst
  int x = __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} syncscope("workgroup") seq_cst
  x = __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_work_group);
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} syncscope("agent") seq_cst
  x = __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_device);
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} seq_cst
  x = __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_all_svm_devices);
  // CHECK: load atomic i32, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} syncscope("subgroup") seq_cst
  x = __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_sub_group);
}

void fi2(atomic_int *i) {
  // CHECK-LABEL: @fi2
  // CHECK: store atomic i32 %{{[.0-9A-Z_a-z]+}}, i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}} syncscope("singlethread") seq_cst
  __opencl_atomic_store(i, 1, memory_order_seq_cst, memory_scope_work_item);
}

void fi3(atomic_int *i, atomic_uint *ui) {
  // CHECK-LABEL: @fi3
  // CHECK: atomicrmw and i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} syncscope("singlethread") seq_cst
  int x = __opencl_atomic_fetch_and(i, 1, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: atomicrmw min i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} syncscope("singlethread") seq_cst
  x = __opencl_atomic_fetch_min(i, 1, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: atomicrmw max i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} syncscope("singlethread") seq_cst
  x = __opencl_atomic_fetch_max(i, 1, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: atomicrmw umin i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} syncscope("singlethread") seq_cst
  x = __opencl_atomic_fetch_min(ui, 1, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: atomicrmw umax i32 addrspace(4)* %{{[.0-9A-Z_a-z]+}}, i32 %{{[.0-9A-Z_a-z]+}} syncscope("singlethread") seq_cst
  x = __opencl_atomic_fetch_max(ui, 1, memory_order_seq_cst, memory_scope_work_item);
}

bool fi4(atomic_int *i) {
  // CHECK-LABEL: @fi4(
  // CHECK: [[PAIR:%[.0-9A-Z_a-z]+]] = cmpxchg i32 addrspace(4)* [[PTR:%[.0-9A-Z_a-z]+]], i32 [[EXPECTED:%[.0-9A-Z_a-z]+]], i32 [[DESIRED:%[.0-9A-Z_a-z]+]] syncscope("singlethread") acquire acquire
  // CHECK: [[OLD:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 0
  // CHECK: [[CMP:%[.0-9A-Z_a-z]+]] = extractvalue { i32, i1 } [[PAIR]], 1
  // CHECK: br i1 [[CMP]], label %[[STORE_EXPECTED:[.0-9A-Z_a-z]+]], label %[[CONTINUE:[.0-9A-Z_a-z]+]]
  // CHECK: store i32 [[OLD]]
  int cmp = 0;
  return __opencl_atomic_compare_exchange_strong(i, &cmp, 1, memory_order_acquire, memory_order_acquire, memory_scope_work_item);
}

float ff1(global atomic_float *d) {
  // CHECK-LABEL: @ff1
  // CHECK: load atomic i32, i32 addrspace(1)* {{.*}} syncscope("singlethread") monotonic
  return __opencl_atomic_load(d, memory_order_relaxed, memory_scope_work_item);
}

void ff2(atomic_float *d) {
  // CHECK-LABEL: @ff2
  // CHECK: store atomic i32 {{.*}} syncscope("singlethread") release
  __opencl_atomic_store(d, 1, memory_order_release, memory_scope_work_item);
}

float ff3(atomic_float *d) {
  // CHECK-LABEL: @ff3
  // CHECK: atomicrmw xchg i32 addrspace(4)* {{.*}} syncscope("singlethread") seq_cst
  return __opencl_atomic_exchange(d, 2, memory_order_seq_cst, memory_scope_work_item);
}

// CHECK-LABEL: @atomic_init_foo
void atomic_init_foo()
{
  // CHECK-NOT: atomic
  // CHECK: store
  __opencl_atomic_init(&j, 42);

  // CHECK-NOT: atomic
  // CHECK: }
}

// CHECK-LABEL: @failureOrder
void failureOrder(atomic_int *ptr, int *ptr2) {
  // CHECK: cmpxchg i32 addrspace(4)* {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z_.]+}} syncscope("singlethread") acquire monotonic
  __opencl_atomic_compare_exchange_strong(ptr, ptr2, 43, memory_order_acquire, memory_order_relaxed, memory_scope_work_item);

  // CHECK: cmpxchg weak i32 addrspace(4)* {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z._]+}}, i32 {{%[0-9A-Za-z_.]+}} syncscope("singlethread") seq_cst acquire
  __opencl_atomic_compare_exchange_weak(ptr, ptr2, 43, memory_order_seq_cst, memory_order_acquire, memory_scope_work_item);
}

// CHECK-LABEL: @generalFailureOrder
void generalFailureOrder(atomic_int *ptr, int *ptr2, int success, int fail) {
  __opencl_atomic_compare_exchange_strong(ptr, ptr2, 42, success, fail, memory_scope_work_item);
  // CHECK: switch i32 {{.*}}, label %[[MONOTONIC:[0-9a-zA-Z._]+]] [
  // CHECK-NEXT: i32 1, label %[[ACQUIRE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: i32 2, label %[[ACQUIRE]]
  // CHECK-NEXT: i32 3, label %[[RELEASE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: i32 4, label %[[ACQREL:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: i32 5, label %[[SEQCST:[0-9a-zA-Z._]+]]

  // CHECK: [[MONOTONIC]]
  // CHECK: switch {{.*}}, label %[[MONOTONIC_MONOTONIC:[0-9a-zA-Z._]+]] [
  // CHECK-NEXT: ]

  // CHECK: [[ACQUIRE]]
  // CHECK: switch {{.*}}, label %[[ACQUIRE_MONOTONIC:[0-9a-zA-Z._]+]] [
  // CHECK-NEXT: i32 1, label %[[ACQUIRE_ACQUIRE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: i32 2, label %[[ACQUIRE_ACQUIRE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: ]

  // CHECK: [[RELEASE]]
  // CHECK: switch {{.*}}, label %[[RELEASE_MONOTONIC:[0-9a-zA-Z._]+]] [
  // CHECK-NEXT: ]

  // CHECK: [[ACQREL]]
  // CHECK: switch {{.*}}, label %[[ACQREL_MONOTONIC:[0-9a-zA-Z._]+]] [
  // CHECK-NEXT: i32 1, label %[[ACQREL_ACQUIRE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: i32 2, label %[[ACQREL_ACQUIRE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: ]

  // CHECK: [[SEQCST]]
  // CHECK: switch {{.*}}, label %[[SEQCST_MONOTONIC:[0-9a-zA-Z._]+]] [
  // CHECK-NEXT: i32 1, label %[[SEQCST_ACQUIRE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: i32 2, label %[[SEQCST_ACQUIRE:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: i32 5, label %[[SEQCST_SEQCST:[0-9a-zA-Z._]+]]
  // CHECK-NEXT: ]

  // CHECK: [[MONOTONIC_MONOTONIC]]
  // CHECK: cmpxchg {{.*}} monotonic monotonic
  // CHECK: br

  // CHECK: [[ACQUIRE_MONOTONIC]]
  // CHECK: cmpxchg {{.*}} acquire monotonic
  // CHECK: br

  // CHECK: [[ACQUIRE_ACQUIRE]]
  // CHECK: cmpxchg {{.*}} acquire acquire
  // CHECK: br

  // CHECK: [[ACQREL_MONOTONIC]]
  // CHECK: cmpxchg {{.*}} acq_rel monotonic
  // CHECK: br

  // CHECK: [[ACQREL_ACQUIRE]]
  // CHECK: cmpxchg {{.*}} acq_rel acquire
  // CHECK: br

  // CHECK: [[SEQCST_MONOTONIC]]
  // CHECK: cmpxchg {{.*}} seq_cst monotonic
  // CHECK: br

  // CHECK: [[SEQCST_ACQUIRE]]
  // CHECK: cmpxchg {{.*}} seq_cst acquire
  // CHECK: br

  // CHECK: [[SEQCST_SEQCST]]
  // CHECK: cmpxchg {{.*}} seq_cst seq_cst
  // CHECK: br
}

int test_volatile(volatile atomic_int *i) {
  // CHECK-LABEL: @test_volatile
  // CHECK:      %[[i_addr:.*]] = alloca i32
  // CHECK-NEXT: %[[atomicdst:.*]] = alloca i32
  // CHECK-NEXT: store i32 addrspace(4)* %i, i32 addrspace(4)** %[[i_addr]]
  // CHECK-NEXT: %[[addr:.*]] = load i32 addrspace(4)*, i32 addrspace(4)** %[[i_addr]]
  // CHECK-NEXT: %[[res:.*]] = load atomic volatile i32, i32 addrspace(4)* %[[addr]] syncscope("singlethread") seq_cst
  // CHECK-NEXT: store i32 %[[res]], i32* %[[atomicdst]]
  // CHECK-NEXT: %[[retval:.*]] = load i32, i32* %[[atomicdst]]
  // CHECK-NEXT: ret i32 %[[retval]]
  return __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_work_item);
}

#endif
