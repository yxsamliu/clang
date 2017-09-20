// RUN: %clang_cc1 %s -cl-std=CL2.0 -ffake-address-space-map -O0 -emit-llvm -o - -triple "spir-unknown-unknown" | FileCheck %s --check-prefix=COMMON --check-prefix=B32
// RUN: %clang_cc1 %s -cl-std=CL2.0 -ffake-address-space-map -O0 -emit-llvm -o - -triple "spir64-unknown-unknown" | FileCheck %s --check-prefix=COMMON --check-prefix=B64

#pragma OPENCL EXTENSION cl_khr_subgroups : enable

typedef void (^bl_t)(local void *);
typedef struct {int a;} ndrange_t;

// COMMON: %struct.__opencl_block_literal_generic = type { i32, i32, i8 addrspace(4)* }

// For a block global variable, first emit the block literal as a global variable, then emit the block variable itself.
// COMMON: [[BL_GLOBAL:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(4)*, i8 addrspace(3)*)* [[INV_G:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: @block_G =  addrspace(1) constant void (i8 addrspace(3)*) addrspace(4)* addrspacecast (void (i8 addrspace(3)*) addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BL_GLOBAL]] to void (i8 addrspace(3)*) addrspace(1)*) to void (i8 addrspace(3)*) addrspace(4)*)

// For anonymous blocks without captures, emit block literals as global variable.
// COMMON: [[BLG1:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INVG1:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG2:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INVG2:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG3:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INVG3:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG4:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INVG4:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG5:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INVG5:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG6:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*, i8 addrspace(3)*, i8 addrspace(3)*)* [[INVG6:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG7:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INVG7:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG8:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(4)*)* [[INVG8:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG9:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(4)*, i8 addrspace(3)*)* [[INVG9:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG8K:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*)* [[INVG8K:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG9K:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INVG9K:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BL_GLOBAL_K:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*, i8 addrspace(3)*)* [[INV_G_K:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG10:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*)* [[INVG10:@[^ ]+]] to i8*) to i8 addrspace(4)*) }
// COMMON: [[BLG11:@__block_literal_global[^ ]*]] = internal addrspace(1) constant { i32, i32, i8 addrspace(4)* } { i32 {{[0-9]+}}, i32 {{[0-9]+}}, i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*)* [[INVG11:@[^ ]+]] to i8*) to i8 addrspace(4)*) }

// Emits block literal [[BL_GLOBAL]], invoke function [[INV_G]] and global block variable @block_G
// COMMON: define internal spir_func void [[INV_G]](i8 addrspace(4)* %.block_descriptor, i8 addrspace(3)* %a)
const bl_t block_G = (bl_t) ^ (local void *a) {};

// COMMON-LABEL: define spir_kernel void @device_side_enqueue(i32 addrspace(1)* %a, i32 addrspace(1)* %b, i32 %i)
kernel void device_side_enqueue(global int *a, global int *b, int i) {
  // COMMON: %default_queue = alloca %opencl.queue_t*
  queue_t default_queue;
  // COMMON: %flags = alloca i32
  unsigned flags = 0;
  // COMMON: %ndrange = alloca %struct.ndrange_t
  ndrange_t ndrange;
  // COMMON: %clk_event = alloca %opencl.clk_event_t*
  clk_event_t clk_event;
  // COMMON: %event_wait_list = alloca %opencl.clk_event_t*
  clk_event_t event_wait_list;
  // COMMON: %event_wait_list2 = alloca [1 x %opencl.clk_event_t*]
  clk_event_t event_wait_list2[] = {clk_event};

  // Emits block literal on stack and invoke function [[INVL1]].
  // COMMON: [[NDR:%[a-z0-9]+]] = alloca %struct.ndrange_t, align 4
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // COMMON: store i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*)* [[INVL1:@__device_side_enqueue_block_invoke[^ ]*]] to i8*) to i8 addrspace(4)*), i8 addrspace(4)** %block.invoke
  // B32: [[BL:%[0-9]+]] = bitcast <{ i32, i32, i8 addrspace(4)*, i32 addrspace(1)*, i32, i32 addrspace(1)* }>* %block to void ()*
  // B64: [[BL:%[0-9]+]] = bitcast <{ i32, i32, i8 addrspace(4)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 }>* %block to void ()*
  // COMMON: [[BL_I8:%[0-9]+]] = addrspacecast void ()* [[BL]] to i8 addrspace(4)*
  // COMMON-LABEL: call i32 @__enqueue_kernel_basic
  // COMMON-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* byval [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* [[BL_I8]])
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(void) {
                   a[i] = b[i];
                 });

  // Emits block literal on stack and invoke function [[INVL2]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // COMMON: [[WAIT_EVNT:%[0-9]+]] = addrspacecast %opencl.clk_event_t{{.*}}** %event_wait_list to %opencl.clk_event_t{{.*}}* addrspace(4)*
  // COMMON: [[EVNT:%[0-9]+]] = addrspacecast %opencl.clk_event_t{{.*}}** %clk_event to %opencl.clk_event_t{{.*}}* addrspace(4)*
  // COMMON: store i8 addrspace(4)* addrspacecast (i8* bitcast (void (i8 addrspace(1)*)* [[INVL2:@__device_side_enqueue_block_invoke[^ ]*]] to i8*) to i8 addrspace(4)*), i8 addrspace(4)** %block.invoke
  // COMMON: [[BL:%[0-9]+]] = bitcast <{ i32, i32, i8 addrspace(4)*, i32{{.*}}, i32{{.*}}, i32{{.*}} }>* %block3 to void ()*
  // COMMON: [[BL_I8:%[0-9]+]] = addrspacecast void ()* [[BL]] to i8 addrspace(4)*
  // COMMON-LABEL: call i32 @__enqueue_kernel_basic_events
  // COMMON-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]],  %struct.ndrange_t* {{.*}}, i32 2, %opencl.clk_event_t{{.*}}* addrspace(4)* [[WAIT_EVNT]], %opencl.clk_event_t{{.*}}* addrspace(4)* [[EVNT]], i8 addrspace(4)* [[BL_I8]])
  enqueue_kernel(default_queue, flags, ndrange, 2, &event_wait_list, &clk_event,
                 ^(void) {
                   a[i] = b[i];
                 });

  // Emits global block literal [[BLG1]] and invoke function [[INVG1]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // B32: %[[TMP:.*]] = alloca [1 x i32]
  // B32: %[[TMP1:.*]] = getelementptr [1 x i32], [1 x i32]* %[[TMP]], i32 0, i32 0
  // B32: store i32 256, i32* %[[TMP1]], align 4
  // B32-LABEL: call i32 @__enqueue_kernel_vaargs
  // B32-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG1]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i32* %[[TMP1]])
  // B64: %[[TMP:.*]] = alloca [1 x i64]
  // B64: %[[TMP1:.*]] = getelementptr [1 x i64], [1 x i64]* %[[TMP]], i32 0, i32 0
  // B64: store i64 256, i64* %[[TMP1]], align 8
  // B64-LABEL: call i32 @__enqueue_kernel_vaargs
  // B64-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG1]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i64* %[[TMP1]])
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(local void *p) {
                   return;
                 },
                 256);
  char c;
  // Emits global block literal [[BLG2]] and invoke function [[INVG2]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // B32: %[[TMP:.*]] = alloca [1 x i32]
  // B32: %[[TMP1:.*]] = getelementptr [1 x i32], [1 x i32]* %[[TMP]], i32 0, i32 0
  // B32: store i32 %{{.*}}, i32* %[[TMP1]], align 4
  // B32-LABEL: call i32 @__enqueue_kernel_vaargs
  // B32-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG2]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i32* %[[TMP1]])
  // B64: %[[TMP:.*]] = alloca [1 x i64]
  // B64: %[[TMP1:.*]] = getelementptr [1 x i64], [1 x i64]* %[[TMP]], i32 0, i32 0
  // B64: store i64 %{{.*}}, i64* %[[TMP1]], align 8
  // B64-LABEL: call i32 @__enqueue_kernel_vaargs
  // B64-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG2]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i64* %[[TMP1]])
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(local void *p) {
                   return;
                 },
                 c);

  // Emits global block literal [[BLG3]] and invoke function [[INVG3]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // COMMON: [[AD:%arraydecay[0-9]*]] = getelementptr inbounds [1 x %opencl.clk_event_t*], [1 x %opencl.clk_event_t*]* %event_wait_list2, i32 0, i32 0
  // COMMON: [[WAIT_EVNT:%[0-9]+]] = addrspacecast %opencl.clk_event_t{{.*}}** [[AD]] to %opencl.clk_event_t{{.*}}* addrspace(4)*
  // COMMON: [[EVNT:%[0-9]+]]  = addrspacecast %opencl.clk_event_t{{.*}}** %clk_event to %opencl.clk_event_t{{.*}}* addrspace(4)*
  // B32: %[[TMP:.*]] = alloca [1 x i32]
  // B32: %[[TMP1:.*]] = getelementptr [1 x i32], [1 x i32]* %[[TMP]], i32 0, i32 0
  // B32: store i32 256, i32* %[[TMP1]], align 4
  // B32-LABEL: call i32 @__enqueue_kernel_events_vaargs
  // B32-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]],  %struct.ndrange_t* {{.*}}, i32 2, %opencl.clk_event_t{{.*}} [[WAIT_EVNT]], %opencl.clk_event_t{{.*}} [[EVNT]], i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG3]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i32* %[[TMP1]])
  // B64: %[[TMP:.*]] = alloca [1 x i64]
  // B64: %[[TMP1:.*]] = getelementptr [1 x i64], [1 x i64]* %[[TMP]], i32 0, i32 0
  // B64: store i64 256, i64* %[[TMP1]], align 8
  // B64-LABEL: call i32 @__enqueue_kernel_events_vaargs
  // B64-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]],  %struct.ndrange_t* {{.*}}, i32 2, %opencl.clk_event_t{{.*}} [[WAIT_EVNT]], %opencl.clk_event_t{{.*}} [[EVNT]], i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG3]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i64* %[[TMP1]])
  enqueue_kernel(default_queue, flags, ndrange, 2, event_wait_list2, &clk_event,
                 ^(local void *p) {
                   return;
                 },
                 256);

  // Emits global block literal [[BLG4]] and invoke function [[INVG4]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // COMMON: [[AD:%arraydecay[0-9]*]] = getelementptr inbounds [1 x %opencl.clk_event_t*], [1 x %opencl.clk_event_t*]* %event_wait_list2, i32 0, i32 0
  // COMMON: [[WAIT_EVNT:%[0-9]+]] = addrspacecast %opencl.clk_event_t{{.*}}** [[AD]] to %opencl.clk_event_t{{.*}}* addrspace(4)*
  // COMMON: [[EVNT:%[0-9]+]]  = addrspacecast %opencl.clk_event_t{{.*}}** %clk_event to %opencl.clk_event_t{{.*}}* addrspace(4)*
  // B32: %[[TMP:.*]] = alloca [1 x i32]
  // B32: %[[TMP1:.*]] = getelementptr [1 x i32], [1 x i32]* %[[TMP]], i32 0, i32 0
  // B32: store i32 %{{.*}}, i32* %[[TMP1]], align 4
  // B32-LABEL: call i32 @__enqueue_kernel_events_vaargs
  // B32-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]],  %struct.ndrange_t* {{.*}}, i32 2, %opencl.clk_event_t{{.*}}* addrspace(4)* [[WAIT_EVNT]], %opencl.clk_event_t{{.*}}* addrspace(4)* [[EVNT]], i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG4]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i32* %[[TMP1]])
  // B64: %[[TMP:.*]] = alloca [1 x i64]
  // B64: %[[TMP1:.*]] = getelementptr [1 x i64], [1 x i64]* %[[TMP]], i32 0, i32 0
  // B64: store i64 %{{.*}}, i64* %[[TMP1]], align 8
  // B64-LABEL: call i32 @__enqueue_kernel_events_vaargs
  // B64-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]],  %struct.ndrange_t* {{.*}}, i32 2, %opencl.clk_event_t{{.*}}* addrspace(4)* [[WAIT_EVNT]], %opencl.clk_event_t{{.*}}* addrspace(4)* [[EVNT]], i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG4]] to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i64* %[[TMP1]])
  enqueue_kernel(default_queue, flags, ndrange, 2, event_wait_list2, &clk_event,
                 ^(local void *p) {
                   return;
                 },
                 c);

  long l;
  // Emits global block literal [[BLG5]] and invoke function [[INVG5]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // B32: %[[TMP:.*]] = alloca [1 x i32]
  // B32: %[[TMP1:.*]] = getelementptr [1 x i32], [1 x i32]* %[[TMP]], i32 0, i32 0
  // B32: store i32 %{{.*}}, i32* %[[TMP1]], align 4
  // B32-LABEL: call i32 @__enqueue_kernel_vaargs
  // B32-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* @__block_literal_global{{(.[0-9]+)?}} to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i32* %[[TMP1]])
  // B64: %[[TMP:.*]] = alloca [1 x i64]
  // B64: %[[TMP1:.*]] = getelementptr [1 x i64], [1 x i64]* %[[TMP]], i32 0, i32 0
  // B64: store i64 %{{.*}}, i64* %[[TMP1]], align 8
  // B64-LABEL: call i32 @__enqueue_kernel_vaargs
  // B64-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* @__block_literal_global{{(.[0-9]+)?}} to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i64* %[[TMP1]])
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(local void *p) {
                   return;
                 },
                 l);

  // Emits global block literal [[BLG6]] and invoke function [[INVG6]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t{{.*}}*, %opencl.queue_t{{.*}}** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // B32: %[[TMP:.*]] = alloca [3 x i32]
  // B32: %[[TMP1:.*]] = getelementptr [3 x i32], [3 x i32]* %[[TMP]], i32 0, i32 0
  // B32: store i32 1, i32* %[[TMP1]], align 4
  // B32: %[[TMP2:.*]] = getelementptr [3 x i32], [3 x i32]* %[[TMP]], i32 0, i32 1
  // B32: store i32 2, i32* %[[TMP2]], align 4
  // B32: %[[TMP3:.*]] = getelementptr [3 x i32], [3 x i32]* %[[TMP]], i32 0, i32 2
  // B32: store i32 4, i32* %[[TMP3]], align 4
  // B32-LABEL: call i32 @__enqueue_kernel_vaargs
  // B32-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* @__block_literal_global{{(.[0-9]+)?}} to i8 addrspace(1)*) to i8 addrspace(4)*), i32 3, i32* %[[TMP1]])
  // B64: %[[TMP:.*]] = alloca [3 x i64]
  // B64: %[[TMP1:.*]] = getelementptr [3 x i64], [3 x i64]* %[[TMP]], i32 0, i32 0
  // B64: store i64 1, i64* %[[TMP1]], align 8
  // B64: %[[TMP2:.*]] = getelementptr [3 x i64], [3 x i64]* %[[TMP]], i32 0, i32 1
  // B64: store i64 2, i64* %[[TMP2]], align 8
  // B64: %[[TMP3:.*]] = getelementptr [3 x i64], [3 x i64]* %[[TMP]], i32 0, i32 2
  // B64: store i64 4, i64* %[[TMP3]], align 8
  // B64-LABEL: call i32 @__enqueue_kernel_vaargs
  // B64-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* @__block_literal_global{{(.[0-9]+)?}} to i8 addrspace(1)*) to i8 addrspace(4)*), i32 3, i64* %[[TMP1]])
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(local void *p1, local void *p2, local void *p3) {
                   return;
                 },
                 1, 2, 4);

  // Emits global block literal [[BLG7]] and invoke function [[INVG7]].
  // COMMON: [[DEF_Q:%[0-9]+]] = load %opencl.queue_t*, %opencl.queue_t** %default_queue
  // COMMON: [[FLAGS:%[0-9]+]] = load i32, i32* %flags
  // B32: %[[TMP:.*]] = alloca [1 x i32]
  // B32: %[[TMP1:.*]] = getelementptr [1 x i32], [1 x i32]* %[[TMP]], i32 0, i32 0
  // B32: store i32 0, i32* %[[TMP1]], align 4
  // B32-LABEL: call i32 @__enqueue_kernel_vaargs
  // B32-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* @__block_literal_global{{(.[0-9]+)?}} to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i32* %[[TMP1]])
  // B64: %[[TMP:.*]] = alloca [1 x i64]
  // B64: %[[TMP1:.*]] = getelementptr [1 x i64], [1 x i64]* %[[TMP]], i32 0, i32 0
  // B64: store i64 4294967296, i64* %[[TMP1]], align 8
  // B64-LABEL: call i32 @__enqueue_kernel_vaargs
  // B64-SAME: (%opencl.queue_t{{.*}}* [[DEF_Q]], i32 [[FLAGS]], %struct.ndrange_t* [[NDR]]{{([0-9]+)?}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* @__block_literal_global{{(.[0-9]+)?}} to i8 addrspace(1)*) to i8 addrspace(4)*), i32 1, i64* %[[TMP1]])
  enqueue_kernel(default_queue, flags, ndrange,
                 ^(local void *p) {
                   return;
                 },
                 4294967296L);

  // Emits global block literal [[BLG8]] and invoke function [[INVG8]].
  // The full type of these expressions are long (and repeated elsewhere), so we
  // capture it as part of the regex for convenience and clarity.
  // COMMON: store void () addrspace(4)* addrspacecast (void () addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG8]] to void () addrspace(1)*) to void () addrspace(4)*), void () addrspace(4)** %block_A
  void (^const block_A)(void) = ^{
    return;
  };

  // Emits global block literal [[BLG9]] and invoke function [[INVG9]].
  // COMMON: store void (i8 addrspace(3)*) addrspace(4)* addrspacecast (void (i8 addrspace(3)*) addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG9]] to void (i8 addrspace(3)*) addrspace(1)*) to void (i8 addrspace(3)*) addrspace(4)*), void (i8 addrspace(3)*) addrspace(4)** %block_B
  void (^const block_B)(local void *) = ^(local void *a) {
    return;
  };

  // Uses global block literal [[BLG8]] and invoke function [[INVG8]].
  // COMMON: [[r1:%.*]] = load i8 addrspace(4)*, i8 addrspace(4)* addrspace(4)* getelementptr inbounds (%struct.__opencl_block_literal_generic, %struct.__opencl_block_literal_generic addrspace(4)* addrspacecast (%struct.__opencl_block_literal_generic addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG8]] to %struct.__opencl_block_literal_generic addrspace(1)*) to %struct.__opencl_block_literal_generic addrspace(4)*), i32 0, i32 2)
  // COMMON: [[r2:%.*]] = addrspacecast i8 addrspace(4)* [[r1]] to void (i8 addrspace(4)*)*
  // COMMON: call spir_func void [[r2]](i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG8]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  block_A();

  // Emits global block literal [[BLG8K]] and invoke function [[INVG8K]]. [[INVG8K]] is the same as [[INV8]] except calling convention, ABI and metadata.
  // COMMON: call i32 @__get_kernel_work_group_size_impl(i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG8K]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  unsigned size = get_kernel_work_group_size(block_A);

  // Uses global block literal [[BLG8]] and invoke function [[INVG8]]. Make sure no redundant block literal and invoke functions are emitted.
  // COMMON: [[r1:%.*]] = load i8 addrspace(4)*, i8 addrspace(4)* addrspace(4)* getelementptr inbounds (%struct.__opencl_block_literal_generic, %struct.__opencl_block_literal_generic addrspace(4)* addrspacecast (%struct.__opencl_block_literal_generic addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG8]] to %struct.__opencl_block_literal_generic addrspace(1)*) to %struct.__opencl_block_literal_generic addrspace(4)*), i32 0, i32 2)
  // COMMON: [[r2:%.*]] = addrspacecast i8 addrspace(4)* [[r1]] to void (i8 addrspace(4)*)*
  // COMMON: call spir_func void [[r2]](i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG8]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  block_A();

  // Emits global block literal [[BLG9K]] and invoke function [[INVG9K]]. [[INVG9K]] is the same as [[INV9]] except calling convention, ABI and metadata.
  // COMMON: call i32 @__get_kernel_work_group_size_impl(i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG9K]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  size = get_kernel_work_group_size(block_B);

  // Uses global block literal [[BLG8K]] and invoke function [[INVG8K]]. Make sure no redundant block literal ind invoke functions are emitted.
  // COMMON: call i32 @__get_kernel_preferred_work_group_multiple_impl(i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG8K]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  size = get_kernel_preferred_work_group_size_multiple(block_A);

  // Uses global block literal [[BL_GLOBAL_K]] and invoke function [[INV_G_K]]. [[INV_G_K]] is the same as [[INV_G]] except calling convention, ABI and metadata.
  // COMMON: call i32 @__get_kernel_preferred_work_group_multiple_impl(i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BL_GLOBAL_K]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  size = get_kernel_preferred_work_group_size_multiple(block_G);

  // Emits global block literal [[BLG10]] and invoke function [[INVG10]].
  // COMMON: call i32 @__get_kernel_max_sub_group_size_for_ndrange_impl(%struct.ndrange_t* {{.*}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG10]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  size = get_kernel_max_sub_group_size_for_ndrange(ndrange, ^(){});

  // Emits global block literal [[BLG11]] and invoke function [[INVG11]].
  // COMMON: call i32 @__get_kernel_sub_group_count_for_ndrange_impl(%struct.ndrange_t* {{.*}}, i8 addrspace(4)* addrspacecast (i8 addrspace(1)* bitcast ({ i32, i32, i8 addrspace(4)* } addrspace(1)* [[BLG11]] to i8 addrspace(1)*) to i8 addrspace(4)*))
  size = get_kernel_sub_group_count_for_ndrange(ndrange, ^(){});
}

// COMMON: define internal spir_kernel void [[INVL1]](i8 addrspace(1)* %{{.*}})
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVL2]](i8 addrspace(1)* %{{.*}})
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG1]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %p)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG2]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %p)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG3]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %p)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG4]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %p)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG5]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %p)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG6]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %p1, i8 addrspace(3)* %p2, i8 addrspace(3)* %p3)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG7]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %p)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_func void [[INVG8]](i8 addrspace(4)* %{{.*}})
// COMMON-NOT: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_func void [[INVG9]](i8 addrspace(4)* %{{.*}}, i8 addrspace(3)* %a)
// COMMON-NOT: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG8K]](i8 addrspace(1)* %{{.*}})
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG9K]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %a)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INV_G_K]](i8 addrspace(1)* %{{.*}}, i8 addrspace(3)* %a)
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG10]](i8 addrspace(1)* %{{.*}})
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}

// COMMON: define internal spir_kernel void [[INVG11]](i8 addrspace(1)* %{{.*}})
// COMMON-SAME: #{{[0-9]+}} !kernel_arg_addr_space !{{.*}} !kernel_arg_access_qual !{{.*}} !kernel_arg_type !{{.*}} !kernel_arg_base_type !{{.*}} !kernel_arg_type_qual !{{.*}}
