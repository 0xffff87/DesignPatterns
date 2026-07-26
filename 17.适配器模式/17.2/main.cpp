#include "target.h"

int main()
{
    Target *target = new Adapter();
    target->Request();
    delete target;
    return 0;
}