// RUN: %clang_cc1 -triple spir-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple spir-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -triple spir-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -triple spir-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -triple spir64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple spir64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -triple spir64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -triple spir64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -triple amdgcn-unknown-amdhsa -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple amdgcn-unknown-amdhsa -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -triple amdgcn-unknown-amdhsa -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -triple amdgcn-unknown-amdhsa -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -triple ppc64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple ppc64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -triple ppc64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -triple ppc64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -triple powerpc-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple powerpc-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -triple powerpc-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -triple powerpc-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -triple nvptx-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple nvptx-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -triple nvptx-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -triple nvptx-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.1| FileCheck %s
// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -emit-llvm -o - %s -cl-std=CL1.2| FileCheck %s
// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -internal-isystem ../../lib/Headers -include opencl-c.h -fblocks -emit-llvm -o - %s -cl-std=CL2.0| FileCheck --check-prefix=CHECK20 %s

// RUN: %clang_cc1 -finclude-default-header -emit-llvm -o - %s | FileCheck %s
// CHECK: _Z16convert_char_rtec
// CHECK20: _Z3ctzc

// Test including the default header as a module.
// The module should be compiled only once and loaded from cache afterwards.

// ===
// Clear current directory.
// RUN: rm -rf %t
// RUN: mkdir -p %t

// ===
// Compile for OpenCL 1.0 for the first time. A module should be generated.
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -fdisable-module-hash %s | FileCheck %s
// RUN: cp %t/opencl_c.pcm %t/1_0.pcm

// ===
// Compile for OpenCL 1.0 for the second time. The module should not change.
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -fdisable-module-hash %s | FileCheck %s
// RUN: diff %t/1_0.pcm %t/opencl_c.pcm
// RUN: rm %t/opencl_c.pcm

// ===
// Compile for OpenCL 2.0 for the first time. The module should change.
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -cl-std=CL2.0 -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -fdisable-module-hash %s | FileCheck --check-prefix=CHECK20 %s
// RUN: not diff %t/1_0.pcm %t/opencl_c.pcm
// RUN: cp %t/opencl_c.pcm %t/2_0.pcm

// ===
// Compile for OpenCL 2.0 for the second time. The module should not change.
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -cl-std=CL2.0 -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -fdisable-module-hash %s | FileCheck --check-prefix=CHECK20 %s
// RUN: diff %t/2_0.pcm %t/opencl_c.pcm

// Check cached module works for different OpenCL versions.
// RUN: rm -rf %t
// RUN: mkdir -p %t
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s | FileCheck %s
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -cl-std=CL2.0 -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s | FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -cc1 -triple amdgcn--amdhsa -emit-llvm -o - -cl-std=CL2.0  -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s | FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s | FileCheck %s
// RUN: %clang_cc1 -cc1 -triple spir-unknown-unknown -emit-llvm -o - -cl-std=CL2.0 -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s | FileCheck --check-prefix=CHECK20 %s
// RUN: %clang_cc1 -cc1 -triple amdgcn--amdhsa -emit-llvm -o - -cl-std=CL2.0 -finclude-default-header -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s | FileCheck --check-prefix=CHECK20 %s

char f(char x) {
#if __OPENCL_C_VERSION__ != CL_VERSION_2_0
  return convert_char_rte(x);
#ifdef NO_HEADER
  //expected-warning@-2{{implicit declaration of function 'convert_char_rte' is invalid in C99}}
#endif //NO_HEADER

#else //__OPENCL_C_VERSION__
  return ctz(x);
#endif //__OPENCL_C_VERSION__
}
