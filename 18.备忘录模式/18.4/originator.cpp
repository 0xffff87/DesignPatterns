#include "originator.h"
#include "memento.h"
#include <iostream>

using namespace std;

Memento Originator::CreateMemento()
{
    return Memento(state);
}

void Originator::SetMemento(Memento memento)
{
    state = memento.state;
}

void Originator::show()
{
    cout << "State: " << state << endl;
}