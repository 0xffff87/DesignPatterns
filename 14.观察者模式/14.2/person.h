#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class StockObserver;

class Secretary
{
public:
    void Attach(StockObserver* observer) { m_observers.push_back(observer); }
    void Notify();

    string GetSecretaryAction() { return m_action; }
    void SetSecretaryAction(string action) { m_action = action; }

private:
    list<StockObserver*> m_observers;
    string m_action;
};

class StockObserver
{
public:
    StockObserver(string name, Secretary* sub) : m_name(name), m_sub(sub) {}
    void Update(string action) { cout << m_name << " 收到消息: " << action << endl; }

private:
    string m_name;
    Secretary* m_sub;
};

inline void Secretary::Notify()
{
    for (auto observer : m_observers)
    {
        observer->Update(m_action);
    }
}
