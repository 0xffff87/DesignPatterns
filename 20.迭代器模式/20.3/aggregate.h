#pragma once

#include <string>
#include <vector>

class Iterator;
class ConcreteIterator;

class Aggregate
{
public:
    virtual Iterator* CreateIterator() = 0;
};

class ConcreteAggregate : public Aggregate
{
public:
    Iterator* CreateIterator() override;
    int Count() const { return m_items.size(); }

    std::vector<std::string> m_items;
};