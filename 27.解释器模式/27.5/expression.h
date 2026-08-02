#pragma once

#include "playcontext.h"

class Expression
{
public:
    void Interpret(PlayContext *context);
    virtual void Excute(const std::string& key, double value) = 0;
};

class Note : public Expression
{
public:
    void Excute(const std::string& key, double value) override;
};

class Scale : public Expression
{
public:
    void Excute(const std::string& key, double value) override;
};