// RUN: %clang_cc1 %s -cl-std=CL2.0 -verify -triple spir-unknown-unknown
// RUN: %clang_cc1 %s -cl-std=CL2.0 -verify -triple spir64-unknown-unknown
// RUN: %clang_cc1 %s -cl-std=CL2.0 -verify -triple amdgcn--

size_t test_private(private char* x) {
  return x;
}

intptr_t test_global(global char* x) {
  return x;
}

uintptr_t test_constant(constant char* x) {
  return x;
}

ptrdiff_t test_local(local char* x, local char *y) {
  return x - y;
}

size_t test_generic(generic char* x) {
  return x;
}
