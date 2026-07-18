#include <iostream>
#include <string>
#include <stdexcept>

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

        double result = 0;
        if (op == "+")
        {
            result = numberA + numberB;
        }
        else if (op == "-")
        {
            result = numberA - numberB;
        }
        else if (op == "*")
        {
            result = numberA * numberB;
        }
        else if (op == "/")
        {
            if (numberB == 0)
            {
                throw invalid_argument("除数不能为0");
            }
            result = numberA / numberB;
        }
        else
        {
            throw invalid_argument("未知的运算符");
        }
        cout << "结果是: " << result << endl;
    }
    catch (const exception& e)
    {
        cerr << "您的输入有错" << endl;
    }
    return 0;
}
