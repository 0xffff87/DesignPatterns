#include "op.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        cout << "请输入数字A: " << endl;
        double numberA = 0;
        cin >> numberA;
        cout << "请输入数字B: " << endl;
        double numberB = 0;
        cin >> numberB;
        cout << "请输入运算符: " << endl;
        string op;
        cin >> op;

        double result = Op::GetResult(numberA, numberB, op);
        cout << "结果是: " << result << endl;
    }
    catch (const exception& e)
    {
        cerr << "您的输入有错" << endl;
    }
    return 0;
}
