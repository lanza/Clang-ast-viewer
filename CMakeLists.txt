cmake_minimum_required(VERSION 3.16)
project(ClangAstViewer CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DQT_DEPRECATED_WARNINGS)

# Find the QtWidgets library
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.15.2/clang_64)
#set(LLVM_DIR /Users/lanza/Projects/llvm-project/build/Debug/lib/cmake)
set(LLVM_DIR ~/.llvm/lib/cmake/llvm)
set(Clang_DIR ~/.llvm/lib/cmake/clang)
find_package(LLVM REQUIRED)
find_package(Clang REQUIRED)
find_package(
  Qt5
  COMPONENTS Core Widgets
  REQUIRED)
find_package(Boost REQUIRED ALL)

include_directories(${LLVM_INCLUDE_DIRS})

add_subdirectory(ClangUtilities)

qt5_wrap_ui(UIS_HDRS MainWindow.ui)

# Tell CMake to create the helloworld executable
add_executable(
  ClangAstViewer
  MainWindow.ui
  main.cpp
  MainWindow.cpp
  Highlighter.cpp
  AstReader.cpp
  AstModel.cpp
  CommandLineSplitter.cpp
  MainWindow.h
  Highlighter.h
  AstReader.h
  AstModel.h
  CommandLineSplitter.h)

# Probably some can be removed...
target_link_libraries(
  ClangAstViewer
  Qt5::Core
  Qt5::Widgets
  Boost::headers
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
