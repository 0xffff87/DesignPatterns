#pragma once

#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person() = default;
    Person(const string& name) : m_name(name) {}
    virtual void Show() { cout << "装扮的" << m_name << endl; }
private:
    string m_name;
};

// 服饰类
class Finery : public Person
{
public:
    void Decorate(Person* component) { m_component = component; }
    void Show() override 
    { 
        if (m_component != nullptr)
        {
            m_component->Show(); 
        }
    }
private:
    Person* m_component = nullptr;
};

class TShirts : public Finery
{
public:
    void Show() override 
    { 
        cout << "大T恤 "; 
        Finery::Show(); 
    }
};

class BigTrouser : public Finery
{
public:
    void Show() override 
    { 
        cout << "垮裤 "; 
        Finery::Show(); 
    }
};

class Sneakers : public Finery
{
public:
    void Show() override 
    { 
        cout << "破球鞋 "; 
        Finery::Show(); 
    }
};

class Suit : public Finery
{
public:
    void Show() override 
    { 
        cout << "西装 "; 
        Finery::Show(); 
    }
};

class Tie : public Finery
{
public:
    void Show() override 
    { 
        cout << "领带 "; 
        Finery::Show(); 
    }
};

class LeatherShoes : public Finery
{
public:
    void Show() override 
    { 
        cout << "皮鞋 "; 
        Finery::Show(); 
    }
};