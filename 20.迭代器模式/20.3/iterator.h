#pragma once

#include "aggregate.h"

class Iterator
{
public:
    virtual std::string First() = 0;
    virtual std::string Next() = 0;
    virtual bool IsDone() = 0;
    virtual std::string CurrentItem() = 0;
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(ConcreteAggregate* aggregate) : m_aggregate(aggregate) {}

    std::string First() override;
    std::string Next() override;
    bool IsDone() override;
    std::string CurrentItem() override;
    
private:
    ConcreteAggregate* m_aggregate;
    int m_current = 0;
};