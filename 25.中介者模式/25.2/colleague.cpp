#include "colleague.h"

#include <iostream>

void ConcreteColleague1::Send(string message)
{
    m_mediator->Send(message, this);
}

void ConcreteColleague1::Notify(string message)
{
    std::cout << "同事1得到消息: " << message << std::endl;
}

void ConcreteColleague2::Send(string message)
{
    m_mediator->Send(message, this);
}

void ConcreteColleague2::Notify(string message)
{
    std::cout << "同事2得到消息: " << message << std::endl;
}