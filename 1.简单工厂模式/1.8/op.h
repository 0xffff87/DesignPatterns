#pragma once

#include <string>
#include <stdexcept>

using namespace std;

class Op
{
public:
    static double GetResult(double numberA, double numberB, const string& op)
    {
        double result = 0;
        if (op == "+")
        {
            result = numberA + numberB;
        }
        else if (op == "-")
        {
            result = numberA - numberB;
        }
        else if (op == "*")
        {
            result = numberA * numberB;
        }
        else if (op == "/")
        {
            if (numberB == 0)
            {
                throw invalid_argument("除数不能为0");
            }
            result = numberA / numberB;
        }
        else
        {
            throw invalid_argument("未知的运算符");
        }
        return result;
    }
};
