#pragma once

#include <iostream>
#include "barbecuer.h"
#include <string>

using namespace std;

class Command 
{
public:
    Command(Barbecuer *receiver) : m_receiver(receiver) {}
    virtual void ExecuteCommand() = 0;
    virtual string ToString() = 0;
protected:
    Barbecuer *m_receiver;
};

class BakeMuttonCommand : public Command
{
public:
    BakeMuttonCommand(Barbecuer *receiver) : Command(receiver) {}
    void ExecuteCommand() override
    {
        m_receiver->BakeMutton();
    }
    string ToString() override
    {
        return "BakeMuttonCommand";
    }
};

class BakeChickenWingCommand : public Command
{
public:
    BakeChickenWingCommand(Barbecuer *receiver) : Command(receiver) {}
    void ExecuteCommand() override
    {
        m_receiver->BakeChickenWing();
    }
    string ToString() override
    {
        return "BakeChickenWingCommand";
    }
};