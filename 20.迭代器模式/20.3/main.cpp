#include "aggregate.h"
#include "iterator.h"
#include <iostream>

using namespace std;


int main()
{
    ConcreteAggregate* a = new ConcreteAggregate();
    a->m_items.push_back("大鸟");
    a->m_items.push_back("小菜");
    a->m_items.push_back("行李");
    a->m_items.push_back("行李");   // 行李也得买
    a->m_items.push_back("老外");
    a->m_items.push_back("公交内部员工");
    a->m_items.push_back("小偷");

    Iterator* i = new ConcreteIterator(a);
    std::string item = i->First();
    while (!i->IsDone())
    {
        cout << i->CurrentItem() << " 请买车票!" << endl;
        i->Next();
    }

    delete i;
    delete a;
    return 0;
}