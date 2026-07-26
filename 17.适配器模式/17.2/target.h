#pragma once

#include <iostream>

using namespace std;

class Target
{
public:
    virtual void Request()
    {
        cout << "普通请求！" << endl;
    }
};

class Adaptee
{
public:
    void SpecificRequest()
    {
        cout << "特殊请求！" << endl;
    }
};

class Adapter : public Target
{
public:
    void Request() override
    {
        m_adaptee->SpecificRequest();
    }
private:
    Adaptee *m_adaptee = new Adaptee();
};