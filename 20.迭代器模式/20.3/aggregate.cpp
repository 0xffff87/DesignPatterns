#include "aggregate.h"
#include "iterator.h"

Iterator* ConcreteAggregate::CreateIterator()
{
    return new ConcreteIterator(this);
}
