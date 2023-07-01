#pragma once

#include <string>
#include "astnode.hpp"

inline const std::string multiply_ch = "*";

class Mul : public ASTNode {
    public:
        Mul(ASTNode *lhs, ASTNode *rhs)
            : ASTNode(multiply_ch, lhs, rhs) {}
};
