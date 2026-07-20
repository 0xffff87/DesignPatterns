#pragma once

#include <iostream>

using namespace std;

class SubsystemOne
{
public:
    void MethodOne()
    {
        cout << "子系统方法一" << endl;
    }
};

class SubsystemTwo
{
public:
    void MethodTwo()
    {
        cout << "子系统方法二" << endl;
    }
};

class SubsystemThree
{
public:
    void MethodThree()
    {
        cout << "子系统方法三" << endl;
    }
};

class SubsystemFour
{
public:
    void MethodFour()
    {
        cout << "子系统方法四" << endl;
    }
};

class Facade
{
public:
    Facade()
    {
        one = new SubsystemOne();
        two = new SubsystemTwo();
        three = new SubsystemThree();
        four = new SubsystemFour();
    }

    void MethodA()
    {
        cout << "方法组A() --- " << endl;
        one->MethodOne();
        two->MethodTwo();
        four->MethodFour();
    }

    void MethodB()
    {
        cout << "方法组B() --- " << endl;
        two->MethodTwo();
        three->MethodThree();
    }

    ~Facade()
    {
        delete one;
        delete two;
        delete three;
        delete four;
    }
private:
    SubsystemOne *one = nullptr;
    SubsystemTwo *two = nullptr;
    SubsystemThree *three = nullptr;
    SubsystemFour *four = nullptr;
};