#pragma once

#include "cash.h"
#include <string>

using namespace std;

class CashContext
{
public:
    explicit CashContext(string type)
    {
        if (type == "正常收费")
        {
            m_pCashSuper = new CashNormal();
        }
        else if (type == "打八折")
        {
            m_pCashSuper = new CashRebate(0.8);
        }
        else if (type == "满300返100")
        {
            m_pCashSuper = new CashReturn(300, 100);
        }
    }

    ~CashContext()
    {
        delete m_pCashSuper;
        m_pCashSuper = nullptr;
    }

    double GetResult(double money) { return m_pCashSuper->AcceptCash(money); }

private:
    CashSuper* m_pCashSuper = nullptr;
};
