#include "subsystem.h"

int main()
{
    Facade *facade = new Facade();

    facade->MethodA();
    facade->MethodB();
    
    return 0;
}