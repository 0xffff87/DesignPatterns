#include "Person.h"

int main()
{
    PersonThinBuilder *ptb = new PersonThinBuilder();
    PersonDirector *pdThin = new PersonDirector(ptb);
    pdThin->createPerson();

    PersonFatBuilder *pfb = new PersonFatBuilder();
    PersonDirector *pdFat = new PersonDirector(pfb);
    pdFat->createPerson();
    return 0;
}