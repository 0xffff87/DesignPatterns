#pragma once

#include "command.h"

class Waiter
{
public:
    void SetCommand(Command *command)
    {
        m_command = command;
    }

    void Notify()
    {
        m_command->ExecuteCommand();
    }
private:
    Command *m_command;
};