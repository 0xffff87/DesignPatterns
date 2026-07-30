#pragma once

#include "command.h"
#include <list>
#include <iostream>

using namespace std;

class Waiter
{
public:
    void SetCommand(Command *command)
    {
        // 如果是烤鸡翅
        if (command->ToString() == "BakeChickenWingCommand")
        {
            cout << "服务员: 鸡翅没有了，请点其他烧烤" << endl;
        }
        else
        {
            m_orders.push_back(command);
            cout << "增加订单: " << command->ToString() << endl;
        }
    }

    void CancelOrder(Command *command)
    {
        m_orders.remove(command);
        cout << "取消订单: " << command->ToString() << endl;
    }

    void Notify()
    {
        for (auto& it : m_orders)
        {
            it->ExecuteCommand();
        }
    }
private:
    Command *m_command;
    
private:
    std::list<Command*> m_orders;
};