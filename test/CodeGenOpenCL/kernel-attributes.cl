// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s

typedef unsigned int uint4 __attribute__((ext_vector_type(4)));

kernel  __attribute__((vec_type_hint(int))) __attribute__((reqd_work_group_size(1,2,4))) void kernel1(int a) {}
// CHECK: define void @kernel1(i32 %a) #[[AT1:[0-9]+]]

kernel __attribute__((vec_type_hint(uint4))) __attribute__((work_group_size_hint(8,16,32))) void kernel2(int a) {}
// CHECK: define void @kernel2(i32 %a) #[[AT2:[0-9]+]]

// CHECK: attributes #[[AT1]] = { 
// CHECK-DAG: "reqd_work_group_size"="1 2 4"
// CHECK-DAG: "vec_type_hint"="vec_type_hint"
// CHECK: attributes #[[AT2]] = {
// CHECK-DAG: "vec_type_hint"="vec_type_hint"
// CHECK-DAG: "work_group_size_hint"="8 16 32"
