#include "iterator.h"

std::string ConcreteIterator::First()
{
    m_current = 0;
    if (m_aggregate->m_items.empty())
        return {};

    return m_aggregate->m_items[0];
}

std::string ConcreteIterator::Next()
{
    ++m_current;
    if (m_current >= m_aggregate->Count())
        return {};

    return m_aggregate->m_items[m_current];
}

bool ConcreteIterator::IsDone()
{
    return m_current >= m_aggregate->Count();
}

std::string ConcreteIterator::CurrentItem()
{
    if (IsDone())
        return {};

    return m_aggregate->m_items[m_current];
}