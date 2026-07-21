#include "product.h"

int main()
{
    Director *director = new Director();
    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();
    director->Construct(b1);
    Product *p1 = b1->GetResult();
    p1->show();
    director->Construct(b2);
    Product *p2 = b2->GetResult();
    p2->show();
    
    delete director;
    delete b1;
    delete b2;
    delete p1;
    delete p2;
    return 0;
}