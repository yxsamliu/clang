// RUN: %clang_cc1 %s -cl-std=CL2.0 -finclude-default-header -emit-llvm -triple spir-unknown-unknown -o - | FileCheck --check-prefix=SZ32 %s
// RUN: %clang_cc1 %s -cl-std=CL2.0 -finclude-default-header -emit-llvm -triple spir64-unknown-unknown -o - | FileCheck --check-prefix=SZ64 %s
// RUN: %clang_cc1 %s -cl-std=CL2.0 -finclude-default-header -emit-llvm -triple amdgcn-- -o - | FileCheck --check-prefix=SZ64 %s

//SZ32: define spir_func i32 @test_private(i8* %x)
//SZ32: ptrtoint i8* %x to i32
//SZ64: define spir_func i64 @test_private(i8* %x)
//SZ64: ptrtoint i8* %x to i64
size_t test_private(private char* x) {
  return (size_t)x;
}

//SZ32: define spir_func i32 @test_global(i8 addrspace(1)* %x)
//SZ32: ptrtoint i8 addrspace(1)* %x to i32
//SZ64: define spir_func i64 @test_global(i8 addrspace(1)* %x)
//SZ64: ptrtoint i8 addrspace(1)* %x to i64
intptr_t test_global(global char* x) {
  return (intptr_t)x;
}

//SZ32: define spir_func i32 @test_constant(i8 addrspace(2)* %x)
//SZ32: ptrtoint i8 addrspace(2)* %x to i32
//SZ64: define spir_func i64 @test_constant(i8 addrspace(2)* %x)
//SZ64: ptrtoint i8 addrspace(2)* %x to i64
uintptr_t test_constant(constant char* x) {
  return (uintptr_t)x;
}

//SZ32: define spir_func i32 @test_local(i8 addrspace(3)* %x, i8 addrspace(3)* %y)
//SZ32: ptrtoint i8 addrspace(3)* %x to i32
//SZ32: ptrtoint i8 addrspace(3)* %y to i32
//SZ64: define spir_func i64 @test_local(i8 addrspace(3)* %x, i8 addrspace(3)* %y)
//SZ64: ptrtoint i8 addrspace(3)* %x to i64
//SZ64: ptrtoint i8 addrspace(3)* %y to i64
ptrdiff_t test_local(local char* x, local char *y) {
  return (ptrdiff_t)(x - y);
}

//SZ32: define spir_func i32 @test_generic(i8 addrspace(4)* %x)
//SZ32: ptrtoint i8 addrspace(4)* %x to i32
//SZ64: define spir_func i64 @test_generic(i8 addrspace(4)* %x)
//SZ64: ptrtoint i8 addrspace(4)* %x to i64
size_t test_generic(generic char* x) {
  return (size_t)x;
}
