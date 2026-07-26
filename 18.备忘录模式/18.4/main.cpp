#include "caretaker.h"
#include "memento.h"
#include "originator.h"

int main()
{
    Originator o;
    o.state = "On";
    o.show();

    Caretaker c;
    c.memento = o.CreateMemento();

    o.state = "Off";
    o.show();

    o.SetMemento(c.memento);
    o.show();

    return 0;
}