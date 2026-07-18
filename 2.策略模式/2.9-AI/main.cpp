#include "cashcontext.h"
#include <iostream>
#include <string>

using namespace std;

// 纯策略模式示例：
// - Context 不创建策略，只使用策略
// - 具体策略由客户端创建并注入
int main()
{
    cout << "请输入收费类型: " << endl;
    cout << "1. 正常收费" << endl;
    cout << "2. 打八折" << endl;
    cout << "3. 满300返100" << endl;

    int type = 0;
    cin >> type;

    // 客户端决定用哪一种具体策略，并注入 Context
    CashSuper* strategy = nullptr;
    string typeStr;
    switch (type)
    {
    case 1:
        typeStr = "正常收费";
        strategy = new CashNormal();
        break;
    case 2:
        typeStr = "打八折";
        strategy = new CashRebate(0.8);
        break;
    case 3:
        typeStr = "满300返100";
        strategy = new CashReturn(300, 100);
        break;
    default:
        cout << "请输入正确的收费类型" << endl;
        return 0;
    }

    CashContext context(strategy);

    cout << "请输入单价: " << endl;
    double price = 0;
    cin >> price;
    cout << "请输入数量: " << endl;
    double num = 0;
    cin >> num;

    double totalPrices = context.GetResult(price * num);
    cout << "单价：" << price
         << " 数量：" << num
         << " " << typeStr
         << " 合计：" << totalPrices << endl;

    // 演示运行时切换策略：Context 接口不变，只替换算法
    context.SetStrategy(new CashRebate(0.5));
    double halfPrice = context.GetResult(price * num);
    cout << "切换为打五折后合计：" << halfPrice << endl;

    return 0;
}
