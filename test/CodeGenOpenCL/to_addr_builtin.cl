// RUN: %clang_cc1 -triple spir-unknown-unknown -emit-llvm -O0 -cl-std=CL2.0 -o - %s | FileCheck %s

void test(void) {
  global int *glob;
  local int *loc;
  private int *priv;
  generic int *gen;

  //CHECK: call i32 addrspace(1)* @_Z9to_globalPU3AS1v(i32 addrspace(1)* %{{.*}})
  glob = to_global(glob);
  
  //CHECK: call i32 addrspace(1)* @_Z9to_globalPU3AS3v(i32 addrspace(3)* %{{.*}})
  glob = to_global(loc);
 
   //CHECK: call i32 addrspace(1)* @_Z9to_globalPv(i32* %{{.*}})
  glob = to_global(priv);
 
   //CHECK: call i32 addrspace(1)* @_Z9to_globalPU3AS4v(i32 addrspace(4)* %{{.*}})
  glob = to_global(gen);
  
  //CHECK: call i32 addrspace(3)* @_Z8to_localPU3AS1v(i32 addrspace(1)* %{{.*}})
  loc = to_local(glob);

  //CHECK: call i32 addrspace(3)* @_Z8to_localPU3AS3v(i32 addrspace(3)* %{{.*}})
  loc = to_local(loc);

  //CHECK: call i32 addrspace(3)* @_Z8to_localPv(i32* %{{.*}})
  loc = to_local(priv);

  //CHECK: call i32 addrspace(3)* @_Z8to_localPU3AS4v(i32 addrspace(4)* %{{.*}})
  loc = to_local(gen);

  //CHECK: call i32* @_Z10to_privatePU3AS1v(i32 addrspace(1)* %{{.*}})
  priv = to_private(glob);

  //CHECK: call i32* @_Z10to_privatePU3AS3v(i32 addrspace(3)* %{{.*}})
  priv = to_private(loc);

  //CHECK: call i32* @_Z10to_privatePv(i32* %{{.*}})
  priv = to_private(priv);

  //CHECK: call i32* @_Z10to_privatePU3AS4v(i32 addrspace(4)* %{{.*}})
  priv = to_private(gen);
}
