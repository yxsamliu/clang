// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -o - -O0 -triple spir-unknown-unknown | FileCheck -check-prefix=GENERIC -check-prefix=COMMON %s
// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -o - -O0 -triple amdgcn-amd-amdhsa-opencl | FileCheck -check-prefix=AMD -check-prefix=COMMON %s

// COMMON: @__block_literal_global = internal addrspace(1) constant { i8* } { i8* bitcast (void (i8 addrspace(4)*, i8 addrspace(3)*)* @block_A_block_invoke to i8*) }, align 4
void (^block_A)(local void *) = ^(local void *a) {
  return;
};

void foo(){
  int i;
// COMMON-NOT: store i8* null, i8** %block.isa
  int (^ block_B)(void) = ^{
    return i;
  };
}
