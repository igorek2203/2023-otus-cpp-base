#pragma once

#include <string>
#include "astnode.hpp"

inline const std::string plus_ch = "+";

class Add : public ASTNode {
    public:
        Add(ASTNode *lhs, ASTNode *rhs)
            : ASTNode(plus_ch, lhs, rhs) {}
};
