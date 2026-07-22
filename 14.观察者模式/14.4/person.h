#pragma once
#include <list>
#include <string>
#include <iostream>
using namespace std;
class Observer;

// 通知者接口
class Subject
{
public:
    virtual void Attach(Observer* observer) = 0;
    virtual void Detach(Observer* observer) = 0;
    virtual void Notify() = 0;
    virtual void SetSubjectAction(string action) = 0;
    virtual string GetSubjectAction() = 0;
};

class Boss : public Subject
{
public:
    void Attach(Observer* observer) override { m_observers.push_back(observer); }
    void Detach(Observer* observer) override { m_observers.remove(observer); }
    void Notify() override;
    void SetSubjectAction(string action) override { m_action = action; }
    string GetSubjectAction() override { return m_action; }
private:
    // 同事列表
    list<Observer*> m_observers;
    string m_action;
};

class Observer
{
public:
    Observer(string name, Subject* sub) : m_name(name), m_sub(sub) {}
    virtual void Update() = 0;
protected:
    string m_name;
    Subject* m_sub;
};

class StockObserver : public Observer
{
public:
    StockObserver(string name, Subject* sub) : Observer(name, sub) {}
    void Update() override 
    { 
        cout << m_sub->GetSubjectAction() 
        << m_name << "关闭股票行情，继续工作！ " << endl; 
    }
};

class NBAObserver : public Observer
{
public:
    NBAObserver(string name, Subject* sub) : Observer(name, sub) {}
    void Update() override 
    { 
        cout << m_sub->GetSubjectAction() 
        << m_name << "关闭NBA直播，继续工作！ " << endl; 
    }
};
inline void Boss::Notify()
{
    for (auto observer : m_observers) 
    observer->Update(); 
}