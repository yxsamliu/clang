// RUN: %clang_cc1 -verify %s
// RUN: %clang_cc1 -cl-std=CL2.0 -verify %s

#define NULL ((void*)0)

void foo(){
  global int *g1 = NULL;
  global int *g2 = (global void *)0;
  global int *g3 = (constant void *)0; // expected-error{{initializing '__global int *' with an expression of type '__constant void *' changes address space of pointer}}
  global int *g4 = (local void *)0; // expected-error{{initializing '__global int *' with an expression of type '__local void *' changes address space of pointer}}
  global int *g5 = (private void *)0; // expected-error{{initializing '__global int *' with an expression of type '__private void *' changes address space of pointer}}

  constant int *c1 = NULL;
  constant int *c2 = (global void *)0; // expected-error{{initializing '__constant int *' with an expression of type '__global void *' changes address space of pointer}}
  constant int *c3 = (constant void *)0;
  constant int *c4 = (local void *)0; // expected-error{{initializing '__constant int *' with an expression of type '__local void *' changes address space of pointer}}
  constant int *c5 = (private void *)0; // expected-error{{initializing '__constant int *' with an expression of type '__private void *' changes address space of pointer}}

  local int *l1 = NULL;
  local int *l2 = (global void *)0; // expected-error{{initializing '__local int *' with an expression of type '__global void *' changes address space of pointer}}
  local int *l3 = (constant void *)0; // expected-error{{initializing '__local int *' with an expression of type '__constant void *' changes address space of pointer}}
  local int *l4 = (local void *)0;
  local int *l5 = (private void *)0; // expected-error{{initializing '__local int *' with an expression of type '__private void *' changes address space of pointer}}

  private int *p1 = NULL;
  private int *p2 = (global void *)0; // expected-error{{initializing '__private int *' with an expression of type '__global void *' changes address space of pointer}}
  private int *p3 = (constant void *)0; // expected-error{{initializing '__private int *' with an expression of type '__constant void *' changes address space of pointer}}
  private int *p4 = (local void *)0; // expected-error{{initializing '__private int *' with an expression of type '__local void *' changes address space of pointer}}
  private int *p5 = (private void *)0;

#if __OPENCL_C_VERSION__ >= 200
  // Assigning a pointer to a pointer to narrower address space causes an error unless there is an valid explicit cast.
  global int *g6 = (generic void *)0; // expected-error{{initializing '__global int *' with an expression of type '__generic void *' changes address space of pointer}}
  constant int *c6 = (generic void *)0; // expected-error{{initializing '__constant int *' with an expression of type '__generic void *' changes address space of pointer}}
  local int *l6 = (generic void *)0; // expected-error{{initializing '__local int *' with an expression of type '__generic void *' changes address space of pointer}}
  private int *p6 = (generic void *)0; // expected-error{{initializing '__private int *' with an expression of type '__generic void *' changes address space of pointer}}

  global int *g7 = (global void*)(generic void *)0;
  constant int *c7 = (constant void*)(generic void *)0; //expected-error{{casting '__generic void *' to type '__constant void *' changes address space of pointer}}
  local int *l7 = (local void*)(generic void *)0;
  private int *p7 = (private void*)(generic void *)0;

  generic int *ge1 = NULL;
  generic int *ge2 = (global void *)0;
  generic int *ge3 = (constant void *)0; // expected-error{{initializing '__generic int *' with an expression of type '__constant void *' changes address space of pointer}}
  generic int *ge4 = (local void *)0;
  generic int *ge5 = (private void *)0;
  generic int *ge6 = (generic void *)0;
#endif

  bool cmp;
  cmp = g1 == NULL;
  cmp = g1 == (global void *)0;
  cmp = g1 == (constant void *)0; // expected-error{{comparison between  ('__global int *' and '__constant void *') which are pointers to non-overlapping address spaces}}
  cmp = g1 == (local void *)0; // expected-error{{comparison between  ('__global int *' and '__local void *') which are pointers to non-overlapping address spaces}}
  cmp = g1 == (private void *)0; // expected-error{{comparison between  ('__global int *' and '__private void *') which are pointers to non-overlapping address spaces}}

#if __OPENCL_C_VERSION__ >= 200
  cmp = g1 == (generic void *)0;

  cmp = ge1 == NULL;
  cmp = ge1 == (global void *)0;
  cmp = ge1 == (constant void *)0; // expected-error{{comparison between  ('__generic int *' and '__constant void *') which are pointers to non-overlapping address spaces}}
  cmp = ge1 == (local void *)0;
  cmp = ge1 == (private void *)0;
  cmp = ge1 == (generic void *)0;
#endif
}
