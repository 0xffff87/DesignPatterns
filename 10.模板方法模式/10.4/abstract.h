#pragma once

#include <iostream>

using namespace std;
class AbstractClass
{
public:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
    void TemplateMethod()
    {
        PrimitiveOperation1();
        PrimitiveOperation2();
    }
};

class ConcreteClassA : public AbstractClass
{
public:
    void PrimitiveOperation1() override
    {
        std::cout << "具体类A方法1实现" << std::endl;
    }
    void PrimitiveOperation2() override
    {
        std::cout << "体类A方法2实现" << std::endl;
    }
};

class ConcreteClassB : public AbstractClass
{
public:
    void PrimitiveOperation1() override
    {
        std::cout << "具体类B方法1实现" << std::endl;
    }
    void PrimitiveOperation2() override
    {
        std::cout << "具体类B方法2实现" << std::endl;
    }
};