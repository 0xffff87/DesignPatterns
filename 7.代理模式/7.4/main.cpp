#include "givegift.h"

int main()
{
    Schoolgirl *jiaojiao = new Schoolgirl("李娇娇");

    Proxy *daili = new Proxy(jiaojiao);
    
    daili->GiveDolls();
    daili->GiveFlowers();
    daili->GiveChocolate();
    return 0;
}