#pragma once

#pragma warning(push)
#pragma warning(                                                               \
    disable : 4100 4127 4800 4512 4245 4291 4510 4610 4324 4267 4244 4996)
#include "clang/Basic/SourceLocation.h"
#include "clang/Frontend/TextDiagnosticBuffer.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"
#pragma warning(pop)
#include <string>

class GenericAstNode;

class AstReader {
public:
  AstReader();
  GenericAstNode *readAst(std::string const &sourceCode,
                          std::string const &options);
  clang::SourceManager &getManager();
  clang::ASTContext &getContext();
  GenericAstNode *getRealRoot();
  std::vector<GenericAstNode *> getBestNodeMatchingPosition(
      int position); // Return the path from root to the node
  bool ready();
  void dirty(); // Ready will be false until the reader is run again
private:
  GenericAstNode *findPosInChildren(
      std::vector<std::unique_ptr<GenericAstNode>> const &candidates,
      int position);
  std::string args;
  std::string mySourceCode; // Needs to stay alive while we navigate the tree
  std::unique_ptr<clang::ASTUnit> myAst;
  std::unique_ptr<GenericAstNode>
      myArtificialRoot; // We need an artificial root on top of the real root,
                        // because the root is not displayed by Qt
  bool isReady;
};
