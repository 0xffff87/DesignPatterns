#pragma once

#include "cash.h"
#include <string>
#include <stdexcept>

using namespace std;

class CashFactory
{
public:
    static CashSuper* CreateCashAccept(const string& type)
    {
        if (type == "正常收费")
        {
            return new CashNormal();
        }
        else if (type == "打八折")
        {
            return new CashRebate(0.8);
        }
        else if (type == "满300返100")
        {
            return new CashReturn(300, 100);
        }
        else
        {
            throw invalid_argument("未知的收费类型");
        }
    }
};
