#pragma once

#include "cash.h"

class CashContext
{
public:
    explicit CashContext(CashSuper* pCashSuper) : m_pCashSuper(pCashSuper) {}

    ~CashContext()
    {
        delete m_pCashSuper;
        m_pCashSuper = nullptr;
    }

    double GetResult(double money) { return m_pCashSuper->AcceptCash(money); }

private:
    CashSuper* m_pCashSuper = nullptr;
};
