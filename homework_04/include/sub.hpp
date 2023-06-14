#pragma once

#include <string>
#include "astnode.hpp"

inline const std::string minus_ch = "-";

class Sub : public ASTNode {
    public:
        Sub(ASTNode *lhs, ASTNode *rhs)
            : ASTNode(minus_ch, lhs, rhs) {}
};
