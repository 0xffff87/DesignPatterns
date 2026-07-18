#include "opfactory.h"
#include <iostream>

using namespace std;

int main()
{
    Op* op = OpFactory::CreateOp("+");
    op->SetNumberA(1);
    op->SetNumberB(2);
    cout << "结果是: " << op->GetResult() << endl;
    delete op;
    return 0;
}
