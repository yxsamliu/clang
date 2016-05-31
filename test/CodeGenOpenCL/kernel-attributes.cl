// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s

typedef unsigned int uint4 __attribute__((ext_vector_type(4)));

kernel  __attribute__((vec_type_hint(int))) __attribute__((reqd_work_group_size(1,2,4))) void kernel1(int a) {}
// CHECK: define void @kernel1(i32 %a) {{[^}]+}} !vec_type_hint ![[VH1:.+]] !reqd_work_group_size ![[WG:.+]] {

kernel __attribute__((vec_type_hint(uint4))) __attribute__((work_group_size_hint(8,16,32))) void kernel2(int a) {}
// CHECK: define void @kernel2(i32 %a) {{[^}]+}} !vec_type_hint ![[VH2:.+]] !work_group_size_hint ![[WH:.+]] {

// CHECK: ![[VH1]] = !{i32 undef, i32 1}
// CHECK: ![[WG]] = !{i32 1, i32 2, i32 4}
// CHECK: ![[VH2]] = !{<4 x i32> undef, i32 0}
// CHECK: ![[WH]] = !{i32 8, i32 16, i32 32}
