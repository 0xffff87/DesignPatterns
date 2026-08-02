#pragma once

#include <iostream>
#include "context.h"

using namespace std;

class AbstractExpression
{
public:
    virtual ~AbstractExpression() = default;
    virtual void Interpret(Context *context) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
    void Interpret(Context *context) override
    {
        cout << "终端解释器" << endl;
    }
};

class NonterminalExpression : public AbstractExpression
{
public:
    void Interpret(Context *context) override
    {
        cout << "非终端解释器" << endl;
    }
};