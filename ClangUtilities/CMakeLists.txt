add_library(
  ClangUtilities STATIC TemplateUtilities.cpp StringLiteralExtractor.cpp
                        TemplateUtilities.h StringLiteralExtractor.h)

# Probably some can be removed...
target_link_libraries(
  ClangUtilities
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangDriver
  clangEdit
  clangFrontend
  clangLex
  clangParse
  clangStaticAnalyzerCore
  clangStaticAnalyzerCheckers
  clangStaticAnalyzerFrontend
  clangRewrite
  clangSema
  clangSerialization
  clangTooling
  LLVMBitReader
  LLVMMC
  LLVMMCParser
  LLVMOption
  LLVMSupport
  LLVMProfileData
  LLVMCore)
