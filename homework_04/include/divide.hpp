#pragma once

#include <string>
#include "astnode.hpp"

inline const std::string divide_ch = "/";

class Div : public ASTNode {
    public:
        Div(ASTNode *lhs, ASTNode *rhs)
            : ASTNode(divide_ch, lhs, rhs) {}
};
