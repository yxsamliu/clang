//===--- SyncScope.h - Atomic synchronization scopes ------------*- C++ -*-===//
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

/// \brief Defines the synch scope values used by the atomic builtins and
/// expressions
enum class SyncScope {
  OpenCLWorkGroup = 1,
  OpenCLDevice = 2,
  OpenCLAllSVMDevices = 3,
  OpenCLSubGroup = 4,
};

inline bool isValidSyncScopeValue(unsigned Scope) {
  return Scope >= static_cast<unsigned>(SyncScope::OpenCLWorkGroup) &&
         Scope <= static_cast<unsigned>(SyncScope::OpenCLSubGroup);
}
}

#endif
