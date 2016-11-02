// RUN: %clang_cc1 %s -cl-std=CL2.0 -include opencl-c.h -triple amdgcn -emit-llvm -o - | FileCheck %s

// Test 0 as initializer.

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

// Test NULL as initializer.

// CHECK: @private_p_NULL = local_unnamed_addr addrspace(1) global i8* addrspacecast (i8 addrspace(4)* null to i8*), align 4
private char *private_p_NULL = NULL;

// CHECK: @local_p_NULL = local_unnamed_addr addrspace(1) global i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*), align 4
local char *local_p_NULL = NULL;

// CHECK: @global_p_NULL = local_unnamed_addr addrspace(1) global i8 addrspace(1)* null, align 4
global char *global_p_NULL = NULL;

// CHECK: @constant_p_NULL = local_unnamed_addr addrspace(1) global i8 addrspace(2)* null, align 4
constant char *constant_p_NULL = NULL;

// CHECK: @generic_p_NULL = local_unnamed_addr addrspace(1) global i8 addrspace(4)* null, align 4
generic char *generic_p_NULL = NULL;

// Test comparison with 0.

// CHECK-LABEL: cmp_private
// CHECK: icmp eq i8* %p, addrspacecast (i8 addrspace(4)* null to i8*)
void cmp_private(private char* p) {
  if (p != 0)
    *p = 0;
}

// CHECK-LABEL: cmp_local
// CHECK: icmp eq i8 addrspace(3)* %p, addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*)
void cmp_local(local char* p) {
  if (p != 0)
    *p = 0;
}

// CHECK-LABEL: cmp_global
// CHECK: icmp eq i8 addrspace(1)* %p, null
void cmp_global(global char* p) {
  if (p != 0)
    *p = 0;
}

// CHECK-LABEL: cmp_constant
// CHECK: icmp eq i8 addrspace(2)* %p, null
char cmp_constant(constant char* p) {
  if (p != 0)
    return *p;
  else
    return 0;
}

// CHECK-LABEL: cmp_generic
// CHECK: icmp eq i8 addrspace(4)* %p, null
void cmp_generic(generic char* p) {
  if (p != 0)
    *p = 0;
}

// Test comparison with NULL.

// CHECK-LABEL: cmp_NULL_private
// CHECK: icmp eq i8* %p, addrspacecast (i8 addrspace(4)* null to i8*)
void cmp_NULL_private(private char* p) {
  if (p != NULL)
    *p = 0;
}

// CHECK-LABEL: cmp_NULL_local
// CHECK: icmp eq i8 addrspace(3)* %p, addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*)
void cmp_NULL_local(local char* p) {
  if (p != NULL)
    *p = 0;
}

// CHECK-LABEL: cmp_NULL_global
// CHECK: icmp eq i8 addrspace(1)* %p, addrspacecast (i8 addrspace(4)* null to i8 addrspace(1)*)
void cmp_NULL_global(global char* p) {
  if (p != NULL)
    *p = 0;
}

// CHECK-LABEL: cmp_NULL_constant
// CHECK: icmp eq i8 addrspace(2)* %p, addrspacecast (i8 addrspace(4)* null to i8 addrspace(2)*)
char cmp_NULL_constant(constant char* p) {
  if (p != NULL)
    return *p;
  else
    return 0;
}

// CHECK-LABEL: cmp_NULL_generic
// CHECK: icmp eq i8 addrspace(4)* %p, null
void cmp_NULL_generic(generic char* p) {
  if (p != NULL)
    *p = 0;
}

// Test storage 0 as null pointer.
// CHECK-LABEL: test_storage_null_pointer
// CHECK: store i8* addrspacecast (i8 addrspace(4)* null to i8*), i8* addrspace(4)* %arg_private
// CHECK: store i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*), i8 addrspace(3)* addrspace(4)* %arg_local
// CHECK: store i8 addrspace(1)* null, i8 addrspace(1)* addrspace(4)* %arg_global
// CHECK: store i8 addrspace(2)* null, i8 addrspace(2)* addrspace(4)* %arg_constant
// CHECK: store i8 addrspace(4)* null, i8 addrspace(4)* addrspace(4)* %arg_generic
void test_storage_null_pointer(private char** arg_private,
                               local char** arg_local,
                               global char** arg_global,
                               constant char** arg_constant,
                               generic char** arg_generic) {
   *arg_private = 0;
   *arg_local = 0;
   *arg_global = 0;
   *arg_constant = 0;
   *arg_generic = 0;
}

// Test storage NULL as null pointer.
// CHECK-LABEL: test_storage_null_pointer_NULL
// CHECK: store i8* addrspacecast (i8 addrspace(4)* null to i8*), i8* addrspace(4)* %arg_private
// CHECK: store i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*), i8 addrspace(3)* addrspace(4)* %arg_local
// CHECK: store i8 addrspace(1)* null, i8 addrspace(1)* addrspace(4)* %arg_global
// CHECK: store i8 addrspace(2)* null, i8 addrspace(2)* addrspace(4)* %arg_constant
// CHECK: store i8 addrspace(4)* null, i8 addrspace(4)* addrspace(4)* %arg_generic
void test_storage_null_pointer_NULL(private char** arg_private,
                                    local char** arg_local,
                                    global char** arg_global,
                                    constant char** arg_constant,
                                    generic char** arg_generic) {
   *arg_private = NULL;
   *arg_local = NULL;
   *arg_global = NULL;
   *arg_constant = NULL;
   *arg_generic = NULL;
}

// Test pass null pointer to function as argument.
void test_pass_null_pointer_arg_calee(private char* arg_private,
                                      local char* arg_local,
                                      global char* arg_global,
                                      constant char* arg_constant,
                                      generic char* arg_generic);

// CHECK-LABEL: test_pass_null_pointer_arg
// CHECK: call void @test_pass_null_pointer_arg_calee(i8* addrspacecast (i8 addrspace(4)* null to i8*), i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*), i8 addrspace(1)* null, i8 addrspace(2)* null, i8 addrspace(4)* null)
// CHECK: call void @test_pass_null_pointer_arg_calee(i8* addrspacecast (i8 addrspace(4)* null to i8*), i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*), i8 addrspace(1)* null, i8 addrspace(2)* null, i8 addrspace(4)* null)
void test_pass_null_pointer_arg(void) {
  test_pass_null_pointer_arg_calee(0, 0, 0, 0, 0);
  test_pass_null_pointer_arg_calee(NULL, NULL, NULL, NULL, NULL);
}

// Test cast null pointer to size_t.
void test_cast_null_pointer_to_sizet_calee(size_t arg_private,
                                           size_t arg_local,
                                           size_t arg_global,
                                           size_t arg_constant,
                                           size_t arg_generic);

// CHECK-LABEL: test_cast_null_pointer_to_sizet
// CHECK: call void @test_cast_null_pointer_to_sizet_calee(i64 ptrtoint (i8* addrspacecast (i8 addrspace(4)* null to i8*) to i64), i64 ptrtoint (i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*) to i64), i64 0, i64 0, i64 0)
// CHeCK: call void @test_cast_null_pointer_to_sizet_calee(i64 ptrtoint (i8* addrspacecast (i8 addrspace(4)* null to i8*) to i64), i64 ptrtoint (i8 addrspace(3)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*) to i64), i64 ptrtoint (i8 addrspace(1)* addrspacecast (i8 addrspace(4)* null to i8 addrspace(1)*) to i64), i64 0, i64 0)
void test_cast_null_pointer_to_sizet(void) {
  test_cast_null_pointer_to_sizet_calee((size_t)((private char*)0),
                                        (size_t)((local char*)0),
                                        (size_t)((global char*)0),
                                        (size_t)((constant char*)0),
                                        (size_t)((generic char*)0));
  test_cast_null_pointer_to_sizet_calee((size_t)((private char*)NULL),
                                        (size_t)((local char*)NULL),
                                        (size_t)((global char*)NULL),
                                        (size_t)((constant char*)0), // NULL cannot be casted to constant pointer since it is defined as a generic pointer
                                        (size_t)((generic char*)NULL));
}

#define TEST_EQ_0_0(addr) int test_compare_nullptr_with_nullptr(void) { return (addr char*)0 == (addr char*)0; }
#define TEST_EQ_0_NULL(addr) int test_compare_nullptr_with_nullptr(void) { return (addr char*)0 == (addr char*)NULL; }
#define TEST_EQ_NULL_NULL(addr) int test_compare_nullptr_with_nullptr(void) { return (addr char*)0 == (addr char*)NULL; }
#define TEST_NE_0_0(addr) int test_compare_nullptr_with_nullptr(void) { return (addr char*)0 != (addr char*)0; }
#define TEST_NE_0_NULL(addr) int test_compare_nullptr_with_nullptr(void) { return (addr char*)0 != (addr char*)NULL; }
#define TEST_NE_NULL_NULL(addr) int test_compare_nullptr_with_nullptr(void) { return (addr char*)0 != (addr char*)NULL; }

// Test cast to bool.

// CHECK-LABEL: cast_bool_private
// CHECK: icmp eq i8* %p, addrspacecast (i8 addrspace(4)* null to i8*)
void cast_bool_private(private char* p) {
  if (p)
    *p = 0;
}

// CHECK-LABEL: cast_bool_local
// CHECK: icmp eq i8 addrspace(3)* %p, addrspacecast (i8 addrspace(4)* null to i8 addrspace(3)*)
void cast_bool_local(local char* p) {
  if (p)
    *p = 0;
}

// CHECK-LABEL: cast_bool_global
// CHECK: icmp eq i8 addrspace(1)* %p, null
void cast_bool_global(global char* p) {
  if (p)
    *p = 0;
}

// CHECK-LABEL: cast_bool_constant
// CHECK: icmp eq i8 addrspace(2)* %p, null
char cast_bool_constant(constant char* p) {
  if (p)
    return *p;
  else
    return 0;
}

// CHECK-LABEL: cast_bool_generic
// CHECK: icmp eq i8 addrspace(4)* %p, null
void cast_bool_generic(generic char* p) {
  if (p)
    *p = 0;
}


