#pragma once

#include <iostream>
#include <string>

using namespace std;

class Handler
{
public:
    void SetSuccessor(Handler *successor)
    {
        m_successor = successor;
    }

    virtual void HandleRequest(int request) = 0;

    virtual string GetTypeName() = 0;
protected:
    Handler *m_successor;
};

class ConcreteHandler1 : public Handler
{
public:
    void HandleRequest(int request) override
    {
        if (request >= 0 && request < 10)
        {
            cout << GetTypeName() << " 处理请求 " << request << endl;
        }
        else if (m_successor != nullptr)
        {
            m_successor->HandleRequest(request);
        }
    }

    string GetTypeName() override
    {
        return "ConcreteHandler1";
    }
};

class ConcreteHandler2 : public Handler
{
public:
    void HandleRequest(int request) override
    {
        if (request >= 10 && request < 20)
        {
            cout << GetTypeName() << " 处理请求 " << request << endl;
        }
        else if (m_successor != nullptr)
        {
            m_successor->HandleRequest(request);
        }
    }

    string GetTypeName() override
    {
        return "ConcreteHandler2";
    }
};

class ConcreteHandler3 : public Handler
{
public:
    void HandleRequest(int request) override
    {
        if (request >= 20 && request < 30)
        {
            cout << GetTypeName() << " 处理请求 " << request << endl;
        }
        else if (m_successor != nullptr)
        {
            m_successor->HandleRequest(request);
        }
    }

    string GetTypeName() override
    {
        return "ConcreteHandler3";
    }
};

