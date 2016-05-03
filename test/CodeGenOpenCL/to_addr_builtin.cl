// RUN: %clang_cc1 -emit-llvm -O0 -cl-std=CL2.0 -o - %s | FileCheck %s

void test(void) {
  global *glob;
  local *loc;
  private *priv;
  generic *gen;

  glob = to_global(glob);
  glob = to_global(loc);
  glob = to_global(priv);
  glob = to_global(gen);

  loc = to_local(glob);
  loc = to_local(loc);
  loc = to_local(priv);
  loc = to_local(gen);

  priv = to_private(glob);
  priv = to_private(loc);
  priv = to_private(priv);
  priv = to_private(gen);
}
