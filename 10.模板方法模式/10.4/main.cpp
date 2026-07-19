#include "abstract.h"

int main()
{
    AbstractClass *c;
    c = new ConcreteClassA();
    c->TemplateMethod();

    c = new ConcreteClassB();
    c->TemplateMethod();
    
    return 0;
}