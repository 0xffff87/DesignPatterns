#pragma once

#include "op.h"
#include <string>
#include <stdexcept>

using namespace std;

class OpFactory
{
public:
    static Op* CreateOp(const string& op)
    {
        if (op == "+")
        {
            return new AddOp();
        }
        else if (op == "-")
        {
            return new SubOp();
        }
        else if (op == "*")
        {
            return new MulOp();
        }
        else if (op == "/")
        {
            return new DivOp();
        }
        else
        {
            throw invalid_argument("未知的运算符");
        }
    }
};
