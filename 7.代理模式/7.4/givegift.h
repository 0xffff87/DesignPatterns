#pragma once

#include <string>
#include <iostream>
#include "schoolgirl.h"
using namespace std;

class GiveGift
{
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

class Pursuit : public GiveGift
{
public:
    Pursuit(Schoolgirl *mm) : m_mm(mm) {}
    void GiveDolls() override { cout << m_mm->GetName() << "送你洋娃娃" << endl; }
    void GiveFlowers() override { cout << m_mm->GetName() << "送你鲜花" << endl; }
    void GiveChocolate() override { cout << m_mm->GetName() << "送你巧克力" << endl; }
private:
    Schoolgirl *m_mm; // 追求者追求的女孩
};

class Proxy : public GiveGift
{
public:
    Proxy(Schoolgirl *mm) : m_gg(new Pursuit(mm)) {}
    // 在实现方法中去调用追求者的方法
    void GiveDolls() override { m_gg->GiveDolls(); }
    void GiveFlowers() override { m_gg->GiveFlowers(); }
    void GiveChocolate() override { m_gg->GiveChocolate(); }
private:
    Pursuit *m_gg;
};