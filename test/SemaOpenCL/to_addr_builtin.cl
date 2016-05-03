// RUN: %clang_cc1 -verify -syntax-only
// RUN: %clang_cc1 -verify -syntax-only -cl-std=CL2.0

void test(void) {
  global *glob;
  local *loc;
  constant *con;

  glob = to_global(glob, loc);
  glob = to_global(con);
  loc = to_global(glob);
}
