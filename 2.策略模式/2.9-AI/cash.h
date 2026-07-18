#pragma once

// 策略接口
class CashSuper
{
public:
    virtual ~CashSuper() = default;
    virtual double AcceptCash(double money) = 0;
};

// 具体策略：正常收费
class CashNormal : public CashSuper
{
public:
    double AcceptCash(double money) override { return money; }
};

// 具体策略：打折收费
class CashRebate : public CashSuper
{
public:
    explicit CashRebate(double rebate) : m_moneyRebate(rebate) {}

    double AcceptCash(double money) override { return money * m_moneyRebate; }

private:
    double m_moneyRebate = 1.0;
};

// 具体策略：返利收费
class CashReturn : public CashSuper
{
public:
    CashReturn(double moneyCondition, double moneyReturn)
        : m_moneyCondition(moneyCondition), m_moneyReturn(moneyReturn)
    {
    }

    double AcceptCash(double money) override
    {
        if (money >= m_moneyCondition)
        {
            return money - m_moneyReturn;
        }
        return money;
    }

private:
    double m_moneyCondition = 0.0;
    double m_moneyReturn = 0.0;
};
