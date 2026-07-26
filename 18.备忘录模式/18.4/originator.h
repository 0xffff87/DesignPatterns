#pragma once

#include <string>

using namespace std;

class Memento;

class Originator
{
public:

    string state;

    Memento CreateMemento();

    void SetMemento(Memento memento);
    
    void show();
};