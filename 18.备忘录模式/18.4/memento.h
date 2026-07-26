#pragma once
#include <string>
using namespace std;

class Memento
{
public:
    Memento() = default;

    Memento(string state)
    {
        this->state = state;
    }
    string state;
};