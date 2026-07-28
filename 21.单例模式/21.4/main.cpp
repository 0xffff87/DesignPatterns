#include "singleton.h"
#include <iostream>

int main()
{
    Singleton& s1 = Singleton::GetInstance();
    Singleton& s2 = Singleton::GetInstance();

    if (&s1 == &s2)
        std::cout << "两个对象是相同的实例" << std::endl;

    return 0;
}