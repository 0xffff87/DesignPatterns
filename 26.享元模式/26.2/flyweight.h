#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Flyweight
{
public:
    virtual void Operation(int extrinsicState) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
    void Operation(int extrinsicState) override
    {
        cout << "具体Flyweight: " << extrinsicState << endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    void Operation(int extrinsicState) override
    {
        cout << "不共享的具体Flyweight: " << extrinsicState << endl;
    }
};

class FlyweightFactory
{
public:
    FlyweightFactory() 
    {
        m_flyweights["X"] = new ConcreteFlyweight();
        m_flyweights["Y"] = new ConcreteFlyweight();
        m_flyweights["Z"] = new ConcreteFlyweight();
    }

    Flyweight* GetFlyweight(const string& key)
    {
        if (m_flyweights.find(key) != m_flyweights.end())
        {
            return m_flyweights[key];
        }
        return nullptr;
    }
    
private:
    unordered_map<string, Flyweight*> m_flyweights;
};