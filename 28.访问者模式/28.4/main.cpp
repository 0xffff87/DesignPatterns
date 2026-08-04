#include <list>

#include "action.h"
#include "person.h"

using namespace std;

int main()
{
    Success* success = new Success();
    Failing* failing = new Failing();
    Amativeness* amativeness = new Amativeness();

    Person* man = new Man();
    Woman* woman = new Woman();

    man->Accept(success);
    woman->Accept(success);

    man->Accept(failing);
    woman->Accept(failing);

    man->Accept(amativeness);
    woman->Accept(amativeness);

    delete success;
    delete failing;
    delete amativeness;
    delete man;
    delete woman;

}