#pragma once

#include <stdexcept>

using namespace std;

class Op
{
public:
    virtual ~Op() = default;
    virtual double GetResult() = 0;

    void SetNumberA(double numberA) { m_numberA = numberA; }
    void SetNumberB(double numberB) { m_numberB = numberB; }
    double GetNumberA() const { return m_numberA; }
    double GetNumberB() const { return m_numberB; }

private:
    double m_numberA = 0.0;
    double m_numberB = 0.0;
};

class AddOp : public Op
{
public:
    double GetResult() override { return GetNumberA() + GetNumberB(); }
};

class SubOp : public Op
{
public:
    double GetResult() override { return GetNumberA() - GetNumberB(); }
};

class MulOp : public Op
{
public:
    double GetResult() override { return GetNumberA() * GetNumberB(); }
};

class DivOp : public Op
{
public:
    double GetResult() override
    {
        if (GetNumberB() == 0)
        {
            throw invalid_argument("除数不能为0");
        }
        return GetNumberA() / GetNumberB();
    }
};
