#include "factory.h"
#include <iostream>

using namespace std;

int main()
{
    IFactory* operFactory = new AddFactory();
    Op* op = operFactory->CreateOperation();
    op->SetNumberA(1);
    op->SetNumberB(2);
    cout << op->GetResult() << endl;
    delete op;
    delete operFactory;

    return 0;
}
