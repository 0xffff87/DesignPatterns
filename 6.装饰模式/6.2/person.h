#pragma once

#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person(const string& name) : m_name(name) {}
    void WearTShirts() { cout << "大T恤 "; }
    void WearBigTrouser() { cout << "垮裤 "; }
    void WearSneakers() { cout << "破球鞋 "; }
    void WearSuit() { cout << "西装 "; }
    void WearTie() { cout << "领带 "; }
    void WearLeatherShoes() { cout << "皮鞋 "; }
    virtual void Show() { cout << "装扮的" << m_name << endl; }

private:
    string m_name;
};