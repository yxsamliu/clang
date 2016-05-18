// RUN: %clang_cc1 -fno-default-header -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -fno-default-header -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -fno-default-header -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -fno-default-header -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck %s

// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -emit-llvm -verify -fno-default-header -DNO_HEADER %s
// CHECK: _Z16convert_char_rtec
char f(char x) {
  return convert_char_rte(x);
#ifdef NO_HEADER
  //expected-warning@-2{{implicit declaration of function 'convert_char_rte' is invalid in C99}}
#endif
}
