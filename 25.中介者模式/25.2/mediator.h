#pragma once

#include <string>

using namespace std;

class Colleague;
class ConcreteColleague1;
class ConcreteColleague2;

class Mediator
{
public:
    virtual void Send(string message, Colleague *colleague) = 0;
};

class ConcreteMediator : public Mediator
{
public:
    void SetColleague1(ConcreteColleague1 *colleague);
    void SetColleague2(ConcreteColleague2 *colleague);
    void Send(string message, Colleague *colleague) override;
private:
    ConcreteColleague1 *m_colleague1;
    ConcreteColleague2 *m_colleague2;
};