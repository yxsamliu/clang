// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -o - -O0 -triple spir-unknown-unknown | FileCheck -check-prefixes=COMMON,SPIR %s
// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -o - -O0 -triple amdgcn-amd-amdhsa-opencl | FileCheck -check-prefixes=COMMON,AMD %s

// COMMON: %struct.__opencl_block_literal_generic = type { i32, i32, i8 addrspace(4)* }
// SPIR: @__block_literal_global = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 12, i32 4, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(4)*, i8 addrspace(3)*)* @block_A_block_invoke to i8*) to i8 addrspace(4)*) }
// AMD: @__block_literal_global = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 16, i32 8, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(4)*, i8 addrspace(3)*)* @block_A_block_invoke to i8*) to i8 addrspace(4)*) }
// COMMON-NOT: .str

// COMMON-LABEL: define internal {{.*}}void @block_A_block_invoke(i8 addrspace(4)* %.block_descriptor, i8 addrspace(3)* %a)
void (^block_A)(local void *) = ^(local void *a) {
  return;
};

// COMMON-LABEL: define {{.*}}void @foo()
void foo(){
  int i;
  // COMMON-NOT: store i8* null, i8** %block.isa
  // COMMON: %[[block_size:.*]] = getelementptr inbounds <{ i32, i32, i8 addrspace(4)*, i32 }>, <{ i32, i32, i8 addrspace(4)*, i32 }>* %block, i32 0, i32 0
  // SPIR: store i32 16, i32* %[[block_size]]
  // AMD: store i32 20, i32* %[[block_size]]
  // COMMON: %[[block_align:.*]] = getelementptr inbounds <{ i32, i32, i8 addrspace(4)*, i32 }>, <{ i32, i32, i8 addrspace(4)*, i32 }>* %block, i32 0, i32 1
  // SPIR: store i32 4, i32* %[[block_align]]
  // AMD: store i32 8, i32* %[[block_align]]
  // COMMON: %[[block_invoke:.*]] = getelementptr inbounds <{ i32, i32, i8 addrspace(4)*, i32 }>, <{ i32, i32, i8 addrspace(4)*, i32 }>* %[[block:.*]], i32 0, i32 2
  // COMMON: store i8 addrspace(4)* addrspacecast (i8* bitcast (i32 (i8 addrspace(4)*)* @__foo_block_invoke to i8*) to i8 addrspace(4)*), i8 addrspace(4)** %[[block_invoke]]
  // COMMON: %[[block_captured:.*]] = getelementptr inbounds <{ i32, i32, i8 addrspace(4)*, i32 }>, <{ i32, i32, i8 addrspace(4)*, i32 }>* %[[block]], i32 0, i32 3
  // COMMON: %[[r0:.*]] = load i32, i32* %i
  // COMMON: store i32 %[[r0]], i32* %[[block_captured]],
  // COMMON: %[[r1:.*]] = bitcast <{ i32, i32, i8 addrspace(4)*, i32 }>* %[[block]] to i32 ()*
  // COMMON: %[[r2:.*]] = addrspacecast i32 ()* %[[r1]] to i32 () addrspace(4)*
  // COMMON: store i32 () addrspace(4)* %[[r2]], i32 () addrspace(4)** %[[block_B:.*]],
  // COMMON: %[[r3:.*]] = load i32 () addrspace(4)*, i32 () addrspace(4)** %[[block_B]]
  // COMMON: %[[block_literal:.*]] = bitcast i32 () addrspace(4)* %3 to %struct.__opencl_block_literal_generic addrspace(4)*
  // COMMON: %[[r4:.*]] = getelementptr inbounds %struct.__opencl_block_literal_generic, %struct.__opencl_block_literal_generic addrspace(4)* %[[block_literal]], i32 0, i32 2
  // COMMON: %[[r5:.*]] = bitcast %struct.__opencl_block_literal_generic addrspace(4)* %[[block_literal]] to i8 addrspace(4)*
  // COMMON: %[[r6:.*]] = load i8 addrspace(4)*, i8 addrspace(4)* addrspace(4)* %[[r4]]
  // COMMON: %[[r7:.*]] = addrspacecast i8 addrspace(4)* %[[r6]] to i32 (i8 addrspace(4)*)*
  // COMMON: call {{.*}}i32 %[[r7]](i8 addrspace(4)* %[[r5]])

  int (^ block_B)(void) = ^{
    return i;
  };
  block_B();
}

// COMMON-LABEL: define internal {{.*}}i32 @__foo_block_invoke(i8 addrspace(4)* %.block_descriptor)
// COMMON:  %[[block:.*]] = bitcast i8 addrspace(4)* %.block_descriptor to <{ i32, i32, i8 addrspace(4)*, i32 }> addrspace(4)*
// COMMON:  %[[block_capture_addr:.*]] = getelementptr inbounds <{ i32, i32, i8 addrspace(4)*, i32 }>, <{ i32, i32, i8 addrspace(4)*, i32 }> addrspace(4)* %[[block]], i32 0, i32 3
// COMMON:  %[[r1:.*]] = load i32, i32 addrspace(4)* %[[block_capture_addr]]
