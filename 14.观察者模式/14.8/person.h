#pragma once
#include <string>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

// 对应 C# 的 delegate void EventHandler();
// 用 std::function 搭载多个回调，实现多播委托
class Event
{
public:
    void operator+=(const function<void()>& handler)
    {
        m_handlers.push_back(handler);
    }

    void operator()()
    {
        for (auto& handler : m_handlers)
        {
            handler();
        }
    }

private:
    vector<function<void()>> m_handlers;
};

// 通知者接口：不再依赖 Observer 抽象类
class Subject
{
public:
    virtual ~Subject() = default;
    virtual void Notify() = 0;
    virtual void SetSubjectAction(string action) = 0;
    virtual string GetSubjectAction() = 0;
};

class Boss : public Subject
{
public:
    // 对应 C#: public event EventHandler Update;
    Event Update;

    void Notify() override { Update(); }
    void SetSubjectAction(string action) override { m_action = action; }
    string GetSubjectAction() override { return m_action; }

private:
    string m_action;
};

// 不必继承 Observer，方法也不必叫 Update
class StockObserver
{
public:
    StockObserver(string name, Subject* sub) : m_name(name), m_sub(sub) {}

    void CloseStockMarket()
    {
        cout << m_sub->GetSubjectAction()
             << m_name << "关闭股票行情，继续工作！" << endl;
    }

private:
    string m_name;
    Subject* m_sub;
};

class NBAObserver
{
public:
    NBAObserver(string name, Subject* sub) : m_name(name), m_sub(sub) {}

    void CloseNBADirectSeeding()
    {
        cout << m_sub->GetSubjectAction()
             << m_name << "关闭NBA直播，继续工作！" << endl;
    }

private:
    string m_name;
    Subject* m_sub;
};
