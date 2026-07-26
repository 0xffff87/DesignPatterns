#pragma once

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Component
{
public:
    Component(string name) : m_name(name) {}
    virtual void Add(Component* c) = 0;
    virtual void Remove(Component* c) = 0;
    virtual void Display(int depth) = 0;
protected:
    string m_name;
};

class Leaf : public Component
{
public:
    Leaf(string name) : Component(name) {}
    void Add(Component* c) override
    {
        cout << "Cannot add to a leaf" << endl;
    }
    void Remove(Component* c) override
    {
        cout << "Cannot remove from a leaf" << endl;
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << m_name << endl;
    }
};

class Composite : public Component
{
public:
    Composite(string name) : Component(name) {}
    void Add(Component* c) override
    {
        m_children.push_back(c);
    }
    void Remove(Component* c) override
    {
        m_children.remove(c);
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << m_name << endl;
        for (auto it = m_children.begin(); it != m_children.end(); ++it)
        {
            (*it)->Display(depth + 2);
        }
    }
private:
    list<Component*> m_children;
};