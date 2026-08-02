#include "abstractexpression.h"
#include <list>

int main()
{
    Context *context = new Context();
    list<AbstractExpression*> list;
    list.push_back(new TerminalExpression());
    list.push_back(new NonterminalExpression());
    list.push_back(new TerminalExpression());
    list.push_back(new TerminalExpression());

    for (auto it : list)
    {
        it->Interpret(context);
    }

    // 清理内存
    for (auto it : list)
    {
        delete it;
    }
    delete context;
}