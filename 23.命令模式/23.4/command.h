#pragma once

#include <iostream>
#include "barbecuer.h"


using namespace std;

class Command 
{
public:
    Command(Barbecuer *receiver) : m_receiver(receiver) {}
    virtual void ExecuteCommand() = 0;

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
};

class BakeChickenWingCommand : public Command
{
public:
    BakeChickenWingCommand(Barbecuer *receiver) : Command(receiver) {}
    void ExecuteCommand() override
    {
        m_receiver->BakeChickenWing();
    }
};