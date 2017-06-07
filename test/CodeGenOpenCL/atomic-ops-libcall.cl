// RUN: %clang_cc1 < %s -cl-std=CL2.0 -finclude-default-header -triple spir64 -emit-llvm | FileCheck %s
// RUN: %clang_cc1 < %s -cl-std=CL2.0 -finclude-default-header -triple armv5e-none-linux-gnueabi -emit-llvm | FileCheck %s

void f(atomic_int *i, int cmp) {
  int x;
  // CHECK: {{%[^ ]*}} = call i32 @__opencl_atomic_load_4(i8* {{%[0-9]+}}, i32 5, i32 0)
  x = __opencl_atomic_load(i, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: call void @__opencl_atomic_store_4(i8* {{%[0-9]+}}, i32 {{%[0-9]+}}, i32 5, i32 0)
  __opencl_atomic_store(i, 1, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: {{%[^ ]*}} = call i32 @__opencl_atomic_fetch_add_4(i8* {{%[0-9]+}}, i32 {{%[0-9]+}}, i32 5, i32 0)
  x = __opencl_atomic_fetch_add(i, 3, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: {{%[^ ]*}} = call i32 @__opencl_atomic_compare_exchange_4(i8* {{%[0-9]+}}, i8* {%[0-9]+}}, i32 {{%[0-9]+}}, i32 5, i32 5, i32 0)
  x = __opencl_atomic_compare_exchange_strong(i, &cmp, 1, memory_order_seq_cst, memory_order_seq_cst, memory_scope_work_item);
  // CHECK: {{%[^ ]*}} = call i32 @__opencl_atomic_compare_exchange_4(i8* {{%[0-9]+}}, i8* {%[0-9]+}}, i32 {{%[0-9]+}}, i32 5, i32 5, i32 0)
  x = __opencl_atomic_compare_exchange_weak(i, &cmp, 1, memory_order_seq_cst, memory_order_seq_cst, memory_scope_work_item);
}
