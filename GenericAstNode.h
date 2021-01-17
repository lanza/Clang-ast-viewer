#pragma once
#include <memory>
#include <string>
#include <variant>

#include <boost/variant.hpp>

//#include "clang/Frontend/TextDiagnosticBuffer.h"
//#include "clang/Tooling/CommonOptionsParser.h"
//#include "clang/Tooling/Tooling.h"
//#include "clang/Basic/SourceLocation.h"
#include "clang/Basic/SourceManager.h"
//#include "llvm/Support/CommandLine.h"

namespace clang {
class Stmt;
class Decl;
class ASTContext;
}; // namespace clang

class GenericAstNode {
public:
  GenericAstNode();
  int findChildIndex(GenericAstNode *node); // Return -1 if not found
  void attach(std::unique_ptr<GenericAstNode> child);
  std::string name;
  std::vector<std::unique_ptr<GenericAstNode>> myChidren;
  bool getRangeInMainFile(
      std::pair<int, int> &result, clang::SourceManager const &manager,
      clang::ASTContext
          &context); // Return false if the range is not fully in the main file
  clang::SourceRange getRange();
  int getColor(); // Will return a color identifier How this is linked to the
                  // real color is up to the user
  using Properties = std::map<std::string, std::string>;
  void setProperty(std::string const &propertyName, std::string const &value);
  Properties const &getProperties() const;
  boost::variant<clang::Decl *, clang::Stmt *> myAstNode;
  GenericAstNode *myParent;

  bool hasDetails;
  std::string detailsTitle;
  std::string details;
  std::function<std::string()> detailsComputer;

private:
  Properties myProperties;
};
