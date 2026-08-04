#pragma once
#include "person.h"
#include <string>

using namespace std;

class Action
{
public:
    virtual void GetManConclusion(Man* concreteElementA) = 0;
    virtual void GetWomanConclusion(Woman* concreteElementB) = 0;
    virtual string GetActionName() = 0;
};

class Success : public Action
{
public:
    void GetManConclusion(Man* concreteElementA) override;
    void GetWomanConclusion(Woman* concreteElementB) override;
    string GetActionName() override { return "成功"; }
};

class Failing : public Action
{
public:
    void GetManConclusion(Man* concreteElementA) override;
    void GetWomanConclusion(Woman* concreteElementB) override;
    string GetActionName() override { return "失败"; }
};

class Amativeness : public Action
{
public:
    void GetManConclusion(Man* concreteElementA) override;
    void GetWomanConclusion(Woman* concreteElementB) override;
    string GetActionName() override { return "恋爱"; }
};