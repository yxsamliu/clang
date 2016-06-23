//===--- OpenCLOptions.h ----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Defines the clang::OpenCLOptions class.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_BASIC_OPENCLOPTIONS_H
#define LLVM_CLANG_BASIC_OPENCLOPTIONS_H

#include <string>
#include <vector>
#include "llvm/ADT/StringMap.h"

namespace clang {

/// \brief OpenCL supported extensions and optional core features
class OpenCLOptions {
  struct Info {
    bool Supported; // Is this option supported
    bool Enabled;   // Is this option enabled
    unsigned Avail; // Option starts to be available in this OpenCL version
    unsigned Core;  // Options becomes (optional) core feature in this OpenCL
                    // version
    Info():Supported(false), Enabled(false), Avail(100), Core(~0U){}
  };
  llvm::StringMap<Info> OptMap;
public:
  bool isKnown(StringRef Ext) const {
    return OptMap.find(Ext) != OptMap.end();
  }

  bool isEnabled(StringRef Ext) const {
    return OptMap.find(Ext)->second.Enabled;
  }

  // Is supported OpenCL extension or (optional) core feature for OpenCL version
  // \p CLVer.
  bool isSupported(StringRef Ext, unsigned CLVer) const {
    auto I = OptMap.find(Ext)->getValue();
    return I.Supported && I.Avail <= CLVer;
  }

  // Is supported (optional) OpenCL core features for OpenCL version \p CLVer.
  // For supported extension, return false.
  bool isSupportedCore(StringRef Ext, unsigned CLVer) const {
    auto I = OptMap.find(Ext)->getValue();
    return I.Supported && I.Avail <= CLVer &&
      I.Core != ~0U && CLVer >= I.Core;
  }

  // Is supported OpenCL extension for OpenCL version \p CLVer.
  // For supported (optional) core feature, return false.
 bool isSupportedExtension(StringRef Ext, unsigned CLVer) const {
    auto I = OptMap.find(Ext)->getValue();
    return I.Supported && I.Avail <= CLVer &&
      (I.Core == ~0U || CLVer < I.Core);
  }

  void enable(StringRef Ext, bool V = true) {
    OptMap[Ext].Enabled = V;
  }

  void support(StringRef Ext, bool V = true, unsigned Avail = 100,
              unsigned Core = ~0U) {
    OptMap[Ext].Supported = V;
    OptMap[Ext].Avail = Avail;
    OptMap[Ext].Core = Core;
  }

  OpenCLOptions(){
#define OPENCLEXT_INTERNAL(Ext, AvailVer, CoreVer) \
    OptMap[#Ext].Avail = AvailVer; \
    OptMap[#Ext].Core = CoreVer;
#include "clang/Basic/OpenCLExtensions.def"
  }

  void copy(const OpenCLOptions &Opts) {
    OptMap = Opts.OptMap;
  }

  void supportAll() {
    for (llvm::StringMap<Info>::iterator I = OptMap.begin(),
         E = OptMap.end(); I != E; ++I)
      I->second.Supported = true;
  }

  void disableAll() {
    for (llvm::StringMap<Info>::iterator I = OptMap.begin(),
         E = OptMap.end(); I != E; ++I)
      I->second.Enabled = false;
  }

  void enableSupportedCore(unsigned CLVer) {
    for (llvm::StringMap<Info>::iterator I = OptMap.begin(),
         E = OptMap.end(); I != E; ++I)
      if (isSupportedCore(I->getKey(), CLVer))
        I->second.Enabled = true;
  }

  friend class ASTWriter;
  friend class ASTReader;
};

}  // end namespace clang

#endif
