#pragma once

class CashSuper
{
public:
    virtual ~CashSuper() = default;
    virtual double AcceptCash(double money) = 0;
};

// 正常收费
class CashNormal : public CashSuper
{
public:
    double AcceptCash(double money) override { return money; }
};

// 打折收费
class CashRebate : public CashSuper
{
public:
    explicit CashRebate(double rebate) : m_moneyRebate(rebate) {}

    double AcceptCash(double money) override { return money * m_moneyRebate; }

private:
    double m_moneyRebate = 1.0;
};

// 返利收费
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
            // 这里书中写的是 money - floor(money / moneyCondition) * moneyReturn，
            // 但是不符合满减逻辑，所以修改了一下
            return money - m_moneyReturn;
        }
        return money;
    }

private:
    double m_moneyCondition = 0.0;
    double m_moneyReturn = 0.0;
};
