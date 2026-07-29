#pragma once

#include <iostream>

using namespace std;

class HandsetSoft
{
public:
    virtual void Run() = 0;
};

class HandsetGame : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "运行手机游戏" << endl;
    }
};

class HandsetAddressList : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "运行手机通讯录" << endl;
    }
};

