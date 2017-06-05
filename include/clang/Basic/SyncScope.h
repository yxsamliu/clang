//===--- SyncScope.h - atomic synchronization scopes ------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Provides definitions for the atomic synchronization scopes.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_BASIC_SYNCSCOPE_H
#define LLVM_CLANG_BASIC_SYNCSCOPE_H

namespace clang {

namespace SyncScope {

/// \brief Defines the synch scope values used by the atomic instructions.
///
enum ID {
  SingleThread      = 0,
  WorkGroup         = 1,
  Device            = 2,
  System            = 3,
  SubGroup          = 4,
};

inline unsigned getMaxValue(void) {
  return SubGroup;
}

inline bool isValid(unsigned Scope) {
  return Scope <= getMaxValue();
}
}
}

#endif
