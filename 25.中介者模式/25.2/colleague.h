#pragma once

#include "mediator.h"

class Colleague
{
public:
    Colleague(Mediator *mediator) : m_mediator(mediator) {}
protected:
    Mediator *m_mediator;
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator *mediator) : Colleague(mediator) {}
    void Send(string message);
    void Notify(string message);
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator *mediator) : Colleague(mediator) {}
    void Send(string message);
    void Notify(string message);
};