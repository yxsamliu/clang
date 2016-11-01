// RUN: %clang_cc1 %s -cl-std=CL2.0 -triple amdgcn -emit-llvm -o - | FileCheck %s

// CHECK: @private_p = local_unnamed_addr addrspace(1) global i8* addrspacecast (i8 addrspace(4)* null to i8*), align 4
private char *private_p = 0;

// CHECK: @local_p = local_unnamed_addr addrspace(1) global i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*), align 4
local char *local_p = 0;

// CHECK: @global_p = local_unnamed_addr addrspace(1) global i8 addrspace(1)* null, align 4
global char *global_p = 0;

// CHECK: @constant_p = local_unnamed_addr addrspace(1) global i8 addrspace(2)* null, align 4
constant char *constant_p = 0;

// CHECK: @generic_p = local_unnamed_addr addrspace(1) global i8 addrspace(4)* null, align 4
generic char *generic_p = 0;

// CHECK: icmp eq i8* %p, addrspacecast (i8 addrspace(4)* null to i8*)
void cmp_private(private char* p) {
  if (p != 0)
    *p = 0;
}

// CHECK: icmp eq i8 addrspace(3)* %p, addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*)
void cmp_local(local char* p) {
  if (p != 0)
    *p = 0;
}

// CHECK: icmp eq i8 addrspace(1)* %p, null
void cmp_global(global char* p) {
  if (p != 0)
    *p = 0;
}

// CHECK: icmp eq i8 addrspace(2)* %p, null
char cmp_constant(constant char* p) {
  if (p != 0)
    return *p;
  else
    return 0;
}

// CHECK: icmp eq i8 addrspace(4)* %p, null
void cmp_generic(generic char* p) {
  if (p != 0)
    *p = 0;
}

