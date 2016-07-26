// RUN: %clang_cc1 -S -cl-denorms-are-zero -o - %s 2>&1
// RUN: %clang_cc1 -emit-llvm -cl-denorms-are-zero -o - -triple amdgcn--amdhsa -cpu fiji %s | FileCheck %s
// RUN: %clang_cc1 -emit-llvm -o - -triple amdgcn--amdhsa -cpu fiji %s | FileCheck %s --check-prefix=CHECK-DENORM

// CHECK-DENORM-LABEL: define void @f()
// CHECK-DENORM: attributes #{{[0-9]*}} = {{{[^}]*}} "target-features"="{{[^"]*}}+fp32-denormals,+fp64-denormals{{[^"]*}}"
// CHECK-LABEL: define void @f()
// CHECK-NOT: attributes #{{[0-9]*}} = {{{[^}]*}} "target-features"="{{[^"]*}}+fp32-denormals,+fp64-denormals{{[^"]*}}"
void f() {}
