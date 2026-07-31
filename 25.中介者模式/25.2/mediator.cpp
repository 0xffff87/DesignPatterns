#include "mediator.h"
#include "colleague.h"

void ConcreteMediator::SetColleague1(ConcreteColleague1 *colleague)
{
    m_colleague1 = colleague;
}

void ConcreteMediator::SetColleague2(ConcreteColleague2 *colleague)
{
    m_colleague2 = colleague;
}

void ConcreteMediator::Send(string message, Colleague *colleague)
{
    if (colleague == m_colleague1)
    {
        m_colleague2->Notify(message);
    }
    else
    {
        m_colleague1->Notify(message);
    }
}