#include "cashfactory.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "请输入收费类型: " << endl;
    cout << "1. 正常收费" << endl;
    cout << "2. 打八折" << endl;
    cout << "3. 满300返100" << endl;

    int type = 0;
    cin >> type;

    string typeStr;
    switch (type)
    {
    case 1:
        typeStr = "正常收费";
        break;
    case 2:
        typeStr = "打八折";
        break;
    case 3:
        typeStr = "满300返100";
        break;
    default:
        cout << "请输入正确的收费类型" << endl;
        return 0;
    }

    CashSuper* cash = CashFactory::CreateCashAccept(typeStr);
    cout << "请输入金额: " << endl;
    double money = 0;
    cin >> money;
    cout << "应付金额: " << cash->AcceptCash(money) << endl;
    delete cash;
    return 0;
}
