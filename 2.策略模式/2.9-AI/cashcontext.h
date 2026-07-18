#pragma once

#include "cash.h"

// 纯策略模式的 Context：
// 1. 不负责创建具体策略（没有 if-else / 工厂逻辑）
// 2. 只持有策略接口，并委托调用
// 3. 允许运行时替换策略
class CashContext
{
public:
    explicit CashContext(CashSuper* pCashSuper) : m_pCashSuper(pCashSuper) {}

    ~CashContext()
    {
        delete m_pCashSuper;
        m_pCashSuper = nullptr;
    }

    // 由外部注入新的策略对象
    void SetStrategy(CashSuper* pCashSuper)
    {
        delete m_pCashSuper;
        m_pCashSuper = pCashSuper;
    }

    double GetResult(double money)
    {
        return m_pCashSuper->AcceptCash(money);
    }

private:
    CashSuper* m_pCashSuper = nullptr;
};
