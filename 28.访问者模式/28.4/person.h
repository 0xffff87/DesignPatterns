#pragma once
#include <string>

using namespace std;
class Action;

class Person
{
public:
    virtual void Accept(Action* visitor) = 0;
    virtual string GetActionName() = 0;
};

class Man : public Person
{
public:
    void Accept(Action* visitor) override;
    string GetActionName() override { return "男人"; }
};

class Woman : public Person
{
public: 
    void Accept(Action* visitor) override;
    string GetActionName() override { return "女人"; }
};