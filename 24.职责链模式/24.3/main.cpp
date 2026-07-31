#include "handler.h"

int main()
{
    Handler *handler1 = new ConcreteHandler1();
    Handler *handler2 = new ConcreteHandler2();
    Handler *handler3 = new ConcreteHandler3();

    handler1->SetSuccessor(handler2);
    handler2->SetSuccessor(handler3);

    int requests[] = { 2, 5, 14, 22, 18, 3, 27, 20 };

    for (int request : requests)
    {
        handler1->HandleRequest(request);
    }

    delete handler1;
    delete handler2;

    return 0;
}