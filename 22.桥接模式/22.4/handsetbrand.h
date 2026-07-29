#pragma once

#include <iostream>
#include "handsetsoft.h"

class HandsetBrand
{
public:
    void SetHandsetSoft(HandsetSoft* soft) { m_soft = soft; }
    virtual void Run() = 0;
protected:
    HandsetSoft* m_soft;
};

class HandsetBrandN : public HandsetBrand
{
public: 
    void Run() override
    {
        m_soft->Run();
    }
};

class HandsetBrandM : public HandsetBrand
{
public:
    void Run() override
    {
        m_soft->Run();
    }
};

