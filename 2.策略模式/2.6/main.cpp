#include "cashcontext.h"
#include <iostream>
#include <string>

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
    CashContext* csuper = new CashContext(typeStr);
    

    // 对应书中：通过 Context 的 GetResult 得到收费结果，使具体算法与客户端分离
    cout << "请输入单价: " << endl;
    double price = 0;
    cin >> price;
    cout << "请输入数量: " << endl;
    double num = 0;
    cin >> num;

    double totalPrices = 0;
    totalPrices = csuper->GetResult(price * num);

    // 书中还有累计总额、列表显示；控制台这里直接输出本笔明细
    cout << "单价：" << price
         << " 数量：" << num
         << " " << typeStr
         << " 合计：" << totalPrices << endl;

    delete csuper;
    return 0;
}
