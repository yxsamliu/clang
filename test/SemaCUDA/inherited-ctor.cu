// RUN: %clang_cc1 -std=c++11 -fsyntax-only -verify %s
// expected-no-diagnostics

// Inherit a valid non-default ctor.
namespace NonDefaultCtorValid {
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
}

// Inherit an invalid non-default ctor.
// The inherited ctor is invalid because it is unable to initialize s.
namespace NonDefaultCtorInvalid {
  struct S {
    S() = delete;
  };
  struct A {
    A(const int &x) {}
  };

  struct B : A {
    using A::A;
    S s;
  };

  struct C {
    struct B b;
    C() : b(0) {}
  };

  void test() {
    B b(0);
    C c;
  }
}

// Inherit a valid default ctor.
namespace DefaultCtorValid {
  struct A {
    A() {}
  };

  struct B : A {
    using A::A;
  };

  struct C {
    struct B b;
    C() {}
  };

  void test() {
    B b;
    C c;
  }
}

// Inherit an invalid default ctor.
// The inherited ctor is invalid because it is unable to initialize s.
namespace DefaultCtorInvalid {
  struct S {
    S() = delete;
  };
  struct A {
    A() {}
  };

  struct B : A {
    using A::A;
    S s;
  };

  struct C {
    struct B b;
    C() {}
  };

  void test() {
    B b;
    C c;
  }
}

// Inherit a valid copy ctor.
namespace CopyCtorValid {
  struct A {
    A(const A&) {}
  };

  struct B : A {
    using A::A;
  };

  struct C {
    struct B b;
    C(const C& c) :B(c.b) {}
  };

  void test() {
    B b;
    C c;
    B b2(b);
    C c2(c);
  }
}

// Inherit an invalid copy ctor.
// The inherited ctor is invalid because it is unable to initialize s.
namespace CopyCtorInvalid {
  struct S {
    S() = delete;
  };
  struct A {
    A(const A&) {}
  };

  struct B : A {
    using A::A;
    S s;
  };

  struct C {
    struct B b;
    C(const C& c) :B(c.b) {}
  };

  void test() {
    B b;
    C c;
    B b2(b);
    C c2(c);
  }
}


