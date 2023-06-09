#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
  public:
    Variable(const std::string &val)
        : ASTNode(val) {}
};
