// RUN: %clang_cc1 -std=c++11 -fsyntax-only -verify %s
// expected-no-diagnostics

struct A {
  A(const int &x) {}
};

struct B : A {
  using A::A;
};

struct C {
  struct B b;
  C() : b(0) {}
};

void test() {
  B b(0);
  C c;
}
