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

#include "llvm/ADT/SmallVector.h"

namespace clang {

/// \brief Defines the synch scope values used by the atomic builtins and
/// expressions.
///
/// The enum values should match the pre-defined macros
/// __OPENCL_MEMORY_SCOPE_*, which are used to define memory_scope_*
/// enums in opencl-c.h.
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

inline llvm::SmallVector<SyncScope, 4> getAllSyncScopeValues() {
  llvm::SmallVector<SyncScope, 4> Scopes;
  Scopes.push_back(SyncScope::OpenCLWorkGroup);
  Scopes.push_back(SyncScope::OpenCLDevice);
  Scopes.push_back(SyncScope::OpenCLAllSVMDevices);
  Scopes.push_back(SyncScope::OpenCLSubGroup);
  return Scopes;
}

inline llvm::StringRef getAsString(SyncScope S) {
  switch (S) {
  case SyncScope::OpenCLWorkGroup:
    return "opencl_workgroup";
  case SyncScope::OpenCLDevice:
    return "opencl_device";
  case SyncScope::OpenCLAllSVMDevices:
    return "opencl_allsvmdevices";
  case SyncScope::OpenCLSubGroup:
    return "opencl_subgroup";
  }
}
}

#endif
