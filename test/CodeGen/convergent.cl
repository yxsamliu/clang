// RUN: %clang_cc1 -triple spir-unknown-unknown -cl-std=CL2.0 -emit-llvm %s -o - | FileCheck %s

// CHECK-LABEL: define spir_func void @convfun1() #0 {
void convfun1(void) __attribute__((convergent));

// CHECK-LABEL: define spir_func void @convfun2() #0 {
void convfun2(void) [[clang : convergent]];

void sink(int a) {
  if (a) {
    convfun1();
  } else {
    convfun1();
  }
}

void unroll() {
  #pragma unroll(2)
  for (int i = 0; i < 100; i++)
    convfun2();
}
